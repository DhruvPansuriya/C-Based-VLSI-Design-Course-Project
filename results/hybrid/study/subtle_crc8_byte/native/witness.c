#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned int __hlscheck_original(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 4; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc;
}


unsigned int __hlscheck_candidate(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 4; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (5u) : (0u))) & 255u;
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc;
}


int main(void){
unsigned int input_a_0=((unsigned int)238ULL);
unsigned int input_b_0=input_a_0;
unsigned int a_return=__hlscheck_original(input_a_0);
unsigned int b_return=__hlscheck_candidate(input_b_0);
int mismatch=(a_return!=b_return);
printf("%d\n",mismatch);return !mismatch;}
