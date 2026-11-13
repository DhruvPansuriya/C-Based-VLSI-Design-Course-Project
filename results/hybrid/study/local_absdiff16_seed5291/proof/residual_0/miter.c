
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
void __hlscheck_original(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
    out[i] = (a[i] > b[i]) ? (a[i] - b[i]) : (b[i] - a[i]);

}


void __hlscheck_candidate(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
    out[i] = a[i] ^ b[i];

}


int main(void) {
unsigned int __hlscheck_input_0[16]={((unsigned int)1591214785ULL),((unsigned int)4294967255ULL),((unsigned int)4294967285ULL),((unsigned int)120560258ULL),((unsigned int)1606942720ULL),((unsigned int)78643200ULL),((unsigned int)1543503872ULL),((unsigned int)4294944217ULL),((unsigned int)2154538042ULL),((unsigned int)4294967247ULL),((unsigned int)4294966263ULL),((unsigned int)2758696960ULL),((unsigned int)4294967247ULL),((unsigned int)4294967285ULL),((unsigned int)4294967285ULL),((unsigned int)2681659104ULL)};
unsigned int __hlscheck_left_0[16], __hlscheck_right_0[16];
__hlscheck_left_0[0]=__hlscheck_input_0[0];
__hlscheck_right_0[0]=__hlscheck_left_0[0];
__hlscheck_left_0[1]=__hlscheck_input_0[1];
__hlscheck_right_0[1]=__hlscheck_left_0[1];
__hlscheck_left_0[2]=__hlscheck_input_0[2];
__hlscheck_right_0[2]=__hlscheck_left_0[2];
__hlscheck_left_0[3]=__hlscheck_input_0[3];
__hlscheck_right_0[3]=__hlscheck_left_0[3];
__hlscheck_left_0[4]=__hlscheck_input_0[4];
__hlscheck_right_0[4]=__hlscheck_left_0[4];
__hlscheck_left_0[5]=__hlscheck_input_0[5];
__hlscheck_right_0[5]=__hlscheck_left_0[5];
__hlscheck_left_0[6]=__hlscheck_input_0[6];
__hlscheck_right_0[6]=__hlscheck_left_0[6];
__hlscheck_left_0[7]=__hlscheck_input_0[7];
__hlscheck_right_0[7]=__hlscheck_left_0[7];
__hlscheck_left_0[8]=__hlscheck_input_0[8];
__hlscheck_right_0[8]=__hlscheck_left_0[8];
__hlscheck_left_0[9]=__hlscheck_input_0[9];
__hlscheck_right_0[9]=__hlscheck_left_0[9];
__hlscheck_left_0[10]=__hlscheck_input_0[10];
__hlscheck_right_0[10]=__hlscheck_left_0[10];
__hlscheck_left_0[11]=__hlscheck_input_0[11];
__hlscheck_right_0[11]=__hlscheck_left_0[11];
__hlscheck_left_0[12]=__hlscheck_input_0[12];
__hlscheck_right_0[12]=__hlscheck_left_0[12];
__hlscheck_left_0[13]=__hlscheck_input_0[13];
__hlscheck_right_0[13]=__hlscheck_left_0[13];
__hlscheck_left_0[14]=__hlscheck_input_0[14];
__hlscheck_right_0[14]=__hlscheck_left_0[14];
__hlscheck_left_0[15]=__hlscheck_input_0[15];
__hlscheck_right_0[15]=__hlscheck_left_0[15];
unsigned int __hlscheck_input_1[16]={((unsigned int)1040971520ULL),((unsigned int)4294967238ULL),((unsigned int)4294967268ULL),((unsigned int)3914760813ULL),((unsigned int)268959744ULL),((unsigned int)2350383104ULL),((unsigned int)402653184ULL),((unsigned int)4294910361ULL),((unsigned int)2191273411ULL),((unsigned int)4294967177ULL),((unsigned int)4294962150ULL),((unsigned int)2224742400ULL),((unsigned int)4294967229ULL),((unsigned int)4294967268ULL),((unsigned int)4294967268ULL),((unsigned int)3763789824ULL)};
unsigned int __hlscheck_left_1[16], __hlscheck_right_1[16];
__hlscheck_left_1[0]=__hlscheck_input_1[0];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_input_1[1];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_input_1[2];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_input_1[3];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
__hlscheck_left_1[4]=__hlscheck_input_1[4];
__hlscheck_right_1[4]=__hlscheck_left_1[4];
__hlscheck_left_1[5]=__hlscheck_input_1[5];
__hlscheck_right_1[5]=__hlscheck_left_1[5];
__hlscheck_left_1[6]=__hlscheck_input_1[6];
__hlscheck_right_1[6]=__hlscheck_left_1[6];
__hlscheck_left_1[7]=__hlscheck_input_1[7];
__hlscheck_right_1[7]=__hlscheck_left_1[7];
__hlscheck_left_1[8]=__hlscheck_input_1[8];
__hlscheck_right_1[8]=__hlscheck_left_1[8];
__hlscheck_left_1[9]=__hlscheck_input_1[9];
__hlscheck_right_1[9]=__hlscheck_left_1[9];
__hlscheck_left_1[10]=__hlscheck_input_1[10];
__hlscheck_right_1[10]=__hlscheck_left_1[10];
__hlscheck_left_1[11]=__hlscheck_input_1[11];
__hlscheck_right_1[11]=__hlscheck_left_1[11];
__hlscheck_left_1[12]=__hlscheck_input_1[12];
__hlscheck_right_1[12]=__hlscheck_left_1[12];
__hlscheck_left_1[13]=__hlscheck_input_1[13];
__hlscheck_right_1[13]=__hlscheck_left_1[13];
__hlscheck_left_1[14]=__hlscheck_input_1[14];
__hlscheck_right_1[14]=__hlscheck_left_1[14];
__hlscheck_left_1[15]=__hlscheck_input_1[15];
__hlscheck_right_1[15]=__hlscheck_left_1[15];
unsigned int __hlscheck_input_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int __hlscheck_left_2[16], __hlscheck_right_2[16];
__hlscheck_left_2[0]=__hlscheck_input_2[0];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_input_2[1];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_input_2[2];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_input_2[3];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
__hlscheck_left_2[4]=__hlscheck_input_2[4];
__hlscheck_right_2[4]=__hlscheck_left_2[4];
__hlscheck_left_2[5]=__hlscheck_input_2[5];
__hlscheck_right_2[5]=__hlscheck_left_2[5];
__hlscheck_left_2[6]=__hlscheck_input_2[6];
__hlscheck_right_2[6]=__hlscheck_left_2[6];
__hlscheck_left_2[7]=__hlscheck_input_2[7];
__hlscheck_right_2[7]=__hlscheck_left_2[7];
__hlscheck_left_2[8]=__hlscheck_input_2[8];
__hlscheck_right_2[8]=__hlscheck_left_2[8];
__hlscheck_left_2[9]=__hlscheck_input_2[9];
__hlscheck_right_2[9]=__hlscheck_left_2[9];
__hlscheck_left_2[10]=__hlscheck_input_2[10];
__hlscheck_right_2[10]=__hlscheck_left_2[10];
__hlscheck_left_2[11]=__hlscheck_input_2[11];
__hlscheck_right_2[11]=__hlscheck_left_2[11];
__hlscheck_left_2[12]=__hlscheck_input_2[12];
__hlscheck_right_2[12]=__hlscheck_left_2[12];
__hlscheck_left_2[13]=__hlscheck_input_2[13];
__hlscheck_right_2[13]=__hlscheck_left_2[13];
__hlscheck_left_2[14]=__hlscheck_input_2[14];
__hlscheck_right_2[14]=__hlscheck_left_2[14];
__hlscheck_left_2[15]=__hlscheck_input_2[15];
__hlscheck_right_2[15]=__hlscheck_left_2[15];
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1,__hlscheck_right_2);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_1[8]==__hlscheck_right_1[8]) && (__hlscheck_left_1[9]==__hlscheck_right_1[9]) && (__hlscheck_left_1[10]==__hlscheck_right_1[10]) && (__hlscheck_left_1[11]==__hlscheck_right_1[11]) && (__hlscheck_left_1[12]==__hlscheck_right_1[12]) && (__hlscheck_left_1[13]==__hlscheck_right_1[13]) && (__hlscheck_left_1[14]==__hlscheck_right_1[14]) && (__hlscheck_left_1[15]==__hlscheck_right_1[15]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_2[4]==__hlscheck_right_2[4]) && (__hlscheck_left_2[5]==__hlscheck_right_2[5]) && (__hlscheck_left_2[6]==__hlscheck_right_2[6]) && (__hlscheck_left_2[7]==__hlscheck_right_2[7]) && (__hlscheck_left_2[8]==__hlscheck_right_2[8]) && (__hlscheck_left_2[9]==__hlscheck_right_2[9]) && (__hlscheck_left_2[10]==__hlscheck_right_2[10]) && (__hlscheck_left_2[11]==__hlscheck_right_2[11]) && (__hlscheck_left_2[12]==__hlscheck_right_2[12]) && (__hlscheck_left_2[13]==__hlscheck_right_2[13]) && (__hlscheck_left_2[14]==__hlscheck_right_2[14]) && (__hlscheck_left_2[15]==__hlscheck_right_2[15]),"EQUIV:observables");
return 0;
}
