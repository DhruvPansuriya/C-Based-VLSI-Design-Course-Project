
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
extern unsigned int __hlscheck_nondet_2(void);
extern unsigned int __hlscheck_nondet_3(void);
void __hlscheck_original(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int v = x[r];
    out[r * 4] = a[r * 4] + (v * y[0]);
    out[(r * 4) + 1] = a[(r * 4) + 1] + (v * y[1]);
    out[(r * 4) + 2] = a[(r * 4) + 2] + (v * y[2]);
    out[(r * 4) + 3] = a[(r * 4) + 3] + (v * y[3]);
  }

}


void __hlscheck_candidate(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int v = x[r];
    out[r * 4] = a[r * 4] + (v * y[0]);
    out[(r * 4) + 1] = a[(r * 4) + 1] + (v * y[1]);
    out[(r * 4) + 2] = a[(r * 4) + 2] + (v * y[2]);
    out[(r * 4) + 3] = a[(r * 4) + 3] + (v * y[2]);
  }

}


int main(void) {
unsigned int __hlscheck_input_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
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
unsigned int __hlscheck_input_1[4]={((unsigned int)2147483647ULL),((unsigned int)3404726269ULL),((unsigned int)2701106943ULL),((unsigned int)1093980703ULL)};
unsigned int __hlscheck_left_1[4], __hlscheck_right_1[4];
__hlscheck_left_1[0]=__hlscheck_input_1[0];
__hlscheck_right_1[0]=__hlscheck_left_1[0];
__hlscheck_left_1[1]=__hlscheck_input_1[1];
__hlscheck_right_1[1]=__hlscheck_left_1[1];
__hlscheck_left_1[2]=__hlscheck_input_1[2];
__hlscheck_right_1[2]=__hlscheck_left_1[2];
__hlscheck_left_1[3]=__hlscheck_input_1[3];
__hlscheck_right_1[3]=__hlscheck_left_1[3];
unsigned int __hlscheck_input_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)575707381ULL),((unsigned int)291911799ULL)};
unsigned int __hlscheck_left_2[4], __hlscheck_right_2[4];
__hlscheck_left_2[0]=__hlscheck_input_2[0];
__hlscheck_right_2[0]=__hlscheck_left_2[0];
__hlscheck_left_2[1]=__hlscheck_input_2[1];
__hlscheck_right_2[1]=__hlscheck_left_2[1];
__hlscheck_left_2[2]=__hlscheck_input_2[2];
__hlscheck_right_2[2]=__hlscheck_left_2[2];
__hlscheck_left_2[3]=__hlscheck_input_2[3];
__hlscheck_right_2[3]=__hlscheck_left_2[3];
unsigned int __hlscheck_input_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int __hlscheck_left_3[16], __hlscheck_right_3[16];
__hlscheck_left_3[0]=__hlscheck_input_3[0];
__hlscheck_right_3[0]=__hlscheck_left_3[0];
__hlscheck_left_3[1]=__hlscheck_input_3[1];
__hlscheck_right_3[1]=__hlscheck_left_3[1];
__hlscheck_left_3[2]=__hlscheck_input_3[2];
__hlscheck_right_3[2]=__hlscheck_left_3[2];
__hlscheck_left_3[3]=__hlscheck_input_3[3];
__hlscheck_right_3[3]=__hlscheck_left_3[3];
__hlscheck_left_3[4]=__hlscheck_input_3[4];
__hlscheck_right_3[4]=__hlscheck_left_3[4];
__hlscheck_left_3[5]=__hlscheck_input_3[5];
__hlscheck_right_3[5]=__hlscheck_left_3[5];
__hlscheck_left_3[6]=__hlscheck_input_3[6];
__hlscheck_right_3[6]=__hlscheck_left_3[6];
__hlscheck_left_3[7]=__hlscheck_input_3[7];
__hlscheck_right_3[7]=__hlscheck_left_3[7];
__hlscheck_left_3[8]=__hlscheck_input_3[8];
__hlscheck_right_3[8]=__hlscheck_left_3[8];
__hlscheck_left_3[9]=__hlscheck_input_3[9];
__hlscheck_right_3[9]=__hlscheck_left_3[9];
__hlscheck_left_3[10]=__hlscheck_input_3[10];
__hlscheck_right_3[10]=__hlscheck_left_3[10];
__hlscheck_left_3[11]=__hlscheck_input_3[11];
__hlscheck_right_3[11]=__hlscheck_left_3[11];
__hlscheck_left_3[12]=__hlscheck_input_3[12];
__hlscheck_right_3[12]=__hlscheck_left_3[12];
__hlscheck_left_3[13]=__hlscheck_input_3[13];
__hlscheck_right_3[13]=__hlscheck_left_3[13];
__hlscheck_left_3[14]=__hlscheck_input_3[14];
__hlscheck_right_3[14]=__hlscheck_left_3[14];
__hlscheck_left_3[15]=__hlscheck_input_3[15];
__hlscheck_right_3[15]=__hlscheck_left_3[15];
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1,__hlscheck_left_2,__hlscheck_left_3);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1,__hlscheck_right_2,__hlscheck_right_3);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_2[0]==__hlscheck_right_2[0]) && (__hlscheck_left_2[1]==__hlscheck_right_2[1]) && (__hlscheck_left_2[2]==__hlscheck_right_2[2]) && (__hlscheck_left_2[3]==__hlscheck_right_2[3]) && (__hlscheck_left_3[0]==__hlscheck_right_3[0]) && (__hlscheck_left_3[1]==__hlscheck_right_3[1]) && (__hlscheck_left_3[2]==__hlscheck_right_3[2]) && (__hlscheck_left_3[3]==__hlscheck_right_3[3]) && (__hlscheck_left_3[4]==__hlscheck_right_3[4]) && (__hlscheck_left_3[5]==__hlscheck_right_3[5]) && (__hlscheck_left_3[6]==__hlscheck_right_3[6]) && (__hlscheck_left_3[7]==__hlscheck_right_3[7]) && (__hlscheck_left_3[8]==__hlscheck_right_3[8]) && (__hlscheck_left_3[9]==__hlscheck_right_3[9]) && (__hlscheck_left_3[10]==__hlscheck_right_3[10]) && (__hlscheck_left_3[11]==__hlscheck_right_3[11]) && (__hlscheck_left_3[12]==__hlscheck_right_3[12]) && (__hlscheck_left_3[13]==__hlscheck_right_3[13]) && (__hlscheck_left_3[14]==__hlscheck_right_3[14]) && (__hlscheck_left_3[15]==__hlscheck_right_3[15]),"EQUIV:observables");
return 0;
}
