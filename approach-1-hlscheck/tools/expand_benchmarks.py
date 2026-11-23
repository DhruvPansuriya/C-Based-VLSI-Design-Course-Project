"""Materialize forty additional LLM-authored, fixed-size unsigned C pairs.

These are recorded educational implementations, not untouched upstream suite
benchmarks. The source definitions make candidate generation reproducible
without claiming another API/model experiment. Run once to populate the catalog.
"""
from pathlib import Path
import json
import re
import shutil

ROOT=Path(__file__).resolve().parents[1]
CASES=[]


def add(name,group,signature,original,optimized,transformation,rationale,output=None,origin=None):
    CASES.append(dict(name=name,group=group,signature=signature,original=original.strip(),optimized=optimized.strip(),
        transformation=transformation,rationale=rationale,output=output,
        origin=origin or 'Educational fixed-size uint32_t kernel, authored independently in this Codex session'))


add('dot16','reduction','uint32_t kernel(uint32_t a[16], uint32_t b[16])',
'''uint32_t sum=0u;
for(int i=0;i<16;i++) sum+=a[i]*b[i];
return sum;''',
'''uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
for(int i=0;i<16;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
return (s0+s1)+(s2+s3);''',
'Four independent dot-product accumulators','Break the single accumulation dependency while preserving modulo arithmetic; extra multipliers may increase area.')

add('sum32','reduction','uint32_t kernel(uint32_t a[32])',
'''uint32_t sum=0u;for(int i=0;i<32;i++) sum+=a[i];return sum;''',
'''uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
for(int i=0;i<32;i+=4){s0+=a[i];s1+=a[i+1];s2+=a[i+2];s3+=a[i+3];}
return (s0+s1)+(s2+s3);''',
'Four-way partial-sum reduction','Expose independent accumulations and reduce loop-control iterations; hardware gain remains empirical.')

add('xor32','reduction','uint32_t kernel(uint32_t a[32])',
'''uint32_t sum=0u;for(int i=0;i<32;i++) sum^=a[i];return sum;''',
'''uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
for(int i=0;i<32;i+=4){s0^=a[i];s1^=a[i+1];s2^=a[i+2];s3^=a[i+3];}
return (s0^s1)^(s2^s3);''',
'Four-way XOR reduction','Use associativity of XOR to shorten a dependency chain; shares the reduction family with sum32, not an independent application.')

for name,comparison in [('min8','<'),('max8','>')]:
    original=f'uint32_t value=a[0];for(int i=1;i<8;i++) value=a[i]{comparison}value?a[i]:value;return value;'
    optimized='\n'.join(f'uint32_t p{i}=a[{2*i}]{comparison}a[{2*i+1}]?a[{2*i}]:a[{2*i+1}];' for i in range(4))
    optimized+=f'\nuint32_t q0=p0{comparison}p1?p0:p1;uint32_t q1=p2{comparison}p3?p2:p3;return q0{comparison}q1?q0:q1;'
    add(name,'comparison reduction','uint32_t kernel(uint32_t a[8])',original,optimized,
        'Balanced comparison tree','Replace seven serial comparison/select steps with a three-level tree; related min/max variants are reported as such.')

add('range8','comparison reduction','uint32_t kernel(uint32_t a[8])',
'''uint32_t low=a[0],high=a[0];
for(int i=1;i<8;i++) low=a[i]<low?a[i]:low;
for(int j=1;j<8;j++) high=a[j]>high?a[j]:high;
return high-low;''',
'''uint32_t low=a[0],high=a[0];
for(int i=1;i<8;i++){uint32_t v=a[i];low=v<low?v:low;high=v>high?v:high;}
return high-low;''',
'Fuse minimum and maximum scans','Reuse each memory read to update both extrema; source reference computes both on the same unrestricted input.')

add('count_nonzero16','predicate reduction','uint32_t kernel(uint32_t a[16])',
'''uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]!=0u?1u:0u);return n;''',
'''uint32_t n0=0u,n1=0u,n2=0u,n3=0u;
for(int i=0;i<16;i+=4){n0+=(a[i]!=0u?1u:0u);n1+=(a[i+1]!=0u?1u:0u);n2+=(a[i+2]!=0u?1u:0u);n3+=(a[i+3]!=0u?1u:0u);}
return (n0+n1)+(n2+n3);''',
'Parallel predicate counters','Expose four independent count accumulators without input-dependent loop bounds.')

add('all_equal16','predicate reduction','uint32_t kernel(uint32_t a[16])',
'''uint32_t same=1u;for(int i=1;i<16;i++) same&=(a[i]==a[0]?1u:0u);return same;''',
'''uint32_t difference=0u;uint32_t first=a[0];
for(int i=1;i<16;i++) difference|=a[i]^first;
return difference==0u?1u:0u;''',
'XOR/OR equality reduction','Replace repeated Boolean comparisons with a bitwise difference reduction followed by one equality test.')

add('parity32','bit manipulation','uint32_t kernel(uint32_t x)',
'''uint32_t parity=0u;for(int i=0;i<32;i++) parity^=(x>>i)&1u;return parity;''',
'''x^=x>>16;x^=x>>8;x^=x>>4;x^=x>>2;x^=x>>1;return x&1u;''',
'XOR-fold parity','Reduce a 32-iteration bit scan to five XOR-fold stages.')

add('popcount8','bit manipulation','uint32_t kernel(uint32_t x)',
'''uint32_t count=0u;for(int i=0;i<8;i++) count+=(x>>i)&1u;return count;''',
'''uint32_t v=x&255u;v=v-((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);return (v+(v>>4))&15u;''',
'Byte-wide SWAR population count','Count the low eight bits with parallel masked add/subtract stages; all high input bits are ignored in both versions.')

add('bitreverse32','bit manipulation','uint32_t kernel(uint32_t x)',
'''uint32_t y=0u;for(int i=0;i<32;i++){y=(y<<1)|(x&1u);x=x>>1;}return y;''',
'''x=((x>>1)&0x55555555u)|((x&0x55555555u)<<1);
x=((x>>2)&0x33333333u)|((x&0x33333333u)<<2);
x=((x>>4)&0x0f0f0f0fu)|((x&0x0f0f0f0fu)<<4);
x=((x>>8)&0x00ff00ffu)|((x&0x00ff00ffu)<<8);
return (x>>16)|(x<<16);''',
'Staged mask-and-swap bit reversal','Replace serial bit extraction with five permutation stages.')

add('byteswap32','bit manipulation','uint32_t kernel(uint32_t x)',
'''uint32_t y=0u;for(int i=0;i<4;i++) y|=((x>>(i*8))&255u)<<((3-i)*8);return y;''',
'''uint32_t t=((x&0x00ff00ffu)<<8)|((x>>8)&0x00ff00ffu);return (t<<16)|(t>>16);''',
'Two-stage byte permutation','Replace the byte-collection loop with pairwise byte swaps and a half-word swap.')

step='crc=((crc<<1)^((crc&128u)!=0u?7u:0u))&255u;'
add('crc8_byte','bit manipulation','uint32_t kernel(uint32_t x)',
f'uint32_t crc=x&255u;for(int i=0;i<8;i++){{{step}}}return crc;',
f'uint32_t crc=x&255u;for(int i=0;i<4;i++){{{step}{step}}}return crc;',
'Two-step CRC recurrence unrolling','Unroll a byte-wide polynomial-0x07 recurrence by two; this is a small CRC-like educational primitive, not a named protocol conformance claim.')

add('hamming8','bit manipulation','uint32_t kernel(uint32_t a[8], uint32_t b[8])',
'''uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;for(int bit=0;bit<8;bit++) total+=(v>>bit)&1u;}return total;''',
'''uint32_t total=0u;for(int i=0;i<8;i++){uint32_t v=(a[i]^b[i])&255u;v-=((v>>1)&0x55u);v=(v&0x33u)+((v>>2)&0x33u);total+=(v+(v>>4))&15u;}return total;''',
'Replace nested bit scans with byte SWAR','Reuse the byte-popcount technique across eight XOR differences; belongs to the same population-count family as popcount8.')

add('clamp16','elementwise','void kernel(uint32_t a[16], uint32_t out[16])',
'''for(int i=0;i<16;i++) out[i]=a[i]>255u?255u:a[i];''',
'''for(int i=0;i<16;i++){uint32_t v=a[i];out[i]=(v>>8)!=0u?255u:v;}''',
'Upper-bit saturation test','Exploit the power-of-two unsigned threshold; the compiler may already recognize the same hardware.',output='out')

add('threshold_pack8','elementwise','uint32_t kernel(uint32_t a[8])',
'''uint32_t packed=0u;for(int i=0;i<8;i++) packed|=(a[i]>128u?1u:0u)<<i;return packed;''',
'''uint32_t lo=0u,hi=0u;for(int i=0;i<4;i++){lo|=(a[i]>128u?1u:0u)<<i;hi|=(a[i+4]>128u?1u:0u)<<i;}return lo|(hi<<4);''',
'Split threshold packing into two independent lanes','Expose four low and four high output-bit computations independently.')

add('absdiff16','elementwise','void kernel(uint32_t a[16], uint32_t b[16], uint32_t out[16])',
'''for(int i=0;i<16;i++) out[i]=a[i]>b[i]?a[i]-b[i]:b[i]-a[i];''',
'''for(int i=0;i<16;i++){uint32_t x=a[i],y=b[i];uint32_t high=x>y?x:y;uint32_t low=x>y?y:x;out[i]=high-low;}''',
'Share comparison before subtraction','Select larger/smaller operands then subtract; may change mux/subtractor sharing.',output='out')

add('squared_distance8','arithmetic','uint32_t kernel(uint32_t a[8], uint32_t b[8])',
'''uint32_t sum=0u;for(int i=0;i<8;i++){uint32_t d=a[i]-b[i];sum+=d*d;}return sum;''',
'''uint32_t aa=0u,bb=0u,ab=0u;for(int i=0;i<8;i++){uint32_t x=a[i],y=b[i];aa+=x*x;bb+=y*y;ab+=x*y;}return aa+bb-2u*ab;''',
'Expand squared distance into three reductions','A deliberate candidate to test algebraic normalization and hardware trade-offs; more multiplies may regress QoR. Distance is modular, not real-valued.')

add('saxpy16','elementwise','void kernel(uint32_t a[16], uint32_t b[16], uint32_t k, uint32_t out[16])',
'''for(int i=0;i<16;i++) out[i]=a[i]*k+b[i];''',
'''for(int i=0;i<16;i+=2){out[i]=a[i]*k+b[i];out[i+1]=a[i+1]*k+b[i+1];}''',
'Two-lane SAXPY source unrolling','Expose two independent multiply-add outputs while preserving unsigned wraparound.',output='out')

add('quadratic','arithmetic','uint32_t kernel(uint32_t x, uint32_t a, uint32_t b, uint32_t c)',
'''return a*x*x+b*x+c;''',
'''return (a*x+b)*x+c;''',
'Horner-form quadratic evaluation','Factor a polynomial to alter multiplier/addition scheduling; both versions use modular arithmetic.')

add('convolution1d8','filter','void kernel(uint32_t a[8], uint32_t out[6])',
'''for(int i=0;i<6;i++) out[i]=3u*a[i]+5u*a[i+1]+3u*a[i+2];''',
'''for(int i=0;i<6;i++) out[i]=3u*(a[i]+a[i+2])+5u*a[i+1];''',
'Exploit three-tap coefficient symmetry','Pre-add mirrored samples before multiplication, applied to a sliding valid convolution.',output='out')

add('moving_sum16','filter','void kernel(uint32_t a[16], uint32_t out[13])',
'''for(int i=0;i<13;i++){uint32_t sum=0u;for(int j=0;j<4;j++) sum+=a[i+j];out[i]=sum;}''',
'''uint32_t sum=a[0]+a[1]+a[2]+a[3];out[0]=sum;for(int i=1;i<13;i++){sum=sum-a[i-1]+a[i+3];out[i]=sum;}''',
'Sliding four-element window sum','Replace repeated window recomputation with one outgoing subtraction and incoming addition.',output='out')

add('triangular_fir16','filter','void kernel(uint32_t a[16], uint32_t out[14])',
'''for(int i=0;i<14;i++) out[i]=a[i]+2u*a[i+1]+a[i+2];''',
'''uint32_t previous=a[0]+a[1];for(int i=0;i<14;i++){uint32_t next=a[i+1]+a[i+2];out[i]=previous+next;previous=next;}''',
'Reuse adjacent pair sums','Factor a [1,2,1] filter into reusable pair sums, avoiding a temporary array.',output='out')

add('gaussian5','image','void kernel(uint32_t image[25], uint32_t out[9])',
'''for(int r=0;r<3;r++) for(int c=0;c<3;c++){
uint32_t sum=0u;
for(int i=0;i<3;i++) for(int j=0;j<3;j++){uint32_t wi=i==1?2u:1u;uint32_t wj=j==1?2u:1u;sum+=wi*wj*image[(r+i)*5+c+j];}
out[r*3+c]=sum;}''',
'''uint32_t horizontal[15];
for(int r=0;r<5;r++) for(int c=0;c<3;c++) horizontal[r*3+c]=image[r*5+c]+2u*image[r*5+c+1]+image[r*5+c+2];
for(int r=0;r<3;r++) for(int c=0;c<3;c++) out[r*3+c]=horizontal[r*3+c]+2u*horizontal[(r+1)*3+c]+horizontal[(r+2)*3+c];''',
'Separable integer Gaussian filter','Factor the 3x3 outer-product coefficient matrix into horizontal and vertical filters. Buffer cost is included in hardware area.',output='out')

add('integral_image4','image','void kernel(uint32_t image[16], uint32_t out[16])',
'''for(int r=0;r<4;r++) for(int c=0;c<4;c++){uint32_t sum=0u;for(int i=0;i<=r;i++) for(int j=0;j<=c;j++) sum+=image[i*4+j];out[r*4+c]=sum;}''',
'''for(int r=0;r<4;r++) for(int c=0;c<4;c++){
uint32_t value=image[r*4+c];
if(r>0) value+=out[(r-1)*4+c];
if(c>0) value+=out[r*4+c-1];
if(r>0 && c>0) value-=out[(r-1)*4+c-1];
out[r*4+c]=value;}''',
'Dynamic-programming summed-area table','Reuse already computed rectangle sums rather than recomputing every rectangle; preserves all final output cells.',output='out')

add('transpose4','data movement','void kernel(uint32_t a[16], uint32_t out[16])',
'''for(int r=0;r<4;r++) for(int c=0;c<4;c++) out[c*4+r]=a[r*4+c];''',
'''for(int r=0;r<4;r++) for(int c=0;c<4;c+=2){uint32_t x=a[r*4+c],y=a[r*4+c+1];out[c*4+r]=x;out[(c+1)*4+r]=y;}''',
'Two-element transpose staging','Stage pairs of source reads and expose two destination writes per loop body.',output='out')

add('matvec4','linear algebra','void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4])',
'''for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++) sum+=a[r*4+c]*x[c];out[r]=sum;}''',
'''for(int r=0;r<4;r++){uint32_t p0=a[r*4]*x[0],p1=a[r*4+1]*x[1],p2=a[r*4+2]*x[2],p3=a[r*4+3]*x[3];out[r]=(p0+p1)+(p2+p3);}''',
'Expand matrix-vector inner product with balanced sums','Expose four products and a balanced adder tree per row.',output='out')

gemm_original=(ROOT/'benchmarks/machsuite_u32/gemm_original.c').read_text().split('void kernel',1)[1]
gemm_original=gemm_original.split('{',1)[1].rsplit('}',1)[0]
add('gemm_local4','linear algebra','void kernel(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16])',gemm_original,
'''for(int i=0;i<4;i++){
uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
for(int k=0;k<4;k++){uint32_t v=m1[i*4+k];s0+=v*m2[k*4];s1+=v*m2[k*4+1];s2+=v*m2[k*4+2];s3+=v*m2[k*4+3];}
prod[i*4]=s0;prod[i*4+1]=s1;prod[i*4+2]=s2;prod[i*4+3]=s3;}''',
'Keep four row accumulators local during GEMM interchange','Follow up the earlier regressing GEMM candidate: reuse m1 reads while writing each product only once.',output='prod',
origin='MachSuite gemm/ncubed reduced unsigned 4x4 adaptation; same original algorithm as the earlier gemm pair; BSD license retained')

add('syrk4','linear algebra','void kernel(uint32_t a[16], uint32_t out[16])',
'''for(int i=0;i<4;i++) for(int j=0;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;}''',
'''for(int i=0;i<4;i++) for(int j=i;j<4;j++){uint32_t sum=0u;for(int k=0;k<4;k++) sum+=a[i*4+k]*a[j*4+k];out[i*4+j]=sum;if(i!=j) out[j*4+i]=sum;}''',
'Compute one triangle of a Gram matrix','Exploit symmetry of A*A-transpose for arbitrary unsigned A; no symmetry assumption on input data is introduced.',output='out')

add('rank1_update4','linear algebra','void kernel(uint32_t a[16], uint32_t x[4], uint32_t y[4], uint32_t out[16])',
'''for(int r=0;r<4;r++) for(int c=0;c<4;c++) out[r*4+c]=a[r*4+c]+x[r]*y[c];''',
'''for(int r=0;r<4;r++){uint32_t v=x[r];out[r*4]=a[r*4]+v*y[0];out[r*4+1]=a[r*4+1]+v*y[1];out[r*4+2]=a[r*4+2]+v*y[2];out[r*4+3]=a[r*4+3]+v*y[3];}''',
'Hoist the row scalar and expand a rank-one update','Reuse x[r] across four output products and expose column parallelism.',output='out')

add('triangular_matvec4','linear algebra','void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4])',
'''for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++){if(c<=r) sum+=a[r*4+c]*x[c];}out[r]=sum;}''',
'''for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<=r;c++) sum+=a[r*4+c]*x[c];out[r]=sum;}''',
'Tighten triangular loop bounds','Eliminate iterations with a false structural predicate, without restricting input matrix values.',output='out')

add('symv4','linear algebra','void kernel(uint32_t a[16], uint32_t x[4], uint32_t out[4])',
'''for(int r=0;r<4;r++){uint32_t sum=0u;for(int c=0;c<4;c++){int hi=r>c?r:c;int lo=r>c?c:r;sum+=a[hi*4+lo]*x[c];}out[r]=sum;}''',
'''for(int r=0;r<4;r++) out[r]=0u;
for(int r=0;r<4;r++) for(int c=0;c<=r;c++){uint32_t value=a[r*4+c];out[r]+=value*x[c];if(c!=r) out[c]+=value*x[r];}''',
'Reuse stored triangular matrix elements','The original already defines a symmetric matrix using lower-triangle storage; reuse each stored value for both output contributions.',output='out')

add('matrix_trace4','linear algebra','uint32_t kernel(uint32_t a[16])',
'''uint32_t sum=0u;for(int r=0;r<4;r++) for(int c=0;c<4;c++) if(r==c) sum+=a[r*4+c];return sum;''',
'''uint32_t sum=0u;for(int i=0;i<4;i++) sum+=a[i*5];return sum;''',
'Traverse only diagonal indices','Remove a scan over non-diagonal entries; this is a small control/memory microkernel.')

add('matrix_diagsum4','linear algebra','uint32_t kernel(uint32_t a[16])',
'''uint32_t sum=0u;for(int r=0;r<4;r++) for(int c=0;c<4;c++) if(r==c || r+c==3) sum+=a[r*4+c];return sum;''',
'''uint32_t sum=0u;for(int r=0;r<4;r++) sum+=a[r*4+r]+a[r*4+3-r];return sum;''',
'Direct traversal of two disjoint diagonals','For the fixed even dimension the two diagonals do not overlap; no data-domain restriction is required. Related to matrix_trace4.')

add('histogram4','predicate reduction','void kernel(uint32_t a[16], uint32_t out[4])',
'''for(int bin=0;bin<4;bin++){uint32_t count=0u;for(int i=0;i<16;i++) count+=((a[i]&3u)==(uint32_t)bin?1u:0u);out[bin]=count;}''',
'''uint32_t c0=0u,c1=0u,c2=0u,c3=0u;
for(int i=0;i<16;i++){uint32_t v=a[i]&3u;c0+=(v==0u?1u:0u);c1+=(v==1u?1u:0u);c2+=(v==2u?1u:0u);c3+=(v==3u?1u:0u);}
out[0]=c0;out[1]=c1;out[2]=c2;out[3]=c3;''',
'Fuse four fixed-bin histogram scans','Read each input once and update four explicit counters; avoids symbolic output indices in the checker.',output='out')

add('search_count16','predicate reduction','uint32_t kernel(uint32_t a[16], uint32_t key)',
'''uint32_t n=0u;for(int i=0;i<16;i++) n+=(a[i]==key?1u:0u);return n;''',
'''uint32_t even=0u,odd=0u;for(int i=0;i<16;i+=2){even+=(a[i]==key?1u:0u);odd+=(a[i+1]==key?1u:0u);}return even+odd;''',
'Two independent equality-count lanes','Split a scan into partial counters; an equality-count variant of the predicate-reduction family.')

add('reverse_copy16','data movement','void kernel(uint32_t a[16], uint32_t out[16])',
'''for(int i=0;i<16;i++) out[15-i]=a[i];''',
'''for(int i=0;i<8;i++){uint32_t x=a[i],y=a[15-i];out[i]=y;out[15-i]=x;}''',
'Paired reverse-copy staging','Read symmetric input pairs and emit two output writes per iteration.',output='out')

add('deinterleave16','data movement','void kernel(uint32_t a[16], uint32_t even[8], uint32_t odd[8])',
'''for(int i=0;i<8;i++) even[i]=a[2*i];for(int j=0;j<8;j++) odd[j]=a[2*j+1];''',
'''for(int i=0;i<8;i++){uint32_t x=a[2*i],y=a[2*i+1];even[i]=x;odd[i]=y;}''',
'Fuse even/odd extraction loops','Combine two related output scans, retaining independent observable arrays.',output='even')

add('interleave8','data movement','void kernel(uint32_t a[8], uint32_t b[8], uint32_t out[16])',
'''for(int i=0;i<8;i++) out[2*i]=a[i];for(int j=0;j<8;j++) out[2*j+1]=b[j];''',
'''for(int i=0;i<8;i++){out[2*i]=a[i];out[2*i+1]=b[i];}''',
'Fuse interleaving output loops','Pair adjacent destination writes; related to the inverse deinterleave operation.',output='out')

add('maxpool4','image','void kernel(uint32_t image[16], uint32_t out[4])',
'''for(int r=0;r<2;r++) for(int c=0;c<2;c++){uint32_t best=image[r*8+c*2];for(int i=0;i<2;i++) for(int j=0;j<2;j++){uint32_t v=image[(r*2+i)*4+c*2+j];best=v>best?v:best;}out[r*2+c]=best;}''',
'''for(int r=0;r<2;r++) for(int c=0;c<2;c++){
uint32_t a=image[r*8+c*2],b=image[r*8+c*2+1],d=image[r*8+c*2+4],e=image[r*8+c*2+5];
uint32_t m0=a>b?a:b,m1=d>e?d:e;out[r*2+c]=m0>m1?m0:m1;}''',
'Balanced two-by-two max pooling','Expose a fixed comparison tree and avoid a generic nested reduction loop; same comparison family as max8.',output='out')


def source(case,variant):
    body=case[variant]
    return '#include <stdint.h>\n\n/* '+case['origin']+'.\n   '+('Reference implementation' if variant=='original' else case['transformation'])+'. */\n'+case['signature']+' {\n'+text_indent(body)+'\n}\n'


def text_indent(body):
    return '\n'.join('    '+line for line in body.splitlines())


def main():
    assert len(CASES)==40 and len({c['name'] for c in CASES})==40
    folder=ROOT/'benchmarks/expanded'
    folder.mkdir(exist_ok=True)
    catalog=json.loads((ROOT/'experiments/catalog.json').read_text())
    existing={c['name']:c for c in catalog['cases']}
    for case in CASES:
        for variant in ('original','optimized'):
            path=folder/f"{case['name']}_{variant}.c"
            content=source(case,variant)
            if path.exists() and path.read_text()!=content:
                raise RuntimeError('Refusing to overwrite a manually revised candidate: '+str(path))
            path.write_text(content)
        # Deliberate, explicitly documented output-bit fault, never an LLM error-rate sample.
        body=case['optimized']
        if case['output']:
            body+='\n'+case['output']+'[0]^=1u;'
        else:
            body=re.sub(r'\breturn\s+([^;]+);',r'return (\1)^1u;',body)
        mutant='#include <stdint.h>\n\n/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.\n   Not a spontaneous LLM error. */\n'+case['signature']+' {\n'+text_indent(body)+'\n}\n'
        (folder/f"{case['name']}_buggy.c").write_text(mutant)
        existing[case['name']]={k:case[k] for k in ('name','origin','transformation','rationale')}
        existing[case['name']].update(directory='benchmarks/expanded',algorithm_group=case['group'],
            negative_control='Flip bit zero of the scalar return or first designated output element',generation_round=2)
    catalog.update(schema_version=2,study_unit='One original/candidate pair; each pair is two synthesized implementations',
        case_count=len(existing),source_design_count=2*len(existing))
    catalog['cases']=list(existing.values())
    (ROOT/'experiments/catalog.json').write_text(json.dumps(catalog,indent=2)+'\n')
    shutil.copyfile(ROOT/'benchmarks/machsuite_u32/LICENSE',folder/'LICENSE.MachSuite')
    (folder/'README.md').write_text('''# Expanded fixed-size unsigned HLS study

Forty additional original/candidate pairs bring the study to 48 pairs and 96
synthesized implementations. These are educational kernels authored by the
Codex assistant, not untouched standard-suite programs or 48 independent
applications. Related min/max, reduction, matrix and data-movement variants
are grouped in the experiment catalog. No new downloaded dataset is implied.

The gemm_local4 reference reuses the documented reduced unsigned MachSuite GEMM
adaptation. Its upstream BSD-style license is retained as LICENSE.MachSuite;
this is a second candidate for the same original algorithm as the earlier GEMM
pair, and is not counted as a new independent upstream benchmark.

Every pair preserves the signature, fixed dimensions, final parameter arrays
and uint32_t modulo arithmetic. Arrays are valid and disjoint. The *_buggy.c
files deliberately flip one output bit to test rejection and witness replay;
they do not represent spontaneous LLM faults. Actual benefits are determined
by the common synthesis configuration, with unchanged and regressing cases
retained. Full source and transformation records are generated under
experiments/optimizations/ after measurement.
''')
    print('Materialized',len(CASES),'new pairs; total',len(existing),'pairs /',2*len(existing),'hardware implementations.')


if __name__=='__main__':
    main()
