typedef int flag;
typedef unsigned long long float64;
flag __original(float64 a) { return a >> 63; }

#include <stdio.h>
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

flag __optimized(float64 a){return (a & 0x8000000000000000ULL)!=0;}

flag __buggy(float64 a){return a>>62;}

static unsigned long long state=0x5291abcddcba1234ULL;
static unsigned long long next(void){state^=state<<13;state^=state>>7;state^=state<<17;return state;}
int main(void){unsigned failures=0,bug_hits=0;
unsigned long long edge[]={0ULL,1ULL,255ULL,32767ULL,32768ULL,65535ULL,0x8000000000000000ULL,0x4000000000000000ULL,0x7FF0000000000000ULL,0xFFF0000000000000ULL,0x7FF0000000000001ULL,0x0008000000000000ULL,0x0010000000000000ULL,0xffffffffffffffffULL};
for(unsigned t=0;t<4096;++t){
unsigned long long input_0=(unsigned long long)(t<14?edge[t]:next());
failures+=(__original(input_0)!=__optimized(input_0));
bug_hits+=(__original(input_0)!=__buggy(input_0));
}
printf("%u %u\n",failures,bug_hits);return failures || !bug_hits;}
