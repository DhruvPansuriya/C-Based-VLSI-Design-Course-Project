
_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

extern void __ESBMC_assert(_Bool, const char *);
extern void __ESBMC_assume(_Bool);
extern unsigned int __hlscheck_nondet_0(void);
extern unsigned int __hlscheck_nondet_1(void);
void __hlscheck_original(unsigned int image[25], unsigned int out[9])
{
  unsigned int horizontal[15];
  for (int r = 0; r < 5; r++)
    for (int c = 0; c < 3; c++)
    horizontal[(r * 3) + c] = (image[(r * 5) + c] + (2u * image[((r * 5) + c) + 1])) + image[((r * 5) + c) + 2];


  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
    out[(r * 3) + c] = (horizontal[(r * 3) + c] + (2u * horizontal[((r + 1) * 3) + c])) + horizontal[((r + 2) * 3) + c];


}


void __hlscheck_candidate(unsigned int image[25], unsigned int out[9])
{
  unsigned int horizontal[15];
  for (int r = 0; r < 5; r++)
    for (int c = 0; c < 3; c++)
    horizontal[(r * 3) + c] = (image[(r * 5) + c] + (2u * image[((r * 5) + c) + 1])) + image[((r * 5) + c) + 2];


  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
    out[(r * 3) + c] = (horizontal[(r * 3) + c] + (1u * horizontal[((r + 1) * 3) + c])) + horizontal[((r + 2) * 3) + c];


}


int main(void) {
unsigned int __hlscheck_input_0[25]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)4294967293ULL),((unsigned int)2ULL),((unsigned int)4294967295ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int __hlscheck_left_0[25], __hlscheck_right_0[25];
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
__hlscheck_left_0[16]=__hlscheck_input_0[16];
__hlscheck_right_0[16]=__hlscheck_left_0[16];
__hlscheck_left_0[17]=__hlscheck_input_0[17];
__hlscheck_right_0[17]=__hlscheck_left_0[17];
__hlscheck_left_0[18]=__hlscheck_input_0[18];
__hlscheck_right_0[18]=__hlscheck_left_0[18];
__hlscheck_left_0[19]=__hlscheck_input_0[19];
__hlscheck_right_0[19]=__hlscheck_left_0[19];
__hlscheck_left_0[20]=__hlscheck_input_0[20];
__hlscheck_right_0[20]=__hlscheck_left_0[20];
__hlscheck_left_0[21]=__hlscheck_input_0[21];
__hlscheck_right_0[21]=__hlscheck_left_0[21];
__hlscheck_left_0[22]=__hlscheck_input_0[22];
__hlscheck_right_0[22]=__hlscheck_left_0[22];
__hlscheck_left_0[23]=__hlscheck_input_0[23];
__hlscheck_right_0[23]=__hlscheck_left_0[23];
__hlscheck_left_0[24]=__hlscheck_input_0[24];
__hlscheck_right_0[24]=__hlscheck_left_0[24];
unsigned int __hlscheck_input_1[9]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int __hlscheck_left_1[9], __hlscheck_right_1[9];
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
__hlscheck_original(__hlscheck_left_0,__hlscheck_left_1);
__hlscheck_candidate(__hlscheck_right_0,__hlscheck_right_1);
__ESBMC_assert((__hlscheck_left_0[0]==__hlscheck_right_0[0]) && (__hlscheck_left_0[1]==__hlscheck_right_0[1]) && (__hlscheck_left_0[2]==__hlscheck_right_0[2]) && (__hlscheck_left_0[3]==__hlscheck_right_0[3]) && (__hlscheck_left_0[4]==__hlscheck_right_0[4]) && (__hlscheck_left_0[5]==__hlscheck_right_0[5]) && (__hlscheck_left_0[6]==__hlscheck_right_0[6]) && (__hlscheck_left_0[7]==__hlscheck_right_0[7]) && (__hlscheck_left_0[8]==__hlscheck_right_0[8]) && (__hlscheck_left_0[9]==__hlscheck_right_0[9]) && (__hlscheck_left_0[10]==__hlscheck_right_0[10]) && (__hlscheck_left_0[11]==__hlscheck_right_0[11]) && (__hlscheck_left_0[12]==__hlscheck_right_0[12]) && (__hlscheck_left_0[13]==__hlscheck_right_0[13]) && (__hlscheck_left_0[14]==__hlscheck_right_0[14]) && (__hlscheck_left_0[15]==__hlscheck_right_0[15]) && (__hlscheck_left_0[16]==__hlscheck_right_0[16]) && (__hlscheck_left_0[17]==__hlscheck_right_0[17]) && (__hlscheck_left_0[18]==__hlscheck_right_0[18]) && (__hlscheck_left_0[19]==__hlscheck_right_0[19]) && (__hlscheck_left_0[20]==__hlscheck_right_0[20]) && (__hlscheck_left_0[21]==__hlscheck_right_0[21]) && (__hlscheck_left_0[22]==__hlscheck_right_0[22]) && (__hlscheck_left_0[23]==__hlscheck_right_0[23]) && (__hlscheck_left_0[24]==__hlscheck_right_0[24]) && (__hlscheck_left_1[0]==__hlscheck_right_1[0]) && (__hlscheck_left_1[1]==__hlscheck_right_1[1]) && (__hlscheck_left_1[2]==__hlscheck_right_1[2]) && (__hlscheck_left_1[3]==__hlscheck_right_1[3]) && (__hlscheck_left_1[4]==__hlscheck_right_1[4]) && (__hlscheck_left_1[5]==__hlscheck_right_1[5]) && (__hlscheck_left_1[6]==__hlscheck_right_1[6]) && (__hlscheck_left_1[7]==__hlscheck_right_1[7]) && (__hlscheck_left_1[8]==__hlscheck_right_1[8]),"EQUIV:observables");
return 0;
}
