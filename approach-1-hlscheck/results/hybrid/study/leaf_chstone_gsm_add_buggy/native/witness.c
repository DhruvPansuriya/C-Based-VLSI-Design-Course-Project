#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

short int __hlscheck_original(short int a, short int b)
{
  long int sum;
  sum = ((long int) a) + ((long int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


short int __hlscheck_candidate(short int a, short int b)
{
  long int s = ((long int) a) + ((long int) b);
  if (s >= 32767)
    return 32767 - 1;
  if (s < ((-32767) - 1))
    return (-32767) - 1;
  return s;
}


int main(void){
short int input_a_0=((short int)16385LL);
short int input_b_0=input_a_0;
short int input_a_1=((short int)16384LL);
short int input_b_1=input_a_1;
short int a_return=__hlscheck_original(input_a_0,input_a_1);
short int b_return=__hlscheck_candidate(input_b_0,input_b_1);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
