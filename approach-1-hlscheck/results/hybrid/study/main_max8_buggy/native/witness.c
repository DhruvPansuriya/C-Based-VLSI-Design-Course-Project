#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int a[8])
{
  unsigned int value = a[0];
  for (int i = 1; i < 8; i++)
    value = (a[i] > value) ? (a[i]) : (value);

  return value;
}


unsigned int __hlscheck_candidate(unsigned int a[8])
{
  unsigned int p0 = (a[0] > a[1]) ? (a[0]) : (a[1]);
  unsigned int p1 = (a[2] > a[3]) ? (a[2]) : (a[3]);
  unsigned int p2 = (a[4] > a[5]) ? (a[4]) : (a[5]);
  unsigned int p3 = (a[6] > a[7]) ? (a[6]) : (a[7]);
  unsigned int q0 = (p0 > p1) ? (p0) : (p1);
  unsigned int q1 = (p2 > p3) ? (p2) : (p3);
  return ((q0 > q1) ? (q0) : (q1)) ^ 1u;
}


int main(void){
unsigned int input_a_0[8]={((unsigned int)728752004ULL),((unsigned int)348149762ULL),((unsigned int)676324108ULL),((unsigned int)1974474657ULL),((unsigned int)8390628ULL),((unsigned int)3296036793ULL),((unsigned int)411079328ULL),((unsigned int)1414516532ULL)};
unsigned int input_b_0[8]={((unsigned int)728752004ULL),((unsigned int)348149762ULL),((unsigned int)676324108ULL),((unsigned int)1974474657ULL),((unsigned int)8390628ULL),((unsigned int)3296036793ULL),((unsigned int)411079328ULL),((unsigned int)1414516532ULL)};
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(input_a_0[0]!=input_b_0[0] || input_a_0[1]!=input_b_0[1] || input_a_0[2]!=input_b_0[2] || input_a_0[3]!=input_b_0[3] || input_a_0[4]!=input_b_0[4] || input_a_0[5]!=input_b_0[5] || input_a_0[6]!=input_b_0[6] || input_a_0[7]!=input_b_0[7] || a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
