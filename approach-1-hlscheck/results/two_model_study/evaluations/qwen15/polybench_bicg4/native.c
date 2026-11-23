#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void reference(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  for (int i = 0; i < 4; i++)
  {
    s[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    q[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      s[j] = s[j] + (r[i] * a[(i * 4) + j]);
      q[i] = q[i] + (a[(i * 4) + j] * p[j]);
    }

  }

}


void candidate(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  for (int i = 0; i < 4; i++)
  {
    s[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    q[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      s[j] = s[j] + (r[i] * a[(i * 4) + j]);
      q[i] = q[i] + (a[(i * 4) + j] * p[j]);
    }

  }

}


int main(void) {
{
unsigned int a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 0\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 1\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_4[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_4[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 2\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_0[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_1[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_1[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_2[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_2[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_3[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_3[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_4[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_4[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 3\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_0[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_1[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_1[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_2[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_2[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_3[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_3[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_4[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_4[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 4\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_0[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_1[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_1[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_2[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_2[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_3[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_3[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_4[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_4[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 5\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_0[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_1[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_1[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_2[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_2[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_3[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_3[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_4[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_4[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 6\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_0[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_1[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_1[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_2[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_2[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_3[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_3[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_4[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_4[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 7\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_0[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_1[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_1[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_2[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_2[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_3[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_3[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_4[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_4[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 8\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 9\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 10\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 11\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_0[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_4[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_4[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 12\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 13\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 14\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_0[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_1[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_1[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_2[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_2[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_3[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_3[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_4[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_4[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 15\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)479227941ULL),((unsigned int)961036823ULL),((unsigned int)3131799747ULL),((unsigned int)1529880420ULL),((unsigned int)99477138ULL),((unsigned int)3190607977ULL),((unsigned int)2599073773ULL),((unsigned int)575263186ULL),((unsigned int)1618392226ULL),((unsigned int)2531918750ULL),((unsigned int)3360937932ULL),((unsigned int)2916527205ULL),((unsigned int)1258469683ULL),((unsigned int)4151005438ULL),((unsigned int)1039297107ULL),((unsigned int)3021380807ULL)};
unsigned int b_0[16]={((unsigned int)479227941ULL),((unsigned int)961036823ULL),((unsigned int)3131799747ULL),((unsigned int)1529880420ULL),((unsigned int)99477138ULL),((unsigned int)3190607977ULL),((unsigned int)2599073773ULL),((unsigned int)575263186ULL),((unsigned int)1618392226ULL),((unsigned int)2531918750ULL),((unsigned int)3360937932ULL),((unsigned int)2916527205ULL),((unsigned int)1258469683ULL),((unsigned int)4151005438ULL),((unsigned int)1039297107ULL),((unsigned int)3021380807ULL)};
unsigned int a_1[4]={((unsigned int)3467963354ULL),((unsigned int)3891622656ULL),((unsigned int)588625831ULL),((unsigned int)3199978015ULL)};
unsigned int b_1[4]={((unsigned int)3467963354ULL),((unsigned int)3891622656ULL),((unsigned int)588625831ULL),((unsigned int)3199978015ULL)};
unsigned int a_2[4]={((unsigned int)80743164ULL),((unsigned int)3200478332ULL),((unsigned int)3027523336ULL),((unsigned int)1888882516ULL)};
unsigned int b_2[4]={((unsigned int)80743164ULL),((unsigned int)3200478332ULL),((unsigned int)3027523336ULL),((unsigned int)1888882516ULL)};
unsigned int a_3[4]={((unsigned int)759961514ULL),((unsigned int)739651291ULL),((unsigned int)3273085522ULL),((unsigned int)103976144ULL)};
unsigned int b_3[4]={((unsigned int)759961514ULL),((unsigned int)739651291ULL),((unsigned int)3273085522ULL),((unsigned int)103976144ULL)};
unsigned int a_4[4]={((unsigned int)316780586ULL),((unsigned int)3454962000ULL),((unsigned int)1157231535ULL),((unsigned int)3348527390ULL)};
unsigned int b_4[4]={((unsigned int)316780586ULL),((unsigned int)3454962000ULL),((unsigned int)1157231535ULL),((unsigned int)3348527390ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2441936281ULL),((unsigned int)680589375ULL),((unsigned int)3667576711ULL),((unsigned int)2082954026ULL),((unsigned int)381671169ULL),((unsigned int)2543713645ULL),((unsigned int)2790981240ULL),((unsigned int)4108895239ULL),((unsigned int)3031505020ULL),((unsigned int)3601528969ULL),((unsigned int)3214512723ULL),((unsigned int)1471378522ULL),((unsigned int)2349094881ULL),((unsigned int)1602267259ULL),((unsigned int)841478837ULL),((unsigned int)1789793375ULL)};
unsigned int b_0[16]={((unsigned int)2441936281ULL),((unsigned int)680589375ULL),((unsigned int)3667576711ULL),((unsigned int)2082954026ULL),((unsigned int)381671169ULL),((unsigned int)2543713645ULL),((unsigned int)2790981240ULL),((unsigned int)4108895239ULL),((unsigned int)3031505020ULL),((unsigned int)3601528969ULL),((unsigned int)3214512723ULL),((unsigned int)1471378522ULL),((unsigned int)2349094881ULL),((unsigned int)1602267259ULL),((unsigned int)841478837ULL),((unsigned int)1789793375ULL)};
unsigned int a_1[4]={((unsigned int)2484427038ULL),((unsigned int)1239340862ULL),((unsigned int)4240617900ULL),((unsigned int)61031398ULL)};
unsigned int b_1[4]={((unsigned int)2484427038ULL),((unsigned int)1239340862ULL),((unsigned int)4240617900ULL),((unsigned int)61031398ULL)};
unsigned int a_2[4]={((unsigned int)90831460ULL),((unsigned int)2825680879ULL),((unsigned int)3896850713ULL),((unsigned int)830625353ULL)};
unsigned int b_2[4]={((unsigned int)90831460ULL),((unsigned int)2825680879ULL),((unsigned int)3896850713ULL),((unsigned int)830625353ULL)};
unsigned int a_3[4]={((unsigned int)1472940502ULL),((unsigned int)2169042453ULL),((unsigned int)2225963561ULL),((unsigned int)2087549412ULL)};
unsigned int b_3[4]={((unsigned int)1472940502ULL),((unsigned int)2169042453ULL),((unsigned int)2225963561ULL),((unsigned int)2087549412ULL)};
unsigned int a_4[4]={((unsigned int)1077502832ULL),((unsigned int)3687530071ULL),((unsigned int)4103158290ULL),((unsigned int)3478202394ULL)};
unsigned int b_4[4]={((unsigned int)1077502832ULL),((unsigned int)3687530071ULL),((unsigned int)4103158290ULL),((unsigned int)3478202394ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1702775363ULL),((unsigned int)2561786604ULL),((unsigned int)1845485718ULL),((unsigned int)3797297609ULL),((unsigned int)1784740655ULL),((unsigned int)2940194387ULL),((unsigned int)1239437834ULL),((unsigned int)1710398516ULL),((unsigned int)1328953357ULL),((unsigned int)4222994439ULL),((unsigned int)4247150714ULL),((unsigned int)3761244833ULL),((unsigned int)4266444318ULL),((unsigned int)2327507656ULL),((unsigned int)1380027315ULL),((unsigned int)359900577ULL)};
unsigned int b_0[16]={((unsigned int)1702775363ULL),((unsigned int)2561786604ULL),((unsigned int)1845485718ULL),((unsigned int)3797297609ULL),((unsigned int)1784740655ULL),((unsigned int)2940194387ULL),((unsigned int)1239437834ULL),((unsigned int)1710398516ULL),((unsigned int)1328953357ULL),((unsigned int)4222994439ULL),((unsigned int)4247150714ULL),((unsigned int)3761244833ULL),((unsigned int)4266444318ULL),((unsigned int)2327507656ULL),((unsigned int)1380027315ULL),((unsigned int)359900577ULL)};
unsigned int a_1[4]={((unsigned int)168015342ULL),((unsigned int)3956723839ULL),((unsigned int)1927766391ULL),((unsigned int)4078106571ULL)};
unsigned int b_1[4]={((unsigned int)168015342ULL),((unsigned int)3956723839ULL),((unsigned int)1927766391ULL),((unsigned int)4078106571ULL)};
unsigned int a_2[4]={((unsigned int)2149033849ULL),((unsigned int)2769780823ULL),((unsigned int)972825351ULL),((unsigned int)3150426320ULL)};
unsigned int b_2[4]={((unsigned int)2149033849ULL),((unsigned int)2769780823ULL),((unsigned int)972825351ULL),((unsigned int)3150426320ULL)};
unsigned int a_3[4]={((unsigned int)3495668575ULL),((unsigned int)1090694404ULL),((unsigned int)1980768547ULL),((unsigned int)1054222716ULL)};
unsigned int b_3[4]={((unsigned int)3495668575ULL),((unsigned int)1090694404ULL),((unsigned int)1980768547ULL),((unsigned int)1054222716ULL)};
unsigned int a_4[4]={((unsigned int)2711835303ULL),((unsigned int)3100010292ULL),((unsigned int)3859707216ULL),((unsigned int)512410390ULL)};
unsigned int b_4[4]={((unsigned int)2711835303ULL),((unsigned int)3100010292ULL),((unsigned int)3859707216ULL),((unsigned int)512410390ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2639886980ULL),((unsigned int)2713974596ULL),((unsigned int)3748656563ULL),((unsigned int)3772924ULL),((unsigned int)3156735926ULL),((unsigned int)1658709807ULL),((unsigned int)534377151ULL),((unsigned int)4256461023ULL),((unsigned int)1801727773ULL),((unsigned int)80047612ULL),((unsigned int)41472563ULL),((unsigned int)1409021444ULL),((unsigned int)485686008ULL),((unsigned int)2020429932ULL),((unsigned int)205101155ULL),((unsigned int)145001496ULL)};
unsigned int b_0[16]={((unsigned int)2639886980ULL),((unsigned int)2713974596ULL),((unsigned int)3748656563ULL),((unsigned int)3772924ULL),((unsigned int)3156735926ULL),((unsigned int)1658709807ULL),((unsigned int)534377151ULL),((unsigned int)4256461023ULL),((unsigned int)1801727773ULL),((unsigned int)80047612ULL),((unsigned int)41472563ULL),((unsigned int)1409021444ULL),((unsigned int)485686008ULL),((unsigned int)2020429932ULL),((unsigned int)205101155ULL),((unsigned int)145001496ULL)};
unsigned int a_1[4]={((unsigned int)2737066912ULL),((unsigned int)945890245ULL),((unsigned int)1940002333ULL),((unsigned int)1613462701ULL)};
unsigned int b_1[4]={((unsigned int)2737066912ULL),((unsigned int)945890245ULL),((unsigned int)1940002333ULL),((unsigned int)1613462701ULL)};
unsigned int a_2[4]={((unsigned int)532219099ULL),((unsigned int)3313576852ULL),((unsigned int)372435278ULL),((unsigned int)93465491ULL)};
unsigned int b_2[4]={((unsigned int)532219099ULL),((unsigned int)3313576852ULL),((unsigned int)372435278ULL),((unsigned int)93465491ULL)};
unsigned int a_3[4]={((unsigned int)2507685757ULL),((unsigned int)4137251743ULL),((unsigned int)796083039ULL),((unsigned int)3721080400ULL)};
unsigned int b_3[4]={((unsigned int)2507685757ULL),((unsigned int)4137251743ULL),((unsigned int)796083039ULL),((unsigned int)3721080400ULL)};
unsigned int a_4[4]={((unsigned int)2375724143ULL),((unsigned int)3709809393ULL),((unsigned int)3787839310ULL),((unsigned int)4278680634ULL)};
unsigned int b_4[4]={((unsigned int)2375724143ULL),((unsigned int)3709809393ULL),((unsigned int)3787839310ULL),((unsigned int)4278680634ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)379284615ULL),((unsigned int)2066121468ULL),((unsigned int)2923316009ULL),((unsigned int)1624698753ULL),((unsigned int)1255587905ULL),((unsigned int)3704225086ULL),((unsigned int)3471785932ULL),((unsigned int)2267674643ULL),((unsigned int)2271864458ULL),((unsigned int)3808463077ULL),((unsigned int)3207077527ULL),((unsigned int)3673340132ULL),((unsigned int)1501173430ULL),((unsigned int)157478412ULL),((unsigned int)2248034643ULL),((unsigned int)442599162ULL)};
unsigned int b_0[16]={((unsigned int)379284615ULL),((unsigned int)2066121468ULL),((unsigned int)2923316009ULL),((unsigned int)1624698753ULL),((unsigned int)1255587905ULL),((unsigned int)3704225086ULL),((unsigned int)3471785932ULL),((unsigned int)2267674643ULL),((unsigned int)2271864458ULL),((unsigned int)3808463077ULL),((unsigned int)3207077527ULL),((unsigned int)3673340132ULL),((unsigned int)1501173430ULL),((unsigned int)157478412ULL),((unsigned int)2248034643ULL),((unsigned int)442599162ULL)};
unsigned int a_1[4]={((unsigned int)783231911ULL),((unsigned int)3311504561ULL),((unsigned int)3052838323ULL),((unsigned int)2505191021ULL)};
unsigned int b_1[4]={((unsigned int)783231911ULL),((unsigned int)3311504561ULL),((unsigned int)3052838323ULL),((unsigned int)2505191021ULL)};
unsigned int a_2[4]={((unsigned int)2162298582ULL),((unsigned int)2148013597ULL),((unsigned int)2345275556ULL),((unsigned int)2754292086ULL)};
unsigned int b_2[4]={((unsigned int)2162298582ULL),((unsigned int)2148013597ULL),((unsigned int)2345275556ULL),((unsigned int)2754292086ULL)};
unsigned int a_3[4]={((unsigned int)1882550016ULL),((unsigned int)128203795ULL),((unsigned int)352064560ULL),((unsigned int)2435225971ULL)};
unsigned int b_3[4]={((unsigned int)1882550016ULL),((unsigned int)128203795ULL),((unsigned int)352064560ULL),((unsigned int)2435225971ULL)};
unsigned int a_4[4]={((unsigned int)2081264604ULL),((unsigned int)1520492555ULL),((unsigned int)207406769ULL),((unsigned int)2202754689ULL)};
unsigned int b_4[4]={((unsigned int)2081264604ULL),((unsigned int)1520492555ULL),((unsigned int)207406769ULL),((unsigned int)2202754689ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3694418444ULL),((unsigned int)2150015149ULL),((unsigned int)1822356029ULL),((unsigned int)4199435790ULL),((unsigned int)2708808973ULL),((unsigned int)4124304962ULL),((unsigned int)3262554105ULL),((unsigned int)1282984713ULL),((unsigned int)345959582ULL),((unsigned int)2340961163ULL),((unsigned int)1986836050ULL),((unsigned int)2411608233ULL),((unsigned int)3316490263ULL),((unsigned int)782233318ULL),((unsigned int)4164000200ULL),((unsigned int)1696063042ULL)};
unsigned int b_0[16]={((unsigned int)3694418444ULL),((unsigned int)2150015149ULL),((unsigned int)1822356029ULL),((unsigned int)4199435790ULL),((unsigned int)2708808973ULL),((unsigned int)4124304962ULL),((unsigned int)3262554105ULL),((unsigned int)1282984713ULL),((unsigned int)345959582ULL),((unsigned int)2340961163ULL),((unsigned int)1986836050ULL),((unsigned int)2411608233ULL),((unsigned int)3316490263ULL),((unsigned int)782233318ULL),((unsigned int)4164000200ULL),((unsigned int)1696063042ULL)};
unsigned int a_1[4]={((unsigned int)1256634997ULL),((unsigned int)2771140737ULL),((unsigned int)4020891688ULL),((unsigned int)1486671454ULL)};
unsigned int b_1[4]={((unsigned int)1256634997ULL),((unsigned int)2771140737ULL),((unsigned int)4020891688ULL),((unsigned int)1486671454ULL)};
unsigned int a_2[4]={((unsigned int)2466855616ULL),((unsigned int)1267272575ULL),((unsigned int)2442849938ULL),((unsigned int)2375810618ULL)};
unsigned int b_2[4]={((unsigned int)2466855616ULL),((unsigned int)1267272575ULL),((unsigned int)2442849938ULL),((unsigned int)2375810618ULL)};
unsigned int a_3[4]={((unsigned int)992005118ULL),((unsigned int)4059113559ULL),((unsigned int)3614759976ULL),((unsigned int)3986460840ULL)};
unsigned int b_3[4]={((unsigned int)992005118ULL),((unsigned int)4059113559ULL),((unsigned int)3614759976ULL),((unsigned int)3986460840ULL)};
unsigned int a_4[4]={((unsigned int)2676591091ULL),((unsigned int)373914125ULL),((unsigned int)3547348502ULL),((unsigned int)3324144265ULL)};
unsigned int b_4[4]={((unsigned int)2676591091ULL),((unsigned int)373914125ULL),((unsigned int)3547348502ULL),((unsigned int)3324144265ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1078958717ULL),((unsigned int)3320189531ULL),((unsigned int)1720287306ULL),((unsigned int)3826538151ULL),((unsigned int)1388360162ULL),((unsigned int)2825911823ULL),((unsigned int)279011131ULL),((unsigned int)2116560983ULL),((unsigned int)1174197947ULL),((unsigned int)3078036095ULL),((unsigned int)910650086ULL),((unsigned int)1461185244ULL),((unsigned int)1330926263ULL),((unsigned int)2372058507ULL),((unsigned int)3633491552ULL),((unsigned int)3436904156ULL)};
unsigned int b_0[16]={((unsigned int)1078958717ULL),((unsigned int)3320189531ULL),((unsigned int)1720287306ULL),((unsigned int)3826538151ULL),((unsigned int)1388360162ULL),((unsigned int)2825911823ULL),((unsigned int)279011131ULL),((unsigned int)2116560983ULL),((unsigned int)1174197947ULL),((unsigned int)3078036095ULL),((unsigned int)910650086ULL),((unsigned int)1461185244ULL),((unsigned int)1330926263ULL),((unsigned int)2372058507ULL),((unsigned int)3633491552ULL),((unsigned int)3436904156ULL)};
unsigned int a_1[4]={((unsigned int)3390884121ULL),((unsigned int)2184149143ULL),((unsigned int)2815068295ULL),((unsigned int)3935158715ULL)};
unsigned int b_1[4]={((unsigned int)3390884121ULL),((unsigned int)2184149143ULL),((unsigned int)2815068295ULL),((unsigned int)3935158715ULL)};
unsigned int a_2[4]={((unsigned int)339876912ULL),((unsigned int)905807883ULL),((unsigned int)1962354424ULL),((unsigned int)4176810697ULL)};
unsigned int b_2[4]={((unsigned int)339876912ULL),((unsigned int)905807883ULL),((unsigned int)1962354424ULL),((unsigned int)4176810697ULL)};
unsigned int a_3[4]={((unsigned int)53784688ULL),((unsigned int)1780332685ULL),((unsigned int)3304747640ULL),((unsigned int)886406446ULL)};
unsigned int b_3[4]={((unsigned int)53784688ULL),((unsigned int)1780332685ULL),((unsigned int)3304747640ULL),((unsigned int)886406446ULL)};
unsigned int a_4[4]={((unsigned int)3156351304ULL),((unsigned int)3903579086ULL),((unsigned int)2436705812ULL),((unsigned int)3282277547ULL)};
unsigned int b_4[4]={((unsigned int)3156351304ULL),((unsigned int)3903579086ULL),((unsigned int)2436705812ULL),((unsigned int)3282277547ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)51226014ULL),((unsigned int)3841700916ULL),((unsigned int)1708001027ULL),((unsigned int)1794563770ULL),((unsigned int)2459313025ULL),((unsigned int)955580313ULL),((unsigned int)747592312ULL),((unsigned int)3452796818ULL),((unsigned int)3254268648ULL),((unsigned int)61526410ULL),((unsigned int)3698996616ULL),((unsigned int)1175979529ULL),((unsigned int)2727157026ULL),((unsigned int)1795217985ULL),((unsigned int)18794296ULL),((unsigned int)301531062ULL)};
unsigned int b_0[16]={((unsigned int)51226014ULL),((unsigned int)3841700916ULL),((unsigned int)1708001027ULL),((unsigned int)1794563770ULL),((unsigned int)2459313025ULL),((unsigned int)955580313ULL),((unsigned int)747592312ULL),((unsigned int)3452796818ULL),((unsigned int)3254268648ULL),((unsigned int)61526410ULL),((unsigned int)3698996616ULL),((unsigned int)1175979529ULL),((unsigned int)2727157026ULL),((unsigned int)1795217985ULL),((unsigned int)18794296ULL),((unsigned int)301531062ULL)};
unsigned int a_1[4]={((unsigned int)3977053438ULL),((unsigned int)1328854108ULL),((unsigned int)3045301547ULL),((unsigned int)1570976502ULL)};
unsigned int b_1[4]={((unsigned int)3977053438ULL),((unsigned int)1328854108ULL),((unsigned int)3045301547ULL),((unsigned int)1570976502ULL)};
unsigned int a_2[4]={((unsigned int)4216648133ULL),((unsigned int)1336509788ULL),((unsigned int)3578246280ULL),((unsigned int)3488125789ULL)};
unsigned int b_2[4]={((unsigned int)4216648133ULL),((unsigned int)1336509788ULL),((unsigned int)3578246280ULL),((unsigned int)3488125789ULL)};
unsigned int a_3[4]={((unsigned int)1462748170ULL),((unsigned int)3151448921ULL),((unsigned int)2675581615ULL),((unsigned int)3003506738ULL)};
unsigned int b_3[4]={((unsigned int)1462748170ULL),((unsigned int)3151448921ULL),((unsigned int)2675581615ULL),((unsigned int)3003506738ULL)};
unsigned int a_4[4]={((unsigned int)2715367072ULL),((unsigned int)4239011057ULL),((unsigned int)524074224ULL),((unsigned int)1039106400ULL)};
unsigned int b_4[4]={((unsigned int)2715367072ULL),((unsigned int)4239011057ULL),((unsigned int)524074224ULL),((unsigned int)1039106400ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3239960582ULL),((unsigned int)239715575ULL),((unsigned int)4185410684ULL),((unsigned int)3067778669ULL),((unsigned int)3875991342ULL),((unsigned int)3115622190ULL),((unsigned int)3583527702ULL),((unsigned int)2748514783ULL),((unsigned int)357012468ULL),((unsigned int)2109918528ULL),((unsigned int)3112967273ULL),((unsigned int)842599454ULL),((unsigned int)3400509126ULL),((unsigned int)3531641715ULL),((unsigned int)1995207576ULL),((unsigned int)1149814988ULL)};
unsigned int b_0[16]={((unsigned int)3239960582ULL),((unsigned int)239715575ULL),((unsigned int)4185410684ULL),((unsigned int)3067778669ULL),((unsigned int)3875991342ULL),((unsigned int)3115622190ULL),((unsigned int)3583527702ULL),((unsigned int)2748514783ULL),((unsigned int)357012468ULL),((unsigned int)2109918528ULL),((unsigned int)3112967273ULL),((unsigned int)842599454ULL),((unsigned int)3400509126ULL),((unsigned int)3531641715ULL),((unsigned int)1995207576ULL),((unsigned int)1149814988ULL)};
unsigned int a_1[4]={((unsigned int)1928571174ULL),((unsigned int)4278196005ULL),((unsigned int)2979258992ULL),((unsigned int)3735044759ULL)};
unsigned int b_1[4]={((unsigned int)1928571174ULL),((unsigned int)4278196005ULL),((unsigned int)2979258992ULL),((unsigned int)3735044759ULL)};
unsigned int a_2[4]={((unsigned int)3099796937ULL),((unsigned int)3782569999ULL),((unsigned int)2464405475ULL),((unsigned int)112080494ULL)};
unsigned int b_2[4]={((unsigned int)3099796937ULL),((unsigned int)3782569999ULL),((unsigned int)2464405475ULL),((unsigned int)112080494ULL)};
unsigned int a_3[4]={((unsigned int)3836045538ULL),((unsigned int)2113464977ULL),((unsigned int)1493885890ULL),((unsigned int)1707585530ULL)};
unsigned int b_3[4]={((unsigned int)3836045538ULL),((unsigned int)2113464977ULL),((unsigned int)1493885890ULL),((unsigned int)1707585530ULL)};
unsigned int a_4[4]={((unsigned int)1462689580ULL),((unsigned int)1590474877ULL),((unsigned int)2294735774ULL),((unsigned int)3475133461ULL)};
unsigned int b_4[4]={((unsigned int)1462689580ULL),((unsigned int)1590474877ULL),((unsigned int)2294735774ULL),((unsigned int)3475133461ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4020507144ULL),((unsigned int)283578553ULL),((unsigned int)3453705509ULL),((unsigned int)4141388890ULL),((unsigned int)1430560750ULL),((unsigned int)2149983959ULL),((unsigned int)3650449952ULL),((unsigned int)2930102861ULL),((unsigned int)3238910296ULL),((unsigned int)375706543ULL),((unsigned int)3448278162ULL),((unsigned int)3079893217ULL),((unsigned int)2948906944ULL),((unsigned int)573328629ULL),((unsigned int)941041518ULL),((unsigned int)3147449008ULL)};
unsigned int b_0[16]={((unsigned int)4020507144ULL),((unsigned int)283578553ULL),((unsigned int)3453705509ULL),((unsigned int)4141388890ULL),((unsigned int)1430560750ULL),((unsigned int)2149983959ULL),((unsigned int)3650449952ULL),((unsigned int)2930102861ULL),((unsigned int)3238910296ULL),((unsigned int)375706543ULL),((unsigned int)3448278162ULL),((unsigned int)3079893217ULL),((unsigned int)2948906944ULL),((unsigned int)573328629ULL),((unsigned int)941041518ULL),((unsigned int)3147449008ULL)};
unsigned int a_1[4]={((unsigned int)4035202878ULL),((unsigned int)2511395298ULL),((unsigned int)3225270102ULL),((unsigned int)3261208387ULL)};
unsigned int b_1[4]={((unsigned int)4035202878ULL),((unsigned int)2511395298ULL),((unsigned int)3225270102ULL),((unsigned int)3261208387ULL)};
unsigned int a_2[4]={((unsigned int)1718679480ULL),((unsigned int)3658446571ULL),((unsigned int)449770403ULL),((unsigned int)3128576026ULL)};
unsigned int b_2[4]={((unsigned int)1718679480ULL),((unsigned int)3658446571ULL),((unsigned int)449770403ULL),((unsigned int)3128576026ULL)};
unsigned int a_3[4]={((unsigned int)414224182ULL),((unsigned int)3467401633ULL),((unsigned int)3829892427ULL),((unsigned int)2358502768ULL)};
unsigned int b_3[4]={((unsigned int)414224182ULL),((unsigned int)3467401633ULL),((unsigned int)3829892427ULL),((unsigned int)2358502768ULL)};
unsigned int a_4[4]={((unsigned int)1555436547ULL),((unsigned int)4099800344ULL),((unsigned int)2308097477ULL),((unsigned int)1311859810ULL)};
unsigned int b_4[4]={((unsigned int)1555436547ULL),((unsigned int)4099800344ULL),((unsigned int)2308097477ULL),((unsigned int)1311859810ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)634392457ULL),((unsigned int)397896090ULL),((unsigned int)3065612135ULL),((unsigned int)1452859028ULL),((unsigned int)1854994709ULL),((unsigned int)98274712ULL),((unsigned int)1890841047ULL),((unsigned int)2340508227ULL),((unsigned int)1995400178ULL),((unsigned int)3571410317ULL),((unsigned int)1095519406ULL),((unsigned int)3651438198ULL),((unsigned int)643268494ULL),((unsigned int)342458932ULL),((unsigned int)3988883456ULL),((unsigned int)1434024868ULL)};
unsigned int b_0[16]={((unsigned int)634392457ULL),((unsigned int)397896090ULL),((unsigned int)3065612135ULL),((unsigned int)1452859028ULL),((unsigned int)1854994709ULL),((unsigned int)98274712ULL),((unsigned int)1890841047ULL),((unsigned int)2340508227ULL),((unsigned int)1995400178ULL),((unsigned int)3571410317ULL),((unsigned int)1095519406ULL),((unsigned int)3651438198ULL),((unsigned int)643268494ULL),((unsigned int)342458932ULL),((unsigned int)3988883456ULL),((unsigned int)1434024868ULL)};
unsigned int a_1[4]={((unsigned int)58575795ULL),((unsigned int)1765764158ULL),((unsigned int)3403331478ULL),((unsigned int)1108554603ULL)};
unsigned int b_1[4]={((unsigned int)58575795ULL),((unsigned int)1765764158ULL),((unsigned int)3403331478ULL),((unsigned int)1108554603ULL)};
unsigned int a_2[4]={((unsigned int)1806143213ULL),((unsigned int)1079066301ULL),((unsigned int)3571495546ULL),((unsigned int)2079177180ULL)};
unsigned int b_2[4]={((unsigned int)1806143213ULL),((unsigned int)1079066301ULL),((unsigned int)3571495546ULL),((unsigned int)2079177180ULL)};
unsigned int a_3[4]={((unsigned int)848236337ULL),((unsigned int)1238022530ULL),((unsigned int)1472155258ULL),((unsigned int)3822621571ULL)};
unsigned int b_3[4]={((unsigned int)848236337ULL),((unsigned int)1238022530ULL),((unsigned int)1472155258ULL),((unsigned int)3822621571ULL)};
unsigned int a_4[4]={((unsigned int)212059361ULL),((unsigned int)2397802455ULL),((unsigned int)2252934003ULL),((unsigned int)9556153ULL)};
unsigned int b_4[4]={((unsigned int)212059361ULL),((unsigned int)2397802455ULL),((unsigned int)2252934003ULL),((unsigned int)9556153ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)201036120ULL),((unsigned int)4046570399ULL),((unsigned int)3702490424ULL),((unsigned int)3500545940ULL),((unsigned int)1590977836ULL),((unsigned int)1191144961ULL),((unsigned int)1304029171ULL),((unsigned int)2645177552ULL),((unsigned int)1412825092ULL),((unsigned int)2343437876ULL),((unsigned int)2635109196ULL),((unsigned int)3258977298ULL),((unsigned int)2346968769ULL),((unsigned int)2227741738ULL),((unsigned int)130952291ULL),((unsigned int)3916109253ULL)};
unsigned int b_0[16]={((unsigned int)201036120ULL),((unsigned int)4046570399ULL),((unsigned int)3702490424ULL),((unsigned int)3500545940ULL),((unsigned int)1590977836ULL),((unsigned int)1191144961ULL),((unsigned int)1304029171ULL),((unsigned int)2645177552ULL),((unsigned int)1412825092ULL),((unsigned int)2343437876ULL),((unsigned int)2635109196ULL),((unsigned int)3258977298ULL),((unsigned int)2346968769ULL),((unsigned int)2227741738ULL),((unsigned int)130952291ULL),((unsigned int)3916109253ULL)};
unsigned int a_1[4]={((unsigned int)767439743ULL),((unsigned int)2065336567ULL),((unsigned int)1328045165ULL),((unsigned int)324170897ULL)};
unsigned int b_1[4]={((unsigned int)767439743ULL),((unsigned int)2065336567ULL),((unsigned int)1328045165ULL),((unsigned int)324170897ULL)};
unsigned int a_2[4]={((unsigned int)1571475806ULL),((unsigned int)1525599211ULL),((unsigned int)3078552926ULL),((unsigned int)3089703576ULL)};
unsigned int b_2[4]={((unsigned int)1571475806ULL),((unsigned int)1525599211ULL),((unsigned int)3078552926ULL),((unsigned int)3089703576ULL)};
unsigned int a_3[4]={((unsigned int)626610362ULL),((unsigned int)3757365641ULL),((unsigned int)3306197313ULL),((unsigned int)3723780835ULL)};
unsigned int b_3[4]={((unsigned int)626610362ULL),((unsigned int)3757365641ULL),((unsigned int)3306197313ULL),((unsigned int)3723780835ULL)};
unsigned int a_4[4]={((unsigned int)3092749354ULL),((unsigned int)3228982778ULL),((unsigned int)86102787ULL),((unsigned int)2521912441ULL)};
unsigned int b_4[4]={((unsigned int)3092749354ULL),((unsigned int)3228982778ULL),((unsigned int)86102787ULL),((unsigned int)2521912441ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2889584330ULL),((unsigned int)1844822254ULL),((unsigned int)3348966198ULL),((unsigned int)3943574692ULL),((unsigned int)1649520377ULL),((unsigned int)2795580181ULL),((unsigned int)2566856248ULL),((unsigned int)1628459151ULL),((unsigned int)1212837205ULL),((unsigned int)2651355685ULL),((unsigned int)3569179669ULL),((unsigned int)1801714720ULL),((unsigned int)1571305241ULL),((unsigned int)3900543556ULL),((unsigned int)1569068071ULL),((unsigned int)3684284395ULL)};
unsigned int b_0[16]={((unsigned int)2889584330ULL),((unsigned int)1844822254ULL),((unsigned int)3348966198ULL),((unsigned int)3943574692ULL),((unsigned int)1649520377ULL),((unsigned int)2795580181ULL),((unsigned int)2566856248ULL),((unsigned int)1628459151ULL),((unsigned int)1212837205ULL),((unsigned int)2651355685ULL),((unsigned int)3569179669ULL),((unsigned int)1801714720ULL),((unsigned int)1571305241ULL),((unsigned int)3900543556ULL),((unsigned int)1569068071ULL),((unsigned int)3684284395ULL)};
unsigned int a_1[4]={((unsigned int)2477253888ULL),((unsigned int)1648744844ULL),((unsigned int)4006840897ULL),((unsigned int)2052244090ULL)};
unsigned int b_1[4]={((unsigned int)2477253888ULL),((unsigned int)1648744844ULL),((unsigned int)4006840897ULL),((unsigned int)2052244090ULL)};
unsigned int a_2[4]={((unsigned int)3431523107ULL),((unsigned int)2261111238ULL),((unsigned int)4081479834ULL),((unsigned int)1218727578ULL)};
unsigned int b_2[4]={((unsigned int)3431523107ULL),((unsigned int)2261111238ULL),((unsigned int)4081479834ULL),((unsigned int)1218727578ULL)};
unsigned int a_3[4]={((unsigned int)3352548232ULL),((unsigned int)2052019591ULL),((unsigned int)3763119601ULL),((unsigned int)514813957ULL)};
unsigned int b_3[4]={((unsigned int)3352548232ULL),((unsigned int)2052019591ULL),((unsigned int)3763119601ULL),((unsigned int)514813957ULL)};
unsigned int a_4[4]={((unsigned int)1299175545ULL),((unsigned int)4187970490ULL),((unsigned int)778395454ULL),((unsigned int)2310741873ULL)};
unsigned int b_4[4]={((unsigned int)1299175545ULL),((unsigned int)4187970490ULL),((unsigned int)778395454ULL),((unsigned int)2310741873ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)636907440ULL),((unsigned int)1660109819ULL),((unsigned int)1039041336ULL),((unsigned int)4153336157ULL),((unsigned int)4090249978ULL),((unsigned int)3041507191ULL),((unsigned int)1810009961ULL),((unsigned int)3106218569ULL),((unsigned int)2258385281ULL),((unsigned int)244486901ULL),((unsigned int)2936890303ULL),((unsigned int)1319959471ULL),((unsigned int)4179490279ULL),((unsigned int)1904229543ULL),((unsigned int)2010675475ULL),((unsigned int)1593561065ULL)};
unsigned int b_0[16]={((unsigned int)636907440ULL),((unsigned int)1660109819ULL),((unsigned int)1039041336ULL),((unsigned int)4153336157ULL),((unsigned int)4090249978ULL),((unsigned int)3041507191ULL),((unsigned int)1810009961ULL),((unsigned int)3106218569ULL),((unsigned int)2258385281ULL),((unsigned int)244486901ULL),((unsigned int)2936890303ULL),((unsigned int)1319959471ULL),((unsigned int)4179490279ULL),((unsigned int)1904229543ULL),((unsigned int)2010675475ULL),((unsigned int)1593561065ULL)};
unsigned int a_1[4]={((unsigned int)504945249ULL),((unsigned int)1853872486ULL),((unsigned int)87355243ULL),((unsigned int)3145813150ULL)};
unsigned int b_1[4]={((unsigned int)504945249ULL),((unsigned int)1853872486ULL),((unsigned int)87355243ULL),((unsigned int)3145813150ULL)};
unsigned int a_2[4]={((unsigned int)4076309635ULL),((unsigned int)1240392964ULL),((unsigned int)1820456935ULL),((unsigned int)2418124134ULL)};
unsigned int b_2[4]={((unsigned int)4076309635ULL),((unsigned int)1240392964ULL),((unsigned int)1820456935ULL),((unsigned int)2418124134ULL)};
unsigned int a_3[4]={((unsigned int)415722905ULL),((unsigned int)3046891717ULL),((unsigned int)3116988344ULL),((unsigned int)1661175817ULL)};
unsigned int b_3[4]={((unsigned int)415722905ULL),((unsigned int)3046891717ULL),((unsigned int)3116988344ULL),((unsigned int)1661175817ULL)};
unsigned int a_4[4]={((unsigned int)851290595ULL),((unsigned int)1167526351ULL),((unsigned int)1207117916ULL),((unsigned int)3461435071ULL)};
unsigned int b_4[4]={((unsigned int)851290595ULL),((unsigned int)1167526351ULL),((unsigned int)1207117916ULL),((unsigned int)3461435071ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3409385865ULL),((unsigned int)1286583980ULL),((unsigned int)2996428110ULL),((unsigned int)2955909779ULL),((unsigned int)3462332615ULL),((unsigned int)912626070ULL),((unsigned int)2271910690ULL),((unsigned int)3821432547ULL),((unsigned int)207423537ULL),((unsigned int)3636131974ULL),((unsigned int)1702856571ULL),((unsigned int)306335064ULL),((unsigned int)3155817677ULL),((unsigned int)1063121496ULL),((unsigned int)2469796149ULL),((unsigned int)400194580ULL)};
unsigned int b_0[16]={((unsigned int)3409385865ULL),((unsigned int)1286583980ULL),((unsigned int)2996428110ULL),((unsigned int)2955909779ULL),((unsigned int)3462332615ULL),((unsigned int)912626070ULL),((unsigned int)2271910690ULL),((unsigned int)3821432547ULL),((unsigned int)207423537ULL),((unsigned int)3636131974ULL),((unsigned int)1702856571ULL),((unsigned int)306335064ULL),((unsigned int)3155817677ULL),((unsigned int)1063121496ULL),((unsigned int)2469796149ULL),((unsigned int)400194580ULL)};
unsigned int a_1[4]={((unsigned int)1860493534ULL),((unsigned int)2699373413ULL),((unsigned int)3279084496ULL),((unsigned int)4009321560ULL)};
unsigned int b_1[4]={((unsigned int)1860493534ULL),((unsigned int)2699373413ULL),((unsigned int)3279084496ULL),((unsigned int)4009321560ULL)};
unsigned int a_2[4]={((unsigned int)548072610ULL),((unsigned int)666222934ULL),((unsigned int)2864862684ULL),((unsigned int)3011703418ULL)};
unsigned int b_2[4]={((unsigned int)548072610ULL),((unsigned int)666222934ULL),((unsigned int)2864862684ULL),((unsigned int)3011703418ULL)};
unsigned int a_3[4]={((unsigned int)575874084ULL),((unsigned int)3481770050ULL),((unsigned int)1150693830ULL),((unsigned int)939448666ULL)};
unsigned int b_3[4]={((unsigned int)575874084ULL),((unsigned int)3481770050ULL),((unsigned int)1150693830ULL),((unsigned int)939448666ULL)};
unsigned int a_4[4]={((unsigned int)3059824246ULL),((unsigned int)662027313ULL),((unsigned int)217189136ULL),((unsigned int)1140519603ULL)};
unsigned int b_4[4]={((unsigned int)3059824246ULL),((unsigned int)662027313ULL),((unsigned int)217189136ULL),((unsigned int)1140519603ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2581694279ULL),((unsigned int)3002852043ULL),((unsigned int)1054206876ULL),((unsigned int)1612529279ULL),((unsigned int)2294426849ULL),((unsigned int)573675627ULL),((unsigned int)1512463155ULL),((unsigned int)3657357311ULL),((unsigned int)2561274286ULL),((unsigned int)1281321058ULL),((unsigned int)3927799660ULL),((unsigned int)42078874ULL),((unsigned int)516730454ULL),((unsigned int)1143053303ULL),((unsigned int)1293175268ULL),((unsigned int)801139585ULL)};
unsigned int b_0[16]={((unsigned int)2581694279ULL),((unsigned int)3002852043ULL),((unsigned int)1054206876ULL),((unsigned int)1612529279ULL),((unsigned int)2294426849ULL),((unsigned int)573675627ULL),((unsigned int)1512463155ULL),((unsigned int)3657357311ULL),((unsigned int)2561274286ULL),((unsigned int)1281321058ULL),((unsigned int)3927799660ULL),((unsigned int)42078874ULL),((unsigned int)516730454ULL),((unsigned int)1143053303ULL),((unsigned int)1293175268ULL),((unsigned int)801139585ULL)};
unsigned int a_1[4]={((unsigned int)288133852ULL),((unsigned int)2815716004ULL),((unsigned int)1800004692ULL),((unsigned int)2836080652ULL)};
unsigned int b_1[4]={((unsigned int)288133852ULL),((unsigned int)2815716004ULL),((unsigned int)1800004692ULL),((unsigned int)2836080652ULL)};
unsigned int a_2[4]={((unsigned int)2811271779ULL),((unsigned int)2582362046ULL),((unsigned int)735635315ULL),((unsigned int)3751998442ULL)};
unsigned int b_2[4]={((unsigned int)2811271779ULL),((unsigned int)2582362046ULL),((unsigned int)735635315ULL),((unsigned int)3751998442ULL)};
unsigned int a_3[4]={((unsigned int)2130094008ULL),((unsigned int)1996097097ULL),((unsigned int)78970169ULL),((unsigned int)741447460ULL)};
unsigned int b_3[4]={((unsigned int)2130094008ULL),((unsigned int)1996097097ULL),((unsigned int)78970169ULL),((unsigned int)741447460ULL)};
unsigned int a_4[4]={((unsigned int)2156067147ULL),((unsigned int)2121786564ULL),((unsigned int)270212310ULL),((unsigned int)1837110107ULL)};
unsigned int b_4[4]={((unsigned int)2156067147ULL),((unsigned int)2121786564ULL),((unsigned int)270212310ULL),((unsigned int)1837110107ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 31\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)457387849ULL),((unsigned int)474028643ULL),((unsigned int)556257621ULL),((unsigned int)3714612888ULL),((unsigned int)3169807402ULL),((unsigned int)623820718ULL),((unsigned int)3721526305ULL),((unsigned int)1620119696ULL),((unsigned int)1648855079ULL),((unsigned int)938467784ULL),((unsigned int)2882887674ULL),((unsigned int)68082832ULL),((unsigned int)3217891559ULL),((unsigned int)3063702129ULL),((unsigned int)1077751734ULL),((unsigned int)4102901893ULL)};
unsigned int b_0[16]={((unsigned int)457387849ULL),((unsigned int)474028643ULL),((unsigned int)556257621ULL),((unsigned int)3714612888ULL),((unsigned int)3169807402ULL),((unsigned int)623820718ULL),((unsigned int)3721526305ULL),((unsigned int)1620119696ULL),((unsigned int)1648855079ULL),((unsigned int)938467784ULL),((unsigned int)2882887674ULL),((unsigned int)68082832ULL),((unsigned int)3217891559ULL),((unsigned int)3063702129ULL),((unsigned int)1077751734ULL),((unsigned int)4102901893ULL)};
unsigned int a_1[4]={((unsigned int)2070480204ULL),((unsigned int)1424324750ULL),((unsigned int)3385122626ULL),((unsigned int)3552762725ULL)};
unsigned int b_1[4]={((unsigned int)2070480204ULL),((unsigned int)1424324750ULL),((unsigned int)3385122626ULL),((unsigned int)3552762725ULL)};
unsigned int a_2[4]={((unsigned int)3232267571ULL),((unsigned int)2192753205ULL),((unsigned int)4122220652ULL),((unsigned int)12281372ULL)};
unsigned int b_2[4]={((unsigned int)3232267571ULL),((unsigned int)2192753205ULL),((unsigned int)4122220652ULL),((unsigned int)12281372ULL)};
unsigned int a_3[4]={((unsigned int)3513897822ULL),((unsigned int)678549066ULL),((unsigned int)922508543ULL),((unsigned int)484335801ULL)};
unsigned int b_3[4]={((unsigned int)3513897822ULL),((unsigned int)678549066ULL),((unsigned int)922508543ULL),((unsigned int)484335801ULL)};
unsigned int a_4[4]={((unsigned int)2795216909ULL),((unsigned int)2254366247ULL),((unsigned int)2395753007ULL),((unsigned int)2838373618ULL)};
unsigned int b_4[4]={((unsigned int)2795216909ULL),((unsigned int)2254366247ULL),((unsigned int)2395753007ULL),((unsigned int)2838373618ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 32\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3738313341ULL),((unsigned int)561686460ULL),((unsigned int)681981120ULL),((unsigned int)2877520346ULL),((unsigned int)831392903ULL),((unsigned int)1873864883ULL),((unsigned int)2730807971ULL),((unsigned int)471741332ULL),((unsigned int)2822794723ULL),((unsigned int)3142676722ULL),((unsigned int)2608459696ULL),((unsigned int)943903188ULL),((unsigned int)458651931ULL),((unsigned int)2095920673ULL),((unsigned int)290499339ULL),((unsigned int)506981941ULL)};
unsigned int b_0[16]={((unsigned int)3738313341ULL),((unsigned int)561686460ULL),((unsigned int)681981120ULL),((unsigned int)2877520346ULL),((unsigned int)831392903ULL),((unsigned int)1873864883ULL),((unsigned int)2730807971ULL),((unsigned int)471741332ULL),((unsigned int)2822794723ULL),((unsigned int)3142676722ULL),((unsigned int)2608459696ULL),((unsigned int)943903188ULL),((unsigned int)458651931ULL),((unsigned int)2095920673ULL),((unsigned int)290499339ULL),((unsigned int)506981941ULL)};
unsigned int a_1[4]={((unsigned int)2230328118ULL),((unsigned int)3178919469ULL),((unsigned int)4253134292ULL),((unsigned int)1674344904ULL)};
unsigned int b_1[4]={((unsigned int)2230328118ULL),((unsigned int)3178919469ULL),((unsigned int)4253134292ULL),((unsigned int)1674344904ULL)};
unsigned int a_2[4]={((unsigned int)3277251699ULL),((unsigned int)335734496ULL),((unsigned int)3524175842ULL),((unsigned int)2871450126ULL)};
unsigned int b_2[4]={((unsigned int)3277251699ULL),((unsigned int)335734496ULL),((unsigned int)3524175842ULL),((unsigned int)2871450126ULL)};
unsigned int a_3[4]={((unsigned int)1458245136ULL),((unsigned int)1451152664ULL),((unsigned int)3060219244ULL),((unsigned int)2289338141ULL)};
unsigned int b_3[4]={((unsigned int)1458245136ULL),((unsigned int)1451152664ULL),((unsigned int)3060219244ULL),((unsigned int)2289338141ULL)};
unsigned int a_4[4]={((unsigned int)4154486815ULL),((unsigned int)3419170305ULL),((unsigned int)975622942ULL),((unsigned int)402909600ULL)};
unsigned int b_4[4]={((unsigned int)4154486815ULL),((unsigned int)3419170305ULL),((unsigned int)975622942ULL),((unsigned int)402909600ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 33\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1167113022ULL),((unsigned int)493879993ULL),((unsigned int)4040794490ULL),((unsigned int)4046676557ULL),((unsigned int)1415528710ULL),((unsigned int)1180564665ULL),((unsigned int)1862129407ULL),((unsigned int)1787831359ULL),((unsigned int)1330977706ULL),((unsigned int)2419079179ULL),((unsigned int)1753512690ULL),((unsigned int)2430702215ULL),((unsigned int)3183039650ULL),((unsigned int)2931993533ULL),((unsigned int)2499296672ULL),((unsigned int)1663292044ULL)};
unsigned int b_0[16]={((unsigned int)1167113022ULL),((unsigned int)493879993ULL),((unsigned int)4040794490ULL),((unsigned int)4046676557ULL),((unsigned int)1415528710ULL),((unsigned int)1180564665ULL),((unsigned int)1862129407ULL),((unsigned int)1787831359ULL),((unsigned int)1330977706ULL),((unsigned int)2419079179ULL),((unsigned int)1753512690ULL),((unsigned int)2430702215ULL),((unsigned int)3183039650ULL),((unsigned int)2931993533ULL),((unsigned int)2499296672ULL),((unsigned int)1663292044ULL)};
unsigned int a_1[4]={((unsigned int)3750448803ULL),((unsigned int)3062661365ULL),((unsigned int)710014498ULL),((unsigned int)2018390069ULL)};
unsigned int b_1[4]={((unsigned int)3750448803ULL),((unsigned int)3062661365ULL),((unsigned int)710014498ULL),((unsigned int)2018390069ULL)};
unsigned int a_2[4]={((unsigned int)4261150226ULL),((unsigned int)3381170286ULL),((unsigned int)3611408037ULL),((unsigned int)3048095724ULL)};
unsigned int b_2[4]={((unsigned int)4261150226ULL),((unsigned int)3381170286ULL),((unsigned int)3611408037ULL),((unsigned int)3048095724ULL)};
unsigned int a_3[4]={((unsigned int)3186670617ULL),((unsigned int)96410629ULL),((unsigned int)4278916726ULL),((unsigned int)3671981753ULL)};
unsigned int b_3[4]={((unsigned int)3186670617ULL),((unsigned int)96410629ULL),((unsigned int)4278916726ULL),((unsigned int)3671981753ULL)};
unsigned int a_4[4]={((unsigned int)4289349087ULL),((unsigned int)2873160009ULL),((unsigned int)408319541ULL),((unsigned int)1829414333ULL)};
unsigned int b_4[4]={((unsigned int)4289349087ULL),((unsigned int)2873160009ULL),((unsigned int)408319541ULL),((unsigned int)1829414333ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 34\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2258847464ULL),((unsigned int)855029215ULL),((unsigned int)2272911481ULL),((unsigned int)1876348122ULL),((unsigned int)1891919708ULL),((unsigned int)253464663ULL),((unsigned int)2500822721ULL),((unsigned int)2488143188ULL),((unsigned int)3017999779ULL),((unsigned int)1521157277ULL),((unsigned int)1042710984ULL),((unsigned int)3482368290ULL),((unsigned int)2232626421ULL),((unsigned int)2195991953ULL),((unsigned int)4071102260ULL),((unsigned int)1901647778ULL)};
unsigned int b_0[16]={((unsigned int)2258847464ULL),((unsigned int)855029215ULL),((unsigned int)2272911481ULL),((unsigned int)1876348122ULL),((unsigned int)1891919708ULL),((unsigned int)253464663ULL),((unsigned int)2500822721ULL),((unsigned int)2488143188ULL),((unsigned int)3017999779ULL),((unsigned int)1521157277ULL),((unsigned int)1042710984ULL),((unsigned int)3482368290ULL),((unsigned int)2232626421ULL),((unsigned int)2195991953ULL),((unsigned int)4071102260ULL),((unsigned int)1901647778ULL)};
unsigned int a_1[4]={((unsigned int)120624921ULL),((unsigned int)3691213964ULL),((unsigned int)2258184113ULL),((unsigned int)2879926368ULL)};
unsigned int b_1[4]={((unsigned int)120624921ULL),((unsigned int)3691213964ULL),((unsigned int)2258184113ULL),((unsigned int)2879926368ULL)};
unsigned int a_2[4]={((unsigned int)4070247863ULL),((unsigned int)3066312015ULL),((unsigned int)1714777429ULL),((unsigned int)3018581337ULL)};
unsigned int b_2[4]={((unsigned int)4070247863ULL),((unsigned int)3066312015ULL),((unsigned int)1714777429ULL),((unsigned int)3018581337ULL)};
unsigned int a_3[4]={((unsigned int)4152494175ULL),((unsigned int)2404249550ULL),((unsigned int)3656055795ULL),((unsigned int)1530851365ULL)};
unsigned int b_3[4]={((unsigned int)4152494175ULL),((unsigned int)2404249550ULL),((unsigned int)3656055795ULL),((unsigned int)1530851365ULL)};
unsigned int a_4[4]={((unsigned int)1060421912ULL),((unsigned int)3307524220ULL),((unsigned int)1149725351ULL),((unsigned int)366250290ULL)};
unsigned int b_4[4]={((unsigned int)1060421912ULL),((unsigned int)3307524220ULL),((unsigned int)1149725351ULL),((unsigned int)366250290ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 35\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3847925333ULL),((unsigned int)3934247315ULL),((unsigned int)392644939ULL),((unsigned int)2192402321ULL),((unsigned int)1377741988ULL),((unsigned int)3814251061ULL),((unsigned int)1842290240ULL),((unsigned int)3058730097ULL),((unsigned int)4036982921ULL),((unsigned int)1477630606ULL),((unsigned int)971423371ULL),((unsigned int)4109186300ULL),((unsigned int)1133153420ULL),((unsigned int)231479222ULL),((unsigned int)2985945455ULL),((unsigned int)2208247025ULL)};
unsigned int b_0[16]={((unsigned int)3847925333ULL),((unsigned int)3934247315ULL),((unsigned int)392644939ULL),((unsigned int)2192402321ULL),((unsigned int)1377741988ULL),((unsigned int)3814251061ULL),((unsigned int)1842290240ULL),((unsigned int)3058730097ULL),((unsigned int)4036982921ULL),((unsigned int)1477630606ULL),((unsigned int)971423371ULL),((unsigned int)4109186300ULL),((unsigned int)1133153420ULL),((unsigned int)231479222ULL),((unsigned int)2985945455ULL),((unsigned int)2208247025ULL)};
unsigned int a_1[4]={((unsigned int)2460493778ULL),((unsigned int)397245307ULL),((unsigned int)847446790ULL),((unsigned int)2769009677ULL)};
unsigned int b_1[4]={((unsigned int)2460493778ULL),((unsigned int)397245307ULL),((unsigned int)847446790ULL),((unsigned int)2769009677ULL)};
unsigned int a_2[4]={((unsigned int)3308538702ULL),((unsigned int)3667837158ULL),((unsigned int)3461026760ULL),((unsigned int)366742046ULL)};
unsigned int b_2[4]={((unsigned int)3308538702ULL),((unsigned int)3667837158ULL),((unsigned int)3461026760ULL),((unsigned int)366742046ULL)};
unsigned int a_3[4]={((unsigned int)2305726600ULL),((unsigned int)2894083694ULL),((unsigned int)3224625039ULL),((unsigned int)3436060637ULL)};
unsigned int b_3[4]={((unsigned int)2305726600ULL),((unsigned int)2894083694ULL),((unsigned int)3224625039ULL),((unsigned int)3436060637ULL)};
unsigned int a_4[4]={((unsigned int)832727763ULL),((unsigned int)3626967701ULL),((unsigned int)235474156ULL),((unsigned int)3896508341ULL)};
unsigned int b_4[4]={((unsigned int)832727763ULL),((unsigned int)3626967701ULL),((unsigned int)235474156ULL),((unsigned int)3896508341ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 36\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)407068708ULL),((unsigned int)1609304807ULL),((unsigned int)3549805797ULL),((unsigned int)2090621035ULL),((unsigned int)404969711ULL),((unsigned int)2067809375ULL),((unsigned int)962784464ULL),((unsigned int)3502478813ULL),((unsigned int)2308934397ULL),((unsigned int)308098779ULL),((unsigned int)2535097291ULL),((unsigned int)3268428550ULL),((unsigned int)917579773ULL),((unsigned int)1797902126ULL),((unsigned int)2016331753ULL),((unsigned int)3552330536ULL)};
unsigned int b_0[16]={((unsigned int)407068708ULL),((unsigned int)1609304807ULL),((unsigned int)3549805797ULL),((unsigned int)2090621035ULL),((unsigned int)404969711ULL),((unsigned int)2067809375ULL),((unsigned int)962784464ULL),((unsigned int)3502478813ULL),((unsigned int)2308934397ULL),((unsigned int)308098779ULL),((unsigned int)2535097291ULL),((unsigned int)3268428550ULL),((unsigned int)917579773ULL),((unsigned int)1797902126ULL),((unsigned int)2016331753ULL),((unsigned int)3552330536ULL)};
unsigned int a_1[4]={((unsigned int)2390953326ULL),((unsigned int)1219837758ULL),((unsigned int)3229392008ULL),((unsigned int)527706071ULL)};
unsigned int b_1[4]={((unsigned int)2390953326ULL),((unsigned int)1219837758ULL),((unsigned int)3229392008ULL),((unsigned int)527706071ULL)};
unsigned int a_2[4]={((unsigned int)2189626202ULL),((unsigned int)1437794479ULL),((unsigned int)236551883ULL),((unsigned int)2952875015ULL)};
unsigned int b_2[4]={((unsigned int)2189626202ULL),((unsigned int)1437794479ULL),((unsigned int)236551883ULL),((unsigned int)2952875015ULL)};
unsigned int a_3[4]={((unsigned int)458694500ULL),((unsigned int)526507612ULL),((unsigned int)1330979239ULL),((unsigned int)2613734232ULL)};
unsigned int b_3[4]={((unsigned int)458694500ULL),((unsigned int)526507612ULL),((unsigned int)1330979239ULL),((unsigned int)2613734232ULL)};
unsigned int a_4[4]={((unsigned int)2371902379ULL),((unsigned int)3338104302ULL),((unsigned int)2690478051ULL),((unsigned int)194984959ULL)};
unsigned int b_4[4]={((unsigned int)2371902379ULL),((unsigned int)3338104302ULL),((unsigned int)2690478051ULL),((unsigned int)194984959ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 37\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)851478206ULL),((unsigned int)2322526145ULL),((unsigned int)1721503810ULL),((unsigned int)833055392ULL),((unsigned int)157621846ULL),((unsigned int)970931531ULL),((unsigned int)3038703294ULL),((unsigned int)104296698ULL),((unsigned int)2450417930ULL),((unsigned int)4224652993ULL),((unsigned int)16196719ULL),((unsigned int)960285735ULL),((unsigned int)710853379ULL),((unsigned int)2357578742ULL),((unsigned int)1542931175ULL),((unsigned int)3895168920ULL)};
unsigned int b_0[16]={((unsigned int)851478206ULL),((unsigned int)2322526145ULL),((unsigned int)1721503810ULL),((unsigned int)833055392ULL),((unsigned int)157621846ULL),((unsigned int)970931531ULL),((unsigned int)3038703294ULL),((unsigned int)104296698ULL),((unsigned int)2450417930ULL),((unsigned int)4224652993ULL),((unsigned int)16196719ULL),((unsigned int)960285735ULL),((unsigned int)710853379ULL),((unsigned int)2357578742ULL),((unsigned int)1542931175ULL),((unsigned int)3895168920ULL)};
unsigned int a_1[4]={((unsigned int)1990416552ULL),((unsigned int)4120670631ULL),((unsigned int)3312035210ULL),((unsigned int)3479288648ULL)};
unsigned int b_1[4]={((unsigned int)1990416552ULL),((unsigned int)4120670631ULL),((unsigned int)3312035210ULL),((unsigned int)3479288648ULL)};
unsigned int a_2[4]={((unsigned int)3979996749ULL),((unsigned int)1108944211ULL),((unsigned int)3858175619ULL),((unsigned int)3914415977ULL)};
unsigned int b_2[4]={((unsigned int)3979996749ULL),((unsigned int)1108944211ULL),((unsigned int)3858175619ULL),((unsigned int)3914415977ULL)};
unsigned int a_3[4]={((unsigned int)1783943379ULL),((unsigned int)609602080ULL),((unsigned int)3146202534ULL),((unsigned int)4222541685ULL)};
unsigned int b_3[4]={((unsigned int)1783943379ULL),((unsigned int)609602080ULL),((unsigned int)3146202534ULL),((unsigned int)4222541685ULL)};
unsigned int a_4[4]={((unsigned int)912156361ULL),((unsigned int)1418258738ULL),((unsigned int)2999658945ULL),((unsigned int)3380003524ULL)};
unsigned int b_4[4]={((unsigned int)912156361ULL),((unsigned int)1418258738ULL),((unsigned int)2999658945ULL),((unsigned int)3380003524ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 38\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1167204593ULL),((unsigned int)4215571817ULL),((unsigned int)303086072ULL),((unsigned int)3075252337ULL),((unsigned int)1978395227ULL),((unsigned int)2233049753ULL),((unsigned int)1182523734ULL),((unsigned int)2417403242ULL),((unsigned int)3403149711ULL),((unsigned int)1014202674ULL),((unsigned int)1394059790ULL),((unsigned int)2243627251ULL),((unsigned int)2195752350ULL),((unsigned int)3519236223ULL),((unsigned int)526563829ULL),((unsigned int)4097168591ULL)};
unsigned int b_0[16]={((unsigned int)1167204593ULL),((unsigned int)4215571817ULL),((unsigned int)303086072ULL),((unsigned int)3075252337ULL),((unsigned int)1978395227ULL),((unsigned int)2233049753ULL),((unsigned int)1182523734ULL),((unsigned int)2417403242ULL),((unsigned int)3403149711ULL),((unsigned int)1014202674ULL),((unsigned int)1394059790ULL),((unsigned int)2243627251ULL),((unsigned int)2195752350ULL),((unsigned int)3519236223ULL),((unsigned int)526563829ULL),((unsigned int)4097168591ULL)};
unsigned int a_1[4]={((unsigned int)730107201ULL),((unsigned int)618911144ULL),((unsigned int)1387699514ULL),((unsigned int)171672644ULL)};
unsigned int b_1[4]={((unsigned int)730107201ULL),((unsigned int)618911144ULL),((unsigned int)1387699514ULL),((unsigned int)171672644ULL)};
unsigned int a_2[4]={((unsigned int)1218171443ULL),((unsigned int)869710159ULL),((unsigned int)2269610681ULL),((unsigned int)2274853657ULL)};
unsigned int b_2[4]={((unsigned int)1218171443ULL),((unsigned int)869710159ULL),((unsigned int)2269610681ULL),((unsigned int)2274853657ULL)};
unsigned int a_3[4]={((unsigned int)3699749616ULL),((unsigned int)685367575ULL),((unsigned int)4287025595ULL),((unsigned int)3520388815ULL)};
unsigned int b_3[4]={((unsigned int)3699749616ULL),((unsigned int)685367575ULL),((unsigned int)4287025595ULL),((unsigned int)3520388815ULL)};
unsigned int a_4[4]={((unsigned int)2573442906ULL),((unsigned int)4243340687ULL),((unsigned int)2178167393ULL),((unsigned int)3960903600ULL)};
unsigned int b_4[4]={((unsigned int)2573442906ULL),((unsigned int)4243340687ULL),((unsigned int)2178167393ULL),((unsigned int)3960903600ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 39\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)865486921ULL),((unsigned int)29922233ULL),((unsigned int)3833081296ULL),((unsigned int)2910710145ULL),((unsigned int)3889823688ULL),((unsigned int)540801159ULL),((unsigned int)3414737641ULL),((unsigned int)2416236556ULL),((unsigned int)1065457471ULL),((unsigned int)1771341697ULL),((unsigned int)3445341538ULL),((unsigned int)1586728507ULL),((unsigned int)891866946ULL),((unsigned int)1623061753ULL),((unsigned int)3313876344ULL),((unsigned int)434928876ULL)};
unsigned int b_0[16]={((unsigned int)865486921ULL),((unsigned int)29922233ULL),((unsigned int)3833081296ULL),((unsigned int)2910710145ULL),((unsigned int)3889823688ULL),((unsigned int)540801159ULL),((unsigned int)3414737641ULL),((unsigned int)2416236556ULL),((unsigned int)1065457471ULL),((unsigned int)1771341697ULL),((unsigned int)3445341538ULL),((unsigned int)1586728507ULL),((unsigned int)891866946ULL),((unsigned int)1623061753ULL),((unsigned int)3313876344ULL),((unsigned int)434928876ULL)};
unsigned int a_1[4]={((unsigned int)766788876ULL),((unsigned int)284597191ULL),((unsigned int)3761769795ULL),((unsigned int)253852893ULL)};
unsigned int b_1[4]={((unsigned int)766788876ULL),((unsigned int)284597191ULL),((unsigned int)3761769795ULL),((unsigned int)253852893ULL)};
unsigned int a_2[4]={((unsigned int)222400979ULL),((unsigned int)924212678ULL),((unsigned int)4181790091ULL),((unsigned int)3677827934ULL)};
unsigned int b_2[4]={((unsigned int)222400979ULL),((unsigned int)924212678ULL),((unsigned int)4181790091ULL),((unsigned int)3677827934ULL)};
unsigned int a_3[4]={((unsigned int)3955464577ULL),((unsigned int)2572965966ULL),((unsigned int)690451488ULL),((unsigned int)39151321ULL)};
unsigned int b_3[4]={((unsigned int)3955464577ULL),((unsigned int)2572965966ULL),((unsigned int)690451488ULL),((unsigned int)39151321ULL)};
unsigned int a_4[4]={((unsigned int)3653028490ULL),((unsigned int)2500047480ULL),((unsigned int)1114781713ULL),((unsigned int)1318686691ULL)};
unsigned int b_4[4]={((unsigned int)3653028490ULL),((unsigned int)2500047480ULL),((unsigned int)1114781713ULL),((unsigned int)1318686691ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 40\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3530690ULL),((unsigned int)3611555133ULL),((unsigned int)2200125310ULL),((unsigned int)1447490576ULL),((unsigned int)4165909842ULL),((unsigned int)2075302238ULL),((unsigned int)2989880758ULL),((unsigned int)2109854019ULL),((unsigned int)1910741713ULL),((unsigned int)1382959024ULL),((unsigned int)730246342ULL),((unsigned int)4046542813ULL),((unsigned int)4018646249ULL),((unsigned int)90375380ULL),((unsigned int)2692881437ULL),((unsigned int)3455720910ULL)};
unsigned int b_0[16]={((unsigned int)3530690ULL),((unsigned int)3611555133ULL),((unsigned int)2200125310ULL),((unsigned int)1447490576ULL),((unsigned int)4165909842ULL),((unsigned int)2075302238ULL),((unsigned int)2989880758ULL),((unsigned int)2109854019ULL),((unsigned int)1910741713ULL),((unsigned int)1382959024ULL),((unsigned int)730246342ULL),((unsigned int)4046542813ULL),((unsigned int)4018646249ULL),((unsigned int)90375380ULL),((unsigned int)2692881437ULL),((unsigned int)3455720910ULL)};
unsigned int a_1[4]={((unsigned int)214001180ULL),((unsigned int)305716812ULL),((unsigned int)3162105922ULL),((unsigned int)931584499ULL)};
unsigned int b_1[4]={((unsigned int)214001180ULL),((unsigned int)305716812ULL),((unsigned int)3162105922ULL),((unsigned int)931584499ULL)};
unsigned int a_2[4]={((unsigned int)1059784777ULL),((unsigned int)2922152820ULL),((unsigned int)1542762729ULL),((unsigned int)972995120ULL)};
unsigned int b_2[4]={((unsigned int)1059784777ULL),((unsigned int)2922152820ULL),((unsigned int)1542762729ULL),((unsigned int)972995120ULL)};
unsigned int a_3[4]={((unsigned int)3181383546ULL),((unsigned int)2776740719ULL),((unsigned int)4261252149ULL),((unsigned int)991883210ULL)};
unsigned int b_3[4]={((unsigned int)3181383546ULL),((unsigned int)2776740719ULL),((unsigned int)4261252149ULL),((unsigned int)991883210ULL)};
unsigned int a_4[4]={((unsigned int)3620829572ULL),((unsigned int)73120191ULL),((unsigned int)4112065693ULL),((unsigned int)3901578557ULL)};
unsigned int b_4[4]={((unsigned int)3620829572ULL),((unsigned int)73120191ULL),((unsigned int)4112065693ULL),((unsigned int)3901578557ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 41\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3125579201ULL),((unsigned int)2613248651ULL),((unsigned int)2622708054ULL),((unsigned int)3022551876ULL),((unsigned int)2001822194ULL),((unsigned int)2094586482ULL),((unsigned int)594227565ULL),((unsigned int)3475705565ULL),((unsigned int)2624826787ULL),((unsigned int)2296087905ULL),((unsigned int)3418955955ULL),((unsigned int)3817243619ULL),((unsigned int)1700529279ULL),((unsigned int)2474017770ULL),((unsigned int)552019379ULL),((unsigned int)1040866863ULL)};
unsigned int b_0[16]={((unsigned int)3125579201ULL),((unsigned int)2613248651ULL),((unsigned int)2622708054ULL),((unsigned int)3022551876ULL),((unsigned int)2001822194ULL),((unsigned int)2094586482ULL),((unsigned int)594227565ULL),((unsigned int)3475705565ULL),((unsigned int)2624826787ULL),((unsigned int)2296087905ULL),((unsigned int)3418955955ULL),((unsigned int)3817243619ULL),((unsigned int)1700529279ULL),((unsigned int)2474017770ULL),((unsigned int)552019379ULL),((unsigned int)1040866863ULL)};
unsigned int a_1[4]={((unsigned int)2198492700ULL),((unsigned int)1015176769ULL),((unsigned int)4203421752ULL),((unsigned int)4101322740ULL)};
unsigned int b_1[4]={((unsigned int)2198492700ULL),((unsigned int)1015176769ULL),((unsigned int)4203421752ULL),((unsigned int)4101322740ULL)};
unsigned int a_2[4]={((unsigned int)1577492747ULL),((unsigned int)3576089386ULL),((unsigned int)2890567736ULL),((unsigned int)3297813696ULL)};
unsigned int b_2[4]={((unsigned int)1577492747ULL),((unsigned int)3576089386ULL),((unsigned int)2890567736ULL),((unsigned int)3297813696ULL)};
unsigned int a_3[4]={((unsigned int)3812956830ULL),((unsigned int)3434381461ULL),((unsigned int)3887544873ULL),((unsigned int)448993712ULL)};
unsigned int b_3[4]={((unsigned int)3812956830ULL),((unsigned int)3434381461ULL),((unsigned int)3887544873ULL),((unsigned int)448993712ULL)};
unsigned int a_4[4]={((unsigned int)2449915827ULL),((unsigned int)1626367552ULL),((unsigned int)3779627296ULL),((unsigned int)1851418452ULL)};
unsigned int b_4[4]={((unsigned int)2449915827ULL),((unsigned int)1626367552ULL),((unsigned int)3779627296ULL),((unsigned int)1851418452ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 42\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)91379122ULL),((unsigned int)1543790755ULL),((unsigned int)2776362951ULL),((unsigned int)2841680355ULL),((unsigned int)3169187512ULL),((unsigned int)1356403002ULL),((unsigned int)4216479787ULL),((unsigned int)3885644327ULL),((unsigned int)1274039238ULL),((unsigned int)1964212285ULL),((unsigned int)3863274272ULL),((unsigned int)3315000897ULL),((unsigned int)1908902954ULL),((unsigned int)3638752431ULL),((unsigned int)3155704598ULL),((unsigned int)2525646996ULL)};
unsigned int b_0[16]={((unsigned int)91379122ULL),((unsigned int)1543790755ULL),((unsigned int)2776362951ULL),((unsigned int)2841680355ULL),((unsigned int)3169187512ULL),((unsigned int)1356403002ULL),((unsigned int)4216479787ULL),((unsigned int)3885644327ULL),((unsigned int)1274039238ULL),((unsigned int)1964212285ULL),((unsigned int)3863274272ULL),((unsigned int)3315000897ULL),((unsigned int)1908902954ULL),((unsigned int)3638752431ULL),((unsigned int)3155704598ULL),((unsigned int)2525646996ULL)};
unsigned int a_1[4]={((unsigned int)1834417554ULL),((unsigned int)675888632ULL),((unsigned int)1353726654ULL),((unsigned int)1946537808ULL)};
unsigned int b_1[4]={((unsigned int)1834417554ULL),((unsigned int)675888632ULL),((unsigned int)1353726654ULL),((unsigned int)1946537808ULL)};
unsigned int a_2[4]={((unsigned int)3617541125ULL),((unsigned int)1810652517ULL),((unsigned int)2680481989ULL),((unsigned int)4055012629ULL)};
unsigned int b_2[4]={((unsigned int)3617541125ULL),((unsigned int)1810652517ULL),((unsigned int)2680481989ULL),((unsigned int)4055012629ULL)};
unsigned int a_3[4]={((unsigned int)923314873ULL),((unsigned int)3375062507ULL),((unsigned int)3873035515ULL),((unsigned int)2183311676ULL)};
unsigned int b_3[4]={((unsigned int)923314873ULL),((unsigned int)3375062507ULL),((unsigned int)3873035515ULL),((unsigned int)2183311676ULL)};
unsigned int a_4[4]={((unsigned int)2372343744ULL),((unsigned int)1371622083ULL),((unsigned int)2444367397ULL),((unsigned int)2191319658ULL)};
unsigned int b_4[4]={((unsigned int)2372343744ULL),((unsigned int)1371622083ULL),((unsigned int)2444367397ULL),((unsigned int)2191319658ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 43\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)653746871ULL),((unsigned int)323354821ULL),((unsigned int)4217115391ULL),((unsigned int)370686315ULL),((unsigned int)4292986412ULL),((unsigned int)2299980147ULL),((unsigned int)1041601615ULL),((unsigned int)1649868768ULL),((unsigned int)806076450ULL),((unsigned int)3417726576ULL),((unsigned int)3523263429ULL),((unsigned int)1880397043ULL),((unsigned int)1625038697ULL),((unsigned int)2858725990ULL),((unsigned int)4092976281ULL),((unsigned int)347578402ULL)};
unsigned int b_0[16]={((unsigned int)653746871ULL),((unsigned int)323354821ULL),((unsigned int)4217115391ULL),((unsigned int)370686315ULL),((unsigned int)4292986412ULL),((unsigned int)2299980147ULL),((unsigned int)1041601615ULL),((unsigned int)1649868768ULL),((unsigned int)806076450ULL),((unsigned int)3417726576ULL),((unsigned int)3523263429ULL),((unsigned int)1880397043ULL),((unsigned int)1625038697ULL),((unsigned int)2858725990ULL),((unsigned int)4092976281ULL),((unsigned int)347578402ULL)};
unsigned int a_1[4]={((unsigned int)659495576ULL),((unsigned int)636039939ULL),((unsigned int)2189701272ULL),((unsigned int)1371764491ULL)};
unsigned int b_1[4]={((unsigned int)659495576ULL),((unsigned int)636039939ULL),((unsigned int)2189701272ULL),((unsigned int)1371764491ULL)};
unsigned int a_2[4]={((unsigned int)2956657978ULL),((unsigned int)691764211ULL),((unsigned int)2404029058ULL),((unsigned int)4100086182ULL)};
unsigned int b_2[4]={((unsigned int)2956657978ULL),((unsigned int)691764211ULL),((unsigned int)2404029058ULL),((unsigned int)4100086182ULL)};
unsigned int a_3[4]={((unsigned int)2290636847ULL),((unsigned int)1490683320ULL),((unsigned int)2379615129ULL),((unsigned int)4223524591ULL)};
unsigned int b_3[4]={((unsigned int)2290636847ULL),((unsigned int)1490683320ULL),((unsigned int)2379615129ULL),((unsigned int)4223524591ULL)};
unsigned int a_4[4]={((unsigned int)604045779ULL),((unsigned int)3964808971ULL),((unsigned int)886504205ULL),((unsigned int)3711154551ULL)};
unsigned int b_4[4]={((unsigned int)604045779ULL),((unsigned int)3964808971ULL),((unsigned int)886504205ULL),((unsigned int)3711154551ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 44\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2334356056ULL),((unsigned int)1063238540ULL),((unsigned int)3879490881ULL),((unsigned int)3742562818ULL),((unsigned int)3223123644ULL),((unsigned int)2344803623ULL),((unsigned int)2186476681ULL),((unsigned int)1674653044ULL),((unsigned int)4021499229ULL),((unsigned int)64330254ULL),((unsigned int)4161086246ULL),((unsigned int)3998068180ULL),((unsigned int)664578764ULL),((unsigned int)229058802ULL),((unsigned int)1430156288ULL),((unsigned int)3040195672ULL)};
unsigned int b_0[16]={((unsigned int)2334356056ULL),((unsigned int)1063238540ULL),((unsigned int)3879490881ULL),((unsigned int)3742562818ULL),((unsigned int)3223123644ULL),((unsigned int)2344803623ULL),((unsigned int)2186476681ULL),((unsigned int)1674653044ULL),((unsigned int)4021499229ULL),((unsigned int)64330254ULL),((unsigned int)4161086246ULL),((unsigned int)3998068180ULL),((unsigned int)664578764ULL),((unsigned int)229058802ULL),((unsigned int)1430156288ULL),((unsigned int)3040195672ULL)};
unsigned int a_1[4]={((unsigned int)111492916ULL),((unsigned int)2833492309ULL),((unsigned int)1379370882ULL),((unsigned int)1269363128ULL)};
unsigned int b_1[4]={((unsigned int)111492916ULL),((unsigned int)2833492309ULL),((unsigned int)1379370882ULL),((unsigned int)1269363128ULL)};
unsigned int a_2[4]={((unsigned int)2709673104ULL),((unsigned int)1633612905ULL),((unsigned int)1762994769ULL),((unsigned int)162122543ULL)};
unsigned int b_2[4]={((unsigned int)2709673104ULL),((unsigned int)1633612905ULL),((unsigned int)1762994769ULL),((unsigned int)162122543ULL)};
unsigned int a_3[4]={((unsigned int)842924949ULL),((unsigned int)1674752405ULL),((unsigned int)1605711882ULL),((unsigned int)2417748563ULL)};
unsigned int b_3[4]={((unsigned int)842924949ULL),((unsigned int)1674752405ULL),((unsigned int)1605711882ULL),((unsigned int)2417748563ULL)};
unsigned int a_4[4]={((unsigned int)2566289681ULL),((unsigned int)349777106ULL),((unsigned int)1049416677ULL),((unsigned int)741394052ULL)};
unsigned int b_4[4]={((unsigned int)2566289681ULL),((unsigned int)349777106ULL),((unsigned int)1049416677ULL),((unsigned int)741394052ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 45\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1419036557ULL),((unsigned int)3177818146ULL),((unsigned int)3529257751ULL),((unsigned int)3503138923ULL),((unsigned int)2868437311ULL),((unsigned int)2253203808ULL),((unsigned int)954072654ULL),((unsigned int)2810030628ULL),((unsigned int)311951658ULL),((unsigned int)779744791ULL),((unsigned int)4202289041ULL),((unsigned int)1387378895ULL),((unsigned int)75671505ULL),((unsigned int)2393268633ULL),((unsigned int)1599500036ULL),((unsigned int)2075348301ULL)};
unsigned int b_0[16]={((unsigned int)1419036557ULL),((unsigned int)3177818146ULL),((unsigned int)3529257751ULL),((unsigned int)3503138923ULL),((unsigned int)2868437311ULL),((unsigned int)2253203808ULL),((unsigned int)954072654ULL),((unsigned int)2810030628ULL),((unsigned int)311951658ULL),((unsigned int)779744791ULL),((unsigned int)4202289041ULL),((unsigned int)1387378895ULL),((unsigned int)75671505ULL),((unsigned int)2393268633ULL),((unsigned int)1599500036ULL),((unsigned int)2075348301ULL)};
unsigned int a_1[4]={((unsigned int)3023819926ULL),((unsigned int)4245805739ULL),((unsigned int)2807401117ULL),((unsigned int)2524905664ULL)};
unsigned int b_1[4]={((unsigned int)3023819926ULL),((unsigned int)4245805739ULL),((unsigned int)2807401117ULL),((unsigned int)2524905664ULL)};
unsigned int a_2[4]={((unsigned int)573701151ULL),((unsigned int)1041158994ULL),((unsigned int)3094584878ULL),((unsigned int)2332296740ULL)};
unsigned int b_2[4]={((unsigned int)573701151ULL),((unsigned int)1041158994ULL),((unsigned int)3094584878ULL),((unsigned int)2332296740ULL)};
unsigned int a_3[4]={((unsigned int)1159970563ULL),((unsigned int)3305095198ULL),((unsigned int)1012876530ULL),((unsigned int)3494244960ULL)};
unsigned int b_3[4]={((unsigned int)1159970563ULL),((unsigned int)3305095198ULL),((unsigned int)1012876530ULL),((unsigned int)3494244960ULL)};
unsigned int a_4[4]={((unsigned int)191200876ULL),((unsigned int)1486133201ULL),((unsigned int)957887597ULL),((unsigned int)3652277140ULL)};
unsigned int b_4[4]={((unsigned int)191200876ULL),((unsigned int)1486133201ULL),((unsigned int)957887597ULL),((unsigned int)3652277140ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 46\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2571630094ULL),((unsigned int)3052840541ULL),((unsigned int)1123517425ULL),((unsigned int)3016804289ULL),((unsigned int)3642192099ULL),((unsigned int)2544191147ULL),((unsigned int)553926693ULL),((unsigned int)1006663419ULL),((unsigned int)141455419ULL),((unsigned int)2577525308ULL),((unsigned int)3532813781ULL),((unsigned int)1479290607ULL),((unsigned int)3806779051ULL),((unsigned int)144853798ULL),((unsigned int)4167350852ULL),((unsigned int)2478881062ULL)};
unsigned int b_0[16]={((unsigned int)2571630094ULL),((unsigned int)3052840541ULL),((unsigned int)1123517425ULL),((unsigned int)3016804289ULL),((unsigned int)3642192099ULL),((unsigned int)2544191147ULL),((unsigned int)553926693ULL),((unsigned int)1006663419ULL),((unsigned int)141455419ULL),((unsigned int)2577525308ULL),((unsigned int)3532813781ULL),((unsigned int)1479290607ULL),((unsigned int)3806779051ULL),((unsigned int)144853798ULL),((unsigned int)4167350852ULL),((unsigned int)2478881062ULL)};
unsigned int a_1[4]={((unsigned int)3137683677ULL),((unsigned int)1790747352ULL),((unsigned int)2643231081ULL),((unsigned int)52035434ULL)};
unsigned int b_1[4]={((unsigned int)3137683677ULL),((unsigned int)1790747352ULL),((unsigned int)2643231081ULL),((unsigned int)52035434ULL)};
unsigned int a_2[4]={((unsigned int)2138711887ULL),((unsigned int)970160781ULL),((unsigned int)3204394935ULL),((unsigned int)3638813084ULL)};
unsigned int b_2[4]={((unsigned int)2138711887ULL),((unsigned int)970160781ULL),((unsigned int)3204394935ULL),((unsigned int)3638813084ULL)};
unsigned int a_3[4]={((unsigned int)3799497996ULL),((unsigned int)54570470ULL),((unsigned int)2671441960ULL),((unsigned int)3526835783ULL)};
unsigned int b_3[4]={((unsigned int)3799497996ULL),((unsigned int)54570470ULL),((unsigned int)2671441960ULL),((unsigned int)3526835783ULL)};
unsigned int a_4[4]={((unsigned int)1466375385ULL),((unsigned int)3188332239ULL),((unsigned int)2809723979ULL),((unsigned int)2853787797ULL)};
unsigned int b_4[4]={((unsigned int)1466375385ULL),((unsigned int)3188332239ULL),((unsigned int)2809723979ULL),((unsigned int)2853787797ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 47\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3904642397ULL),((unsigned int)2395760630ULL),((unsigned int)3343945864ULL),((unsigned int)3240675053ULL),((unsigned int)1025401147ULL),((unsigned int)1510287633ULL),((unsigned int)3589383477ULL),((unsigned int)161964710ULL),((unsigned int)3867047678ULL),((unsigned int)443842897ULL),((unsigned int)3592889212ULL),((unsigned int)2592734720ULL),((unsigned int)2892130886ULL),((unsigned int)1567671221ULL),((unsigned int)1100543427ULL),((unsigned int)1652068945ULL)};
unsigned int b_0[16]={((unsigned int)3904642397ULL),((unsigned int)2395760630ULL),((unsigned int)3343945864ULL),((unsigned int)3240675053ULL),((unsigned int)1025401147ULL),((unsigned int)1510287633ULL),((unsigned int)3589383477ULL),((unsigned int)161964710ULL),((unsigned int)3867047678ULL),((unsigned int)443842897ULL),((unsigned int)3592889212ULL),((unsigned int)2592734720ULL),((unsigned int)2892130886ULL),((unsigned int)1567671221ULL),((unsigned int)1100543427ULL),((unsigned int)1652068945ULL)};
unsigned int a_1[4]={((unsigned int)707484740ULL),((unsigned int)3387715375ULL),((unsigned int)4261913980ULL),((unsigned int)4143383253ULL)};
unsigned int b_1[4]={((unsigned int)707484740ULL),((unsigned int)3387715375ULL),((unsigned int)4261913980ULL),((unsigned int)4143383253ULL)};
unsigned int a_2[4]={((unsigned int)1956294484ULL),((unsigned int)891278751ULL),((unsigned int)3393343501ULL),((unsigned int)3631103234ULL)};
unsigned int b_2[4]={((unsigned int)1956294484ULL),((unsigned int)891278751ULL),((unsigned int)3393343501ULL),((unsigned int)3631103234ULL)};
unsigned int a_3[4]={((unsigned int)3544817562ULL),((unsigned int)2838266494ULL),((unsigned int)783546581ULL),((unsigned int)1693411344ULL)};
unsigned int b_3[4]={((unsigned int)3544817562ULL),((unsigned int)2838266494ULL),((unsigned int)783546581ULL),((unsigned int)1693411344ULL)};
unsigned int a_4[4]={((unsigned int)557402186ULL),((unsigned int)2485117676ULL),((unsigned int)1813852251ULL),((unsigned int)751718286ULL)};
unsigned int b_4[4]={((unsigned int)557402186ULL),((unsigned int)2485117676ULL),((unsigned int)1813852251ULL),((unsigned int)751718286ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 48\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2071342207ULL),((unsigned int)4092499544ULL),((unsigned int)782582374ULL),((unsigned int)2563926418ULL),((unsigned int)2722798263ULL),((unsigned int)3275656222ULL),((unsigned int)2554369601ULL),((unsigned int)1200727787ULL),((unsigned int)3486970391ULL),((unsigned int)3867182986ULL),((unsigned int)1742348819ULL),((unsigned int)2720672836ULL),((unsigned int)1853299542ULL),((unsigned int)632271778ULL),((unsigned int)3454740144ULL),((unsigned int)3759631425ULL)};
unsigned int b_0[16]={((unsigned int)2071342207ULL),((unsigned int)4092499544ULL),((unsigned int)782582374ULL),((unsigned int)2563926418ULL),((unsigned int)2722798263ULL),((unsigned int)3275656222ULL),((unsigned int)2554369601ULL),((unsigned int)1200727787ULL),((unsigned int)3486970391ULL),((unsigned int)3867182986ULL),((unsigned int)1742348819ULL),((unsigned int)2720672836ULL),((unsigned int)1853299542ULL),((unsigned int)632271778ULL),((unsigned int)3454740144ULL),((unsigned int)3759631425ULL)};
unsigned int a_1[4]={((unsigned int)3490839142ULL),((unsigned int)4071562328ULL),((unsigned int)1605674668ULL),((unsigned int)3563319457ULL)};
unsigned int b_1[4]={((unsigned int)3490839142ULL),((unsigned int)4071562328ULL),((unsigned int)1605674668ULL),((unsigned int)3563319457ULL)};
unsigned int a_2[4]={((unsigned int)3405007157ULL),((unsigned int)897348687ULL),((unsigned int)1269955090ULL),((unsigned int)3814843243ULL)};
unsigned int b_2[4]={((unsigned int)3405007157ULL),((unsigned int)897348687ULL),((unsigned int)1269955090ULL),((unsigned int)3814843243ULL)};
unsigned int a_3[4]={((unsigned int)1471855349ULL),((unsigned int)273172346ULL),((unsigned int)4286235857ULL),((unsigned int)1429206332ULL)};
unsigned int b_3[4]={((unsigned int)1471855349ULL),((unsigned int)273172346ULL),((unsigned int)4286235857ULL),((unsigned int)1429206332ULL)};
unsigned int a_4[4]={((unsigned int)2964623027ULL),((unsigned int)799902576ULL),((unsigned int)1138201196ULL),((unsigned int)227036567ULL)};
unsigned int b_4[4]={((unsigned int)2964623027ULL),((unsigned int)799902576ULL),((unsigned int)1138201196ULL),((unsigned int)227036567ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 49\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)391082848ULL),((unsigned int)2009229008ULL),((unsigned int)2066671922ULL),((unsigned int)2128109286ULL),((unsigned int)1331448651ULL),((unsigned int)4067803326ULL),((unsigned int)589290923ULL),((unsigned int)2593851679ULL),((unsigned int)1269980167ULL),((unsigned int)4028155307ULL),((unsigned int)2556741456ULL),((unsigned int)231785011ULL),((unsigned int)4248621435ULL),((unsigned int)3745241606ULL),((unsigned int)3493442963ULL),((unsigned int)178482342ULL)};
unsigned int b_0[16]={((unsigned int)391082848ULL),((unsigned int)2009229008ULL),((unsigned int)2066671922ULL),((unsigned int)2128109286ULL),((unsigned int)1331448651ULL),((unsigned int)4067803326ULL),((unsigned int)589290923ULL),((unsigned int)2593851679ULL),((unsigned int)1269980167ULL),((unsigned int)4028155307ULL),((unsigned int)2556741456ULL),((unsigned int)231785011ULL),((unsigned int)4248621435ULL),((unsigned int)3745241606ULL),((unsigned int)3493442963ULL),((unsigned int)178482342ULL)};
unsigned int a_1[4]={((unsigned int)177641870ULL),((unsigned int)268910916ULL),((unsigned int)1817001881ULL),((unsigned int)561783855ULL)};
unsigned int b_1[4]={((unsigned int)177641870ULL),((unsigned int)268910916ULL),((unsigned int)1817001881ULL),((unsigned int)561783855ULL)};
unsigned int a_2[4]={((unsigned int)1175019818ULL),((unsigned int)2999890141ULL),((unsigned int)1631136493ULL),((unsigned int)3676518142ULL)};
unsigned int b_2[4]={((unsigned int)1175019818ULL),((unsigned int)2999890141ULL),((unsigned int)1631136493ULL),((unsigned int)3676518142ULL)};
unsigned int a_3[4]={((unsigned int)2422377130ULL),((unsigned int)3191213415ULL),((unsigned int)2925816935ULL),((unsigned int)4115941915ULL)};
unsigned int b_3[4]={((unsigned int)2422377130ULL),((unsigned int)3191213415ULL),((unsigned int)2925816935ULL),((unsigned int)4115941915ULL)};
unsigned int a_4[4]={((unsigned int)1863315621ULL),((unsigned int)3917464984ULL),((unsigned int)2029326063ULL),((unsigned int)1367757835ULL)};
unsigned int b_4[4]={((unsigned int)1863315621ULL),((unsigned int)3917464984ULL),((unsigned int)2029326063ULL),((unsigned int)1367757835ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 50\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3415054236ULL),((unsigned int)4150589575ULL),((unsigned int)3859021744ULL),((unsigned int)2794241913ULL),((unsigned int)2230997604ULL),((unsigned int)3152110249ULL),((unsigned int)2400613167ULL),((unsigned int)3042213127ULL),((unsigned int)1784686370ULL),((unsigned int)3901851102ULL),((unsigned int)830815814ULL),((unsigned int)3881515787ULL),((unsigned int)1358030082ULL),((unsigned int)3075135691ULL),((unsigned int)1056830901ULL),((unsigned int)3332380332ULL)};
unsigned int b_0[16]={((unsigned int)3415054236ULL),((unsigned int)4150589575ULL),((unsigned int)3859021744ULL),((unsigned int)2794241913ULL),((unsigned int)2230997604ULL),((unsigned int)3152110249ULL),((unsigned int)2400613167ULL),((unsigned int)3042213127ULL),((unsigned int)1784686370ULL),((unsigned int)3901851102ULL),((unsigned int)830815814ULL),((unsigned int)3881515787ULL),((unsigned int)1358030082ULL),((unsigned int)3075135691ULL),((unsigned int)1056830901ULL),((unsigned int)3332380332ULL)};
unsigned int a_1[4]={((unsigned int)1613910380ULL),((unsigned int)2210117809ULL),((unsigned int)1759239399ULL),((unsigned int)2060514874ULL)};
unsigned int b_1[4]={((unsigned int)1613910380ULL),((unsigned int)2210117809ULL),((unsigned int)1759239399ULL),((unsigned int)2060514874ULL)};
unsigned int a_2[4]={((unsigned int)3360642022ULL),((unsigned int)2031159749ULL),((unsigned int)4235925294ULL),((unsigned int)515285282ULL)};
unsigned int b_2[4]={((unsigned int)3360642022ULL),((unsigned int)2031159749ULL),((unsigned int)4235925294ULL),((unsigned int)515285282ULL)};
unsigned int a_3[4]={((unsigned int)309693176ULL),((unsigned int)1857199650ULL),((unsigned int)3370420938ULL),((unsigned int)1385636482ULL)};
unsigned int b_3[4]={((unsigned int)309693176ULL),((unsigned int)1857199650ULL),((unsigned int)3370420938ULL),((unsigned int)1385636482ULL)};
unsigned int a_4[4]={((unsigned int)1404269327ULL),((unsigned int)2997025953ULL),((unsigned int)767768418ULL),((unsigned int)2444129219ULL)};
unsigned int b_4[4]={((unsigned int)1404269327ULL),((unsigned int)2997025953ULL),((unsigned int)767768418ULL),((unsigned int)2444129219ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 51\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1296218009ULL),((unsigned int)701795735ULL),((unsigned int)2493922740ULL),((unsigned int)2465797365ULL),((unsigned int)3358744547ULL),((unsigned int)2084435842ULL),((unsigned int)2984746573ULL),((unsigned int)136642243ULL),((unsigned int)3421399081ULL),((unsigned int)606623943ULL),((unsigned int)3482411742ULL),((unsigned int)3658905872ULL),((unsigned int)1941046188ULL),((unsigned int)3869070750ULL),((unsigned int)3056304434ULL),((unsigned int)755376614ULL)};
unsigned int b_0[16]={((unsigned int)1296218009ULL),((unsigned int)701795735ULL),((unsigned int)2493922740ULL),((unsigned int)2465797365ULL),((unsigned int)3358744547ULL),((unsigned int)2084435842ULL),((unsigned int)2984746573ULL),((unsigned int)136642243ULL),((unsigned int)3421399081ULL),((unsigned int)606623943ULL),((unsigned int)3482411742ULL),((unsigned int)3658905872ULL),((unsigned int)1941046188ULL),((unsigned int)3869070750ULL),((unsigned int)3056304434ULL),((unsigned int)755376614ULL)};
unsigned int a_1[4]={((unsigned int)2805645513ULL),((unsigned int)1898461203ULL),((unsigned int)2078569138ULL),((unsigned int)1582141588ULL)};
unsigned int b_1[4]={((unsigned int)2805645513ULL),((unsigned int)1898461203ULL),((unsigned int)2078569138ULL),((unsigned int)1582141588ULL)};
unsigned int a_2[4]={((unsigned int)1253230830ULL),((unsigned int)2735558351ULL),((unsigned int)1801807674ULL),((unsigned int)2936386195ULL)};
unsigned int b_2[4]={((unsigned int)1253230830ULL),((unsigned int)2735558351ULL),((unsigned int)1801807674ULL),((unsigned int)2936386195ULL)};
unsigned int a_3[4]={((unsigned int)573113490ULL),((unsigned int)2847214184ULL),((unsigned int)3366636633ULL),((unsigned int)4094026986ULL)};
unsigned int b_3[4]={((unsigned int)573113490ULL),((unsigned int)2847214184ULL),((unsigned int)3366636633ULL),((unsigned int)4094026986ULL)};
unsigned int a_4[4]={((unsigned int)3076103505ULL),((unsigned int)4276357448ULL),((unsigned int)2536123840ULL),((unsigned int)3233779064ULL)};
unsigned int b_4[4]={((unsigned int)3076103505ULL),((unsigned int)4276357448ULL),((unsigned int)2536123840ULL),((unsigned int)3233779064ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 52\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2849295304ULL),((unsigned int)1719644718ULL),((unsigned int)1791895824ULL),((unsigned int)3493387073ULL),((unsigned int)886398030ULL),((unsigned int)2360511385ULL),((unsigned int)1497052084ULL),((unsigned int)2034775180ULL),((unsigned int)658621016ULL),((unsigned int)4031910810ULL),((unsigned int)3582659436ULL),((unsigned int)916070236ULL),((unsigned int)2406956728ULL),((unsigned int)496270766ULL),((unsigned int)185753029ULL),((unsigned int)954278204ULL)};
unsigned int b_0[16]={((unsigned int)2849295304ULL),((unsigned int)1719644718ULL),((unsigned int)1791895824ULL),((unsigned int)3493387073ULL),((unsigned int)886398030ULL),((unsigned int)2360511385ULL),((unsigned int)1497052084ULL),((unsigned int)2034775180ULL),((unsigned int)658621016ULL),((unsigned int)4031910810ULL),((unsigned int)3582659436ULL),((unsigned int)916070236ULL),((unsigned int)2406956728ULL),((unsigned int)496270766ULL),((unsigned int)185753029ULL),((unsigned int)954278204ULL)};
unsigned int a_1[4]={((unsigned int)2972245505ULL),((unsigned int)972827178ULL),((unsigned int)1392568789ULL),((unsigned int)3881300004ULL)};
unsigned int b_1[4]={((unsigned int)2972245505ULL),((unsigned int)972827178ULL),((unsigned int)1392568789ULL),((unsigned int)3881300004ULL)};
unsigned int a_2[4]={((unsigned int)1872173076ULL),((unsigned int)2553753415ULL),((unsigned int)3501063809ULL),((unsigned int)1651189632ULL)};
unsigned int b_2[4]={((unsigned int)1872173076ULL),((unsigned int)2553753415ULL),((unsigned int)3501063809ULL),((unsigned int)1651189632ULL)};
unsigned int a_3[4]={((unsigned int)3898882626ULL),((unsigned int)2875302843ULL),((unsigned int)1020721602ULL),((unsigned int)762743374ULL)};
unsigned int b_3[4]={((unsigned int)3898882626ULL),((unsigned int)2875302843ULL),((unsigned int)1020721602ULL),((unsigned int)762743374ULL)};
unsigned int a_4[4]={((unsigned int)2392486184ULL),((unsigned int)4004926945ULL),((unsigned int)1780033241ULL),((unsigned int)3916920913ULL)};
unsigned int b_4[4]={((unsigned int)2392486184ULL),((unsigned int)4004926945ULL),((unsigned int)1780033241ULL),((unsigned int)3916920913ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 53\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1791369301ULL),((unsigned int)3317026519ULL),((unsigned int)523962735ULL),((unsigned int)2326511688ULL),((unsigned int)1844626457ULL),((unsigned int)1982656891ULL),((unsigned int)1705479146ULL),((unsigned int)869146361ULL),((unsigned int)3481254372ULL),((unsigned int)1840138991ULL),((unsigned int)1621533981ULL),((unsigned int)89546684ULL),((unsigned int)4071041440ULL),((unsigned int)516510152ULL),((unsigned int)4058837638ULL),((unsigned int)3116877854ULL)};
unsigned int b_0[16]={((unsigned int)1791369301ULL),((unsigned int)3317026519ULL),((unsigned int)523962735ULL),((unsigned int)2326511688ULL),((unsigned int)1844626457ULL),((unsigned int)1982656891ULL),((unsigned int)1705479146ULL),((unsigned int)869146361ULL),((unsigned int)3481254372ULL),((unsigned int)1840138991ULL),((unsigned int)1621533981ULL),((unsigned int)89546684ULL),((unsigned int)4071041440ULL),((unsigned int)516510152ULL),((unsigned int)4058837638ULL),((unsigned int)3116877854ULL)};
unsigned int a_1[4]={((unsigned int)312479239ULL),((unsigned int)2488724991ULL),((unsigned int)3934147117ULL),((unsigned int)2701799466ULL)};
unsigned int b_1[4]={((unsigned int)312479239ULL),((unsigned int)2488724991ULL),((unsigned int)3934147117ULL),((unsigned int)2701799466ULL)};
unsigned int a_2[4]={((unsigned int)651122287ULL),((unsigned int)1544728026ULL),((unsigned int)10616103ULL),((unsigned int)2777033682ULL)};
unsigned int b_2[4]={((unsigned int)651122287ULL),((unsigned int)1544728026ULL),((unsigned int)10616103ULL),((unsigned int)2777033682ULL)};
unsigned int a_3[4]={((unsigned int)366446814ULL),((unsigned int)2685867502ULL),((unsigned int)1233333436ULL),((unsigned int)2465355284ULL)};
unsigned int b_3[4]={((unsigned int)366446814ULL),((unsigned int)2685867502ULL),((unsigned int)1233333436ULL),((unsigned int)2465355284ULL)};
unsigned int a_4[4]={((unsigned int)3649556135ULL),((unsigned int)4243566274ULL),((unsigned int)2871663051ULL),((unsigned int)3391594396ULL)};
unsigned int b_4[4]={((unsigned int)3649556135ULL),((unsigned int)4243566274ULL),((unsigned int)2871663051ULL),((unsigned int)3391594396ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 54\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3018727493ULL),((unsigned int)1440112210ULL),((unsigned int)585351191ULL),((unsigned int)3620177548ULL),((unsigned int)506751139ULL),((unsigned int)1288269811ULL),((unsigned int)281340809ULL),((unsigned int)3781499353ULL),((unsigned int)3344941957ULL),((unsigned int)1572509752ULL),((unsigned int)539071022ULL),((unsigned int)1210569697ULL),((unsigned int)2943029706ULL),((unsigned int)1108549070ULL),((unsigned int)721263455ULL),((unsigned int)4017952838ULL)};
unsigned int b_0[16]={((unsigned int)3018727493ULL),((unsigned int)1440112210ULL),((unsigned int)585351191ULL),((unsigned int)3620177548ULL),((unsigned int)506751139ULL),((unsigned int)1288269811ULL),((unsigned int)281340809ULL),((unsigned int)3781499353ULL),((unsigned int)3344941957ULL),((unsigned int)1572509752ULL),((unsigned int)539071022ULL),((unsigned int)1210569697ULL),((unsigned int)2943029706ULL),((unsigned int)1108549070ULL),((unsigned int)721263455ULL),((unsigned int)4017952838ULL)};
unsigned int a_1[4]={((unsigned int)139851558ULL),((unsigned int)3485858218ULL),((unsigned int)2216165651ULL),((unsigned int)988815942ULL)};
unsigned int b_1[4]={((unsigned int)139851558ULL),((unsigned int)3485858218ULL),((unsigned int)2216165651ULL),((unsigned int)988815942ULL)};
unsigned int a_2[4]={((unsigned int)942639900ULL),((unsigned int)2719882297ULL),((unsigned int)3948013047ULL),((unsigned int)3078738920ULL)};
unsigned int b_2[4]={((unsigned int)942639900ULL),((unsigned int)2719882297ULL),((unsigned int)3948013047ULL),((unsigned int)3078738920ULL)};
unsigned int a_3[4]={((unsigned int)3118391414ULL),((unsigned int)3540859618ULL),((unsigned int)2524533598ULL),((unsigned int)3884959850ULL)};
unsigned int b_3[4]={((unsigned int)3118391414ULL),((unsigned int)3540859618ULL),((unsigned int)2524533598ULL),((unsigned int)3884959850ULL)};
unsigned int a_4[4]={((unsigned int)833969987ULL),((unsigned int)3524697166ULL),((unsigned int)1902527375ULL),((unsigned int)381696463ULL)};
unsigned int b_4[4]={((unsigned int)833969987ULL),((unsigned int)3524697166ULL),((unsigned int)1902527375ULL),((unsigned int)381696463ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 55\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3935517047ULL),((unsigned int)2066653395ULL),((unsigned int)1142247167ULL),((unsigned int)3276023726ULL),((unsigned int)3320489564ULL),((unsigned int)446075427ULL),((unsigned int)2581574173ULL),((unsigned int)2017220688ULL),((unsigned int)1832731374ULL),((unsigned int)2000266070ULL),((unsigned int)3379342728ULL),((unsigned int)4058694895ULL),((unsigned int)582344027ULL),((unsigned int)3897066493ULL),((unsigned int)3167388112ULL),((unsigned int)232864196ULL)};
unsigned int b_0[16]={((unsigned int)3935517047ULL),((unsigned int)2066653395ULL),((unsigned int)1142247167ULL),((unsigned int)3276023726ULL),((unsigned int)3320489564ULL),((unsigned int)446075427ULL),((unsigned int)2581574173ULL),((unsigned int)2017220688ULL),((unsigned int)1832731374ULL),((unsigned int)2000266070ULL),((unsigned int)3379342728ULL),((unsigned int)4058694895ULL),((unsigned int)582344027ULL),((unsigned int)3897066493ULL),((unsigned int)3167388112ULL),((unsigned int)232864196ULL)};
unsigned int a_1[4]={((unsigned int)3893545346ULL),((unsigned int)4218984677ULL),((unsigned int)1340469429ULL),((unsigned int)3930627623ULL)};
unsigned int b_1[4]={((unsigned int)3893545346ULL),((unsigned int)4218984677ULL),((unsigned int)1340469429ULL),((unsigned int)3930627623ULL)};
unsigned int a_2[4]={((unsigned int)2480666166ULL),((unsigned int)3987924381ULL),((unsigned int)4043094618ULL),((unsigned int)531610158ULL)};
unsigned int b_2[4]={((unsigned int)2480666166ULL),((unsigned int)3987924381ULL),((unsigned int)4043094618ULL),((unsigned int)531610158ULL)};
unsigned int a_3[4]={((unsigned int)981299726ULL),((unsigned int)2203583190ULL),((unsigned int)1442380638ULL),((unsigned int)2923023279ULL)};
unsigned int b_3[4]={((unsigned int)981299726ULL),((unsigned int)2203583190ULL),((unsigned int)1442380638ULL),((unsigned int)2923023279ULL)};
unsigned int a_4[4]={((unsigned int)2781720374ULL),((unsigned int)876192452ULL),((unsigned int)2438581462ULL),((unsigned int)2525349786ULL)};
unsigned int b_4[4]={((unsigned int)2781720374ULL),((unsigned int)876192452ULL),((unsigned int)2438581462ULL),((unsigned int)2525349786ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 56\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)885739361ULL),((unsigned int)231194942ULL),((unsigned int)2029298516ULL),((unsigned int)4064278956ULL),((unsigned int)1639813292ULL),((unsigned int)762252602ULL),((unsigned int)3269994539ULL),((unsigned int)3117118123ULL),((unsigned int)246473428ULL),((unsigned int)1145320727ULL),((unsigned int)1189029593ULL),((unsigned int)3843104925ULL),((unsigned int)1247960279ULL),((unsigned int)1420485378ULL),((unsigned int)2301276098ULL),((unsigned int)3901343136ULL)};
unsigned int b_0[16]={((unsigned int)885739361ULL),((unsigned int)231194942ULL),((unsigned int)2029298516ULL),((unsigned int)4064278956ULL),((unsigned int)1639813292ULL),((unsigned int)762252602ULL),((unsigned int)3269994539ULL),((unsigned int)3117118123ULL),((unsigned int)246473428ULL),((unsigned int)1145320727ULL),((unsigned int)1189029593ULL),((unsigned int)3843104925ULL),((unsigned int)1247960279ULL),((unsigned int)1420485378ULL),((unsigned int)2301276098ULL),((unsigned int)3901343136ULL)};
unsigned int a_1[4]={((unsigned int)46878570ULL),((unsigned int)251432839ULL),((unsigned int)3829613179ULL),((unsigned int)1857898567ULL)};
unsigned int b_1[4]={((unsigned int)46878570ULL),((unsigned int)251432839ULL),((unsigned int)3829613179ULL),((unsigned int)1857898567ULL)};
unsigned int a_2[4]={((unsigned int)2932836001ULL),((unsigned int)1185805704ULL),((unsigned int)597609889ULL),((unsigned int)2846820922ULL)};
unsigned int b_2[4]={((unsigned int)2932836001ULL),((unsigned int)1185805704ULL),((unsigned int)597609889ULL),((unsigned int)2846820922ULL)};
unsigned int a_3[4]={((unsigned int)2182866179ULL),((unsigned int)2093162719ULL),((unsigned int)1139473134ULL),((unsigned int)3574636864ULL)};
unsigned int b_3[4]={((unsigned int)2182866179ULL),((unsigned int)2093162719ULL),((unsigned int)1139473134ULL),((unsigned int)3574636864ULL)};
unsigned int a_4[4]={((unsigned int)3931790880ULL),((unsigned int)237548057ULL),((unsigned int)3382738432ULL),((unsigned int)404764630ULL)};
unsigned int b_4[4]={((unsigned int)3931790880ULL),((unsigned int)237548057ULL),((unsigned int)3382738432ULL),((unsigned int)404764630ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 57\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1175076928ULL),((unsigned int)929417830ULL),((unsigned int)1113127870ULL),((unsigned int)1982288045ULL),((unsigned int)617156204ULL),((unsigned int)1954240431ULL),((unsigned int)4093728579ULL),((unsigned int)33534391ULL),((unsigned int)597374718ULL),((unsigned int)1525054175ULL),((unsigned int)2549091403ULL),((unsigned int)2721717717ULL),((unsigned int)3306113280ULL),((unsigned int)622784794ULL),((unsigned int)1156420499ULL),((unsigned int)2901094616ULL)};
unsigned int b_0[16]={((unsigned int)1175076928ULL),((unsigned int)929417830ULL),((unsigned int)1113127870ULL),((unsigned int)1982288045ULL),((unsigned int)617156204ULL),((unsigned int)1954240431ULL),((unsigned int)4093728579ULL),((unsigned int)33534391ULL),((unsigned int)597374718ULL),((unsigned int)1525054175ULL),((unsigned int)2549091403ULL),((unsigned int)2721717717ULL),((unsigned int)3306113280ULL),((unsigned int)622784794ULL),((unsigned int)1156420499ULL),((unsigned int)2901094616ULL)};
unsigned int a_1[4]={((unsigned int)1390537768ULL),((unsigned int)1541154919ULL),((unsigned int)2235729332ULL),((unsigned int)3178604475ULL)};
unsigned int b_1[4]={((unsigned int)1390537768ULL),((unsigned int)1541154919ULL),((unsigned int)2235729332ULL),((unsigned int)3178604475ULL)};
unsigned int a_2[4]={((unsigned int)2668150386ULL),((unsigned int)4125313545ULL),((unsigned int)3009486975ULL),((unsigned int)675957749ULL)};
unsigned int b_2[4]={((unsigned int)2668150386ULL),((unsigned int)4125313545ULL),((unsigned int)3009486975ULL),((unsigned int)675957749ULL)};
unsigned int a_3[4]={((unsigned int)3958403505ULL),((unsigned int)1343207414ULL),((unsigned int)3897256680ULL),((unsigned int)2207313875ULL)};
unsigned int b_3[4]={((unsigned int)3958403505ULL),((unsigned int)1343207414ULL),((unsigned int)3897256680ULL),((unsigned int)2207313875ULL)};
unsigned int a_4[4]={((unsigned int)400937723ULL),((unsigned int)3729078877ULL),((unsigned int)3470964570ULL),((unsigned int)3052987181ULL)};
unsigned int b_4[4]={((unsigned int)400937723ULL),((unsigned int)3729078877ULL),((unsigned int)3470964570ULL),((unsigned int)3052987181ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 58\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3660571098ULL),((unsigned int)2519335049ULL),((unsigned int)2467221987ULL),((unsigned int)2175079037ULL),((unsigned int)4265721973ULL),((unsigned int)30171ULL),((unsigned int)2768498810ULL),((unsigned int)3883298713ULL),((unsigned int)2887113622ULL),((unsigned int)4281696343ULL),((unsigned int)2744972068ULL),((unsigned int)1972073300ULL),((unsigned int)3383700285ULL),((unsigned int)3826634238ULL),((unsigned int)3421112831ULL),((unsigned int)405028058ULL)};
unsigned int b_0[16]={((unsigned int)3660571098ULL),((unsigned int)2519335049ULL),((unsigned int)2467221987ULL),((unsigned int)2175079037ULL),((unsigned int)4265721973ULL),((unsigned int)30171ULL),((unsigned int)2768498810ULL),((unsigned int)3883298713ULL),((unsigned int)2887113622ULL),((unsigned int)4281696343ULL),((unsigned int)2744972068ULL),((unsigned int)1972073300ULL),((unsigned int)3383700285ULL),((unsigned int)3826634238ULL),((unsigned int)3421112831ULL),((unsigned int)405028058ULL)};
unsigned int a_1[4]={((unsigned int)228476662ULL),((unsigned int)921239016ULL),((unsigned int)2818818046ULL),((unsigned int)2060544048ULL)};
unsigned int b_1[4]={((unsigned int)228476662ULL),((unsigned int)921239016ULL),((unsigned int)2818818046ULL),((unsigned int)2060544048ULL)};
unsigned int a_2[4]={((unsigned int)48223258ULL),((unsigned int)3021700477ULL),((unsigned int)346508104ULL),((unsigned int)1078359032ULL)};
unsigned int b_2[4]={((unsigned int)48223258ULL),((unsigned int)3021700477ULL),((unsigned int)346508104ULL),((unsigned int)1078359032ULL)};
unsigned int a_3[4]={((unsigned int)610486766ULL),((unsigned int)118243993ULL),((unsigned int)502168113ULL),((unsigned int)85105336ULL)};
unsigned int b_3[4]={((unsigned int)610486766ULL),((unsigned int)118243993ULL),((unsigned int)502168113ULL),((unsigned int)85105336ULL)};
unsigned int a_4[4]={((unsigned int)3048591594ULL),((unsigned int)3544225888ULL),((unsigned int)162209202ULL),((unsigned int)20922121ULL)};
unsigned int b_4[4]={((unsigned int)3048591594ULL),((unsigned int)3544225888ULL),((unsigned int)162209202ULL),((unsigned int)20922121ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 59\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3489750485ULL),((unsigned int)382231740ULL),((unsigned int)3875942354ULL),((unsigned int)3052313734ULL),((unsigned int)1193354739ULL),((unsigned int)3801017757ULL),((unsigned int)73640910ULL),((unsigned int)729911113ULL),((unsigned int)2685716978ULL),((unsigned int)3463837788ULL),((unsigned int)3241468096ULL),((unsigned int)2868684580ULL),((unsigned int)2049680992ULL),((unsigned int)2374656441ULL),((unsigned int)3891114546ULL),((unsigned int)1398362936ULL)};
unsigned int b_0[16]={((unsigned int)3489750485ULL),((unsigned int)382231740ULL),((unsigned int)3875942354ULL),((unsigned int)3052313734ULL),((unsigned int)1193354739ULL),((unsigned int)3801017757ULL),((unsigned int)73640910ULL),((unsigned int)729911113ULL),((unsigned int)2685716978ULL),((unsigned int)3463837788ULL),((unsigned int)3241468096ULL),((unsigned int)2868684580ULL),((unsigned int)2049680992ULL),((unsigned int)2374656441ULL),((unsigned int)3891114546ULL),((unsigned int)1398362936ULL)};
unsigned int a_1[4]={((unsigned int)1357442545ULL),((unsigned int)3495750883ULL),((unsigned int)2570135578ULL),((unsigned int)3516364509ULL)};
unsigned int b_1[4]={((unsigned int)1357442545ULL),((unsigned int)3495750883ULL),((unsigned int)2570135578ULL),((unsigned int)3516364509ULL)};
unsigned int a_2[4]={((unsigned int)4210219351ULL),((unsigned int)3368102520ULL),((unsigned int)1893299800ULL),((unsigned int)571857901ULL)};
unsigned int b_2[4]={((unsigned int)4210219351ULL),((unsigned int)3368102520ULL),((unsigned int)1893299800ULL),((unsigned int)571857901ULL)};
unsigned int a_3[4]={((unsigned int)2495545347ULL),((unsigned int)2706479070ULL),((unsigned int)930469542ULL),((unsigned int)2304542093ULL)};
unsigned int b_3[4]={((unsigned int)2495545347ULL),((unsigned int)2706479070ULL),((unsigned int)930469542ULL),((unsigned int)2304542093ULL)};
unsigned int a_4[4]={((unsigned int)800135069ULL),((unsigned int)2221902641ULL),((unsigned int)2081952467ULL),((unsigned int)1896940136ULL)};
unsigned int b_4[4]={((unsigned int)800135069ULL),((unsigned int)2221902641ULL),((unsigned int)2081952467ULL),((unsigned int)1896940136ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 60\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4231983867ULL),((unsigned int)4282356035ULL),((unsigned int)2204996662ULL),((unsigned int)2808878366ULL),((unsigned int)1405849245ULL),((unsigned int)4262123856ULL),((unsigned int)3550276165ULL),((unsigned int)513830076ULL),((unsigned int)885879067ULL),((unsigned int)3851631231ULL),((unsigned int)3435885706ULL),((unsigned int)3105777391ULL),((unsigned int)1356267591ULL),((unsigned int)124546211ULL),((unsigned int)2563550518ULL),((unsigned int)2192509644ULL)};
unsigned int b_0[16]={((unsigned int)4231983867ULL),((unsigned int)4282356035ULL),((unsigned int)2204996662ULL),((unsigned int)2808878366ULL),((unsigned int)1405849245ULL),((unsigned int)4262123856ULL),((unsigned int)3550276165ULL),((unsigned int)513830076ULL),((unsigned int)885879067ULL),((unsigned int)3851631231ULL),((unsigned int)3435885706ULL),((unsigned int)3105777391ULL),((unsigned int)1356267591ULL),((unsigned int)124546211ULL),((unsigned int)2563550518ULL),((unsigned int)2192509644ULL)};
unsigned int a_1[4]={((unsigned int)3317037389ULL),((unsigned int)3374203509ULL),((unsigned int)1817470378ULL),((unsigned int)704766462ULL)};
unsigned int b_1[4]={((unsigned int)3317037389ULL),((unsigned int)3374203509ULL),((unsigned int)1817470378ULL),((unsigned int)704766462ULL)};
unsigned int a_2[4]={((unsigned int)815407891ULL),((unsigned int)533410658ULL),((unsigned int)494900049ULL),((unsigned int)3189125231ULL)};
unsigned int b_2[4]={((unsigned int)815407891ULL),((unsigned int)533410658ULL),((unsigned int)494900049ULL),((unsigned int)3189125231ULL)};
unsigned int a_3[4]={((unsigned int)2711420489ULL),((unsigned int)2155511928ULL),((unsigned int)1388830873ULL),((unsigned int)833449300ULL)};
unsigned int b_3[4]={((unsigned int)2711420489ULL),((unsigned int)2155511928ULL),((unsigned int)1388830873ULL),((unsigned int)833449300ULL)};
unsigned int a_4[4]={((unsigned int)256371190ULL),((unsigned int)3507317804ULL),((unsigned int)277070016ULL),((unsigned int)2310255272ULL)};
unsigned int b_4[4]={((unsigned int)256371190ULL),((unsigned int)3507317804ULL),((unsigned int)277070016ULL),((unsigned int)2310255272ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 61\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3868268157ULL),((unsigned int)290954273ULL),((unsigned int)1239689826ULL),((unsigned int)3329804496ULL),((unsigned int)1599097881ULL),((unsigned int)3588678344ULL),((unsigned int)3351135063ULL),((unsigned int)3858728468ULL),((unsigned int)4033271728ULL),((unsigned int)3339527482ULL),((unsigned int)3335930429ULL),((unsigned int)2930398490ULL),((unsigned int)2037757184ULL),((unsigned int)1259958964ULL),((unsigned int)983479900ULL),((unsigned int)3027977881ULL)};
unsigned int b_0[16]={((unsigned int)3868268157ULL),((unsigned int)290954273ULL),((unsigned int)1239689826ULL),((unsigned int)3329804496ULL),((unsigned int)1599097881ULL),((unsigned int)3588678344ULL),((unsigned int)3351135063ULL),((unsigned int)3858728468ULL),((unsigned int)4033271728ULL),((unsigned int)3339527482ULL),((unsigned int)3335930429ULL),((unsigned int)2930398490ULL),((unsigned int)2037757184ULL),((unsigned int)1259958964ULL),((unsigned int)983479900ULL),((unsigned int)3027977881ULL)};
unsigned int a_1[4]={((unsigned int)4092437424ULL),((unsigned int)4199791077ULL),((unsigned int)3056317304ULL),((unsigned int)3491111712ULL)};
unsigned int b_1[4]={((unsigned int)4092437424ULL),((unsigned int)4199791077ULL),((unsigned int)3056317304ULL),((unsigned int)3491111712ULL)};
unsigned int a_2[4]={((unsigned int)2287970304ULL),((unsigned int)2774147307ULL),((unsigned int)3126766612ULL),((unsigned int)3142291148ULL)};
unsigned int b_2[4]={((unsigned int)2287970304ULL),((unsigned int)2774147307ULL),((unsigned int)3126766612ULL),((unsigned int)3142291148ULL)};
unsigned int a_3[4]={((unsigned int)3867827818ULL),((unsigned int)1359382704ULL),((unsigned int)3924279864ULL),((unsigned int)3749315707ULL)};
unsigned int b_3[4]={((unsigned int)3867827818ULL),((unsigned int)1359382704ULL),((unsigned int)3924279864ULL),((unsigned int)3749315707ULL)};
unsigned int a_4[4]={((unsigned int)119973373ULL),((unsigned int)2059837922ULL),((unsigned int)3315592535ULL),((unsigned int)3432529203ULL)};
unsigned int b_4[4]={((unsigned int)119973373ULL),((unsigned int)2059837922ULL),((unsigned int)3315592535ULL),((unsigned int)3432529203ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 62\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3503571977ULL),((unsigned int)3759691757ULL),((unsigned int)1289262931ULL),((unsigned int)3032057102ULL),((unsigned int)3270600688ULL),((unsigned int)1507246988ULL),((unsigned int)1891171065ULL),((unsigned int)1355760650ULL),((unsigned int)651197481ULL),((unsigned int)3098643076ULL),((unsigned int)2623088674ULL),((unsigned int)3612069936ULL),((unsigned int)2275228044ULL),((unsigned int)1185389613ULL),((unsigned int)2036401503ULL),((unsigned int)620644839ULL)};
unsigned int b_0[16]={((unsigned int)3503571977ULL),((unsigned int)3759691757ULL),((unsigned int)1289262931ULL),((unsigned int)3032057102ULL),((unsigned int)3270600688ULL),((unsigned int)1507246988ULL),((unsigned int)1891171065ULL),((unsigned int)1355760650ULL),((unsigned int)651197481ULL),((unsigned int)3098643076ULL),((unsigned int)2623088674ULL),((unsigned int)3612069936ULL),((unsigned int)2275228044ULL),((unsigned int)1185389613ULL),((unsigned int)2036401503ULL),((unsigned int)620644839ULL)};
unsigned int a_1[4]={((unsigned int)1448492804ULL),((unsigned int)907735995ULL),((unsigned int)2728590142ULL),((unsigned int)3067368152ULL)};
unsigned int b_1[4]={((unsigned int)1448492804ULL),((unsigned int)907735995ULL),((unsigned int)2728590142ULL),((unsigned int)3067368152ULL)};
unsigned int a_2[4]={((unsigned int)555680703ULL),((unsigned int)3145281671ULL),((unsigned int)729942859ULL),((unsigned int)3872436854ULL)};
unsigned int b_2[4]={((unsigned int)555680703ULL),((unsigned int)3145281671ULL),((unsigned int)729942859ULL),((unsigned int)3872436854ULL)};
unsigned int a_3[4]={((unsigned int)1147495941ULL),((unsigned int)1054509103ULL),((unsigned int)3556863004ULL),((unsigned int)3153755942ULL)};
unsigned int b_3[4]={((unsigned int)1147495941ULL),((unsigned int)1054509103ULL),((unsigned int)3556863004ULL),((unsigned int)3153755942ULL)};
unsigned int a_4[4]={((unsigned int)2533043671ULL),((unsigned int)3382171266ULL),((unsigned int)1184921431ULL),((unsigned int)1205015937ULL)};
unsigned int b_4[4]={((unsigned int)2533043671ULL),((unsigned int)3382171266ULL),((unsigned int)1184921431ULL),((unsigned int)1205015937ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 63\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)449504020ULL),((unsigned int)3341497745ULL),((unsigned int)3185692970ULL),((unsigned int)891036672ULL),((unsigned int)671873098ULL),((unsigned int)3094056714ULL),((unsigned int)469749000ULL),((unsigned int)564316366ULL),((unsigned int)1365206044ULL),((unsigned int)3870116094ULL),((unsigned int)2747170978ULL),((unsigned int)1573667481ULL),((unsigned int)66361290ULL),((unsigned int)3076762702ULL),((unsigned int)178053629ULL),((unsigned int)1557110409ULL)};
unsigned int b_0[16]={((unsigned int)449504020ULL),((unsigned int)3341497745ULL),((unsigned int)3185692970ULL),((unsigned int)891036672ULL),((unsigned int)671873098ULL),((unsigned int)3094056714ULL),((unsigned int)469749000ULL),((unsigned int)564316366ULL),((unsigned int)1365206044ULL),((unsigned int)3870116094ULL),((unsigned int)2747170978ULL),((unsigned int)1573667481ULL),((unsigned int)66361290ULL),((unsigned int)3076762702ULL),((unsigned int)178053629ULL),((unsigned int)1557110409ULL)};
unsigned int a_1[4]={((unsigned int)194643845ULL),((unsigned int)2696800378ULL),((unsigned int)838831125ULL),((unsigned int)2398193493ULL)};
unsigned int b_1[4]={((unsigned int)194643845ULL),((unsigned int)2696800378ULL),((unsigned int)838831125ULL),((unsigned int)2398193493ULL)};
unsigned int a_2[4]={((unsigned int)3042198514ULL),((unsigned int)1575677583ULL),((unsigned int)2804094391ULL),((unsigned int)3077478789ULL)};
unsigned int b_2[4]={((unsigned int)3042198514ULL),((unsigned int)1575677583ULL),((unsigned int)2804094391ULL),((unsigned int)3077478789ULL)};
unsigned int a_3[4]={((unsigned int)2314125544ULL),((unsigned int)1971810093ULL),((unsigned int)737056074ULL),((unsigned int)381165377ULL)};
unsigned int b_3[4]={((unsigned int)2314125544ULL),((unsigned int)1971810093ULL),((unsigned int)737056074ULL),((unsigned int)381165377ULL)};
unsigned int a_4[4]={((unsigned int)4164871284ULL),((unsigned int)4292520255ULL),((unsigned int)2776361304ULL),((unsigned int)1375088650ULL)};
unsigned int b_4[4]={((unsigned int)4164871284ULL),((unsigned int)4292520255ULL),((unsigned int)2776361304ULL),((unsigned int)1375088650ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 64\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1732853239ULL),((unsigned int)3952147437ULL),((unsigned int)928125706ULL),((unsigned int)2907842667ULL),((unsigned int)4180429533ULL),((unsigned int)1476709155ULL),((unsigned int)2878469614ULL),((unsigned int)1878039084ULL),((unsigned int)2033269364ULL),((unsigned int)2336385101ULL),((unsigned int)2126240282ULL),((unsigned int)3105212969ULL),((unsigned int)559213000ULL),((unsigned int)4049286904ULL),((unsigned int)3945934690ULL),((unsigned int)1296873915ULL)};
unsigned int b_0[16]={((unsigned int)1732853239ULL),((unsigned int)3952147437ULL),((unsigned int)928125706ULL),((unsigned int)2907842667ULL),((unsigned int)4180429533ULL),((unsigned int)1476709155ULL),((unsigned int)2878469614ULL),((unsigned int)1878039084ULL),((unsigned int)2033269364ULL),((unsigned int)2336385101ULL),((unsigned int)2126240282ULL),((unsigned int)3105212969ULL),((unsigned int)559213000ULL),((unsigned int)4049286904ULL),((unsigned int)3945934690ULL),((unsigned int)1296873915ULL)};
unsigned int a_1[4]={((unsigned int)3562669113ULL),((unsigned int)1675531005ULL),((unsigned int)3788058480ULL),((unsigned int)115141657ULL)};
unsigned int b_1[4]={((unsigned int)3562669113ULL),((unsigned int)1675531005ULL),((unsigned int)3788058480ULL),((unsigned int)115141657ULL)};
unsigned int a_2[4]={((unsigned int)2325418194ULL),((unsigned int)3238034525ULL),((unsigned int)44507259ULL),((unsigned int)2309629182ULL)};
unsigned int b_2[4]={((unsigned int)2325418194ULL),((unsigned int)3238034525ULL),((unsigned int)44507259ULL),((unsigned int)2309629182ULL)};
unsigned int a_3[4]={((unsigned int)3409884098ULL),((unsigned int)695337562ULL),((unsigned int)3421238141ULL),((unsigned int)3886039680ULL)};
unsigned int b_3[4]={((unsigned int)3409884098ULL),((unsigned int)695337562ULL),((unsigned int)3421238141ULL),((unsigned int)3886039680ULL)};
unsigned int a_4[4]={((unsigned int)3044158158ULL),((unsigned int)1958478360ULL),((unsigned int)3247113989ULL),((unsigned int)2693336580ULL)};
unsigned int b_4[4]={((unsigned int)3044158158ULL),((unsigned int)1958478360ULL),((unsigned int)3247113989ULL),((unsigned int)2693336580ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 65\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1046119077ULL),((unsigned int)3376178501ULL),((unsigned int)758903265ULL),((unsigned int)1753695110ULL),((unsigned int)1072567069ULL),((unsigned int)3672058260ULL),((unsigned int)396639978ULL),((unsigned int)1343207571ULL),((unsigned int)769167145ULL),((unsigned int)3843945666ULL),((unsigned int)2494429516ULL),((unsigned int)3111426152ULL),((unsigned int)3423250634ULL),((unsigned int)4127931483ULL),((unsigned int)1593699303ULL),((unsigned int)3102980907ULL)};
unsigned int b_0[16]={((unsigned int)1046119077ULL),((unsigned int)3376178501ULL),((unsigned int)758903265ULL),((unsigned int)1753695110ULL),((unsigned int)1072567069ULL),((unsigned int)3672058260ULL),((unsigned int)396639978ULL),((unsigned int)1343207571ULL),((unsigned int)769167145ULL),((unsigned int)3843945666ULL),((unsigned int)2494429516ULL),((unsigned int)3111426152ULL),((unsigned int)3423250634ULL),((unsigned int)4127931483ULL),((unsigned int)1593699303ULL),((unsigned int)3102980907ULL)};
unsigned int a_1[4]={((unsigned int)3466678847ULL),((unsigned int)3718998219ULL),((unsigned int)1537282734ULL),((unsigned int)2469000256ULL)};
unsigned int b_1[4]={((unsigned int)3466678847ULL),((unsigned int)3718998219ULL),((unsigned int)1537282734ULL),((unsigned int)2469000256ULL)};
unsigned int a_2[4]={((unsigned int)317367059ULL),((unsigned int)2515815652ULL),((unsigned int)2263906307ULL),((unsigned int)2198688277ULL)};
unsigned int b_2[4]={((unsigned int)317367059ULL),((unsigned int)2515815652ULL),((unsigned int)2263906307ULL),((unsigned int)2198688277ULL)};
unsigned int a_3[4]={((unsigned int)464209346ULL),((unsigned int)2299493419ULL),((unsigned int)2979049864ULL),((unsigned int)1636342148ULL)};
unsigned int b_3[4]={((unsigned int)464209346ULL),((unsigned int)2299493419ULL),((unsigned int)2979049864ULL),((unsigned int)1636342148ULL)};
unsigned int a_4[4]={((unsigned int)2656837868ULL),((unsigned int)1810851392ULL),((unsigned int)4021675321ULL),((unsigned int)586544246ULL)};
unsigned int b_4[4]={((unsigned int)2656837868ULL),((unsigned int)1810851392ULL),((unsigned int)4021675321ULL),((unsigned int)586544246ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 66\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4135387513ULL),((unsigned int)267581118ULL),((unsigned int)822647846ULL),((unsigned int)3742909844ULL),((unsigned int)3390351137ULL),((unsigned int)2374546351ULL),((unsigned int)1167475068ULL),((unsigned int)1444507770ULL),((unsigned int)1856527400ULL),((unsigned int)3697589777ULL),((unsigned int)419186492ULL),((unsigned int)3683116107ULL),((unsigned int)2838134033ULL),((unsigned int)4225637428ULL),((unsigned int)1778932551ULL),((unsigned int)105309881ULL)};
unsigned int b_0[16]={((unsigned int)4135387513ULL),((unsigned int)267581118ULL),((unsigned int)822647846ULL),((unsigned int)3742909844ULL),((unsigned int)3390351137ULL),((unsigned int)2374546351ULL),((unsigned int)1167475068ULL),((unsigned int)1444507770ULL),((unsigned int)1856527400ULL),((unsigned int)3697589777ULL),((unsigned int)419186492ULL),((unsigned int)3683116107ULL),((unsigned int)2838134033ULL),((unsigned int)4225637428ULL),((unsigned int)1778932551ULL),((unsigned int)105309881ULL)};
unsigned int a_1[4]={((unsigned int)2552805138ULL),((unsigned int)3804897470ULL),((unsigned int)1080034745ULL),((unsigned int)556670961ULL)};
unsigned int b_1[4]={((unsigned int)2552805138ULL),((unsigned int)3804897470ULL),((unsigned int)1080034745ULL),((unsigned int)556670961ULL)};
unsigned int a_2[4]={((unsigned int)3584564242ULL),((unsigned int)3859376047ULL),((unsigned int)2537516012ULL),((unsigned int)1712155059ULL)};
unsigned int b_2[4]={((unsigned int)3584564242ULL),((unsigned int)3859376047ULL),((unsigned int)2537516012ULL),((unsigned int)1712155059ULL)};
unsigned int a_3[4]={((unsigned int)2585962291ULL),((unsigned int)1514362762ULL),((unsigned int)399050634ULL),((unsigned int)868755618ULL)};
unsigned int b_3[4]={((unsigned int)2585962291ULL),((unsigned int)1514362762ULL),((unsigned int)399050634ULL),((unsigned int)868755618ULL)};
unsigned int a_4[4]={((unsigned int)1688234697ULL),((unsigned int)4237155388ULL),((unsigned int)1537463570ULL),((unsigned int)568732226ULL)};
unsigned int b_4[4]={((unsigned int)1688234697ULL),((unsigned int)4237155388ULL),((unsigned int)1537463570ULL),((unsigned int)568732226ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 67\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2845923958ULL),((unsigned int)1329860392ULL),((unsigned int)3173027834ULL),((unsigned int)2496546043ULL),((unsigned int)3710035053ULL),((unsigned int)3156495228ULL),((unsigned int)3566933180ULL),((unsigned int)2215659541ULL),((unsigned int)426331359ULL),((unsigned int)156344321ULL),((unsigned int)3371356301ULL),((unsigned int)70249454ULL),((unsigned int)3359927629ULL),((unsigned int)3526329313ULL),((unsigned int)2863752140ULL),((unsigned int)2000851469ULL)};
unsigned int b_0[16]={((unsigned int)2845923958ULL),((unsigned int)1329860392ULL),((unsigned int)3173027834ULL),((unsigned int)2496546043ULL),((unsigned int)3710035053ULL),((unsigned int)3156495228ULL),((unsigned int)3566933180ULL),((unsigned int)2215659541ULL),((unsigned int)426331359ULL),((unsigned int)156344321ULL),((unsigned int)3371356301ULL),((unsigned int)70249454ULL),((unsigned int)3359927629ULL),((unsigned int)3526329313ULL),((unsigned int)2863752140ULL),((unsigned int)2000851469ULL)};
unsigned int a_1[4]={((unsigned int)1305796839ULL),((unsigned int)1949921921ULL),((unsigned int)3838216781ULL),((unsigned int)2860458029ULL)};
unsigned int b_1[4]={((unsigned int)1305796839ULL),((unsigned int)1949921921ULL),((unsigned int)3838216781ULL),((unsigned int)2860458029ULL)};
unsigned int a_2[4]={((unsigned int)412239362ULL),((unsigned int)1884171612ULL),((unsigned int)3721826506ULL),((unsigned int)645003650ULL)};
unsigned int b_2[4]={((unsigned int)412239362ULL),((unsigned int)1884171612ULL),((unsigned int)3721826506ULL),((unsigned int)645003650ULL)};
unsigned int a_3[4]={((unsigned int)2318874391ULL),((unsigned int)94572790ULL),((unsigned int)2726428217ULL),((unsigned int)2719623626ULL)};
unsigned int b_3[4]={((unsigned int)2318874391ULL),((unsigned int)94572790ULL),((unsigned int)2726428217ULL),((unsigned int)2719623626ULL)};
unsigned int a_4[4]={((unsigned int)3342294634ULL),((unsigned int)3626635816ULL),((unsigned int)4052812832ULL),((unsigned int)1991211228ULL)};
unsigned int b_4[4]={((unsigned int)3342294634ULL),((unsigned int)3626635816ULL),((unsigned int)4052812832ULL),((unsigned int)1991211228ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 68\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)498249871ULL),((unsigned int)768149875ULL),((unsigned int)2979416954ULL),((unsigned int)3186621046ULL),((unsigned int)2304867987ULL),((unsigned int)950302194ULL),((unsigned int)1655970252ULL),((unsigned int)3080646398ULL),((unsigned int)4230032734ULL),((unsigned int)2978358160ULL),((unsigned int)3767642160ULL),((unsigned int)1062405309ULL),((unsigned int)1517758651ULL),((unsigned int)2720736423ULL),((unsigned int)1908015405ULL),((unsigned int)3923821352ULL)};
unsigned int b_0[16]={((unsigned int)498249871ULL),((unsigned int)768149875ULL),((unsigned int)2979416954ULL),((unsigned int)3186621046ULL),((unsigned int)2304867987ULL),((unsigned int)950302194ULL),((unsigned int)1655970252ULL),((unsigned int)3080646398ULL),((unsigned int)4230032734ULL),((unsigned int)2978358160ULL),((unsigned int)3767642160ULL),((unsigned int)1062405309ULL),((unsigned int)1517758651ULL),((unsigned int)2720736423ULL),((unsigned int)1908015405ULL),((unsigned int)3923821352ULL)};
unsigned int a_1[4]={((unsigned int)790025424ULL),((unsigned int)2173571666ULL),((unsigned int)735488206ULL),((unsigned int)3621212409ULL)};
unsigned int b_1[4]={((unsigned int)790025424ULL),((unsigned int)2173571666ULL),((unsigned int)735488206ULL),((unsigned int)3621212409ULL)};
unsigned int a_2[4]={((unsigned int)2720195439ULL),((unsigned int)3976656209ULL),((unsigned int)648182474ULL),((unsigned int)3723933850ULL)};
unsigned int b_2[4]={((unsigned int)2720195439ULL),((unsigned int)3976656209ULL),((unsigned int)648182474ULL),((unsigned int)3723933850ULL)};
unsigned int a_3[4]={((unsigned int)3931302846ULL),((unsigned int)4170332957ULL),((unsigned int)766855897ULL),((unsigned int)106016459ULL)};
unsigned int b_3[4]={((unsigned int)3931302846ULL),((unsigned int)4170332957ULL),((unsigned int)766855897ULL),((unsigned int)106016459ULL)};
unsigned int a_4[4]={((unsigned int)1811829175ULL),((unsigned int)2426304200ULL),((unsigned int)3795684356ULL),((unsigned int)3260708091ULL)};
unsigned int b_4[4]={((unsigned int)1811829175ULL),((unsigned int)2426304200ULL),((unsigned int)3795684356ULL),((unsigned int)3260708091ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 69\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3775946534ULL),((unsigned int)1198199146ULL),((unsigned int)1648610236ULL),((unsigned int)2436465119ULL),((unsigned int)1724235428ULL),((unsigned int)2657008446ULL),((unsigned int)3349414828ULL),((unsigned int)998536168ULL),((unsigned int)1763628197ULL),((unsigned int)150334357ULL),((unsigned int)887908711ULL),((unsigned int)3615420792ULL),((unsigned int)3552980123ULL),((unsigned int)185778093ULL),((unsigned int)779234037ULL),((unsigned int)896845791ULL)};
unsigned int b_0[16]={((unsigned int)3775946534ULL),((unsigned int)1198199146ULL),((unsigned int)1648610236ULL),((unsigned int)2436465119ULL),((unsigned int)1724235428ULL),((unsigned int)2657008446ULL),((unsigned int)3349414828ULL),((unsigned int)998536168ULL),((unsigned int)1763628197ULL),((unsigned int)150334357ULL),((unsigned int)887908711ULL),((unsigned int)3615420792ULL),((unsigned int)3552980123ULL),((unsigned int)185778093ULL),((unsigned int)779234037ULL),((unsigned int)896845791ULL)};
unsigned int a_1[4]={((unsigned int)2926122517ULL),((unsigned int)3866588121ULL),((unsigned int)2536538887ULL),((unsigned int)2659667743ULL)};
unsigned int b_1[4]={((unsigned int)2926122517ULL),((unsigned int)3866588121ULL),((unsigned int)2536538887ULL),((unsigned int)2659667743ULL)};
unsigned int a_2[4]={((unsigned int)2436784478ULL),((unsigned int)2880758786ULL),((unsigned int)1531139571ULL),((unsigned int)1962325284ULL)};
unsigned int b_2[4]={((unsigned int)2436784478ULL),((unsigned int)2880758786ULL),((unsigned int)1531139571ULL),((unsigned int)1962325284ULL)};
unsigned int a_3[4]={((unsigned int)3847849592ULL),((unsigned int)1821692832ULL),((unsigned int)2651461384ULL),((unsigned int)3995145934ULL)};
unsigned int b_3[4]={((unsigned int)3847849592ULL),((unsigned int)1821692832ULL),((unsigned int)2651461384ULL),((unsigned int)3995145934ULL)};
unsigned int a_4[4]={((unsigned int)1419577906ULL),((unsigned int)66043597ULL),((unsigned int)1214477687ULL),((unsigned int)3774124364ULL)};
unsigned int b_4[4]={((unsigned int)1419577906ULL),((unsigned int)66043597ULL),((unsigned int)1214477687ULL),((unsigned int)3774124364ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 70\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)987094997ULL),((unsigned int)792587057ULL),((unsigned int)3886234529ULL),((unsigned int)1576939902ULL),((unsigned int)613719829ULL),((unsigned int)3454062954ULL),((unsigned int)3011198137ULL),((unsigned int)3304738799ULL),((unsigned int)3148472187ULL),((unsigned int)2926000161ULL),((unsigned int)4069431344ULL),((unsigned int)3835114394ULL),((unsigned int)233679374ULL),((unsigned int)1819180799ULL),((unsigned int)1318905210ULL),((unsigned int)1672779309ULL)};
unsigned int b_0[16]={((unsigned int)987094997ULL),((unsigned int)792587057ULL),((unsigned int)3886234529ULL),((unsigned int)1576939902ULL),((unsigned int)613719829ULL),((unsigned int)3454062954ULL),((unsigned int)3011198137ULL),((unsigned int)3304738799ULL),((unsigned int)3148472187ULL),((unsigned int)2926000161ULL),((unsigned int)4069431344ULL),((unsigned int)3835114394ULL),((unsigned int)233679374ULL),((unsigned int)1819180799ULL),((unsigned int)1318905210ULL),((unsigned int)1672779309ULL)};
unsigned int a_1[4]={((unsigned int)1870707989ULL),((unsigned int)282705474ULL),((unsigned int)571785254ULL),((unsigned int)1934197360ULL)};
unsigned int b_1[4]={((unsigned int)1870707989ULL),((unsigned int)282705474ULL),((unsigned int)571785254ULL),((unsigned int)1934197360ULL)};
unsigned int a_2[4]={((unsigned int)3886519892ULL),((unsigned int)4087665936ULL),((unsigned int)1514307312ULL),((unsigned int)2536754501ULL)};
unsigned int b_2[4]={((unsigned int)3886519892ULL),((unsigned int)4087665936ULL),((unsigned int)1514307312ULL),((unsigned int)2536754501ULL)};
unsigned int a_3[4]={((unsigned int)895150909ULL),((unsigned int)3135952214ULL),((unsigned int)4201891597ULL),((unsigned int)2605089288ULL)};
unsigned int b_3[4]={((unsigned int)895150909ULL),((unsigned int)3135952214ULL),((unsigned int)4201891597ULL),((unsigned int)2605089288ULL)};
unsigned int a_4[4]={((unsigned int)2232977051ULL),((unsigned int)2777030424ULL),((unsigned int)1169128683ULL),((unsigned int)2306989367ULL)};
unsigned int b_4[4]={((unsigned int)2232977051ULL),((unsigned int)2777030424ULL),((unsigned int)1169128683ULL),((unsigned int)2306989367ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 71\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2467043075ULL),((unsigned int)1164408472ULL),((unsigned int)2463834008ULL),((unsigned int)1738980761ULL),((unsigned int)2792216990ULL),((unsigned int)926866548ULL),((unsigned int)147270889ULL),((unsigned int)1431896677ULL),((unsigned int)70641938ULL),((unsigned int)431252544ULL),((unsigned int)2693436424ULL),((unsigned int)2934955038ULL),((unsigned int)374409947ULL),((unsigned int)807445449ULL),((unsigned int)2848689198ULL),((unsigned int)2412732527ULL)};
unsigned int b_0[16]={((unsigned int)2467043075ULL),((unsigned int)1164408472ULL),((unsigned int)2463834008ULL),((unsigned int)1738980761ULL),((unsigned int)2792216990ULL),((unsigned int)926866548ULL),((unsigned int)147270889ULL),((unsigned int)1431896677ULL),((unsigned int)70641938ULL),((unsigned int)431252544ULL),((unsigned int)2693436424ULL),((unsigned int)2934955038ULL),((unsigned int)374409947ULL),((unsigned int)807445449ULL),((unsigned int)2848689198ULL),((unsigned int)2412732527ULL)};
unsigned int a_1[4]={((unsigned int)1376793455ULL),((unsigned int)575610012ULL),((unsigned int)1723930106ULL),((unsigned int)1076349398ULL)};
unsigned int b_1[4]={((unsigned int)1376793455ULL),((unsigned int)575610012ULL),((unsigned int)1723930106ULL),((unsigned int)1076349398ULL)};
unsigned int a_2[4]={((unsigned int)4142462600ULL),((unsigned int)206207546ULL),((unsigned int)1466449209ULL),((unsigned int)3734374480ULL)};
unsigned int b_2[4]={((unsigned int)4142462600ULL),((unsigned int)206207546ULL),((unsigned int)1466449209ULL),((unsigned int)3734374480ULL)};
unsigned int a_3[4]={((unsigned int)1103837907ULL),((unsigned int)167773870ULL),((unsigned int)1172984639ULL),((unsigned int)1050416595ULL)};
unsigned int b_3[4]={((unsigned int)1103837907ULL),((unsigned int)167773870ULL),((unsigned int)1172984639ULL),((unsigned int)1050416595ULL)};
unsigned int a_4[4]={((unsigned int)1498191869ULL),((unsigned int)2100193684ULL),((unsigned int)725987581ULL),((unsigned int)4156775717ULL)};
unsigned int b_4[4]={((unsigned int)1498191869ULL),((unsigned int)2100193684ULL),((unsigned int)725987581ULL),((unsigned int)4156775717ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 72\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3849992284ULL),((unsigned int)1614673192ULL),((unsigned int)1881853841ULL),((unsigned int)1687252460ULL),((unsigned int)2800719294ULL),((unsigned int)3331639862ULL),((unsigned int)2336607744ULL),((unsigned int)959669451ULL),((unsigned int)566510687ULL),((unsigned int)2284113920ULL),((unsigned int)3933585338ULL),((unsigned int)2187789454ULL),((unsigned int)2383389194ULL),((unsigned int)3834131639ULL),((unsigned int)1476365528ULL),((unsigned int)2030127699ULL)};
unsigned int b_0[16]={((unsigned int)3849992284ULL),((unsigned int)1614673192ULL),((unsigned int)1881853841ULL),((unsigned int)1687252460ULL),((unsigned int)2800719294ULL),((unsigned int)3331639862ULL),((unsigned int)2336607744ULL),((unsigned int)959669451ULL),((unsigned int)566510687ULL),((unsigned int)2284113920ULL),((unsigned int)3933585338ULL),((unsigned int)2187789454ULL),((unsigned int)2383389194ULL),((unsigned int)3834131639ULL),((unsigned int)1476365528ULL),((unsigned int)2030127699ULL)};
unsigned int a_1[4]={((unsigned int)3129378049ULL),((unsigned int)329112440ULL),((unsigned int)2455823160ULL),((unsigned int)1527225660ULL)};
unsigned int b_1[4]={((unsigned int)3129378049ULL),((unsigned int)329112440ULL),((unsigned int)2455823160ULL),((unsigned int)1527225660ULL)};
unsigned int a_2[4]={((unsigned int)2581002624ULL),((unsigned int)2577740782ULL),((unsigned int)2348086714ULL),((unsigned int)2891939238ULL)};
unsigned int b_2[4]={((unsigned int)2581002624ULL),((unsigned int)2577740782ULL),((unsigned int)2348086714ULL),((unsigned int)2891939238ULL)};
unsigned int a_3[4]={((unsigned int)2162282774ULL),((unsigned int)3937857241ULL),((unsigned int)2932326373ULL),((unsigned int)1115354431ULL)};
unsigned int b_3[4]={((unsigned int)2162282774ULL),((unsigned int)3937857241ULL),((unsigned int)2932326373ULL),((unsigned int)1115354431ULL)};
unsigned int a_4[4]={((unsigned int)3074773154ULL),((unsigned int)250213997ULL),((unsigned int)1032901710ULL),((unsigned int)1845159566ULL)};
unsigned int b_4[4]={((unsigned int)3074773154ULL),((unsigned int)250213997ULL),((unsigned int)1032901710ULL),((unsigned int)1845159566ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 73\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)687519841ULL),((unsigned int)355370278ULL),((unsigned int)3533507364ULL),((unsigned int)141078434ULL),((unsigned int)2804297013ULL),((unsigned int)3296588905ULL),((unsigned int)4275648203ULL),((unsigned int)1042855965ULL),((unsigned int)4003544791ULL),((unsigned int)3152316076ULL),((unsigned int)1513198436ULL),((unsigned int)584981598ULL),((unsigned int)717948336ULL),((unsigned int)1566855812ULL),((unsigned int)2335107557ULL),((unsigned int)1765231092ULL)};
unsigned int b_0[16]={((unsigned int)687519841ULL),((unsigned int)355370278ULL),((unsigned int)3533507364ULL),((unsigned int)141078434ULL),((unsigned int)2804297013ULL),((unsigned int)3296588905ULL),((unsigned int)4275648203ULL),((unsigned int)1042855965ULL),((unsigned int)4003544791ULL),((unsigned int)3152316076ULL),((unsigned int)1513198436ULL),((unsigned int)584981598ULL),((unsigned int)717948336ULL),((unsigned int)1566855812ULL),((unsigned int)2335107557ULL),((unsigned int)1765231092ULL)};
unsigned int a_1[4]={((unsigned int)2665147541ULL),((unsigned int)1733073963ULL),((unsigned int)683367431ULL),((unsigned int)2734848429ULL)};
unsigned int b_1[4]={((unsigned int)2665147541ULL),((unsigned int)1733073963ULL),((unsigned int)683367431ULL),((unsigned int)2734848429ULL)};
unsigned int a_2[4]={((unsigned int)1689730507ULL),((unsigned int)4292895793ULL),((unsigned int)3098125318ULL),((unsigned int)1826331386ULL)};
unsigned int b_2[4]={((unsigned int)1689730507ULL),((unsigned int)4292895793ULL),((unsigned int)3098125318ULL),((unsigned int)1826331386ULL)};
unsigned int a_3[4]={((unsigned int)241698576ULL),((unsigned int)1578257728ULL),((unsigned int)3130407330ULL),((unsigned int)367373712ULL)};
unsigned int b_3[4]={((unsigned int)241698576ULL),((unsigned int)1578257728ULL),((unsigned int)3130407330ULL),((unsigned int)367373712ULL)};
unsigned int a_4[4]={((unsigned int)2420218806ULL),((unsigned int)4109675840ULL),((unsigned int)312109629ULL),((unsigned int)2540506586ULL)};
unsigned int b_4[4]={((unsigned int)2420218806ULL),((unsigned int)4109675840ULL),((unsigned int)312109629ULL),((unsigned int)2540506586ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 74\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3359480089ULL),((unsigned int)3181185087ULL),((unsigned int)2029097438ULL),((unsigned int)3346298354ULL),((unsigned int)3107314533ULL),((unsigned int)608032446ULL),((unsigned int)1800355425ULL),((unsigned int)940809880ULL),((unsigned int)2240539792ULL),((unsigned int)2471795245ULL),((unsigned int)803490520ULL),((unsigned int)2417251842ULL),((unsigned int)2418152322ULL),((unsigned int)1145138940ULL),((unsigned int)4095479267ULL),((unsigned int)1398935204ULL)};
unsigned int b_0[16]={((unsigned int)3359480089ULL),((unsigned int)3181185087ULL),((unsigned int)2029097438ULL),((unsigned int)3346298354ULL),((unsigned int)3107314533ULL),((unsigned int)608032446ULL),((unsigned int)1800355425ULL),((unsigned int)940809880ULL),((unsigned int)2240539792ULL),((unsigned int)2471795245ULL),((unsigned int)803490520ULL),((unsigned int)2417251842ULL),((unsigned int)2418152322ULL),((unsigned int)1145138940ULL),((unsigned int)4095479267ULL),((unsigned int)1398935204ULL)};
unsigned int a_1[4]={((unsigned int)244346237ULL),((unsigned int)2980635046ULL),((unsigned int)3935580873ULL),((unsigned int)584708952ULL)};
unsigned int b_1[4]={((unsigned int)244346237ULL),((unsigned int)2980635046ULL),((unsigned int)3935580873ULL),((unsigned int)584708952ULL)};
unsigned int a_2[4]={((unsigned int)1035535220ULL),((unsigned int)31511720ULL),((unsigned int)3729752028ULL),((unsigned int)1072325496ULL)};
unsigned int b_2[4]={((unsigned int)1035535220ULL),((unsigned int)31511720ULL),((unsigned int)3729752028ULL),((unsigned int)1072325496ULL)};
unsigned int a_3[4]={((unsigned int)1147704108ULL),((unsigned int)1832908455ULL),((unsigned int)692928320ULL),((unsigned int)4113933455ULL)};
unsigned int b_3[4]={((unsigned int)1147704108ULL),((unsigned int)1832908455ULL),((unsigned int)692928320ULL),((unsigned int)4113933455ULL)};
unsigned int a_4[4]={((unsigned int)470855939ULL),((unsigned int)3801415589ULL),((unsigned int)3767758968ULL),((unsigned int)908098621ULL)};
unsigned int b_4[4]={((unsigned int)470855939ULL),((unsigned int)3801415589ULL),((unsigned int)3767758968ULL),((unsigned int)908098621ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 75\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2470603094ULL),((unsigned int)2161560361ULL),((unsigned int)2682278849ULL),((unsigned int)2535346513ULL),((unsigned int)1273909972ULL),((unsigned int)3720855267ULL),((unsigned int)159881468ULL),((unsigned int)922235760ULL),((unsigned int)1653842894ULL),((unsigned int)4188201306ULL),((unsigned int)140948449ULL),((unsigned int)3752536258ULL),((unsigned int)3939194229ULL),((unsigned int)369721822ULL),((unsigned int)2392976853ULL),((unsigned int)2334553639ULL)};
unsigned int b_0[16]={((unsigned int)2470603094ULL),((unsigned int)2161560361ULL),((unsigned int)2682278849ULL),((unsigned int)2535346513ULL),((unsigned int)1273909972ULL),((unsigned int)3720855267ULL),((unsigned int)159881468ULL),((unsigned int)922235760ULL),((unsigned int)1653842894ULL),((unsigned int)4188201306ULL),((unsigned int)140948449ULL),((unsigned int)3752536258ULL),((unsigned int)3939194229ULL),((unsigned int)369721822ULL),((unsigned int)2392976853ULL),((unsigned int)2334553639ULL)};
unsigned int a_1[4]={((unsigned int)3680594254ULL),((unsigned int)4076683430ULL),((unsigned int)3268203776ULL),((unsigned int)4180949294ULL)};
unsigned int b_1[4]={((unsigned int)3680594254ULL),((unsigned int)4076683430ULL),((unsigned int)3268203776ULL),((unsigned int)4180949294ULL)};
unsigned int a_2[4]={((unsigned int)4260677457ULL),((unsigned int)201635482ULL),((unsigned int)2024024806ULL),((unsigned int)416337805ULL)};
unsigned int b_2[4]={((unsigned int)4260677457ULL),((unsigned int)201635482ULL),((unsigned int)2024024806ULL),((unsigned int)416337805ULL)};
unsigned int a_3[4]={((unsigned int)784667713ULL),((unsigned int)2624878482ULL),((unsigned int)1876365324ULL),((unsigned int)1441074354ULL)};
unsigned int b_3[4]={((unsigned int)784667713ULL),((unsigned int)2624878482ULL),((unsigned int)1876365324ULL),((unsigned int)1441074354ULL)};
unsigned int a_4[4]={((unsigned int)3692368188ULL),((unsigned int)4185834562ULL),((unsigned int)2791084943ULL),((unsigned int)1559618819ULL)};
unsigned int b_4[4]={((unsigned int)3692368188ULL),((unsigned int)4185834562ULL),((unsigned int)2791084943ULL),((unsigned int)1559618819ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 76\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2301210436ULL),((unsigned int)2116943920ULL),((unsigned int)587233189ULL),((unsigned int)2778910113ULL),((unsigned int)2320040062ULL),((unsigned int)2124688210ULL),((unsigned int)3144353535ULL),((unsigned int)1655143797ULL),((unsigned int)1733586038ULL),((unsigned int)1922288166ULL),((unsigned int)611961916ULL),((unsigned int)1136042959ULL),((unsigned int)4010998454ULL),((unsigned int)3777840760ULL),((unsigned int)224553658ULL),((unsigned int)2507017135ULL)};
unsigned int b_0[16]={((unsigned int)2301210436ULL),((unsigned int)2116943920ULL),((unsigned int)587233189ULL),((unsigned int)2778910113ULL),((unsigned int)2320040062ULL),((unsigned int)2124688210ULL),((unsigned int)3144353535ULL),((unsigned int)1655143797ULL),((unsigned int)1733586038ULL),((unsigned int)1922288166ULL),((unsigned int)611961916ULL),((unsigned int)1136042959ULL),((unsigned int)4010998454ULL),((unsigned int)3777840760ULL),((unsigned int)224553658ULL),((unsigned int)2507017135ULL)};
unsigned int a_1[4]={((unsigned int)3262454861ULL),((unsigned int)1865480830ULL),((unsigned int)989870537ULL),((unsigned int)1351629283ULL)};
unsigned int b_1[4]={((unsigned int)3262454861ULL),((unsigned int)1865480830ULL),((unsigned int)989870537ULL),((unsigned int)1351629283ULL)};
unsigned int a_2[4]={((unsigned int)1288444516ULL),((unsigned int)2989381873ULL),((unsigned int)3181914645ULL),((unsigned int)3258448981ULL)};
unsigned int b_2[4]={((unsigned int)1288444516ULL),((unsigned int)2989381873ULL),((unsigned int)3181914645ULL),((unsigned int)3258448981ULL)};
unsigned int a_3[4]={((unsigned int)4148578473ULL),((unsigned int)1655569213ULL),((unsigned int)970286953ULL),((unsigned int)1109779355ULL)};
unsigned int b_3[4]={((unsigned int)4148578473ULL),((unsigned int)1655569213ULL),((unsigned int)970286953ULL),((unsigned int)1109779355ULL)};
unsigned int a_4[4]={((unsigned int)158005774ULL),((unsigned int)1942363236ULL),((unsigned int)2564536268ULL),((unsigned int)4108068692ULL)};
unsigned int b_4[4]={((unsigned int)158005774ULL),((unsigned int)1942363236ULL),((unsigned int)2564536268ULL),((unsigned int)4108068692ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 77\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3360957116ULL),((unsigned int)174350697ULL),((unsigned int)675611496ULL),((unsigned int)2253489520ULL),((unsigned int)2641474837ULL),((unsigned int)4218849413ULL),((unsigned int)4226889333ULL),((unsigned int)3587126998ULL),((unsigned int)3189669151ULL),((unsigned int)2687722564ULL),((unsigned int)3170133796ULL),((unsigned int)3929437860ULL),((unsigned int)1751732283ULL),((unsigned int)2061171731ULL),((unsigned int)2629615148ULL),((unsigned int)2885748088ULL)};
unsigned int b_0[16]={((unsigned int)3360957116ULL),((unsigned int)174350697ULL),((unsigned int)675611496ULL),((unsigned int)2253489520ULL),((unsigned int)2641474837ULL),((unsigned int)4218849413ULL),((unsigned int)4226889333ULL),((unsigned int)3587126998ULL),((unsigned int)3189669151ULL),((unsigned int)2687722564ULL),((unsigned int)3170133796ULL),((unsigned int)3929437860ULL),((unsigned int)1751732283ULL),((unsigned int)2061171731ULL),((unsigned int)2629615148ULL),((unsigned int)2885748088ULL)};
unsigned int a_1[4]={((unsigned int)4292453912ULL),((unsigned int)2632551895ULL),((unsigned int)3645325137ULL),((unsigned int)4293918373ULL)};
unsigned int b_1[4]={((unsigned int)4292453912ULL),((unsigned int)2632551895ULL),((unsigned int)3645325137ULL),((unsigned int)4293918373ULL)};
unsigned int a_2[4]={((unsigned int)3072102379ULL),((unsigned int)2461999694ULL),((unsigned int)81248848ULL),((unsigned int)3903783000ULL)};
unsigned int b_2[4]={((unsigned int)3072102379ULL),((unsigned int)2461999694ULL),((unsigned int)81248848ULL),((unsigned int)3903783000ULL)};
unsigned int a_3[4]={((unsigned int)3147538508ULL),((unsigned int)1625234628ULL),((unsigned int)1924537068ULL),((unsigned int)4086906487ULL)};
unsigned int b_3[4]={((unsigned int)3147538508ULL),((unsigned int)1625234628ULL),((unsigned int)1924537068ULL),((unsigned int)4086906487ULL)};
unsigned int a_4[4]={((unsigned int)2434346667ULL),((unsigned int)517037307ULL),((unsigned int)2250465674ULL),((unsigned int)1134877136ULL)};
unsigned int b_4[4]={((unsigned int)2434346667ULL),((unsigned int)517037307ULL),((unsigned int)2250465674ULL),((unsigned int)1134877136ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 78\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2522196945ULL),((unsigned int)1405211117ULL),((unsigned int)3874084579ULL),((unsigned int)4125217225ULL),((unsigned int)2995991143ULL),((unsigned int)2658465689ULL),((unsigned int)312436348ULL),((unsigned int)2681769450ULL),((unsigned int)25974658ULL),((unsigned int)3170959732ULL),((unsigned int)2668780118ULL),((unsigned int)391609293ULL),((unsigned int)3369539175ULL),((unsigned int)2412515188ULL),((unsigned int)1445411181ULL),((unsigned int)2086312269ULL)};
unsigned int b_0[16]={((unsigned int)2522196945ULL),((unsigned int)1405211117ULL),((unsigned int)3874084579ULL),((unsigned int)4125217225ULL),((unsigned int)2995991143ULL),((unsigned int)2658465689ULL),((unsigned int)312436348ULL),((unsigned int)2681769450ULL),((unsigned int)25974658ULL),((unsigned int)3170959732ULL),((unsigned int)2668780118ULL),((unsigned int)391609293ULL),((unsigned int)3369539175ULL),((unsigned int)2412515188ULL),((unsigned int)1445411181ULL),((unsigned int)2086312269ULL)};
unsigned int a_1[4]={((unsigned int)2814292946ULL),((unsigned int)1149752742ULL),((unsigned int)650554667ULL),((unsigned int)1780231082ULL)};
unsigned int b_1[4]={((unsigned int)2814292946ULL),((unsigned int)1149752742ULL),((unsigned int)650554667ULL),((unsigned int)1780231082ULL)};
unsigned int a_2[4]={((unsigned int)1518877688ULL),((unsigned int)272318041ULL),((unsigned int)3902093778ULL),((unsigned int)553657284ULL)};
unsigned int b_2[4]={((unsigned int)1518877688ULL),((unsigned int)272318041ULL),((unsigned int)3902093778ULL),((unsigned int)553657284ULL)};
unsigned int a_3[4]={((unsigned int)358379855ULL),((unsigned int)1159302362ULL),((unsigned int)3344317390ULL),((unsigned int)2451906808ULL)};
unsigned int b_3[4]={((unsigned int)358379855ULL),((unsigned int)1159302362ULL),((unsigned int)3344317390ULL),((unsigned int)2451906808ULL)};
unsigned int a_4[4]={((unsigned int)2623037998ULL),((unsigned int)1244816256ULL),((unsigned int)1690966747ULL),((unsigned int)4085378387ULL)};
unsigned int b_4[4]={((unsigned int)2623037998ULL),((unsigned int)1244816256ULL),((unsigned int)1690966747ULL),((unsigned int)4085378387ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 79\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2505093703ULL),((unsigned int)1979250610ULL),((unsigned int)3974509139ULL),((unsigned int)3292754116ULL),((unsigned int)1235361198ULL),((unsigned int)4268741114ULL),((unsigned int)1612109325ULL),((unsigned int)146390352ULL),((unsigned int)1762422230ULL),((unsigned int)1605553989ULL),((unsigned int)1060357925ULL),((unsigned int)3670694209ULL),((unsigned int)538570254ULL),((unsigned int)761721700ULL),((unsigned int)704709188ULL),((unsigned int)1093636338ULL)};
unsigned int b_0[16]={((unsigned int)2505093703ULL),((unsigned int)1979250610ULL),((unsigned int)3974509139ULL),((unsigned int)3292754116ULL),((unsigned int)1235361198ULL),((unsigned int)4268741114ULL),((unsigned int)1612109325ULL),((unsigned int)146390352ULL),((unsigned int)1762422230ULL),((unsigned int)1605553989ULL),((unsigned int)1060357925ULL),((unsigned int)3670694209ULL),((unsigned int)538570254ULL),((unsigned int)761721700ULL),((unsigned int)704709188ULL),((unsigned int)1093636338ULL)};
unsigned int a_1[4]={((unsigned int)186253758ULL),((unsigned int)2786269384ULL),((unsigned int)939776825ULL),((unsigned int)1489616644ULL)};
unsigned int b_1[4]={((unsigned int)186253758ULL),((unsigned int)2786269384ULL),((unsigned int)939776825ULL),((unsigned int)1489616644ULL)};
unsigned int a_2[4]={((unsigned int)3898339151ULL),((unsigned int)1751352808ULL),((unsigned int)139591910ULL),((unsigned int)2568738450ULL)};
unsigned int b_2[4]={((unsigned int)3898339151ULL),((unsigned int)1751352808ULL),((unsigned int)139591910ULL),((unsigned int)2568738450ULL)};
unsigned int a_3[4]={((unsigned int)458289235ULL),((unsigned int)3656339513ULL),((unsigned int)262546116ULL),((unsigned int)2712925821ULL)};
unsigned int b_3[4]={((unsigned int)458289235ULL),((unsigned int)3656339513ULL),((unsigned int)262546116ULL),((unsigned int)2712925821ULL)};
unsigned int a_4[4]={((unsigned int)118936445ULL),((unsigned int)3410651376ULL),((unsigned int)3805650559ULL),((unsigned int)2315518664ULL)};
unsigned int b_4[4]={((unsigned int)118936445ULL),((unsigned int)3410651376ULL),((unsigned int)3805650559ULL),((unsigned int)2315518664ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 80\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1642348803ULL),((unsigned int)1443820429ULL),((unsigned int)220775756ULL),((unsigned int)2443454645ULL),((unsigned int)3788734917ULL),((unsigned int)3497224229ULL),((unsigned int)180420384ULL),((unsigned int)2504126914ULL),((unsigned int)790443782ULL),((unsigned int)4090333433ULL),((unsigned int)4019794798ULL),((unsigned int)732254418ULL),((unsigned int)4272482574ULL),((unsigned int)2434806689ULL),((unsigned int)519225971ULL),((unsigned int)2244068132ULL)};
unsigned int b_0[16]={((unsigned int)1642348803ULL),((unsigned int)1443820429ULL),((unsigned int)220775756ULL),((unsigned int)2443454645ULL),((unsigned int)3788734917ULL),((unsigned int)3497224229ULL),((unsigned int)180420384ULL),((unsigned int)2504126914ULL),((unsigned int)790443782ULL),((unsigned int)4090333433ULL),((unsigned int)4019794798ULL),((unsigned int)732254418ULL),((unsigned int)4272482574ULL),((unsigned int)2434806689ULL),((unsigned int)519225971ULL),((unsigned int)2244068132ULL)};
unsigned int a_1[4]={((unsigned int)642547343ULL),((unsigned int)4217016738ULL),((unsigned int)3996633073ULL),((unsigned int)2660166606ULL)};
unsigned int b_1[4]={((unsigned int)642547343ULL),((unsigned int)4217016738ULL),((unsigned int)3996633073ULL),((unsigned int)2660166606ULL)};
unsigned int a_2[4]={((unsigned int)523316052ULL),((unsigned int)2869569241ULL),((unsigned int)2382176605ULL),((unsigned int)1206756913ULL)};
unsigned int b_2[4]={((unsigned int)523316052ULL),((unsigned int)2869569241ULL),((unsigned int)2382176605ULL),((unsigned int)1206756913ULL)};
unsigned int a_3[4]={((unsigned int)807701831ULL),((unsigned int)3826629170ULL),((unsigned int)517911890ULL),((unsigned int)115565055ULL)};
unsigned int b_3[4]={((unsigned int)807701831ULL),((unsigned int)3826629170ULL),((unsigned int)517911890ULL),((unsigned int)115565055ULL)};
unsigned int a_4[4]={((unsigned int)2873537309ULL),((unsigned int)1565489460ULL),((unsigned int)4230017977ULL),((unsigned int)2984040279ULL)};
unsigned int b_4[4]={((unsigned int)2873537309ULL),((unsigned int)1565489460ULL),((unsigned int)4230017977ULL),((unsigned int)2984040279ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 81\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4123393376ULL),((unsigned int)564851152ULL),((unsigned int)1858529107ULL),((unsigned int)2399044039ULL),((unsigned int)3043433894ULL),((unsigned int)4242918745ULL),((unsigned int)1798594517ULL),((unsigned int)289846682ULL),((unsigned int)3091416746ULL),((unsigned int)3112137677ULL),((unsigned int)3429882769ULL),((unsigned int)2488907437ULL),((unsigned int)3833128683ULL),((unsigned int)3582557336ULL),((unsigned int)2545054905ULL),((unsigned int)615221527ULL)};
unsigned int b_0[16]={((unsigned int)4123393376ULL),((unsigned int)564851152ULL),((unsigned int)1858529107ULL),((unsigned int)2399044039ULL),((unsigned int)3043433894ULL),((unsigned int)4242918745ULL),((unsigned int)1798594517ULL),((unsigned int)289846682ULL),((unsigned int)3091416746ULL),((unsigned int)3112137677ULL),((unsigned int)3429882769ULL),((unsigned int)2488907437ULL),((unsigned int)3833128683ULL),((unsigned int)3582557336ULL),((unsigned int)2545054905ULL),((unsigned int)615221527ULL)};
unsigned int a_1[4]={((unsigned int)155445619ULL),((unsigned int)3828210462ULL),((unsigned int)345616295ULL),((unsigned int)1141679700ULL)};
unsigned int b_1[4]={((unsigned int)155445619ULL),((unsigned int)3828210462ULL),((unsigned int)345616295ULL),((unsigned int)1141679700ULL)};
unsigned int a_2[4]={((unsigned int)2214930258ULL),((unsigned int)2549348134ULL),((unsigned int)3279701093ULL),((unsigned int)1085090034ULL)};
unsigned int b_2[4]={((unsigned int)2214930258ULL),((unsigned int)2549348134ULL),((unsigned int)3279701093ULL),((unsigned int)1085090034ULL)};
unsigned int a_3[4]={((unsigned int)949781203ULL),((unsigned int)2036755117ULL),((unsigned int)3823237766ULL),((unsigned int)73268706ULL)};
unsigned int b_3[4]={((unsigned int)949781203ULL),((unsigned int)2036755117ULL),((unsigned int)3823237766ULL),((unsigned int)73268706ULL)};
unsigned int a_4[4]={((unsigned int)2849752786ULL),((unsigned int)3345875649ULL),((unsigned int)1736897627ULL),((unsigned int)1142964261ULL)};
unsigned int b_4[4]={((unsigned int)2849752786ULL),((unsigned int)3345875649ULL),((unsigned int)1736897627ULL),((unsigned int)1142964261ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 82\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2281859337ULL),((unsigned int)1824430365ULL),((unsigned int)4189200323ULL),((unsigned int)3939290732ULL),((unsigned int)3090237736ULL),((unsigned int)2605055558ULL),((unsigned int)3120994047ULL),((unsigned int)480213035ULL),((unsigned int)990039737ULL),((unsigned int)2629727891ULL),((unsigned int)1170193561ULL),((unsigned int)4026224286ULL),((unsigned int)2171382150ULL),((unsigned int)3784107990ULL),((unsigned int)51687785ULL),((unsigned int)3875737029ULL)};
unsigned int b_0[16]={((unsigned int)2281859337ULL),((unsigned int)1824430365ULL),((unsigned int)4189200323ULL),((unsigned int)3939290732ULL),((unsigned int)3090237736ULL),((unsigned int)2605055558ULL),((unsigned int)3120994047ULL),((unsigned int)480213035ULL),((unsigned int)990039737ULL),((unsigned int)2629727891ULL),((unsigned int)1170193561ULL),((unsigned int)4026224286ULL),((unsigned int)2171382150ULL),((unsigned int)3784107990ULL),((unsigned int)51687785ULL),((unsigned int)3875737029ULL)};
unsigned int a_1[4]={((unsigned int)802120454ULL),((unsigned int)2810587218ULL),((unsigned int)748373276ULL),((unsigned int)1659720070ULL)};
unsigned int b_1[4]={((unsigned int)802120454ULL),((unsigned int)2810587218ULL),((unsigned int)748373276ULL),((unsigned int)1659720070ULL)};
unsigned int a_2[4]={((unsigned int)659038423ULL),((unsigned int)4195343134ULL),((unsigned int)4048180011ULL),((unsigned int)496022790ULL)};
unsigned int b_2[4]={((unsigned int)659038423ULL),((unsigned int)4195343134ULL),((unsigned int)4048180011ULL),((unsigned int)496022790ULL)};
unsigned int a_3[4]={((unsigned int)2936688000ULL),((unsigned int)678703153ULL),((unsigned int)3094948926ULL),((unsigned int)3254787518ULL)};
unsigned int b_3[4]={((unsigned int)2936688000ULL),((unsigned int)678703153ULL),((unsigned int)3094948926ULL),((unsigned int)3254787518ULL)};
unsigned int a_4[4]={((unsigned int)3286674215ULL),((unsigned int)1628522107ULL),((unsigned int)3991546312ULL),((unsigned int)1765571010ULL)};
unsigned int b_4[4]={((unsigned int)3286674215ULL),((unsigned int)1628522107ULL),((unsigned int)3991546312ULL),((unsigned int)1765571010ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 83\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3913880727ULL),((unsigned int)3576860748ULL),((unsigned int)337614753ULL),((unsigned int)3701442885ULL),((unsigned int)3773680721ULL),((unsigned int)1975792403ULL),((unsigned int)3799153112ULL),((unsigned int)2540695453ULL),((unsigned int)2745629600ULL),((unsigned int)2108815212ULL),((unsigned int)3007365180ULL),((unsigned int)1437985758ULL),((unsigned int)946962951ULL),((unsigned int)4146669275ULL),((unsigned int)3191546852ULL),((unsigned int)4194266619ULL)};
unsigned int b_0[16]={((unsigned int)3913880727ULL),((unsigned int)3576860748ULL),((unsigned int)337614753ULL),((unsigned int)3701442885ULL),((unsigned int)3773680721ULL),((unsigned int)1975792403ULL),((unsigned int)3799153112ULL),((unsigned int)2540695453ULL),((unsigned int)2745629600ULL),((unsigned int)2108815212ULL),((unsigned int)3007365180ULL),((unsigned int)1437985758ULL),((unsigned int)946962951ULL),((unsigned int)4146669275ULL),((unsigned int)3191546852ULL),((unsigned int)4194266619ULL)};
unsigned int a_1[4]={((unsigned int)351896424ULL),((unsigned int)4065874817ULL),((unsigned int)2020946055ULL),((unsigned int)4211348540ULL)};
unsigned int b_1[4]={((unsigned int)351896424ULL),((unsigned int)4065874817ULL),((unsigned int)2020946055ULL),((unsigned int)4211348540ULL)};
unsigned int a_2[4]={((unsigned int)215622745ULL),((unsigned int)3608525628ULL),((unsigned int)4042940561ULL),((unsigned int)2584947922ULL)};
unsigned int b_2[4]={((unsigned int)215622745ULL),((unsigned int)3608525628ULL),((unsigned int)4042940561ULL),((unsigned int)2584947922ULL)};
unsigned int a_3[4]={((unsigned int)2656440668ULL),((unsigned int)468122560ULL),((unsigned int)194836045ULL),((unsigned int)4262836124ULL)};
unsigned int b_3[4]={((unsigned int)2656440668ULL),((unsigned int)468122560ULL),((unsigned int)194836045ULL),((unsigned int)4262836124ULL)};
unsigned int a_4[4]={((unsigned int)2195198473ULL),((unsigned int)684299438ULL),((unsigned int)748366693ULL),((unsigned int)2332807ULL)};
unsigned int b_4[4]={((unsigned int)2195198473ULL),((unsigned int)684299438ULL),((unsigned int)748366693ULL),((unsigned int)2332807ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 84\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3742408819ULL),((unsigned int)3938355857ULL),((unsigned int)1057797455ULL),((unsigned int)1091704901ULL),((unsigned int)1202636382ULL),((unsigned int)3386288598ULL),((unsigned int)2317729579ULL),((unsigned int)4175708003ULL),((unsigned int)378910534ULL),((unsigned int)3005168846ULL),((unsigned int)1079977028ULL),((unsigned int)3872970940ULL),((unsigned int)1795964810ULL),((unsigned int)3983741030ULL),((unsigned int)3749480856ULL),((unsigned int)2497079698ULL)};
unsigned int b_0[16]={((unsigned int)3742408819ULL),((unsigned int)3938355857ULL),((unsigned int)1057797455ULL),((unsigned int)1091704901ULL),((unsigned int)1202636382ULL),((unsigned int)3386288598ULL),((unsigned int)2317729579ULL),((unsigned int)4175708003ULL),((unsigned int)378910534ULL),((unsigned int)3005168846ULL),((unsigned int)1079977028ULL),((unsigned int)3872970940ULL),((unsigned int)1795964810ULL),((unsigned int)3983741030ULL),((unsigned int)3749480856ULL),((unsigned int)2497079698ULL)};
unsigned int a_1[4]={((unsigned int)2801867397ULL),((unsigned int)754667758ULL),((unsigned int)2657092143ULL),((unsigned int)3095364997ULL)};
unsigned int b_1[4]={((unsigned int)2801867397ULL),((unsigned int)754667758ULL),((unsigned int)2657092143ULL),((unsigned int)3095364997ULL)};
unsigned int a_2[4]={((unsigned int)3399022751ULL),((unsigned int)2890511308ULL),((unsigned int)2615985629ULL),((unsigned int)432749183ULL)};
unsigned int b_2[4]={((unsigned int)3399022751ULL),((unsigned int)2890511308ULL),((unsigned int)2615985629ULL),((unsigned int)432749183ULL)};
unsigned int a_3[4]={((unsigned int)1891572535ULL),((unsigned int)315519731ULL),((unsigned int)3464439623ULL),((unsigned int)2733660454ULL)};
unsigned int b_3[4]={((unsigned int)1891572535ULL),((unsigned int)315519731ULL),((unsigned int)3464439623ULL),((unsigned int)2733660454ULL)};
unsigned int a_4[4]={((unsigned int)3264497930ULL),((unsigned int)3955862046ULL),((unsigned int)3343067133ULL),((unsigned int)2170286991ULL)};
unsigned int b_4[4]={((unsigned int)3264497930ULL),((unsigned int)3955862046ULL),((unsigned int)3343067133ULL),((unsigned int)2170286991ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 85\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1724565074ULL),((unsigned int)2957495515ULL),((unsigned int)1383917379ULL),((unsigned int)1708751859ULL),((unsigned int)4160839664ULL),((unsigned int)326327521ULL),((unsigned int)995391963ULL),((unsigned int)2429824664ULL),((unsigned int)1884066176ULL),((unsigned int)2761018029ULL),((unsigned int)4083167453ULL),((unsigned int)1155802680ULL),((unsigned int)3146619377ULL),((unsigned int)3736601968ULL),((unsigned int)2796659446ULL),((unsigned int)104339804ULL)};
unsigned int b_0[16]={((unsigned int)1724565074ULL),((unsigned int)2957495515ULL),((unsigned int)1383917379ULL),((unsigned int)1708751859ULL),((unsigned int)4160839664ULL),((unsigned int)326327521ULL),((unsigned int)995391963ULL),((unsigned int)2429824664ULL),((unsigned int)1884066176ULL),((unsigned int)2761018029ULL),((unsigned int)4083167453ULL),((unsigned int)1155802680ULL),((unsigned int)3146619377ULL),((unsigned int)3736601968ULL),((unsigned int)2796659446ULL),((unsigned int)104339804ULL)};
unsigned int a_1[4]={((unsigned int)676242239ULL),((unsigned int)2113320825ULL),((unsigned int)124825116ULL),((unsigned int)3964692195ULL)};
unsigned int b_1[4]={((unsigned int)676242239ULL),((unsigned int)2113320825ULL),((unsigned int)124825116ULL),((unsigned int)3964692195ULL)};
unsigned int a_2[4]={((unsigned int)3797360843ULL),((unsigned int)929007358ULL),((unsigned int)3724437330ULL),((unsigned int)4149386615ULL)};
unsigned int b_2[4]={((unsigned int)3797360843ULL),((unsigned int)929007358ULL),((unsigned int)3724437330ULL),((unsigned int)4149386615ULL)};
unsigned int a_3[4]={((unsigned int)3540552342ULL),((unsigned int)1410286677ULL),((unsigned int)510001209ULL),((unsigned int)1395158622ULL)};
unsigned int b_3[4]={((unsigned int)3540552342ULL),((unsigned int)1410286677ULL),((unsigned int)510001209ULL),((unsigned int)1395158622ULL)};
unsigned int a_4[4]={((unsigned int)2631746992ULL),((unsigned int)1601074625ULL),((unsigned int)1402579852ULL),((unsigned int)3792309539ULL)};
unsigned int b_4[4]={((unsigned int)2631746992ULL),((unsigned int)1601074625ULL),((unsigned int)1402579852ULL),((unsigned int)3792309539ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 86\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1684118335ULL),((unsigned int)3058272302ULL),((unsigned int)543206994ULL),((unsigned int)213404767ULL),((unsigned int)1722521397ULL),((unsigned int)773615717ULL),((unsigned int)537230120ULL),((unsigned int)882313315ULL),((unsigned int)2518424330ULL),((unsigned int)3265125636ULL),((unsigned int)4259213671ULL),((unsigned int)700399169ULL),((unsigned int)459595996ULL),((unsigned int)1268473408ULL),((unsigned int)1702015810ULL),((unsigned int)2942960656ULL)};
unsigned int b_0[16]={((unsigned int)1684118335ULL),((unsigned int)3058272302ULL),((unsigned int)543206994ULL),((unsigned int)213404767ULL),((unsigned int)1722521397ULL),((unsigned int)773615717ULL),((unsigned int)537230120ULL),((unsigned int)882313315ULL),((unsigned int)2518424330ULL),((unsigned int)3265125636ULL),((unsigned int)4259213671ULL),((unsigned int)700399169ULL),((unsigned int)459595996ULL),((unsigned int)1268473408ULL),((unsigned int)1702015810ULL),((unsigned int)2942960656ULL)};
unsigned int a_1[4]={((unsigned int)1580905900ULL),((unsigned int)258735393ULL),((unsigned int)612886334ULL),((unsigned int)468566440ULL)};
unsigned int b_1[4]={((unsigned int)1580905900ULL),((unsigned int)258735393ULL),((unsigned int)612886334ULL),((unsigned int)468566440ULL)};
unsigned int a_2[4]={((unsigned int)3262807837ULL),((unsigned int)1588535777ULL),((unsigned int)2262097652ULL),((unsigned int)3075702148ULL)};
unsigned int b_2[4]={((unsigned int)3262807837ULL),((unsigned int)1588535777ULL),((unsigned int)2262097652ULL),((unsigned int)3075702148ULL)};
unsigned int a_3[4]={((unsigned int)3545215167ULL),((unsigned int)669225456ULL),((unsigned int)1936486329ULL),((unsigned int)3648169854ULL)};
unsigned int b_3[4]={((unsigned int)3545215167ULL),((unsigned int)669225456ULL),((unsigned int)1936486329ULL),((unsigned int)3648169854ULL)};
unsigned int a_4[4]={((unsigned int)2925945658ULL),((unsigned int)4280067910ULL),((unsigned int)1751593318ULL),((unsigned int)738313332ULL)};
unsigned int b_4[4]={((unsigned int)2925945658ULL),((unsigned int)4280067910ULL),((unsigned int)1751593318ULL),((unsigned int)738313332ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 87\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2474526627ULL),((unsigned int)262851453ULL),((unsigned int)2548238569ULL),((unsigned int)447511628ULL),((unsigned int)572231354ULL),((unsigned int)300491561ULL),((unsigned int)330613709ULL),((unsigned int)2294024062ULL),((unsigned int)1685974440ULL),((unsigned int)2117730066ULL),((unsigned int)2547779968ULL),((unsigned int)780308329ULL),((unsigned int)3745888178ULL),((unsigned int)1236472876ULL),((unsigned int)3119475024ULL),((unsigned int)402794858ULL)};
unsigned int b_0[16]={((unsigned int)2474526627ULL),((unsigned int)262851453ULL),((unsigned int)2548238569ULL),((unsigned int)447511628ULL),((unsigned int)572231354ULL),((unsigned int)300491561ULL),((unsigned int)330613709ULL),((unsigned int)2294024062ULL),((unsigned int)1685974440ULL),((unsigned int)2117730066ULL),((unsigned int)2547779968ULL),((unsigned int)780308329ULL),((unsigned int)3745888178ULL),((unsigned int)1236472876ULL),((unsigned int)3119475024ULL),((unsigned int)402794858ULL)};
unsigned int a_1[4]={((unsigned int)784684429ULL),((unsigned int)1849798100ULL),((unsigned int)2374593214ULL),((unsigned int)4015476597ULL)};
unsigned int b_1[4]={((unsigned int)784684429ULL),((unsigned int)1849798100ULL),((unsigned int)2374593214ULL),((unsigned int)4015476597ULL)};
unsigned int a_2[4]={((unsigned int)1272971878ULL),((unsigned int)4242293628ULL),((unsigned int)1744668468ULL),((unsigned int)3755168803ULL)};
unsigned int b_2[4]={((unsigned int)1272971878ULL),((unsigned int)4242293628ULL),((unsigned int)1744668468ULL),((unsigned int)3755168803ULL)};
unsigned int a_3[4]={((unsigned int)2951001455ULL),((unsigned int)2288553598ULL),((unsigned int)4277546942ULL),((unsigned int)3747245462ULL)};
unsigned int b_3[4]={((unsigned int)2951001455ULL),((unsigned int)2288553598ULL),((unsigned int)4277546942ULL),((unsigned int)3747245462ULL)};
unsigned int a_4[4]={((unsigned int)3750887482ULL),((unsigned int)1433985034ULL),((unsigned int)4051492172ULL),((unsigned int)2862539528ULL)};
unsigned int b_4[4]={((unsigned int)3750887482ULL),((unsigned int)1433985034ULL),((unsigned int)4051492172ULL),((unsigned int)2862539528ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 88\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)431176858ULL),((unsigned int)1890748617ULL),((unsigned int)1965485045ULL),((unsigned int)2112550059ULL),((unsigned int)301882259ULL),((unsigned int)3705558421ULL),((unsigned int)4286396352ULL),((unsigned int)2519329746ULL),((unsigned int)898814956ULL),((unsigned int)1642588694ULL),((unsigned int)2574023287ULL),((unsigned int)1689472436ULL),((unsigned int)3818040744ULL),((unsigned int)213922176ULL),((unsigned int)693078075ULL),((unsigned int)4000662801ULL)};
unsigned int b_0[16]={((unsigned int)431176858ULL),((unsigned int)1890748617ULL),((unsigned int)1965485045ULL),((unsigned int)2112550059ULL),((unsigned int)301882259ULL),((unsigned int)3705558421ULL),((unsigned int)4286396352ULL),((unsigned int)2519329746ULL),((unsigned int)898814956ULL),((unsigned int)1642588694ULL),((unsigned int)2574023287ULL),((unsigned int)1689472436ULL),((unsigned int)3818040744ULL),((unsigned int)213922176ULL),((unsigned int)693078075ULL),((unsigned int)4000662801ULL)};
unsigned int a_1[4]={((unsigned int)1588621251ULL),((unsigned int)3226763491ULL),((unsigned int)3544655750ULL),((unsigned int)3584210365ULL)};
unsigned int b_1[4]={((unsigned int)1588621251ULL),((unsigned int)3226763491ULL),((unsigned int)3544655750ULL),((unsigned int)3584210365ULL)};
unsigned int a_2[4]={((unsigned int)3627438094ULL),((unsigned int)1261058990ULL),((unsigned int)63195646ULL),((unsigned int)3809994642ULL)};
unsigned int b_2[4]={((unsigned int)3627438094ULL),((unsigned int)1261058990ULL),((unsigned int)63195646ULL),((unsigned int)3809994642ULL)};
unsigned int a_3[4]={((unsigned int)1287734106ULL),((unsigned int)2911024126ULL),((unsigned int)1932687911ULL),((unsigned int)599287487ULL)};
unsigned int b_3[4]={((unsigned int)1287734106ULL),((unsigned int)2911024126ULL),((unsigned int)1932687911ULL),((unsigned int)599287487ULL)};
unsigned int a_4[4]={((unsigned int)3043220002ULL),((unsigned int)408695889ULL),((unsigned int)3179061828ULL),((unsigned int)506598210ULL)};
unsigned int b_4[4]={((unsigned int)3043220002ULL),((unsigned int)408695889ULL),((unsigned int)3179061828ULL),((unsigned int)506598210ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 89\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1243517356ULL),((unsigned int)2190009245ULL),((unsigned int)1125477201ULL),((unsigned int)1960538486ULL),((unsigned int)1740155631ULL),((unsigned int)3171091086ULL),((unsigned int)3259673652ULL),((unsigned int)2347994483ULL),((unsigned int)2435045206ULL),((unsigned int)2717094369ULL),((unsigned int)335360272ULL),((unsigned int)4017608298ULL),((unsigned int)437222550ULL),((unsigned int)3358921032ULL),((unsigned int)1133670103ULL),((unsigned int)1556326903ULL)};
unsigned int b_0[16]={((unsigned int)1243517356ULL),((unsigned int)2190009245ULL),((unsigned int)1125477201ULL),((unsigned int)1960538486ULL),((unsigned int)1740155631ULL),((unsigned int)3171091086ULL),((unsigned int)3259673652ULL),((unsigned int)2347994483ULL),((unsigned int)2435045206ULL),((unsigned int)2717094369ULL),((unsigned int)335360272ULL),((unsigned int)4017608298ULL),((unsigned int)437222550ULL),((unsigned int)3358921032ULL),((unsigned int)1133670103ULL),((unsigned int)1556326903ULL)};
unsigned int a_1[4]={((unsigned int)2632882952ULL),((unsigned int)4172017422ULL),((unsigned int)1585991153ULL),((unsigned int)4023581535ULL)};
unsigned int b_1[4]={((unsigned int)2632882952ULL),((unsigned int)4172017422ULL),((unsigned int)1585991153ULL),((unsigned int)4023581535ULL)};
unsigned int a_2[4]={((unsigned int)4077200322ULL),((unsigned int)1240817946ULL),((unsigned int)3800095031ULL),((unsigned int)3118173898ULL)};
unsigned int b_2[4]={((unsigned int)4077200322ULL),((unsigned int)1240817946ULL),((unsigned int)3800095031ULL),((unsigned int)3118173898ULL)};
unsigned int a_3[4]={((unsigned int)4211747934ULL),((unsigned int)1290745359ULL),((unsigned int)2964740991ULL),((unsigned int)475871486ULL)};
unsigned int b_3[4]={((unsigned int)4211747934ULL),((unsigned int)1290745359ULL),((unsigned int)2964740991ULL),((unsigned int)475871486ULL)};
unsigned int a_4[4]={((unsigned int)29009696ULL),((unsigned int)1680905487ULL),((unsigned int)3057852337ULL),((unsigned int)1137413091ULL)};
unsigned int b_4[4]={((unsigned int)29009696ULL),((unsigned int)1680905487ULL),((unsigned int)3057852337ULL),((unsigned int)1137413091ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 90\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2636635166ULL),((unsigned int)2806236509ULL),((unsigned int)1186677426ULL),((unsigned int)757757682ULL),((unsigned int)4177952387ULL),((unsigned int)4007627709ULL),((unsigned int)1292955785ULL),((unsigned int)1656996342ULL),((unsigned int)3156108142ULL),((unsigned int)1321043022ULL),((unsigned int)3317524978ULL),((unsigned int)772521689ULL),((unsigned int)3599768486ULL),((unsigned int)1602577254ULL),((unsigned int)3605121862ULL),((unsigned int)1151625151ULL)};
unsigned int b_0[16]={((unsigned int)2636635166ULL),((unsigned int)2806236509ULL),((unsigned int)1186677426ULL),((unsigned int)757757682ULL),((unsigned int)4177952387ULL),((unsigned int)4007627709ULL),((unsigned int)1292955785ULL),((unsigned int)1656996342ULL),((unsigned int)3156108142ULL),((unsigned int)1321043022ULL),((unsigned int)3317524978ULL),((unsigned int)772521689ULL),((unsigned int)3599768486ULL),((unsigned int)1602577254ULL),((unsigned int)3605121862ULL),((unsigned int)1151625151ULL)};
unsigned int a_1[4]={((unsigned int)3880597243ULL),((unsigned int)3109772251ULL),((unsigned int)2202735738ULL),((unsigned int)3187736346ULL)};
unsigned int b_1[4]={((unsigned int)3880597243ULL),((unsigned int)3109772251ULL),((unsigned int)2202735738ULL),((unsigned int)3187736346ULL)};
unsigned int a_2[4]={((unsigned int)2253507501ULL),((unsigned int)891724357ULL),((unsigned int)692948681ULL),((unsigned int)2738986789ULL)};
unsigned int b_2[4]={((unsigned int)2253507501ULL),((unsigned int)891724357ULL),((unsigned int)692948681ULL),((unsigned int)2738986789ULL)};
unsigned int a_3[4]={((unsigned int)3139258437ULL),((unsigned int)2648046478ULL),((unsigned int)588886154ULL),((unsigned int)3116323780ULL)};
unsigned int b_3[4]={((unsigned int)3139258437ULL),((unsigned int)2648046478ULL),((unsigned int)588886154ULL),((unsigned int)3116323780ULL)};
unsigned int a_4[4]={((unsigned int)1760063300ULL),((unsigned int)1418225765ULL),((unsigned int)379521828ULL),((unsigned int)1863274952ULL)};
unsigned int b_4[4]={((unsigned int)1760063300ULL),((unsigned int)1418225765ULL),((unsigned int)379521828ULL),((unsigned int)1863274952ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 91\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2797672109ULL),((unsigned int)779773717ULL),((unsigned int)1602859859ULL),((unsigned int)4211969302ULL),((unsigned int)1835702048ULL),((unsigned int)3672915204ULL),((unsigned int)1030741911ULL),((unsigned int)1157371362ULL),((unsigned int)609794628ULL),((unsigned int)3829201389ULL),((unsigned int)1740071301ULL),((unsigned int)3730589715ULL),((unsigned int)3680169003ULL),((unsigned int)1742857549ULL),((unsigned int)1580999455ULL),((unsigned int)871521016ULL)};
unsigned int b_0[16]={((unsigned int)2797672109ULL),((unsigned int)779773717ULL),((unsigned int)1602859859ULL),((unsigned int)4211969302ULL),((unsigned int)1835702048ULL),((unsigned int)3672915204ULL),((unsigned int)1030741911ULL),((unsigned int)1157371362ULL),((unsigned int)609794628ULL),((unsigned int)3829201389ULL),((unsigned int)1740071301ULL),((unsigned int)3730589715ULL),((unsigned int)3680169003ULL),((unsigned int)1742857549ULL),((unsigned int)1580999455ULL),((unsigned int)871521016ULL)};
unsigned int a_1[4]={((unsigned int)3784644992ULL),((unsigned int)3958072076ULL),((unsigned int)3944472430ULL),((unsigned int)1206524322ULL)};
unsigned int b_1[4]={((unsigned int)3784644992ULL),((unsigned int)3958072076ULL),((unsigned int)3944472430ULL),((unsigned int)1206524322ULL)};
unsigned int a_2[4]={((unsigned int)1139783847ULL),((unsigned int)3671641333ULL),((unsigned int)2268667963ULL),((unsigned int)3627070787ULL)};
unsigned int b_2[4]={((unsigned int)1139783847ULL),((unsigned int)3671641333ULL),((unsigned int)2268667963ULL),((unsigned int)3627070787ULL)};
unsigned int a_3[4]={((unsigned int)1835196545ULL),((unsigned int)3644088932ULL),((unsigned int)606159489ULL),((unsigned int)2425189496ULL)};
unsigned int b_3[4]={((unsigned int)1835196545ULL),((unsigned int)3644088932ULL),((unsigned int)606159489ULL),((unsigned int)2425189496ULL)};
unsigned int a_4[4]={((unsigned int)464657253ULL),((unsigned int)3923330844ULL),((unsigned int)3883323310ULL),((unsigned int)4279791748ULL)};
unsigned int b_4[4]={((unsigned int)464657253ULL),((unsigned int)3923330844ULL),((unsigned int)3883323310ULL),((unsigned int)4279791748ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 92\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2542872915ULL),((unsigned int)2094324303ULL),((unsigned int)3665708471ULL),((unsigned int)4157994864ULL),((unsigned int)2886208887ULL),((unsigned int)2433323086ULL),((unsigned int)2344227751ULL),((unsigned int)3540671656ULL),((unsigned int)1593009067ULL),((unsigned int)3639815170ULL),((unsigned int)2536417493ULL),((unsigned int)940453790ULL),((unsigned int)2335207368ULL),((unsigned int)2015129002ULL),((unsigned int)2570343033ULL),((unsigned int)1456165987ULL)};
unsigned int b_0[16]={((unsigned int)2542872915ULL),((unsigned int)2094324303ULL),((unsigned int)3665708471ULL),((unsigned int)4157994864ULL),((unsigned int)2886208887ULL),((unsigned int)2433323086ULL),((unsigned int)2344227751ULL),((unsigned int)3540671656ULL),((unsigned int)1593009067ULL),((unsigned int)3639815170ULL),((unsigned int)2536417493ULL),((unsigned int)940453790ULL),((unsigned int)2335207368ULL),((unsigned int)2015129002ULL),((unsigned int)2570343033ULL),((unsigned int)1456165987ULL)};
unsigned int a_1[4]={((unsigned int)3679194767ULL),((unsigned int)869778994ULL),((unsigned int)2039106008ULL),((unsigned int)3279054353ULL)};
unsigned int b_1[4]={((unsigned int)3679194767ULL),((unsigned int)869778994ULL),((unsigned int)2039106008ULL),((unsigned int)3279054353ULL)};
unsigned int a_2[4]={((unsigned int)3982578913ULL),((unsigned int)3837543413ULL),((unsigned int)846217773ULL),((unsigned int)3330910769ULL)};
unsigned int b_2[4]={((unsigned int)3982578913ULL),((unsigned int)3837543413ULL),((unsigned int)846217773ULL),((unsigned int)3330910769ULL)};
unsigned int a_3[4]={((unsigned int)1494894691ULL),((unsigned int)508350787ULL),((unsigned int)62993247ULL),((unsigned int)2355369998ULL)};
unsigned int b_3[4]={((unsigned int)1494894691ULL),((unsigned int)508350787ULL),((unsigned int)62993247ULL),((unsigned int)2355369998ULL)};
unsigned int a_4[4]={((unsigned int)3966796263ULL),((unsigned int)1119477129ULL),((unsigned int)3620941446ULL),((unsigned int)1978911639ULL)};
unsigned int b_4[4]={((unsigned int)3966796263ULL),((unsigned int)1119477129ULL),((unsigned int)3620941446ULL),((unsigned int)1978911639ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 93\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2085859720ULL),((unsigned int)965889072ULL),((unsigned int)2815301856ULL),((unsigned int)3097205257ULL),((unsigned int)3401132401ULL),((unsigned int)1927191573ULL),((unsigned int)4118837585ULL),((unsigned int)723539067ULL),((unsigned int)556615333ULL),((unsigned int)526975637ULL),((unsigned int)3373695883ULL),((unsigned int)2089602722ULL),((unsigned int)794158313ULL),((unsigned int)1020440181ULL),((unsigned int)3574628939ULL),((unsigned int)1811924614ULL)};
unsigned int b_0[16]={((unsigned int)2085859720ULL),((unsigned int)965889072ULL),((unsigned int)2815301856ULL),((unsigned int)3097205257ULL),((unsigned int)3401132401ULL),((unsigned int)1927191573ULL),((unsigned int)4118837585ULL),((unsigned int)723539067ULL),((unsigned int)556615333ULL),((unsigned int)526975637ULL),((unsigned int)3373695883ULL),((unsigned int)2089602722ULL),((unsigned int)794158313ULL),((unsigned int)1020440181ULL),((unsigned int)3574628939ULL),((unsigned int)1811924614ULL)};
unsigned int a_1[4]={((unsigned int)2123058245ULL),((unsigned int)858076221ULL),((unsigned int)2629908353ULL),((unsigned int)421911697ULL)};
unsigned int b_1[4]={((unsigned int)2123058245ULL),((unsigned int)858076221ULL),((unsigned int)2629908353ULL),((unsigned int)421911697ULL)};
unsigned int a_2[4]={((unsigned int)3907431521ULL),((unsigned int)3728095466ULL),((unsigned int)2175451711ULL),((unsigned int)3503184280ULL)};
unsigned int b_2[4]={((unsigned int)3907431521ULL),((unsigned int)3728095466ULL),((unsigned int)2175451711ULL),((unsigned int)3503184280ULL)};
unsigned int a_3[4]={((unsigned int)3730291192ULL),((unsigned int)7590086ULL),((unsigned int)2727776443ULL),((unsigned int)927122651ULL)};
unsigned int b_3[4]={((unsigned int)3730291192ULL),((unsigned int)7590086ULL),((unsigned int)2727776443ULL),((unsigned int)927122651ULL)};
unsigned int a_4[4]={((unsigned int)3308777306ULL),((unsigned int)265548907ULL),((unsigned int)1465404177ULL),((unsigned int)1493592427ULL)};
unsigned int b_4[4]={((unsigned int)3308777306ULL),((unsigned int)265548907ULL),((unsigned int)1465404177ULL),((unsigned int)1493592427ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 94\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4246036887ULL),((unsigned int)593509624ULL),((unsigned int)281884970ULL),((unsigned int)2747767159ULL),((unsigned int)1574436254ULL),((unsigned int)1274302712ULL),((unsigned int)1034157711ULL),((unsigned int)3837297765ULL),((unsigned int)3722445606ULL),((unsigned int)1680425399ULL),((unsigned int)1683311251ULL),((unsigned int)1153581253ULL),((unsigned int)3223253086ULL),((unsigned int)1821203576ULL),((unsigned int)64583716ULL),((unsigned int)735702638ULL)};
unsigned int b_0[16]={((unsigned int)4246036887ULL),((unsigned int)593509624ULL),((unsigned int)281884970ULL),((unsigned int)2747767159ULL),((unsigned int)1574436254ULL),((unsigned int)1274302712ULL),((unsigned int)1034157711ULL),((unsigned int)3837297765ULL),((unsigned int)3722445606ULL),((unsigned int)1680425399ULL),((unsigned int)1683311251ULL),((unsigned int)1153581253ULL),((unsigned int)3223253086ULL),((unsigned int)1821203576ULL),((unsigned int)64583716ULL),((unsigned int)735702638ULL)};
unsigned int a_1[4]={((unsigned int)1742405068ULL),((unsigned int)201401651ULL),((unsigned int)3912010880ULL),((unsigned int)2096502466ULL)};
unsigned int b_1[4]={((unsigned int)1742405068ULL),((unsigned int)201401651ULL),((unsigned int)3912010880ULL),((unsigned int)2096502466ULL)};
unsigned int a_2[4]={((unsigned int)1429331395ULL),((unsigned int)3724938265ULL),((unsigned int)2847124794ULL),((unsigned int)2198573449ULL)};
unsigned int b_2[4]={((unsigned int)1429331395ULL),((unsigned int)3724938265ULL),((unsigned int)2847124794ULL),((unsigned int)2198573449ULL)};
unsigned int a_3[4]={((unsigned int)2801201946ULL),((unsigned int)3263573985ULL),((unsigned int)2319329572ULL),((unsigned int)3870629569ULL)};
unsigned int b_3[4]={((unsigned int)2801201946ULL),((unsigned int)3263573985ULL),((unsigned int)2319329572ULL),((unsigned int)3870629569ULL)};
unsigned int a_4[4]={((unsigned int)2877107506ULL),((unsigned int)2411673498ULL),((unsigned int)656347396ULL),((unsigned int)3971800268ULL)};
unsigned int b_4[4]={((unsigned int)2877107506ULL),((unsigned int)2411673498ULL),((unsigned int)656347396ULL),((unsigned int)3971800268ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 95\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3158974276ULL),((unsigned int)2103706722ULL),((unsigned int)1789232179ULL),((unsigned int)3212092698ULL),((unsigned int)1709146088ULL),((unsigned int)850836215ULL),((unsigned int)1219916206ULL),((unsigned int)764466416ULL),((unsigned int)442226388ULL),((unsigned int)3303063279ULL),((unsigned int)670156957ULL),((unsigned int)2797538486ULL),((unsigned int)1908296645ULL),((unsigned int)2265954390ULL),((unsigned int)706161577ULL),((unsigned int)2416985387ULL)};
unsigned int b_0[16]={((unsigned int)3158974276ULL),((unsigned int)2103706722ULL),((unsigned int)1789232179ULL),((unsigned int)3212092698ULL),((unsigned int)1709146088ULL),((unsigned int)850836215ULL),((unsigned int)1219916206ULL),((unsigned int)764466416ULL),((unsigned int)442226388ULL),((unsigned int)3303063279ULL),((unsigned int)670156957ULL),((unsigned int)2797538486ULL),((unsigned int)1908296645ULL),((unsigned int)2265954390ULL),((unsigned int)706161577ULL),((unsigned int)2416985387ULL)};
unsigned int a_1[4]={((unsigned int)3545683585ULL),((unsigned int)2290751118ULL),((unsigned int)542522564ULL),((unsigned int)85930070ULL)};
unsigned int b_1[4]={((unsigned int)3545683585ULL),((unsigned int)2290751118ULL),((unsigned int)542522564ULL),((unsigned int)85930070ULL)};
unsigned int a_2[4]={((unsigned int)3805221284ULL),((unsigned int)657659562ULL),((unsigned int)2399780110ULL),((unsigned int)424349554ULL)};
unsigned int b_2[4]={((unsigned int)3805221284ULL),((unsigned int)657659562ULL),((unsigned int)2399780110ULL),((unsigned int)424349554ULL)};
unsigned int a_3[4]={((unsigned int)3883741605ULL),((unsigned int)2039941663ULL),((unsigned int)2369065045ULL),((unsigned int)3101394222ULL)};
unsigned int b_3[4]={((unsigned int)3883741605ULL),((unsigned int)2039941663ULL),((unsigned int)2369065045ULL),((unsigned int)3101394222ULL)};
unsigned int a_4[4]={((unsigned int)1704508834ULL),((unsigned int)4011865835ULL),((unsigned int)3645813462ULL),((unsigned int)3308876348ULL)};
unsigned int b_4[4]={((unsigned int)1704508834ULL),((unsigned int)4011865835ULL),((unsigned int)3645813462ULL),((unsigned int)3308876348ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 96\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)835089805ULL),((unsigned int)2551828778ULL),((unsigned int)1016985438ULL),((unsigned int)3596699517ULL),((unsigned int)1890580079ULL),((unsigned int)1079252545ULL),((unsigned int)4134326243ULL),((unsigned int)978123224ULL),((unsigned int)3047422014ULL),((unsigned int)1893167066ULL),((unsigned int)1359009622ULL),((unsigned int)2645468717ULL),((unsigned int)428883614ULL),((unsigned int)3462920155ULL),((unsigned int)1560031347ULL),((unsigned int)482754135ULL)};
unsigned int b_0[16]={((unsigned int)835089805ULL),((unsigned int)2551828778ULL),((unsigned int)1016985438ULL),((unsigned int)3596699517ULL),((unsigned int)1890580079ULL),((unsigned int)1079252545ULL),((unsigned int)4134326243ULL),((unsigned int)978123224ULL),((unsigned int)3047422014ULL),((unsigned int)1893167066ULL),((unsigned int)1359009622ULL),((unsigned int)2645468717ULL),((unsigned int)428883614ULL),((unsigned int)3462920155ULL),((unsigned int)1560031347ULL),((unsigned int)482754135ULL)};
unsigned int a_1[4]={((unsigned int)3437062777ULL),((unsigned int)191608062ULL),((unsigned int)3823798674ULL),((unsigned int)2092894526ULL)};
unsigned int b_1[4]={((unsigned int)3437062777ULL),((unsigned int)191608062ULL),((unsigned int)3823798674ULL),((unsigned int)2092894526ULL)};
unsigned int a_2[4]={((unsigned int)1616155470ULL),((unsigned int)1704503069ULL),((unsigned int)2965817963ULL),((unsigned int)2176919840ULL)};
unsigned int b_2[4]={((unsigned int)1616155470ULL),((unsigned int)1704503069ULL),((unsigned int)2965817963ULL),((unsigned int)2176919840ULL)};
unsigned int a_3[4]={((unsigned int)4129088993ULL),((unsigned int)2139902817ULL),((unsigned int)831494526ULL),((unsigned int)2905803302ULL)};
unsigned int b_3[4]={((unsigned int)4129088993ULL),((unsigned int)2139902817ULL),((unsigned int)831494526ULL),((unsigned int)2905803302ULL)};
unsigned int a_4[4]={((unsigned int)1795299994ULL),((unsigned int)3523963187ULL),((unsigned int)3360600420ULL),((unsigned int)1245765880ULL)};
unsigned int b_4[4]={((unsigned int)1795299994ULL),((unsigned int)3523963187ULL),((unsigned int)3360600420ULL),((unsigned int)1245765880ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 97\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3629206971ULL),((unsigned int)1596556906ULL),((unsigned int)1019941607ULL),((unsigned int)2772997629ULL),((unsigned int)3301469139ULL),((unsigned int)758143560ULL),((unsigned int)2418007553ULL),((unsigned int)2060614733ULL),((unsigned int)459533367ULL),((unsigned int)2216373724ULL),((unsigned int)3097462846ULL),((unsigned int)410698394ULL),((unsigned int)2491753517ULL),((unsigned int)2887458601ULL),((unsigned int)436631244ULL),((unsigned int)2150023446ULL)};
unsigned int b_0[16]={((unsigned int)3629206971ULL),((unsigned int)1596556906ULL),((unsigned int)1019941607ULL),((unsigned int)2772997629ULL),((unsigned int)3301469139ULL),((unsigned int)758143560ULL),((unsigned int)2418007553ULL),((unsigned int)2060614733ULL),((unsigned int)459533367ULL),((unsigned int)2216373724ULL),((unsigned int)3097462846ULL),((unsigned int)410698394ULL),((unsigned int)2491753517ULL),((unsigned int)2887458601ULL),((unsigned int)436631244ULL),((unsigned int)2150023446ULL)};
unsigned int a_1[4]={((unsigned int)1177410384ULL),((unsigned int)556578605ULL),((unsigned int)1348975256ULL),((unsigned int)3978541090ULL)};
unsigned int b_1[4]={((unsigned int)1177410384ULL),((unsigned int)556578605ULL),((unsigned int)1348975256ULL),((unsigned int)3978541090ULL)};
unsigned int a_2[4]={((unsigned int)3782018585ULL),((unsigned int)3958361059ULL),((unsigned int)1999675306ULL),((unsigned int)2308898645ULL)};
unsigned int b_2[4]={((unsigned int)3782018585ULL),((unsigned int)3958361059ULL),((unsigned int)1999675306ULL),((unsigned int)2308898645ULL)};
unsigned int a_3[4]={((unsigned int)2513194214ULL),((unsigned int)2545933213ULL),((unsigned int)2755170779ULL),((unsigned int)615357023ULL)};
unsigned int b_3[4]={((unsigned int)2513194214ULL),((unsigned int)2545933213ULL),((unsigned int)2755170779ULL),((unsigned int)615357023ULL)};
unsigned int a_4[4]={((unsigned int)639590737ULL),((unsigned int)4033747742ULL),((unsigned int)2146913583ULL),((unsigned int)680955252ULL)};
unsigned int b_4[4]={((unsigned int)639590737ULL),((unsigned int)4033747742ULL),((unsigned int)2146913583ULL),((unsigned int)680955252ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 98\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1341525148ULL),((unsigned int)662030415ULL),((unsigned int)4118835589ULL),((unsigned int)52899305ULL),((unsigned int)2908399433ULL),((unsigned int)2924461216ULL),((unsigned int)4160721784ULL),((unsigned int)1230739976ULL),((unsigned int)2054156843ULL),((unsigned int)2502960155ULL),((unsigned int)2433322161ULL),((unsigned int)700200479ULL),((unsigned int)2928232544ULL),((unsigned int)218044370ULL),((unsigned int)4274687508ULL),((unsigned int)3809876154ULL)};
unsigned int b_0[16]={((unsigned int)1341525148ULL),((unsigned int)662030415ULL),((unsigned int)4118835589ULL),((unsigned int)52899305ULL),((unsigned int)2908399433ULL),((unsigned int)2924461216ULL),((unsigned int)4160721784ULL),((unsigned int)1230739976ULL),((unsigned int)2054156843ULL),((unsigned int)2502960155ULL),((unsigned int)2433322161ULL),((unsigned int)700200479ULL),((unsigned int)2928232544ULL),((unsigned int)218044370ULL),((unsigned int)4274687508ULL),((unsigned int)3809876154ULL)};
unsigned int a_1[4]={((unsigned int)1882852203ULL),((unsigned int)851606466ULL),((unsigned int)4110627811ULL),((unsigned int)781710080ULL)};
unsigned int b_1[4]={((unsigned int)1882852203ULL),((unsigned int)851606466ULL),((unsigned int)4110627811ULL),((unsigned int)781710080ULL)};
unsigned int a_2[4]={((unsigned int)1502440410ULL),((unsigned int)1871052229ULL),((unsigned int)940513187ULL),((unsigned int)1284465171ULL)};
unsigned int b_2[4]={((unsigned int)1502440410ULL),((unsigned int)1871052229ULL),((unsigned int)940513187ULL),((unsigned int)1284465171ULL)};
unsigned int a_3[4]={((unsigned int)4186969648ULL),((unsigned int)4166371370ULL),((unsigned int)3648059981ULL),((unsigned int)513762655ULL)};
unsigned int b_3[4]={((unsigned int)4186969648ULL),((unsigned int)4166371370ULL),((unsigned int)3648059981ULL),((unsigned int)513762655ULL)};
unsigned int a_4[4]={((unsigned int)1544010284ULL),((unsigned int)3237387521ULL),((unsigned int)3064095865ULL),((unsigned int)1176585710ULL)};
unsigned int b_4[4]={((unsigned int)1544010284ULL),((unsigned int)3237387521ULL),((unsigned int)3064095865ULL),((unsigned int)1176585710ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 99\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)897955643ULL),((unsigned int)3062482071ULL),((unsigned int)574011455ULL),((unsigned int)3308514084ULL),((unsigned int)258611357ULL),((unsigned int)3431614671ULL),((unsigned int)2370715146ULL),((unsigned int)794539945ULL),((unsigned int)2239371718ULL),((unsigned int)3654612537ULL),((unsigned int)2291038377ULL),((unsigned int)166027905ULL),((unsigned int)3671584402ULL),((unsigned int)1117069366ULL),((unsigned int)3586439809ULL),((unsigned int)779651329ULL)};
unsigned int b_0[16]={((unsigned int)897955643ULL),((unsigned int)3062482071ULL),((unsigned int)574011455ULL),((unsigned int)3308514084ULL),((unsigned int)258611357ULL),((unsigned int)3431614671ULL),((unsigned int)2370715146ULL),((unsigned int)794539945ULL),((unsigned int)2239371718ULL),((unsigned int)3654612537ULL),((unsigned int)2291038377ULL),((unsigned int)166027905ULL),((unsigned int)3671584402ULL),((unsigned int)1117069366ULL),((unsigned int)3586439809ULL),((unsigned int)779651329ULL)};
unsigned int a_1[4]={((unsigned int)1744181366ULL),((unsigned int)2579788690ULL),((unsigned int)2949971828ULL),((unsigned int)3035181316ULL)};
unsigned int b_1[4]={((unsigned int)1744181366ULL),((unsigned int)2579788690ULL),((unsigned int)2949971828ULL),((unsigned int)3035181316ULL)};
unsigned int a_2[4]={((unsigned int)1334589195ULL),((unsigned int)3821540053ULL),((unsigned int)465648189ULL),((unsigned int)3878194638ULL)};
unsigned int b_2[4]={((unsigned int)1334589195ULL),((unsigned int)3821540053ULL),((unsigned int)465648189ULL),((unsigned int)3878194638ULL)};
unsigned int a_3[4]={((unsigned int)228465134ULL),((unsigned int)3027534700ULL),((unsigned int)357676692ULL),((unsigned int)2237841805ULL)};
unsigned int b_3[4]={((unsigned int)228465134ULL),((unsigned int)3027534700ULL),((unsigned int)357676692ULL),((unsigned int)2237841805ULL)};
unsigned int a_4[4]={((unsigned int)3665149937ULL),((unsigned int)2392092013ULL),((unsigned int)2014438333ULL),((unsigned int)3225362203ULL)};
unsigned int b_4[4]={((unsigned int)3665149937ULL),((unsigned int)2392092013ULL),((unsigned int)2014438333ULL),((unsigned int)3225362203ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 100\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3480689996ULL),((unsigned int)1865693510ULL),((unsigned int)3999558702ULL),((unsigned int)3175427225ULL),((unsigned int)1081290014ULL),((unsigned int)1215822419ULL),((unsigned int)1466400433ULL),((unsigned int)895957822ULL),((unsigned int)2231008106ULL),((unsigned int)3162221687ULL),((unsigned int)1115030826ULL),((unsigned int)2151190512ULL),((unsigned int)558788779ULL),((unsigned int)1455554011ULL),((unsigned int)162214581ULL),((unsigned int)436791136ULL)};
unsigned int b_0[16]={((unsigned int)3480689996ULL),((unsigned int)1865693510ULL),((unsigned int)3999558702ULL),((unsigned int)3175427225ULL),((unsigned int)1081290014ULL),((unsigned int)1215822419ULL),((unsigned int)1466400433ULL),((unsigned int)895957822ULL),((unsigned int)2231008106ULL),((unsigned int)3162221687ULL),((unsigned int)1115030826ULL),((unsigned int)2151190512ULL),((unsigned int)558788779ULL),((unsigned int)1455554011ULL),((unsigned int)162214581ULL),((unsigned int)436791136ULL)};
unsigned int a_1[4]={((unsigned int)2925790724ULL),((unsigned int)3644012513ULL),((unsigned int)2269659112ULL),((unsigned int)52624871ULL)};
unsigned int b_1[4]={((unsigned int)2925790724ULL),((unsigned int)3644012513ULL),((unsigned int)2269659112ULL),((unsigned int)52624871ULL)};
unsigned int a_2[4]={((unsigned int)4051206545ULL),((unsigned int)3880332138ULL),((unsigned int)463187099ULL),((unsigned int)1595801171ULL)};
unsigned int b_2[4]={((unsigned int)4051206545ULL),((unsigned int)3880332138ULL),((unsigned int)463187099ULL),((unsigned int)1595801171ULL)};
unsigned int a_3[4]={((unsigned int)4090154254ULL),((unsigned int)245740352ULL),((unsigned int)2622132552ULL),((unsigned int)4052681955ULL)};
unsigned int b_3[4]={((unsigned int)4090154254ULL),((unsigned int)245740352ULL),((unsigned int)2622132552ULL),((unsigned int)4052681955ULL)};
unsigned int a_4[4]={((unsigned int)3216750029ULL),((unsigned int)3625238871ULL),((unsigned int)611966317ULL),((unsigned int)2368525907ULL)};
unsigned int b_4[4]={((unsigned int)3216750029ULL),((unsigned int)3625238871ULL),((unsigned int)611966317ULL),((unsigned int)2368525907ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 101\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)132849301ULL),((unsigned int)3873132797ULL),((unsigned int)2470894682ULL),((unsigned int)1366607051ULL),((unsigned int)1495200224ULL),((unsigned int)470466511ULL),((unsigned int)1956098690ULL),((unsigned int)4100568951ULL),((unsigned int)539100162ULL),((unsigned int)2409411854ULL),((unsigned int)3890690862ULL),((unsigned int)4167765151ULL),((unsigned int)193073279ULL),((unsigned int)1696056960ULL),((unsigned int)1425352677ULL),((unsigned int)1060442500ULL)};
unsigned int b_0[16]={((unsigned int)132849301ULL),((unsigned int)3873132797ULL),((unsigned int)2470894682ULL),((unsigned int)1366607051ULL),((unsigned int)1495200224ULL),((unsigned int)470466511ULL),((unsigned int)1956098690ULL),((unsigned int)4100568951ULL),((unsigned int)539100162ULL),((unsigned int)2409411854ULL),((unsigned int)3890690862ULL),((unsigned int)4167765151ULL),((unsigned int)193073279ULL),((unsigned int)1696056960ULL),((unsigned int)1425352677ULL),((unsigned int)1060442500ULL)};
unsigned int a_1[4]={((unsigned int)1273579711ULL),((unsigned int)8440790ULL),((unsigned int)3028784606ULL),((unsigned int)3375223730ULL)};
unsigned int b_1[4]={((unsigned int)1273579711ULL),((unsigned int)8440790ULL),((unsigned int)3028784606ULL),((unsigned int)3375223730ULL)};
unsigned int a_2[4]={((unsigned int)2731120558ULL),((unsigned int)3472502904ULL),((unsigned int)2718143723ULL),((unsigned int)2091604148ULL)};
unsigned int b_2[4]={((unsigned int)2731120558ULL),((unsigned int)3472502904ULL),((unsigned int)2718143723ULL),((unsigned int)2091604148ULL)};
unsigned int a_3[4]={((unsigned int)1845941690ULL),((unsigned int)991420651ULL),((unsigned int)2547025143ULL),((unsigned int)917267660ULL)};
unsigned int b_3[4]={((unsigned int)1845941690ULL),((unsigned int)991420651ULL),((unsigned int)2547025143ULL),((unsigned int)917267660ULL)};
unsigned int a_4[4]={((unsigned int)192540714ULL),((unsigned int)3591777822ULL),((unsigned int)2002132888ULL),((unsigned int)2650602747ULL)};
unsigned int b_4[4]={((unsigned int)192540714ULL),((unsigned int)3591777822ULL),((unsigned int)2002132888ULL),((unsigned int)2650602747ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 102\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2524535438ULL),((unsigned int)849081684ULL),((unsigned int)2033222805ULL),((unsigned int)916026858ULL),((unsigned int)4124912128ULL),((unsigned int)3789631489ULL),((unsigned int)1428797523ULL),((unsigned int)60116093ULL),((unsigned int)2800651085ULL),((unsigned int)873079686ULL),((unsigned int)3693543508ULL),((unsigned int)293101386ULL),((unsigned int)3081592163ULL),((unsigned int)3308888684ULL),((unsigned int)4068372927ULL),((unsigned int)2205538646ULL)};
unsigned int b_0[16]={((unsigned int)2524535438ULL),((unsigned int)849081684ULL),((unsigned int)2033222805ULL),((unsigned int)916026858ULL),((unsigned int)4124912128ULL),((unsigned int)3789631489ULL),((unsigned int)1428797523ULL),((unsigned int)60116093ULL),((unsigned int)2800651085ULL),((unsigned int)873079686ULL),((unsigned int)3693543508ULL),((unsigned int)293101386ULL),((unsigned int)3081592163ULL),((unsigned int)3308888684ULL),((unsigned int)4068372927ULL),((unsigned int)2205538646ULL)};
unsigned int a_1[4]={((unsigned int)3252366760ULL),((unsigned int)334273952ULL),((unsigned int)2572989750ULL),((unsigned int)2793385613ULL)};
unsigned int b_1[4]={((unsigned int)3252366760ULL),((unsigned int)334273952ULL),((unsigned int)2572989750ULL),((unsigned int)2793385613ULL)};
unsigned int a_2[4]={((unsigned int)1036364141ULL),((unsigned int)3067702840ULL),((unsigned int)886287043ULL),((unsigned int)351112651ULL)};
unsigned int b_2[4]={((unsigned int)1036364141ULL),((unsigned int)3067702840ULL),((unsigned int)886287043ULL),((unsigned int)351112651ULL)};
unsigned int a_3[4]={((unsigned int)2198563149ULL),((unsigned int)3765029713ULL),((unsigned int)1461603206ULL),((unsigned int)2551812270ULL)};
unsigned int b_3[4]={((unsigned int)2198563149ULL),((unsigned int)3765029713ULL),((unsigned int)1461603206ULL),((unsigned int)2551812270ULL)};
unsigned int a_4[4]={((unsigned int)4299612ULL),((unsigned int)2516760081ULL),((unsigned int)434166604ULL),((unsigned int)3368945727ULL)};
unsigned int b_4[4]={((unsigned int)4299612ULL),((unsigned int)2516760081ULL),((unsigned int)434166604ULL),((unsigned int)3368945727ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 103\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1166512591ULL),((unsigned int)2307593709ULL),((unsigned int)3413053104ULL),((unsigned int)578285054ULL),((unsigned int)2889608048ULL),((unsigned int)3714426793ULL),((unsigned int)3178372953ULL),((unsigned int)2557818248ULL),((unsigned int)2643367509ULL),((unsigned int)4108761351ULL),((unsigned int)2471260469ULL),((unsigned int)2042696423ULL),((unsigned int)1844483536ULL),((unsigned int)878002403ULL),((unsigned int)1980678947ULL),((unsigned int)2453256570ULL)};
unsigned int b_0[16]={((unsigned int)1166512591ULL),((unsigned int)2307593709ULL),((unsigned int)3413053104ULL),((unsigned int)578285054ULL),((unsigned int)2889608048ULL),((unsigned int)3714426793ULL),((unsigned int)3178372953ULL),((unsigned int)2557818248ULL),((unsigned int)2643367509ULL),((unsigned int)4108761351ULL),((unsigned int)2471260469ULL),((unsigned int)2042696423ULL),((unsigned int)1844483536ULL),((unsigned int)878002403ULL),((unsigned int)1980678947ULL),((unsigned int)2453256570ULL)};
unsigned int a_1[4]={((unsigned int)2460548714ULL),((unsigned int)4240025865ULL),((unsigned int)3823626641ULL),((unsigned int)1952980952ULL)};
unsigned int b_1[4]={((unsigned int)2460548714ULL),((unsigned int)4240025865ULL),((unsigned int)3823626641ULL),((unsigned int)1952980952ULL)};
unsigned int a_2[4]={((unsigned int)1011196051ULL),((unsigned int)1815558413ULL),((unsigned int)3256937450ULL),((unsigned int)1363614470ULL)};
unsigned int b_2[4]={((unsigned int)1011196051ULL),((unsigned int)1815558413ULL),((unsigned int)3256937450ULL),((unsigned int)1363614470ULL)};
unsigned int a_3[4]={((unsigned int)911655999ULL),((unsigned int)717023432ULL),((unsigned int)2955260661ULL),((unsigned int)1646194663ULL)};
unsigned int b_3[4]={((unsigned int)911655999ULL),((unsigned int)717023432ULL),((unsigned int)2955260661ULL),((unsigned int)1646194663ULL)};
unsigned int a_4[4]={((unsigned int)385408168ULL),((unsigned int)2827598076ULL),((unsigned int)3279665835ULL),((unsigned int)2040577967ULL)};
unsigned int b_4[4]={((unsigned int)385408168ULL),((unsigned int)2827598076ULL),((unsigned int)3279665835ULL),((unsigned int)2040577967ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 104\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2825169264ULL),((unsigned int)2076433392ULL),((unsigned int)2193844072ULL),((unsigned int)479136446ULL),((unsigned int)1282755923ULL),((unsigned int)349438811ULL),((unsigned int)4242580490ULL),((unsigned int)2143605667ULL),((unsigned int)636006470ULL),((unsigned int)439308476ULL),((unsigned int)2810757337ULL),((unsigned int)3662145227ULL),((unsigned int)1903877688ULL),((unsigned int)1931913133ULL),((unsigned int)1743243627ULL),((unsigned int)1316796543ULL)};
unsigned int b_0[16]={((unsigned int)2825169264ULL),((unsigned int)2076433392ULL),((unsigned int)2193844072ULL),((unsigned int)479136446ULL),((unsigned int)1282755923ULL),((unsigned int)349438811ULL),((unsigned int)4242580490ULL),((unsigned int)2143605667ULL),((unsigned int)636006470ULL),((unsigned int)439308476ULL),((unsigned int)2810757337ULL),((unsigned int)3662145227ULL),((unsigned int)1903877688ULL),((unsigned int)1931913133ULL),((unsigned int)1743243627ULL),((unsigned int)1316796543ULL)};
unsigned int a_1[4]={((unsigned int)508610623ULL),((unsigned int)3835499241ULL),((unsigned int)248143685ULL),((unsigned int)2621605548ULL)};
unsigned int b_1[4]={((unsigned int)508610623ULL),((unsigned int)3835499241ULL),((unsigned int)248143685ULL),((unsigned int)2621605548ULL)};
unsigned int a_2[4]={((unsigned int)799097812ULL),((unsigned int)151183011ULL),((unsigned int)1586194716ULL),((unsigned int)91903069ULL)};
unsigned int b_2[4]={((unsigned int)799097812ULL),((unsigned int)151183011ULL),((unsigned int)1586194716ULL),((unsigned int)91903069ULL)};
unsigned int a_3[4]={((unsigned int)187117799ULL),((unsigned int)1647009093ULL),((unsigned int)766349032ULL),((unsigned int)3963003387ULL)};
unsigned int b_3[4]={((unsigned int)187117799ULL),((unsigned int)1647009093ULL),((unsigned int)766349032ULL),((unsigned int)3963003387ULL)};
unsigned int a_4[4]={((unsigned int)546811325ULL),((unsigned int)1338568408ULL),((unsigned int)273729884ULL),((unsigned int)1222237402ULL)};
unsigned int b_4[4]={((unsigned int)546811325ULL),((unsigned int)1338568408ULL),((unsigned int)273729884ULL),((unsigned int)1222237402ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 105\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4247686982ULL),((unsigned int)3201743145ULL),((unsigned int)3229817573ULL),((unsigned int)3709462071ULL),((unsigned int)1159741159ULL),((unsigned int)546438637ULL),((unsigned int)1871340749ULL),((unsigned int)1693605686ULL),((unsigned int)2851088883ULL),((unsigned int)1514402630ULL),((unsigned int)4062189218ULL),((unsigned int)636885087ULL),((unsigned int)1660513044ULL),((unsigned int)1256031646ULL),((unsigned int)3394941748ULL),((unsigned int)1668391836ULL)};
unsigned int b_0[16]={((unsigned int)4247686982ULL),((unsigned int)3201743145ULL),((unsigned int)3229817573ULL),((unsigned int)3709462071ULL),((unsigned int)1159741159ULL),((unsigned int)546438637ULL),((unsigned int)1871340749ULL),((unsigned int)1693605686ULL),((unsigned int)2851088883ULL),((unsigned int)1514402630ULL),((unsigned int)4062189218ULL),((unsigned int)636885087ULL),((unsigned int)1660513044ULL),((unsigned int)1256031646ULL),((unsigned int)3394941748ULL),((unsigned int)1668391836ULL)};
unsigned int a_1[4]={((unsigned int)3376358184ULL),((unsigned int)973643545ULL),((unsigned int)1451572062ULL),((unsigned int)2394595730ULL)};
unsigned int b_1[4]={((unsigned int)3376358184ULL),((unsigned int)973643545ULL),((unsigned int)1451572062ULL),((unsigned int)2394595730ULL)};
unsigned int a_2[4]={((unsigned int)3397125769ULL),((unsigned int)285207497ULL),((unsigned int)3863196467ULL),((unsigned int)393106983ULL)};
unsigned int b_2[4]={((unsigned int)3397125769ULL),((unsigned int)285207497ULL),((unsigned int)3863196467ULL),((unsigned int)393106983ULL)};
unsigned int a_3[4]={((unsigned int)3480406675ULL),((unsigned int)208486953ULL),((unsigned int)1541272481ULL),((unsigned int)1184887538ULL)};
unsigned int b_3[4]={((unsigned int)3480406675ULL),((unsigned int)208486953ULL),((unsigned int)1541272481ULL),((unsigned int)1184887538ULL)};
unsigned int a_4[4]={((unsigned int)1627893340ULL),((unsigned int)3110865972ULL),((unsigned int)1101278203ULL),((unsigned int)3837909728ULL)};
unsigned int b_4[4]={((unsigned int)1627893340ULL),((unsigned int)3110865972ULL),((unsigned int)1101278203ULL),((unsigned int)3837909728ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 106\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)395851242ULL),((unsigned int)465959998ULL),((unsigned int)220876154ULL),((unsigned int)2214425949ULL),((unsigned int)1110749115ULL),((unsigned int)433444700ULL),((unsigned int)3939460372ULL),((unsigned int)1543966526ULL),((unsigned int)2824830928ULL),((unsigned int)3316038215ULL),((unsigned int)2711712910ULL),((unsigned int)2957917206ULL),((unsigned int)3717224313ULL),((unsigned int)615012670ULL),((unsigned int)2023373935ULL),((unsigned int)829114884ULL)};
unsigned int b_0[16]={((unsigned int)395851242ULL),((unsigned int)465959998ULL),((unsigned int)220876154ULL),((unsigned int)2214425949ULL),((unsigned int)1110749115ULL),((unsigned int)433444700ULL),((unsigned int)3939460372ULL),((unsigned int)1543966526ULL),((unsigned int)2824830928ULL),((unsigned int)3316038215ULL),((unsigned int)2711712910ULL),((unsigned int)2957917206ULL),((unsigned int)3717224313ULL),((unsigned int)615012670ULL),((unsigned int)2023373935ULL),((unsigned int)829114884ULL)};
unsigned int a_1[4]={((unsigned int)3924237269ULL),((unsigned int)177198348ULL),((unsigned int)2757078141ULL),((unsigned int)1554966673ULL)};
unsigned int b_1[4]={((unsigned int)3924237269ULL),((unsigned int)177198348ULL),((unsigned int)2757078141ULL),((unsigned int)1554966673ULL)};
unsigned int a_2[4]={((unsigned int)1217407748ULL),((unsigned int)2758177275ULL),((unsigned int)3298562158ULL),((unsigned int)4256540203ULL)};
unsigned int b_2[4]={((unsigned int)1217407748ULL),((unsigned int)2758177275ULL),((unsigned int)3298562158ULL),((unsigned int)4256540203ULL)};
unsigned int a_3[4]={((unsigned int)3573399819ULL),((unsigned int)4008679067ULL),((unsigned int)973652775ULL),((unsigned int)1098903087ULL)};
unsigned int b_3[4]={((unsigned int)3573399819ULL),((unsigned int)4008679067ULL),((unsigned int)973652775ULL),((unsigned int)1098903087ULL)};
unsigned int a_4[4]={((unsigned int)3729698934ULL),((unsigned int)656151934ULL),((unsigned int)2728237547ULL),((unsigned int)572972778ULL)};
unsigned int b_4[4]={((unsigned int)3729698934ULL),((unsigned int)656151934ULL),((unsigned int)2728237547ULL),((unsigned int)572972778ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 107\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2044327040ULL),((unsigned int)181418610ULL),((unsigned int)4074350667ULL),((unsigned int)3765785122ULL),((unsigned int)3812395085ULL),((unsigned int)2380884781ULL),((unsigned int)2896024909ULL),((unsigned int)4293375154ULL),((unsigned int)1730749045ULL),((unsigned int)3941126068ULL),((unsigned int)2721729747ULL),((unsigned int)3776706610ULL),((unsigned int)732116198ULL),((unsigned int)932277851ULL),((unsigned int)2307581596ULL),((unsigned int)3813757819ULL)};
unsigned int b_0[16]={((unsigned int)2044327040ULL),((unsigned int)181418610ULL),((unsigned int)4074350667ULL),((unsigned int)3765785122ULL),((unsigned int)3812395085ULL),((unsigned int)2380884781ULL),((unsigned int)2896024909ULL),((unsigned int)4293375154ULL),((unsigned int)1730749045ULL),((unsigned int)3941126068ULL),((unsigned int)2721729747ULL),((unsigned int)3776706610ULL),((unsigned int)732116198ULL),((unsigned int)932277851ULL),((unsigned int)2307581596ULL),((unsigned int)3813757819ULL)};
unsigned int a_1[4]={((unsigned int)3029178287ULL),((unsigned int)3997463155ULL),((unsigned int)619720824ULL),((unsigned int)2363787421ULL)};
unsigned int b_1[4]={((unsigned int)3029178287ULL),((unsigned int)3997463155ULL),((unsigned int)619720824ULL),((unsigned int)2363787421ULL)};
unsigned int a_2[4]={((unsigned int)2809766094ULL),((unsigned int)3002990547ULL),((unsigned int)2979618704ULL),((unsigned int)1104733022ULL)};
unsigned int b_2[4]={((unsigned int)2809766094ULL),((unsigned int)3002990547ULL),((unsigned int)2979618704ULL),((unsigned int)1104733022ULL)};
unsigned int a_3[4]={((unsigned int)440739735ULL),((unsigned int)2248581652ULL),((unsigned int)1918134242ULL),((unsigned int)133864109ULL)};
unsigned int b_3[4]={((unsigned int)440739735ULL),((unsigned int)2248581652ULL),((unsigned int)1918134242ULL),((unsigned int)133864109ULL)};
unsigned int a_4[4]={((unsigned int)2161043383ULL),((unsigned int)687684824ULL),((unsigned int)3553663485ULL),((unsigned int)12811538ULL)};
unsigned int b_4[4]={((unsigned int)2161043383ULL),((unsigned int)687684824ULL),((unsigned int)3553663485ULL),((unsigned int)12811538ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 108\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)170835933ULL),((unsigned int)3171586370ULL),((unsigned int)1595604268ULL),((unsigned int)1861677201ULL),((unsigned int)3319792353ULL),((unsigned int)272715137ULL),((unsigned int)25212026ULL),((unsigned int)1019404799ULL),((unsigned int)1349532278ULL),((unsigned int)1253160791ULL),((unsigned int)1368983715ULL),((unsigned int)518399320ULL),((unsigned int)3269924599ULL),((unsigned int)2561485900ULL),((unsigned int)3608110104ULL),((unsigned int)2138873592ULL)};
unsigned int b_0[16]={((unsigned int)170835933ULL),((unsigned int)3171586370ULL),((unsigned int)1595604268ULL),((unsigned int)1861677201ULL),((unsigned int)3319792353ULL),((unsigned int)272715137ULL),((unsigned int)25212026ULL),((unsigned int)1019404799ULL),((unsigned int)1349532278ULL),((unsigned int)1253160791ULL),((unsigned int)1368983715ULL),((unsigned int)518399320ULL),((unsigned int)3269924599ULL),((unsigned int)2561485900ULL),((unsigned int)3608110104ULL),((unsigned int)2138873592ULL)};
unsigned int a_1[4]={((unsigned int)605424862ULL),((unsigned int)1262383673ULL),((unsigned int)3948925402ULL),((unsigned int)1316425750ULL)};
unsigned int b_1[4]={((unsigned int)605424862ULL),((unsigned int)1262383673ULL),((unsigned int)3948925402ULL),((unsigned int)1316425750ULL)};
unsigned int a_2[4]={((unsigned int)52477526ULL),((unsigned int)1896950638ULL),((unsigned int)3043959997ULL),((unsigned int)3146147721ULL)};
unsigned int b_2[4]={((unsigned int)52477526ULL),((unsigned int)1896950638ULL),((unsigned int)3043959997ULL),((unsigned int)3146147721ULL)};
unsigned int a_3[4]={((unsigned int)3290276210ULL),((unsigned int)3824171890ULL),((unsigned int)4171202888ULL),((unsigned int)1946564448ULL)};
unsigned int b_3[4]={((unsigned int)3290276210ULL),((unsigned int)3824171890ULL),((unsigned int)4171202888ULL),((unsigned int)1946564448ULL)};
unsigned int a_4[4]={((unsigned int)4060115693ULL),((unsigned int)2359738518ULL),((unsigned int)3722543389ULL),((unsigned int)2699817440ULL)};
unsigned int b_4[4]={((unsigned int)4060115693ULL),((unsigned int)2359738518ULL),((unsigned int)3722543389ULL),((unsigned int)2699817440ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 109\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1181684457ULL),((unsigned int)1160615924ULL),((unsigned int)2396727966ULL),((unsigned int)2992560605ULL),((unsigned int)2864657263ULL),((unsigned int)1977928829ULL),((unsigned int)3598855835ULL),((unsigned int)3014511172ULL),((unsigned int)2912648768ULL),((unsigned int)3444005583ULL),((unsigned int)3776112476ULL),((unsigned int)2464773400ULL),((unsigned int)3494462715ULL),((unsigned int)617457239ULL),((unsigned int)1587828044ULL),((unsigned int)1986235077ULL)};
unsigned int b_0[16]={((unsigned int)1181684457ULL),((unsigned int)1160615924ULL),((unsigned int)2396727966ULL),((unsigned int)2992560605ULL),((unsigned int)2864657263ULL),((unsigned int)1977928829ULL),((unsigned int)3598855835ULL),((unsigned int)3014511172ULL),((unsigned int)2912648768ULL),((unsigned int)3444005583ULL),((unsigned int)3776112476ULL),((unsigned int)2464773400ULL),((unsigned int)3494462715ULL),((unsigned int)617457239ULL),((unsigned int)1587828044ULL),((unsigned int)1986235077ULL)};
unsigned int a_1[4]={((unsigned int)3083959146ULL),((unsigned int)2270303766ULL),((unsigned int)2249665955ULL),((unsigned int)1289074562ULL)};
unsigned int b_1[4]={((unsigned int)3083959146ULL),((unsigned int)2270303766ULL),((unsigned int)2249665955ULL),((unsigned int)1289074562ULL)};
unsigned int a_2[4]={((unsigned int)3348382168ULL),((unsigned int)1128768466ULL),((unsigned int)3951722731ULL),((unsigned int)392372828ULL)};
unsigned int b_2[4]={((unsigned int)3348382168ULL),((unsigned int)1128768466ULL),((unsigned int)3951722731ULL),((unsigned int)392372828ULL)};
unsigned int a_3[4]={((unsigned int)2044212767ULL),((unsigned int)1596731048ULL),((unsigned int)2563471924ULL),((unsigned int)1990546186ULL)};
unsigned int b_3[4]={((unsigned int)2044212767ULL),((unsigned int)1596731048ULL),((unsigned int)2563471924ULL),((unsigned int)1990546186ULL)};
unsigned int a_4[4]={((unsigned int)3647593301ULL),((unsigned int)4095108350ULL),((unsigned int)1663579310ULL),((unsigned int)2938974706ULL)};
unsigned int b_4[4]={((unsigned int)3647593301ULL),((unsigned int)4095108350ULL),((unsigned int)1663579310ULL),((unsigned int)2938974706ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 110\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)386902161ULL),((unsigned int)4198791913ULL),((unsigned int)1640645113ULL),((unsigned int)1988948550ULL),((unsigned int)2872143756ULL),((unsigned int)898196702ULL),((unsigned int)3824086280ULL),((unsigned int)938720029ULL),((unsigned int)1264460060ULL),((unsigned int)1805191328ULL),((unsigned int)4109837340ULL),((unsigned int)3592720049ULL),((unsigned int)1635886013ULL),((unsigned int)2548508232ULL),((unsigned int)2136201242ULL),((unsigned int)3111870308ULL)};
unsigned int b_0[16]={((unsigned int)386902161ULL),((unsigned int)4198791913ULL),((unsigned int)1640645113ULL),((unsigned int)1988948550ULL),((unsigned int)2872143756ULL),((unsigned int)898196702ULL),((unsigned int)3824086280ULL),((unsigned int)938720029ULL),((unsigned int)1264460060ULL),((unsigned int)1805191328ULL),((unsigned int)4109837340ULL),((unsigned int)3592720049ULL),((unsigned int)1635886013ULL),((unsigned int)2548508232ULL),((unsigned int)2136201242ULL),((unsigned int)3111870308ULL)};
unsigned int a_1[4]={((unsigned int)1597302232ULL),((unsigned int)1357519376ULL),((unsigned int)1409916118ULL),((unsigned int)3158308483ULL)};
unsigned int b_1[4]={((unsigned int)1597302232ULL),((unsigned int)1357519376ULL),((unsigned int)1409916118ULL),((unsigned int)3158308483ULL)};
unsigned int a_2[4]={((unsigned int)2263044423ULL),((unsigned int)2255331331ULL),((unsigned int)385236672ULL),((unsigned int)1327138688ULL)};
unsigned int b_2[4]={((unsigned int)2263044423ULL),((unsigned int)2255331331ULL),((unsigned int)385236672ULL),((unsigned int)1327138688ULL)};
unsigned int a_3[4]={((unsigned int)2109617254ULL),((unsigned int)2525437400ULL),((unsigned int)217725043ULL),((unsigned int)1313188182ULL)};
unsigned int b_3[4]={((unsigned int)2109617254ULL),((unsigned int)2525437400ULL),((unsigned int)217725043ULL),((unsigned int)1313188182ULL)};
unsigned int a_4[4]={((unsigned int)34509848ULL),((unsigned int)392998468ULL),((unsigned int)1123259274ULL),((unsigned int)2793356521ULL)};
unsigned int b_4[4]={((unsigned int)34509848ULL),((unsigned int)392998468ULL),((unsigned int)1123259274ULL),((unsigned int)2793356521ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 111\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)758900177ULL),((unsigned int)296458506ULL),((unsigned int)2925669664ULL),((unsigned int)1879529018ULL),((unsigned int)2384179375ULL),((unsigned int)3408322933ULL),((unsigned int)3088731431ULL),((unsigned int)4218503613ULL),((unsigned int)2942361477ULL),((unsigned int)3736258869ULL),((unsigned int)2777442049ULL),((unsigned int)3761058053ULL),((unsigned int)2471562103ULL),((unsigned int)628823776ULL),((unsigned int)2300505731ULL),((unsigned int)3201353150ULL)};
unsigned int b_0[16]={((unsigned int)758900177ULL),((unsigned int)296458506ULL),((unsigned int)2925669664ULL),((unsigned int)1879529018ULL),((unsigned int)2384179375ULL),((unsigned int)3408322933ULL),((unsigned int)3088731431ULL),((unsigned int)4218503613ULL),((unsigned int)2942361477ULL),((unsigned int)3736258869ULL),((unsigned int)2777442049ULL),((unsigned int)3761058053ULL),((unsigned int)2471562103ULL),((unsigned int)628823776ULL),((unsigned int)2300505731ULL),((unsigned int)3201353150ULL)};
unsigned int a_1[4]={((unsigned int)4150054518ULL),((unsigned int)1157898456ULL),((unsigned int)4009955196ULL),((unsigned int)1017229340ULL)};
unsigned int b_1[4]={((unsigned int)4150054518ULL),((unsigned int)1157898456ULL),((unsigned int)4009955196ULL),((unsigned int)1017229340ULL)};
unsigned int a_2[4]={((unsigned int)1265014626ULL),((unsigned int)3527253733ULL),((unsigned int)212294717ULL),((unsigned int)3882397625ULL)};
unsigned int b_2[4]={((unsigned int)1265014626ULL),((unsigned int)3527253733ULL),((unsigned int)212294717ULL),((unsigned int)3882397625ULL)};
unsigned int a_3[4]={((unsigned int)2895585306ULL),((unsigned int)1674155952ULL),((unsigned int)516502138ULL),((unsigned int)4069761533ULL)};
unsigned int b_3[4]={((unsigned int)2895585306ULL),((unsigned int)1674155952ULL),((unsigned int)516502138ULL),((unsigned int)4069761533ULL)};
unsigned int a_4[4]={((unsigned int)717001308ULL),((unsigned int)603381277ULL),((unsigned int)375811660ULL),((unsigned int)828488777ULL)};
unsigned int b_4[4]={((unsigned int)717001308ULL),((unsigned int)603381277ULL),((unsigned int)375811660ULL),((unsigned int)828488777ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 112\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3022164002ULL),((unsigned int)81517264ULL),((unsigned int)552103132ULL),((unsigned int)2604707551ULL),((unsigned int)2062631719ULL),((unsigned int)1328383152ULL),((unsigned int)1539718378ULL),((unsigned int)1078836649ULL),((unsigned int)1030097117ULL),((unsigned int)2299636700ULL),((unsigned int)4158312269ULL),((unsigned int)2398158815ULL),((unsigned int)2177310619ULL),((unsigned int)3066771665ULL),((unsigned int)672478239ULL),((unsigned int)172483258ULL)};
unsigned int b_0[16]={((unsigned int)3022164002ULL),((unsigned int)81517264ULL),((unsigned int)552103132ULL),((unsigned int)2604707551ULL),((unsigned int)2062631719ULL),((unsigned int)1328383152ULL),((unsigned int)1539718378ULL),((unsigned int)1078836649ULL),((unsigned int)1030097117ULL),((unsigned int)2299636700ULL),((unsigned int)4158312269ULL),((unsigned int)2398158815ULL),((unsigned int)2177310619ULL),((unsigned int)3066771665ULL),((unsigned int)672478239ULL),((unsigned int)172483258ULL)};
unsigned int a_1[4]={((unsigned int)3380866362ULL),((unsigned int)2731718706ULL),((unsigned int)4134471149ULL),((unsigned int)1762812845ULL)};
unsigned int b_1[4]={((unsigned int)3380866362ULL),((unsigned int)2731718706ULL),((unsigned int)4134471149ULL),((unsigned int)1762812845ULL)};
unsigned int a_2[4]={((unsigned int)2794392022ULL),((unsigned int)3620804823ULL),((unsigned int)574175599ULL),((unsigned int)2166983824ULL)};
unsigned int b_2[4]={((unsigned int)2794392022ULL),((unsigned int)3620804823ULL),((unsigned int)574175599ULL),((unsigned int)2166983824ULL)};
unsigned int a_3[4]={((unsigned int)1833978209ULL),((unsigned int)1999260468ULL),((unsigned int)3110097468ULL),((unsigned int)841270948ULL)};
unsigned int b_3[4]={((unsigned int)1833978209ULL),((unsigned int)1999260468ULL),((unsigned int)3110097468ULL),((unsigned int)841270948ULL)};
unsigned int a_4[4]={((unsigned int)1352249714ULL),((unsigned int)1006413280ULL),((unsigned int)2877159604ULL),((unsigned int)3810993324ULL)};
unsigned int b_4[4]={((unsigned int)1352249714ULL),((unsigned int)1006413280ULL),((unsigned int)2877159604ULL),((unsigned int)3810993324ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 113\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1149098858ULL),((unsigned int)2198746612ULL),((unsigned int)3568108174ULL),((unsigned int)29040324ULL),((unsigned int)1630311605ULL),((unsigned int)422224429ULL),((unsigned int)1410751790ULL),((unsigned int)3380137257ULL),((unsigned int)117478962ULL),((unsigned int)2996082056ULL),((unsigned int)2726895394ULL),((unsigned int)638732413ULL),((unsigned int)1941158287ULL),((unsigned int)1002037050ULL),((unsigned int)3627464260ULL),((unsigned int)2873332827ULL)};
unsigned int b_0[16]={((unsigned int)1149098858ULL),((unsigned int)2198746612ULL),((unsigned int)3568108174ULL),((unsigned int)29040324ULL),((unsigned int)1630311605ULL),((unsigned int)422224429ULL),((unsigned int)1410751790ULL),((unsigned int)3380137257ULL),((unsigned int)117478962ULL),((unsigned int)2996082056ULL),((unsigned int)2726895394ULL),((unsigned int)638732413ULL),((unsigned int)1941158287ULL),((unsigned int)1002037050ULL),((unsigned int)3627464260ULL),((unsigned int)2873332827ULL)};
unsigned int a_1[4]={((unsigned int)2874681744ULL),((unsigned int)727333583ULL),((unsigned int)2101749338ULL),((unsigned int)1511789247ULL)};
unsigned int b_1[4]={((unsigned int)2874681744ULL),((unsigned int)727333583ULL),((unsigned int)2101749338ULL),((unsigned int)1511789247ULL)};
unsigned int a_2[4]={((unsigned int)3364302263ULL),((unsigned int)181486166ULL),((unsigned int)3971378326ULL),((unsigned int)744658924ULL)};
unsigned int b_2[4]={((unsigned int)3364302263ULL),((unsigned int)181486166ULL),((unsigned int)3971378326ULL),((unsigned int)744658924ULL)};
unsigned int a_3[4]={((unsigned int)3002433233ULL),((unsigned int)1349053544ULL),((unsigned int)3361263521ULL),((unsigned int)225345255ULL)};
unsigned int b_3[4]={((unsigned int)3002433233ULL),((unsigned int)1349053544ULL),((unsigned int)3361263521ULL),((unsigned int)225345255ULL)};
unsigned int a_4[4]={((unsigned int)2240215809ULL),((unsigned int)3375168681ULL),((unsigned int)1455777809ULL),((unsigned int)3201753351ULL)};
unsigned int b_4[4]={((unsigned int)2240215809ULL),((unsigned int)3375168681ULL),((unsigned int)1455777809ULL),((unsigned int)3201753351ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 114\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3500380401ULL),((unsigned int)1243334911ULL),((unsigned int)1527960545ULL),((unsigned int)3425038812ULL),((unsigned int)240783269ULL),((unsigned int)2029022621ULL),((unsigned int)598177619ULL),((unsigned int)3742440264ULL),((unsigned int)2879503523ULL),((unsigned int)3236464713ULL),((unsigned int)4173392234ULL),((unsigned int)2710217821ULL),((unsigned int)3021382923ULL),((unsigned int)1880026644ULL),((unsigned int)1554205759ULL),((unsigned int)2803139072ULL)};
unsigned int b_0[16]={((unsigned int)3500380401ULL),((unsigned int)1243334911ULL),((unsigned int)1527960545ULL),((unsigned int)3425038812ULL),((unsigned int)240783269ULL),((unsigned int)2029022621ULL),((unsigned int)598177619ULL),((unsigned int)3742440264ULL),((unsigned int)2879503523ULL),((unsigned int)3236464713ULL),((unsigned int)4173392234ULL),((unsigned int)2710217821ULL),((unsigned int)3021382923ULL),((unsigned int)1880026644ULL),((unsigned int)1554205759ULL),((unsigned int)2803139072ULL)};
unsigned int a_1[4]={((unsigned int)1571155432ULL),((unsigned int)2875592951ULL),((unsigned int)3635436300ULL),((unsigned int)3025709492ULL)};
unsigned int b_1[4]={((unsigned int)1571155432ULL),((unsigned int)2875592951ULL),((unsigned int)3635436300ULL),((unsigned int)3025709492ULL)};
unsigned int a_2[4]={((unsigned int)2116916ULL),((unsigned int)1387802131ULL),((unsigned int)3689520446ULL),((unsigned int)1647452915ULL)};
unsigned int b_2[4]={((unsigned int)2116916ULL),((unsigned int)1387802131ULL),((unsigned int)3689520446ULL),((unsigned int)1647452915ULL)};
unsigned int a_3[4]={((unsigned int)3102239690ULL),((unsigned int)554016893ULL),((unsigned int)1585337876ULL),((unsigned int)3841080838ULL)};
unsigned int b_3[4]={((unsigned int)3102239690ULL),((unsigned int)554016893ULL),((unsigned int)1585337876ULL),((unsigned int)3841080838ULL)};
unsigned int a_4[4]={((unsigned int)1542929339ULL),((unsigned int)4270000059ULL),((unsigned int)797429582ULL),((unsigned int)3018835312ULL)};
unsigned int b_4[4]={((unsigned int)1542929339ULL),((unsigned int)4270000059ULL),((unsigned int)797429582ULL),((unsigned int)3018835312ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 115\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3525804579ULL),((unsigned int)4256475667ULL),((unsigned int)3713501231ULL),((unsigned int)1578044301ULL),((unsigned int)815877808ULL),((unsigned int)4118236053ULL),((unsigned int)4126103080ULL),((unsigned int)2592496785ULL),((unsigned int)1864329958ULL),((unsigned int)2042086942ULL),((unsigned int)2954134816ULL),((unsigned int)3345789277ULL),((unsigned int)750778809ULL),((unsigned int)2184538085ULL),((unsigned int)2173302290ULL),((unsigned int)2314950732ULL)};
unsigned int b_0[16]={((unsigned int)3525804579ULL),((unsigned int)4256475667ULL),((unsigned int)3713501231ULL),((unsigned int)1578044301ULL),((unsigned int)815877808ULL),((unsigned int)4118236053ULL),((unsigned int)4126103080ULL),((unsigned int)2592496785ULL),((unsigned int)1864329958ULL),((unsigned int)2042086942ULL),((unsigned int)2954134816ULL),((unsigned int)3345789277ULL),((unsigned int)750778809ULL),((unsigned int)2184538085ULL),((unsigned int)2173302290ULL),((unsigned int)2314950732ULL)};
unsigned int a_1[4]={((unsigned int)2105700238ULL),((unsigned int)1046641712ULL),((unsigned int)3751870869ULL),((unsigned int)3628163163ULL)};
unsigned int b_1[4]={((unsigned int)2105700238ULL),((unsigned int)1046641712ULL),((unsigned int)3751870869ULL),((unsigned int)3628163163ULL)};
unsigned int a_2[4]={((unsigned int)2694109929ULL),((unsigned int)2441090251ULL),((unsigned int)3674145432ULL),((unsigned int)995267319ULL)};
unsigned int b_2[4]={((unsigned int)2694109929ULL),((unsigned int)2441090251ULL),((unsigned int)3674145432ULL),((unsigned int)995267319ULL)};
unsigned int a_3[4]={((unsigned int)2157871304ULL),((unsigned int)812939407ULL),((unsigned int)3930442788ULL),((unsigned int)2213359181ULL)};
unsigned int b_3[4]={((unsigned int)2157871304ULL),((unsigned int)812939407ULL),((unsigned int)3930442788ULL),((unsigned int)2213359181ULL)};
unsigned int a_4[4]={((unsigned int)2170860453ULL),((unsigned int)978108910ULL),((unsigned int)2901220775ULL),((unsigned int)1900916436ULL)};
unsigned int b_4[4]={((unsigned int)2170860453ULL),((unsigned int)978108910ULL),((unsigned int)2901220775ULL),((unsigned int)1900916436ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 116\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)420464791ULL),((unsigned int)2514578076ULL),((unsigned int)2492051522ULL),((unsigned int)1046095506ULL),((unsigned int)1877773050ULL),((unsigned int)969779428ULL),((unsigned int)3082513319ULL),((unsigned int)1230735445ULL),((unsigned int)1582920819ULL),((unsigned int)3784574730ULL),((unsigned int)3991173882ULL),((unsigned int)2850570937ULL),((unsigned int)1132269252ULL),((unsigned int)4077389376ULL),((unsigned int)1022341059ULL),((unsigned int)2747724865ULL)};
unsigned int b_0[16]={((unsigned int)420464791ULL),((unsigned int)2514578076ULL),((unsigned int)2492051522ULL),((unsigned int)1046095506ULL),((unsigned int)1877773050ULL),((unsigned int)969779428ULL),((unsigned int)3082513319ULL),((unsigned int)1230735445ULL),((unsigned int)1582920819ULL),((unsigned int)3784574730ULL),((unsigned int)3991173882ULL),((unsigned int)2850570937ULL),((unsigned int)1132269252ULL),((unsigned int)4077389376ULL),((unsigned int)1022341059ULL),((unsigned int)2747724865ULL)};
unsigned int a_1[4]={((unsigned int)3107552070ULL),((unsigned int)1873996571ULL),((unsigned int)3638534015ULL),((unsigned int)1725605234ULL)};
unsigned int b_1[4]={((unsigned int)3107552070ULL),((unsigned int)1873996571ULL),((unsigned int)3638534015ULL),((unsigned int)1725605234ULL)};
unsigned int a_2[4]={((unsigned int)3051676936ULL),((unsigned int)2266292519ULL),((unsigned int)1102989219ULL),((unsigned int)1410947999ULL)};
unsigned int b_2[4]={((unsigned int)3051676936ULL),((unsigned int)2266292519ULL),((unsigned int)1102989219ULL),((unsigned int)1410947999ULL)};
unsigned int a_3[4]={((unsigned int)1358387485ULL),((unsigned int)1257842564ULL),((unsigned int)3818869466ULL),((unsigned int)2725841914ULL)};
unsigned int b_3[4]={((unsigned int)1358387485ULL),((unsigned int)1257842564ULL),((unsigned int)3818869466ULL),((unsigned int)2725841914ULL)};
unsigned int a_4[4]={((unsigned int)4038708285ULL),((unsigned int)3888949885ULL),((unsigned int)2538641676ULL),((unsigned int)256714972ULL)};
unsigned int b_4[4]={((unsigned int)4038708285ULL),((unsigned int)3888949885ULL),((unsigned int)2538641676ULL),((unsigned int)256714972ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 117\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2949849163ULL),((unsigned int)1472252144ULL),((unsigned int)1759261720ULL),((unsigned int)4079198582ULL),((unsigned int)2531307610ULL),((unsigned int)2618947361ULL),((unsigned int)1389627367ULL),((unsigned int)1690829782ULL),((unsigned int)3662406094ULL),((unsigned int)3428806317ULL),((unsigned int)3922823401ULL),((unsigned int)269475301ULL),((unsigned int)2512457454ULL),((unsigned int)1189617774ULL),((unsigned int)2047199790ULL),((unsigned int)2395623107ULL)};
unsigned int b_0[16]={((unsigned int)2949849163ULL),((unsigned int)1472252144ULL),((unsigned int)1759261720ULL),((unsigned int)4079198582ULL),((unsigned int)2531307610ULL),((unsigned int)2618947361ULL),((unsigned int)1389627367ULL),((unsigned int)1690829782ULL),((unsigned int)3662406094ULL),((unsigned int)3428806317ULL),((unsigned int)3922823401ULL),((unsigned int)269475301ULL),((unsigned int)2512457454ULL),((unsigned int)1189617774ULL),((unsigned int)2047199790ULL),((unsigned int)2395623107ULL)};
unsigned int a_1[4]={((unsigned int)2590435338ULL),((unsigned int)4000685529ULL),((unsigned int)3223128647ULL),((unsigned int)3827424893ULL)};
unsigned int b_1[4]={((unsigned int)2590435338ULL),((unsigned int)4000685529ULL),((unsigned int)3223128647ULL),((unsigned int)3827424893ULL)};
unsigned int a_2[4]={((unsigned int)497963684ULL),((unsigned int)2209287286ULL),((unsigned int)3040028241ULL),((unsigned int)660098013ULL)};
unsigned int b_2[4]={((unsigned int)497963684ULL),((unsigned int)2209287286ULL),((unsigned int)3040028241ULL),((unsigned int)660098013ULL)};
unsigned int a_3[4]={((unsigned int)1692275926ULL),((unsigned int)1236755480ULL),((unsigned int)985929034ULL),((unsigned int)3716237923ULL)};
unsigned int b_3[4]={((unsigned int)1692275926ULL),((unsigned int)1236755480ULL),((unsigned int)985929034ULL),((unsigned int)3716237923ULL)};
unsigned int a_4[4]={((unsigned int)1876710137ULL),((unsigned int)1570517736ULL),((unsigned int)3330943397ULL),((unsigned int)774913244ULL)};
unsigned int b_4[4]={((unsigned int)1876710137ULL),((unsigned int)1570517736ULL),((unsigned int)3330943397ULL),((unsigned int)774913244ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 118\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3588003970ULL),((unsigned int)937122691ULL),((unsigned int)3119767610ULL),((unsigned int)1708214375ULL),((unsigned int)3467581114ULL),((unsigned int)3756077791ULL),((unsigned int)766453099ULL),((unsigned int)3049106519ULL),((unsigned int)4262597178ULL),((unsigned int)1053927384ULL),((unsigned int)3379381481ULL),((unsigned int)3110412007ULL),((unsigned int)2434143762ULL),((unsigned int)3795791716ULL),((unsigned int)741136716ULL),((unsigned int)573187812ULL)};
unsigned int b_0[16]={((unsigned int)3588003970ULL),((unsigned int)937122691ULL),((unsigned int)3119767610ULL),((unsigned int)1708214375ULL),((unsigned int)3467581114ULL),((unsigned int)3756077791ULL),((unsigned int)766453099ULL),((unsigned int)3049106519ULL),((unsigned int)4262597178ULL),((unsigned int)1053927384ULL),((unsigned int)3379381481ULL),((unsigned int)3110412007ULL),((unsigned int)2434143762ULL),((unsigned int)3795791716ULL),((unsigned int)741136716ULL),((unsigned int)573187812ULL)};
unsigned int a_1[4]={((unsigned int)66825710ULL),((unsigned int)270169930ULL),((unsigned int)659740061ULL),((unsigned int)1501013508ULL)};
unsigned int b_1[4]={((unsigned int)66825710ULL),((unsigned int)270169930ULL),((unsigned int)659740061ULL),((unsigned int)1501013508ULL)};
unsigned int a_2[4]={((unsigned int)3654701429ULL),((unsigned int)1596570075ULL),((unsigned int)2565557527ULL),((unsigned int)331107345ULL)};
unsigned int b_2[4]={((unsigned int)3654701429ULL),((unsigned int)1596570075ULL),((unsigned int)2565557527ULL),((unsigned int)331107345ULL)};
unsigned int a_3[4]={((unsigned int)4012710311ULL),((unsigned int)3302995735ULL),((unsigned int)2647689688ULL),((unsigned int)2049596568ULL)};
unsigned int b_3[4]={((unsigned int)4012710311ULL),((unsigned int)3302995735ULL),((unsigned int)2647689688ULL),((unsigned int)2049596568ULL)};
unsigned int a_4[4]={((unsigned int)1243244333ULL),((unsigned int)1061553156ULL),((unsigned int)1867174900ULL),((unsigned int)1588130492ULL)};
unsigned int b_4[4]={((unsigned int)1243244333ULL),((unsigned int)1061553156ULL),((unsigned int)1867174900ULL),((unsigned int)1588130492ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 119\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3010699087ULL),((unsigned int)669644053ULL),((unsigned int)1320316631ULL),((unsigned int)1782924953ULL),((unsigned int)504245757ULL),((unsigned int)3580931774ULL),((unsigned int)2097417298ULL),((unsigned int)433251754ULL),((unsigned int)1436502049ULL),((unsigned int)572663689ULL),((unsigned int)1064241333ULL),((unsigned int)1640435796ULL),((unsigned int)1332352809ULL),((unsigned int)2494553634ULL),((unsigned int)4125513247ULL),((unsigned int)3623561026ULL)};
unsigned int b_0[16]={((unsigned int)3010699087ULL),((unsigned int)669644053ULL),((unsigned int)1320316631ULL),((unsigned int)1782924953ULL),((unsigned int)504245757ULL),((unsigned int)3580931774ULL),((unsigned int)2097417298ULL),((unsigned int)433251754ULL),((unsigned int)1436502049ULL),((unsigned int)572663689ULL),((unsigned int)1064241333ULL),((unsigned int)1640435796ULL),((unsigned int)1332352809ULL),((unsigned int)2494553634ULL),((unsigned int)4125513247ULL),((unsigned int)3623561026ULL)};
unsigned int a_1[4]={((unsigned int)1763589150ULL),((unsigned int)93968438ULL),((unsigned int)1488519323ULL),((unsigned int)4159200038ULL)};
unsigned int b_1[4]={((unsigned int)1763589150ULL),((unsigned int)93968438ULL),((unsigned int)1488519323ULL),((unsigned int)4159200038ULL)};
unsigned int a_2[4]={((unsigned int)1252758847ULL),((unsigned int)1590903542ULL),((unsigned int)1527303952ULL),((unsigned int)3975829184ULL)};
unsigned int b_2[4]={((unsigned int)1252758847ULL),((unsigned int)1590903542ULL),((unsigned int)1527303952ULL),((unsigned int)3975829184ULL)};
unsigned int a_3[4]={((unsigned int)3700335225ULL),((unsigned int)1012339889ULL),((unsigned int)856974403ULL),((unsigned int)4181745744ULL)};
unsigned int b_3[4]={((unsigned int)3700335225ULL),((unsigned int)1012339889ULL),((unsigned int)856974403ULL),((unsigned int)4181745744ULL)};
unsigned int a_4[4]={((unsigned int)2150959817ULL),((unsigned int)3990885508ULL),((unsigned int)1295334632ULL),((unsigned int)3820270981ULL)};
unsigned int b_4[4]={((unsigned int)2150959817ULL),((unsigned int)3990885508ULL),((unsigned int)1295334632ULL),((unsigned int)3820270981ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 120\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3060240512ULL),((unsigned int)680926753ULL),((unsigned int)2414442544ULL),((unsigned int)1520578485ULL),((unsigned int)1451818577ULL),((unsigned int)1245242398ULL),((unsigned int)3776372348ULL),((unsigned int)471859145ULL),((unsigned int)478125465ULL),((unsigned int)3631997400ULL),((unsigned int)2155860357ULL),((unsigned int)3231621303ULL),((unsigned int)1201443057ULL),((unsigned int)1562701158ULL),((unsigned int)3003343662ULL),((unsigned int)1167439955ULL)};
unsigned int b_0[16]={((unsigned int)3060240512ULL),((unsigned int)680926753ULL),((unsigned int)2414442544ULL),((unsigned int)1520578485ULL),((unsigned int)1451818577ULL),((unsigned int)1245242398ULL),((unsigned int)3776372348ULL),((unsigned int)471859145ULL),((unsigned int)478125465ULL),((unsigned int)3631997400ULL),((unsigned int)2155860357ULL),((unsigned int)3231621303ULL),((unsigned int)1201443057ULL),((unsigned int)1562701158ULL),((unsigned int)3003343662ULL),((unsigned int)1167439955ULL)};
unsigned int a_1[4]={((unsigned int)873810177ULL),((unsigned int)1940902491ULL),((unsigned int)2774756093ULL),((unsigned int)2404523270ULL)};
unsigned int b_1[4]={((unsigned int)873810177ULL),((unsigned int)1940902491ULL),((unsigned int)2774756093ULL),((unsigned int)2404523270ULL)};
unsigned int a_2[4]={((unsigned int)3509137354ULL),((unsigned int)1527297992ULL),((unsigned int)1111243739ULL),((unsigned int)858978413ULL)};
unsigned int b_2[4]={((unsigned int)3509137354ULL),((unsigned int)1527297992ULL),((unsigned int)1111243739ULL),((unsigned int)858978413ULL)};
unsigned int a_3[4]={((unsigned int)1386775335ULL),((unsigned int)1386600242ULL),((unsigned int)238456995ULL),((unsigned int)28341447ULL)};
unsigned int b_3[4]={((unsigned int)1386775335ULL),((unsigned int)1386600242ULL),((unsigned int)238456995ULL),((unsigned int)28341447ULL)};
unsigned int a_4[4]={((unsigned int)4104963675ULL),((unsigned int)2834626186ULL),((unsigned int)51855958ULL),((unsigned int)661480884ULL)};
unsigned int b_4[4]={((unsigned int)4104963675ULL),((unsigned int)2834626186ULL),((unsigned int)51855958ULL),((unsigned int)661480884ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 121\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)669725314ULL),((unsigned int)2727250473ULL),((unsigned int)2994896440ULL),((unsigned int)791914990ULL),((unsigned int)3147040123ULL),((unsigned int)2378149200ULL),((unsigned int)2037294900ULL),((unsigned int)1184800365ULL),((unsigned int)2275012980ULL),((unsigned int)2753655703ULL),((unsigned int)2874886973ULL),((unsigned int)3615438642ULL),((unsigned int)183441057ULL),((unsigned int)1786580780ULL),((unsigned int)1695015493ULL),((unsigned int)3126091061ULL)};
unsigned int b_0[16]={((unsigned int)669725314ULL),((unsigned int)2727250473ULL),((unsigned int)2994896440ULL),((unsigned int)791914990ULL),((unsigned int)3147040123ULL),((unsigned int)2378149200ULL),((unsigned int)2037294900ULL),((unsigned int)1184800365ULL),((unsigned int)2275012980ULL),((unsigned int)2753655703ULL),((unsigned int)2874886973ULL),((unsigned int)3615438642ULL),((unsigned int)183441057ULL),((unsigned int)1786580780ULL),((unsigned int)1695015493ULL),((unsigned int)3126091061ULL)};
unsigned int a_1[4]={((unsigned int)2622101363ULL),((unsigned int)3953469236ULL),((unsigned int)1997018239ULL),((unsigned int)1910530635ULL)};
unsigned int b_1[4]={((unsigned int)2622101363ULL),((unsigned int)3953469236ULL),((unsigned int)1997018239ULL),((unsigned int)1910530635ULL)};
unsigned int a_2[4]={((unsigned int)2127009207ULL),((unsigned int)2470504955ULL),((unsigned int)2097033717ULL),((unsigned int)3476019483ULL)};
unsigned int b_2[4]={((unsigned int)2127009207ULL),((unsigned int)2470504955ULL),((unsigned int)2097033717ULL),((unsigned int)3476019483ULL)};
unsigned int a_3[4]={((unsigned int)955032542ULL),((unsigned int)4263948421ULL),((unsigned int)3572103510ULL),((unsigned int)1124529902ULL)};
unsigned int b_3[4]={((unsigned int)955032542ULL),((unsigned int)4263948421ULL),((unsigned int)3572103510ULL),((unsigned int)1124529902ULL)};
unsigned int a_4[4]={((unsigned int)2096330666ULL),((unsigned int)3645470156ULL),((unsigned int)1247895692ULL),((unsigned int)3811892989ULL)};
unsigned int b_4[4]={((unsigned int)2096330666ULL),((unsigned int)3645470156ULL),((unsigned int)1247895692ULL),((unsigned int)3811892989ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 122\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)336464135ULL),((unsigned int)602140359ULL),((unsigned int)1006546602ULL),((unsigned int)2740362751ULL),((unsigned int)1621872208ULL),((unsigned int)2695826732ULL),((unsigned int)3590796749ULL),((unsigned int)1291593558ULL),((unsigned int)3403032249ULL),((unsigned int)2063440696ULL),((unsigned int)2800671883ULL),((unsigned int)1695146753ULL),((unsigned int)10946426ULL),((unsigned int)232973289ULL),((unsigned int)3411140661ULL),((unsigned int)3626233699ULL)};
unsigned int b_0[16]={((unsigned int)336464135ULL),((unsigned int)602140359ULL),((unsigned int)1006546602ULL),((unsigned int)2740362751ULL),((unsigned int)1621872208ULL),((unsigned int)2695826732ULL),((unsigned int)3590796749ULL),((unsigned int)1291593558ULL),((unsigned int)3403032249ULL),((unsigned int)2063440696ULL),((unsigned int)2800671883ULL),((unsigned int)1695146753ULL),((unsigned int)10946426ULL),((unsigned int)232973289ULL),((unsigned int)3411140661ULL),((unsigned int)3626233699ULL)};
unsigned int a_1[4]={((unsigned int)1497445308ULL),((unsigned int)3304850660ULL),((unsigned int)4005021282ULL),((unsigned int)2686753227ULL)};
unsigned int b_1[4]={((unsigned int)1497445308ULL),((unsigned int)3304850660ULL),((unsigned int)4005021282ULL),((unsigned int)2686753227ULL)};
unsigned int a_2[4]={((unsigned int)2117567167ULL),((unsigned int)3411821061ULL),((unsigned int)258453586ULL),((unsigned int)2985454570ULL)};
unsigned int b_2[4]={((unsigned int)2117567167ULL),((unsigned int)3411821061ULL),((unsigned int)258453586ULL),((unsigned int)2985454570ULL)};
unsigned int a_3[4]={((unsigned int)4063951928ULL),((unsigned int)3048589193ULL),((unsigned int)3587412854ULL),((unsigned int)459168587ULL)};
unsigned int b_3[4]={((unsigned int)4063951928ULL),((unsigned int)3048589193ULL),((unsigned int)3587412854ULL),((unsigned int)459168587ULL)};
unsigned int a_4[4]={((unsigned int)4099037883ULL),((unsigned int)1518858447ULL),((unsigned int)3720083407ULL),((unsigned int)3009772461ULL)};
unsigned int b_4[4]={((unsigned int)4099037883ULL),((unsigned int)1518858447ULL),((unsigned int)3720083407ULL),((unsigned int)3009772461ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 123\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4221705674ULL),((unsigned int)3240196234ULL),((unsigned int)305077978ULL),((unsigned int)2985101799ULL),((unsigned int)2611469578ULL),((unsigned int)2286880041ULL),((unsigned int)1237217500ULL),((unsigned int)894784683ULL),((unsigned int)4277627293ULL),((unsigned int)1087516079ULL),((unsigned int)1577577293ULL),((unsigned int)1180546790ULL),((unsigned int)962328803ULL),((unsigned int)3664931188ULL),((unsigned int)791485805ULL),((unsigned int)3420354358ULL)};
unsigned int b_0[16]={((unsigned int)4221705674ULL),((unsigned int)3240196234ULL),((unsigned int)305077978ULL),((unsigned int)2985101799ULL),((unsigned int)2611469578ULL),((unsigned int)2286880041ULL),((unsigned int)1237217500ULL),((unsigned int)894784683ULL),((unsigned int)4277627293ULL),((unsigned int)1087516079ULL),((unsigned int)1577577293ULL),((unsigned int)1180546790ULL),((unsigned int)962328803ULL),((unsigned int)3664931188ULL),((unsigned int)791485805ULL),((unsigned int)3420354358ULL)};
unsigned int a_1[4]={((unsigned int)802919704ULL),((unsigned int)1901550589ULL),((unsigned int)2499626142ULL),((unsigned int)759490493ULL)};
unsigned int b_1[4]={((unsigned int)802919704ULL),((unsigned int)1901550589ULL),((unsigned int)2499626142ULL),((unsigned int)759490493ULL)};
unsigned int a_2[4]={((unsigned int)2271542235ULL),((unsigned int)3008831389ULL),((unsigned int)2556922743ULL),((unsigned int)1548069288ULL)};
unsigned int b_2[4]={((unsigned int)2271542235ULL),((unsigned int)3008831389ULL),((unsigned int)2556922743ULL),((unsigned int)1548069288ULL)};
unsigned int a_3[4]={((unsigned int)3870133545ULL),((unsigned int)392395906ULL),((unsigned int)503773ULL),((unsigned int)2285549630ULL)};
unsigned int b_3[4]={((unsigned int)3870133545ULL),((unsigned int)392395906ULL),((unsigned int)503773ULL),((unsigned int)2285549630ULL)};
unsigned int a_4[4]={((unsigned int)1925977726ULL),((unsigned int)367688077ULL),((unsigned int)713685524ULL),((unsigned int)208004778ULL)};
unsigned int b_4[4]={((unsigned int)1925977726ULL),((unsigned int)367688077ULL),((unsigned int)713685524ULL),((unsigned int)208004778ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 124\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)648908345ULL),((unsigned int)122708135ULL),((unsigned int)2937341203ULL),((unsigned int)4019151576ULL),((unsigned int)2919002278ULL),((unsigned int)1091516720ULL),((unsigned int)51468030ULL),((unsigned int)1269402135ULL),((unsigned int)3621335197ULL),((unsigned int)2229442662ULL),((unsigned int)4087784118ULL),((unsigned int)494684104ULL),((unsigned int)58076603ULL),((unsigned int)2583458287ULL),((unsigned int)3360652912ULL),((unsigned int)165748251ULL)};
unsigned int b_0[16]={((unsigned int)648908345ULL),((unsigned int)122708135ULL),((unsigned int)2937341203ULL),((unsigned int)4019151576ULL),((unsigned int)2919002278ULL),((unsigned int)1091516720ULL),((unsigned int)51468030ULL),((unsigned int)1269402135ULL),((unsigned int)3621335197ULL),((unsigned int)2229442662ULL),((unsigned int)4087784118ULL),((unsigned int)494684104ULL),((unsigned int)58076603ULL),((unsigned int)2583458287ULL),((unsigned int)3360652912ULL),((unsigned int)165748251ULL)};
unsigned int a_1[4]={((unsigned int)2837681856ULL),((unsigned int)945022278ULL),((unsigned int)812631615ULL),((unsigned int)1169464198ULL)};
unsigned int b_1[4]={((unsigned int)2837681856ULL),((unsigned int)945022278ULL),((unsigned int)812631615ULL),((unsigned int)1169464198ULL)};
unsigned int a_2[4]={((unsigned int)3915221070ULL),((unsigned int)3037398868ULL),((unsigned int)989973839ULL),((unsigned int)1856784969ULL)};
unsigned int b_2[4]={((unsigned int)3915221070ULL),((unsigned int)3037398868ULL),((unsigned int)989973839ULL),((unsigned int)1856784969ULL)};
unsigned int a_3[4]={((unsigned int)1518213365ULL),((unsigned int)538126707ULL),((unsigned int)400292112ULL),((unsigned int)2252268030ULL)};
unsigned int b_3[4]={((unsigned int)1518213365ULL),((unsigned int)538126707ULL),((unsigned int)400292112ULL),((unsigned int)2252268030ULL)};
unsigned int a_4[4]={((unsigned int)2244759185ULL),((unsigned int)3425325644ULL),((unsigned int)2432733975ULL),((unsigned int)1125465252ULL)};
unsigned int b_4[4]={((unsigned int)2244759185ULL),((unsigned int)3425325644ULL),((unsigned int)2432733975ULL),((unsigned int)1125465252ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 125\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1139658664ULL),((unsigned int)3336974802ULL),((unsigned int)1301904760ULL),((unsigned int)841493211ULL),((unsigned int)654791461ULL),((unsigned int)1360731715ULL),((unsigned int)2870467497ULL),((unsigned int)2927891729ULL),((unsigned int)3357652751ULL),((unsigned int)3029511305ULL),((unsigned int)1017077363ULL),((unsigned int)4127625869ULL),((unsigned int)3311054114ULL),((unsigned int)2944091599ULL),((unsigned int)3535124384ULL),((unsigned int)1935600768ULL)};
unsigned int b_0[16]={((unsigned int)1139658664ULL),((unsigned int)3336974802ULL),((unsigned int)1301904760ULL),((unsigned int)841493211ULL),((unsigned int)654791461ULL),((unsigned int)1360731715ULL),((unsigned int)2870467497ULL),((unsigned int)2927891729ULL),((unsigned int)3357652751ULL),((unsigned int)3029511305ULL),((unsigned int)1017077363ULL),((unsigned int)4127625869ULL),((unsigned int)3311054114ULL),((unsigned int)2944091599ULL),((unsigned int)3535124384ULL),((unsigned int)1935600768ULL)};
unsigned int a_1[4]={((unsigned int)1147098791ULL),((unsigned int)2428354757ULL),((unsigned int)4083777342ULL),((unsigned int)407979578ULL)};
unsigned int b_1[4]={((unsigned int)1147098791ULL),((unsigned int)2428354757ULL),((unsigned int)4083777342ULL),((unsigned int)407979578ULL)};
unsigned int a_2[4]={((unsigned int)558145443ULL),((unsigned int)1235859706ULL),((unsigned int)638293110ULL),((unsigned int)3649700246ULL)};
unsigned int b_2[4]={((unsigned int)558145443ULL),((unsigned int)1235859706ULL),((unsigned int)638293110ULL),((unsigned int)3649700246ULL)};
unsigned int a_3[4]={((unsigned int)1384465381ULL),((unsigned int)3336355343ULL),((unsigned int)1678402130ULL),((unsigned int)2238284348ULL)};
unsigned int b_3[4]={((unsigned int)1384465381ULL),((unsigned int)3336355343ULL),((unsigned int)1678402130ULL),((unsigned int)2238284348ULL)};
unsigned int a_4[4]={((unsigned int)3481689460ULL),((unsigned int)1876463565ULL),((unsigned int)2646513181ULL),((unsigned int)70809408ULL)};
unsigned int b_4[4]={((unsigned int)3481689460ULL),((unsigned int)1876463565ULL),((unsigned int)2646513181ULL),((unsigned int)70809408ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 126\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3181684093ULL),((unsigned int)3300866565ULL),((unsigned int)2887999662ULL),((unsigned int)3099775907ULL),((unsigned int)4145431077ULL),((unsigned int)1076123318ULL),((unsigned int)1343040628ULL),((unsigned int)891137352ULL),((unsigned int)2285228389ULL),((unsigned int)769006401ULL),((unsigned int)3250619321ULL),((unsigned int)3630814577ULL),((unsigned int)672936725ULL),((unsigned int)306817673ULL),((unsigned int)228551428ULL),((unsigned int)3350668999ULL)};
unsigned int b_0[16]={((unsigned int)3181684093ULL),((unsigned int)3300866565ULL),((unsigned int)2887999662ULL),((unsigned int)3099775907ULL),((unsigned int)4145431077ULL),((unsigned int)1076123318ULL),((unsigned int)1343040628ULL),((unsigned int)891137352ULL),((unsigned int)2285228389ULL),((unsigned int)769006401ULL),((unsigned int)3250619321ULL),((unsigned int)3630814577ULL),((unsigned int)672936725ULL),((unsigned int)306817673ULL),((unsigned int)228551428ULL),((unsigned int)3350668999ULL)};
unsigned int a_1[4]={((unsigned int)1331267459ULL),((unsigned int)981633805ULL),((unsigned int)3251637282ULL),((unsigned int)4126945977ULL)};
unsigned int b_1[4]={((unsigned int)1331267459ULL),((unsigned int)981633805ULL),((unsigned int)3251637282ULL),((unsigned int)4126945977ULL)};
unsigned int a_2[4]={((unsigned int)3531899770ULL),((unsigned int)1768397293ULL),((unsigned int)3210344832ULL),((unsigned int)2159517126ULL)};
unsigned int b_2[4]={((unsigned int)3531899770ULL),((unsigned int)1768397293ULL),((unsigned int)3210344832ULL),((unsigned int)2159517126ULL)};
unsigned int a_3[4]={((unsigned int)844636692ULL),((unsigned int)1876649473ULL),((unsigned int)4047266921ULL),((unsigned int)2471884275ULL)};
unsigned int b_3[4]={((unsigned int)844636692ULL),((unsigned int)1876649473ULL),((unsigned int)4047266921ULL),((unsigned int)2471884275ULL)};
unsigned int a_4[4]={((unsigned int)3570899003ULL),((unsigned int)855037445ULL),((unsigned int)2096724802ULL),((unsigned int)1208590972ULL)};
unsigned int b_4[4]={((unsigned int)3570899003ULL),((unsigned int)855037445ULL),((unsigned int)2096724802ULL),((unsigned int)1208590972ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 127\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1266277006ULL),((unsigned int)4020456127ULL),((unsigned int)2231883410ULL),((unsigned int)2195388823ULL),((unsigned int)2809992875ULL),((unsigned int)3910347154ULL),((unsigned int)2464496790ULL),((unsigned int)1874765836ULL),((unsigned int)3426246812ULL),((unsigned int)2659101822ULL),((unsigned int)4207339731ULL),((unsigned int)2399761292ULL),((unsigned int)1557345078ULL),((unsigned int)113834174ULL),((unsigned int)3479282099ULL),((unsigned int)294747319ULL)};
unsigned int b_0[16]={((unsigned int)1266277006ULL),((unsigned int)4020456127ULL),((unsigned int)2231883410ULL),((unsigned int)2195388823ULL),((unsigned int)2809992875ULL),((unsigned int)3910347154ULL),((unsigned int)2464496790ULL),((unsigned int)1874765836ULL),((unsigned int)3426246812ULL),((unsigned int)2659101822ULL),((unsigned int)4207339731ULL),((unsigned int)2399761292ULL),((unsigned int)1557345078ULL),((unsigned int)113834174ULL),((unsigned int)3479282099ULL),((unsigned int)294747319ULL)};
unsigned int a_1[4]={((unsigned int)2233609093ULL),((unsigned int)1788469041ULL),((unsigned int)4250035300ULL),((unsigned int)2740275267ULL)};
unsigned int b_1[4]={((unsigned int)2233609093ULL),((unsigned int)1788469041ULL),((unsigned int)4250035300ULL),((unsigned int)2740275267ULL)};
unsigned int a_2[4]={((unsigned int)1752224407ULL),((unsigned int)3265909455ULL),((unsigned int)1168166844ULL),((unsigned int)3988501551ULL)};
unsigned int b_2[4]={((unsigned int)1752224407ULL),((unsigned int)3265909455ULL),((unsigned int)1168166844ULL),((unsigned int)3988501551ULL)};
unsigned int a_3[4]={((unsigned int)2752788585ULL),((unsigned int)250888619ULL),((unsigned int)4055778364ULL),((unsigned int)4081902997ULL)};
unsigned int b_3[4]={((unsigned int)2752788585ULL),((unsigned int)250888619ULL),((unsigned int)4055778364ULL),((unsigned int)4081902997ULL)};
unsigned int a_4[4]={((unsigned int)1391743110ULL),((unsigned int)1178742418ULL),((unsigned int)3303173646ULL),((unsigned int)2921230840ULL)};
unsigned int b_4[4]={((unsigned int)1391743110ULL),((unsigned int)1178742418ULL),((unsigned int)3303173646ULL),((unsigned int)2921230840ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 128\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2170455067ULL),((unsigned int)386539940ULL),((unsigned int)2361107912ULL),((unsigned int)1542188600ULL),((unsigned int)860951586ULL),((unsigned int)1484241575ULL),((unsigned int)2939793285ULL),((unsigned int)537472318ULL),((unsigned int)224257299ULL),((unsigned int)1143078668ULL),((unsigned int)4239168462ULL),((unsigned int)1890604617ULL),((unsigned int)224259065ULL),((unsigned int)475271129ULL),((unsigned int)867873735ULL),((unsigned int)1380557093ULL)};
unsigned int b_0[16]={((unsigned int)2170455067ULL),((unsigned int)386539940ULL),((unsigned int)2361107912ULL),((unsigned int)1542188600ULL),((unsigned int)860951586ULL),((unsigned int)1484241575ULL),((unsigned int)2939793285ULL),((unsigned int)537472318ULL),((unsigned int)224257299ULL),((unsigned int)1143078668ULL),((unsigned int)4239168462ULL),((unsigned int)1890604617ULL),((unsigned int)224259065ULL),((unsigned int)475271129ULL),((unsigned int)867873735ULL),((unsigned int)1380557093ULL)};
unsigned int a_1[4]={((unsigned int)1172508828ULL),((unsigned int)2533669137ULL),((unsigned int)3365935663ULL),((unsigned int)2312848084ULL)};
unsigned int b_1[4]={((unsigned int)1172508828ULL),((unsigned int)2533669137ULL),((unsigned int)3365935663ULL),((unsigned int)2312848084ULL)};
unsigned int a_2[4]={((unsigned int)2610880833ULL),((unsigned int)1442905847ULL),((unsigned int)3299181962ULL),((unsigned int)2304636975ULL)};
unsigned int b_2[4]={((unsigned int)2610880833ULL),((unsigned int)1442905847ULL),((unsigned int)3299181962ULL),((unsigned int)2304636975ULL)};
unsigned int a_3[4]={((unsigned int)4042936827ULL),((unsigned int)1212194444ULL),((unsigned int)4016469724ULL),((unsigned int)2776829568ULL)};
unsigned int b_3[4]={((unsigned int)4042936827ULL),((unsigned int)1212194444ULL),((unsigned int)4016469724ULL),((unsigned int)2776829568ULL)};
unsigned int a_4[4]={((unsigned int)3232123571ULL),((unsigned int)2557023434ULL),((unsigned int)2277351591ULL),((unsigned int)2750286049ULL)};
unsigned int b_4[4]={((unsigned int)3232123571ULL),((unsigned int)2557023434ULL),((unsigned int)2277351591ULL),((unsigned int)2750286049ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 129\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1702507424ULL),((unsigned int)998228710ULL),((unsigned int)2530042019ULL),((unsigned int)2999528396ULL),((unsigned int)325128759ULL),((unsigned int)828691337ULL),((unsigned int)3933963636ULL),((unsigned int)2131100168ULL),((unsigned int)1855990937ULL),((unsigned int)3634784016ULL),((unsigned int)823437423ULL),((unsigned int)2520579178ULL),((unsigned int)354052810ULL),((unsigned int)1326279159ULL),((unsigned int)1235700037ULL),((unsigned int)3107157839ULL)};
unsigned int b_0[16]={((unsigned int)1702507424ULL),((unsigned int)998228710ULL),((unsigned int)2530042019ULL),((unsigned int)2999528396ULL),((unsigned int)325128759ULL),((unsigned int)828691337ULL),((unsigned int)3933963636ULL),((unsigned int)2131100168ULL),((unsigned int)1855990937ULL),((unsigned int)3634784016ULL),((unsigned int)823437423ULL),((unsigned int)2520579178ULL),((unsigned int)354052810ULL),((unsigned int)1326279159ULL),((unsigned int)1235700037ULL),((unsigned int)3107157839ULL)};
unsigned int a_1[4]={((unsigned int)3914049008ULL),((unsigned int)1945860120ULL),((unsigned int)3967638353ULL),((unsigned int)1998239496ULL)};
unsigned int b_1[4]={((unsigned int)3914049008ULL),((unsigned int)1945860120ULL),((unsigned int)3967638353ULL),((unsigned int)1998239496ULL)};
unsigned int a_2[4]={((unsigned int)1155181806ULL),((unsigned int)4188598664ULL),((unsigned int)3123504610ULL),((unsigned int)3333148613ULL)};
unsigned int b_2[4]={((unsigned int)1155181806ULL),((unsigned int)4188598664ULL),((unsigned int)3123504610ULL),((unsigned int)3333148613ULL)};
unsigned int a_3[4]={((unsigned int)1608738618ULL),((unsigned int)1536462613ULL),((unsigned int)495172391ULL),((unsigned int)2233920668ULL)};
unsigned int b_3[4]={((unsigned int)1608738618ULL),((unsigned int)1536462613ULL),((unsigned int)495172391ULL),((unsigned int)2233920668ULL)};
unsigned int a_4[4]={((unsigned int)806919506ULL),((unsigned int)3875069892ULL),((unsigned int)3669540034ULL),((unsigned int)3361415878ULL)};
unsigned int b_4[4]={((unsigned int)806919506ULL),((unsigned int)3875069892ULL),((unsigned int)3669540034ULL),((unsigned int)3361415878ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 130\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3075406173ULL),((unsigned int)3309461710ULL),((unsigned int)3646833885ULL),((unsigned int)358176660ULL),((unsigned int)4157947147ULL),((unsigned int)2768343872ULL),((unsigned int)3335720889ULL),((unsigned int)4237252712ULL),((unsigned int)2488702592ULL),((unsigned int)4134051467ULL),((unsigned int)487305508ULL),((unsigned int)3615184407ULL),((unsigned int)3994667779ULL),((unsigned int)1121608878ULL),((unsigned int)2771838955ULL),((unsigned int)340416615ULL)};
unsigned int b_0[16]={((unsigned int)3075406173ULL),((unsigned int)3309461710ULL),((unsigned int)3646833885ULL),((unsigned int)358176660ULL),((unsigned int)4157947147ULL),((unsigned int)2768343872ULL),((unsigned int)3335720889ULL),((unsigned int)4237252712ULL),((unsigned int)2488702592ULL),((unsigned int)4134051467ULL),((unsigned int)487305508ULL),((unsigned int)3615184407ULL),((unsigned int)3994667779ULL),((unsigned int)1121608878ULL),((unsigned int)2771838955ULL),((unsigned int)340416615ULL)};
unsigned int a_1[4]={((unsigned int)1158896397ULL),((unsigned int)1658556790ULL),((unsigned int)463130472ULL),((unsigned int)514876518ULL)};
unsigned int b_1[4]={((unsigned int)1158896397ULL),((unsigned int)1658556790ULL),((unsigned int)463130472ULL),((unsigned int)514876518ULL)};
unsigned int a_2[4]={((unsigned int)626954309ULL),((unsigned int)3731553832ULL),((unsigned int)210740273ULL),((unsigned int)2533268490ULL)};
unsigned int b_2[4]={((unsigned int)626954309ULL),((unsigned int)3731553832ULL),((unsigned int)210740273ULL),((unsigned int)2533268490ULL)};
unsigned int a_3[4]={((unsigned int)666773678ULL),((unsigned int)3619245844ULL),((unsigned int)3264637454ULL),((unsigned int)3823028422ULL)};
unsigned int b_3[4]={((unsigned int)666773678ULL),((unsigned int)3619245844ULL),((unsigned int)3264637454ULL),((unsigned int)3823028422ULL)};
unsigned int a_4[4]={((unsigned int)2835989652ULL),((unsigned int)3879323354ULL),((unsigned int)1510857326ULL),((unsigned int)3472995178ULL)};
unsigned int b_4[4]={((unsigned int)2835989652ULL),((unsigned int)3879323354ULL),((unsigned int)1510857326ULL),((unsigned int)3472995178ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 131\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3008045006ULL),((unsigned int)2376144196ULL),((unsigned int)2588178254ULL),((unsigned int)4136666199ULL),((unsigned int)3358648602ULL),((unsigned int)2109752825ULL),((unsigned int)2467709230ULL),((unsigned int)348696404ULL),((unsigned int)1429848816ULL),((unsigned int)1612024788ULL),((unsigned int)2606342008ULL),((unsigned int)1877515948ULL),((unsigned int)1692402306ULL),((unsigned int)1174422397ULL),((unsigned int)3154312953ULL),((unsigned int)1547378172ULL)};
unsigned int b_0[16]={((unsigned int)3008045006ULL),((unsigned int)2376144196ULL),((unsigned int)2588178254ULL),((unsigned int)4136666199ULL),((unsigned int)3358648602ULL),((unsigned int)2109752825ULL),((unsigned int)2467709230ULL),((unsigned int)348696404ULL),((unsigned int)1429848816ULL),((unsigned int)1612024788ULL),((unsigned int)2606342008ULL),((unsigned int)1877515948ULL),((unsigned int)1692402306ULL),((unsigned int)1174422397ULL),((unsigned int)3154312953ULL),((unsigned int)1547378172ULL)};
unsigned int a_1[4]={((unsigned int)2357648699ULL),((unsigned int)1757536308ULL),((unsigned int)3796422639ULL),((unsigned int)836645776ULL)};
unsigned int b_1[4]={((unsigned int)2357648699ULL),((unsigned int)1757536308ULL),((unsigned int)3796422639ULL),((unsigned int)836645776ULL)};
unsigned int a_2[4]={((unsigned int)2188147090ULL),((unsigned int)454244400ULL),((unsigned int)2846362937ULL),((unsigned int)2990422400ULL)};
unsigned int b_2[4]={((unsigned int)2188147090ULL),((unsigned int)454244400ULL),((unsigned int)2846362937ULL),((unsigned int)2990422400ULL)};
unsigned int a_3[4]={((unsigned int)3073848533ULL),((unsigned int)485951693ULL),((unsigned int)331271137ULL),((unsigned int)289021044ULL)};
unsigned int b_3[4]={((unsigned int)3073848533ULL),((unsigned int)485951693ULL),((unsigned int)331271137ULL),((unsigned int)289021044ULL)};
unsigned int a_4[4]={((unsigned int)862788215ULL),((unsigned int)1865759615ULL),((unsigned int)281142371ULL),((unsigned int)3173272247ULL)};
unsigned int b_4[4]={((unsigned int)862788215ULL),((unsigned int)1865759615ULL),((unsigned int)281142371ULL),((unsigned int)3173272247ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 132\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3123653385ULL),((unsigned int)490925230ULL),((unsigned int)2887900497ULL),((unsigned int)2234997222ULL),((unsigned int)2106431423ULL),((unsigned int)1454536766ULL),((unsigned int)2318864160ULL),((unsigned int)3925019704ULL),((unsigned int)572175509ULL),((unsigned int)4206616722ULL),((unsigned int)441585511ULL),((unsigned int)802237365ULL),((unsigned int)891961728ULL),((unsigned int)480242151ULL),((unsigned int)1598207773ULL),((unsigned int)1332432736ULL)};
unsigned int b_0[16]={((unsigned int)3123653385ULL),((unsigned int)490925230ULL),((unsigned int)2887900497ULL),((unsigned int)2234997222ULL),((unsigned int)2106431423ULL),((unsigned int)1454536766ULL),((unsigned int)2318864160ULL),((unsigned int)3925019704ULL),((unsigned int)572175509ULL),((unsigned int)4206616722ULL),((unsigned int)441585511ULL),((unsigned int)802237365ULL),((unsigned int)891961728ULL),((unsigned int)480242151ULL),((unsigned int)1598207773ULL),((unsigned int)1332432736ULL)};
unsigned int a_1[4]={((unsigned int)813775058ULL),((unsigned int)113285432ULL),((unsigned int)3986386712ULL),((unsigned int)3847014983ULL)};
unsigned int b_1[4]={((unsigned int)813775058ULL),((unsigned int)113285432ULL),((unsigned int)3986386712ULL),((unsigned int)3847014983ULL)};
unsigned int a_2[4]={((unsigned int)3395800672ULL),((unsigned int)816076366ULL),((unsigned int)2727606558ULL),((unsigned int)504216462ULL)};
unsigned int b_2[4]={((unsigned int)3395800672ULL),((unsigned int)816076366ULL),((unsigned int)2727606558ULL),((unsigned int)504216462ULL)};
unsigned int a_3[4]={((unsigned int)774051441ULL),((unsigned int)2421944107ULL),((unsigned int)308514778ULL),((unsigned int)602000706ULL)};
unsigned int b_3[4]={((unsigned int)774051441ULL),((unsigned int)2421944107ULL),((unsigned int)308514778ULL),((unsigned int)602000706ULL)};
unsigned int a_4[4]={((unsigned int)4176880751ULL),((unsigned int)3568757353ULL),((unsigned int)142023947ULL),((unsigned int)4286787391ULL)};
unsigned int b_4[4]={((unsigned int)4176880751ULL),((unsigned int)3568757353ULL),((unsigned int)142023947ULL),((unsigned int)4286787391ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 133\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3012582757ULL),((unsigned int)495447424ULL),((unsigned int)3698239588ULL),((unsigned int)2613069927ULL),((unsigned int)773948692ULL),((unsigned int)3356544900ULL),((unsigned int)905947557ULL),((unsigned int)2959952286ULL),((unsigned int)3854568576ULL),((unsigned int)2163515344ULL),((unsigned int)2027718756ULL),((unsigned int)1707354239ULL),((unsigned int)4012718301ULL),((unsigned int)3896769160ULL),((unsigned int)3676604655ULL),((unsigned int)1962329288ULL)};
unsigned int b_0[16]={((unsigned int)3012582757ULL),((unsigned int)495447424ULL),((unsigned int)3698239588ULL),((unsigned int)2613069927ULL),((unsigned int)773948692ULL),((unsigned int)3356544900ULL),((unsigned int)905947557ULL),((unsigned int)2959952286ULL),((unsigned int)3854568576ULL),((unsigned int)2163515344ULL),((unsigned int)2027718756ULL),((unsigned int)1707354239ULL),((unsigned int)4012718301ULL),((unsigned int)3896769160ULL),((unsigned int)3676604655ULL),((unsigned int)1962329288ULL)};
unsigned int a_1[4]={((unsigned int)2480030914ULL),((unsigned int)3034640149ULL),((unsigned int)2942396878ULL),((unsigned int)1514939248ULL)};
unsigned int b_1[4]={((unsigned int)2480030914ULL),((unsigned int)3034640149ULL),((unsigned int)2942396878ULL),((unsigned int)1514939248ULL)};
unsigned int a_2[4]={((unsigned int)1550428078ULL),((unsigned int)2754504989ULL),((unsigned int)3221099538ULL),((unsigned int)3097750765ULL)};
unsigned int b_2[4]={((unsigned int)1550428078ULL),((unsigned int)2754504989ULL),((unsigned int)3221099538ULL),((unsigned int)3097750765ULL)};
unsigned int a_3[4]={((unsigned int)2715434139ULL),((unsigned int)2093777990ULL),((unsigned int)2327309197ULL),((unsigned int)264527504ULL)};
unsigned int b_3[4]={((unsigned int)2715434139ULL),((unsigned int)2093777990ULL),((unsigned int)2327309197ULL),((unsigned int)264527504ULL)};
unsigned int a_4[4]={((unsigned int)741035942ULL),((unsigned int)2583921429ULL),((unsigned int)2605345865ULL),((unsigned int)899429622ULL)};
unsigned int b_4[4]={((unsigned int)741035942ULL),((unsigned int)2583921429ULL),((unsigned int)2605345865ULL),((unsigned int)899429622ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 134\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)576608529ULL),((unsigned int)2982129451ULL),((unsigned int)2321441758ULL),((unsigned int)2761167582ULL),((unsigned int)258770130ULL),((unsigned int)747539842ULL),((unsigned int)2091632894ULL),((unsigned int)2607695116ULL),((unsigned int)3484734920ULL),((unsigned int)1534604345ULL),((unsigned int)614189536ULL),((unsigned int)688900099ULL),((unsigned int)2135706913ULL),((unsigned int)3892993459ULL),((unsigned int)2235615615ULL),((unsigned int)3996360267ULL)};
unsigned int b_0[16]={((unsigned int)576608529ULL),((unsigned int)2982129451ULL),((unsigned int)2321441758ULL),((unsigned int)2761167582ULL),((unsigned int)258770130ULL),((unsigned int)747539842ULL),((unsigned int)2091632894ULL),((unsigned int)2607695116ULL),((unsigned int)3484734920ULL),((unsigned int)1534604345ULL),((unsigned int)614189536ULL),((unsigned int)688900099ULL),((unsigned int)2135706913ULL),((unsigned int)3892993459ULL),((unsigned int)2235615615ULL),((unsigned int)3996360267ULL)};
unsigned int a_1[4]={((unsigned int)4146260895ULL),((unsigned int)2521761177ULL),((unsigned int)2876088229ULL),((unsigned int)2293936415ULL)};
unsigned int b_1[4]={((unsigned int)4146260895ULL),((unsigned int)2521761177ULL),((unsigned int)2876088229ULL),((unsigned int)2293936415ULL)};
unsigned int a_2[4]={((unsigned int)4267882547ULL),((unsigned int)1901823894ULL),((unsigned int)1221435518ULL),((unsigned int)3046479833ULL)};
unsigned int b_2[4]={((unsigned int)4267882547ULL),((unsigned int)1901823894ULL),((unsigned int)1221435518ULL),((unsigned int)3046479833ULL)};
unsigned int a_3[4]={((unsigned int)1980229756ULL),((unsigned int)1846051352ULL),((unsigned int)1304399628ULL),((unsigned int)1204927629ULL)};
unsigned int b_3[4]={((unsigned int)1980229756ULL),((unsigned int)1846051352ULL),((unsigned int)1304399628ULL),((unsigned int)1204927629ULL)};
unsigned int a_4[4]={((unsigned int)2221803030ULL),((unsigned int)3861805526ULL),((unsigned int)3081406706ULL),((unsigned int)2048138628ULL)};
unsigned int b_4[4]={((unsigned int)2221803030ULL),((unsigned int)3861805526ULL),((unsigned int)3081406706ULL),((unsigned int)2048138628ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 135\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3538857472ULL),((unsigned int)2132819277ULL),((unsigned int)3666365069ULL),((unsigned int)3733798682ULL),((unsigned int)16503559ULL),((unsigned int)823164414ULL),((unsigned int)2446713010ULL),((unsigned int)1017468049ULL),((unsigned int)282515631ULL),((unsigned int)823439998ULL),((unsigned int)2287395795ULL),((unsigned int)2143878703ULL),((unsigned int)659862196ULL),((unsigned int)341833635ULL),((unsigned int)3841733234ULL),((unsigned int)1182819740ULL)};
unsigned int b_0[16]={((unsigned int)3538857472ULL),((unsigned int)2132819277ULL),((unsigned int)3666365069ULL),((unsigned int)3733798682ULL),((unsigned int)16503559ULL),((unsigned int)823164414ULL),((unsigned int)2446713010ULL),((unsigned int)1017468049ULL),((unsigned int)282515631ULL),((unsigned int)823439998ULL),((unsigned int)2287395795ULL),((unsigned int)2143878703ULL),((unsigned int)659862196ULL),((unsigned int)341833635ULL),((unsigned int)3841733234ULL),((unsigned int)1182819740ULL)};
unsigned int a_1[4]={((unsigned int)1012223761ULL),((unsigned int)3450788339ULL),((unsigned int)391410924ULL),((unsigned int)3859260567ULL)};
unsigned int b_1[4]={((unsigned int)1012223761ULL),((unsigned int)3450788339ULL),((unsigned int)391410924ULL),((unsigned int)3859260567ULL)};
unsigned int a_2[4]={((unsigned int)426732485ULL),((unsigned int)2103228733ULL),((unsigned int)424458973ULL),((unsigned int)1563265999ULL)};
unsigned int b_2[4]={((unsigned int)426732485ULL),((unsigned int)2103228733ULL),((unsigned int)424458973ULL),((unsigned int)1563265999ULL)};
unsigned int a_3[4]={((unsigned int)699644849ULL),((unsigned int)205477626ULL),((unsigned int)3982893550ULL),((unsigned int)3761879036ULL)};
unsigned int b_3[4]={((unsigned int)699644849ULL),((unsigned int)205477626ULL),((unsigned int)3982893550ULL),((unsigned int)3761879036ULL)};
unsigned int a_4[4]={((unsigned int)253237126ULL),((unsigned int)81977282ULL),((unsigned int)983799346ULL),((unsigned int)17787017ULL)};
unsigned int b_4[4]={((unsigned int)253237126ULL),((unsigned int)81977282ULL),((unsigned int)983799346ULL),((unsigned int)17787017ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 136\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3744535762ULL),((unsigned int)562442343ULL),((unsigned int)2040442223ULL),((unsigned int)4170473927ULL),((unsigned int)1302433690ULL),((unsigned int)3439486876ULL),((unsigned int)503183119ULL),((unsigned int)3124089814ULL),((unsigned int)2473279226ULL),((unsigned int)845612227ULL),((unsigned int)436533665ULL),((unsigned int)3427736043ULL),((unsigned int)1556851098ULL),((unsigned int)413549268ULL),((unsigned int)4055660548ULL),((unsigned int)1068634369ULL)};
unsigned int b_0[16]={((unsigned int)3744535762ULL),((unsigned int)562442343ULL),((unsigned int)2040442223ULL),((unsigned int)4170473927ULL),((unsigned int)1302433690ULL),((unsigned int)3439486876ULL),((unsigned int)503183119ULL),((unsigned int)3124089814ULL),((unsigned int)2473279226ULL),((unsigned int)845612227ULL),((unsigned int)436533665ULL),((unsigned int)3427736043ULL),((unsigned int)1556851098ULL),((unsigned int)413549268ULL),((unsigned int)4055660548ULL),((unsigned int)1068634369ULL)};
unsigned int a_1[4]={((unsigned int)2976539863ULL),((unsigned int)3320630692ULL),((unsigned int)975072820ULL),((unsigned int)2420103510ULL)};
unsigned int b_1[4]={((unsigned int)2976539863ULL),((unsigned int)3320630692ULL),((unsigned int)975072820ULL),((unsigned int)2420103510ULL)};
unsigned int a_2[4]={((unsigned int)1544046488ULL),((unsigned int)4260234700ULL),((unsigned int)711560190ULL),((unsigned int)2080318944ULL)};
unsigned int b_2[4]={((unsigned int)1544046488ULL),((unsigned int)4260234700ULL),((unsigned int)711560190ULL),((unsigned int)2080318944ULL)};
unsigned int a_3[4]={((unsigned int)662482196ULL),((unsigned int)2442829359ULL),((unsigned int)3079314076ULL),((unsigned int)638420924ULL)};
unsigned int b_3[4]={((unsigned int)662482196ULL),((unsigned int)2442829359ULL),((unsigned int)3079314076ULL),((unsigned int)638420924ULL)};
unsigned int a_4[4]={((unsigned int)1569185037ULL),((unsigned int)2281157614ULL),((unsigned int)1320290488ULL),((unsigned int)481034797ULL)};
unsigned int b_4[4]={((unsigned int)1569185037ULL),((unsigned int)2281157614ULL),((unsigned int)1320290488ULL),((unsigned int)481034797ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 137\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)756225200ULL),((unsigned int)1766538606ULL),((unsigned int)839512752ULL),((unsigned int)1150281461ULL),((unsigned int)3617538363ULL),((unsigned int)469797401ULL),((unsigned int)4274330475ULL),((unsigned int)2326412003ULL),((unsigned int)1382656226ULL),((unsigned int)2081564269ULL),((unsigned int)2527203283ULL),((unsigned int)1745578689ULL),((unsigned int)3522826417ULL),((unsigned int)624046472ULL),((unsigned int)1496799627ULL),((unsigned int)2880780865ULL)};
unsigned int b_0[16]={((unsigned int)756225200ULL),((unsigned int)1766538606ULL),((unsigned int)839512752ULL),((unsigned int)1150281461ULL),((unsigned int)3617538363ULL),((unsigned int)469797401ULL),((unsigned int)4274330475ULL),((unsigned int)2326412003ULL),((unsigned int)1382656226ULL),((unsigned int)2081564269ULL),((unsigned int)2527203283ULL),((unsigned int)1745578689ULL),((unsigned int)3522826417ULL),((unsigned int)624046472ULL),((unsigned int)1496799627ULL),((unsigned int)2880780865ULL)};
unsigned int a_1[4]={((unsigned int)874378064ULL),((unsigned int)1453599230ULL),((unsigned int)3465525032ULL),((unsigned int)838954986ULL)};
unsigned int b_1[4]={((unsigned int)874378064ULL),((unsigned int)1453599230ULL),((unsigned int)3465525032ULL),((unsigned int)838954986ULL)};
unsigned int a_2[4]={((unsigned int)2911875554ULL),((unsigned int)486689723ULL),((unsigned int)290259130ULL),((unsigned int)4047324216ULL)};
unsigned int b_2[4]={((unsigned int)2911875554ULL),((unsigned int)486689723ULL),((unsigned int)290259130ULL),((unsigned int)4047324216ULL)};
unsigned int a_3[4]={((unsigned int)2469992673ULL),((unsigned int)4163000304ULL),((unsigned int)1052835686ULL),((unsigned int)3413727533ULL)};
unsigned int b_3[4]={((unsigned int)2469992673ULL),((unsigned int)4163000304ULL),((unsigned int)1052835686ULL),((unsigned int)3413727533ULL)};
unsigned int a_4[4]={((unsigned int)3518352884ULL),((unsigned int)1972196253ULL),((unsigned int)656178242ULL),((unsigned int)4029468630ULL)};
unsigned int b_4[4]={((unsigned int)3518352884ULL),((unsigned int)1972196253ULL),((unsigned int)656178242ULL),((unsigned int)4029468630ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 138\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4095042548ULL),((unsigned int)1539516982ULL),((unsigned int)3835904840ULL),((unsigned int)2202558382ULL),((unsigned int)2891178535ULL),((unsigned int)3118067947ULL),((unsigned int)204034784ULL),((unsigned int)945676096ULL),((unsigned int)2740821854ULL),((unsigned int)1329019356ULL),((unsigned int)1833618375ULL),((unsigned int)1022297482ULL),((unsigned int)4282798757ULL),((unsigned int)519875912ULL),((unsigned int)2318811928ULL),((unsigned int)730758694ULL)};
unsigned int b_0[16]={((unsigned int)4095042548ULL),((unsigned int)1539516982ULL),((unsigned int)3835904840ULL),((unsigned int)2202558382ULL),((unsigned int)2891178535ULL),((unsigned int)3118067947ULL),((unsigned int)204034784ULL),((unsigned int)945676096ULL),((unsigned int)2740821854ULL),((unsigned int)1329019356ULL),((unsigned int)1833618375ULL),((unsigned int)1022297482ULL),((unsigned int)4282798757ULL),((unsigned int)519875912ULL),((unsigned int)2318811928ULL),((unsigned int)730758694ULL)};
unsigned int a_1[4]={((unsigned int)4174383831ULL),((unsigned int)3942131822ULL),((unsigned int)2737662516ULL),((unsigned int)889623130ULL)};
unsigned int b_1[4]={((unsigned int)4174383831ULL),((unsigned int)3942131822ULL),((unsigned int)2737662516ULL),((unsigned int)889623130ULL)};
unsigned int a_2[4]={((unsigned int)35704960ULL),((unsigned int)2348711881ULL),((unsigned int)222682432ULL),((unsigned int)2895675534ULL)};
unsigned int b_2[4]={((unsigned int)35704960ULL),((unsigned int)2348711881ULL),((unsigned int)222682432ULL),((unsigned int)2895675534ULL)};
unsigned int a_3[4]={((unsigned int)2616138055ULL),((unsigned int)1292080138ULL),((unsigned int)594251343ULL),((unsigned int)143995980ULL)};
unsigned int b_3[4]={((unsigned int)2616138055ULL),((unsigned int)1292080138ULL),((unsigned int)594251343ULL),((unsigned int)143995980ULL)};
unsigned int a_4[4]={((unsigned int)2349916740ULL),((unsigned int)1517968824ULL),((unsigned int)2268951174ULL),((unsigned int)4010210496ULL)};
unsigned int b_4[4]={((unsigned int)2349916740ULL),((unsigned int)1517968824ULL),((unsigned int)2268951174ULL),((unsigned int)4010210496ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 139\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)580312564ULL),((unsigned int)206234998ULL),((unsigned int)58246148ULL),((unsigned int)1514362422ULL),((unsigned int)1957280753ULL),((unsigned int)2175071669ULL),((unsigned int)1022359796ULL),((unsigned int)763240037ULL),((unsigned int)2392959018ULL),((unsigned int)3292226919ULL),((unsigned int)538935988ULL),((unsigned int)3593570366ULL),((unsigned int)398993162ULL),((unsigned int)455427969ULL),((unsigned int)4208845091ULL),((unsigned int)1469905153ULL)};
unsigned int b_0[16]={((unsigned int)580312564ULL),((unsigned int)206234998ULL),((unsigned int)58246148ULL),((unsigned int)1514362422ULL),((unsigned int)1957280753ULL),((unsigned int)2175071669ULL),((unsigned int)1022359796ULL),((unsigned int)763240037ULL),((unsigned int)2392959018ULL),((unsigned int)3292226919ULL),((unsigned int)538935988ULL),((unsigned int)3593570366ULL),((unsigned int)398993162ULL),((unsigned int)455427969ULL),((unsigned int)4208845091ULL),((unsigned int)1469905153ULL)};
unsigned int a_1[4]={((unsigned int)1343426228ULL),((unsigned int)744588131ULL),((unsigned int)908223057ULL),((unsigned int)3246368341ULL)};
unsigned int b_1[4]={((unsigned int)1343426228ULL),((unsigned int)744588131ULL),((unsigned int)908223057ULL),((unsigned int)3246368341ULL)};
unsigned int a_2[4]={((unsigned int)400808395ULL),((unsigned int)1881161767ULL),((unsigned int)2361833027ULL),((unsigned int)292719024ULL)};
unsigned int b_2[4]={((unsigned int)400808395ULL),((unsigned int)1881161767ULL),((unsigned int)2361833027ULL),((unsigned int)292719024ULL)};
unsigned int a_3[4]={((unsigned int)3868517805ULL),((unsigned int)3449596417ULL),((unsigned int)2811893358ULL),((unsigned int)2464625269ULL)};
unsigned int b_3[4]={((unsigned int)3868517805ULL),((unsigned int)3449596417ULL),((unsigned int)2811893358ULL),((unsigned int)2464625269ULL)};
unsigned int a_4[4]={((unsigned int)2505827426ULL),((unsigned int)1525370769ULL),((unsigned int)2063442032ULL),((unsigned int)290966790ULL)};
unsigned int b_4[4]={((unsigned int)2505827426ULL),((unsigned int)1525370769ULL),((unsigned int)2063442032ULL),((unsigned int)290966790ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 140\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3911611274ULL),((unsigned int)1675507973ULL),((unsigned int)1446222741ULL),((unsigned int)2429719953ULL),((unsigned int)2781161180ULL),((unsigned int)2665453781ULL),((unsigned int)1409661567ULL),((unsigned int)384439777ULL),((unsigned int)2833496015ULL),((unsigned int)306175794ULL),((unsigned int)1343398717ULL),((unsigned int)2110246818ULL),((unsigned int)2941078041ULL),((unsigned int)3530942411ULL),((unsigned int)3705478942ULL),((unsigned int)123208681ULL)};
unsigned int b_0[16]={((unsigned int)3911611274ULL),((unsigned int)1675507973ULL),((unsigned int)1446222741ULL),((unsigned int)2429719953ULL),((unsigned int)2781161180ULL),((unsigned int)2665453781ULL),((unsigned int)1409661567ULL),((unsigned int)384439777ULL),((unsigned int)2833496015ULL),((unsigned int)306175794ULL),((unsigned int)1343398717ULL),((unsigned int)2110246818ULL),((unsigned int)2941078041ULL),((unsigned int)3530942411ULL),((unsigned int)3705478942ULL),((unsigned int)123208681ULL)};
unsigned int a_1[4]={((unsigned int)582634040ULL),((unsigned int)3661674131ULL),((unsigned int)4124880293ULL),((unsigned int)3449226611ULL)};
unsigned int b_1[4]={((unsigned int)582634040ULL),((unsigned int)3661674131ULL),((unsigned int)4124880293ULL),((unsigned int)3449226611ULL)};
unsigned int a_2[4]={((unsigned int)906833145ULL),((unsigned int)4206236152ULL),((unsigned int)2798066868ULL),((unsigned int)4050680288ULL)};
unsigned int b_2[4]={((unsigned int)906833145ULL),((unsigned int)4206236152ULL),((unsigned int)2798066868ULL),((unsigned int)4050680288ULL)};
unsigned int a_3[4]={((unsigned int)4115699182ULL),((unsigned int)2016487350ULL),((unsigned int)3170951355ULL),((unsigned int)1751797041ULL)};
unsigned int b_3[4]={((unsigned int)4115699182ULL),((unsigned int)2016487350ULL),((unsigned int)3170951355ULL),((unsigned int)1751797041ULL)};
unsigned int a_4[4]={((unsigned int)854112580ULL),((unsigned int)1937948630ULL),((unsigned int)88091898ULL),((unsigned int)2873504906ULL)};
unsigned int b_4[4]={((unsigned int)854112580ULL),((unsigned int)1937948630ULL),((unsigned int)88091898ULL),((unsigned int)2873504906ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 141\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1999411563ULL),((unsigned int)1992080093ULL),((unsigned int)537325963ULL),((unsigned int)752530129ULL),((unsigned int)1622545823ULL),((unsigned int)2715127103ULL),((unsigned int)2932742543ULL),((unsigned int)141618276ULL),((unsigned int)2582254901ULL),((unsigned int)1076379070ULL),((unsigned int)2252782792ULL),((unsigned int)1703535428ULL),((unsigned int)4049586211ULL),((unsigned int)2901202291ULL),((unsigned int)4105397957ULL),((unsigned int)3926867364ULL)};
unsigned int b_0[16]={((unsigned int)1999411563ULL),((unsigned int)1992080093ULL),((unsigned int)537325963ULL),((unsigned int)752530129ULL),((unsigned int)1622545823ULL),((unsigned int)2715127103ULL),((unsigned int)2932742543ULL),((unsigned int)141618276ULL),((unsigned int)2582254901ULL),((unsigned int)1076379070ULL),((unsigned int)2252782792ULL),((unsigned int)1703535428ULL),((unsigned int)4049586211ULL),((unsigned int)2901202291ULL),((unsigned int)4105397957ULL),((unsigned int)3926867364ULL)};
unsigned int a_1[4]={((unsigned int)2299036110ULL),((unsigned int)2297510478ULL),((unsigned int)155618343ULL),((unsigned int)1814974227ULL)};
unsigned int b_1[4]={((unsigned int)2299036110ULL),((unsigned int)2297510478ULL),((unsigned int)155618343ULL),((unsigned int)1814974227ULL)};
unsigned int a_2[4]={((unsigned int)3468771991ULL),((unsigned int)2505758233ULL),((unsigned int)987999483ULL),((unsigned int)3450749690ULL)};
unsigned int b_2[4]={((unsigned int)3468771991ULL),((unsigned int)2505758233ULL),((unsigned int)987999483ULL),((unsigned int)3450749690ULL)};
unsigned int a_3[4]={((unsigned int)2312003191ULL),((unsigned int)1652321391ULL),((unsigned int)2870507922ULL),((unsigned int)1880666667ULL)};
unsigned int b_3[4]={((unsigned int)2312003191ULL),((unsigned int)1652321391ULL),((unsigned int)2870507922ULL),((unsigned int)1880666667ULL)};
unsigned int a_4[4]={((unsigned int)275998620ULL),((unsigned int)2400774501ULL),((unsigned int)523891869ULL),((unsigned int)1157671764ULL)};
unsigned int b_4[4]={((unsigned int)275998620ULL),((unsigned int)2400774501ULL),((unsigned int)523891869ULL),((unsigned int)1157671764ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 142\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2602960192ULL),((unsigned int)2529765342ULL),((unsigned int)1649987392ULL),((unsigned int)2093106333ULL),((unsigned int)1236427883ULL),((unsigned int)848693842ULL),((unsigned int)1560177566ULL),((unsigned int)2864636699ULL),((unsigned int)2776192292ULL),((unsigned int)3412656043ULL),((unsigned int)3854244072ULL),((unsigned int)3370535273ULL),((unsigned int)3718344559ULL),((unsigned int)1955762824ULL),((unsigned int)2143028149ULL),((unsigned int)253346511ULL)};
unsigned int b_0[16]={((unsigned int)2602960192ULL),((unsigned int)2529765342ULL),((unsigned int)1649987392ULL),((unsigned int)2093106333ULL),((unsigned int)1236427883ULL),((unsigned int)848693842ULL),((unsigned int)1560177566ULL),((unsigned int)2864636699ULL),((unsigned int)2776192292ULL),((unsigned int)3412656043ULL),((unsigned int)3854244072ULL),((unsigned int)3370535273ULL),((unsigned int)3718344559ULL),((unsigned int)1955762824ULL),((unsigned int)2143028149ULL),((unsigned int)253346511ULL)};
unsigned int a_1[4]={((unsigned int)2275944274ULL),((unsigned int)375190810ULL),((unsigned int)1461555866ULL),((unsigned int)1984619648ULL)};
unsigned int b_1[4]={((unsigned int)2275944274ULL),((unsigned int)375190810ULL),((unsigned int)1461555866ULL),((unsigned int)1984619648ULL)};
unsigned int a_2[4]={((unsigned int)4230108101ULL),((unsigned int)1367757964ULL),((unsigned int)1380624997ULL),((unsigned int)729276088ULL)};
unsigned int b_2[4]={((unsigned int)4230108101ULL),((unsigned int)1367757964ULL),((unsigned int)1380624997ULL),((unsigned int)729276088ULL)};
unsigned int a_3[4]={((unsigned int)1067297402ULL),((unsigned int)2103176507ULL),((unsigned int)1596069522ULL),((unsigned int)4024524796ULL)};
unsigned int b_3[4]={((unsigned int)1067297402ULL),((unsigned int)2103176507ULL),((unsigned int)1596069522ULL),((unsigned int)4024524796ULL)};
unsigned int a_4[4]={((unsigned int)130082652ULL),((unsigned int)1247913742ULL),((unsigned int)413868101ULL),((unsigned int)3743206289ULL)};
unsigned int b_4[4]={((unsigned int)130082652ULL),((unsigned int)1247913742ULL),((unsigned int)413868101ULL),((unsigned int)3743206289ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 143\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)25388192ULL),((unsigned int)2348891696ULL),((unsigned int)277426928ULL),((unsigned int)469258234ULL),((unsigned int)171661083ULL),((unsigned int)875209695ULL),((unsigned int)3427018362ULL),((unsigned int)4126994619ULL),((unsigned int)3981243860ULL),((unsigned int)748471175ULL),((unsigned int)1018257299ULL),((unsigned int)2545335094ULL),((unsigned int)3878933482ULL),((unsigned int)327338415ULL),((unsigned int)876881190ULL),((unsigned int)835672506ULL)};
unsigned int b_0[16]={((unsigned int)25388192ULL),((unsigned int)2348891696ULL),((unsigned int)277426928ULL),((unsigned int)469258234ULL),((unsigned int)171661083ULL),((unsigned int)875209695ULL),((unsigned int)3427018362ULL),((unsigned int)4126994619ULL),((unsigned int)3981243860ULL),((unsigned int)748471175ULL),((unsigned int)1018257299ULL),((unsigned int)2545335094ULL),((unsigned int)3878933482ULL),((unsigned int)327338415ULL),((unsigned int)876881190ULL),((unsigned int)835672506ULL)};
unsigned int a_1[4]={((unsigned int)402038189ULL),((unsigned int)2235714087ULL),((unsigned int)1948123180ULL),((unsigned int)119344796ULL)};
unsigned int b_1[4]={((unsigned int)402038189ULL),((unsigned int)2235714087ULL),((unsigned int)1948123180ULL),((unsigned int)119344796ULL)};
unsigned int a_2[4]={((unsigned int)2346986410ULL),((unsigned int)2950771268ULL),((unsigned int)3522744102ULL),((unsigned int)4197564990ULL)};
unsigned int b_2[4]={((unsigned int)2346986410ULL),((unsigned int)2950771268ULL),((unsigned int)3522744102ULL),((unsigned int)4197564990ULL)};
unsigned int a_3[4]={((unsigned int)3638365153ULL),((unsigned int)2311994803ULL),((unsigned int)3086621829ULL),((unsigned int)828357464ULL)};
unsigned int b_3[4]={((unsigned int)3638365153ULL),((unsigned int)2311994803ULL),((unsigned int)3086621829ULL),((unsigned int)828357464ULL)};
unsigned int a_4[4]={((unsigned int)2436756165ULL),((unsigned int)2117729797ULL),((unsigned int)3384912988ULL),((unsigned int)2370184299ULL)};
unsigned int b_4[4]={((unsigned int)2436756165ULL),((unsigned int)2117729797ULL),((unsigned int)3384912988ULL),((unsigned int)2370184299ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 144\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4036584756ULL),((unsigned int)3893247608ULL),((unsigned int)3893596659ULL),((unsigned int)3387533491ULL),((unsigned int)1574890470ULL),((unsigned int)2841052174ULL),((unsigned int)3029488854ULL),((unsigned int)4080957521ULL),((unsigned int)2329308517ULL),((unsigned int)1065853586ULL),((unsigned int)550393317ULL),((unsigned int)938093925ULL),((unsigned int)157089631ULL),((unsigned int)3410241655ULL),((unsigned int)2924079102ULL),((unsigned int)272607688ULL)};
unsigned int b_0[16]={((unsigned int)4036584756ULL),((unsigned int)3893247608ULL),((unsigned int)3893596659ULL),((unsigned int)3387533491ULL),((unsigned int)1574890470ULL),((unsigned int)2841052174ULL),((unsigned int)3029488854ULL),((unsigned int)4080957521ULL),((unsigned int)2329308517ULL),((unsigned int)1065853586ULL),((unsigned int)550393317ULL),((unsigned int)938093925ULL),((unsigned int)157089631ULL),((unsigned int)3410241655ULL),((unsigned int)2924079102ULL),((unsigned int)272607688ULL)};
unsigned int a_1[4]={((unsigned int)1069836741ULL),((unsigned int)35369375ULL),((unsigned int)1532469717ULL),((unsigned int)2232251491ULL)};
unsigned int b_1[4]={((unsigned int)1069836741ULL),((unsigned int)35369375ULL),((unsigned int)1532469717ULL),((unsigned int)2232251491ULL)};
unsigned int a_2[4]={((unsigned int)2790281257ULL),((unsigned int)1836438263ULL),((unsigned int)3921530996ULL),((unsigned int)3299918494ULL)};
unsigned int b_2[4]={((unsigned int)2790281257ULL),((unsigned int)1836438263ULL),((unsigned int)3921530996ULL),((unsigned int)3299918494ULL)};
unsigned int a_3[4]={((unsigned int)583387389ULL),((unsigned int)2673036631ULL),((unsigned int)1351473588ULL),((unsigned int)3701756581ULL)};
unsigned int b_3[4]={((unsigned int)583387389ULL),((unsigned int)2673036631ULL),((unsigned int)1351473588ULL),((unsigned int)3701756581ULL)};
unsigned int a_4[4]={((unsigned int)1400070384ULL),((unsigned int)570462900ULL),((unsigned int)1712964748ULL),((unsigned int)4238159122ULL)};
unsigned int b_4[4]={((unsigned int)1400070384ULL),((unsigned int)570462900ULL),((unsigned int)1712964748ULL),((unsigned int)4238159122ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 145\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2232541906ULL),((unsigned int)2286740519ULL),((unsigned int)1863810528ULL),((unsigned int)2666917738ULL),((unsigned int)1740634329ULL),((unsigned int)1311063715ULL),((unsigned int)4099218305ULL),((unsigned int)52912552ULL),((unsigned int)2481070262ULL),((unsigned int)3808489502ULL),((unsigned int)2037276337ULL),((unsigned int)3097074061ULL),((unsigned int)3232267297ULL),((unsigned int)3178051225ULL),((unsigned int)2000481769ULL),((unsigned int)3621539342ULL)};
unsigned int b_0[16]={((unsigned int)2232541906ULL),((unsigned int)2286740519ULL),((unsigned int)1863810528ULL),((unsigned int)2666917738ULL),((unsigned int)1740634329ULL),((unsigned int)1311063715ULL),((unsigned int)4099218305ULL),((unsigned int)52912552ULL),((unsigned int)2481070262ULL),((unsigned int)3808489502ULL),((unsigned int)2037276337ULL),((unsigned int)3097074061ULL),((unsigned int)3232267297ULL),((unsigned int)3178051225ULL),((unsigned int)2000481769ULL),((unsigned int)3621539342ULL)};
unsigned int a_1[4]={((unsigned int)2125222180ULL),((unsigned int)1590995071ULL),((unsigned int)850150121ULL),((unsigned int)4204649260ULL)};
unsigned int b_1[4]={((unsigned int)2125222180ULL),((unsigned int)1590995071ULL),((unsigned int)850150121ULL),((unsigned int)4204649260ULL)};
unsigned int a_2[4]={((unsigned int)1665190351ULL),((unsigned int)1346254687ULL),((unsigned int)3984083453ULL),((unsigned int)3765895791ULL)};
unsigned int b_2[4]={((unsigned int)1665190351ULL),((unsigned int)1346254687ULL),((unsigned int)3984083453ULL),((unsigned int)3765895791ULL)};
unsigned int a_3[4]={((unsigned int)109900495ULL),((unsigned int)168777798ULL),((unsigned int)139888280ULL),((unsigned int)2708649803ULL)};
unsigned int b_3[4]={((unsigned int)109900495ULL),((unsigned int)168777798ULL),((unsigned int)139888280ULL),((unsigned int)2708649803ULL)};
unsigned int a_4[4]={((unsigned int)3512848456ULL),((unsigned int)3519187211ULL),((unsigned int)1921110419ULL),((unsigned int)1965419405ULL)};
unsigned int b_4[4]={((unsigned int)3512848456ULL),((unsigned int)3519187211ULL),((unsigned int)1921110419ULL),((unsigned int)1965419405ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 146\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3204613675ULL),((unsigned int)3708055610ULL),((unsigned int)2202264321ULL),((unsigned int)445114581ULL),((unsigned int)2960128319ULL),((unsigned int)1711137856ULL),((unsigned int)2259076583ULL),((unsigned int)560433598ULL),((unsigned int)446268349ULL),((unsigned int)1073498942ULL),((unsigned int)3674089020ULL),((unsigned int)1616959010ULL),((unsigned int)3187129573ULL),((unsigned int)600430829ULL),((unsigned int)2148562390ULL),((unsigned int)844034919ULL)};
unsigned int b_0[16]={((unsigned int)3204613675ULL),((unsigned int)3708055610ULL),((unsigned int)2202264321ULL),((unsigned int)445114581ULL),((unsigned int)2960128319ULL),((unsigned int)1711137856ULL),((unsigned int)2259076583ULL),((unsigned int)560433598ULL),((unsigned int)446268349ULL),((unsigned int)1073498942ULL),((unsigned int)3674089020ULL),((unsigned int)1616959010ULL),((unsigned int)3187129573ULL),((unsigned int)600430829ULL),((unsigned int)2148562390ULL),((unsigned int)844034919ULL)};
unsigned int a_1[4]={((unsigned int)1376569291ULL),((unsigned int)1057882504ULL),((unsigned int)1617841661ULL),((unsigned int)1773326718ULL)};
unsigned int b_1[4]={((unsigned int)1376569291ULL),((unsigned int)1057882504ULL),((unsigned int)1617841661ULL),((unsigned int)1773326718ULL)};
unsigned int a_2[4]={((unsigned int)3062179261ULL),((unsigned int)4043543502ULL),((unsigned int)3194007344ULL),((unsigned int)929055754ULL)};
unsigned int b_2[4]={((unsigned int)3062179261ULL),((unsigned int)4043543502ULL),((unsigned int)3194007344ULL),((unsigned int)929055754ULL)};
unsigned int a_3[4]={((unsigned int)4077877418ULL),((unsigned int)2038195001ULL),((unsigned int)1804253516ULL),((unsigned int)1254514227ULL)};
unsigned int b_3[4]={((unsigned int)4077877418ULL),((unsigned int)2038195001ULL),((unsigned int)1804253516ULL),((unsigned int)1254514227ULL)};
unsigned int a_4[4]={((unsigned int)1191197958ULL),((unsigned int)3257781855ULL),((unsigned int)3067884395ULL),((unsigned int)3722831169ULL)};
unsigned int b_4[4]={((unsigned int)1191197958ULL),((unsigned int)3257781855ULL),((unsigned int)3067884395ULL),((unsigned int)3722831169ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 147\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2199807334ULL),((unsigned int)1571311678ULL),((unsigned int)3964861486ULL),((unsigned int)3030795847ULL),((unsigned int)316048406ULL),((unsigned int)2351977776ULL),((unsigned int)2056988702ULL),((unsigned int)1032775748ULL),((unsigned int)1054583571ULL),((unsigned int)2199215041ULL),((unsigned int)3547013305ULL),((unsigned int)1410939144ULL),((unsigned int)1744937162ULL),((unsigned int)1378553766ULL),((unsigned int)125632468ULL),((unsigned int)2071175261ULL)};
unsigned int b_0[16]={((unsigned int)2199807334ULL),((unsigned int)1571311678ULL),((unsigned int)3964861486ULL),((unsigned int)3030795847ULL),((unsigned int)316048406ULL),((unsigned int)2351977776ULL),((unsigned int)2056988702ULL),((unsigned int)1032775748ULL),((unsigned int)1054583571ULL),((unsigned int)2199215041ULL),((unsigned int)3547013305ULL),((unsigned int)1410939144ULL),((unsigned int)1744937162ULL),((unsigned int)1378553766ULL),((unsigned int)125632468ULL),((unsigned int)2071175261ULL)};
unsigned int a_1[4]={((unsigned int)3830736122ULL),((unsigned int)2569906116ULL),((unsigned int)3204290279ULL),((unsigned int)1969985902ULL)};
unsigned int b_1[4]={((unsigned int)3830736122ULL),((unsigned int)2569906116ULL),((unsigned int)3204290279ULL),((unsigned int)1969985902ULL)};
unsigned int a_2[4]={((unsigned int)3902627634ULL),((unsigned int)1252799457ULL),((unsigned int)966143294ULL),((unsigned int)1903741758ULL)};
unsigned int b_2[4]={((unsigned int)3902627634ULL),((unsigned int)1252799457ULL),((unsigned int)966143294ULL),((unsigned int)1903741758ULL)};
unsigned int a_3[4]={((unsigned int)4024269894ULL),((unsigned int)3022172898ULL),((unsigned int)3854823625ULL),((unsigned int)546390406ULL)};
unsigned int b_3[4]={((unsigned int)4024269894ULL),((unsigned int)3022172898ULL),((unsigned int)3854823625ULL),((unsigned int)546390406ULL)};
unsigned int a_4[4]={((unsigned int)4176022617ULL),((unsigned int)688402679ULL),((unsigned int)1260069996ULL),((unsigned int)958046654ULL)};
unsigned int b_4[4]={((unsigned int)4176022617ULL),((unsigned int)688402679ULL),((unsigned int)1260069996ULL),((unsigned int)958046654ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 148\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1771901252ULL),((unsigned int)2856893253ULL),((unsigned int)1959515558ULL),((unsigned int)626097477ULL),((unsigned int)598920480ULL),((unsigned int)1087950170ULL),((unsigned int)2979262673ULL),((unsigned int)2941037584ULL),((unsigned int)2694362612ULL),((unsigned int)440345538ULL),((unsigned int)871105352ULL),((unsigned int)2857670735ULL),((unsigned int)1595615930ULL),((unsigned int)2301533095ULL),((unsigned int)2251651832ULL),((unsigned int)1033143894ULL)};
unsigned int b_0[16]={((unsigned int)1771901252ULL),((unsigned int)2856893253ULL),((unsigned int)1959515558ULL),((unsigned int)626097477ULL),((unsigned int)598920480ULL),((unsigned int)1087950170ULL),((unsigned int)2979262673ULL),((unsigned int)2941037584ULL),((unsigned int)2694362612ULL),((unsigned int)440345538ULL),((unsigned int)871105352ULL),((unsigned int)2857670735ULL),((unsigned int)1595615930ULL),((unsigned int)2301533095ULL),((unsigned int)2251651832ULL),((unsigned int)1033143894ULL)};
unsigned int a_1[4]={((unsigned int)3380413623ULL),((unsigned int)2487371585ULL),((unsigned int)3655641476ULL),((unsigned int)2722176618ULL)};
unsigned int b_1[4]={((unsigned int)3380413623ULL),((unsigned int)2487371585ULL),((unsigned int)3655641476ULL),((unsigned int)2722176618ULL)};
unsigned int a_2[4]={((unsigned int)1578124750ULL),((unsigned int)4134070270ULL),((unsigned int)847239472ULL),((unsigned int)844618319ULL)};
unsigned int b_2[4]={((unsigned int)1578124750ULL),((unsigned int)4134070270ULL),((unsigned int)847239472ULL),((unsigned int)844618319ULL)};
unsigned int a_3[4]={((unsigned int)3957768496ULL),((unsigned int)1458365695ULL),((unsigned int)1376026416ULL),((unsigned int)1120826940ULL)};
unsigned int b_3[4]={((unsigned int)3957768496ULL),((unsigned int)1458365695ULL),((unsigned int)1376026416ULL),((unsigned int)1120826940ULL)};
unsigned int a_4[4]={((unsigned int)1035747930ULL),((unsigned int)1161842639ULL),((unsigned int)4219938213ULL),((unsigned int)3251262884ULL)};
unsigned int b_4[4]={((unsigned int)1035747930ULL),((unsigned int)1161842639ULL),((unsigned int)4219938213ULL),((unsigned int)3251262884ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 149\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3616920201ULL),((unsigned int)291982182ULL),((unsigned int)3086079022ULL),((unsigned int)2509510904ULL),((unsigned int)3963975812ULL),((unsigned int)2412892078ULL),((unsigned int)1208242777ULL),((unsigned int)3977100883ULL),((unsigned int)2944038899ULL),((unsigned int)4035966330ULL),((unsigned int)3912456599ULL),((unsigned int)4293778438ULL),((unsigned int)79512321ULL),((unsigned int)3072762954ULL),((unsigned int)4063472467ULL),((unsigned int)840515183ULL)};
unsigned int b_0[16]={((unsigned int)3616920201ULL),((unsigned int)291982182ULL),((unsigned int)3086079022ULL),((unsigned int)2509510904ULL),((unsigned int)3963975812ULL),((unsigned int)2412892078ULL),((unsigned int)1208242777ULL),((unsigned int)3977100883ULL),((unsigned int)2944038899ULL),((unsigned int)4035966330ULL),((unsigned int)3912456599ULL),((unsigned int)4293778438ULL),((unsigned int)79512321ULL),((unsigned int)3072762954ULL),((unsigned int)4063472467ULL),((unsigned int)840515183ULL)};
unsigned int a_1[4]={((unsigned int)2116892837ULL),((unsigned int)2629219579ULL),((unsigned int)2946025140ULL),((unsigned int)3344679737ULL)};
unsigned int b_1[4]={((unsigned int)2116892837ULL),((unsigned int)2629219579ULL),((unsigned int)2946025140ULL),((unsigned int)3344679737ULL)};
unsigned int a_2[4]={((unsigned int)2783488969ULL),((unsigned int)927353129ULL),((unsigned int)3193555158ULL),((unsigned int)4249243163ULL)};
unsigned int b_2[4]={((unsigned int)2783488969ULL),((unsigned int)927353129ULL),((unsigned int)3193555158ULL),((unsigned int)4249243163ULL)};
unsigned int a_3[4]={((unsigned int)2791525246ULL),((unsigned int)2527267166ULL),((unsigned int)3556370549ULL),((unsigned int)719739820ULL)};
unsigned int b_3[4]={((unsigned int)2791525246ULL),((unsigned int)2527267166ULL),((unsigned int)3556370549ULL),((unsigned int)719739820ULL)};
unsigned int a_4[4]={((unsigned int)2863943974ULL),((unsigned int)4216464933ULL),((unsigned int)394644625ULL),((unsigned int)799524740ULL)};
unsigned int b_4[4]={((unsigned int)2863943974ULL),((unsigned int)4216464933ULL),((unsigned int)394644625ULL),((unsigned int)799524740ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 150\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3343655565ULL),((unsigned int)3093764442ULL),((unsigned int)1148137924ULL),((unsigned int)967708232ULL),((unsigned int)1112672696ULL),((unsigned int)618069693ULL),((unsigned int)2576454811ULL),((unsigned int)2959242397ULL),((unsigned int)2354080594ULL),((unsigned int)2068777452ULL),((unsigned int)3736893739ULL),((unsigned int)2649324155ULL),((unsigned int)4251379465ULL),((unsigned int)1973115703ULL),((unsigned int)239615420ULL),((unsigned int)3139842346ULL)};
unsigned int b_0[16]={((unsigned int)3343655565ULL),((unsigned int)3093764442ULL),((unsigned int)1148137924ULL),((unsigned int)967708232ULL),((unsigned int)1112672696ULL),((unsigned int)618069693ULL),((unsigned int)2576454811ULL),((unsigned int)2959242397ULL),((unsigned int)2354080594ULL),((unsigned int)2068777452ULL),((unsigned int)3736893739ULL),((unsigned int)2649324155ULL),((unsigned int)4251379465ULL),((unsigned int)1973115703ULL),((unsigned int)239615420ULL),((unsigned int)3139842346ULL)};
unsigned int a_1[4]={((unsigned int)3076570155ULL),((unsigned int)1849301526ULL),((unsigned int)334734081ULL),((unsigned int)2447876206ULL)};
unsigned int b_1[4]={((unsigned int)3076570155ULL),((unsigned int)1849301526ULL),((unsigned int)334734081ULL),((unsigned int)2447876206ULL)};
unsigned int a_2[4]={((unsigned int)2077991639ULL),((unsigned int)3877526169ULL),((unsigned int)2760801465ULL),((unsigned int)224301270ULL)};
unsigned int b_2[4]={((unsigned int)2077991639ULL),((unsigned int)3877526169ULL),((unsigned int)2760801465ULL),((unsigned int)224301270ULL)};
unsigned int a_3[4]={((unsigned int)3766564474ULL),((unsigned int)3553758289ULL),((unsigned int)3871773360ULL),((unsigned int)4187033656ULL)};
unsigned int b_3[4]={((unsigned int)3766564474ULL),((unsigned int)3553758289ULL),((unsigned int)3871773360ULL),((unsigned int)4187033656ULL)};
unsigned int a_4[4]={((unsigned int)612494062ULL),((unsigned int)1411531400ULL),((unsigned int)1101948643ULL),((unsigned int)50333557ULL)};
unsigned int b_4[4]={((unsigned int)612494062ULL),((unsigned int)1411531400ULL),((unsigned int)1101948643ULL),((unsigned int)50333557ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 151\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)244453644ULL),((unsigned int)380560647ULL),((unsigned int)3120861886ULL),((unsigned int)811677049ULL),((unsigned int)4014970649ULL),((unsigned int)1845264612ULL),((unsigned int)179623666ULL),((unsigned int)978548087ULL),((unsigned int)429991263ULL),((unsigned int)2007277468ULL),((unsigned int)1039425727ULL),((unsigned int)2609310017ULL),((unsigned int)904487385ULL),((unsigned int)812986230ULL),((unsigned int)2227717509ULL),((unsigned int)1045092501ULL)};
unsigned int b_0[16]={((unsigned int)244453644ULL),((unsigned int)380560647ULL),((unsigned int)3120861886ULL),((unsigned int)811677049ULL),((unsigned int)4014970649ULL),((unsigned int)1845264612ULL),((unsigned int)179623666ULL),((unsigned int)978548087ULL),((unsigned int)429991263ULL),((unsigned int)2007277468ULL),((unsigned int)1039425727ULL),((unsigned int)2609310017ULL),((unsigned int)904487385ULL),((unsigned int)812986230ULL),((unsigned int)2227717509ULL),((unsigned int)1045092501ULL)};
unsigned int a_1[4]={((unsigned int)2318103763ULL),((unsigned int)2410672766ULL),((unsigned int)2744778083ULL),((unsigned int)3662909152ULL)};
unsigned int b_1[4]={((unsigned int)2318103763ULL),((unsigned int)2410672766ULL),((unsigned int)2744778083ULL),((unsigned int)3662909152ULL)};
unsigned int a_2[4]={((unsigned int)2868729457ULL),((unsigned int)2106833194ULL),((unsigned int)1715497941ULL),((unsigned int)1882902433ULL)};
unsigned int b_2[4]={((unsigned int)2868729457ULL),((unsigned int)2106833194ULL),((unsigned int)1715497941ULL),((unsigned int)1882902433ULL)};
unsigned int a_3[4]={((unsigned int)731248651ULL),((unsigned int)2947204533ULL),((unsigned int)4169359268ULL),((unsigned int)2269054447ULL)};
unsigned int b_3[4]={((unsigned int)731248651ULL),((unsigned int)2947204533ULL),((unsigned int)4169359268ULL),((unsigned int)2269054447ULL)};
unsigned int a_4[4]={((unsigned int)827244313ULL),((unsigned int)1711282959ULL),((unsigned int)862878529ULL),((unsigned int)2845733309ULL)};
unsigned int b_4[4]={((unsigned int)827244313ULL),((unsigned int)1711282959ULL),((unsigned int)862878529ULL),((unsigned int)2845733309ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 152\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)974130580ULL),((unsigned int)2823218329ULL),((unsigned int)246335274ULL),((unsigned int)162357451ULL),((unsigned int)2894650360ULL),((unsigned int)3941553556ULL),((unsigned int)3333043811ULL),((unsigned int)2206903661ULL),((unsigned int)1143420002ULL),((unsigned int)3320032261ULL),((unsigned int)497425564ULL),((unsigned int)2970319581ULL),((unsigned int)346733869ULL),((unsigned int)2202714748ULL),((unsigned int)771748973ULL),((unsigned int)994208731ULL)};
unsigned int b_0[16]={((unsigned int)974130580ULL),((unsigned int)2823218329ULL),((unsigned int)246335274ULL),((unsigned int)162357451ULL),((unsigned int)2894650360ULL),((unsigned int)3941553556ULL),((unsigned int)3333043811ULL),((unsigned int)2206903661ULL),((unsigned int)1143420002ULL),((unsigned int)3320032261ULL),((unsigned int)497425564ULL),((unsigned int)2970319581ULL),((unsigned int)346733869ULL),((unsigned int)2202714748ULL),((unsigned int)771748973ULL),((unsigned int)994208731ULL)};
unsigned int a_1[4]={((unsigned int)1030938620ULL),((unsigned int)629624936ULL),((unsigned int)384239835ULL),((unsigned int)285237221ULL)};
unsigned int b_1[4]={((unsigned int)1030938620ULL),((unsigned int)629624936ULL),((unsigned int)384239835ULL),((unsigned int)285237221ULL)};
unsigned int a_2[4]={((unsigned int)507251019ULL),((unsigned int)2378617163ULL),((unsigned int)1685384471ULL),((unsigned int)2933411264ULL)};
unsigned int b_2[4]={((unsigned int)507251019ULL),((unsigned int)2378617163ULL),((unsigned int)1685384471ULL),((unsigned int)2933411264ULL)};
unsigned int a_3[4]={((unsigned int)1458728046ULL),((unsigned int)276418009ULL),((unsigned int)1319892463ULL),((unsigned int)2247191612ULL)};
unsigned int b_3[4]={((unsigned int)1458728046ULL),((unsigned int)276418009ULL),((unsigned int)1319892463ULL),((unsigned int)2247191612ULL)};
unsigned int a_4[4]={((unsigned int)3989927ULL),((unsigned int)1981983795ULL),((unsigned int)385451122ULL),((unsigned int)657634439ULL)};
unsigned int b_4[4]={((unsigned int)3989927ULL),((unsigned int)1981983795ULL),((unsigned int)385451122ULL),((unsigned int)657634439ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 153\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3258711741ULL),((unsigned int)2526894130ULL),((unsigned int)3463984937ULL),((unsigned int)3935075074ULL),((unsigned int)653627670ULL),((unsigned int)2316670986ULL),((unsigned int)3610786447ULL),((unsigned int)2504498559ULL),((unsigned int)2789664071ULL),((unsigned int)2925988279ULL),((unsigned int)433561979ULL),((unsigned int)3189600687ULL),((unsigned int)71974798ULL),((unsigned int)1633859368ULL),((unsigned int)3798413261ULL),((unsigned int)897496884ULL)};
unsigned int b_0[16]={((unsigned int)3258711741ULL),((unsigned int)2526894130ULL),((unsigned int)3463984937ULL),((unsigned int)3935075074ULL),((unsigned int)653627670ULL),((unsigned int)2316670986ULL),((unsigned int)3610786447ULL),((unsigned int)2504498559ULL),((unsigned int)2789664071ULL),((unsigned int)2925988279ULL),((unsigned int)433561979ULL),((unsigned int)3189600687ULL),((unsigned int)71974798ULL),((unsigned int)1633859368ULL),((unsigned int)3798413261ULL),((unsigned int)897496884ULL)};
unsigned int a_1[4]={((unsigned int)1123355821ULL),((unsigned int)806817165ULL),((unsigned int)436582804ULL),((unsigned int)4069858890ULL)};
unsigned int b_1[4]={((unsigned int)1123355821ULL),((unsigned int)806817165ULL),((unsigned int)436582804ULL),((unsigned int)4069858890ULL)};
unsigned int a_2[4]={((unsigned int)1993304904ULL),((unsigned int)3030676192ULL),((unsigned int)451088323ULL),((unsigned int)2219360593ULL)};
unsigned int b_2[4]={((unsigned int)1993304904ULL),((unsigned int)3030676192ULL),((unsigned int)451088323ULL),((unsigned int)2219360593ULL)};
unsigned int a_3[4]={((unsigned int)3072455345ULL),((unsigned int)510439499ULL),((unsigned int)779154030ULL),((unsigned int)4222390436ULL)};
unsigned int b_3[4]={((unsigned int)3072455345ULL),((unsigned int)510439499ULL),((unsigned int)779154030ULL),((unsigned int)4222390436ULL)};
unsigned int a_4[4]={((unsigned int)2937261121ULL),((unsigned int)3624283773ULL),((unsigned int)2820557886ULL),((unsigned int)1804598523ULL)};
unsigned int b_4[4]={((unsigned int)2937261121ULL),((unsigned int)3624283773ULL),((unsigned int)2820557886ULL),((unsigned int)1804598523ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 154\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)341343058ULL),((unsigned int)1346929421ULL),((unsigned int)1579433188ULL),((unsigned int)1344254796ULL),((unsigned int)194309056ULL),((unsigned int)4154518274ULL),((unsigned int)2818754291ULL),((unsigned int)3956712354ULL),((unsigned int)2992069291ULL),((unsigned int)2011842269ULL),((unsigned int)3793341998ULL),((unsigned int)439602305ULL),((unsigned int)396297361ULL),((unsigned int)4170078567ULL),((unsigned int)2227103068ULL),((unsigned int)2813103139ULL)};
unsigned int b_0[16]={((unsigned int)341343058ULL),((unsigned int)1346929421ULL),((unsigned int)1579433188ULL),((unsigned int)1344254796ULL),((unsigned int)194309056ULL),((unsigned int)4154518274ULL),((unsigned int)2818754291ULL),((unsigned int)3956712354ULL),((unsigned int)2992069291ULL),((unsigned int)2011842269ULL),((unsigned int)3793341998ULL),((unsigned int)439602305ULL),((unsigned int)396297361ULL),((unsigned int)4170078567ULL),((unsigned int)2227103068ULL),((unsigned int)2813103139ULL)};
unsigned int a_1[4]={((unsigned int)374948766ULL),((unsigned int)483836531ULL),((unsigned int)3434693796ULL),((unsigned int)3777987181ULL)};
unsigned int b_1[4]={((unsigned int)374948766ULL),((unsigned int)483836531ULL),((unsigned int)3434693796ULL),((unsigned int)3777987181ULL)};
unsigned int a_2[4]={((unsigned int)3259117173ULL),((unsigned int)2954595848ULL),((unsigned int)3778352166ULL),((unsigned int)1597777097ULL)};
unsigned int b_2[4]={((unsigned int)3259117173ULL),((unsigned int)2954595848ULL),((unsigned int)3778352166ULL),((unsigned int)1597777097ULL)};
unsigned int a_3[4]={((unsigned int)1069630888ULL),((unsigned int)4188832207ULL),((unsigned int)1448122044ULL),((unsigned int)2651055068ULL)};
unsigned int b_3[4]={((unsigned int)1069630888ULL),((unsigned int)4188832207ULL),((unsigned int)1448122044ULL),((unsigned int)2651055068ULL)};
unsigned int a_4[4]={((unsigned int)576511032ULL),((unsigned int)1858034696ULL),((unsigned int)1028252148ULL),((unsigned int)374407680ULL)};
unsigned int b_4[4]={((unsigned int)576511032ULL),((unsigned int)1858034696ULL),((unsigned int)1028252148ULL),((unsigned int)374407680ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 155\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1876463145ULL),((unsigned int)3282827456ULL),((unsigned int)3426561813ULL),((unsigned int)3793805422ULL),((unsigned int)2364961730ULL),((unsigned int)1029611375ULL),((unsigned int)4276342469ULL),((unsigned int)1547093881ULL),((unsigned int)954558008ULL),((unsigned int)3395827426ULL),((unsigned int)1892791218ULL),((unsigned int)2216745685ULL),((unsigned int)3551559272ULL),((unsigned int)1794533325ULL),((unsigned int)1554829537ULL),((unsigned int)751477411ULL)};
unsigned int b_0[16]={((unsigned int)1876463145ULL),((unsigned int)3282827456ULL),((unsigned int)3426561813ULL),((unsigned int)3793805422ULL),((unsigned int)2364961730ULL),((unsigned int)1029611375ULL),((unsigned int)4276342469ULL),((unsigned int)1547093881ULL),((unsigned int)954558008ULL),((unsigned int)3395827426ULL),((unsigned int)1892791218ULL),((unsigned int)2216745685ULL),((unsigned int)3551559272ULL),((unsigned int)1794533325ULL),((unsigned int)1554829537ULL),((unsigned int)751477411ULL)};
unsigned int a_1[4]={((unsigned int)313425160ULL),((unsigned int)225263119ULL),((unsigned int)119865099ULL),((unsigned int)1866422478ULL)};
unsigned int b_1[4]={((unsigned int)313425160ULL),((unsigned int)225263119ULL),((unsigned int)119865099ULL),((unsigned int)1866422478ULL)};
unsigned int a_2[4]={((unsigned int)1437264195ULL),((unsigned int)766217400ULL),((unsigned int)168418620ULL),((unsigned int)3153815392ULL)};
unsigned int b_2[4]={((unsigned int)1437264195ULL),((unsigned int)766217400ULL),((unsigned int)168418620ULL),((unsigned int)3153815392ULL)};
unsigned int a_3[4]={((unsigned int)2291540292ULL),((unsigned int)1527818791ULL),((unsigned int)3880055732ULL),((unsigned int)3825391214ULL)};
unsigned int b_3[4]={((unsigned int)2291540292ULL),((unsigned int)1527818791ULL),((unsigned int)3880055732ULL),((unsigned int)3825391214ULL)};
unsigned int a_4[4]={((unsigned int)3804562174ULL),((unsigned int)1970588868ULL),((unsigned int)3894759004ULL),((unsigned int)1499399545ULL)};
unsigned int b_4[4]={((unsigned int)3804562174ULL),((unsigned int)1970588868ULL),((unsigned int)3894759004ULL),((unsigned int)1499399545ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 156\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3588715953ULL),((unsigned int)324694705ULL),((unsigned int)2584193806ULL),((unsigned int)3315250709ULL),((unsigned int)2499646140ULL),((unsigned int)106009166ULL),((unsigned int)3228621469ULL),((unsigned int)2578460654ULL),((unsigned int)2512092728ULL),((unsigned int)1789354736ULL),((unsigned int)2777907254ULL),((unsigned int)1116646665ULL),((unsigned int)2842652500ULL),((unsigned int)4217764275ULL),((unsigned int)2240697061ULL),((unsigned int)3011841667ULL)};
unsigned int b_0[16]={((unsigned int)3588715953ULL),((unsigned int)324694705ULL),((unsigned int)2584193806ULL),((unsigned int)3315250709ULL),((unsigned int)2499646140ULL),((unsigned int)106009166ULL),((unsigned int)3228621469ULL),((unsigned int)2578460654ULL),((unsigned int)2512092728ULL),((unsigned int)1789354736ULL),((unsigned int)2777907254ULL),((unsigned int)1116646665ULL),((unsigned int)2842652500ULL),((unsigned int)4217764275ULL),((unsigned int)2240697061ULL),((unsigned int)3011841667ULL)};
unsigned int a_1[4]={((unsigned int)174029060ULL),((unsigned int)3155648262ULL),((unsigned int)86659495ULL),((unsigned int)493656647ULL)};
unsigned int b_1[4]={((unsigned int)174029060ULL),((unsigned int)3155648262ULL),((unsigned int)86659495ULL),((unsigned int)493656647ULL)};
unsigned int a_2[4]={((unsigned int)277249941ULL),((unsigned int)1293976050ULL),((unsigned int)1724672343ULL),((unsigned int)2111122739ULL)};
unsigned int b_2[4]={((unsigned int)277249941ULL),((unsigned int)1293976050ULL),((unsigned int)1724672343ULL),((unsigned int)2111122739ULL)};
unsigned int a_3[4]={((unsigned int)2217530215ULL),((unsigned int)1971761912ULL),((unsigned int)833524262ULL),((unsigned int)217398963ULL)};
unsigned int b_3[4]={((unsigned int)2217530215ULL),((unsigned int)1971761912ULL),((unsigned int)833524262ULL),((unsigned int)217398963ULL)};
unsigned int a_4[4]={((unsigned int)402287193ULL),((unsigned int)1776455604ULL),((unsigned int)288298048ULL),((unsigned int)155668381ULL)};
unsigned int b_4[4]={((unsigned int)402287193ULL),((unsigned int)1776455604ULL),((unsigned int)288298048ULL),((unsigned int)155668381ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 157\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2108817036ULL),((unsigned int)1164388259ULL),((unsigned int)4030026056ULL),((unsigned int)1565944970ULL),((unsigned int)841629059ULL),((unsigned int)3722793593ULL),((unsigned int)1606790295ULL),((unsigned int)109258780ULL),((unsigned int)3028758197ULL),((unsigned int)1319595452ULL),((unsigned int)2986731852ULL),((unsigned int)2052391944ULL),((unsigned int)1088051756ULL),((unsigned int)2901697126ULL),((unsigned int)2140896577ULL),((unsigned int)4220573457ULL)};
unsigned int b_0[16]={((unsigned int)2108817036ULL),((unsigned int)1164388259ULL),((unsigned int)4030026056ULL),((unsigned int)1565944970ULL),((unsigned int)841629059ULL),((unsigned int)3722793593ULL),((unsigned int)1606790295ULL),((unsigned int)109258780ULL),((unsigned int)3028758197ULL),((unsigned int)1319595452ULL),((unsigned int)2986731852ULL),((unsigned int)2052391944ULL),((unsigned int)1088051756ULL),((unsigned int)2901697126ULL),((unsigned int)2140896577ULL),((unsigned int)4220573457ULL)};
unsigned int a_1[4]={((unsigned int)510518919ULL),((unsigned int)1297966668ULL),((unsigned int)2183276996ULL),((unsigned int)1884516876ULL)};
unsigned int b_1[4]={((unsigned int)510518919ULL),((unsigned int)1297966668ULL),((unsigned int)2183276996ULL),((unsigned int)1884516876ULL)};
unsigned int a_2[4]={((unsigned int)3961229713ULL),((unsigned int)2379016685ULL),((unsigned int)1395700828ULL),((unsigned int)3943346925ULL)};
unsigned int b_2[4]={((unsigned int)3961229713ULL),((unsigned int)2379016685ULL),((unsigned int)1395700828ULL),((unsigned int)3943346925ULL)};
unsigned int a_3[4]={((unsigned int)1776472553ULL),((unsigned int)3193957572ULL),((unsigned int)1261962715ULL),((unsigned int)3411903363ULL)};
unsigned int b_3[4]={((unsigned int)1776472553ULL),((unsigned int)3193957572ULL),((unsigned int)1261962715ULL),((unsigned int)3411903363ULL)};
unsigned int a_4[4]={((unsigned int)580934676ULL),((unsigned int)871479843ULL),((unsigned int)3897819721ULL),((unsigned int)2146403019ULL)};
unsigned int b_4[4]={((unsigned int)580934676ULL),((unsigned int)871479843ULL),((unsigned int)3897819721ULL),((unsigned int)2146403019ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 158\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1367226154ULL),((unsigned int)1710712481ULL),((unsigned int)2110142406ULL),((unsigned int)3064829186ULL),((unsigned int)3978801055ULL),((unsigned int)1849416901ULL),((unsigned int)1445915319ULL),((unsigned int)444070349ULL),((unsigned int)3824775123ULL),((unsigned int)2578452065ULL),((unsigned int)1187267597ULL),((unsigned int)3890570341ULL),((unsigned int)2218271910ULL),((unsigned int)4293993713ULL),((unsigned int)3534869128ULL),((unsigned int)2958303782ULL)};
unsigned int b_0[16]={((unsigned int)1367226154ULL),((unsigned int)1710712481ULL),((unsigned int)2110142406ULL),((unsigned int)3064829186ULL),((unsigned int)3978801055ULL),((unsigned int)1849416901ULL),((unsigned int)1445915319ULL),((unsigned int)444070349ULL),((unsigned int)3824775123ULL),((unsigned int)2578452065ULL),((unsigned int)1187267597ULL),((unsigned int)3890570341ULL),((unsigned int)2218271910ULL),((unsigned int)4293993713ULL),((unsigned int)3534869128ULL),((unsigned int)2958303782ULL)};
unsigned int a_1[4]={((unsigned int)3246655892ULL),((unsigned int)695544333ULL),((unsigned int)2915549753ULL),((unsigned int)578705074ULL)};
unsigned int b_1[4]={((unsigned int)3246655892ULL),((unsigned int)695544333ULL),((unsigned int)2915549753ULL),((unsigned int)578705074ULL)};
unsigned int a_2[4]={((unsigned int)1229654074ULL),((unsigned int)2661235683ULL),((unsigned int)1623831359ULL),((unsigned int)4178973719ULL)};
unsigned int b_2[4]={((unsigned int)1229654074ULL),((unsigned int)2661235683ULL),((unsigned int)1623831359ULL),((unsigned int)4178973719ULL)};
unsigned int a_3[4]={((unsigned int)1127965805ULL),((unsigned int)571304291ULL),((unsigned int)3454358103ULL),((unsigned int)2611185153ULL)};
unsigned int b_3[4]={((unsigned int)1127965805ULL),((unsigned int)571304291ULL),((unsigned int)3454358103ULL),((unsigned int)2611185153ULL)};
unsigned int a_4[4]={((unsigned int)3893846403ULL),((unsigned int)3500511619ULL),((unsigned int)3095009434ULL),((unsigned int)236109334ULL)};
unsigned int b_4[4]={((unsigned int)3893846403ULL),((unsigned int)3500511619ULL),((unsigned int)3095009434ULL),((unsigned int)236109334ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 159\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4179626955ULL),((unsigned int)1957576973ULL),((unsigned int)2362455655ULL),((unsigned int)2887419398ULL),((unsigned int)1069210158ULL),((unsigned int)3697752282ULL),((unsigned int)3930976596ULL),((unsigned int)2561111022ULL),((unsigned int)212847295ULL),((unsigned int)4051352022ULL),((unsigned int)2954078954ULL),((unsigned int)2714963303ULL),((unsigned int)2418241970ULL),((unsigned int)2909933213ULL),((unsigned int)392051604ULL),((unsigned int)3030137835ULL)};
unsigned int b_0[16]={((unsigned int)4179626955ULL),((unsigned int)1957576973ULL),((unsigned int)2362455655ULL),((unsigned int)2887419398ULL),((unsigned int)1069210158ULL),((unsigned int)3697752282ULL),((unsigned int)3930976596ULL),((unsigned int)2561111022ULL),((unsigned int)212847295ULL),((unsigned int)4051352022ULL),((unsigned int)2954078954ULL),((unsigned int)2714963303ULL),((unsigned int)2418241970ULL),((unsigned int)2909933213ULL),((unsigned int)392051604ULL),((unsigned int)3030137835ULL)};
unsigned int a_1[4]={((unsigned int)4147710672ULL),((unsigned int)3840535656ULL),((unsigned int)716491539ULL),((unsigned int)386526798ULL)};
unsigned int b_1[4]={((unsigned int)4147710672ULL),((unsigned int)3840535656ULL),((unsigned int)716491539ULL),((unsigned int)386526798ULL)};
unsigned int a_2[4]={((unsigned int)3115604848ULL),((unsigned int)924072392ULL),((unsigned int)3450543081ULL),((unsigned int)1445961409ULL)};
unsigned int b_2[4]={((unsigned int)3115604848ULL),((unsigned int)924072392ULL),((unsigned int)3450543081ULL),((unsigned int)1445961409ULL)};
unsigned int a_3[4]={((unsigned int)617740594ULL),((unsigned int)703239483ULL),((unsigned int)2835820933ULL),((unsigned int)1091423570ULL)};
unsigned int b_3[4]={((unsigned int)617740594ULL),((unsigned int)703239483ULL),((unsigned int)2835820933ULL),((unsigned int)1091423570ULL)};
unsigned int a_4[4]={((unsigned int)2692124496ULL),((unsigned int)608076659ULL),((unsigned int)3438995111ULL),((unsigned int)1893167442ULL)};
unsigned int b_4[4]={((unsigned int)2692124496ULL),((unsigned int)608076659ULL),((unsigned int)3438995111ULL),((unsigned int)1893167442ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 160\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1939876451ULL),((unsigned int)3058641940ULL),((unsigned int)178712028ULL),((unsigned int)2897673909ULL),((unsigned int)3168610404ULL),((unsigned int)3893302398ULL),((unsigned int)1559011769ULL),((unsigned int)3596451319ULL),((unsigned int)474254502ULL),((unsigned int)1421727198ULL),((unsigned int)2972043192ULL),((unsigned int)3899030263ULL),((unsigned int)1722666955ULL),((unsigned int)2834558251ULL),((unsigned int)514696213ULL),((unsigned int)626798424ULL)};
unsigned int b_0[16]={((unsigned int)1939876451ULL),((unsigned int)3058641940ULL),((unsigned int)178712028ULL),((unsigned int)2897673909ULL),((unsigned int)3168610404ULL),((unsigned int)3893302398ULL),((unsigned int)1559011769ULL),((unsigned int)3596451319ULL),((unsigned int)474254502ULL),((unsigned int)1421727198ULL),((unsigned int)2972043192ULL),((unsigned int)3899030263ULL),((unsigned int)1722666955ULL),((unsigned int)2834558251ULL),((unsigned int)514696213ULL),((unsigned int)626798424ULL)};
unsigned int a_1[4]={((unsigned int)2985831470ULL),((unsigned int)3986852495ULL),((unsigned int)288174440ULL),((unsigned int)2292041272ULL)};
unsigned int b_1[4]={((unsigned int)2985831470ULL),((unsigned int)3986852495ULL),((unsigned int)288174440ULL),((unsigned int)2292041272ULL)};
unsigned int a_2[4]={((unsigned int)857127930ULL),((unsigned int)2774722434ULL),((unsigned int)313639232ULL),((unsigned int)416383612ULL)};
unsigned int b_2[4]={((unsigned int)857127930ULL),((unsigned int)2774722434ULL),((unsigned int)313639232ULL),((unsigned int)416383612ULL)};
unsigned int a_3[4]={((unsigned int)388219374ULL),((unsigned int)3221637415ULL),((unsigned int)3673193181ULL),((unsigned int)50854966ULL)};
unsigned int b_3[4]={((unsigned int)388219374ULL),((unsigned int)3221637415ULL),((unsigned int)3673193181ULL),((unsigned int)50854966ULL)};
unsigned int a_4[4]={((unsigned int)3872070381ULL),((unsigned int)4024446967ULL),((unsigned int)3454517290ULL),((unsigned int)1123049775ULL)};
unsigned int b_4[4]={((unsigned int)3872070381ULL),((unsigned int)4024446967ULL),((unsigned int)3454517290ULL),((unsigned int)1123049775ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 161\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4017677756ULL),((unsigned int)1230011805ULL),((unsigned int)1640211220ULL),((unsigned int)1048112883ULL),((unsigned int)3319469025ULL),((unsigned int)2215495692ULL),((unsigned int)3774472438ULL),((unsigned int)1408587560ULL),((unsigned int)94620634ULL),((unsigned int)1857344935ULL),((unsigned int)539714127ULL),((unsigned int)3465351365ULL),((unsigned int)3250867083ULL),((unsigned int)1654733467ULL),((unsigned int)4130382949ULL),((unsigned int)4136389052ULL)};
unsigned int b_0[16]={((unsigned int)4017677756ULL),((unsigned int)1230011805ULL),((unsigned int)1640211220ULL),((unsigned int)1048112883ULL),((unsigned int)3319469025ULL),((unsigned int)2215495692ULL),((unsigned int)3774472438ULL),((unsigned int)1408587560ULL),((unsigned int)94620634ULL),((unsigned int)1857344935ULL),((unsigned int)539714127ULL),((unsigned int)3465351365ULL),((unsigned int)3250867083ULL),((unsigned int)1654733467ULL),((unsigned int)4130382949ULL),((unsigned int)4136389052ULL)};
unsigned int a_1[4]={((unsigned int)1948746264ULL),((unsigned int)251475245ULL),((unsigned int)1044850171ULL),((unsigned int)1299925098ULL)};
unsigned int b_1[4]={((unsigned int)1948746264ULL),((unsigned int)251475245ULL),((unsigned int)1044850171ULL),((unsigned int)1299925098ULL)};
unsigned int a_2[4]={((unsigned int)1385346873ULL),((unsigned int)834811905ULL),((unsigned int)3173168924ULL),((unsigned int)4236377873ULL)};
unsigned int b_2[4]={((unsigned int)1385346873ULL),((unsigned int)834811905ULL),((unsigned int)3173168924ULL),((unsigned int)4236377873ULL)};
unsigned int a_3[4]={((unsigned int)3676505517ULL),((unsigned int)3840055633ULL),((unsigned int)828228099ULL),((unsigned int)27530480ULL)};
unsigned int b_3[4]={((unsigned int)3676505517ULL),((unsigned int)3840055633ULL),((unsigned int)828228099ULL),((unsigned int)27530480ULL)};
unsigned int a_4[4]={((unsigned int)3592398767ULL),((unsigned int)1669107990ULL),((unsigned int)1587667916ULL),((unsigned int)3497872509ULL)};
unsigned int b_4[4]={((unsigned int)3592398767ULL),((unsigned int)1669107990ULL),((unsigned int)1587667916ULL),((unsigned int)3497872509ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 162\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)33030009ULL),((unsigned int)1033045892ULL),((unsigned int)3341504086ULL),((unsigned int)204151215ULL),((unsigned int)3718998102ULL),((unsigned int)318901994ULL),((unsigned int)2798760026ULL),((unsigned int)852662638ULL),((unsigned int)1640126631ULL),((unsigned int)3528667639ULL),((unsigned int)2523136060ULL),((unsigned int)1867938351ULL),((unsigned int)3236009591ULL),((unsigned int)869543611ULL),((unsigned int)3620117623ULL),((unsigned int)2283514139ULL)};
unsigned int b_0[16]={((unsigned int)33030009ULL),((unsigned int)1033045892ULL),((unsigned int)3341504086ULL),((unsigned int)204151215ULL),((unsigned int)3718998102ULL),((unsigned int)318901994ULL),((unsigned int)2798760026ULL),((unsigned int)852662638ULL),((unsigned int)1640126631ULL),((unsigned int)3528667639ULL),((unsigned int)2523136060ULL),((unsigned int)1867938351ULL),((unsigned int)3236009591ULL),((unsigned int)869543611ULL),((unsigned int)3620117623ULL),((unsigned int)2283514139ULL)};
unsigned int a_1[4]={((unsigned int)1323880946ULL),((unsigned int)3826763167ULL),((unsigned int)3527054915ULL),((unsigned int)2160127104ULL)};
unsigned int b_1[4]={((unsigned int)1323880946ULL),((unsigned int)3826763167ULL),((unsigned int)3527054915ULL),((unsigned int)2160127104ULL)};
unsigned int a_2[4]={((unsigned int)1023309364ULL),((unsigned int)2224672494ULL),((unsigned int)2792303600ULL),((unsigned int)2827824092ULL)};
unsigned int b_2[4]={((unsigned int)1023309364ULL),((unsigned int)2224672494ULL),((unsigned int)2792303600ULL),((unsigned int)2827824092ULL)};
unsigned int a_3[4]={((unsigned int)2037596905ULL),((unsigned int)543288689ULL),((unsigned int)783985703ULL),((unsigned int)795764045ULL)};
unsigned int b_3[4]={((unsigned int)2037596905ULL),((unsigned int)543288689ULL),((unsigned int)783985703ULL),((unsigned int)795764045ULL)};
unsigned int a_4[4]={((unsigned int)435729388ULL),((unsigned int)2699248961ULL),((unsigned int)734564699ULL),((unsigned int)2103777956ULL)};
unsigned int b_4[4]={((unsigned int)435729388ULL),((unsigned int)2699248961ULL),((unsigned int)734564699ULL),((unsigned int)2103777956ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 163\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)284918451ULL),((unsigned int)3860961408ULL),((unsigned int)1657680062ULL),((unsigned int)3209879054ULL),((unsigned int)1047051142ULL),((unsigned int)3390924781ULL),((unsigned int)3371463550ULL),((unsigned int)3679882853ULL),((unsigned int)1160256411ULL),((unsigned int)2030278697ULL),((unsigned int)573051360ULL),((unsigned int)2174947498ULL),((unsigned int)4065164779ULL),((unsigned int)3183246864ULL),((unsigned int)250392654ULL),((unsigned int)2454482357ULL)};
unsigned int b_0[16]={((unsigned int)284918451ULL),((unsigned int)3860961408ULL),((unsigned int)1657680062ULL),((unsigned int)3209879054ULL),((unsigned int)1047051142ULL),((unsigned int)3390924781ULL),((unsigned int)3371463550ULL),((unsigned int)3679882853ULL),((unsigned int)1160256411ULL),((unsigned int)2030278697ULL),((unsigned int)573051360ULL),((unsigned int)2174947498ULL),((unsigned int)4065164779ULL),((unsigned int)3183246864ULL),((unsigned int)250392654ULL),((unsigned int)2454482357ULL)};
unsigned int a_1[4]={((unsigned int)1718136655ULL),((unsigned int)997625063ULL),((unsigned int)1449354895ULL),((unsigned int)771447093ULL)};
unsigned int b_1[4]={((unsigned int)1718136655ULL),((unsigned int)997625063ULL),((unsigned int)1449354895ULL),((unsigned int)771447093ULL)};
unsigned int a_2[4]={((unsigned int)1783184545ULL),((unsigned int)1330275937ULL),((unsigned int)2416706343ULL),((unsigned int)837135752ULL)};
unsigned int b_2[4]={((unsigned int)1783184545ULL),((unsigned int)1330275937ULL),((unsigned int)2416706343ULL),((unsigned int)837135752ULL)};
unsigned int a_3[4]={((unsigned int)105211290ULL),((unsigned int)2299012800ULL),((unsigned int)1732860539ULL),((unsigned int)3234451189ULL)};
unsigned int b_3[4]={((unsigned int)105211290ULL),((unsigned int)2299012800ULL),((unsigned int)1732860539ULL),((unsigned int)3234451189ULL)};
unsigned int a_4[4]={((unsigned int)3057356448ULL),((unsigned int)3914995085ULL),((unsigned int)71773269ULL),((unsigned int)3864078927ULL)};
unsigned int b_4[4]={((unsigned int)3057356448ULL),((unsigned int)3914995085ULL),((unsigned int)71773269ULL),((unsigned int)3864078927ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 164\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)957931705ULL),((unsigned int)501615732ULL),((unsigned int)3862296148ULL),((unsigned int)1319464981ULL),((unsigned int)2902883176ULL),((unsigned int)3776912234ULL),((unsigned int)2359506366ULL),((unsigned int)150356419ULL),((unsigned int)3978282313ULL),((unsigned int)50790530ULL),((unsigned int)1855057607ULL),((unsigned int)2469119098ULL),((unsigned int)1119680577ULL),((unsigned int)3086232506ULL),((unsigned int)2135190194ULL),((unsigned int)4152036236ULL)};
unsigned int b_0[16]={((unsigned int)957931705ULL),((unsigned int)501615732ULL),((unsigned int)3862296148ULL),((unsigned int)1319464981ULL),((unsigned int)2902883176ULL),((unsigned int)3776912234ULL),((unsigned int)2359506366ULL),((unsigned int)150356419ULL),((unsigned int)3978282313ULL),((unsigned int)50790530ULL),((unsigned int)1855057607ULL),((unsigned int)2469119098ULL),((unsigned int)1119680577ULL),((unsigned int)3086232506ULL),((unsigned int)2135190194ULL),((unsigned int)4152036236ULL)};
unsigned int a_1[4]={((unsigned int)4130512047ULL),((unsigned int)638445975ULL),((unsigned int)1574237619ULL),((unsigned int)3163793796ULL)};
unsigned int b_1[4]={((unsigned int)4130512047ULL),((unsigned int)638445975ULL),((unsigned int)1574237619ULL),((unsigned int)3163793796ULL)};
unsigned int a_2[4]={((unsigned int)1775468969ULL),((unsigned int)3656730448ULL),((unsigned int)222485477ULL),((unsigned int)1733777335ULL)};
unsigned int b_2[4]={((unsigned int)1775468969ULL),((unsigned int)3656730448ULL),((unsigned int)222485477ULL),((unsigned int)1733777335ULL)};
unsigned int a_3[4]={((unsigned int)1391089422ULL),((unsigned int)96777003ULL),((unsigned int)2208330902ULL),((unsigned int)3027801016ULL)};
unsigned int b_3[4]={((unsigned int)1391089422ULL),((unsigned int)96777003ULL),((unsigned int)2208330902ULL),((unsigned int)3027801016ULL)};
unsigned int a_4[4]={((unsigned int)1477747418ULL),((unsigned int)3093070630ULL),((unsigned int)3329864425ULL),((unsigned int)1334859500ULL)};
unsigned int b_4[4]={((unsigned int)1477747418ULL),((unsigned int)3093070630ULL),((unsigned int)3329864425ULL),((unsigned int)1334859500ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 165\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1131567719ULL),((unsigned int)3018760517ULL),((unsigned int)1282120273ULL),((unsigned int)3431392620ULL),((unsigned int)3399607005ULL),((unsigned int)743204327ULL),((unsigned int)3781552062ULL),((unsigned int)210555694ULL),((unsigned int)429470370ULL),((unsigned int)2105441282ULL),((unsigned int)2486946875ULL),((unsigned int)1890493575ULL),((unsigned int)2940267723ULL),((unsigned int)1392811065ULL),((unsigned int)1471715817ULL),((unsigned int)2504680103ULL)};
unsigned int b_0[16]={((unsigned int)1131567719ULL),((unsigned int)3018760517ULL),((unsigned int)1282120273ULL),((unsigned int)3431392620ULL),((unsigned int)3399607005ULL),((unsigned int)743204327ULL),((unsigned int)3781552062ULL),((unsigned int)210555694ULL),((unsigned int)429470370ULL),((unsigned int)2105441282ULL),((unsigned int)2486946875ULL),((unsigned int)1890493575ULL),((unsigned int)2940267723ULL),((unsigned int)1392811065ULL),((unsigned int)1471715817ULL),((unsigned int)2504680103ULL)};
unsigned int a_1[4]={((unsigned int)556364604ULL),((unsigned int)3998748437ULL),((unsigned int)519409629ULL),((unsigned int)1991287486ULL)};
unsigned int b_1[4]={((unsigned int)556364604ULL),((unsigned int)3998748437ULL),((unsigned int)519409629ULL),((unsigned int)1991287486ULL)};
unsigned int a_2[4]={((unsigned int)3427892673ULL),((unsigned int)4131657383ULL),((unsigned int)2038180043ULL),((unsigned int)1536568308ULL)};
unsigned int b_2[4]={((unsigned int)3427892673ULL),((unsigned int)4131657383ULL),((unsigned int)2038180043ULL),((unsigned int)1536568308ULL)};
unsigned int a_3[4]={((unsigned int)3707268325ULL),((unsigned int)2672700434ULL),((unsigned int)1836737798ULL),((unsigned int)1995053256ULL)};
unsigned int b_3[4]={((unsigned int)3707268325ULL),((unsigned int)2672700434ULL),((unsigned int)1836737798ULL),((unsigned int)1995053256ULL)};
unsigned int a_4[4]={((unsigned int)178909493ULL),((unsigned int)884151639ULL),((unsigned int)2280007406ULL),((unsigned int)1009357230ULL)};
unsigned int b_4[4]={((unsigned int)178909493ULL),((unsigned int)884151639ULL),((unsigned int)2280007406ULL),((unsigned int)1009357230ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 166\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)351575243ULL),((unsigned int)1840402002ULL),((unsigned int)2659193590ULL),((unsigned int)2608940247ULL),((unsigned int)1688228224ULL),((unsigned int)749310984ULL),((unsigned int)787146928ULL),((unsigned int)2721256125ULL),((unsigned int)3392251340ULL),((unsigned int)4167348395ULL),((unsigned int)3237645227ULL),((unsigned int)700544091ULL),((unsigned int)2402001630ULL),((unsigned int)2550553125ULL),((unsigned int)2585574985ULL),((unsigned int)1640342582ULL)};
unsigned int b_0[16]={((unsigned int)351575243ULL),((unsigned int)1840402002ULL),((unsigned int)2659193590ULL),((unsigned int)2608940247ULL),((unsigned int)1688228224ULL),((unsigned int)749310984ULL),((unsigned int)787146928ULL),((unsigned int)2721256125ULL),((unsigned int)3392251340ULL),((unsigned int)4167348395ULL),((unsigned int)3237645227ULL),((unsigned int)700544091ULL),((unsigned int)2402001630ULL),((unsigned int)2550553125ULL),((unsigned int)2585574985ULL),((unsigned int)1640342582ULL)};
unsigned int a_1[4]={((unsigned int)4057199523ULL),((unsigned int)321618998ULL),((unsigned int)1498893138ULL),((unsigned int)3216451267ULL)};
unsigned int b_1[4]={((unsigned int)4057199523ULL),((unsigned int)321618998ULL),((unsigned int)1498893138ULL),((unsigned int)3216451267ULL)};
unsigned int a_2[4]={((unsigned int)3791759995ULL),((unsigned int)3360914746ULL),((unsigned int)3890173833ULL),((unsigned int)102416776ULL)};
unsigned int b_2[4]={((unsigned int)3791759995ULL),((unsigned int)3360914746ULL),((unsigned int)3890173833ULL),((unsigned int)102416776ULL)};
unsigned int a_3[4]={((unsigned int)1482143296ULL),((unsigned int)4116544825ULL),((unsigned int)867183946ULL),((unsigned int)683880833ULL)};
unsigned int b_3[4]={((unsigned int)1482143296ULL),((unsigned int)4116544825ULL),((unsigned int)867183946ULL),((unsigned int)683880833ULL)};
unsigned int a_4[4]={((unsigned int)2752391197ULL),((unsigned int)3929378478ULL),((unsigned int)4066284072ULL),((unsigned int)2764735204ULL)};
unsigned int b_4[4]={((unsigned int)2752391197ULL),((unsigned int)3929378478ULL),((unsigned int)4066284072ULL),((unsigned int)2764735204ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 167\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2578892516ULL),((unsigned int)438902707ULL),((unsigned int)1730826252ULL),((unsigned int)2268128619ULL),((unsigned int)1830699100ULL),((unsigned int)2605023968ULL),((unsigned int)3857215673ULL),((unsigned int)1874644644ULL),((unsigned int)1371547884ULL),((unsigned int)2768768674ULL),((unsigned int)2774935395ULL),((unsigned int)3380608574ULL),((unsigned int)2932029522ULL),((unsigned int)1838791888ULL),((unsigned int)2012732986ULL),((unsigned int)2312156120ULL)};
unsigned int b_0[16]={((unsigned int)2578892516ULL),((unsigned int)438902707ULL),((unsigned int)1730826252ULL),((unsigned int)2268128619ULL),((unsigned int)1830699100ULL),((unsigned int)2605023968ULL),((unsigned int)3857215673ULL),((unsigned int)1874644644ULL),((unsigned int)1371547884ULL),((unsigned int)2768768674ULL),((unsigned int)2774935395ULL),((unsigned int)3380608574ULL),((unsigned int)2932029522ULL),((unsigned int)1838791888ULL),((unsigned int)2012732986ULL),((unsigned int)2312156120ULL)};
unsigned int a_1[4]={((unsigned int)3155925912ULL),((unsigned int)4234462339ULL),((unsigned int)2417444298ULL),((unsigned int)3328620814ULL)};
unsigned int b_1[4]={((unsigned int)3155925912ULL),((unsigned int)4234462339ULL),((unsigned int)2417444298ULL),((unsigned int)3328620814ULL)};
unsigned int a_2[4]={((unsigned int)2828547997ULL),((unsigned int)2960645985ULL),((unsigned int)1338102123ULL),((unsigned int)1344993040ULL)};
unsigned int b_2[4]={((unsigned int)2828547997ULL),((unsigned int)2960645985ULL),((unsigned int)1338102123ULL),((unsigned int)1344993040ULL)};
unsigned int a_3[4]={((unsigned int)2228463622ULL),((unsigned int)3829910581ULL),((unsigned int)337702047ULL),((unsigned int)3747178361ULL)};
unsigned int b_3[4]={((unsigned int)2228463622ULL),((unsigned int)3829910581ULL),((unsigned int)337702047ULL),((unsigned int)3747178361ULL)};
unsigned int a_4[4]={((unsigned int)746149981ULL),((unsigned int)587175726ULL),((unsigned int)2077362486ULL),((unsigned int)404738254ULL)};
unsigned int b_4[4]={((unsigned int)746149981ULL),((unsigned int)587175726ULL),((unsigned int)2077362486ULL),((unsigned int)404738254ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 168\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)9788833ULL),((unsigned int)1618822930ULL),((unsigned int)282090034ULL),((unsigned int)2202278734ULL),((unsigned int)166571457ULL),((unsigned int)592478431ULL),((unsigned int)2556247009ULL),((unsigned int)2071306738ULL),((unsigned int)2493784122ULL),((unsigned int)1743570064ULL),((unsigned int)1190186535ULL),((unsigned int)2375447357ULL),((unsigned int)2302348641ULL),((unsigned int)3964865466ULL),((unsigned int)1943374262ULL),((unsigned int)1702204543ULL)};
unsigned int b_0[16]={((unsigned int)9788833ULL),((unsigned int)1618822930ULL),((unsigned int)282090034ULL),((unsigned int)2202278734ULL),((unsigned int)166571457ULL),((unsigned int)592478431ULL),((unsigned int)2556247009ULL),((unsigned int)2071306738ULL),((unsigned int)2493784122ULL),((unsigned int)1743570064ULL),((unsigned int)1190186535ULL),((unsigned int)2375447357ULL),((unsigned int)2302348641ULL),((unsigned int)3964865466ULL),((unsigned int)1943374262ULL),((unsigned int)1702204543ULL)};
unsigned int a_1[4]={((unsigned int)75692306ULL),((unsigned int)3140545219ULL),((unsigned int)1147269214ULL),((unsigned int)4134063558ULL)};
unsigned int b_1[4]={((unsigned int)75692306ULL),((unsigned int)3140545219ULL),((unsigned int)1147269214ULL),((unsigned int)4134063558ULL)};
unsigned int a_2[4]={((unsigned int)1563330009ULL),((unsigned int)4269012276ULL),((unsigned int)3743118491ULL),((unsigned int)343870764ULL)};
unsigned int b_2[4]={((unsigned int)1563330009ULL),((unsigned int)4269012276ULL),((unsigned int)3743118491ULL),((unsigned int)343870764ULL)};
unsigned int a_3[4]={((unsigned int)2645947934ULL),((unsigned int)1011053170ULL),((unsigned int)1059878456ULL),((unsigned int)3186592547ULL)};
unsigned int b_3[4]={((unsigned int)2645947934ULL),((unsigned int)1011053170ULL),((unsigned int)1059878456ULL),((unsigned int)3186592547ULL)};
unsigned int a_4[4]={((unsigned int)1439762133ULL),((unsigned int)610178071ULL),((unsigned int)3421502978ULL),((unsigned int)3280355890ULL)};
unsigned int b_4[4]={((unsigned int)1439762133ULL),((unsigned int)610178071ULL),((unsigned int)3421502978ULL),((unsigned int)3280355890ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 169\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2109023158ULL),((unsigned int)1460798049ULL),((unsigned int)2627453494ULL),((unsigned int)1165604682ULL),((unsigned int)807324329ULL),((unsigned int)1365415114ULL),((unsigned int)2857986022ULL),((unsigned int)3279429243ULL),((unsigned int)1968567857ULL),((unsigned int)876951993ULL),((unsigned int)1928414548ULL),((unsigned int)3351696797ULL),((unsigned int)1299629508ULL),((unsigned int)3902795929ULL),((unsigned int)1368157379ULL),((unsigned int)2663560591ULL)};
unsigned int b_0[16]={((unsigned int)2109023158ULL),((unsigned int)1460798049ULL),((unsigned int)2627453494ULL),((unsigned int)1165604682ULL),((unsigned int)807324329ULL),((unsigned int)1365415114ULL),((unsigned int)2857986022ULL),((unsigned int)3279429243ULL),((unsigned int)1968567857ULL),((unsigned int)876951993ULL),((unsigned int)1928414548ULL),((unsigned int)3351696797ULL),((unsigned int)1299629508ULL),((unsigned int)3902795929ULL),((unsigned int)1368157379ULL),((unsigned int)2663560591ULL)};
unsigned int a_1[4]={((unsigned int)3354801763ULL),((unsigned int)3769670055ULL),((unsigned int)256589796ULL),((unsigned int)1476872820ULL)};
unsigned int b_1[4]={((unsigned int)3354801763ULL),((unsigned int)3769670055ULL),((unsigned int)256589796ULL),((unsigned int)1476872820ULL)};
unsigned int a_2[4]={((unsigned int)3621888962ULL),((unsigned int)3223334795ULL),((unsigned int)2993682251ULL),((unsigned int)2746956404ULL)};
unsigned int b_2[4]={((unsigned int)3621888962ULL),((unsigned int)3223334795ULL),((unsigned int)2993682251ULL),((unsigned int)2746956404ULL)};
unsigned int a_3[4]={((unsigned int)3717913761ULL),((unsigned int)352579337ULL),((unsigned int)427653211ULL),((unsigned int)2843176367ULL)};
unsigned int b_3[4]={((unsigned int)3717913761ULL),((unsigned int)352579337ULL),((unsigned int)427653211ULL),((unsigned int)2843176367ULL)};
unsigned int a_4[4]={((unsigned int)1459651206ULL),((unsigned int)279368091ULL),((unsigned int)3156005553ULL),((unsigned int)386612295ULL)};
unsigned int b_4[4]={((unsigned int)1459651206ULL),((unsigned int)279368091ULL),((unsigned int)3156005553ULL),((unsigned int)386612295ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 170\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3196815285ULL),((unsigned int)713417988ULL),((unsigned int)4142398601ULL),((unsigned int)3658921604ULL),((unsigned int)2926449125ULL),((unsigned int)4150280082ULL),((unsigned int)367057048ULL),((unsigned int)2611990445ULL),((unsigned int)3292674441ULL),((unsigned int)3769616899ULL),((unsigned int)858026220ULL),((unsigned int)2463832461ULL),((unsigned int)1976626169ULL),((unsigned int)4055522708ULL),((unsigned int)2263118832ULL),((unsigned int)2422221468ULL)};
unsigned int b_0[16]={((unsigned int)3196815285ULL),((unsigned int)713417988ULL),((unsigned int)4142398601ULL),((unsigned int)3658921604ULL),((unsigned int)2926449125ULL),((unsigned int)4150280082ULL),((unsigned int)367057048ULL),((unsigned int)2611990445ULL),((unsigned int)3292674441ULL),((unsigned int)3769616899ULL),((unsigned int)858026220ULL),((unsigned int)2463832461ULL),((unsigned int)1976626169ULL),((unsigned int)4055522708ULL),((unsigned int)2263118832ULL),((unsigned int)2422221468ULL)};
unsigned int a_1[4]={((unsigned int)916184699ULL),((unsigned int)3261909485ULL),((unsigned int)406228139ULL),((unsigned int)3301016773ULL)};
unsigned int b_1[4]={((unsigned int)916184699ULL),((unsigned int)3261909485ULL),((unsigned int)406228139ULL),((unsigned int)3301016773ULL)};
unsigned int a_2[4]={((unsigned int)1417412815ULL),((unsigned int)2217841569ULL),((unsigned int)1174183942ULL),((unsigned int)2330018842ULL)};
unsigned int b_2[4]={((unsigned int)1417412815ULL),((unsigned int)2217841569ULL),((unsigned int)1174183942ULL),((unsigned int)2330018842ULL)};
unsigned int a_3[4]={((unsigned int)2785058166ULL),((unsigned int)2302081199ULL),((unsigned int)630994513ULL),((unsigned int)1560024697ULL)};
unsigned int b_3[4]={((unsigned int)2785058166ULL),((unsigned int)2302081199ULL),((unsigned int)630994513ULL),((unsigned int)1560024697ULL)};
unsigned int a_4[4]={((unsigned int)2056323745ULL),((unsigned int)668987030ULL),((unsigned int)4242367149ULL),((unsigned int)2710532555ULL)};
unsigned int b_4[4]={((unsigned int)2056323745ULL),((unsigned int)668987030ULL),((unsigned int)4242367149ULL),((unsigned int)2710532555ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 171\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1180927828ULL),((unsigned int)125273750ULL),((unsigned int)115167882ULL),((unsigned int)2551116713ULL),((unsigned int)1470407223ULL),((unsigned int)100819115ULL),((unsigned int)104696851ULL),((unsigned int)2275431586ULL),((unsigned int)3979358692ULL),((unsigned int)34826433ULL),((unsigned int)5230918ULL),((unsigned int)1949152352ULL),((unsigned int)2665104096ULL),((unsigned int)419070732ULL),((unsigned int)784463504ULL),((unsigned int)360836362ULL)};
unsigned int b_0[16]={((unsigned int)1180927828ULL),((unsigned int)125273750ULL),((unsigned int)115167882ULL),((unsigned int)2551116713ULL),((unsigned int)1470407223ULL),((unsigned int)100819115ULL),((unsigned int)104696851ULL),((unsigned int)2275431586ULL),((unsigned int)3979358692ULL),((unsigned int)34826433ULL),((unsigned int)5230918ULL),((unsigned int)1949152352ULL),((unsigned int)2665104096ULL),((unsigned int)419070732ULL),((unsigned int)784463504ULL),((unsigned int)360836362ULL)};
unsigned int a_1[4]={((unsigned int)597682737ULL),((unsigned int)927358912ULL),((unsigned int)253973990ULL),((unsigned int)944990511ULL)};
unsigned int b_1[4]={((unsigned int)597682737ULL),((unsigned int)927358912ULL),((unsigned int)253973990ULL),((unsigned int)944990511ULL)};
unsigned int a_2[4]={((unsigned int)60366707ULL),((unsigned int)3155369473ULL),((unsigned int)3114752744ULL),((unsigned int)620147623ULL)};
unsigned int b_2[4]={((unsigned int)60366707ULL),((unsigned int)3155369473ULL),((unsigned int)3114752744ULL),((unsigned int)620147623ULL)};
unsigned int a_3[4]={((unsigned int)2702791143ULL),((unsigned int)1867499392ULL),((unsigned int)3563609796ULL),((unsigned int)1735610315ULL)};
unsigned int b_3[4]={((unsigned int)2702791143ULL),((unsigned int)1867499392ULL),((unsigned int)3563609796ULL),((unsigned int)1735610315ULL)};
unsigned int a_4[4]={((unsigned int)2947272045ULL),((unsigned int)3577279786ULL),((unsigned int)1962733733ULL),((unsigned int)2209942563ULL)};
unsigned int b_4[4]={((unsigned int)2947272045ULL),((unsigned int)3577279786ULL),((unsigned int)1962733733ULL),((unsigned int)2209942563ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 172\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2640499758ULL),((unsigned int)1308073313ULL),((unsigned int)1502285395ULL),((unsigned int)383121948ULL),((unsigned int)585771442ULL),((unsigned int)3933723529ULL),((unsigned int)558213692ULL),((unsigned int)1254773765ULL),((unsigned int)168358372ULL),((unsigned int)2859286226ULL),((unsigned int)1771902759ULL),((unsigned int)1429912316ULL),((unsigned int)980689928ULL),((unsigned int)3830777956ULL),((unsigned int)1058398613ULL),((unsigned int)3604862289ULL)};
unsigned int b_0[16]={((unsigned int)2640499758ULL),((unsigned int)1308073313ULL),((unsigned int)1502285395ULL),((unsigned int)383121948ULL),((unsigned int)585771442ULL),((unsigned int)3933723529ULL),((unsigned int)558213692ULL),((unsigned int)1254773765ULL),((unsigned int)168358372ULL),((unsigned int)2859286226ULL),((unsigned int)1771902759ULL),((unsigned int)1429912316ULL),((unsigned int)980689928ULL),((unsigned int)3830777956ULL),((unsigned int)1058398613ULL),((unsigned int)3604862289ULL)};
unsigned int a_1[4]={((unsigned int)1288806914ULL),((unsigned int)1944474605ULL),((unsigned int)1066301982ULL),((unsigned int)2314400448ULL)};
unsigned int b_1[4]={((unsigned int)1288806914ULL),((unsigned int)1944474605ULL),((unsigned int)1066301982ULL),((unsigned int)2314400448ULL)};
unsigned int a_2[4]={((unsigned int)756820924ULL),((unsigned int)3010056512ULL),((unsigned int)87740665ULL),((unsigned int)454179016ULL)};
unsigned int b_2[4]={((unsigned int)756820924ULL),((unsigned int)3010056512ULL),((unsigned int)87740665ULL),((unsigned int)454179016ULL)};
unsigned int a_3[4]={((unsigned int)757247938ULL),((unsigned int)1361651782ULL),((unsigned int)3301880374ULL),((unsigned int)2319104400ULL)};
unsigned int b_3[4]={((unsigned int)757247938ULL),((unsigned int)1361651782ULL),((unsigned int)3301880374ULL),((unsigned int)2319104400ULL)};
unsigned int a_4[4]={((unsigned int)2264775587ULL),((unsigned int)3374772716ULL),((unsigned int)3518927407ULL),((unsigned int)3145767253ULL)};
unsigned int b_4[4]={((unsigned int)2264775587ULL),((unsigned int)3374772716ULL),((unsigned int)3518927407ULL),((unsigned int)3145767253ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 173\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2416784098ULL),((unsigned int)1386380641ULL),((unsigned int)1252640822ULL),((unsigned int)1857789943ULL),((unsigned int)1521326277ULL),((unsigned int)2777718947ULL),((unsigned int)2104811472ULL),((unsigned int)212444502ULL),((unsigned int)1119086509ULL),((unsigned int)4038857705ULL),((unsigned int)4090094195ULL),((unsigned int)1437723111ULL),((unsigned int)3693983415ULL),((unsigned int)3547116729ULL),((unsigned int)600610820ULL),((unsigned int)1810037992ULL)};
unsigned int b_0[16]={((unsigned int)2416784098ULL),((unsigned int)1386380641ULL),((unsigned int)1252640822ULL),((unsigned int)1857789943ULL),((unsigned int)1521326277ULL),((unsigned int)2777718947ULL),((unsigned int)2104811472ULL),((unsigned int)212444502ULL),((unsigned int)1119086509ULL),((unsigned int)4038857705ULL),((unsigned int)4090094195ULL),((unsigned int)1437723111ULL),((unsigned int)3693983415ULL),((unsigned int)3547116729ULL),((unsigned int)600610820ULL),((unsigned int)1810037992ULL)};
unsigned int a_1[4]={((unsigned int)1003945642ULL),((unsigned int)3741894689ULL),((unsigned int)2000684398ULL),((unsigned int)744859327ULL)};
unsigned int b_1[4]={((unsigned int)1003945642ULL),((unsigned int)3741894689ULL),((unsigned int)2000684398ULL),((unsigned int)744859327ULL)};
unsigned int a_2[4]={((unsigned int)4060246028ULL),((unsigned int)259569438ULL),((unsigned int)172659869ULL),((unsigned int)615830005ULL)};
unsigned int b_2[4]={((unsigned int)4060246028ULL),((unsigned int)259569438ULL),((unsigned int)172659869ULL),((unsigned int)615830005ULL)};
unsigned int a_3[4]={((unsigned int)3587304387ULL),((unsigned int)1943220979ULL),((unsigned int)608016302ULL),((unsigned int)1677166291ULL)};
unsigned int b_3[4]={((unsigned int)3587304387ULL),((unsigned int)1943220979ULL),((unsigned int)608016302ULL),((unsigned int)1677166291ULL)};
unsigned int a_4[4]={((unsigned int)100148612ULL),((unsigned int)3428215408ULL),((unsigned int)1629339587ULL),((unsigned int)3278430304ULL)};
unsigned int b_4[4]={((unsigned int)100148612ULL),((unsigned int)3428215408ULL),((unsigned int)1629339587ULL),((unsigned int)3278430304ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 174\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2753686606ULL),((unsigned int)4082699890ULL),((unsigned int)443498649ULL),((unsigned int)3224411066ULL),((unsigned int)1948862772ULL),((unsigned int)3317212179ULL),((unsigned int)1286443200ULL),((unsigned int)2164269805ULL),((unsigned int)3949564055ULL),((unsigned int)3151409114ULL),((unsigned int)1714181920ULL),((unsigned int)4280923160ULL),((unsigned int)1842092385ULL),((unsigned int)4200174866ULL),((unsigned int)3325197852ULL),((unsigned int)1405777126ULL)};
unsigned int b_0[16]={((unsigned int)2753686606ULL),((unsigned int)4082699890ULL),((unsigned int)443498649ULL),((unsigned int)3224411066ULL),((unsigned int)1948862772ULL),((unsigned int)3317212179ULL),((unsigned int)1286443200ULL),((unsigned int)2164269805ULL),((unsigned int)3949564055ULL),((unsigned int)3151409114ULL),((unsigned int)1714181920ULL),((unsigned int)4280923160ULL),((unsigned int)1842092385ULL),((unsigned int)4200174866ULL),((unsigned int)3325197852ULL),((unsigned int)1405777126ULL)};
unsigned int a_1[4]={((unsigned int)2874854019ULL),((unsigned int)1408972770ULL),((unsigned int)444367204ULL),((unsigned int)622207439ULL)};
unsigned int b_1[4]={((unsigned int)2874854019ULL),((unsigned int)1408972770ULL),((unsigned int)444367204ULL),((unsigned int)622207439ULL)};
unsigned int a_2[4]={((unsigned int)2902599369ULL),((unsigned int)3564113740ULL),((unsigned int)864405528ULL),((unsigned int)3055340738ULL)};
unsigned int b_2[4]={((unsigned int)2902599369ULL),((unsigned int)3564113740ULL),((unsigned int)864405528ULL),((unsigned int)3055340738ULL)};
unsigned int a_3[4]={((unsigned int)3927762742ULL),((unsigned int)3627444073ULL),((unsigned int)3077974132ULL),((unsigned int)222603042ULL)};
unsigned int b_3[4]={((unsigned int)3927762742ULL),((unsigned int)3627444073ULL),((unsigned int)3077974132ULL),((unsigned int)222603042ULL)};
unsigned int a_4[4]={((unsigned int)4202109445ULL),((unsigned int)643973653ULL),((unsigned int)2210382523ULL),((unsigned int)3098227441ULL)};
unsigned int b_4[4]={((unsigned int)4202109445ULL),((unsigned int)643973653ULL),((unsigned int)2210382523ULL),((unsigned int)3098227441ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 175\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3380454359ULL),((unsigned int)402906850ULL),((unsigned int)3463818978ULL),((unsigned int)84001731ULL),((unsigned int)1371251096ULL),((unsigned int)1337613847ULL),((unsigned int)4198519907ULL),((unsigned int)2171184305ULL),((unsigned int)2057933983ULL),((unsigned int)1557807696ULL),((unsigned int)1241526846ULL),((unsigned int)4165743386ULL),((unsigned int)3961701274ULL),((unsigned int)444721592ULL),((unsigned int)2875175986ULL),((unsigned int)939166347ULL)};
unsigned int b_0[16]={((unsigned int)3380454359ULL),((unsigned int)402906850ULL),((unsigned int)3463818978ULL),((unsigned int)84001731ULL),((unsigned int)1371251096ULL),((unsigned int)1337613847ULL),((unsigned int)4198519907ULL),((unsigned int)2171184305ULL),((unsigned int)2057933983ULL),((unsigned int)1557807696ULL),((unsigned int)1241526846ULL),((unsigned int)4165743386ULL),((unsigned int)3961701274ULL),((unsigned int)444721592ULL),((unsigned int)2875175986ULL),((unsigned int)939166347ULL)};
unsigned int a_1[4]={((unsigned int)3282546752ULL),((unsigned int)1554388435ULL),((unsigned int)471985721ULL),((unsigned int)1840772438ULL)};
unsigned int b_1[4]={((unsigned int)3282546752ULL),((unsigned int)1554388435ULL),((unsigned int)471985721ULL),((unsigned int)1840772438ULL)};
unsigned int a_2[4]={((unsigned int)3762808689ULL),((unsigned int)3375966317ULL),((unsigned int)1860940682ULL),((unsigned int)2698788767ULL)};
unsigned int b_2[4]={((unsigned int)3762808689ULL),((unsigned int)3375966317ULL),((unsigned int)1860940682ULL),((unsigned int)2698788767ULL)};
unsigned int a_3[4]={((unsigned int)1573392767ULL),((unsigned int)1944694783ULL),((unsigned int)3737926542ULL),((unsigned int)3795798960ULL)};
unsigned int b_3[4]={((unsigned int)1573392767ULL),((unsigned int)1944694783ULL),((unsigned int)3737926542ULL),((unsigned int)3795798960ULL)};
unsigned int a_4[4]={((unsigned int)2040763377ULL),((unsigned int)1432437240ULL),((unsigned int)1409961597ULL),((unsigned int)3117631462ULL)};
unsigned int b_4[4]={((unsigned int)2040763377ULL),((unsigned int)1432437240ULL),((unsigned int)1409961597ULL),((unsigned int)3117631462ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 176\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)113371284ULL),((unsigned int)1730798763ULL),((unsigned int)4116449108ULL),((unsigned int)3986121568ULL),((unsigned int)3069350868ULL),((unsigned int)36246880ULL),((unsigned int)3231341647ULL),((unsigned int)994941928ULL),((unsigned int)1992957135ULL),((unsigned int)3909639004ULL),((unsigned int)3851284623ULL),((unsigned int)2237828607ULL),((unsigned int)2894734390ULL),((unsigned int)1356420759ULL),((unsigned int)3213605979ULL),((unsigned int)1021351386ULL)};
unsigned int b_0[16]={((unsigned int)113371284ULL),((unsigned int)1730798763ULL),((unsigned int)4116449108ULL),((unsigned int)3986121568ULL),((unsigned int)3069350868ULL),((unsigned int)36246880ULL),((unsigned int)3231341647ULL),((unsigned int)994941928ULL),((unsigned int)1992957135ULL),((unsigned int)3909639004ULL),((unsigned int)3851284623ULL),((unsigned int)2237828607ULL),((unsigned int)2894734390ULL),((unsigned int)1356420759ULL),((unsigned int)3213605979ULL),((unsigned int)1021351386ULL)};
unsigned int a_1[4]={((unsigned int)1647568027ULL),((unsigned int)2356038317ULL),((unsigned int)768518395ULL),((unsigned int)649203897ULL)};
unsigned int b_1[4]={((unsigned int)1647568027ULL),((unsigned int)2356038317ULL),((unsigned int)768518395ULL),((unsigned int)649203897ULL)};
unsigned int a_2[4]={((unsigned int)1037744474ULL),((unsigned int)1883968820ULL),((unsigned int)3173555070ULL),((unsigned int)1890848177ULL)};
unsigned int b_2[4]={((unsigned int)1037744474ULL),((unsigned int)1883968820ULL),((unsigned int)3173555070ULL),((unsigned int)1890848177ULL)};
unsigned int a_3[4]={((unsigned int)2608214621ULL),((unsigned int)86804687ULL),((unsigned int)3450371231ULL),((unsigned int)3169100983ULL)};
unsigned int b_3[4]={((unsigned int)2608214621ULL),((unsigned int)86804687ULL),((unsigned int)3450371231ULL),((unsigned int)3169100983ULL)};
unsigned int a_4[4]={((unsigned int)3573737595ULL),((unsigned int)3206706411ULL),((unsigned int)3909488308ULL),((unsigned int)196326220ULL)};
unsigned int b_4[4]={((unsigned int)3573737595ULL),((unsigned int)3206706411ULL),((unsigned int)3909488308ULL),((unsigned int)196326220ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 177\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3212869252ULL),((unsigned int)1708984901ULL),((unsigned int)2124641535ULL),((unsigned int)747090886ULL),((unsigned int)2416838542ULL),((unsigned int)3515522801ULL),((unsigned int)4265611799ULL),((unsigned int)1031137180ULL),((unsigned int)3212455364ULL),((unsigned int)125980795ULL),((unsigned int)3750425862ULL),((unsigned int)3890465233ULL),((unsigned int)2817374230ULL),((unsigned int)3613436680ULL),((unsigned int)3630426625ULL),((unsigned int)988958952ULL)};
unsigned int b_0[16]={((unsigned int)3212869252ULL),((unsigned int)1708984901ULL),((unsigned int)2124641535ULL),((unsigned int)747090886ULL),((unsigned int)2416838542ULL),((unsigned int)3515522801ULL),((unsigned int)4265611799ULL),((unsigned int)1031137180ULL),((unsigned int)3212455364ULL),((unsigned int)125980795ULL),((unsigned int)3750425862ULL),((unsigned int)3890465233ULL),((unsigned int)2817374230ULL),((unsigned int)3613436680ULL),((unsigned int)3630426625ULL),((unsigned int)988958952ULL)};
unsigned int a_1[4]={((unsigned int)3573413313ULL),((unsigned int)3828377605ULL),((unsigned int)2513640596ULL),((unsigned int)1248382025ULL)};
unsigned int b_1[4]={((unsigned int)3573413313ULL),((unsigned int)3828377605ULL),((unsigned int)2513640596ULL),((unsigned int)1248382025ULL)};
unsigned int a_2[4]={((unsigned int)1320906499ULL),((unsigned int)81017180ULL),((unsigned int)3247345000ULL),((unsigned int)901587993ULL)};
unsigned int b_2[4]={((unsigned int)1320906499ULL),((unsigned int)81017180ULL),((unsigned int)3247345000ULL),((unsigned int)901587993ULL)};
unsigned int a_3[4]={((unsigned int)3113051556ULL),((unsigned int)929765847ULL),((unsigned int)2506071469ULL),((unsigned int)3243474658ULL)};
unsigned int b_3[4]={((unsigned int)3113051556ULL),((unsigned int)929765847ULL),((unsigned int)2506071469ULL),((unsigned int)3243474658ULL)};
unsigned int a_4[4]={((unsigned int)3096576486ULL),((unsigned int)3062483567ULL),((unsigned int)831448241ULL),((unsigned int)3145577649ULL)};
unsigned int b_4[4]={((unsigned int)3096576486ULL),((unsigned int)3062483567ULL),((unsigned int)831448241ULL),((unsigned int)3145577649ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 178\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1758834323ULL),((unsigned int)317224606ULL),((unsigned int)3040982137ULL),((unsigned int)739502201ULL),((unsigned int)4157105663ULL),((unsigned int)2231637480ULL),((unsigned int)1862319637ULL),((unsigned int)1455197585ULL),((unsigned int)2815284558ULL),((unsigned int)4262266824ULL),((unsigned int)3747480546ULL),((unsigned int)1543853319ULL),((unsigned int)1068176877ULL),((unsigned int)3577424787ULL),((unsigned int)2739573969ULL),((unsigned int)3662060351ULL)};
unsigned int b_0[16]={((unsigned int)1758834323ULL),((unsigned int)317224606ULL),((unsigned int)3040982137ULL),((unsigned int)739502201ULL),((unsigned int)4157105663ULL),((unsigned int)2231637480ULL),((unsigned int)1862319637ULL),((unsigned int)1455197585ULL),((unsigned int)2815284558ULL),((unsigned int)4262266824ULL),((unsigned int)3747480546ULL),((unsigned int)1543853319ULL),((unsigned int)1068176877ULL),((unsigned int)3577424787ULL),((unsigned int)2739573969ULL),((unsigned int)3662060351ULL)};
unsigned int a_1[4]={((unsigned int)2668943164ULL),((unsigned int)980494752ULL),((unsigned int)4144360272ULL),((unsigned int)2194866833ULL)};
unsigned int b_1[4]={((unsigned int)2668943164ULL),((unsigned int)980494752ULL),((unsigned int)4144360272ULL),((unsigned int)2194866833ULL)};
unsigned int a_2[4]={((unsigned int)545196275ULL),((unsigned int)2862722794ULL),((unsigned int)966808317ULL),((unsigned int)1623410408ULL)};
unsigned int b_2[4]={((unsigned int)545196275ULL),((unsigned int)2862722794ULL),((unsigned int)966808317ULL),((unsigned int)1623410408ULL)};
unsigned int a_3[4]={((unsigned int)147102647ULL),((unsigned int)4121888811ULL),((unsigned int)2474884794ULL),((unsigned int)3023751717ULL)};
unsigned int b_3[4]={((unsigned int)147102647ULL),((unsigned int)4121888811ULL),((unsigned int)2474884794ULL),((unsigned int)3023751717ULL)};
unsigned int a_4[4]={((unsigned int)1856392318ULL),((unsigned int)2618383859ULL),((unsigned int)1249318768ULL),((unsigned int)1932374314ULL)};
unsigned int b_4[4]={((unsigned int)1856392318ULL),((unsigned int)2618383859ULL),((unsigned int)1249318768ULL),((unsigned int)1932374314ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 179\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1243662531ULL),((unsigned int)2765310369ULL),((unsigned int)197073760ULL),((unsigned int)3734279884ULL),((unsigned int)3442136313ULL),((unsigned int)3381463758ULL),((unsigned int)993820573ULL),((unsigned int)3858403330ULL),((unsigned int)4001681421ULL),((unsigned int)2405510006ULL),((unsigned int)3037266218ULL),((unsigned int)1176016620ULL),((unsigned int)1339187928ULL),((unsigned int)115576140ULL),((unsigned int)3547654195ULL),((unsigned int)558824022ULL)};
unsigned int b_0[16]={((unsigned int)1243662531ULL),((unsigned int)2765310369ULL),((unsigned int)197073760ULL),((unsigned int)3734279884ULL),((unsigned int)3442136313ULL),((unsigned int)3381463758ULL),((unsigned int)993820573ULL),((unsigned int)3858403330ULL),((unsigned int)4001681421ULL),((unsigned int)2405510006ULL),((unsigned int)3037266218ULL),((unsigned int)1176016620ULL),((unsigned int)1339187928ULL),((unsigned int)115576140ULL),((unsigned int)3547654195ULL),((unsigned int)558824022ULL)};
unsigned int a_1[4]={((unsigned int)1522831708ULL),((unsigned int)3571712986ULL),((unsigned int)3381065179ULL),((unsigned int)2997125536ULL)};
unsigned int b_1[4]={((unsigned int)1522831708ULL),((unsigned int)3571712986ULL),((unsigned int)3381065179ULL),((unsigned int)2997125536ULL)};
unsigned int a_2[4]={((unsigned int)4230558684ULL),((unsigned int)3947617172ULL),((unsigned int)2829678991ULL),((unsigned int)690673892ULL)};
unsigned int b_2[4]={((unsigned int)4230558684ULL),((unsigned int)3947617172ULL),((unsigned int)2829678991ULL),((unsigned int)690673892ULL)};
unsigned int a_3[4]={((unsigned int)1882274835ULL),((unsigned int)1060625897ULL),((unsigned int)677395323ULL),((unsigned int)3110927046ULL)};
unsigned int b_3[4]={((unsigned int)1882274835ULL),((unsigned int)1060625897ULL),((unsigned int)677395323ULL),((unsigned int)3110927046ULL)};
unsigned int a_4[4]={((unsigned int)1874639639ULL),((unsigned int)714262302ULL),((unsigned int)3639675454ULL),((unsigned int)2884154331ULL)};
unsigned int b_4[4]={((unsigned int)1874639639ULL),((unsigned int)714262302ULL),((unsigned int)3639675454ULL),((unsigned int)2884154331ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 180\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)575577514ULL),((unsigned int)3419578390ULL),((unsigned int)72905737ULL),((unsigned int)3999487585ULL),((unsigned int)1109889461ULL),((unsigned int)188847465ULL),((unsigned int)1989212866ULL),((unsigned int)1169094730ULL),((unsigned int)1422987699ULL),((unsigned int)3688582869ULL),((unsigned int)1355312217ULL),((unsigned int)3701248466ULL),((unsigned int)121054877ULL),((unsigned int)2531042249ULL),((unsigned int)4072496990ULL),((unsigned int)4151120801ULL)};
unsigned int b_0[16]={((unsigned int)575577514ULL),((unsigned int)3419578390ULL),((unsigned int)72905737ULL),((unsigned int)3999487585ULL),((unsigned int)1109889461ULL),((unsigned int)188847465ULL),((unsigned int)1989212866ULL),((unsigned int)1169094730ULL),((unsigned int)1422987699ULL),((unsigned int)3688582869ULL),((unsigned int)1355312217ULL),((unsigned int)3701248466ULL),((unsigned int)121054877ULL),((unsigned int)2531042249ULL),((unsigned int)4072496990ULL),((unsigned int)4151120801ULL)};
unsigned int a_1[4]={((unsigned int)3671616694ULL),((unsigned int)886718584ULL),((unsigned int)1566979643ULL),((unsigned int)3350296857ULL)};
unsigned int b_1[4]={((unsigned int)3671616694ULL),((unsigned int)886718584ULL),((unsigned int)1566979643ULL),((unsigned int)3350296857ULL)};
unsigned int a_2[4]={((unsigned int)3512105524ULL),((unsigned int)1335141596ULL),((unsigned int)4266401829ULL),((unsigned int)3130068823ULL)};
unsigned int b_2[4]={((unsigned int)3512105524ULL),((unsigned int)1335141596ULL),((unsigned int)4266401829ULL),((unsigned int)3130068823ULL)};
unsigned int a_3[4]={((unsigned int)1586094769ULL),((unsigned int)2889765193ULL),((unsigned int)2217620480ULL),((unsigned int)3169507526ULL)};
unsigned int b_3[4]={((unsigned int)1586094769ULL),((unsigned int)2889765193ULL),((unsigned int)2217620480ULL),((unsigned int)3169507526ULL)};
unsigned int a_4[4]={((unsigned int)3570484856ULL),((unsigned int)336872053ULL),((unsigned int)1502818015ULL),((unsigned int)2456399850ULL)};
unsigned int b_4[4]={((unsigned int)3570484856ULL),((unsigned int)336872053ULL),((unsigned int)1502818015ULL),((unsigned int)2456399850ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 181\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1133623010ULL),((unsigned int)2435585692ULL),((unsigned int)1030696535ULL),((unsigned int)2388409641ULL),((unsigned int)3579012198ULL),((unsigned int)2180409394ULL),((unsigned int)3276474943ULL),((unsigned int)2086191487ULL),((unsigned int)3257946430ULL),((unsigned int)1864343672ULL),((unsigned int)2849099764ULL),((unsigned int)2359363315ULL),((unsigned int)922683730ULL),((unsigned int)2224421004ULL),((unsigned int)2886537021ULL),((unsigned int)2329099422ULL)};
unsigned int b_0[16]={((unsigned int)1133623010ULL),((unsigned int)2435585692ULL),((unsigned int)1030696535ULL),((unsigned int)2388409641ULL),((unsigned int)3579012198ULL),((unsigned int)2180409394ULL),((unsigned int)3276474943ULL),((unsigned int)2086191487ULL),((unsigned int)3257946430ULL),((unsigned int)1864343672ULL),((unsigned int)2849099764ULL),((unsigned int)2359363315ULL),((unsigned int)922683730ULL),((unsigned int)2224421004ULL),((unsigned int)2886537021ULL),((unsigned int)2329099422ULL)};
unsigned int a_1[4]={((unsigned int)2625942978ULL),((unsigned int)552213977ULL),((unsigned int)993336802ULL),((unsigned int)3951622769ULL)};
unsigned int b_1[4]={((unsigned int)2625942978ULL),((unsigned int)552213977ULL),((unsigned int)993336802ULL),((unsigned int)3951622769ULL)};
unsigned int a_2[4]={((unsigned int)2901132381ULL),((unsigned int)1773753163ULL),((unsigned int)854208738ULL),((unsigned int)3353949687ULL)};
unsigned int b_2[4]={((unsigned int)2901132381ULL),((unsigned int)1773753163ULL),((unsigned int)854208738ULL),((unsigned int)3353949687ULL)};
unsigned int a_3[4]={((unsigned int)2433927755ULL),((unsigned int)3218642499ULL),((unsigned int)2657236671ULL),((unsigned int)1448584779ULL)};
unsigned int b_3[4]={((unsigned int)2433927755ULL),((unsigned int)3218642499ULL),((unsigned int)2657236671ULL),((unsigned int)1448584779ULL)};
unsigned int a_4[4]={((unsigned int)4070971080ULL),((unsigned int)1700091870ULL),((unsigned int)969561242ULL),((unsigned int)1471068673ULL)};
unsigned int b_4[4]={((unsigned int)4070971080ULL),((unsigned int)1700091870ULL),((unsigned int)969561242ULL),((unsigned int)1471068673ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 182\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)513307631ULL),((unsigned int)3696139986ULL),((unsigned int)1943434597ULL),((unsigned int)1376458737ULL),((unsigned int)2780513906ULL),((unsigned int)3204661506ULL),((unsigned int)4120400865ULL),((unsigned int)3379237800ULL),((unsigned int)3130889274ULL),((unsigned int)2417666032ULL),((unsigned int)3644187811ULL),((unsigned int)3746474017ULL),((unsigned int)246142809ULL),((unsigned int)3262097624ULL),((unsigned int)3980438146ULL),((unsigned int)99445481ULL)};
unsigned int b_0[16]={((unsigned int)513307631ULL),((unsigned int)3696139986ULL),((unsigned int)1943434597ULL),((unsigned int)1376458737ULL),((unsigned int)2780513906ULL),((unsigned int)3204661506ULL),((unsigned int)4120400865ULL),((unsigned int)3379237800ULL),((unsigned int)3130889274ULL),((unsigned int)2417666032ULL),((unsigned int)3644187811ULL),((unsigned int)3746474017ULL),((unsigned int)246142809ULL),((unsigned int)3262097624ULL),((unsigned int)3980438146ULL),((unsigned int)99445481ULL)};
unsigned int a_1[4]={((unsigned int)300475496ULL),((unsigned int)2497234215ULL),((unsigned int)2859636595ULL),((unsigned int)503206690ULL)};
unsigned int b_1[4]={((unsigned int)300475496ULL),((unsigned int)2497234215ULL),((unsigned int)2859636595ULL),((unsigned int)503206690ULL)};
unsigned int a_2[4]={((unsigned int)4283346296ULL),((unsigned int)161429848ULL),((unsigned int)3682326506ULL),((unsigned int)1190965771ULL)};
unsigned int b_2[4]={((unsigned int)4283346296ULL),((unsigned int)161429848ULL),((unsigned int)3682326506ULL),((unsigned int)1190965771ULL)};
unsigned int a_3[4]={((unsigned int)362351322ULL),((unsigned int)2298301706ULL),((unsigned int)825520582ULL),((unsigned int)1787571402ULL)};
unsigned int b_3[4]={((unsigned int)362351322ULL),((unsigned int)2298301706ULL),((unsigned int)825520582ULL),((unsigned int)1787571402ULL)};
unsigned int a_4[4]={((unsigned int)3315284338ULL),((unsigned int)224061406ULL),((unsigned int)275552164ULL),((unsigned int)3473288849ULL)};
unsigned int b_4[4]={((unsigned int)3315284338ULL),((unsigned int)224061406ULL),((unsigned int)275552164ULL),((unsigned int)3473288849ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 183\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)968721966ULL),((unsigned int)713669408ULL),((unsigned int)105274302ULL),((unsigned int)4172401065ULL),((unsigned int)2252882533ULL),((unsigned int)2721928671ULL),((unsigned int)1964939021ULL),((unsigned int)135202240ULL),((unsigned int)1447256771ULL),((unsigned int)2060385098ULL),((unsigned int)2642780877ULL),((unsigned int)3670769934ULL),((unsigned int)2179119085ULL),((unsigned int)3109088232ULL),((unsigned int)1321195755ULL),((unsigned int)3979715459ULL)};
unsigned int b_0[16]={((unsigned int)968721966ULL),((unsigned int)713669408ULL),((unsigned int)105274302ULL),((unsigned int)4172401065ULL),((unsigned int)2252882533ULL),((unsigned int)2721928671ULL),((unsigned int)1964939021ULL),((unsigned int)135202240ULL),((unsigned int)1447256771ULL),((unsigned int)2060385098ULL),((unsigned int)2642780877ULL),((unsigned int)3670769934ULL),((unsigned int)2179119085ULL),((unsigned int)3109088232ULL),((unsigned int)1321195755ULL),((unsigned int)3979715459ULL)};
unsigned int a_1[4]={((unsigned int)1311849109ULL),((unsigned int)4204907054ULL),((unsigned int)2585766619ULL),((unsigned int)1175875591ULL)};
unsigned int b_1[4]={((unsigned int)1311849109ULL),((unsigned int)4204907054ULL),((unsigned int)2585766619ULL),((unsigned int)1175875591ULL)};
unsigned int a_2[4]={((unsigned int)256603182ULL),((unsigned int)3931816384ULL),((unsigned int)1718842067ULL),((unsigned int)2307513570ULL)};
unsigned int b_2[4]={((unsigned int)256603182ULL),((unsigned int)3931816384ULL),((unsigned int)1718842067ULL),((unsigned int)2307513570ULL)};
unsigned int a_3[4]={((unsigned int)172124338ULL),((unsigned int)1537618099ULL),((unsigned int)1457884134ULL),((unsigned int)2274948919ULL)};
unsigned int b_3[4]={((unsigned int)172124338ULL),((unsigned int)1537618099ULL),((unsigned int)1457884134ULL),((unsigned int)2274948919ULL)};
unsigned int a_4[4]={((unsigned int)438131796ULL),((unsigned int)2140801512ULL),((unsigned int)1095329278ULL),((unsigned int)1246501369ULL)};
unsigned int b_4[4]={((unsigned int)438131796ULL),((unsigned int)2140801512ULL),((unsigned int)1095329278ULL),((unsigned int)1246501369ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 184\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)498091811ULL),((unsigned int)817537611ULL),((unsigned int)3302455583ULL),((unsigned int)821501179ULL),((unsigned int)1111726448ULL),((unsigned int)349948453ULL),((unsigned int)2432840421ULL),((unsigned int)2151263061ULL),((unsigned int)3028276577ULL),((unsigned int)215631408ULL),((unsigned int)2670395918ULL),((unsigned int)2091650142ULL),((unsigned int)3275077040ULL),((unsigned int)4247606079ULL),((unsigned int)3134176257ULL),((unsigned int)3423309284ULL)};
unsigned int b_0[16]={((unsigned int)498091811ULL),((unsigned int)817537611ULL),((unsigned int)3302455583ULL),((unsigned int)821501179ULL),((unsigned int)1111726448ULL),((unsigned int)349948453ULL),((unsigned int)2432840421ULL),((unsigned int)2151263061ULL),((unsigned int)3028276577ULL),((unsigned int)215631408ULL),((unsigned int)2670395918ULL),((unsigned int)2091650142ULL),((unsigned int)3275077040ULL),((unsigned int)4247606079ULL),((unsigned int)3134176257ULL),((unsigned int)3423309284ULL)};
unsigned int a_1[4]={((unsigned int)2456691665ULL),((unsigned int)4118605183ULL),((unsigned int)3912577200ULL),((unsigned int)2743572761ULL)};
unsigned int b_1[4]={((unsigned int)2456691665ULL),((unsigned int)4118605183ULL),((unsigned int)3912577200ULL),((unsigned int)2743572761ULL)};
unsigned int a_2[4]={((unsigned int)2325363994ULL),((unsigned int)1209783196ULL),((unsigned int)3448715836ULL),((unsigned int)3914912489ULL)};
unsigned int b_2[4]={((unsigned int)2325363994ULL),((unsigned int)1209783196ULL),((unsigned int)3448715836ULL),((unsigned int)3914912489ULL)};
unsigned int a_3[4]={((unsigned int)2114735360ULL),((unsigned int)489308679ULL),((unsigned int)2563373144ULL),((unsigned int)1498318629ULL)};
unsigned int b_3[4]={((unsigned int)2114735360ULL),((unsigned int)489308679ULL),((unsigned int)2563373144ULL),((unsigned int)1498318629ULL)};
unsigned int a_4[4]={((unsigned int)1042049499ULL),((unsigned int)741862523ULL),((unsigned int)2142440018ULL),((unsigned int)2033030169ULL)};
unsigned int b_4[4]={((unsigned int)1042049499ULL),((unsigned int)741862523ULL),((unsigned int)2142440018ULL),((unsigned int)2033030169ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 185\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3764652647ULL),((unsigned int)993806388ULL),((unsigned int)2912186687ULL),((unsigned int)1768141966ULL),((unsigned int)311692242ULL),((unsigned int)2585090188ULL),((unsigned int)2254857732ULL),((unsigned int)1328483002ULL),((unsigned int)2678597698ULL),((unsigned int)4200860352ULL),((unsigned int)1828487377ULL),((unsigned int)1676250444ULL),((unsigned int)2306559149ULL),((unsigned int)3668400425ULL),((unsigned int)4030136231ULL),((unsigned int)2609495216ULL)};
unsigned int b_0[16]={((unsigned int)3764652647ULL),((unsigned int)993806388ULL),((unsigned int)2912186687ULL),((unsigned int)1768141966ULL),((unsigned int)311692242ULL),((unsigned int)2585090188ULL),((unsigned int)2254857732ULL),((unsigned int)1328483002ULL),((unsigned int)2678597698ULL),((unsigned int)4200860352ULL),((unsigned int)1828487377ULL),((unsigned int)1676250444ULL),((unsigned int)2306559149ULL),((unsigned int)3668400425ULL),((unsigned int)4030136231ULL),((unsigned int)2609495216ULL)};
unsigned int a_1[4]={((unsigned int)1245192375ULL),((unsigned int)2052190813ULL),((unsigned int)1490762517ULL),((unsigned int)2628177710ULL)};
unsigned int b_1[4]={((unsigned int)1245192375ULL),((unsigned int)2052190813ULL),((unsigned int)1490762517ULL),((unsigned int)2628177710ULL)};
unsigned int a_2[4]={((unsigned int)3354837946ULL),((unsigned int)3469655426ULL),((unsigned int)3641545695ULL),((unsigned int)906138740ULL)};
unsigned int b_2[4]={((unsigned int)3354837946ULL),((unsigned int)3469655426ULL),((unsigned int)3641545695ULL),((unsigned int)906138740ULL)};
unsigned int a_3[4]={((unsigned int)2757867676ULL),((unsigned int)4259738920ULL),((unsigned int)2684291331ULL),((unsigned int)713235352ULL)};
unsigned int b_3[4]={((unsigned int)2757867676ULL),((unsigned int)4259738920ULL),((unsigned int)2684291331ULL),((unsigned int)713235352ULL)};
unsigned int a_4[4]={((unsigned int)1074623802ULL),((unsigned int)3250391642ULL),((unsigned int)1917530388ULL),((unsigned int)3605841377ULL)};
unsigned int b_4[4]={((unsigned int)1074623802ULL),((unsigned int)3250391642ULL),((unsigned int)1917530388ULL),((unsigned int)3605841377ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 186\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1754981226ULL),((unsigned int)1226031715ULL),((unsigned int)4220552765ULL),((unsigned int)2651495628ULL),((unsigned int)4069376044ULL),((unsigned int)2625642330ULL),((unsigned int)155092442ULL),((unsigned int)2598158514ULL),((unsigned int)2354291713ULL),((unsigned int)3790927682ULL),((unsigned int)139857387ULL),((unsigned int)1979954875ULL),((unsigned int)3485429965ULL),((unsigned int)3800618420ULL),((unsigned int)708446108ULL),((unsigned int)1160026300ULL)};
unsigned int b_0[16]={((unsigned int)1754981226ULL),((unsigned int)1226031715ULL),((unsigned int)4220552765ULL),((unsigned int)2651495628ULL),((unsigned int)4069376044ULL),((unsigned int)2625642330ULL),((unsigned int)155092442ULL),((unsigned int)2598158514ULL),((unsigned int)2354291713ULL),((unsigned int)3790927682ULL),((unsigned int)139857387ULL),((unsigned int)1979954875ULL),((unsigned int)3485429965ULL),((unsigned int)3800618420ULL),((unsigned int)708446108ULL),((unsigned int)1160026300ULL)};
unsigned int a_1[4]={((unsigned int)3084838616ULL),((unsigned int)2649431752ULL),((unsigned int)3902500191ULL),((unsigned int)2252652149ULL)};
unsigned int b_1[4]={((unsigned int)3084838616ULL),((unsigned int)2649431752ULL),((unsigned int)3902500191ULL),((unsigned int)2252652149ULL)};
unsigned int a_2[4]={((unsigned int)846956767ULL),((unsigned int)1421576729ULL),((unsigned int)4235991419ULL),((unsigned int)3485611541ULL)};
unsigned int b_2[4]={((unsigned int)846956767ULL),((unsigned int)1421576729ULL),((unsigned int)4235991419ULL),((unsigned int)3485611541ULL)};
unsigned int a_3[4]={((unsigned int)2504728504ULL),((unsigned int)195070253ULL),((unsigned int)2946547196ULL),((unsigned int)2972346853ULL)};
unsigned int b_3[4]={((unsigned int)2504728504ULL),((unsigned int)195070253ULL),((unsigned int)2946547196ULL),((unsigned int)2972346853ULL)};
unsigned int a_4[4]={((unsigned int)3408661590ULL),((unsigned int)3689218710ULL),((unsigned int)2292067796ULL),((unsigned int)3759630240ULL)};
unsigned int b_4[4]={((unsigned int)3408661590ULL),((unsigned int)3689218710ULL),((unsigned int)2292067796ULL),((unsigned int)3759630240ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 187\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3044186516ULL),((unsigned int)2050299956ULL),((unsigned int)3156878157ULL),((unsigned int)1872367127ULL),((unsigned int)1798629066ULL),((unsigned int)2636601191ULL),((unsigned int)3650273353ULL),((unsigned int)757764876ULL),((unsigned int)1300324677ULL),((unsigned int)2381339233ULL),((unsigned int)4146984583ULL),((unsigned int)237218039ULL),((unsigned int)1245773417ULL),((unsigned int)2384426495ULL),((unsigned int)4197508884ULL),((unsigned int)3462057528ULL)};
unsigned int b_0[16]={((unsigned int)3044186516ULL),((unsigned int)2050299956ULL),((unsigned int)3156878157ULL),((unsigned int)1872367127ULL),((unsigned int)1798629066ULL),((unsigned int)2636601191ULL),((unsigned int)3650273353ULL),((unsigned int)757764876ULL),((unsigned int)1300324677ULL),((unsigned int)2381339233ULL),((unsigned int)4146984583ULL),((unsigned int)237218039ULL),((unsigned int)1245773417ULL),((unsigned int)2384426495ULL),((unsigned int)4197508884ULL),((unsigned int)3462057528ULL)};
unsigned int a_1[4]={((unsigned int)3512421549ULL),((unsigned int)1763294698ULL),((unsigned int)3435666858ULL),((unsigned int)2295364090ULL)};
unsigned int b_1[4]={((unsigned int)3512421549ULL),((unsigned int)1763294698ULL),((unsigned int)3435666858ULL),((unsigned int)2295364090ULL)};
unsigned int a_2[4]={((unsigned int)1283471428ULL),((unsigned int)4130700716ULL),((unsigned int)4195851082ULL),((unsigned int)3005332939ULL)};
unsigned int b_2[4]={((unsigned int)1283471428ULL),((unsigned int)4130700716ULL),((unsigned int)4195851082ULL),((unsigned int)3005332939ULL)};
unsigned int a_3[4]={((unsigned int)1052373674ULL),((unsigned int)3424467687ULL),((unsigned int)1581180957ULL),((unsigned int)1992907932ULL)};
unsigned int b_3[4]={((unsigned int)1052373674ULL),((unsigned int)3424467687ULL),((unsigned int)1581180957ULL),((unsigned int)1992907932ULL)};
unsigned int a_4[4]={((unsigned int)3357207471ULL),((unsigned int)1181381057ULL),((unsigned int)2033543625ULL),((unsigned int)169630380ULL)};
unsigned int b_4[4]={((unsigned int)3357207471ULL),((unsigned int)1181381057ULL),((unsigned int)2033543625ULL),((unsigned int)169630380ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 188\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3940616844ULL),((unsigned int)138888476ULL),((unsigned int)2614393760ULL),((unsigned int)1446418699ULL),((unsigned int)2366434845ULL),((unsigned int)1964058302ULL),((unsigned int)4029394466ULL),((unsigned int)53927992ULL),((unsigned int)3726572038ULL),((unsigned int)1486463770ULL),((unsigned int)3496235284ULL),((unsigned int)1676453945ULL),((unsigned int)3599010624ULL),((unsigned int)1766689968ULL),((unsigned int)394201050ULL),((unsigned int)1349558083ULL)};
unsigned int b_0[16]={((unsigned int)3940616844ULL),((unsigned int)138888476ULL),((unsigned int)2614393760ULL),((unsigned int)1446418699ULL),((unsigned int)2366434845ULL),((unsigned int)1964058302ULL),((unsigned int)4029394466ULL),((unsigned int)53927992ULL),((unsigned int)3726572038ULL),((unsigned int)1486463770ULL),((unsigned int)3496235284ULL),((unsigned int)1676453945ULL),((unsigned int)3599010624ULL),((unsigned int)1766689968ULL),((unsigned int)394201050ULL),((unsigned int)1349558083ULL)};
unsigned int a_1[4]={((unsigned int)4108954324ULL),((unsigned int)571888051ULL),((unsigned int)2109105352ULL),((unsigned int)3777235166ULL)};
unsigned int b_1[4]={((unsigned int)4108954324ULL),((unsigned int)571888051ULL),((unsigned int)2109105352ULL),((unsigned int)3777235166ULL)};
unsigned int a_2[4]={((unsigned int)2423214117ULL),((unsigned int)4033166236ULL),((unsigned int)1466998867ULL),((unsigned int)588117088ULL)};
unsigned int b_2[4]={((unsigned int)2423214117ULL),((unsigned int)4033166236ULL),((unsigned int)1466998867ULL),((unsigned int)588117088ULL)};
unsigned int a_3[4]={((unsigned int)646182592ULL),((unsigned int)233976840ULL),((unsigned int)3018365690ULL),((unsigned int)3401919389ULL)};
unsigned int b_3[4]={((unsigned int)646182592ULL),((unsigned int)233976840ULL),((unsigned int)3018365690ULL),((unsigned int)3401919389ULL)};
unsigned int a_4[4]={((unsigned int)2394958879ULL),((unsigned int)1963023642ULL),((unsigned int)73529204ULL),((unsigned int)3446797816ULL)};
unsigned int b_4[4]={((unsigned int)2394958879ULL),((unsigned int)1963023642ULL),((unsigned int)73529204ULL),((unsigned int)3446797816ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 189\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)308478979ULL),((unsigned int)636980860ULL),((unsigned int)3723043587ULL),((unsigned int)2137399158ULL),((unsigned int)4265916114ULL),((unsigned int)1413998421ULL),((unsigned int)483108502ULL),((unsigned int)1138178559ULL),((unsigned int)192442229ULL),((unsigned int)2043085799ULL),((unsigned int)1004764997ULL),((unsigned int)305597048ULL),((unsigned int)1480290418ULL),((unsigned int)1801810145ULL),((unsigned int)1863434517ULL),((unsigned int)3850273330ULL)};
unsigned int b_0[16]={((unsigned int)308478979ULL),((unsigned int)636980860ULL),((unsigned int)3723043587ULL),((unsigned int)2137399158ULL),((unsigned int)4265916114ULL),((unsigned int)1413998421ULL),((unsigned int)483108502ULL),((unsigned int)1138178559ULL),((unsigned int)192442229ULL),((unsigned int)2043085799ULL),((unsigned int)1004764997ULL),((unsigned int)305597048ULL),((unsigned int)1480290418ULL),((unsigned int)1801810145ULL),((unsigned int)1863434517ULL),((unsigned int)3850273330ULL)};
unsigned int a_1[4]={((unsigned int)727383937ULL),((unsigned int)3365239413ULL),((unsigned int)2057510751ULL),((unsigned int)3170695157ULL)};
unsigned int b_1[4]={((unsigned int)727383937ULL),((unsigned int)3365239413ULL),((unsigned int)2057510751ULL),((unsigned int)3170695157ULL)};
unsigned int a_2[4]={((unsigned int)570823261ULL),((unsigned int)4049486402ULL),((unsigned int)3757433973ULL),((unsigned int)968877566ULL)};
unsigned int b_2[4]={((unsigned int)570823261ULL),((unsigned int)4049486402ULL),((unsigned int)3757433973ULL),((unsigned int)968877566ULL)};
unsigned int a_3[4]={((unsigned int)644353889ULL),((unsigned int)1864189946ULL),((unsigned int)1291395688ULL),((unsigned int)1544210188ULL)};
unsigned int b_3[4]={((unsigned int)644353889ULL),((unsigned int)1864189946ULL),((unsigned int)1291395688ULL),((unsigned int)1544210188ULL)};
unsigned int a_4[4]={((unsigned int)1490076414ULL),((unsigned int)2697324340ULL),((unsigned int)756789433ULL),((unsigned int)939052989ULL)};
unsigned int b_4[4]={((unsigned int)1490076414ULL),((unsigned int)2697324340ULL),((unsigned int)756789433ULL),((unsigned int)939052989ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 190\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4047878612ULL),((unsigned int)3122089811ULL),((unsigned int)817891412ULL),((unsigned int)621086024ULL),((unsigned int)2219579143ULL),((unsigned int)1333651379ULL),((unsigned int)1204450832ULL),((unsigned int)3556499071ULL),((unsigned int)623356586ULL),((unsigned int)42045745ULL),((unsigned int)3742524642ULL),((unsigned int)2633672048ULL),((unsigned int)1421022428ULL),((unsigned int)3196966661ULL),((unsigned int)1444860501ULL),((unsigned int)2485742449ULL)};
unsigned int b_0[16]={((unsigned int)4047878612ULL),((unsigned int)3122089811ULL),((unsigned int)817891412ULL),((unsigned int)621086024ULL),((unsigned int)2219579143ULL),((unsigned int)1333651379ULL),((unsigned int)1204450832ULL),((unsigned int)3556499071ULL),((unsigned int)623356586ULL),((unsigned int)42045745ULL),((unsigned int)3742524642ULL),((unsigned int)2633672048ULL),((unsigned int)1421022428ULL),((unsigned int)3196966661ULL),((unsigned int)1444860501ULL),((unsigned int)2485742449ULL)};
unsigned int a_1[4]={((unsigned int)4127771360ULL),((unsigned int)1609851831ULL),((unsigned int)1126439496ULL),((unsigned int)1282840186ULL)};
unsigned int b_1[4]={((unsigned int)4127771360ULL),((unsigned int)1609851831ULL),((unsigned int)1126439496ULL),((unsigned int)1282840186ULL)};
unsigned int a_2[4]={((unsigned int)1422139533ULL),((unsigned int)3531813629ULL),((unsigned int)3632458885ULL),((unsigned int)3889393188ULL)};
unsigned int b_2[4]={((unsigned int)1422139533ULL),((unsigned int)3531813629ULL),((unsigned int)3632458885ULL),((unsigned int)3889393188ULL)};
unsigned int a_3[4]={((unsigned int)3866909004ULL),((unsigned int)2511813027ULL),((unsigned int)2551642771ULL),((unsigned int)872396079ULL)};
unsigned int b_3[4]={((unsigned int)3866909004ULL),((unsigned int)2511813027ULL),((unsigned int)2551642771ULL),((unsigned int)872396079ULL)};
unsigned int a_4[4]={((unsigned int)2702759751ULL),((unsigned int)1789973351ULL),((unsigned int)4287454966ULL),((unsigned int)3555337150ULL)};
unsigned int b_4[4]={((unsigned int)2702759751ULL),((unsigned int)1789973351ULL),((unsigned int)4287454966ULL),((unsigned int)3555337150ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 191\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3191105372ULL),((unsigned int)4117184711ULL),((unsigned int)3923668456ULL),((unsigned int)1924859089ULL),((unsigned int)2641561447ULL),((unsigned int)3447305207ULL),((unsigned int)1251980109ULL),((unsigned int)3488219439ULL),((unsigned int)1115674337ULL),((unsigned int)1156919538ULL),((unsigned int)634157193ULL),((unsigned int)94616106ULL),((unsigned int)810064875ULL),((unsigned int)1417026133ULL),((unsigned int)2304959469ULL),((unsigned int)2374070387ULL)};
unsigned int b_0[16]={((unsigned int)3191105372ULL),((unsigned int)4117184711ULL),((unsigned int)3923668456ULL),((unsigned int)1924859089ULL),((unsigned int)2641561447ULL),((unsigned int)3447305207ULL),((unsigned int)1251980109ULL),((unsigned int)3488219439ULL),((unsigned int)1115674337ULL),((unsigned int)1156919538ULL),((unsigned int)634157193ULL),((unsigned int)94616106ULL),((unsigned int)810064875ULL),((unsigned int)1417026133ULL),((unsigned int)2304959469ULL),((unsigned int)2374070387ULL)};
unsigned int a_1[4]={((unsigned int)856799438ULL),((unsigned int)2563563919ULL),((unsigned int)2023462382ULL),((unsigned int)837497325ULL)};
unsigned int b_1[4]={((unsigned int)856799438ULL),((unsigned int)2563563919ULL),((unsigned int)2023462382ULL),((unsigned int)837497325ULL)};
unsigned int a_2[4]={((unsigned int)3540161779ULL),((unsigned int)4205441683ULL),((unsigned int)2307679361ULL),((unsigned int)3952017136ULL)};
unsigned int b_2[4]={((unsigned int)3540161779ULL),((unsigned int)4205441683ULL),((unsigned int)2307679361ULL),((unsigned int)3952017136ULL)};
unsigned int a_3[4]={((unsigned int)1698924595ULL),((unsigned int)2015371548ULL),((unsigned int)4130768019ULL),((unsigned int)650325164ULL)};
unsigned int b_3[4]={((unsigned int)1698924595ULL),((unsigned int)2015371548ULL),((unsigned int)4130768019ULL),((unsigned int)650325164ULL)};
unsigned int a_4[4]={((unsigned int)1037348972ULL),((unsigned int)817476425ULL),((unsigned int)634275545ULL),((unsigned int)241257049ULL)};
unsigned int b_4[4]={((unsigned int)1037348972ULL),((unsigned int)817476425ULL),((unsigned int)634275545ULL),((unsigned int)241257049ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 192\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)195832879ULL),((unsigned int)1694568071ULL),((unsigned int)143767745ULL),((unsigned int)3900275530ULL),((unsigned int)4223514714ULL),((unsigned int)4059508496ULL),((unsigned int)2033713329ULL),((unsigned int)524589294ULL),((unsigned int)2641931838ULL),((unsigned int)3184908906ULL),((unsigned int)2993681748ULL),((unsigned int)3076109778ULL),((unsigned int)3330766230ULL),((unsigned int)321747392ULL),((unsigned int)2584744384ULL),((unsigned int)1492504834ULL)};
unsigned int b_0[16]={((unsigned int)195832879ULL),((unsigned int)1694568071ULL),((unsigned int)143767745ULL),((unsigned int)3900275530ULL),((unsigned int)4223514714ULL),((unsigned int)4059508496ULL),((unsigned int)2033713329ULL),((unsigned int)524589294ULL),((unsigned int)2641931838ULL),((unsigned int)3184908906ULL),((unsigned int)2993681748ULL),((unsigned int)3076109778ULL),((unsigned int)3330766230ULL),((unsigned int)321747392ULL),((unsigned int)2584744384ULL),((unsigned int)1492504834ULL)};
unsigned int a_1[4]={((unsigned int)3701994999ULL),((unsigned int)2130119700ULL),((unsigned int)3839665943ULL),((unsigned int)485423117ULL)};
unsigned int b_1[4]={((unsigned int)3701994999ULL),((unsigned int)2130119700ULL),((unsigned int)3839665943ULL),((unsigned int)485423117ULL)};
unsigned int a_2[4]={((unsigned int)1883353508ULL),((unsigned int)1713057281ULL),((unsigned int)3047489346ULL),((unsigned int)1375818379ULL)};
unsigned int b_2[4]={((unsigned int)1883353508ULL),((unsigned int)1713057281ULL),((unsigned int)3047489346ULL),((unsigned int)1375818379ULL)};
unsigned int a_3[4]={((unsigned int)3786140638ULL),((unsigned int)2125982344ULL),((unsigned int)3560832020ULL),((unsigned int)1773788573ULL)};
unsigned int b_3[4]={((unsigned int)3786140638ULL),((unsigned int)2125982344ULL),((unsigned int)3560832020ULL),((unsigned int)1773788573ULL)};
unsigned int a_4[4]={((unsigned int)3169064977ULL),((unsigned int)3818148266ULL),((unsigned int)4203613658ULL),((unsigned int)3583695701ULL)};
unsigned int b_4[4]={((unsigned int)3169064977ULL),((unsigned int)3818148266ULL),((unsigned int)4203613658ULL),((unsigned int)3583695701ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 193\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2115497896ULL),((unsigned int)1182162793ULL),((unsigned int)2747089290ULL),((unsigned int)3380388754ULL),((unsigned int)1789876946ULL),((unsigned int)248773181ULL),((unsigned int)3322555069ULL),((unsigned int)93404595ULL),((unsigned int)2960309883ULL),((unsigned int)2514518637ULL),((unsigned int)3189699023ULL),((unsigned int)3371733589ULL),((unsigned int)3499815865ULL),((unsigned int)3073899660ULL),((unsigned int)1832124819ULL),((unsigned int)529893118ULL)};
unsigned int b_0[16]={((unsigned int)2115497896ULL),((unsigned int)1182162793ULL),((unsigned int)2747089290ULL),((unsigned int)3380388754ULL),((unsigned int)1789876946ULL),((unsigned int)248773181ULL),((unsigned int)3322555069ULL),((unsigned int)93404595ULL),((unsigned int)2960309883ULL),((unsigned int)2514518637ULL),((unsigned int)3189699023ULL),((unsigned int)3371733589ULL),((unsigned int)3499815865ULL),((unsigned int)3073899660ULL),((unsigned int)1832124819ULL),((unsigned int)529893118ULL)};
unsigned int a_1[4]={((unsigned int)3522091082ULL),((unsigned int)3758431996ULL),((unsigned int)1558841900ULL),((unsigned int)2416809665ULL)};
unsigned int b_1[4]={((unsigned int)3522091082ULL),((unsigned int)3758431996ULL),((unsigned int)1558841900ULL),((unsigned int)2416809665ULL)};
unsigned int a_2[4]={((unsigned int)3262699810ULL),((unsigned int)1548721859ULL),((unsigned int)1034101986ULL),((unsigned int)2468017926ULL)};
unsigned int b_2[4]={((unsigned int)3262699810ULL),((unsigned int)1548721859ULL),((unsigned int)1034101986ULL),((unsigned int)2468017926ULL)};
unsigned int a_3[4]={((unsigned int)705778994ULL),((unsigned int)3611901775ULL),((unsigned int)103356234ULL),((unsigned int)997081122ULL)};
unsigned int b_3[4]={((unsigned int)705778994ULL),((unsigned int)3611901775ULL),((unsigned int)103356234ULL),((unsigned int)997081122ULL)};
unsigned int a_4[4]={((unsigned int)841250285ULL),((unsigned int)143461478ULL),((unsigned int)3529274426ULL),((unsigned int)2773135196ULL)};
unsigned int b_4[4]={((unsigned int)841250285ULL),((unsigned int)143461478ULL),((unsigned int)3529274426ULL),((unsigned int)2773135196ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 194\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)145727617ULL),((unsigned int)2705044613ULL),((unsigned int)835480997ULL),((unsigned int)4093080824ULL),((unsigned int)630365813ULL),((unsigned int)4106706628ULL),((unsigned int)2885001657ULL),((unsigned int)3414983513ULL),((unsigned int)351047284ULL),((unsigned int)909240841ULL),((unsigned int)4224672241ULL),((unsigned int)252191199ULL),((unsigned int)4167051961ULL),((unsigned int)2063616331ULL),((unsigned int)977338321ULL),((unsigned int)3686086660ULL)};
unsigned int b_0[16]={((unsigned int)145727617ULL),((unsigned int)2705044613ULL),((unsigned int)835480997ULL),((unsigned int)4093080824ULL),((unsigned int)630365813ULL),((unsigned int)4106706628ULL),((unsigned int)2885001657ULL),((unsigned int)3414983513ULL),((unsigned int)351047284ULL),((unsigned int)909240841ULL),((unsigned int)4224672241ULL),((unsigned int)252191199ULL),((unsigned int)4167051961ULL),((unsigned int)2063616331ULL),((unsigned int)977338321ULL),((unsigned int)3686086660ULL)};
unsigned int a_1[4]={((unsigned int)90576436ULL),((unsigned int)1775175763ULL),((unsigned int)734258234ULL),((unsigned int)1615035340ULL)};
unsigned int b_1[4]={((unsigned int)90576436ULL),((unsigned int)1775175763ULL),((unsigned int)734258234ULL),((unsigned int)1615035340ULL)};
unsigned int a_2[4]={((unsigned int)1286570065ULL),((unsigned int)1677302609ULL),((unsigned int)3161995984ULL),((unsigned int)597558827ULL)};
unsigned int b_2[4]={((unsigned int)1286570065ULL),((unsigned int)1677302609ULL),((unsigned int)3161995984ULL),((unsigned int)597558827ULL)};
unsigned int a_3[4]={((unsigned int)1807450370ULL),((unsigned int)675791994ULL),((unsigned int)330963865ULL),((unsigned int)3085032972ULL)};
unsigned int b_3[4]={((unsigned int)1807450370ULL),((unsigned int)675791994ULL),((unsigned int)330963865ULL),((unsigned int)3085032972ULL)};
unsigned int a_4[4]={((unsigned int)3123234464ULL),((unsigned int)3190068497ULL),((unsigned int)2335500422ULL),((unsigned int)3996835567ULL)};
unsigned int b_4[4]={((unsigned int)3123234464ULL),((unsigned int)3190068497ULL),((unsigned int)2335500422ULL),((unsigned int)3996835567ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 195\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4074503149ULL),((unsigned int)1312464457ULL),((unsigned int)644768838ULL),((unsigned int)3945774519ULL),((unsigned int)2077816569ULL),((unsigned int)3333532519ULL),((unsigned int)3081219259ULL),((unsigned int)1856281292ULL),((unsigned int)3739132355ULL),((unsigned int)315173167ULL),((unsigned int)2380730575ULL),((unsigned int)459739237ULL),((unsigned int)3798050261ULL),((unsigned int)957044030ULL),((unsigned int)4058888696ULL),((unsigned int)2917368072ULL)};
unsigned int b_0[16]={((unsigned int)4074503149ULL),((unsigned int)1312464457ULL),((unsigned int)644768838ULL),((unsigned int)3945774519ULL),((unsigned int)2077816569ULL),((unsigned int)3333532519ULL),((unsigned int)3081219259ULL),((unsigned int)1856281292ULL),((unsigned int)3739132355ULL),((unsigned int)315173167ULL),((unsigned int)2380730575ULL),((unsigned int)459739237ULL),((unsigned int)3798050261ULL),((unsigned int)957044030ULL),((unsigned int)4058888696ULL),((unsigned int)2917368072ULL)};
unsigned int a_1[4]={((unsigned int)3187579565ULL),((unsigned int)4009396229ULL),((unsigned int)902275892ULL),((unsigned int)233569456ULL)};
unsigned int b_1[4]={((unsigned int)3187579565ULL),((unsigned int)4009396229ULL),((unsigned int)902275892ULL),((unsigned int)233569456ULL)};
unsigned int a_2[4]={((unsigned int)2660576572ULL),((unsigned int)2614360083ULL),((unsigned int)2284940813ULL),((unsigned int)3876851479ULL)};
unsigned int b_2[4]={((unsigned int)2660576572ULL),((unsigned int)2614360083ULL),((unsigned int)2284940813ULL),((unsigned int)3876851479ULL)};
unsigned int a_3[4]={((unsigned int)1194748407ULL),((unsigned int)2229185168ULL),((unsigned int)4195267649ULL),((unsigned int)2620735118ULL)};
unsigned int b_3[4]={((unsigned int)1194748407ULL),((unsigned int)2229185168ULL),((unsigned int)4195267649ULL),((unsigned int)2620735118ULL)};
unsigned int a_4[4]={((unsigned int)140218991ULL),((unsigned int)1917147275ULL),((unsigned int)3542116235ULL),((unsigned int)1428072276ULL)};
unsigned int b_4[4]={((unsigned int)140218991ULL),((unsigned int)1917147275ULL),((unsigned int)3542116235ULL),((unsigned int)1428072276ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 196\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4066258369ULL),((unsigned int)3647634366ULL),((unsigned int)1039311780ULL),((unsigned int)1445083657ULL),((unsigned int)2098706311ULL),((unsigned int)1566629665ULL),((unsigned int)1430871364ULL),((unsigned int)313142010ULL),((unsigned int)2312255448ULL),((unsigned int)54228862ULL),((unsigned int)2125878471ULL),((unsigned int)831010678ULL),((unsigned int)3768311001ULL),((unsigned int)2367549337ULL),((unsigned int)1822098705ULL),((unsigned int)1462955289ULL)};
unsigned int b_0[16]={((unsigned int)4066258369ULL),((unsigned int)3647634366ULL),((unsigned int)1039311780ULL),((unsigned int)1445083657ULL),((unsigned int)2098706311ULL),((unsigned int)1566629665ULL),((unsigned int)1430871364ULL),((unsigned int)313142010ULL),((unsigned int)2312255448ULL),((unsigned int)54228862ULL),((unsigned int)2125878471ULL),((unsigned int)831010678ULL),((unsigned int)3768311001ULL),((unsigned int)2367549337ULL),((unsigned int)1822098705ULL),((unsigned int)1462955289ULL)};
unsigned int a_1[4]={((unsigned int)1919778779ULL),((unsigned int)1956944098ULL),((unsigned int)3822790195ULL),((unsigned int)2870456370ULL)};
unsigned int b_1[4]={((unsigned int)1919778779ULL),((unsigned int)1956944098ULL),((unsigned int)3822790195ULL),((unsigned int)2870456370ULL)};
unsigned int a_2[4]={((unsigned int)3813596801ULL),((unsigned int)1073861246ULL),((unsigned int)681307670ULL),((unsigned int)2224709228ULL)};
unsigned int b_2[4]={((unsigned int)3813596801ULL),((unsigned int)1073861246ULL),((unsigned int)681307670ULL),((unsigned int)2224709228ULL)};
unsigned int a_3[4]={((unsigned int)2403566880ULL),((unsigned int)4294832125ULL),((unsigned int)4076521328ULL),((unsigned int)3766180900ULL)};
unsigned int b_3[4]={((unsigned int)2403566880ULL),((unsigned int)4294832125ULL),((unsigned int)4076521328ULL),((unsigned int)3766180900ULL)};
unsigned int a_4[4]={((unsigned int)752929039ULL),((unsigned int)1548144968ULL),((unsigned int)35101703ULL),((unsigned int)1614161505ULL)};
unsigned int b_4[4]={((unsigned int)752929039ULL),((unsigned int)1548144968ULL),((unsigned int)35101703ULL),((unsigned int)1614161505ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 197\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2144574107ULL),((unsigned int)1218688021ULL),((unsigned int)3479067840ULL),((unsigned int)1341195755ULL),((unsigned int)202630059ULL),((unsigned int)2181898159ULL),((unsigned int)2096535429ULL),((unsigned int)1301108807ULL),((unsigned int)469368789ULL),((unsigned int)2206432637ULL),((unsigned int)2714111845ULL),((unsigned int)3473652913ULL),((unsigned int)2194723779ULL),((unsigned int)3565900994ULL),((unsigned int)1821537578ULL),((unsigned int)3770811656ULL)};
unsigned int b_0[16]={((unsigned int)2144574107ULL),((unsigned int)1218688021ULL),((unsigned int)3479067840ULL),((unsigned int)1341195755ULL),((unsigned int)202630059ULL),((unsigned int)2181898159ULL),((unsigned int)2096535429ULL),((unsigned int)1301108807ULL),((unsigned int)469368789ULL),((unsigned int)2206432637ULL),((unsigned int)2714111845ULL),((unsigned int)3473652913ULL),((unsigned int)2194723779ULL),((unsigned int)3565900994ULL),((unsigned int)1821537578ULL),((unsigned int)3770811656ULL)};
unsigned int a_1[4]={((unsigned int)3603288664ULL),((unsigned int)1192237652ULL),((unsigned int)3203773031ULL),((unsigned int)1121219937ULL)};
unsigned int b_1[4]={((unsigned int)3603288664ULL),((unsigned int)1192237652ULL),((unsigned int)3203773031ULL),((unsigned int)1121219937ULL)};
unsigned int a_2[4]={((unsigned int)3336095881ULL),((unsigned int)4090304648ULL),((unsigned int)3567021207ULL),((unsigned int)1219112207ULL)};
unsigned int b_2[4]={((unsigned int)3336095881ULL),((unsigned int)4090304648ULL),((unsigned int)3567021207ULL),((unsigned int)1219112207ULL)};
unsigned int a_3[4]={((unsigned int)57870027ULL),((unsigned int)2311169819ULL),((unsigned int)100882195ULL),((unsigned int)1626258832ULL)};
unsigned int b_3[4]={((unsigned int)57870027ULL),((unsigned int)2311169819ULL),((unsigned int)100882195ULL),((unsigned int)1626258832ULL)};
unsigned int a_4[4]={((unsigned int)2353285686ULL),((unsigned int)3182069420ULL),((unsigned int)1869084133ULL),((unsigned int)1755946872ULL)};
unsigned int b_4[4]={((unsigned int)2353285686ULL),((unsigned int)3182069420ULL),((unsigned int)1869084133ULL),((unsigned int)1755946872ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 198\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)488850966ULL),((unsigned int)2257084548ULL),((unsigned int)2194384540ULL),((unsigned int)3558227553ULL),((unsigned int)1113098876ULL),((unsigned int)2181893785ULL),((unsigned int)2867362288ULL),((unsigned int)2020305092ULL),((unsigned int)1692229724ULL),((unsigned int)3800399457ULL),((unsigned int)4071456666ULL),((unsigned int)3377221900ULL),((unsigned int)3571014727ULL),((unsigned int)649437992ULL),((unsigned int)4155674677ULL),((unsigned int)1300806802ULL)};
unsigned int b_0[16]={((unsigned int)488850966ULL),((unsigned int)2257084548ULL),((unsigned int)2194384540ULL),((unsigned int)3558227553ULL),((unsigned int)1113098876ULL),((unsigned int)2181893785ULL),((unsigned int)2867362288ULL),((unsigned int)2020305092ULL),((unsigned int)1692229724ULL),((unsigned int)3800399457ULL),((unsigned int)4071456666ULL),((unsigned int)3377221900ULL),((unsigned int)3571014727ULL),((unsigned int)649437992ULL),((unsigned int)4155674677ULL),((unsigned int)1300806802ULL)};
unsigned int a_1[4]={((unsigned int)1893912100ULL),((unsigned int)4051865036ULL),((unsigned int)1587215397ULL),((unsigned int)1368815970ULL)};
unsigned int b_1[4]={((unsigned int)1893912100ULL),((unsigned int)4051865036ULL),((unsigned int)1587215397ULL),((unsigned int)1368815970ULL)};
unsigned int a_2[4]={((unsigned int)3470844778ULL),((unsigned int)2415280340ULL),((unsigned int)4175417929ULL),((unsigned int)2375405762ULL)};
unsigned int b_2[4]={((unsigned int)3470844778ULL),((unsigned int)2415280340ULL),((unsigned int)4175417929ULL),((unsigned int)2375405762ULL)};
unsigned int a_3[4]={((unsigned int)3028850282ULL),((unsigned int)128055198ULL),((unsigned int)1521585870ULL),((unsigned int)2960051073ULL)};
unsigned int b_3[4]={((unsigned int)3028850282ULL),((unsigned int)128055198ULL),((unsigned int)1521585870ULL),((unsigned int)2960051073ULL)};
unsigned int a_4[4]={((unsigned int)3519986027ULL),((unsigned int)2709348430ULL),((unsigned int)1235828895ULL),((unsigned int)1883407733ULL)};
unsigned int b_4[4]={((unsigned int)3519986027ULL),((unsigned int)2709348430ULL),((unsigned int)1235828895ULL),((unsigned int)1883407733ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 199\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)853955253ULL),((unsigned int)3214061414ULL),((unsigned int)2641747703ULL),((unsigned int)2348838032ULL),((unsigned int)4044696717ULL),((unsigned int)1831897577ULL),((unsigned int)1036990140ULL),((unsigned int)2677464933ULL),((unsigned int)969754435ULL),((unsigned int)2419295857ULL),((unsigned int)832914308ULL),((unsigned int)663195309ULL),((unsigned int)435641814ULL),((unsigned int)476102243ULL),((unsigned int)2231277696ULL),((unsigned int)3384583403ULL)};
unsigned int b_0[16]={((unsigned int)853955253ULL),((unsigned int)3214061414ULL),((unsigned int)2641747703ULL),((unsigned int)2348838032ULL),((unsigned int)4044696717ULL),((unsigned int)1831897577ULL),((unsigned int)1036990140ULL),((unsigned int)2677464933ULL),((unsigned int)969754435ULL),((unsigned int)2419295857ULL),((unsigned int)832914308ULL),((unsigned int)663195309ULL),((unsigned int)435641814ULL),((unsigned int)476102243ULL),((unsigned int)2231277696ULL),((unsigned int)3384583403ULL)};
unsigned int a_1[4]={((unsigned int)1440038709ULL),((unsigned int)1766562274ULL),((unsigned int)3580314676ULL),((unsigned int)1177230979ULL)};
unsigned int b_1[4]={((unsigned int)1440038709ULL),((unsigned int)1766562274ULL),((unsigned int)3580314676ULL),((unsigned int)1177230979ULL)};
unsigned int a_2[4]={((unsigned int)1752369170ULL),((unsigned int)1970281571ULL),((unsigned int)2259788388ULL),((unsigned int)3990949123ULL)};
unsigned int b_2[4]={((unsigned int)1752369170ULL),((unsigned int)1970281571ULL),((unsigned int)2259788388ULL),((unsigned int)3990949123ULL)};
unsigned int a_3[4]={((unsigned int)2572144705ULL),((unsigned int)1259801118ULL),((unsigned int)876520440ULL),((unsigned int)3564469520ULL)};
unsigned int b_3[4]={((unsigned int)2572144705ULL),((unsigned int)1259801118ULL),((unsigned int)876520440ULL),((unsigned int)3564469520ULL)};
unsigned int a_4[4]={((unsigned int)1833406358ULL),((unsigned int)2650019325ULL),((unsigned int)1431585605ULL),((unsigned int)1273068068ULL)};
unsigned int b_4[4]={((unsigned int)1833406358ULL),((unsigned int)2650019325ULL),((unsigned int)1431585605ULL),((unsigned int)1273068068ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 200\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2797936728ULL),((unsigned int)2667785899ULL),((unsigned int)2569717147ULL),((unsigned int)1583339330ULL),((unsigned int)3717382652ULL),((unsigned int)218083568ULL),((unsigned int)2154112065ULL),((unsigned int)2348384112ULL),((unsigned int)303593786ULL),((unsigned int)979966258ULL),((unsigned int)572753197ULL),((unsigned int)2856461627ULL),((unsigned int)2214337730ULL),((unsigned int)2288145335ULL),((unsigned int)1180151094ULL),((unsigned int)3151866157ULL)};
unsigned int b_0[16]={((unsigned int)2797936728ULL),((unsigned int)2667785899ULL),((unsigned int)2569717147ULL),((unsigned int)1583339330ULL),((unsigned int)3717382652ULL),((unsigned int)218083568ULL),((unsigned int)2154112065ULL),((unsigned int)2348384112ULL),((unsigned int)303593786ULL),((unsigned int)979966258ULL),((unsigned int)572753197ULL),((unsigned int)2856461627ULL),((unsigned int)2214337730ULL),((unsigned int)2288145335ULL),((unsigned int)1180151094ULL),((unsigned int)3151866157ULL)};
unsigned int a_1[4]={((unsigned int)858683596ULL),((unsigned int)2793443401ULL),((unsigned int)2297351261ULL),((unsigned int)2352384859ULL)};
unsigned int b_1[4]={((unsigned int)858683596ULL),((unsigned int)2793443401ULL),((unsigned int)2297351261ULL),((unsigned int)2352384859ULL)};
unsigned int a_2[4]={((unsigned int)3553460220ULL),((unsigned int)2948562848ULL),((unsigned int)1814770541ULL),((unsigned int)984917971ULL)};
unsigned int b_2[4]={((unsigned int)3553460220ULL),((unsigned int)2948562848ULL),((unsigned int)1814770541ULL),((unsigned int)984917971ULL)};
unsigned int a_3[4]={((unsigned int)3156064675ULL),((unsigned int)4047358229ULL),((unsigned int)2470419568ULL),((unsigned int)1582608340ULL)};
unsigned int b_3[4]={((unsigned int)3156064675ULL),((unsigned int)4047358229ULL),((unsigned int)2470419568ULL),((unsigned int)1582608340ULL)};
unsigned int a_4[4]={((unsigned int)555813180ULL),((unsigned int)4158222501ULL),((unsigned int)2257338577ULL),((unsigned int)4176962824ULL)};
unsigned int b_4[4]={((unsigned int)555813180ULL),((unsigned int)4158222501ULL),((unsigned int)2257338577ULL),((unsigned int)4176962824ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 201\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2756223367ULL),((unsigned int)3488259764ULL),((unsigned int)4153574444ULL),((unsigned int)3185276358ULL),((unsigned int)645372061ULL),((unsigned int)3596551467ULL),((unsigned int)2220348769ULL),((unsigned int)4228795487ULL),((unsigned int)2244966157ULL),((unsigned int)3976156202ULL),((unsigned int)1115842121ULL),((unsigned int)1804205066ULL),((unsigned int)3343100049ULL),((unsigned int)1653578693ULL),((unsigned int)2257903664ULL),((unsigned int)284622861ULL)};
unsigned int b_0[16]={((unsigned int)2756223367ULL),((unsigned int)3488259764ULL),((unsigned int)4153574444ULL),((unsigned int)3185276358ULL),((unsigned int)645372061ULL),((unsigned int)3596551467ULL),((unsigned int)2220348769ULL),((unsigned int)4228795487ULL),((unsigned int)2244966157ULL),((unsigned int)3976156202ULL),((unsigned int)1115842121ULL),((unsigned int)1804205066ULL),((unsigned int)3343100049ULL),((unsigned int)1653578693ULL),((unsigned int)2257903664ULL),((unsigned int)284622861ULL)};
unsigned int a_1[4]={((unsigned int)265217870ULL),((unsigned int)4283737467ULL),((unsigned int)2734937191ULL),((unsigned int)2318242753ULL)};
unsigned int b_1[4]={((unsigned int)265217870ULL),((unsigned int)4283737467ULL),((unsigned int)2734937191ULL),((unsigned int)2318242753ULL)};
unsigned int a_2[4]={((unsigned int)13725403ULL),((unsigned int)2414571745ULL),((unsigned int)1496360559ULL),((unsigned int)3162620285ULL)};
unsigned int b_2[4]={((unsigned int)13725403ULL),((unsigned int)2414571745ULL),((unsigned int)1496360559ULL),((unsigned int)3162620285ULL)};
unsigned int a_3[4]={((unsigned int)3849292433ULL),((unsigned int)3113803344ULL),((unsigned int)273017135ULL),((unsigned int)3140980663ULL)};
unsigned int b_3[4]={((unsigned int)3849292433ULL),((unsigned int)3113803344ULL),((unsigned int)273017135ULL),((unsigned int)3140980663ULL)};
unsigned int a_4[4]={((unsigned int)716493877ULL),((unsigned int)1930976265ULL),((unsigned int)4073506211ULL),((unsigned int)3367330284ULL)};
unsigned int b_4[4]={((unsigned int)716493877ULL),((unsigned int)1930976265ULL),((unsigned int)4073506211ULL),((unsigned int)3367330284ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 202\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3002703801ULL),((unsigned int)3269387076ULL),((unsigned int)2858200640ULL),((unsigned int)2753317124ULL),((unsigned int)287221569ULL),((unsigned int)869702312ULL),((unsigned int)1269107396ULL),((unsigned int)3500699327ULL),((unsigned int)1188614310ULL),((unsigned int)3634224798ULL),((unsigned int)581064219ULL),((unsigned int)1674798512ULL),((unsigned int)3687943342ULL),((unsigned int)833753891ULL),((unsigned int)4275773096ULL),((unsigned int)2754799853ULL)};
unsigned int b_0[16]={((unsigned int)3002703801ULL),((unsigned int)3269387076ULL),((unsigned int)2858200640ULL),((unsigned int)2753317124ULL),((unsigned int)287221569ULL),((unsigned int)869702312ULL),((unsigned int)1269107396ULL),((unsigned int)3500699327ULL),((unsigned int)1188614310ULL),((unsigned int)3634224798ULL),((unsigned int)581064219ULL),((unsigned int)1674798512ULL),((unsigned int)3687943342ULL),((unsigned int)833753891ULL),((unsigned int)4275773096ULL),((unsigned int)2754799853ULL)};
unsigned int a_1[4]={((unsigned int)2573670917ULL),((unsigned int)2610681862ULL),((unsigned int)2576632104ULL),((unsigned int)4168597031ULL)};
unsigned int b_1[4]={((unsigned int)2573670917ULL),((unsigned int)2610681862ULL),((unsigned int)2576632104ULL),((unsigned int)4168597031ULL)};
unsigned int a_2[4]={((unsigned int)2011450202ULL),((unsigned int)435918395ULL),((unsigned int)1528443819ULL),((unsigned int)3837575289ULL)};
unsigned int b_2[4]={((unsigned int)2011450202ULL),((unsigned int)435918395ULL),((unsigned int)1528443819ULL),((unsigned int)3837575289ULL)};
unsigned int a_3[4]={((unsigned int)2870900213ULL),((unsigned int)7616860ULL),((unsigned int)2805964214ULL),((unsigned int)1832380119ULL)};
unsigned int b_3[4]={((unsigned int)2870900213ULL),((unsigned int)7616860ULL),((unsigned int)2805964214ULL),((unsigned int)1832380119ULL)};
unsigned int a_4[4]={((unsigned int)3262526783ULL),((unsigned int)3459873490ULL),((unsigned int)2536585237ULL),((unsigned int)2457580718ULL)};
unsigned int b_4[4]={((unsigned int)3262526783ULL),((unsigned int)3459873490ULL),((unsigned int)2536585237ULL),((unsigned int)2457580718ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 203\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3011457860ULL),((unsigned int)2609325995ULL),((unsigned int)1664782559ULL),((unsigned int)986604779ULL),((unsigned int)3026462892ULL),((unsigned int)2344125965ULL),((unsigned int)850755553ULL),((unsigned int)646201580ULL),((unsigned int)834490586ULL),((unsigned int)394278206ULL),((unsigned int)1071687426ULL),((unsigned int)3353592244ULL),((unsigned int)3851196202ULL),((unsigned int)483178452ULL),((unsigned int)3404236366ULL),((unsigned int)688385754ULL)};
unsigned int b_0[16]={((unsigned int)3011457860ULL),((unsigned int)2609325995ULL),((unsigned int)1664782559ULL),((unsigned int)986604779ULL),((unsigned int)3026462892ULL),((unsigned int)2344125965ULL),((unsigned int)850755553ULL),((unsigned int)646201580ULL),((unsigned int)834490586ULL),((unsigned int)394278206ULL),((unsigned int)1071687426ULL),((unsigned int)3353592244ULL),((unsigned int)3851196202ULL),((unsigned int)483178452ULL),((unsigned int)3404236366ULL),((unsigned int)688385754ULL)};
unsigned int a_1[4]={((unsigned int)2341775092ULL),((unsigned int)114347482ULL),((unsigned int)1111354260ULL),((unsigned int)4293303266ULL)};
unsigned int b_1[4]={((unsigned int)2341775092ULL),((unsigned int)114347482ULL),((unsigned int)1111354260ULL),((unsigned int)4293303266ULL)};
unsigned int a_2[4]={((unsigned int)2254237478ULL),((unsigned int)2241631316ULL),((unsigned int)1683836172ULL),((unsigned int)3101556733ULL)};
unsigned int b_2[4]={((unsigned int)2254237478ULL),((unsigned int)2241631316ULL),((unsigned int)1683836172ULL),((unsigned int)3101556733ULL)};
unsigned int a_3[4]={((unsigned int)2460043813ULL),((unsigned int)3675061723ULL),((unsigned int)48555884ULL),((unsigned int)2339133271ULL)};
unsigned int b_3[4]={((unsigned int)2460043813ULL),((unsigned int)3675061723ULL),((unsigned int)48555884ULL),((unsigned int)2339133271ULL)};
unsigned int a_4[4]={((unsigned int)922656375ULL),((unsigned int)1402404822ULL),((unsigned int)2541554028ULL),((unsigned int)2973164317ULL)};
unsigned int b_4[4]={((unsigned int)922656375ULL),((unsigned int)1402404822ULL),((unsigned int)2541554028ULL),((unsigned int)2973164317ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 204\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1959216203ULL),((unsigned int)1597479597ULL),((unsigned int)3423287677ULL),((unsigned int)1148213225ULL),((unsigned int)1976063314ULL),((unsigned int)2447422870ULL),((unsigned int)3143682092ULL),((unsigned int)41943160ULL),((unsigned int)3701348550ULL),((unsigned int)1380963564ULL),((unsigned int)1778817073ULL),((unsigned int)2678446680ULL),((unsigned int)2096232092ULL),((unsigned int)2563196486ULL),((unsigned int)549820958ULL),((unsigned int)3617105770ULL)};
unsigned int b_0[16]={((unsigned int)1959216203ULL),((unsigned int)1597479597ULL),((unsigned int)3423287677ULL),((unsigned int)1148213225ULL),((unsigned int)1976063314ULL),((unsigned int)2447422870ULL),((unsigned int)3143682092ULL),((unsigned int)41943160ULL),((unsigned int)3701348550ULL),((unsigned int)1380963564ULL),((unsigned int)1778817073ULL),((unsigned int)2678446680ULL),((unsigned int)2096232092ULL),((unsigned int)2563196486ULL),((unsigned int)549820958ULL),((unsigned int)3617105770ULL)};
unsigned int a_1[4]={((unsigned int)3999170870ULL),((unsigned int)1268965261ULL),((unsigned int)3388583277ULL),((unsigned int)3958607304ULL)};
unsigned int b_1[4]={((unsigned int)3999170870ULL),((unsigned int)1268965261ULL),((unsigned int)3388583277ULL),((unsigned int)3958607304ULL)};
unsigned int a_2[4]={((unsigned int)2646040377ULL),((unsigned int)2831629546ULL),((unsigned int)2760801380ULL),((unsigned int)2900128818ULL)};
unsigned int b_2[4]={((unsigned int)2646040377ULL),((unsigned int)2831629546ULL),((unsigned int)2760801380ULL),((unsigned int)2900128818ULL)};
unsigned int a_3[4]={((unsigned int)3739030152ULL),((unsigned int)4281463760ULL),((unsigned int)1478791810ULL),((unsigned int)240753103ULL)};
unsigned int b_3[4]={((unsigned int)3739030152ULL),((unsigned int)4281463760ULL),((unsigned int)1478791810ULL),((unsigned int)240753103ULL)};
unsigned int a_4[4]={((unsigned int)303391914ULL),((unsigned int)3847764535ULL),((unsigned int)3752622255ULL),((unsigned int)1674125654ULL)};
unsigned int b_4[4]={((unsigned int)303391914ULL),((unsigned int)3847764535ULL),((unsigned int)3752622255ULL),((unsigned int)1674125654ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 205\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3683491359ULL),((unsigned int)526980449ULL),((unsigned int)3027951336ULL),((unsigned int)3762116887ULL),((unsigned int)4228199229ULL),((unsigned int)140281108ULL),((unsigned int)4259033653ULL),((unsigned int)3825928378ULL),((unsigned int)851090254ULL),((unsigned int)1061711408ULL),((unsigned int)2344877049ULL),((unsigned int)2481507152ULL),((unsigned int)3030387881ULL),((unsigned int)454108910ULL),((unsigned int)2252602263ULL),((unsigned int)2756868794ULL)};
unsigned int b_0[16]={((unsigned int)3683491359ULL),((unsigned int)526980449ULL),((unsigned int)3027951336ULL),((unsigned int)3762116887ULL),((unsigned int)4228199229ULL),((unsigned int)140281108ULL),((unsigned int)4259033653ULL),((unsigned int)3825928378ULL),((unsigned int)851090254ULL),((unsigned int)1061711408ULL),((unsigned int)2344877049ULL),((unsigned int)2481507152ULL),((unsigned int)3030387881ULL),((unsigned int)454108910ULL),((unsigned int)2252602263ULL),((unsigned int)2756868794ULL)};
unsigned int a_1[4]={((unsigned int)882274290ULL),((unsigned int)1359017202ULL),((unsigned int)4174513005ULL),((unsigned int)1924096056ULL)};
unsigned int b_1[4]={((unsigned int)882274290ULL),((unsigned int)1359017202ULL),((unsigned int)4174513005ULL),((unsigned int)1924096056ULL)};
unsigned int a_2[4]={((unsigned int)1388184862ULL),((unsigned int)266302791ULL),((unsigned int)3950494461ULL),((unsigned int)267572410ULL)};
unsigned int b_2[4]={((unsigned int)1388184862ULL),((unsigned int)266302791ULL),((unsigned int)3950494461ULL),((unsigned int)267572410ULL)};
unsigned int a_3[4]={((unsigned int)1445892419ULL),((unsigned int)2618949961ULL),((unsigned int)4183792731ULL),((unsigned int)4232453442ULL)};
unsigned int b_3[4]={((unsigned int)1445892419ULL),((unsigned int)2618949961ULL),((unsigned int)4183792731ULL),((unsigned int)4232453442ULL)};
unsigned int a_4[4]={((unsigned int)2977663331ULL),((unsigned int)1015974216ULL),((unsigned int)291796608ULL),((unsigned int)1427697853ULL)};
unsigned int b_4[4]={((unsigned int)2977663331ULL),((unsigned int)1015974216ULL),((unsigned int)291796608ULL),((unsigned int)1427697853ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 206\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1065630180ULL),((unsigned int)2132561119ULL),((unsigned int)3193500640ULL),((unsigned int)822547177ULL),((unsigned int)2933464029ULL),((unsigned int)2019922595ULL),((unsigned int)3353728561ULL),((unsigned int)462941214ULL),((unsigned int)2606255935ULL),((unsigned int)1738558320ULL),((unsigned int)2496198434ULL),((unsigned int)1224989764ULL),((unsigned int)2664237274ULL),((unsigned int)3981569422ULL),((unsigned int)2346143337ULL),((unsigned int)685353003ULL)};
unsigned int b_0[16]={((unsigned int)1065630180ULL),((unsigned int)2132561119ULL),((unsigned int)3193500640ULL),((unsigned int)822547177ULL),((unsigned int)2933464029ULL),((unsigned int)2019922595ULL),((unsigned int)3353728561ULL),((unsigned int)462941214ULL),((unsigned int)2606255935ULL),((unsigned int)1738558320ULL),((unsigned int)2496198434ULL),((unsigned int)1224989764ULL),((unsigned int)2664237274ULL),((unsigned int)3981569422ULL),((unsigned int)2346143337ULL),((unsigned int)685353003ULL)};
unsigned int a_1[4]={((unsigned int)189745893ULL),((unsigned int)739790482ULL),((unsigned int)3297480060ULL),((unsigned int)2967645488ULL)};
unsigned int b_1[4]={((unsigned int)189745893ULL),((unsigned int)739790482ULL),((unsigned int)3297480060ULL),((unsigned int)2967645488ULL)};
unsigned int a_2[4]={((unsigned int)855588946ULL),((unsigned int)585315481ULL),((unsigned int)3328918540ULL),((unsigned int)2581850920ULL)};
unsigned int b_2[4]={((unsigned int)855588946ULL),((unsigned int)585315481ULL),((unsigned int)3328918540ULL),((unsigned int)2581850920ULL)};
unsigned int a_3[4]={((unsigned int)2482850329ULL),((unsigned int)3923379445ULL),((unsigned int)2087682345ULL),((unsigned int)1716391944ULL)};
unsigned int b_3[4]={((unsigned int)2482850329ULL),((unsigned int)3923379445ULL),((unsigned int)2087682345ULL),((unsigned int)1716391944ULL)};
unsigned int a_4[4]={((unsigned int)2185851302ULL),((unsigned int)2093580070ULL),((unsigned int)1538357742ULL),((unsigned int)2722854808ULL)};
unsigned int b_4[4]={((unsigned int)2185851302ULL),((unsigned int)2093580070ULL),((unsigned int)1538357742ULL),((unsigned int)2722854808ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 207\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2614409049ULL),((unsigned int)2091565606ULL),((unsigned int)3665292823ULL),((unsigned int)4068934896ULL),((unsigned int)433522682ULL),((unsigned int)4149283689ULL),((unsigned int)3400980077ULL),((unsigned int)1497991310ULL),((unsigned int)2569973508ULL),((unsigned int)3397468895ULL),((unsigned int)2566177994ULL),((unsigned int)3983248221ULL),((unsigned int)2222709898ULL),((unsigned int)616729224ULL),((unsigned int)1528381989ULL),((unsigned int)2695904515ULL)};
unsigned int b_0[16]={((unsigned int)2614409049ULL),((unsigned int)2091565606ULL),((unsigned int)3665292823ULL),((unsigned int)4068934896ULL),((unsigned int)433522682ULL),((unsigned int)4149283689ULL),((unsigned int)3400980077ULL),((unsigned int)1497991310ULL),((unsigned int)2569973508ULL),((unsigned int)3397468895ULL),((unsigned int)2566177994ULL),((unsigned int)3983248221ULL),((unsigned int)2222709898ULL),((unsigned int)616729224ULL),((unsigned int)1528381989ULL),((unsigned int)2695904515ULL)};
unsigned int a_1[4]={((unsigned int)2381424034ULL),((unsigned int)1330872552ULL),((unsigned int)425797155ULL),((unsigned int)1227109547ULL)};
unsigned int b_1[4]={((unsigned int)2381424034ULL),((unsigned int)1330872552ULL),((unsigned int)425797155ULL),((unsigned int)1227109547ULL)};
unsigned int a_2[4]={((unsigned int)400412101ULL),((unsigned int)1294477845ULL),((unsigned int)3622410102ULL),((unsigned int)3943779736ULL)};
unsigned int b_2[4]={((unsigned int)400412101ULL),((unsigned int)1294477845ULL),((unsigned int)3622410102ULL),((unsigned int)3943779736ULL)};
unsigned int a_3[4]={((unsigned int)1502765217ULL),((unsigned int)1887058935ULL),((unsigned int)870841371ULL),((unsigned int)1537459941ULL)};
unsigned int b_3[4]={((unsigned int)1502765217ULL),((unsigned int)1887058935ULL),((unsigned int)870841371ULL),((unsigned int)1537459941ULL)};
unsigned int a_4[4]={((unsigned int)3477131178ULL),((unsigned int)937897882ULL),((unsigned int)1301015345ULL),((unsigned int)3072123456ULL)};
unsigned int b_4[4]={((unsigned int)3477131178ULL),((unsigned int)937897882ULL),((unsigned int)1301015345ULL),((unsigned int)3072123456ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 208\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)590180491ULL),((unsigned int)3073107586ULL),((unsigned int)3783033615ULL),((unsigned int)1709119842ULL),((unsigned int)791555522ULL),((unsigned int)3308503149ULL),((unsigned int)3365351768ULL),((unsigned int)2371348542ULL),((unsigned int)1263256176ULL),((unsigned int)570566309ULL),((unsigned int)2239204192ULL),((unsigned int)2202867433ULL),((unsigned int)2953433642ULL),((unsigned int)2665621172ULL),((unsigned int)3291902973ULL),((unsigned int)629337830ULL)};
unsigned int b_0[16]={((unsigned int)590180491ULL),((unsigned int)3073107586ULL),((unsigned int)3783033615ULL),((unsigned int)1709119842ULL),((unsigned int)791555522ULL),((unsigned int)3308503149ULL),((unsigned int)3365351768ULL),((unsigned int)2371348542ULL),((unsigned int)1263256176ULL),((unsigned int)570566309ULL),((unsigned int)2239204192ULL),((unsigned int)2202867433ULL),((unsigned int)2953433642ULL),((unsigned int)2665621172ULL),((unsigned int)3291902973ULL),((unsigned int)629337830ULL)};
unsigned int a_1[4]={((unsigned int)3975685767ULL),((unsigned int)3947479117ULL),((unsigned int)2546805262ULL),((unsigned int)1738853001ULL)};
unsigned int b_1[4]={((unsigned int)3975685767ULL),((unsigned int)3947479117ULL),((unsigned int)2546805262ULL),((unsigned int)1738853001ULL)};
unsigned int a_2[4]={((unsigned int)592174406ULL),((unsigned int)3720081080ULL),((unsigned int)967581451ULL),((unsigned int)1015285739ULL)};
unsigned int b_2[4]={((unsigned int)592174406ULL),((unsigned int)3720081080ULL),((unsigned int)967581451ULL),((unsigned int)1015285739ULL)};
unsigned int a_3[4]={((unsigned int)4134985737ULL),((unsigned int)4035464930ULL),((unsigned int)4188694877ULL),((unsigned int)491118165ULL)};
unsigned int b_3[4]={((unsigned int)4134985737ULL),((unsigned int)4035464930ULL),((unsigned int)4188694877ULL),((unsigned int)491118165ULL)};
unsigned int a_4[4]={((unsigned int)2730516497ULL),((unsigned int)3395292896ULL),((unsigned int)2074449916ULL),((unsigned int)2851770942ULL)};
unsigned int b_4[4]={((unsigned int)2730516497ULL),((unsigned int)3395292896ULL),((unsigned int)2074449916ULL),((unsigned int)2851770942ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 209\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2410225221ULL),((unsigned int)4089935636ULL),((unsigned int)582403468ULL),((unsigned int)1894883292ULL),((unsigned int)1126889424ULL),((unsigned int)3511180731ULL),((unsigned int)2753033802ULL),((unsigned int)2786799444ULL),((unsigned int)3918083904ULL),((unsigned int)3901735380ULL),((unsigned int)2581415362ULL),((unsigned int)1140510554ULL),((unsigned int)282727393ULL),((unsigned int)47790994ULL),((unsigned int)2843368912ULL),((unsigned int)2537355562ULL)};
unsigned int b_0[16]={((unsigned int)2410225221ULL),((unsigned int)4089935636ULL),((unsigned int)582403468ULL),((unsigned int)1894883292ULL),((unsigned int)1126889424ULL),((unsigned int)3511180731ULL),((unsigned int)2753033802ULL),((unsigned int)2786799444ULL),((unsigned int)3918083904ULL),((unsigned int)3901735380ULL),((unsigned int)2581415362ULL),((unsigned int)1140510554ULL),((unsigned int)282727393ULL),((unsigned int)47790994ULL),((unsigned int)2843368912ULL),((unsigned int)2537355562ULL)};
unsigned int a_1[4]={((unsigned int)3904815630ULL),((unsigned int)1042566845ULL),((unsigned int)3526713587ULL),((unsigned int)3575976197ULL)};
unsigned int b_1[4]={((unsigned int)3904815630ULL),((unsigned int)1042566845ULL),((unsigned int)3526713587ULL),((unsigned int)3575976197ULL)};
unsigned int a_2[4]={((unsigned int)3743830957ULL),((unsigned int)602703353ULL),((unsigned int)2786321810ULL),((unsigned int)872563726ULL)};
unsigned int b_2[4]={((unsigned int)3743830957ULL),((unsigned int)602703353ULL),((unsigned int)2786321810ULL),((unsigned int)872563726ULL)};
unsigned int a_3[4]={((unsigned int)2298936325ULL),((unsigned int)3282294900ULL),((unsigned int)2619775616ULL),((unsigned int)1149922451ULL)};
unsigned int b_3[4]={((unsigned int)2298936325ULL),((unsigned int)3282294900ULL),((unsigned int)2619775616ULL),((unsigned int)1149922451ULL)};
unsigned int a_4[4]={((unsigned int)991075136ULL),((unsigned int)3041458384ULL),((unsigned int)899995946ULL),((unsigned int)1269908078ULL)};
unsigned int b_4[4]={((unsigned int)991075136ULL),((unsigned int)3041458384ULL),((unsigned int)899995946ULL),((unsigned int)1269908078ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 210\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2168009597ULL),((unsigned int)1353753350ULL),((unsigned int)1857149439ULL),((unsigned int)235013683ULL),((unsigned int)300913029ULL),((unsigned int)1170886153ULL),((unsigned int)301514157ULL),((unsigned int)582916826ULL),((unsigned int)1950678317ULL),((unsigned int)2023212944ULL),((unsigned int)14637435ULL),((unsigned int)3224837986ULL),((unsigned int)2911091758ULL),((unsigned int)74284100ULL),((unsigned int)3546734956ULL),((unsigned int)1666682776ULL)};
unsigned int b_0[16]={((unsigned int)2168009597ULL),((unsigned int)1353753350ULL),((unsigned int)1857149439ULL),((unsigned int)235013683ULL),((unsigned int)300913029ULL),((unsigned int)1170886153ULL),((unsigned int)301514157ULL),((unsigned int)582916826ULL),((unsigned int)1950678317ULL),((unsigned int)2023212944ULL),((unsigned int)14637435ULL),((unsigned int)3224837986ULL),((unsigned int)2911091758ULL),((unsigned int)74284100ULL),((unsigned int)3546734956ULL),((unsigned int)1666682776ULL)};
unsigned int a_1[4]={((unsigned int)1369083396ULL),((unsigned int)3955833191ULL),((unsigned int)1957947751ULL),((unsigned int)2573220365ULL)};
unsigned int b_1[4]={((unsigned int)1369083396ULL),((unsigned int)3955833191ULL),((unsigned int)1957947751ULL),((unsigned int)2573220365ULL)};
unsigned int a_2[4]={((unsigned int)1896270160ULL),((unsigned int)4117956084ULL),((unsigned int)2932611954ULL),((unsigned int)2704723700ULL)};
unsigned int b_2[4]={((unsigned int)1896270160ULL),((unsigned int)4117956084ULL),((unsigned int)2932611954ULL),((unsigned int)2704723700ULL)};
unsigned int a_3[4]={((unsigned int)3388967637ULL),((unsigned int)781515890ULL),((unsigned int)1183489754ULL),((unsigned int)2402580320ULL)};
unsigned int b_3[4]={((unsigned int)3388967637ULL),((unsigned int)781515890ULL),((unsigned int)1183489754ULL),((unsigned int)2402580320ULL)};
unsigned int a_4[4]={((unsigned int)446997376ULL),((unsigned int)2026092360ULL),((unsigned int)160016793ULL),((unsigned int)132625294ULL)};
unsigned int b_4[4]={((unsigned int)446997376ULL),((unsigned int)2026092360ULL),((unsigned int)160016793ULL),((unsigned int)132625294ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 211\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)934131050ULL),((unsigned int)3746152633ULL),((unsigned int)1566000422ULL),((unsigned int)1662411945ULL),((unsigned int)3842341132ULL),((unsigned int)3395253864ULL),((unsigned int)1124891138ULL),((unsigned int)3948478570ULL),((unsigned int)3166509896ULL),((unsigned int)1806712774ULL),((unsigned int)1042439238ULL),((unsigned int)2769585725ULL),((unsigned int)4214102288ULL),((unsigned int)2023250297ULL),((unsigned int)4095934060ULL),((unsigned int)1710990633ULL)};
unsigned int b_0[16]={((unsigned int)934131050ULL),((unsigned int)3746152633ULL),((unsigned int)1566000422ULL),((unsigned int)1662411945ULL),((unsigned int)3842341132ULL),((unsigned int)3395253864ULL),((unsigned int)1124891138ULL),((unsigned int)3948478570ULL),((unsigned int)3166509896ULL),((unsigned int)1806712774ULL),((unsigned int)1042439238ULL),((unsigned int)2769585725ULL),((unsigned int)4214102288ULL),((unsigned int)2023250297ULL),((unsigned int)4095934060ULL),((unsigned int)1710990633ULL)};
unsigned int a_1[4]={((unsigned int)3835152113ULL),((unsigned int)482295930ULL),((unsigned int)1988554071ULL),((unsigned int)4192930105ULL)};
unsigned int b_1[4]={((unsigned int)3835152113ULL),((unsigned int)482295930ULL),((unsigned int)1988554071ULL),((unsigned int)4192930105ULL)};
unsigned int a_2[4]={((unsigned int)3628469658ULL),((unsigned int)2666633341ULL),((unsigned int)2548395321ULL),((unsigned int)3800399954ULL)};
unsigned int b_2[4]={((unsigned int)3628469658ULL),((unsigned int)2666633341ULL),((unsigned int)2548395321ULL),((unsigned int)3800399954ULL)};
unsigned int a_3[4]={((unsigned int)2331585842ULL),((unsigned int)1715188188ULL),((unsigned int)4091887771ULL),((unsigned int)2752798014ULL)};
unsigned int b_3[4]={((unsigned int)2331585842ULL),((unsigned int)1715188188ULL),((unsigned int)4091887771ULL),((unsigned int)2752798014ULL)};
unsigned int a_4[4]={((unsigned int)495831983ULL),((unsigned int)4191987499ULL),((unsigned int)2449716212ULL),((unsigned int)2996666278ULL)};
unsigned int b_4[4]={((unsigned int)495831983ULL),((unsigned int)4191987499ULL),((unsigned int)2449716212ULL),((unsigned int)2996666278ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 212\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2391512497ULL),((unsigned int)3710309531ULL),((unsigned int)1658601330ULL),((unsigned int)252216220ULL),((unsigned int)3761102434ULL),((unsigned int)2656261908ULL),((unsigned int)2512784663ULL),((unsigned int)2873502785ULL),((unsigned int)2682895656ULL),((unsigned int)2374405535ULL),((unsigned int)988355861ULL),((unsigned int)598632679ULL),((unsigned int)2406881362ULL),((unsigned int)3623374808ULL),((unsigned int)3490247672ULL),((unsigned int)2634908611ULL)};
unsigned int b_0[16]={((unsigned int)2391512497ULL),((unsigned int)3710309531ULL),((unsigned int)1658601330ULL),((unsigned int)252216220ULL),((unsigned int)3761102434ULL),((unsigned int)2656261908ULL),((unsigned int)2512784663ULL),((unsigned int)2873502785ULL),((unsigned int)2682895656ULL),((unsigned int)2374405535ULL),((unsigned int)988355861ULL),((unsigned int)598632679ULL),((unsigned int)2406881362ULL),((unsigned int)3623374808ULL),((unsigned int)3490247672ULL),((unsigned int)2634908611ULL)};
unsigned int a_1[4]={((unsigned int)873534450ULL),((unsigned int)954117266ULL),((unsigned int)2090230580ULL),((unsigned int)1550893094ULL)};
unsigned int b_1[4]={((unsigned int)873534450ULL),((unsigned int)954117266ULL),((unsigned int)2090230580ULL),((unsigned int)1550893094ULL)};
unsigned int a_2[4]={((unsigned int)1723211806ULL),((unsigned int)1443054486ULL),((unsigned int)1445548796ULL),((unsigned int)759670132ULL)};
unsigned int b_2[4]={((unsigned int)1723211806ULL),((unsigned int)1443054486ULL),((unsigned int)1445548796ULL),((unsigned int)759670132ULL)};
unsigned int a_3[4]={((unsigned int)213949194ULL),((unsigned int)3912212433ULL),((unsigned int)2948155221ULL),((unsigned int)2163166664ULL)};
unsigned int b_3[4]={((unsigned int)213949194ULL),((unsigned int)3912212433ULL),((unsigned int)2948155221ULL),((unsigned int)2163166664ULL)};
unsigned int a_4[4]={((unsigned int)2576249592ULL),((unsigned int)1446322552ULL),((unsigned int)386350706ULL),((unsigned int)3092473391ULL)};
unsigned int b_4[4]={((unsigned int)2576249592ULL),((unsigned int)1446322552ULL),((unsigned int)386350706ULL),((unsigned int)3092473391ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 213\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1218986115ULL),((unsigned int)2666876507ULL),((unsigned int)2147271302ULL),((unsigned int)3110677982ULL),((unsigned int)1428374597ULL),((unsigned int)256551940ULL),((unsigned int)3951465640ULL),((unsigned int)4071352506ULL),((unsigned int)1954663453ULL),((unsigned int)1081616730ULL),((unsigned int)1722203010ULL),((unsigned int)1809510950ULL),((unsigned int)634972578ULL),((unsigned int)2606708890ULL),((unsigned int)1463761521ULL),((unsigned int)1688821362ULL)};
unsigned int b_0[16]={((unsigned int)1218986115ULL),((unsigned int)2666876507ULL),((unsigned int)2147271302ULL),((unsigned int)3110677982ULL),((unsigned int)1428374597ULL),((unsigned int)256551940ULL),((unsigned int)3951465640ULL),((unsigned int)4071352506ULL),((unsigned int)1954663453ULL),((unsigned int)1081616730ULL),((unsigned int)1722203010ULL),((unsigned int)1809510950ULL),((unsigned int)634972578ULL),((unsigned int)2606708890ULL),((unsigned int)1463761521ULL),((unsigned int)1688821362ULL)};
unsigned int a_1[4]={((unsigned int)243648175ULL),((unsigned int)1439763098ULL),((unsigned int)3782321471ULL),((unsigned int)3288646991ULL)};
unsigned int b_1[4]={((unsigned int)243648175ULL),((unsigned int)1439763098ULL),((unsigned int)3782321471ULL),((unsigned int)3288646991ULL)};
unsigned int a_2[4]={((unsigned int)2326594217ULL),((unsigned int)3267699997ULL),((unsigned int)1796240471ULL),((unsigned int)1049973938ULL)};
unsigned int b_2[4]={((unsigned int)2326594217ULL),((unsigned int)3267699997ULL),((unsigned int)1796240471ULL),((unsigned int)1049973938ULL)};
unsigned int a_3[4]={((unsigned int)2644613641ULL),((unsigned int)707862709ULL),((unsigned int)903112666ULL),((unsigned int)2543019481ULL)};
unsigned int b_3[4]={((unsigned int)2644613641ULL),((unsigned int)707862709ULL),((unsigned int)903112666ULL),((unsigned int)2543019481ULL)};
unsigned int a_4[4]={((unsigned int)3710751583ULL),((unsigned int)3993204394ULL),((unsigned int)2169812768ULL),((unsigned int)336117991ULL)};
unsigned int b_4[4]={((unsigned int)3710751583ULL),((unsigned int)3993204394ULL),((unsigned int)2169812768ULL),((unsigned int)336117991ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 214\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3850394795ULL),((unsigned int)974233962ULL),((unsigned int)2931146447ULL),((unsigned int)403367966ULL),((unsigned int)3704102849ULL),((unsigned int)1279579256ULL),((unsigned int)3890427473ULL),((unsigned int)422872017ULL),((unsigned int)993882478ULL),((unsigned int)4083684960ULL),((unsigned int)3749306972ULL),((unsigned int)4262056633ULL),((unsigned int)3126303397ULL),((unsigned int)2205928623ULL),((unsigned int)1698750318ULL),((unsigned int)3208767575ULL)};
unsigned int b_0[16]={((unsigned int)3850394795ULL),((unsigned int)974233962ULL),((unsigned int)2931146447ULL),((unsigned int)403367966ULL),((unsigned int)3704102849ULL),((unsigned int)1279579256ULL),((unsigned int)3890427473ULL),((unsigned int)422872017ULL),((unsigned int)993882478ULL),((unsigned int)4083684960ULL),((unsigned int)3749306972ULL),((unsigned int)4262056633ULL),((unsigned int)3126303397ULL),((unsigned int)2205928623ULL),((unsigned int)1698750318ULL),((unsigned int)3208767575ULL)};
unsigned int a_1[4]={((unsigned int)2801504017ULL),((unsigned int)3498636869ULL),((unsigned int)2986836780ULL),((unsigned int)2934488872ULL)};
unsigned int b_1[4]={((unsigned int)2801504017ULL),((unsigned int)3498636869ULL),((unsigned int)2986836780ULL),((unsigned int)2934488872ULL)};
unsigned int a_2[4]={((unsigned int)2367397451ULL),((unsigned int)2628994235ULL),((unsigned int)2922155025ULL),((unsigned int)3871335887ULL)};
unsigned int b_2[4]={((unsigned int)2367397451ULL),((unsigned int)2628994235ULL),((unsigned int)2922155025ULL),((unsigned int)3871335887ULL)};
unsigned int a_3[4]={((unsigned int)1163267423ULL),((unsigned int)979825752ULL),((unsigned int)1180074471ULL),((unsigned int)2576861239ULL)};
unsigned int b_3[4]={((unsigned int)1163267423ULL),((unsigned int)979825752ULL),((unsigned int)1180074471ULL),((unsigned int)2576861239ULL)};
unsigned int a_4[4]={((unsigned int)1975013647ULL),((unsigned int)526558844ULL),((unsigned int)3309099849ULL),((unsigned int)2314595976ULL)};
unsigned int b_4[4]={((unsigned int)1975013647ULL),((unsigned int)526558844ULL),((unsigned int)3309099849ULL),((unsigned int)2314595976ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 215\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3739088626ULL),((unsigned int)22272645ULL),((unsigned int)1937963022ULL),((unsigned int)4287911401ULL),((unsigned int)2669284876ULL),((unsigned int)2557326027ULL),((unsigned int)1508657934ULL),((unsigned int)2724963046ULL),((unsigned int)3206328898ULL),((unsigned int)3247260002ULL),((unsigned int)4062287362ULL),((unsigned int)1083067198ULL),((unsigned int)3364683037ULL),((unsigned int)4106925925ULL),((unsigned int)1581502450ULL),((unsigned int)4160939180ULL)};
unsigned int b_0[16]={((unsigned int)3739088626ULL),((unsigned int)22272645ULL),((unsigned int)1937963022ULL),((unsigned int)4287911401ULL),((unsigned int)2669284876ULL),((unsigned int)2557326027ULL),((unsigned int)1508657934ULL),((unsigned int)2724963046ULL),((unsigned int)3206328898ULL),((unsigned int)3247260002ULL),((unsigned int)4062287362ULL),((unsigned int)1083067198ULL),((unsigned int)3364683037ULL),((unsigned int)4106925925ULL),((unsigned int)1581502450ULL),((unsigned int)4160939180ULL)};
unsigned int a_1[4]={((unsigned int)3850237643ULL),((unsigned int)737471667ULL),((unsigned int)3243137612ULL),((unsigned int)3865706011ULL)};
unsigned int b_1[4]={((unsigned int)3850237643ULL),((unsigned int)737471667ULL),((unsigned int)3243137612ULL),((unsigned int)3865706011ULL)};
unsigned int a_2[4]={((unsigned int)2746714780ULL),((unsigned int)1119047257ULL),((unsigned int)2289593530ULL),((unsigned int)3705293610ULL)};
unsigned int b_2[4]={((unsigned int)2746714780ULL),((unsigned int)1119047257ULL),((unsigned int)2289593530ULL),((unsigned int)3705293610ULL)};
unsigned int a_3[4]={((unsigned int)2203956259ULL),((unsigned int)1191613197ULL),((unsigned int)3693345885ULL),((unsigned int)4103652385ULL)};
unsigned int b_3[4]={((unsigned int)2203956259ULL),((unsigned int)1191613197ULL),((unsigned int)3693345885ULL),((unsigned int)4103652385ULL)};
unsigned int a_4[4]={((unsigned int)881976023ULL),((unsigned int)1516707706ULL),((unsigned int)460033242ULL),((unsigned int)3135741537ULL)};
unsigned int b_4[4]={((unsigned int)881976023ULL),((unsigned int)1516707706ULL),((unsigned int)460033242ULL),((unsigned int)3135741537ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 216\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)4026550368ULL),((unsigned int)476906531ULL),((unsigned int)2734299260ULL),((unsigned int)866388770ULL),((unsigned int)4122676071ULL),((unsigned int)1013507983ULL),((unsigned int)3941585077ULL),((unsigned int)4167601717ULL),((unsigned int)1441376638ULL),((unsigned int)149032664ULL),((unsigned int)562991166ULL),((unsigned int)2836529631ULL),((unsigned int)457798656ULL),((unsigned int)1593722158ULL),((unsigned int)922969356ULL),((unsigned int)3061630828ULL)};
unsigned int b_0[16]={((unsigned int)4026550368ULL),((unsigned int)476906531ULL),((unsigned int)2734299260ULL),((unsigned int)866388770ULL),((unsigned int)4122676071ULL),((unsigned int)1013507983ULL),((unsigned int)3941585077ULL),((unsigned int)4167601717ULL),((unsigned int)1441376638ULL),((unsigned int)149032664ULL),((unsigned int)562991166ULL),((unsigned int)2836529631ULL),((unsigned int)457798656ULL),((unsigned int)1593722158ULL),((unsigned int)922969356ULL),((unsigned int)3061630828ULL)};
unsigned int a_1[4]={((unsigned int)373253805ULL),((unsigned int)567578701ULL),((unsigned int)2099682644ULL),((unsigned int)3345150997ULL)};
unsigned int b_1[4]={((unsigned int)373253805ULL),((unsigned int)567578701ULL),((unsigned int)2099682644ULL),((unsigned int)3345150997ULL)};
unsigned int a_2[4]={((unsigned int)61489754ULL),((unsigned int)261521383ULL),((unsigned int)3630715154ULL),((unsigned int)2032764667ULL)};
unsigned int b_2[4]={((unsigned int)61489754ULL),((unsigned int)261521383ULL),((unsigned int)3630715154ULL),((unsigned int)2032764667ULL)};
unsigned int a_3[4]={((unsigned int)1710881072ULL),((unsigned int)1051591966ULL),((unsigned int)416499611ULL),((unsigned int)3989913509ULL)};
unsigned int b_3[4]={((unsigned int)1710881072ULL),((unsigned int)1051591966ULL),((unsigned int)416499611ULL),((unsigned int)3989913509ULL)};
unsigned int a_4[4]={((unsigned int)3274233705ULL),((unsigned int)321580135ULL),((unsigned int)1529668785ULL),((unsigned int)3602629921ULL)};
unsigned int b_4[4]={((unsigned int)3274233705ULL),((unsigned int)321580135ULL),((unsigned int)1529668785ULL),((unsigned int)3602629921ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 217\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)904633268ULL),((unsigned int)2597375502ULL),((unsigned int)2109503871ULL),((unsigned int)914799536ULL),((unsigned int)3144179535ULL),((unsigned int)2395051374ULL),((unsigned int)2448843220ULL),((unsigned int)3697095971ULL),((unsigned int)4093662067ULL),((unsigned int)2044965494ULL),((unsigned int)1068660404ULL),((unsigned int)2411210673ULL),((unsigned int)1105847879ULL),((unsigned int)3614558420ULL),((unsigned int)3830690756ULL),((unsigned int)1861576442ULL)};
unsigned int b_0[16]={((unsigned int)904633268ULL),((unsigned int)2597375502ULL),((unsigned int)2109503871ULL),((unsigned int)914799536ULL),((unsigned int)3144179535ULL),((unsigned int)2395051374ULL),((unsigned int)2448843220ULL),((unsigned int)3697095971ULL),((unsigned int)4093662067ULL),((unsigned int)2044965494ULL),((unsigned int)1068660404ULL),((unsigned int)2411210673ULL),((unsigned int)1105847879ULL),((unsigned int)3614558420ULL),((unsigned int)3830690756ULL),((unsigned int)1861576442ULL)};
unsigned int a_1[4]={((unsigned int)923094664ULL),((unsigned int)2904551927ULL),((unsigned int)1097864471ULL),((unsigned int)1326059771ULL)};
unsigned int b_1[4]={((unsigned int)923094664ULL),((unsigned int)2904551927ULL),((unsigned int)1097864471ULL),((unsigned int)1326059771ULL)};
unsigned int a_2[4]={((unsigned int)632542993ULL),((unsigned int)1961466418ULL),((unsigned int)1784330663ULL),((unsigned int)3511710145ULL)};
unsigned int b_2[4]={((unsigned int)632542993ULL),((unsigned int)1961466418ULL),((unsigned int)1784330663ULL),((unsigned int)3511710145ULL)};
unsigned int a_3[4]={((unsigned int)2736885847ULL),((unsigned int)239700957ULL),((unsigned int)3720185637ULL),((unsigned int)2582434801ULL)};
unsigned int b_3[4]={((unsigned int)2736885847ULL),((unsigned int)239700957ULL),((unsigned int)3720185637ULL),((unsigned int)2582434801ULL)};
unsigned int a_4[4]={((unsigned int)1038964235ULL),((unsigned int)2682031137ULL),((unsigned int)1165604215ULL),((unsigned int)2968437741ULL)};
unsigned int b_4[4]={((unsigned int)1038964235ULL),((unsigned int)2682031137ULL),((unsigned int)1165604215ULL),((unsigned int)2968437741ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 218\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1744821849ULL),((unsigned int)4220809813ULL),((unsigned int)1381725270ULL),((unsigned int)1027298576ULL),((unsigned int)2562736688ULL),((unsigned int)504406404ULL),((unsigned int)1523158348ULL),((unsigned int)2547741633ULL),((unsigned int)3024963228ULL),((unsigned int)3082020127ULL),((unsigned int)780919807ULL),((unsigned int)1668198233ULL),((unsigned int)687568530ULL),((unsigned int)3757006469ULL),((unsigned int)3784550482ULL),((unsigned int)2116894098ULL)};
unsigned int b_0[16]={((unsigned int)1744821849ULL),((unsigned int)4220809813ULL),((unsigned int)1381725270ULL),((unsigned int)1027298576ULL),((unsigned int)2562736688ULL),((unsigned int)504406404ULL),((unsigned int)1523158348ULL),((unsigned int)2547741633ULL),((unsigned int)3024963228ULL),((unsigned int)3082020127ULL),((unsigned int)780919807ULL),((unsigned int)1668198233ULL),((unsigned int)687568530ULL),((unsigned int)3757006469ULL),((unsigned int)3784550482ULL),((unsigned int)2116894098ULL)};
unsigned int a_1[4]={((unsigned int)82116856ULL),((unsigned int)287743045ULL),((unsigned int)1820899540ULL),((unsigned int)3076123207ULL)};
unsigned int b_1[4]={((unsigned int)82116856ULL),((unsigned int)287743045ULL),((unsigned int)1820899540ULL),((unsigned int)3076123207ULL)};
unsigned int a_2[4]={((unsigned int)3443240752ULL),((unsigned int)851788080ULL),((unsigned int)762758345ULL),((unsigned int)4112794326ULL)};
unsigned int b_2[4]={((unsigned int)3443240752ULL),((unsigned int)851788080ULL),((unsigned int)762758345ULL),((unsigned int)4112794326ULL)};
unsigned int a_3[4]={((unsigned int)2893337520ULL),((unsigned int)1343910073ULL),((unsigned int)3428990147ULL),((unsigned int)140765685ULL)};
unsigned int b_3[4]={((unsigned int)2893337520ULL),((unsigned int)1343910073ULL),((unsigned int)3428990147ULL),((unsigned int)140765685ULL)};
unsigned int a_4[4]={((unsigned int)3378141167ULL),((unsigned int)872645447ULL),((unsigned int)1155229687ULL),((unsigned int)951656628ULL)};
unsigned int b_4[4]={((unsigned int)3378141167ULL),((unsigned int)872645447ULL),((unsigned int)1155229687ULL),((unsigned int)951656628ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 219\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3625622019ULL),((unsigned int)4106920299ULL),((unsigned int)165261065ULL),((unsigned int)527706347ULL),((unsigned int)2941541954ULL),((unsigned int)3734572672ULL),((unsigned int)2363980337ULL),((unsigned int)3732776683ULL),((unsigned int)633254063ULL),((unsigned int)4121630847ULL),((unsigned int)2467409289ULL),((unsigned int)2055003390ULL),((unsigned int)1444700685ULL),((unsigned int)489763446ULL),((unsigned int)687346284ULL),((unsigned int)1187348548ULL)};
unsigned int b_0[16]={((unsigned int)3625622019ULL),((unsigned int)4106920299ULL),((unsigned int)165261065ULL),((unsigned int)527706347ULL),((unsigned int)2941541954ULL),((unsigned int)3734572672ULL),((unsigned int)2363980337ULL),((unsigned int)3732776683ULL),((unsigned int)633254063ULL),((unsigned int)4121630847ULL),((unsigned int)2467409289ULL),((unsigned int)2055003390ULL),((unsigned int)1444700685ULL),((unsigned int)489763446ULL),((unsigned int)687346284ULL),((unsigned int)1187348548ULL)};
unsigned int a_1[4]={((unsigned int)2571046836ULL),((unsigned int)2532498628ULL),((unsigned int)2099584624ULL),((unsigned int)986128128ULL)};
unsigned int b_1[4]={((unsigned int)2571046836ULL),((unsigned int)2532498628ULL),((unsigned int)2099584624ULL),((unsigned int)986128128ULL)};
unsigned int a_2[4]={((unsigned int)509009296ULL),((unsigned int)2546253099ULL),((unsigned int)1174415880ULL),((unsigned int)614999227ULL)};
unsigned int b_2[4]={((unsigned int)509009296ULL),((unsigned int)2546253099ULL),((unsigned int)1174415880ULL),((unsigned int)614999227ULL)};
unsigned int a_3[4]={((unsigned int)510698411ULL),((unsigned int)3824605863ULL),((unsigned int)2177012280ULL),((unsigned int)1478257735ULL)};
unsigned int b_3[4]={((unsigned int)510698411ULL),((unsigned int)3824605863ULL),((unsigned int)2177012280ULL),((unsigned int)1478257735ULL)};
unsigned int a_4[4]={((unsigned int)1731024851ULL),((unsigned int)3212576252ULL),((unsigned int)114204033ULL),((unsigned int)74005713ULL)};
unsigned int b_4[4]={((unsigned int)1731024851ULL),((unsigned int)3212576252ULL),((unsigned int)114204033ULL),((unsigned int)74005713ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 220\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)577679607ULL),((unsigned int)251718449ULL),((unsigned int)1717666277ULL),((unsigned int)2100930822ULL),((unsigned int)772374163ULL),((unsigned int)2656698169ULL),((unsigned int)3513075939ULL),((unsigned int)3641890487ULL),((unsigned int)2357207379ULL),((unsigned int)3914378165ULL),((unsigned int)3947894097ULL),((unsigned int)1117721484ULL),((unsigned int)785361166ULL),((unsigned int)774403992ULL),((unsigned int)1839705616ULL),((unsigned int)1347954108ULL)};
unsigned int b_0[16]={((unsigned int)577679607ULL),((unsigned int)251718449ULL),((unsigned int)1717666277ULL),((unsigned int)2100930822ULL),((unsigned int)772374163ULL),((unsigned int)2656698169ULL),((unsigned int)3513075939ULL),((unsigned int)3641890487ULL),((unsigned int)2357207379ULL),((unsigned int)3914378165ULL),((unsigned int)3947894097ULL),((unsigned int)1117721484ULL),((unsigned int)785361166ULL),((unsigned int)774403992ULL),((unsigned int)1839705616ULL),((unsigned int)1347954108ULL)};
unsigned int a_1[4]={((unsigned int)2729040026ULL),((unsigned int)3344592315ULL),((unsigned int)1984311246ULL),((unsigned int)1141172613ULL)};
unsigned int b_1[4]={((unsigned int)2729040026ULL),((unsigned int)3344592315ULL),((unsigned int)1984311246ULL),((unsigned int)1141172613ULL)};
unsigned int a_2[4]={((unsigned int)2831585632ULL),((unsigned int)1095130698ULL),((unsigned int)161738656ULL),((unsigned int)4152188083ULL)};
unsigned int b_2[4]={((unsigned int)2831585632ULL),((unsigned int)1095130698ULL),((unsigned int)161738656ULL),((unsigned int)4152188083ULL)};
unsigned int a_3[4]={((unsigned int)3446924994ULL),((unsigned int)2477125228ULL),((unsigned int)767295801ULL),((unsigned int)3060453192ULL)};
unsigned int b_3[4]={((unsigned int)3446924994ULL),((unsigned int)2477125228ULL),((unsigned int)767295801ULL),((unsigned int)3060453192ULL)};
unsigned int a_4[4]={((unsigned int)267979896ULL),((unsigned int)911112818ULL),((unsigned int)3877975645ULL),((unsigned int)2303164049ULL)};
unsigned int b_4[4]={((unsigned int)267979896ULL),((unsigned int)911112818ULL),((unsigned int)3877975645ULL),((unsigned int)2303164049ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 221\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3525745613ULL),((unsigned int)4183987466ULL),((unsigned int)2815104938ULL),((unsigned int)474986532ULL),((unsigned int)359391504ULL),((unsigned int)2265607884ULL),((unsigned int)2864795680ULL),((unsigned int)4293813203ULL),((unsigned int)2123016525ULL),((unsigned int)1887035327ULL),((unsigned int)3344053505ULL),((unsigned int)2297802794ULL),((unsigned int)1006290687ULL),((unsigned int)585433557ULL),((unsigned int)3413270231ULL),((unsigned int)3970606292ULL)};
unsigned int b_0[16]={((unsigned int)3525745613ULL),((unsigned int)4183987466ULL),((unsigned int)2815104938ULL),((unsigned int)474986532ULL),((unsigned int)359391504ULL),((unsigned int)2265607884ULL),((unsigned int)2864795680ULL),((unsigned int)4293813203ULL),((unsigned int)2123016525ULL),((unsigned int)1887035327ULL),((unsigned int)3344053505ULL),((unsigned int)2297802794ULL),((unsigned int)1006290687ULL),((unsigned int)585433557ULL),((unsigned int)3413270231ULL),((unsigned int)3970606292ULL)};
unsigned int a_1[4]={((unsigned int)3037492537ULL),((unsigned int)3636171681ULL),((unsigned int)1789798300ULL),((unsigned int)814324277ULL)};
unsigned int b_1[4]={((unsigned int)3037492537ULL),((unsigned int)3636171681ULL),((unsigned int)1789798300ULL),((unsigned int)814324277ULL)};
unsigned int a_2[4]={((unsigned int)547524661ULL),((unsigned int)1528875852ULL),((unsigned int)1322402403ULL),((unsigned int)3502314817ULL)};
unsigned int b_2[4]={((unsigned int)547524661ULL),((unsigned int)1528875852ULL),((unsigned int)1322402403ULL),((unsigned int)3502314817ULL)};
unsigned int a_3[4]={((unsigned int)3823036005ULL),((unsigned int)1305211599ULL),((unsigned int)3420663382ULL),((unsigned int)370812620ULL)};
unsigned int b_3[4]={((unsigned int)3823036005ULL),((unsigned int)1305211599ULL),((unsigned int)3420663382ULL),((unsigned int)370812620ULL)};
unsigned int a_4[4]={((unsigned int)3128845272ULL),((unsigned int)2492659171ULL),((unsigned int)2223177931ULL),((unsigned int)2418929748ULL)};
unsigned int b_4[4]={((unsigned int)3128845272ULL),((unsigned int)2492659171ULL),((unsigned int)2223177931ULL),((unsigned int)2418929748ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 222\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3378687256ULL),((unsigned int)1731450022ULL),((unsigned int)1994658324ULL),((unsigned int)839656209ULL),((unsigned int)250485235ULL),((unsigned int)4187464831ULL),((unsigned int)1711707787ULL),((unsigned int)2253810584ULL),((unsigned int)2108022468ULL),((unsigned int)1732503597ULL),((unsigned int)577430432ULL),((unsigned int)2747629621ULL),((unsigned int)2739002733ULL),((unsigned int)3694797107ULL),((unsigned int)3495294621ULL),((unsigned int)3492900381ULL)};
unsigned int b_0[16]={((unsigned int)3378687256ULL),((unsigned int)1731450022ULL),((unsigned int)1994658324ULL),((unsigned int)839656209ULL),((unsigned int)250485235ULL),((unsigned int)4187464831ULL),((unsigned int)1711707787ULL),((unsigned int)2253810584ULL),((unsigned int)2108022468ULL),((unsigned int)1732503597ULL),((unsigned int)577430432ULL),((unsigned int)2747629621ULL),((unsigned int)2739002733ULL),((unsigned int)3694797107ULL),((unsigned int)3495294621ULL),((unsigned int)3492900381ULL)};
unsigned int a_1[4]={((unsigned int)1490009151ULL),((unsigned int)2399293191ULL),((unsigned int)3069473025ULL),((unsigned int)1488038954ULL)};
unsigned int b_1[4]={((unsigned int)1490009151ULL),((unsigned int)2399293191ULL),((unsigned int)3069473025ULL),((unsigned int)1488038954ULL)};
unsigned int a_2[4]={((unsigned int)2694965055ULL),((unsigned int)250416457ULL),((unsigned int)1394914274ULL),((unsigned int)3384238646ULL)};
unsigned int b_2[4]={((unsigned int)2694965055ULL),((unsigned int)250416457ULL),((unsigned int)1394914274ULL),((unsigned int)3384238646ULL)};
unsigned int a_3[4]={((unsigned int)914968102ULL),((unsigned int)36903792ULL),((unsigned int)374631615ULL),((unsigned int)584386290ULL)};
unsigned int b_3[4]={((unsigned int)914968102ULL),((unsigned int)36903792ULL),((unsigned int)374631615ULL),((unsigned int)584386290ULL)};
unsigned int a_4[4]={((unsigned int)344097781ULL),((unsigned int)215448860ULL),((unsigned int)3681083613ULL),((unsigned int)398191240ULL)};
unsigned int b_4[4]={((unsigned int)344097781ULL),((unsigned int)215448860ULL),((unsigned int)3681083613ULL),((unsigned int)398191240ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 223\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1971864775ULL),((unsigned int)359530898ULL),((unsigned int)2201765197ULL),((unsigned int)1983513897ULL),((unsigned int)3255284140ULL),((unsigned int)1477076516ULL),((unsigned int)399427753ULL),((unsigned int)3888290664ULL),((unsigned int)357073524ULL),((unsigned int)2019193020ULL),((unsigned int)2206737244ULL),((unsigned int)1012965660ULL),((unsigned int)3312965972ULL),((unsigned int)3344930375ULL),((unsigned int)3304048850ULL),((unsigned int)1957306891ULL)};
unsigned int b_0[16]={((unsigned int)1971864775ULL),((unsigned int)359530898ULL),((unsigned int)2201765197ULL),((unsigned int)1983513897ULL),((unsigned int)3255284140ULL),((unsigned int)1477076516ULL),((unsigned int)399427753ULL),((unsigned int)3888290664ULL),((unsigned int)357073524ULL),((unsigned int)2019193020ULL),((unsigned int)2206737244ULL),((unsigned int)1012965660ULL),((unsigned int)3312965972ULL),((unsigned int)3344930375ULL),((unsigned int)3304048850ULL),((unsigned int)1957306891ULL)};
unsigned int a_1[4]={((unsigned int)1401228170ULL),((unsigned int)2497066828ULL),((unsigned int)1149335426ULL),((unsigned int)1892622511ULL)};
unsigned int b_1[4]={((unsigned int)1401228170ULL),((unsigned int)2497066828ULL),((unsigned int)1149335426ULL),((unsigned int)1892622511ULL)};
unsigned int a_2[4]={((unsigned int)1025304494ULL),((unsigned int)1422672971ULL),((unsigned int)190641498ULL),((unsigned int)1734698305ULL)};
unsigned int b_2[4]={((unsigned int)1025304494ULL),((unsigned int)1422672971ULL),((unsigned int)190641498ULL),((unsigned int)1734698305ULL)};
unsigned int a_3[4]={((unsigned int)3462104312ULL),((unsigned int)3378404865ULL),((unsigned int)3112820660ULL),((unsigned int)2163837291ULL)};
unsigned int b_3[4]={((unsigned int)3462104312ULL),((unsigned int)3378404865ULL),((unsigned int)3112820660ULL),((unsigned int)2163837291ULL)};
unsigned int a_4[4]={((unsigned int)3380468746ULL),((unsigned int)739231995ULL),((unsigned int)2165879841ULL),((unsigned int)1796727443ULL)};
unsigned int b_4[4]={((unsigned int)3380468746ULL),((unsigned int)739231995ULL),((unsigned int)2165879841ULL),((unsigned int)1796727443ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 224\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1056912962ULL),((unsigned int)185105393ULL),((unsigned int)1520420163ULL),((unsigned int)2464807899ULL),((unsigned int)1061626196ULL),((unsigned int)1806761304ULL),((unsigned int)1404598626ULL),((unsigned int)524489124ULL),((unsigned int)3140873947ULL),((unsigned int)2385402204ULL),((unsigned int)1432080386ULL),((unsigned int)108457819ULL),((unsigned int)4169165140ULL),((unsigned int)3360360585ULL),((unsigned int)3981448162ULL),((unsigned int)203012675ULL)};
unsigned int b_0[16]={((unsigned int)1056912962ULL),((unsigned int)185105393ULL),((unsigned int)1520420163ULL),((unsigned int)2464807899ULL),((unsigned int)1061626196ULL),((unsigned int)1806761304ULL),((unsigned int)1404598626ULL),((unsigned int)524489124ULL),((unsigned int)3140873947ULL),((unsigned int)2385402204ULL),((unsigned int)1432080386ULL),((unsigned int)108457819ULL),((unsigned int)4169165140ULL),((unsigned int)3360360585ULL),((unsigned int)3981448162ULL),((unsigned int)203012675ULL)};
unsigned int a_1[4]={((unsigned int)1858458946ULL),((unsigned int)3528453946ULL),((unsigned int)4059153241ULL),((unsigned int)2276607826ULL)};
unsigned int b_1[4]={((unsigned int)1858458946ULL),((unsigned int)3528453946ULL),((unsigned int)4059153241ULL),((unsigned int)2276607826ULL)};
unsigned int a_2[4]={((unsigned int)4112682661ULL),((unsigned int)2288288766ULL),((unsigned int)1774566152ULL),((unsigned int)2038645738ULL)};
unsigned int b_2[4]={((unsigned int)4112682661ULL),((unsigned int)2288288766ULL),((unsigned int)1774566152ULL),((unsigned int)2038645738ULL)};
unsigned int a_3[4]={((unsigned int)1672735522ULL),((unsigned int)2510434127ULL),((unsigned int)1103727984ULL),((unsigned int)3615443226ULL)};
unsigned int b_3[4]={((unsigned int)1672735522ULL),((unsigned int)2510434127ULL),((unsigned int)1103727984ULL),((unsigned int)3615443226ULL)};
unsigned int a_4[4]={((unsigned int)1337469057ULL),((unsigned int)1224240942ULL),((unsigned int)4291784829ULL),((unsigned int)3463361320ULL)};
unsigned int b_4[4]={((unsigned int)1337469057ULL),((unsigned int)1224240942ULL),((unsigned int)4291784829ULL),((unsigned int)3463361320ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 225\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1468345090ULL),((unsigned int)4137801212ULL),((unsigned int)3638410740ULL),((unsigned int)2124070318ULL),((unsigned int)1145129440ULL),((unsigned int)3521745702ULL),((unsigned int)480142615ULL),((unsigned int)2412300132ULL),((unsigned int)1589370605ULL),((unsigned int)1031745209ULL),((unsigned int)2799233580ULL),((unsigned int)840751499ULL),((unsigned int)436992653ULL),((unsigned int)3869048571ULL),((unsigned int)2392918916ULL),((unsigned int)1057358381ULL)};
unsigned int b_0[16]={((unsigned int)1468345090ULL),((unsigned int)4137801212ULL),((unsigned int)3638410740ULL),((unsigned int)2124070318ULL),((unsigned int)1145129440ULL),((unsigned int)3521745702ULL),((unsigned int)480142615ULL),((unsigned int)2412300132ULL),((unsigned int)1589370605ULL),((unsigned int)1031745209ULL),((unsigned int)2799233580ULL),((unsigned int)840751499ULL),((unsigned int)436992653ULL),((unsigned int)3869048571ULL),((unsigned int)2392918916ULL),((unsigned int)1057358381ULL)};
unsigned int a_1[4]={((unsigned int)3486518300ULL),((unsigned int)2752992532ULL),((unsigned int)1941645540ULL),((unsigned int)2599210674ULL)};
unsigned int b_1[4]={((unsigned int)3486518300ULL),((unsigned int)2752992532ULL),((unsigned int)1941645540ULL),((unsigned int)2599210674ULL)};
unsigned int a_2[4]={((unsigned int)531134790ULL),((unsigned int)1714264536ULL),((unsigned int)399991968ULL),((unsigned int)1099260600ULL)};
unsigned int b_2[4]={((unsigned int)531134790ULL),((unsigned int)1714264536ULL),((unsigned int)399991968ULL),((unsigned int)1099260600ULL)};
unsigned int a_3[4]={((unsigned int)3686252304ULL),((unsigned int)1850683168ULL),((unsigned int)3647365978ULL),((unsigned int)40041063ULL)};
unsigned int b_3[4]={((unsigned int)3686252304ULL),((unsigned int)1850683168ULL),((unsigned int)3647365978ULL),((unsigned int)40041063ULL)};
unsigned int a_4[4]={((unsigned int)1015079434ULL),((unsigned int)1472815309ULL),((unsigned int)1815945701ULL),((unsigned int)1871549258ULL)};
unsigned int b_4[4]={((unsigned int)1015079434ULL),((unsigned int)1472815309ULL),((unsigned int)1815945701ULL),((unsigned int)1871549258ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 226\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)845635403ULL),((unsigned int)477791159ULL),((unsigned int)1341443392ULL),((unsigned int)1103666866ULL),((unsigned int)4164937190ULL),((unsigned int)3490094630ULL),((unsigned int)2284331428ULL),((unsigned int)2408531809ULL),((unsigned int)2775930475ULL),((unsigned int)1638653145ULL),((unsigned int)986829438ULL),((unsigned int)2767132449ULL),((unsigned int)3171587132ULL),((unsigned int)4247387900ULL),((unsigned int)362503994ULL),((unsigned int)3157854385ULL)};
unsigned int b_0[16]={((unsigned int)845635403ULL),((unsigned int)477791159ULL),((unsigned int)1341443392ULL),((unsigned int)1103666866ULL),((unsigned int)4164937190ULL),((unsigned int)3490094630ULL),((unsigned int)2284331428ULL),((unsigned int)2408531809ULL),((unsigned int)2775930475ULL),((unsigned int)1638653145ULL),((unsigned int)986829438ULL),((unsigned int)2767132449ULL),((unsigned int)3171587132ULL),((unsigned int)4247387900ULL),((unsigned int)362503994ULL),((unsigned int)3157854385ULL)};
unsigned int a_1[4]={((unsigned int)3597567036ULL),((unsigned int)2516825537ULL),((unsigned int)754752085ULL),((unsigned int)1114343117ULL)};
unsigned int b_1[4]={((unsigned int)3597567036ULL),((unsigned int)2516825537ULL),((unsigned int)754752085ULL),((unsigned int)1114343117ULL)};
unsigned int a_2[4]={((unsigned int)1504834118ULL),((unsigned int)1313306460ULL),((unsigned int)2529241006ULL),((unsigned int)2797536183ULL)};
unsigned int b_2[4]={((unsigned int)1504834118ULL),((unsigned int)1313306460ULL),((unsigned int)2529241006ULL),((unsigned int)2797536183ULL)};
unsigned int a_3[4]={((unsigned int)434883351ULL),((unsigned int)1892868879ULL),((unsigned int)3827627091ULL),((unsigned int)3976925273ULL)};
unsigned int b_3[4]={((unsigned int)434883351ULL),((unsigned int)1892868879ULL),((unsigned int)3827627091ULL),((unsigned int)3976925273ULL)};
unsigned int a_4[4]={((unsigned int)3371244435ULL),((unsigned int)4166870939ULL),((unsigned int)376203340ULL),((unsigned int)3840914839ULL)};
unsigned int b_4[4]={((unsigned int)3371244435ULL),((unsigned int)4166870939ULL),((unsigned int)376203340ULL),((unsigned int)3840914839ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 227\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3252868053ULL),((unsigned int)794542909ULL),((unsigned int)4104854575ULL),((unsigned int)3992194728ULL),((unsigned int)3677862439ULL),((unsigned int)4267371205ULL),((unsigned int)1532686041ULL),((unsigned int)4235612125ULL),((unsigned int)3591492096ULL),((unsigned int)1237610750ULL),((unsigned int)1491642989ULL),((unsigned int)1386534329ULL),((unsigned int)1524366120ULL),((unsigned int)3244072264ULL),((unsigned int)3720966000ULL),((unsigned int)1170716186ULL)};
unsigned int b_0[16]={((unsigned int)3252868053ULL),((unsigned int)794542909ULL),((unsigned int)4104854575ULL),((unsigned int)3992194728ULL),((unsigned int)3677862439ULL),((unsigned int)4267371205ULL),((unsigned int)1532686041ULL),((unsigned int)4235612125ULL),((unsigned int)3591492096ULL),((unsigned int)1237610750ULL),((unsigned int)1491642989ULL),((unsigned int)1386534329ULL),((unsigned int)1524366120ULL),((unsigned int)3244072264ULL),((unsigned int)3720966000ULL),((unsigned int)1170716186ULL)};
unsigned int a_1[4]={((unsigned int)243598904ULL),((unsigned int)3621895594ULL),((unsigned int)655973636ULL),((unsigned int)1104685037ULL)};
unsigned int b_1[4]={((unsigned int)243598904ULL),((unsigned int)3621895594ULL),((unsigned int)655973636ULL),((unsigned int)1104685037ULL)};
unsigned int a_2[4]={((unsigned int)1914386671ULL),((unsigned int)2287034807ULL),((unsigned int)3888353758ULL),((unsigned int)1847578101ULL)};
unsigned int b_2[4]={((unsigned int)1914386671ULL),((unsigned int)2287034807ULL),((unsigned int)3888353758ULL),((unsigned int)1847578101ULL)};
unsigned int a_3[4]={((unsigned int)1536765923ULL),((unsigned int)3003643806ULL),((unsigned int)4109787637ULL),((unsigned int)498949142ULL)};
unsigned int b_3[4]={((unsigned int)1536765923ULL),((unsigned int)3003643806ULL),((unsigned int)4109787637ULL),((unsigned int)498949142ULL)};
unsigned int a_4[4]={((unsigned int)2754359199ULL),((unsigned int)2176400774ULL),((unsigned int)1456411255ULL),((unsigned int)1868706645ULL)};
unsigned int b_4[4]={((unsigned int)2754359199ULL),((unsigned int)2176400774ULL),((unsigned int)1456411255ULL),((unsigned int)1868706645ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 228\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1991221623ULL),((unsigned int)598993158ULL),((unsigned int)2609789768ULL),((unsigned int)1191686416ULL),((unsigned int)3463002658ULL),((unsigned int)2829529911ULL),((unsigned int)530333161ULL),((unsigned int)417443635ULL),((unsigned int)1890458480ULL),((unsigned int)959913783ULL),((unsigned int)2912942556ULL),((unsigned int)2426330149ULL),((unsigned int)1434990684ULL),((unsigned int)3583325506ULL),((unsigned int)715228930ULL),((unsigned int)1774256516ULL)};
unsigned int b_0[16]={((unsigned int)1991221623ULL),((unsigned int)598993158ULL),((unsigned int)2609789768ULL),((unsigned int)1191686416ULL),((unsigned int)3463002658ULL),((unsigned int)2829529911ULL),((unsigned int)530333161ULL),((unsigned int)417443635ULL),((unsigned int)1890458480ULL),((unsigned int)959913783ULL),((unsigned int)2912942556ULL),((unsigned int)2426330149ULL),((unsigned int)1434990684ULL),((unsigned int)3583325506ULL),((unsigned int)715228930ULL),((unsigned int)1774256516ULL)};
unsigned int a_1[4]={((unsigned int)2005198767ULL),((unsigned int)2112190209ULL),((unsigned int)450243765ULL),((unsigned int)3013596876ULL)};
unsigned int b_1[4]={((unsigned int)2005198767ULL),((unsigned int)2112190209ULL),((unsigned int)450243765ULL),((unsigned int)3013596876ULL)};
unsigned int a_2[4]={((unsigned int)2501660790ULL),((unsigned int)2858103287ULL),((unsigned int)2315297423ULL),((unsigned int)3651480319ULL)};
unsigned int b_2[4]={((unsigned int)2501660790ULL),((unsigned int)2858103287ULL),((unsigned int)2315297423ULL),((unsigned int)3651480319ULL)};
unsigned int a_3[4]={((unsigned int)3854969146ULL),((unsigned int)871857056ULL),((unsigned int)3767396178ULL),((unsigned int)1900949758ULL)};
unsigned int b_3[4]={((unsigned int)3854969146ULL),((unsigned int)871857056ULL),((unsigned int)3767396178ULL),((unsigned int)1900949758ULL)};
unsigned int a_4[4]={((unsigned int)2985750114ULL),((unsigned int)1442129483ULL),((unsigned int)3345212834ULL),((unsigned int)1235861748ULL)};
unsigned int b_4[4]={((unsigned int)2985750114ULL),((unsigned int)1442129483ULL),((unsigned int)3345212834ULL),((unsigned int)1235861748ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 229\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2336958816ULL),((unsigned int)403102456ULL),((unsigned int)2274167528ULL),((unsigned int)3550915112ULL),((unsigned int)1552383793ULL),((unsigned int)2851700821ULL),((unsigned int)1789176542ULL),((unsigned int)2970254215ULL),((unsigned int)3692938466ULL),((unsigned int)903977703ULL),((unsigned int)3920835597ULL),((unsigned int)259864254ULL),((unsigned int)2857209926ULL),((unsigned int)4101087296ULL),((unsigned int)2897039405ULL),((unsigned int)3499146667ULL)};
unsigned int b_0[16]={((unsigned int)2336958816ULL),((unsigned int)403102456ULL),((unsigned int)2274167528ULL),((unsigned int)3550915112ULL),((unsigned int)1552383793ULL),((unsigned int)2851700821ULL),((unsigned int)1789176542ULL),((unsigned int)2970254215ULL),((unsigned int)3692938466ULL),((unsigned int)903977703ULL),((unsigned int)3920835597ULL),((unsigned int)259864254ULL),((unsigned int)2857209926ULL),((unsigned int)4101087296ULL),((unsigned int)2897039405ULL),((unsigned int)3499146667ULL)};
unsigned int a_1[4]={((unsigned int)265668072ULL),((unsigned int)2580638013ULL),((unsigned int)3673231632ULL),((unsigned int)3597495525ULL)};
unsigned int b_1[4]={((unsigned int)265668072ULL),((unsigned int)2580638013ULL),((unsigned int)3673231632ULL),((unsigned int)3597495525ULL)};
unsigned int a_2[4]={((unsigned int)380668286ULL),((unsigned int)1597840938ULL),((unsigned int)662180588ULL),((unsigned int)2160505927ULL)};
unsigned int b_2[4]={((unsigned int)380668286ULL),((unsigned int)1597840938ULL),((unsigned int)662180588ULL),((unsigned int)2160505927ULL)};
unsigned int a_3[4]={((unsigned int)3608475340ULL),((unsigned int)1528660820ULL),((unsigned int)3763807430ULL),((unsigned int)922897563ULL)};
unsigned int b_3[4]={((unsigned int)3608475340ULL),((unsigned int)1528660820ULL),((unsigned int)3763807430ULL),((unsigned int)922897563ULL)};
unsigned int a_4[4]={((unsigned int)821632633ULL),((unsigned int)3837253537ULL),((unsigned int)4102371586ULL),((unsigned int)2915585532ULL)};
unsigned int b_4[4]={((unsigned int)821632633ULL),((unsigned int)3837253537ULL),((unsigned int)4102371586ULL),((unsigned int)2915585532ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 230\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)640688499ULL),((unsigned int)4081210023ULL),((unsigned int)4081968620ULL),((unsigned int)1309906043ULL),((unsigned int)1017900833ULL),((unsigned int)3682710780ULL),((unsigned int)3255283841ULL),((unsigned int)4232290419ULL),((unsigned int)751832148ULL),((unsigned int)328592585ULL),((unsigned int)1325624893ULL),((unsigned int)2801819993ULL),((unsigned int)2390371279ULL),((unsigned int)2243540037ULL),((unsigned int)2340953445ULL),((unsigned int)3974139676ULL)};
unsigned int b_0[16]={((unsigned int)640688499ULL),((unsigned int)4081210023ULL),((unsigned int)4081968620ULL),((unsigned int)1309906043ULL),((unsigned int)1017900833ULL),((unsigned int)3682710780ULL),((unsigned int)3255283841ULL),((unsigned int)4232290419ULL),((unsigned int)751832148ULL),((unsigned int)328592585ULL),((unsigned int)1325624893ULL),((unsigned int)2801819993ULL),((unsigned int)2390371279ULL),((unsigned int)2243540037ULL),((unsigned int)2340953445ULL),((unsigned int)3974139676ULL)};
unsigned int a_1[4]={((unsigned int)2103173412ULL),((unsigned int)3049206233ULL),((unsigned int)1396452ULL),((unsigned int)3708893036ULL)};
unsigned int b_1[4]={((unsigned int)2103173412ULL),((unsigned int)3049206233ULL),((unsigned int)1396452ULL),((unsigned int)3708893036ULL)};
unsigned int a_2[4]={((unsigned int)4020701196ULL),((unsigned int)170262846ULL),((unsigned int)2531159118ULL),((unsigned int)3626188365ULL)};
unsigned int b_2[4]={((unsigned int)4020701196ULL),((unsigned int)170262846ULL),((unsigned int)2531159118ULL),((unsigned int)3626188365ULL)};
unsigned int a_3[4]={((unsigned int)461693827ULL),((unsigned int)1627813533ULL),((unsigned int)3312958538ULL),((unsigned int)402094306ULL)};
unsigned int b_3[4]={((unsigned int)461693827ULL),((unsigned int)1627813533ULL),((unsigned int)3312958538ULL),((unsigned int)402094306ULL)};
unsigned int a_4[4]={((unsigned int)2453836666ULL),((unsigned int)190280238ULL),((unsigned int)3710701299ULL),((unsigned int)2573506170ULL)};
unsigned int b_4[4]={((unsigned int)2453836666ULL),((unsigned int)190280238ULL),((unsigned int)3710701299ULL),((unsigned int)2573506170ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 231\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2276533668ULL),((unsigned int)2592823819ULL),((unsigned int)589147145ULL),((unsigned int)2839188587ULL),((unsigned int)2415948496ULL),((unsigned int)2677741144ULL),((unsigned int)2344462993ULL),((unsigned int)3149414585ULL),((unsigned int)2943856278ULL),((unsigned int)529726776ULL),((unsigned int)1045315203ULL),((unsigned int)1710081567ULL),((unsigned int)4277381698ULL),((unsigned int)3306798257ULL),((unsigned int)1346172474ULL),((unsigned int)180406933ULL)};
unsigned int b_0[16]={((unsigned int)2276533668ULL),((unsigned int)2592823819ULL),((unsigned int)589147145ULL),((unsigned int)2839188587ULL),((unsigned int)2415948496ULL),((unsigned int)2677741144ULL),((unsigned int)2344462993ULL),((unsigned int)3149414585ULL),((unsigned int)2943856278ULL),((unsigned int)529726776ULL),((unsigned int)1045315203ULL),((unsigned int)1710081567ULL),((unsigned int)4277381698ULL),((unsigned int)3306798257ULL),((unsigned int)1346172474ULL),((unsigned int)180406933ULL)};
unsigned int a_1[4]={((unsigned int)3640118461ULL),((unsigned int)907133252ULL),((unsigned int)140843127ULL),((unsigned int)1795857770ULL)};
unsigned int b_1[4]={((unsigned int)3640118461ULL),((unsigned int)907133252ULL),((unsigned int)140843127ULL),((unsigned int)1795857770ULL)};
unsigned int a_2[4]={((unsigned int)3072370537ULL),((unsigned int)1260580517ULL),((unsigned int)2279910217ULL),((unsigned int)2340869197ULL)};
unsigned int b_2[4]={((unsigned int)3072370537ULL),((unsigned int)1260580517ULL),((unsigned int)2279910217ULL),((unsigned int)2340869197ULL)};
unsigned int a_3[4]={((unsigned int)1933793708ULL),((unsigned int)1933633015ULL),((unsigned int)1732209795ULL),((unsigned int)3589857649ULL)};
unsigned int b_3[4]={((unsigned int)1933793708ULL),((unsigned int)1933633015ULL),((unsigned int)1732209795ULL),((unsigned int)3589857649ULL)};
unsigned int a_4[4]={((unsigned int)2627626824ULL),((unsigned int)1342806980ULL),((unsigned int)2083345772ULL),((unsigned int)772040030ULL)};
unsigned int b_4[4]={((unsigned int)2627626824ULL),((unsigned int)1342806980ULL),((unsigned int)2083345772ULL),((unsigned int)772040030ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 232\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1557921991ULL),((unsigned int)4231898529ULL),((unsigned int)1583573936ULL),((unsigned int)4086136079ULL),((unsigned int)2992157322ULL),((unsigned int)629319383ULL),((unsigned int)3133129768ULL),((unsigned int)81559197ULL),((unsigned int)2744671000ULL),((unsigned int)1396449464ULL),((unsigned int)3601667394ULL),((unsigned int)1669502679ULL),((unsigned int)2999766239ULL),((unsigned int)1547593216ULL),((unsigned int)2727755268ULL),((unsigned int)4102882256ULL)};
unsigned int b_0[16]={((unsigned int)1557921991ULL),((unsigned int)4231898529ULL),((unsigned int)1583573936ULL),((unsigned int)4086136079ULL),((unsigned int)2992157322ULL),((unsigned int)629319383ULL),((unsigned int)3133129768ULL),((unsigned int)81559197ULL),((unsigned int)2744671000ULL),((unsigned int)1396449464ULL),((unsigned int)3601667394ULL),((unsigned int)1669502679ULL),((unsigned int)2999766239ULL),((unsigned int)1547593216ULL),((unsigned int)2727755268ULL),((unsigned int)4102882256ULL)};
unsigned int a_1[4]={((unsigned int)494834947ULL),((unsigned int)3452145093ULL),((unsigned int)4037322103ULL),((unsigned int)1988808695ULL)};
unsigned int b_1[4]={((unsigned int)494834947ULL),((unsigned int)3452145093ULL),((unsigned int)4037322103ULL),((unsigned int)1988808695ULL)};
unsigned int a_2[4]={((unsigned int)1932256785ULL),((unsigned int)2723574514ULL),((unsigned int)562239230ULL),((unsigned int)3255631890ULL)};
unsigned int b_2[4]={((unsigned int)1932256785ULL),((unsigned int)2723574514ULL),((unsigned int)562239230ULL),((unsigned int)3255631890ULL)};
unsigned int a_3[4]={((unsigned int)1446186435ULL),((unsigned int)1814830759ULL),((unsigned int)728543081ULL),((unsigned int)1654470432ULL)};
unsigned int b_3[4]={((unsigned int)1446186435ULL),((unsigned int)1814830759ULL),((unsigned int)728543081ULL),((unsigned int)1654470432ULL)};
unsigned int a_4[4]={((unsigned int)2404619015ULL),((unsigned int)4010326495ULL),((unsigned int)618409590ULL),((unsigned int)1159054920ULL)};
unsigned int b_4[4]={((unsigned int)2404619015ULL),((unsigned int)4010326495ULL),((unsigned int)618409590ULL),((unsigned int)1159054920ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 233\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)781286126ULL),((unsigned int)1730545940ULL),((unsigned int)2070820136ULL),((unsigned int)1859029788ULL),((unsigned int)897648758ULL),((unsigned int)2626901767ULL),((unsigned int)1144096511ULL),((unsigned int)359812977ULL),((unsigned int)1795028797ULL),((unsigned int)1540478080ULL),((unsigned int)1435368526ULL),((unsigned int)394517139ULL),((unsigned int)3710450583ULL),((unsigned int)3882103924ULL),((unsigned int)2339376146ULL),((unsigned int)2582937580ULL)};
unsigned int b_0[16]={((unsigned int)781286126ULL),((unsigned int)1730545940ULL),((unsigned int)2070820136ULL),((unsigned int)1859029788ULL),((unsigned int)897648758ULL),((unsigned int)2626901767ULL),((unsigned int)1144096511ULL),((unsigned int)359812977ULL),((unsigned int)1795028797ULL),((unsigned int)1540478080ULL),((unsigned int)1435368526ULL),((unsigned int)394517139ULL),((unsigned int)3710450583ULL),((unsigned int)3882103924ULL),((unsigned int)2339376146ULL),((unsigned int)2582937580ULL)};
unsigned int a_1[4]={((unsigned int)1548422427ULL),((unsigned int)2572245354ULL),((unsigned int)1613280479ULL),((unsigned int)2241159787ULL)};
unsigned int b_1[4]={((unsigned int)1548422427ULL),((unsigned int)2572245354ULL),((unsigned int)1613280479ULL),((unsigned int)2241159787ULL)};
unsigned int a_2[4]={((unsigned int)2286839338ULL),((unsigned int)1770458659ULL),((unsigned int)2194471585ULL),((unsigned int)2243818526ULL)};
unsigned int b_2[4]={((unsigned int)2286839338ULL),((unsigned int)1770458659ULL),((unsigned int)2194471585ULL),((unsigned int)2243818526ULL)};
unsigned int a_3[4]={((unsigned int)441686517ULL),((unsigned int)3169249999ULL),((unsigned int)1094786028ULL),((unsigned int)752850858ULL)};
unsigned int b_3[4]={((unsigned int)441686517ULL),((unsigned int)3169249999ULL),((unsigned int)1094786028ULL),((unsigned int)752850858ULL)};
unsigned int a_4[4]={((unsigned int)3645791182ULL),((unsigned int)1445635470ULL),((unsigned int)2807003883ULL),((unsigned int)251894523ULL)};
unsigned int b_4[4]={((unsigned int)3645791182ULL),((unsigned int)1445635470ULL),((unsigned int)2807003883ULL),((unsigned int)251894523ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 234\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1152698340ULL),((unsigned int)3625606705ULL),((unsigned int)1893143818ULL),((unsigned int)175896150ULL),((unsigned int)3931800287ULL),((unsigned int)1461198700ULL),((unsigned int)223792486ULL),((unsigned int)3622409231ULL),((unsigned int)1361531984ULL),((unsigned int)4202694875ULL),((unsigned int)1870915447ULL),((unsigned int)4006188067ULL),((unsigned int)719172505ULL),((unsigned int)464498297ULL),((unsigned int)3245214648ULL),((unsigned int)151408247ULL)};
unsigned int b_0[16]={((unsigned int)1152698340ULL),((unsigned int)3625606705ULL),((unsigned int)1893143818ULL),((unsigned int)175896150ULL),((unsigned int)3931800287ULL),((unsigned int)1461198700ULL),((unsigned int)223792486ULL),((unsigned int)3622409231ULL),((unsigned int)1361531984ULL),((unsigned int)4202694875ULL),((unsigned int)1870915447ULL),((unsigned int)4006188067ULL),((unsigned int)719172505ULL),((unsigned int)464498297ULL),((unsigned int)3245214648ULL),((unsigned int)151408247ULL)};
unsigned int a_1[4]={((unsigned int)453255833ULL),((unsigned int)4239520031ULL),((unsigned int)3439941972ULL),((unsigned int)4189002176ULL)};
unsigned int b_1[4]={((unsigned int)453255833ULL),((unsigned int)4239520031ULL),((unsigned int)3439941972ULL),((unsigned int)4189002176ULL)};
unsigned int a_2[4]={((unsigned int)761430562ULL),((unsigned int)175223893ULL),((unsigned int)3868338504ULL),((unsigned int)1175555041ULL)};
unsigned int b_2[4]={((unsigned int)761430562ULL),((unsigned int)175223893ULL),((unsigned int)3868338504ULL),((unsigned int)1175555041ULL)};
unsigned int a_3[4]={((unsigned int)2022775522ULL),((unsigned int)543929087ULL),((unsigned int)354052745ULL),((unsigned int)1141839457ULL)};
unsigned int b_3[4]={((unsigned int)2022775522ULL),((unsigned int)543929087ULL),((unsigned int)354052745ULL),((unsigned int)1141839457ULL)};
unsigned int a_4[4]={((unsigned int)2718928387ULL),((unsigned int)34017454ULL),((unsigned int)764207364ULL),((unsigned int)2161624554ULL)};
unsigned int b_4[4]={((unsigned int)2718928387ULL),((unsigned int)34017454ULL),((unsigned int)764207364ULL),((unsigned int)2161624554ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 235\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)833232797ULL),((unsigned int)1866961557ULL),((unsigned int)1009368667ULL),((unsigned int)3162568342ULL),((unsigned int)4138139382ULL),((unsigned int)243425324ULL),((unsigned int)1283503344ULL),((unsigned int)3369623760ULL),((unsigned int)3123809873ULL),((unsigned int)2124105463ULL),((unsigned int)2034538725ULL),((unsigned int)2100800035ULL),((unsigned int)3153901019ULL),((unsigned int)1576349701ULL),((unsigned int)3487139333ULL),((unsigned int)354855744ULL)};
unsigned int b_0[16]={((unsigned int)833232797ULL),((unsigned int)1866961557ULL),((unsigned int)1009368667ULL),((unsigned int)3162568342ULL),((unsigned int)4138139382ULL),((unsigned int)243425324ULL),((unsigned int)1283503344ULL),((unsigned int)3369623760ULL),((unsigned int)3123809873ULL),((unsigned int)2124105463ULL),((unsigned int)2034538725ULL),((unsigned int)2100800035ULL),((unsigned int)3153901019ULL),((unsigned int)1576349701ULL),((unsigned int)3487139333ULL),((unsigned int)354855744ULL)};
unsigned int a_1[4]={((unsigned int)1554449875ULL),((unsigned int)1276392801ULL),((unsigned int)3302047394ULL),((unsigned int)3193635188ULL)};
unsigned int b_1[4]={((unsigned int)1554449875ULL),((unsigned int)1276392801ULL),((unsigned int)3302047394ULL),((unsigned int)3193635188ULL)};
unsigned int a_2[4]={((unsigned int)964661638ULL),((unsigned int)1996184704ULL),((unsigned int)910989471ULL),((unsigned int)3712380321ULL)};
unsigned int b_2[4]={((unsigned int)964661638ULL),((unsigned int)1996184704ULL),((unsigned int)910989471ULL),((unsigned int)3712380321ULL)};
unsigned int a_3[4]={((unsigned int)148158169ULL),((unsigned int)2898082982ULL),((unsigned int)4134425856ULL),((unsigned int)3913540017ULL)};
unsigned int b_3[4]={((unsigned int)148158169ULL),((unsigned int)2898082982ULL),((unsigned int)4134425856ULL),((unsigned int)3913540017ULL)};
unsigned int a_4[4]={((unsigned int)1162950813ULL),((unsigned int)2122385385ULL),((unsigned int)2571253559ULL),((unsigned int)2444364220ULL)};
unsigned int b_4[4]={((unsigned int)1162950813ULL),((unsigned int)2122385385ULL),((unsigned int)2571253559ULL),((unsigned int)2444364220ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 236\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)423989545ULL),((unsigned int)2056019090ULL),((unsigned int)2193091366ULL),((unsigned int)3912510201ULL),((unsigned int)1817339705ULL),((unsigned int)2042380421ULL),((unsigned int)966383813ULL),((unsigned int)2703783222ULL),((unsigned int)4149872708ULL),((unsigned int)2339722839ULL),((unsigned int)2463288873ULL),((unsigned int)3319750876ULL),((unsigned int)3865193329ULL),((unsigned int)3840779040ULL),((unsigned int)2995742909ULL),((unsigned int)1497786712ULL)};
unsigned int b_0[16]={((unsigned int)423989545ULL),((unsigned int)2056019090ULL),((unsigned int)2193091366ULL),((unsigned int)3912510201ULL),((unsigned int)1817339705ULL),((unsigned int)2042380421ULL),((unsigned int)966383813ULL),((unsigned int)2703783222ULL),((unsigned int)4149872708ULL),((unsigned int)2339722839ULL),((unsigned int)2463288873ULL),((unsigned int)3319750876ULL),((unsigned int)3865193329ULL),((unsigned int)3840779040ULL),((unsigned int)2995742909ULL),((unsigned int)1497786712ULL)};
unsigned int a_1[4]={((unsigned int)356539119ULL),((unsigned int)1228101114ULL),((unsigned int)2649063077ULL),((unsigned int)3283611206ULL)};
unsigned int b_1[4]={((unsigned int)356539119ULL),((unsigned int)1228101114ULL),((unsigned int)2649063077ULL),((unsigned int)3283611206ULL)};
unsigned int a_2[4]={((unsigned int)2859017602ULL),((unsigned int)2003202086ULL),((unsigned int)3702125097ULL),((unsigned int)3482392070ULL)};
unsigned int b_2[4]={((unsigned int)2859017602ULL),((unsigned int)2003202086ULL),((unsigned int)3702125097ULL),((unsigned int)3482392070ULL)};
unsigned int a_3[4]={((unsigned int)1052345015ULL),((unsigned int)1710596995ULL),((unsigned int)820827100ULL),((unsigned int)2042772429ULL)};
unsigned int b_3[4]={((unsigned int)1052345015ULL),((unsigned int)1710596995ULL),((unsigned int)820827100ULL),((unsigned int)2042772429ULL)};
unsigned int a_4[4]={((unsigned int)3944089966ULL),((unsigned int)3643326422ULL),((unsigned int)427643337ULL),((unsigned int)3605066872ULL)};
unsigned int b_4[4]={((unsigned int)3944089966ULL),((unsigned int)3643326422ULL),((unsigned int)427643337ULL),((unsigned int)3605066872ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 237\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1316170597ULL),((unsigned int)3524918661ULL),((unsigned int)1213090195ULL),((unsigned int)3996689739ULL),((unsigned int)434158681ULL),((unsigned int)2083808699ULL),((unsigned int)2002027378ULL),((unsigned int)2011588854ULL),((unsigned int)3649397333ULL),((unsigned int)2869792164ULL),((unsigned int)1549374629ULL),((unsigned int)4065171145ULL),((unsigned int)1736394306ULL),((unsigned int)154917034ULL),((unsigned int)1370168706ULL),((unsigned int)3496259498ULL)};
unsigned int b_0[16]={((unsigned int)1316170597ULL),((unsigned int)3524918661ULL),((unsigned int)1213090195ULL),((unsigned int)3996689739ULL),((unsigned int)434158681ULL),((unsigned int)2083808699ULL),((unsigned int)2002027378ULL),((unsigned int)2011588854ULL),((unsigned int)3649397333ULL),((unsigned int)2869792164ULL),((unsigned int)1549374629ULL),((unsigned int)4065171145ULL),((unsigned int)1736394306ULL),((unsigned int)154917034ULL),((unsigned int)1370168706ULL),((unsigned int)3496259498ULL)};
unsigned int a_1[4]={((unsigned int)1444090850ULL),((unsigned int)26963657ULL),((unsigned int)895411996ULL),((unsigned int)2867916631ULL)};
unsigned int b_1[4]={((unsigned int)1444090850ULL),((unsigned int)26963657ULL),((unsigned int)895411996ULL),((unsigned int)2867916631ULL)};
unsigned int a_2[4]={((unsigned int)3934462907ULL),((unsigned int)3881013495ULL),((unsigned int)1688722902ULL),((unsigned int)1456089326ULL)};
unsigned int b_2[4]={((unsigned int)3934462907ULL),((unsigned int)3881013495ULL),((unsigned int)1688722902ULL),((unsigned int)1456089326ULL)};
unsigned int a_3[4]={((unsigned int)2004111078ULL),((unsigned int)871100198ULL),((unsigned int)3019785454ULL),((unsigned int)2463279971ULL)};
unsigned int b_3[4]={((unsigned int)2004111078ULL),((unsigned int)871100198ULL),((unsigned int)3019785454ULL),((unsigned int)2463279971ULL)};
unsigned int a_4[4]={((unsigned int)766184468ULL),((unsigned int)575084542ULL),((unsigned int)2779538432ULL),((unsigned int)2303184976ULL)};
unsigned int b_4[4]={((unsigned int)766184468ULL),((unsigned int)575084542ULL),((unsigned int)2779538432ULL),((unsigned int)2303184976ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 238\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)285699818ULL),((unsigned int)4265043282ULL),((unsigned int)3684517188ULL),((unsigned int)1337641314ULL),((unsigned int)2354336534ULL),((unsigned int)2101556987ULL),((unsigned int)1921301304ULL),((unsigned int)1263087136ULL),((unsigned int)1242338757ULL),((unsigned int)2487356757ULL),((unsigned int)530586889ULL),((unsigned int)3767236218ULL),((unsigned int)290273795ULL),((unsigned int)2170513019ULL),((unsigned int)2827563849ULL),((unsigned int)4243557954ULL)};
unsigned int b_0[16]={((unsigned int)285699818ULL),((unsigned int)4265043282ULL),((unsigned int)3684517188ULL),((unsigned int)1337641314ULL),((unsigned int)2354336534ULL),((unsigned int)2101556987ULL),((unsigned int)1921301304ULL),((unsigned int)1263087136ULL),((unsigned int)1242338757ULL),((unsigned int)2487356757ULL),((unsigned int)530586889ULL),((unsigned int)3767236218ULL),((unsigned int)290273795ULL),((unsigned int)2170513019ULL),((unsigned int)2827563849ULL),((unsigned int)4243557954ULL)};
unsigned int a_1[4]={((unsigned int)4103716784ULL),((unsigned int)4001799137ULL),((unsigned int)1652038827ULL),((unsigned int)2528383025ULL)};
unsigned int b_1[4]={((unsigned int)4103716784ULL),((unsigned int)4001799137ULL),((unsigned int)1652038827ULL),((unsigned int)2528383025ULL)};
unsigned int a_2[4]={((unsigned int)3413471006ULL),((unsigned int)2792590328ULL),((unsigned int)1518468993ULL),((unsigned int)2702593866ULL)};
unsigned int b_2[4]={((unsigned int)3413471006ULL),((unsigned int)2792590328ULL),((unsigned int)1518468993ULL),((unsigned int)2702593866ULL)};
unsigned int a_3[4]={((unsigned int)1571027882ULL),((unsigned int)3186587098ULL),((unsigned int)3231569710ULL),((unsigned int)116769608ULL)};
unsigned int b_3[4]={((unsigned int)1571027882ULL),((unsigned int)3186587098ULL),((unsigned int)3231569710ULL),((unsigned int)116769608ULL)};
unsigned int a_4[4]={((unsigned int)1946819557ULL),((unsigned int)1456945111ULL),((unsigned int)4138212952ULL),((unsigned int)2159051367ULL)};
unsigned int b_4[4]={((unsigned int)1946819557ULL),((unsigned int)1456945111ULL),((unsigned int)4138212952ULL),((unsigned int)2159051367ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 239\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)594043855ULL),((unsigned int)1984691029ULL),((unsigned int)912304556ULL),((unsigned int)3842290732ULL),((unsigned int)943443043ULL),((unsigned int)703055651ULL),((unsigned int)1390878129ULL),((unsigned int)363053479ULL),((unsigned int)42352075ULL),((unsigned int)1384898596ULL),((unsigned int)3885110672ULL),((unsigned int)1285927557ULL),((unsigned int)985457757ULL),((unsigned int)1776117388ULL),((unsigned int)2799244206ULL),((unsigned int)4167214136ULL)};
unsigned int b_0[16]={((unsigned int)594043855ULL),((unsigned int)1984691029ULL),((unsigned int)912304556ULL),((unsigned int)3842290732ULL),((unsigned int)943443043ULL),((unsigned int)703055651ULL),((unsigned int)1390878129ULL),((unsigned int)363053479ULL),((unsigned int)42352075ULL),((unsigned int)1384898596ULL),((unsigned int)3885110672ULL),((unsigned int)1285927557ULL),((unsigned int)985457757ULL),((unsigned int)1776117388ULL),((unsigned int)2799244206ULL),((unsigned int)4167214136ULL)};
unsigned int a_1[4]={((unsigned int)3765105968ULL),((unsigned int)1187215907ULL),((unsigned int)264577832ULL),((unsigned int)2910413750ULL)};
unsigned int b_1[4]={((unsigned int)3765105968ULL),((unsigned int)1187215907ULL),((unsigned int)264577832ULL),((unsigned int)2910413750ULL)};
unsigned int a_2[4]={((unsigned int)1844803457ULL),((unsigned int)2948789678ULL),((unsigned int)4009149979ULL),((unsigned int)1818734429ULL)};
unsigned int b_2[4]={((unsigned int)1844803457ULL),((unsigned int)2948789678ULL),((unsigned int)4009149979ULL),((unsigned int)1818734429ULL)};
unsigned int a_3[4]={((unsigned int)1618713581ULL),((unsigned int)2341015864ULL),((unsigned int)1058707070ULL),((unsigned int)980782162ULL)};
unsigned int b_3[4]={((unsigned int)1618713581ULL),((unsigned int)2341015864ULL),((unsigned int)1058707070ULL),((unsigned int)980782162ULL)};
unsigned int a_4[4]={((unsigned int)1511414097ULL),((unsigned int)1435345501ULL),((unsigned int)2341646060ULL),((unsigned int)2555604553ULL)};
unsigned int b_4[4]={((unsigned int)1511414097ULL),((unsigned int)1435345501ULL),((unsigned int)2341646060ULL),((unsigned int)2555604553ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 240\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1072670235ULL),((unsigned int)4280629695ULL),((unsigned int)3501187487ULL),((unsigned int)342190353ULL),((unsigned int)3065240513ULL),((unsigned int)4279839528ULL),((unsigned int)2425209765ULL),((unsigned int)1323919082ULL),((unsigned int)322443312ULL),((unsigned int)254901100ULL),((unsigned int)2275738692ULL),((unsigned int)1692724833ULL),((unsigned int)2542503193ULL),((unsigned int)2193238992ULL),((unsigned int)1426392033ULL),((unsigned int)640929567ULL)};
unsigned int b_0[16]={((unsigned int)1072670235ULL),((unsigned int)4280629695ULL),((unsigned int)3501187487ULL),((unsigned int)342190353ULL),((unsigned int)3065240513ULL),((unsigned int)4279839528ULL),((unsigned int)2425209765ULL),((unsigned int)1323919082ULL),((unsigned int)322443312ULL),((unsigned int)254901100ULL),((unsigned int)2275738692ULL),((unsigned int)1692724833ULL),((unsigned int)2542503193ULL),((unsigned int)2193238992ULL),((unsigned int)1426392033ULL),((unsigned int)640929567ULL)};
unsigned int a_1[4]={((unsigned int)290506264ULL),((unsigned int)3805224368ULL),((unsigned int)682649580ULL),((unsigned int)2629684862ULL)};
unsigned int b_1[4]={((unsigned int)290506264ULL),((unsigned int)3805224368ULL),((unsigned int)682649580ULL),((unsigned int)2629684862ULL)};
unsigned int a_2[4]={((unsigned int)3709417232ULL),((unsigned int)3563781911ULL),((unsigned int)1671524560ULL),((unsigned int)2727114731ULL)};
unsigned int b_2[4]={((unsigned int)3709417232ULL),((unsigned int)3563781911ULL),((unsigned int)1671524560ULL),((unsigned int)2727114731ULL)};
unsigned int a_3[4]={((unsigned int)3145849056ULL),((unsigned int)422248624ULL),((unsigned int)3466889725ULL),((unsigned int)1514981742ULL)};
unsigned int b_3[4]={((unsigned int)3145849056ULL),((unsigned int)422248624ULL),((unsigned int)3466889725ULL),((unsigned int)1514981742ULL)};
unsigned int a_4[4]={((unsigned int)2355035882ULL),((unsigned int)1583260650ULL),((unsigned int)577303028ULL),((unsigned int)1299884180ULL)};
unsigned int b_4[4]={((unsigned int)2355035882ULL),((unsigned int)1583260650ULL),((unsigned int)577303028ULL),((unsigned int)1299884180ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 241\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1030444721ULL),((unsigned int)1488713119ULL),((unsigned int)2093217646ULL),((unsigned int)3696731396ULL),((unsigned int)1184696837ULL),((unsigned int)1227348358ULL),((unsigned int)3788794483ULL),((unsigned int)158256737ULL),((unsigned int)586788770ULL),((unsigned int)4259229732ULL),((unsigned int)4196569657ULL),((unsigned int)4028550435ULL),((unsigned int)1476947238ULL),((unsigned int)1660487192ULL),((unsigned int)438789411ULL),((unsigned int)3341853853ULL)};
unsigned int b_0[16]={((unsigned int)1030444721ULL),((unsigned int)1488713119ULL),((unsigned int)2093217646ULL),((unsigned int)3696731396ULL),((unsigned int)1184696837ULL),((unsigned int)1227348358ULL),((unsigned int)3788794483ULL),((unsigned int)158256737ULL),((unsigned int)586788770ULL),((unsigned int)4259229732ULL),((unsigned int)4196569657ULL),((unsigned int)4028550435ULL),((unsigned int)1476947238ULL),((unsigned int)1660487192ULL),((unsigned int)438789411ULL),((unsigned int)3341853853ULL)};
unsigned int a_1[4]={((unsigned int)27424624ULL),((unsigned int)2808649638ULL),((unsigned int)32218760ULL),((unsigned int)2585819973ULL)};
unsigned int b_1[4]={((unsigned int)27424624ULL),((unsigned int)2808649638ULL),((unsigned int)32218760ULL),((unsigned int)2585819973ULL)};
unsigned int a_2[4]={((unsigned int)27835790ULL),((unsigned int)2928566883ULL),((unsigned int)2922004880ULL),((unsigned int)272337948ULL)};
unsigned int b_2[4]={((unsigned int)27835790ULL),((unsigned int)2928566883ULL),((unsigned int)2922004880ULL),((unsigned int)272337948ULL)};
unsigned int a_3[4]={((unsigned int)4278585407ULL),((unsigned int)1042479128ULL),((unsigned int)1371731614ULL),((unsigned int)3784790985ULL)};
unsigned int b_3[4]={((unsigned int)4278585407ULL),((unsigned int)1042479128ULL),((unsigned int)1371731614ULL),((unsigned int)3784790985ULL)};
unsigned int a_4[4]={((unsigned int)2808186640ULL),((unsigned int)721357400ULL),((unsigned int)250174316ULL),((unsigned int)619045104ULL)};
unsigned int b_4[4]={((unsigned int)2808186640ULL),((unsigned int)721357400ULL),((unsigned int)250174316ULL),((unsigned int)619045104ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 242\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2505688944ULL),((unsigned int)597305487ULL),((unsigned int)2572288197ULL),((unsigned int)3792235116ULL),((unsigned int)118939273ULL),((unsigned int)889289457ULL),((unsigned int)4054615026ULL),((unsigned int)18130685ULL),((unsigned int)1629531762ULL),((unsigned int)2029205888ULL),((unsigned int)621529176ULL),((unsigned int)353699567ULL),((unsigned int)2823309103ULL),((unsigned int)3951513333ULL),((unsigned int)369629608ULL),((unsigned int)3456979680ULL)};
unsigned int b_0[16]={((unsigned int)2505688944ULL),((unsigned int)597305487ULL),((unsigned int)2572288197ULL),((unsigned int)3792235116ULL),((unsigned int)118939273ULL),((unsigned int)889289457ULL),((unsigned int)4054615026ULL),((unsigned int)18130685ULL),((unsigned int)1629531762ULL),((unsigned int)2029205888ULL),((unsigned int)621529176ULL),((unsigned int)353699567ULL),((unsigned int)2823309103ULL),((unsigned int)3951513333ULL),((unsigned int)369629608ULL),((unsigned int)3456979680ULL)};
unsigned int a_1[4]={((unsigned int)1685430089ULL),((unsigned int)278525203ULL),((unsigned int)3355226396ULL),((unsigned int)1704676358ULL)};
unsigned int b_1[4]={((unsigned int)1685430089ULL),((unsigned int)278525203ULL),((unsigned int)3355226396ULL),((unsigned int)1704676358ULL)};
unsigned int a_2[4]={((unsigned int)1626968903ULL),((unsigned int)3011666236ULL),((unsigned int)94582490ULL),((unsigned int)1032692950ULL)};
unsigned int b_2[4]={((unsigned int)1626968903ULL),((unsigned int)3011666236ULL),((unsigned int)94582490ULL),((unsigned int)1032692950ULL)};
unsigned int a_3[4]={((unsigned int)795554359ULL),((unsigned int)833789387ULL),((unsigned int)4266308328ULL),((unsigned int)1615543109ULL)};
unsigned int b_3[4]={((unsigned int)795554359ULL),((unsigned int)833789387ULL),((unsigned int)4266308328ULL),((unsigned int)1615543109ULL)};
unsigned int a_4[4]={((unsigned int)1423454267ULL),((unsigned int)3268300294ULL),((unsigned int)1634155307ULL),((unsigned int)2118059122ULL)};
unsigned int b_4[4]={((unsigned int)1423454267ULL),((unsigned int)3268300294ULL),((unsigned int)1634155307ULL),((unsigned int)2118059122ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 243\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1007814906ULL),((unsigned int)1807517198ULL),((unsigned int)2571601600ULL),((unsigned int)1726823492ULL),((unsigned int)735336340ULL),((unsigned int)2927152868ULL),((unsigned int)4206994895ULL),((unsigned int)3201570112ULL),((unsigned int)2470617717ULL),((unsigned int)2459852527ULL),((unsigned int)1430818722ULL),((unsigned int)2473395732ULL),((unsigned int)948895829ULL),((unsigned int)903687347ULL),((unsigned int)345102464ULL),((unsigned int)2409531643ULL)};
unsigned int b_0[16]={((unsigned int)1007814906ULL),((unsigned int)1807517198ULL),((unsigned int)2571601600ULL),((unsigned int)1726823492ULL),((unsigned int)735336340ULL),((unsigned int)2927152868ULL),((unsigned int)4206994895ULL),((unsigned int)3201570112ULL),((unsigned int)2470617717ULL),((unsigned int)2459852527ULL),((unsigned int)1430818722ULL),((unsigned int)2473395732ULL),((unsigned int)948895829ULL),((unsigned int)903687347ULL),((unsigned int)345102464ULL),((unsigned int)2409531643ULL)};
unsigned int a_1[4]={((unsigned int)1809485154ULL),((unsigned int)2861996292ULL),((unsigned int)486665657ULL),((unsigned int)4278370520ULL)};
unsigned int b_1[4]={((unsigned int)1809485154ULL),((unsigned int)2861996292ULL),((unsigned int)486665657ULL),((unsigned int)4278370520ULL)};
unsigned int a_2[4]={((unsigned int)1245741401ULL),((unsigned int)1941156719ULL),((unsigned int)4104418824ULL),((unsigned int)2709384545ULL)};
unsigned int b_2[4]={((unsigned int)1245741401ULL),((unsigned int)1941156719ULL),((unsigned int)4104418824ULL),((unsigned int)2709384545ULL)};
unsigned int a_3[4]={((unsigned int)4160653450ULL),((unsigned int)2345927287ULL),((unsigned int)2981015298ULL),((unsigned int)1098760015ULL)};
unsigned int b_3[4]={((unsigned int)4160653450ULL),((unsigned int)2345927287ULL),((unsigned int)2981015298ULL),((unsigned int)1098760015ULL)};
unsigned int a_4[4]={((unsigned int)3281725997ULL),((unsigned int)2676487865ULL),((unsigned int)3109303327ULL),((unsigned int)1029305261ULL)};
unsigned int b_4[4]={((unsigned int)3281725997ULL),((unsigned int)2676487865ULL),((unsigned int)3109303327ULL),((unsigned int)1029305261ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 244\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2402885056ULL),((unsigned int)1412433624ULL),((unsigned int)3887674884ULL),((unsigned int)225534796ULL),((unsigned int)1310481411ULL),((unsigned int)4282101444ULL),((unsigned int)249963199ULL),((unsigned int)4021912016ULL),((unsigned int)4000892883ULL),((unsigned int)213394444ULL),((unsigned int)3115343795ULL),((unsigned int)3889396420ULL),((unsigned int)471509403ULL),((unsigned int)943352010ULL),((unsigned int)1544501842ULL),((unsigned int)1241608785ULL)};
unsigned int b_0[16]={((unsigned int)2402885056ULL),((unsigned int)1412433624ULL),((unsigned int)3887674884ULL),((unsigned int)225534796ULL),((unsigned int)1310481411ULL),((unsigned int)4282101444ULL),((unsigned int)249963199ULL),((unsigned int)4021912016ULL),((unsigned int)4000892883ULL),((unsigned int)213394444ULL),((unsigned int)3115343795ULL),((unsigned int)3889396420ULL),((unsigned int)471509403ULL),((unsigned int)943352010ULL),((unsigned int)1544501842ULL),((unsigned int)1241608785ULL)};
unsigned int a_1[4]={((unsigned int)3027729936ULL),((unsigned int)1940782986ULL),((unsigned int)4062807393ULL),((unsigned int)3073576995ULL)};
unsigned int b_1[4]={((unsigned int)3027729936ULL),((unsigned int)1940782986ULL),((unsigned int)4062807393ULL),((unsigned int)3073576995ULL)};
unsigned int a_2[4]={((unsigned int)3562524700ULL),((unsigned int)2306036857ULL),((unsigned int)2859530945ULL),((unsigned int)2962426098ULL)};
unsigned int b_2[4]={((unsigned int)3562524700ULL),((unsigned int)2306036857ULL),((unsigned int)2859530945ULL),((unsigned int)2962426098ULL)};
unsigned int a_3[4]={((unsigned int)502000838ULL),((unsigned int)897563328ULL),((unsigned int)2995213560ULL),((unsigned int)3343677558ULL)};
unsigned int b_3[4]={((unsigned int)502000838ULL),((unsigned int)897563328ULL),((unsigned int)2995213560ULL),((unsigned int)3343677558ULL)};
unsigned int a_4[4]={((unsigned int)927340964ULL),((unsigned int)2112932174ULL),((unsigned int)1362187423ULL),((unsigned int)462704690ULL)};
unsigned int b_4[4]={((unsigned int)927340964ULL),((unsigned int)2112932174ULL),((unsigned int)1362187423ULL),((unsigned int)462704690ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 245\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3612816739ULL),((unsigned int)3521713889ULL),((unsigned int)1463312847ULL),((unsigned int)3115457372ULL),((unsigned int)3074458525ULL),((unsigned int)1961463028ULL),((unsigned int)1063539146ULL),((unsigned int)1475115681ULL),((unsigned int)3598673574ULL),((unsigned int)3119581531ULL),((unsigned int)603983934ULL),((unsigned int)713453246ULL),((unsigned int)160172780ULL),((unsigned int)2966500404ULL),((unsigned int)958537013ULL),((unsigned int)3100420663ULL)};
unsigned int b_0[16]={((unsigned int)3612816739ULL),((unsigned int)3521713889ULL),((unsigned int)1463312847ULL),((unsigned int)3115457372ULL),((unsigned int)3074458525ULL),((unsigned int)1961463028ULL),((unsigned int)1063539146ULL),((unsigned int)1475115681ULL),((unsigned int)3598673574ULL),((unsigned int)3119581531ULL),((unsigned int)603983934ULL),((unsigned int)713453246ULL),((unsigned int)160172780ULL),((unsigned int)2966500404ULL),((unsigned int)958537013ULL),((unsigned int)3100420663ULL)};
unsigned int a_1[4]={((unsigned int)371323412ULL),((unsigned int)3591333488ULL),((unsigned int)2703580360ULL),((unsigned int)2231533335ULL)};
unsigned int b_1[4]={((unsigned int)371323412ULL),((unsigned int)3591333488ULL),((unsigned int)2703580360ULL),((unsigned int)2231533335ULL)};
unsigned int a_2[4]={((unsigned int)2408760769ULL),((unsigned int)1930375580ULL),((unsigned int)1790580463ULL),((unsigned int)2863649779ULL)};
unsigned int b_2[4]={((unsigned int)2408760769ULL),((unsigned int)1930375580ULL),((unsigned int)1790580463ULL),((unsigned int)2863649779ULL)};
unsigned int a_3[4]={((unsigned int)2427116685ULL),((unsigned int)2190762527ULL),((unsigned int)125877316ULL),((unsigned int)1180040497ULL)};
unsigned int b_3[4]={((unsigned int)2427116685ULL),((unsigned int)2190762527ULL),((unsigned int)125877316ULL),((unsigned int)1180040497ULL)};
unsigned int a_4[4]={((unsigned int)3307434901ULL),((unsigned int)3776575884ULL),((unsigned int)1202292363ULL),((unsigned int)3365592811ULL)};
unsigned int b_4[4]={((unsigned int)3307434901ULL),((unsigned int)3776575884ULL),((unsigned int)1202292363ULL),((unsigned int)3365592811ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 246\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2290729104ULL),((unsigned int)326866509ULL),((unsigned int)431212616ULL),((unsigned int)3679432188ULL),((unsigned int)947804794ULL),((unsigned int)2991103524ULL),((unsigned int)2480866883ULL),((unsigned int)571208093ULL),((unsigned int)1287584882ULL),((unsigned int)2817949133ULL),((unsigned int)4128531447ULL),((unsigned int)1694057285ULL),((unsigned int)2519442843ULL),((unsigned int)3175392879ULL),((unsigned int)1027115767ULL),((unsigned int)3244285571ULL)};
unsigned int b_0[16]={((unsigned int)2290729104ULL),((unsigned int)326866509ULL),((unsigned int)431212616ULL),((unsigned int)3679432188ULL),((unsigned int)947804794ULL),((unsigned int)2991103524ULL),((unsigned int)2480866883ULL),((unsigned int)571208093ULL),((unsigned int)1287584882ULL),((unsigned int)2817949133ULL),((unsigned int)4128531447ULL),((unsigned int)1694057285ULL),((unsigned int)2519442843ULL),((unsigned int)3175392879ULL),((unsigned int)1027115767ULL),((unsigned int)3244285571ULL)};
unsigned int a_1[4]={((unsigned int)653686678ULL),((unsigned int)350413857ULL),((unsigned int)2481360431ULL),((unsigned int)3458252830ULL)};
unsigned int b_1[4]={((unsigned int)653686678ULL),((unsigned int)350413857ULL),((unsigned int)2481360431ULL),((unsigned int)3458252830ULL)};
unsigned int a_2[4]={((unsigned int)1906647516ULL),((unsigned int)2930550044ULL),((unsigned int)3641476442ULL),((unsigned int)1005676682ULL)};
unsigned int b_2[4]={((unsigned int)1906647516ULL),((unsigned int)2930550044ULL),((unsigned int)3641476442ULL),((unsigned int)1005676682ULL)};
unsigned int a_3[4]={((unsigned int)96256504ULL),((unsigned int)1607987075ULL),((unsigned int)2418905978ULL),((unsigned int)3776940679ULL)};
unsigned int b_3[4]={((unsigned int)96256504ULL),((unsigned int)1607987075ULL),((unsigned int)2418905978ULL),((unsigned int)3776940679ULL)};
unsigned int a_4[4]={((unsigned int)1224227508ULL),((unsigned int)947503885ULL),((unsigned int)3732388183ULL),((unsigned int)208250633ULL)};
unsigned int b_4[4]={((unsigned int)1224227508ULL),((unsigned int)947503885ULL),((unsigned int)3732388183ULL),((unsigned int)208250633ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 247\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)281011269ULL),((unsigned int)1779642123ULL),((unsigned int)4242853184ULL),((unsigned int)1987834477ULL),((unsigned int)3215613955ULL),((unsigned int)3205928554ULL),((unsigned int)981892216ULL),((unsigned int)3121522259ULL),((unsigned int)2085641483ULL),((unsigned int)336770220ULL),((unsigned int)3554264203ULL),((unsigned int)1783277225ULL),((unsigned int)2659969540ULL),((unsigned int)3299042711ULL),((unsigned int)3014005763ULL),((unsigned int)186844094ULL)};
unsigned int b_0[16]={((unsigned int)281011269ULL),((unsigned int)1779642123ULL),((unsigned int)4242853184ULL),((unsigned int)1987834477ULL),((unsigned int)3215613955ULL),((unsigned int)3205928554ULL),((unsigned int)981892216ULL),((unsigned int)3121522259ULL),((unsigned int)2085641483ULL),((unsigned int)336770220ULL),((unsigned int)3554264203ULL),((unsigned int)1783277225ULL),((unsigned int)2659969540ULL),((unsigned int)3299042711ULL),((unsigned int)3014005763ULL),((unsigned int)186844094ULL)};
unsigned int a_1[4]={((unsigned int)1297641507ULL),((unsigned int)3684011557ULL),((unsigned int)2129357765ULL),((unsigned int)535856026ULL)};
unsigned int b_1[4]={((unsigned int)1297641507ULL),((unsigned int)3684011557ULL),((unsigned int)2129357765ULL),((unsigned int)535856026ULL)};
unsigned int a_2[4]={((unsigned int)1489596517ULL),((unsigned int)2792211627ULL),((unsigned int)731284406ULL),((unsigned int)1875985586ULL)};
unsigned int b_2[4]={((unsigned int)1489596517ULL),((unsigned int)2792211627ULL),((unsigned int)731284406ULL),((unsigned int)1875985586ULL)};
unsigned int a_3[4]={((unsigned int)4225387389ULL),((unsigned int)1903768118ULL),((unsigned int)887651049ULL),((unsigned int)1810299311ULL)};
unsigned int b_3[4]={((unsigned int)4225387389ULL),((unsigned int)1903768118ULL),((unsigned int)887651049ULL),((unsigned int)1810299311ULL)};
unsigned int a_4[4]={((unsigned int)3277513506ULL),((unsigned int)928845188ULL),((unsigned int)283235482ULL),((unsigned int)931584383ULL)};
unsigned int b_4[4]={((unsigned int)3277513506ULL),((unsigned int)928845188ULL),((unsigned int)283235482ULL),((unsigned int)931584383ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 248\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1917087339ULL),((unsigned int)1239226592ULL),((unsigned int)3786314677ULL),((unsigned int)1300177666ULL),((unsigned int)2543845367ULL),((unsigned int)4041893389ULL),((unsigned int)2653365150ULL),((unsigned int)3909504234ULL),((unsigned int)3223323651ULL),((unsigned int)2803389278ULL),((unsigned int)844187841ULL),((unsigned int)3913755155ULL),((unsigned int)1199673881ULL),((unsigned int)4105138992ULL),((unsigned int)3797524477ULL),((unsigned int)1747537091ULL)};
unsigned int b_0[16]={((unsigned int)1917087339ULL),((unsigned int)1239226592ULL),((unsigned int)3786314677ULL),((unsigned int)1300177666ULL),((unsigned int)2543845367ULL),((unsigned int)4041893389ULL),((unsigned int)2653365150ULL),((unsigned int)3909504234ULL),((unsigned int)3223323651ULL),((unsigned int)2803389278ULL),((unsigned int)844187841ULL),((unsigned int)3913755155ULL),((unsigned int)1199673881ULL),((unsigned int)4105138992ULL),((unsigned int)3797524477ULL),((unsigned int)1747537091ULL)};
unsigned int a_1[4]={((unsigned int)2962005117ULL),((unsigned int)117567984ULL),((unsigned int)3653860632ULL),((unsigned int)2913710013ULL)};
unsigned int b_1[4]={((unsigned int)2962005117ULL),((unsigned int)117567984ULL),((unsigned int)3653860632ULL),((unsigned int)2913710013ULL)};
unsigned int a_2[4]={((unsigned int)2589838125ULL),((unsigned int)2237075050ULL),((unsigned int)1351948386ULL),((unsigned int)2702959711ULL)};
unsigned int b_2[4]={((unsigned int)2589838125ULL),((unsigned int)2237075050ULL),((unsigned int)1351948386ULL),((unsigned int)2702959711ULL)};
unsigned int a_3[4]={((unsigned int)1608050827ULL),((unsigned int)546836941ULL),((unsigned int)659928524ULL),((unsigned int)1160686846ULL)};
unsigned int b_3[4]={((unsigned int)1608050827ULL),((unsigned int)546836941ULL),((unsigned int)659928524ULL),((unsigned int)1160686846ULL)};
unsigned int a_4[4]={((unsigned int)1053275744ULL),((unsigned int)3610928090ULL),((unsigned int)3546163175ULL),((unsigned int)1426963931ULL)};
unsigned int b_4[4]={((unsigned int)1053275744ULL),((unsigned int)3610928090ULL),((unsigned int)3546163175ULL),((unsigned int)1426963931ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 249\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3126261ULL),((unsigned int)1624897571ULL),((unsigned int)4182393503ULL),((unsigned int)1002154954ULL),((unsigned int)514763794ULL),((unsigned int)3311770028ULL),((unsigned int)943624834ULL),((unsigned int)4167506143ULL),((unsigned int)3509848766ULL),((unsigned int)1618224789ULL),((unsigned int)2397131166ULL),((unsigned int)364305559ULL),((unsigned int)901345936ULL),((unsigned int)4098502469ULL),((unsigned int)2922725251ULL),((unsigned int)3256825576ULL)};
unsigned int b_0[16]={((unsigned int)3126261ULL),((unsigned int)1624897571ULL),((unsigned int)4182393503ULL),((unsigned int)1002154954ULL),((unsigned int)514763794ULL),((unsigned int)3311770028ULL),((unsigned int)943624834ULL),((unsigned int)4167506143ULL),((unsigned int)3509848766ULL),((unsigned int)1618224789ULL),((unsigned int)2397131166ULL),((unsigned int)364305559ULL),((unsigned int)901345936ULL),((unsigned int)4098502469ULL),((unsigned int)2922725251ULL),((unsigned int)3256825576ULL)};
unsigned int a_1[4]={((unsigned int)2958065338ULL),((unsigned int)2497338892ULL),((unsigned int)810528183ULL),((unsigned int)4073859635ULL)};
unsigned int b_1[4]={((unsigned int)2958065338ULL),((unsigned int)2497338892ULL),((unsigned int)810528183ULL),((unsigned int)4073859635ULL)};
unsigned int a_2[4]={((unsigned int)3795389565ULL),((unsigned int)2567922741ULL),((unsigned int)536038614ULL),((unsigned int)3987740938ULL)};
unsigned int b_2[4]={((unsigned int)3795389565ULL),((unsigned int)2567922741ULL),((unsigned int)536038614ULL),((unsigned int)3987740938ULL)};
unsigned int a_3[4]={((unsigned int)3360873799ULL),((unsigned int)792937664ULL),((unsigned int)29588687ULL),((unsigned int)1259178268ULL)};
unsigned int b_3[4]={((unsigned int)3360873799ULL),((unsigned int)792937664ULL),((unsigned int)29588687ULL),((unsigned int)1259178268ULL)};
unsigned int a_4[4]={((unsigned int)1210484926ULL),((unsigned int)4144410250ULL),((unsigned int)3194917994ULL),((unsigned int)851601721ULL)};
unsigned int b_4[4]={((unsigned int)1210484926ULL),((unsigned int)4144410250ULL),((unsigned int)3194917994ULL),((unsigned int)851601721ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 250\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2434507494ULL),((unsigned int)3357357276ULL),((unsigned int)1210601642ULL),((unsigned int)3209692495ULL),((unsigned int)2324930450ULL),((unsigned int)1117931846ULL),((unsigned int)136142753ULL),((unsigned int)4024966971ULL),((unsigned int)2370350848ULL),((unsigned int)2323588609ULL),((unsigned int)1265924788ULL),((unsigned int)544467863ULL),((unsigned int)1337423853ULL),((unsigned int)1553008576ULL),((unsigned int)783772082ULL),((unsigned int)67588406ULL)};
unsigned int b_0[16]={((unsigned int)2434507494ULL),((unsigned int)3357357276ULL),((unsigned int)1210601642ULL),((unsigned int)3209692495ULL),((unsigned int)2324930450ULL),((unsigned int)1117931846ULL),((unsigned int)136142753ULL),((unsigned int)4024966971ULL),((unsigned int)2370350848ULL),((unsigned int)2323588609ULL),((unsigned int)1265924788ULL),((unsigned int)544467863ULL),((unsigned int)1337423853ULL),((unsigned int)1553008576ULL),((unsigned int)783772082ULL),((unsigned int)67588406ULL)};
unsigned int a_1[4]={((unsigned int)3886713819ULL),((unsigned int)4005138099ULL),((unsigned int)422865563ULL),((unsigned int)2302531400ULL)};
unsigned int b_1[4]={((unsigned int)3886713819ULL),((unsigned int)4005138099ULL),((unsigned int)422865563ULL),((unsigned int)2302531400ULL)};
unsigned int a_2[4]={((unsigned int)233181320ULL),((unsigned int)170897527ULL),((unsigned int)960155235ULL),((unsigned int)4067884758ULL)};
unsigned int b_2[4]={((unsigned int)233181320ULL),((unsigned int)170897527ULL),((unsigned int)960155235ULL),((unsigned int)4067884758ULL)};
unsigned int a_3[4]={((unsigned int)3787563299ULL),((unsigned int)2671442836ULL),((unsigned int)1327902315ULL),((unsigned int)1156801059ULL)};
unsigned int b_3[4]={((unsigned int)3787563299ULL),((unsigned int)2671442836ULL),((unsigned int)1327902315ULL),((unsigned int)1156801059ULL)};
unsigned int a_4[4]={((unsigned int)2957593661ULL),((unsigned int)2621321751ULL),((unsigned int)2123241181ULL),((unsigned int)1900892860ULL)};
unsigned int b_4[4]={((unsigned int)2957593661ULL),((unsigned int)2621321751ULL),((unsigned int)2123241181ULL),((unsigned int)1900892860ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 251\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2311128517ULL),((unsigned int)232162471ULL),((unsigned int)39325047ULL),((unsigned int)3107446734ULL),((unsigned int)3320117159ULL),((unsigned int)3160401505ULL),((unsigned int)4254548671ULL),((unsigned int)1919595003ULL),((unsigned int)698525597ULL),((unsigned int)3820945632ULL),((unsigned int)170703568ULL),((unsigned int)3622823484ULL),((unsigned int)4177242802ULL),((unsigned int)1034393388ULL),((unsigned int)1719799043ULL),((unsigned int)275471467ULL)};
unsigned int b_0[16]={((unsigned int)2311128517ULL),((unsigned int)232162471ULL),((unsigned int)39325047ULL),((unsigned int)3107446734ULL),((unsigned int)3320117159ULL),((unsigned int)3160401505ULL),((unsigned int)4254548671ULL),((unsigned int)1919595003ULL),((unsigned int)698525597ULL),((unsigned int)3820945632ULL),((unsigned int)170703568ULL),((unsigned int)3622823484ULL),((unsigned int)4177242802ULL),((unsigned int)1034393388ULL),((unsigned int)1719799043ULL),((unsigned int)275471467ULL)};
unsigned int a_1[4]={((unsigned int)2056263174ULL),((unsigned int)4236782132ULL),((unsigned int)2379964213ULL),((unsigned int)2272439148ULL)};
unsigned int b_1[4]={((unsigned int)2056263174ULL),((unsigned int)4236782132ULL),((unsigned int)2379964213ULL),((unsigned int)2272439148ULL)};
unsigned int a_2[4]={((unsigned int)522488140ULL),((unsigned int)112912800ULL),((unsigned int)1116165676ULL),((unsigned int)1005955133ULL)};
unsigned int b_2[4]={((unsigned int)522488140ULL),((unsigned int)112912800ULL),((unsigned int)1116165676ULL),((unsigned int)1005955133ULL)};
unsigned int a_3[4]={((unsigned int)1109698614ULL),((unsigned int)1616406006ULL),((unsigned int)1369370343ULL),((unsigned int)2107197748ULL)};
unsigned int b_3[4]={((unsigned int)1109698614ULL),((unsigned int)1616406006ULL),((unsigned int)1369370343ULL),((unsigned int)2107197748ULL)};
unsigned int a_4[4]={((unsigned int)3964461449ULL),((unsigned int)2273056260ULL),((unsigned int)246605099ULL),((unsigned int)1675372241ULL)};
unsigned int b_4[4]={((unsigned int)3964461449ULL),((unsigned int)2273056260ULL),((unsigned int)246605099ULL),((unsigned int)1675372241ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 252\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1563284887ULL),((unsigned int)690467217ULL),((unsigned int)2490891285ULL),((unsigned int)1849071056ULL),((unsigned int)3155106920ULL),((unsigned int)836494499ULL),((unsigned int)2320813755ULL),((unsigned int)4284366378ULL),((unsigned int)1954670496ULL),((unsigned int)3975506009ULL),((unsigned int)3206929085ULL),((unsigned int)2605664996ULL),((unsigned int)2560575864ULL),((unsigned int)3698253754ULL),((unsigned int)3354994319ULL),((unsigned int)3650217419ULL)};
unsigned int b_0[16]={((unsigned int)1563284887ULL),((unsigned int)690467217ULL),((unsigned int)2490891285ULL),((unsigned int)1849071056ULL),((unsigned int)3155106920ULL),((unsigned int)836494499ULL),((unsigned int)2320813755ULL),((unsigned int)4284366378ULL),((unsigned int)1954670496ULL),((unsigned int)3975506009ULL),((unsigned int)3206929085ULL),((unsigned int)2605664996ULL),((unsigned int)2560575864ULL),((unsigned int)3698253754ULL),((unsigned int)3354994319ULL),((unsigned int)3650217419ULL)};
unsigned int a_1[4]={((unsigned int)4161844847ULL),((unsigned int)232780373ULL),((unsigned int)2415818042ULL),((unsigned int)2952512838ULL)};
unsigned int b_1[4]={((unsigned int)4161844847ULL),((unsigned int)232780373ULL),((unsigned int)2415818042ULL),((unsigned int)2952512838ULL)};
unsigned int a_2[4]={((unsigned int)1127809826ULL),((unsigned int)1007001494ULL),((unsigned int)3462913874ULL),((unsigned int)107244033ULL)};
unsigned int b_2[4]={((unsigned int)1127809826ULL),((unsigned int)1007001494ULL),((unsigned int)3462913874ULL),((unsigned int)107244033ULL)};
unsigned int a_3[4]={((unsigned int)3643279259ULL),((unsigned int)1605346570ULL),((unsigned int)2860554234ULL),((unsigned int)469113118ULL)};
unsigned int b_3[4]={((unsigned int)3643279259ULL),((unsigned int)1605346570ULL),((unsigned int)2860554234ULL),((unsigned int)469113118ULL)};
unsigned int a_4[4]={((unsigned int)3440094615ULL),((unsigned int)2359173409ULL),((unsigned int)976517380ULL),((unsigned int)2956526276ULL)};
unsigned int b_4[4]={((unsigned int)3440094615ULL),((unsigned int)2359173409ULL),((unsigned int)976517380ULL),((unsigned int)2956526276ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 253\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1698447141ULL),((unsigned int)646881563ULL),((unsigned int)3897100919ULL),((unsigned int)931468961ULL),((unsigned int)4171516836ULL),((unsigned int)556403880ULL),((unsigned int)2634325439ULL),((unsigned int)2677487266ULL),((unsigned int)1246799611ULL),((unsigned int)3212490280ULL),((unsigned int)3115420439ULL),((unsigned int)3917893751ULL),((unsigned int)3107548102ULL),((unsigned int)2466112514ULL),((unsigned int)4100867270ULL),((unsigned int)2861193014ULL)};
unsigned int b_0[16]={((unsigned int)1698447141ULL),((unsigned int)646881563ULL),((unsigned int)3897100919ULL),((unsigned int)931468961ULL),((unsigned int)4171516836ULL),((unsigned int)556403880ULL),((unsigned int)2634325439ULL),((unsigned int)2677487266ULL),((unsigned int)1246799611ULL),((unsigned int)3212490280ULL),((unsigned int)3115420439ULL),((unsigned int)3917893751ULL),((unsigned int)3107548102ULL),((unsigned int)2466112514ULL),((unsigned int)4100867270ULL),((unsigned int)2861193014ULL)};
unsigned int a_1[4]={((unsigned int)1608379905ULL),((unsigned int)4280577944ULL),((unsigned int)675640827ULL),((unsigned int)1839688570ULL)};
unsigned int b_1[4]={((unsigned int)1608379905ULL),((unsigned int)4280577944ULL),((unsigned int)675640827ULL),((unsigned int)1839688570ULL)};
unsigned int a_2[4]={((unsigned int)2892197482ULL),((unsigned int)717537587ULL),((unsigned int)4192069504ULL),((unsigned int)118672764ULL)};
unsigned int b_2[4]={((unsigned int)2892197482ULL),((unsigned int)717537587ULL),((unsigned int)4192069504ULL),((unsigned int)118672764ULL)};
unsigned int a_3[4]={((unsigned int)1033164354ULL),((unsigned int)2494266404ULL),((unsigned int)1689722841ULL),((unsigned int)688515578ULL)};
unsigned int b_3[4]={((unsigned int)1033164354ULL),((unsigned int)2494266404ULL),((unsigned int)1689722841ULL),((unsigned int)688515578ULL)};
unsigned int a_4[4]={((unsigned int)1230911779ULL),((unsigned int)3743419304ULL),((unsigned int)2112673294ULL),((unsigned int)3686223876ULL)};
unsigned int b_4[4]={((unsigned int)1230911779ULL),((unsigned int)3743419304ULL),((unsigned int)2112673294ULL),((unsigned int)3686223876ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 254\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)730915071ULL),((unsigned int)3094255052ULL),((unsigned int)1698141387ULL),((unsigned int)402236507ULL),((unsigned int)285406559ULL),((unsigned int)132258976ULL),((unsigned int)1155485554ULL),((unsigned int)2086768495ULL),((unsigned int)679582518ULL),((unsigned int)565536314ULL),((unsigned int)1596589982ULL),((unsigned int)461490280ULL),((unsigned int)2333810970ULL),((unsigned int)162034843ULL),((unsigned int)14859998ULL),((unsigned int)2745710795ULL)};
unsigned int b_0[16]={((unsigned int)730915071ULL),((unsigned int)3094255052ULL),((unsigned int)1698141387ULL),((unsigned int)402236507ULL),((unsigned int)285406559ULL),((unsigned int)132258976ULL),((unsigned int)1155485554ULL),((unsigned int)2086768495ULL),((unsigned int)679582518ULL),((unsigned int)565536314ULL),((unsigned int)1596589982ULL),((unsigned int)461490280ULL),((unsigned int)2333810970ULL),((unsigned int)162034843ULL),((unsigned int)14859998ULL),((unsigned int)2745710795ULL)};
unsigned int a_1[4]={((unsigned int)1621795884ULL),((unsigned int)3625733386ULL),((unsigned int)2293814772ULL),((unsigned int)3010971667ULL)};
unsigned int b_1[4]={((unsigned int)1621795884ULL),((unsigned int)3625733386ULL),((unsigned int)2293814772ULL),((unsigned int)3010971667ULL)};
unsigned int a_2[4]={((unsigned int)2313231132ULL),((unsigned int)4035348713ULL),((unsigned int)2927017282ULL),((unsigned int)837722942ULL)};
unsigned int b_2[4]={((unsigned int)2313231132ULL),((unsigned int)4035348713ULL),((unsigned int)2927017282ULL),((unsigned int)837722942ULL)};
unsigned int a_3[4]={((unsigned int)945907788ULL),((unsigned int)935577822ULL),((unsigned int)3217282123ULL),((unsigned int)3353354574ULL)};
unsigned int b_3[4]={((unsigned int)945907788ULL),((unsigned int)935577822ULL),((unsigned int)3217282123ULL),((unsigned int)3353354574ULL)};
unsigned int a_4[4]={((unsigned int)3554996165ULL),((unsigned int)3935976206ULL),((unsigned int)3357901010ULL),((unsigned int)14816638ULL)};
unsigned int b_4[4]={((unsigned int)3554996165ULL),((unsigned int)3935976206ULL),((unsigned int)3357901010ULL),((unsigned int)14816638ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 255\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3434025652ULL),((unsigned int)3924215033ULL),((unsigned int)3221939526ULL),((unsigned int)3607349713ULL),((unsigned int)1354863024ULL),((unsigned int)1430913202ULL),((unsigned int)1241071505ULL),((unsigned int)144005867ULL),((unsigned int)1464257585ULL),((unsigned int)2444556674ULL),((unsigned int)813928105ULL),((unsigned int)2666369668ULL),((unsigned int)2146813028ULL),((unsigned int)2338236962ULL),((unsigned int)2564048357ULL),((unsigned int)1261247458ULL)};
unsigned int b_0[16]={((unsigned int)3434025652ULL),((unsigned int)3924215033ULL),((unsigned int)3221939526ULL),((unsigned int)3607349713ULL),((unsigned int)1354863024ULL),((unsigned int)1430913202ULL),((unsigned int)1241071505ULL),((unsigned int)144005867ULL),((unsigned int)1464257585ULL),((unsigned int)2444556674ULL),((unsigned int)813928105ULL),((unsigned int)2666369668ULL),((unsigned int)2146813028ULL),((unsigned int)2338236962ULL),((unsigned int)2564048357ULL),((unsigned int)1261247458ULL)};
unsigned int a_1[4]={((unsigned int)3102474408ULL),((unsigned int)1395080793ULL),((unsigned int)3697801452ULL),((unsigned int)1125215166ULL)};
unsigned int b_1[4]={((unsigned int)3102474408ULL),((unsigned int)1395080793ULL),((unsigned int)3697801452ULL),((unsigned int)1125215166ULL)};
unsigned int a_2[4]={((unsigned int)3675536573ULL),((unsigned int)1257009164ULL),((unsigned int)2355063161ULL),((unsigned int)1084915154ULL)};
unsigned int b_2[4]={((unsigned int)3675536573ULL),((unsigned int)1257009164ULL),((unsigned int)2355063161ULL),((unsigned int)1084915154ULL)};
unsigned int a_3[4]={((unsigned int)3996570105ULL),((unsigned int)249654158ULL),((unsigned int)502297438ULL),((unsigned int)3627475362ULL)};
unsigned int b_3[4]={((unsigned int)3996570105ULL),((unsigned int)249654158ULL),((unsigned int)502297438ULL),((unsigned int)3627475362ULL)};
unsigned int a_4[4]={((unsigned int)3178737443ULL),((unsigned int)2663959555ULL),((unsigned int)3207153688ULL),((unsigned int)3862353448ULL)};
unsigned int b_4[4]={((unsigned int)3178737443ULL),((unsigned int)2663959555ULL),((unsigned int)3207153688ULL),((unsigned int)3862353448ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 256\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)3751392601ULL),((unsigned int)1433307432ULL),((unsigned int)1007701792ULL),((unsigned int)2741248882ULL),((unsigned int)2587752015ULL),((unsigned int)3159533487ULL),((unsigned int)514550228ULL),((unsigned int)273801195ULL),((unsigned int)842661977ULL),((unsigned int)4018502286ULL),((unsigned int)4263085151ULL),((unsigned int)479547657ULL),((unsigned int)961257498ULL),((unsigned int)1790678451ULL),((unsigned int)5010489ULL),((unsigned int)2932379517ULL)};
unsigned int b_0[16]={((unsigned int)3751392601ULL),((unsigned int)1433307432ULL),((unsigned int)1007701792ULL),((unsigned int)2741248882ULL),((unsigned int)2587752015ULL),((unsigned int)3159533487ULL),((unsigned int)514550228ULL),((unsigned int)273801195ULL),((unsigned int)842661977ULL),((unsigned int)4018502286ULL),((unsigned int)4263085151ULL),((unsigned int)479547657ULL),((unsigned int)961257498ULL),((unsigned int)1790678451ULL),((unsigned int)5010489ULL),((unsigned int)2932379517ULL)};
unsigned int a_1[4]={((unsigned int)428544634ULL),((unsigned int)3294362408ULL),((unsigned int)1434653745ULL),((unsigned int)107715418ULL)};
unsigned int b_1[4]={((unsigned int)428544634ULL),((unsigned int)3294362408ULL),((unsigned int)1434653745ULL),((unsigned int)107715418ULL)};
unsigned int a_2[4]={((unsigned int)4066689672ULL),((unsigned int)920081518ULL),((unsigned int)3824152125ULL),((unsigned int)966263124ULL)};
unsigned int b_2[4]={((unsigned int)4066689672ULL),((unsigned int)920081518ULL),((unsigned int)3824152125ULL),((unsigned int)966263124ULL)};
unsigned int a_3[4]={((unsigned int)3084793626ULL),((unsigned int)2977347133ULL),((unsigned int)1234353516ULL),((unsigned int)563789982ULL)};
unsigned int b_3[4]={((unsigned int)3084793626ULL),((unsigned int)2977347133ULL),((unsigned int)1234353516ULL),((unsigned int)563789982ULL)};
unsigned int a_4[4]={((unsigned int)220910774ULL),((unsigned int)2891431197ULL),((unsigned int)3686875316ULL),((unsigned int)781050407ULL)};
unsigned int b_4[4]={((unsigned int)220910774ULL),((unsigned int)2891431197ULL),((unsigned int)3686875316ULL),((unsigned int)781050407ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 257\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2899200637ULL),((unsigned int)1190770567ULL),((unsigned int)961634620ULL),((unsigned int)4216014291ULL),((unsigned int)1536754831ULL),((unsigned int)629984270ULL),((unsigned int)700433623ULL),((unsigned int)2000480278ULL),((unsigned int)4171228280ULL),((unsigned int)541379557ULL),((unsigned int)3960352331ULL),((unsigned int)194108324ULL),((unsigned int)3015256453ULL),((unsigned int)2314908890ULL),((unsigned int)3430785295ULL),((unsigned int)2972489547ULL)};
unsigned int b_0[16]={((unsigned int)2899200637ULL),((unsigned int)1190770567ULL),((unsigned int)961634620ULL),((unsigned int)4216014291ULL),((unsigned int)1536754831ULL),((unsigned int)629984270ULL),((unsigned int)700433623ULL),((unsigned int)2000480278ULL),((unsigned int)4171228280ULL),((unsigned int)541379557ULL),((unsigned int)3960352331ULL),((unsigned int)194108324ULL),((unsigned int)3015256453ULL),((unsigned int)2314908890ULL),((unsigned int)3430785295ULL),((unsigned int)2972489547ULL)};
unsigned int a_1[4]={((unsigned int)1502798245ULL),((unsigned int)660244826ULL),((unsigned int)1787468518ULL),((unsigned int)3347882531ULL)};
unsigned int b_1[4]={((unsigned int)1502798245ULL),((unsigned int)660244826ULL),((unsigned int)1787468518ULL),((unsigned int)3347882531ULL)};
unsigned int a_2[4]={((unsigned int)1152306518ULL),((unsigned int)3415396948ULL),((unsigned int)3359068656ULL),((unsigned int)3302921276ULL)};
unsigned int b_2[4]={((unsigned int)1152306518ULL),((unsigned int)3415396948ULL),((unsigned int)3359068656ULL),((unsigned int)3302921276ULL)};
unsigned int a_3[4]={((unsigned int)3846461936ULL),((unsigned int)95745592ULL),((unsigned int)883725544ULL),((unsigned int)589752611ULL)};
unsigned int b_3[4]={((unsigned int)3846461936ULL),((unsigned int)95745592ULL),((unsigned int)883725544ULL),((unsigned int)589752611ULL)};
unsigned int a_4[4]={((unsigned int)2986510800ULL),((unsigned int)3293902277ULL),((unsigned int)3015190309ULL),((unsigned int)2344144757ULL)};
unsigned int b_4[4]={((unsigned int)2986510800ULL),((unsigned int)3293902277ULL),((unsigned int)3015190309ULL),((unsigned int)2344144757ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 258\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)549079423ULL),((unsigned int)728178295ULL),((unsigned int)3868937811ULL),((unsigned int)2475439285ULL),((unsigned int)2240752139ULL),((unsigned int)2951667453ULL),((unsigned int)2881656417ULL),((unsigned int)1411385754ULL),((unsigned int)1778765835ULL),((unsigned int)4274759492ULL),((unsigned int)4063653596ULL),((unsigned int)2204215014ULL),((unsigned int)784479606ULL),((unsigned int)2483715323ULL),((unsigned int)2325157044ULL),((unsigned int)3039406766ULL)};
unsigned int b_0[16]={((unsigned int)549079423ULL),((unsigned int)728178295ULL),((unsigned int)3868937811ULL),((unsigned int)2475439285ULL),((unsigned int)2240752139ULL),((unsigned int)2951667453ULL),((unsigned int)2881656417ULL),((unsigned int)1411385754ULL),((unsigned int)1778765835ULL),((unsigned int)4274759492ULL),((unsigned int)4063653596ULL),((unsigned int)2204215014ULL),((unsigned int)784479606ULL),((unsigned int)2483715323ULL),((unsigned int)2325157044ULL),((unsigned int)3039406766ULL)};
unsigned int a_1[4]={((unsigned int)369049581ULL),((unsigned int)164124146ULL),((unsigned int)1092632146ULL),((unsigned int)1035845914ULL)};
unsigned int b_1[4]={((unsigned int)369049581ULL),((unsigned int)164124146ULL),((unsigned int)1092632146ULL),((unsigned int)1035845914ULL)};
unsigned int a_2[4]={((unsigned int)272177406ULL),((unsigned int)2699712484ULL),((unsigned int)41402389ULL),((unsigned int)4060006230ULL)};
unsigned int b_2[4]={((unsigned int)272177406ULL),((unsigned int)2699712484ULL),((unsigned int)41402389ULL),((unsigned int)4060006230ULL)};
unsigned int a_3[4]={((unsigned int)3020438007ULL),((unsigned int)1439882792ULL),((unsigned int)1546282349ULL),((unsigned int)3017356564ULL)};
unsigned int b_3[4]={((unsigned int)3020438007ULL),((unsigned int)1439882792ULL),((unsigned int)1546282349ULL),((unsigned int)3017356564ULL)};
unsigned int a_4[4]={((unsigned int)3191616540ULL),((unsigned int)3056831996ULL),((unsigned int)2838237713ULL),((unsigned int)3798863753ULL)};
unsigned int b_4[4]={((unsigned int)3191616540ULL),((unsigned int)3056831996ULL),((unsigned int)2838237713ULL),((unsigned int)3798863753ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 259\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)108099230ULL),((unsigned int)1424846006ULL),((unsigned int)2331292254ULL),((unsigned int)3756677996ULL),((unsigned int)2500166534ULL),((unsigned int)1152417202ULL),((unsigned int)3625511272ULL),((unsigned int)858836348ULL),((unsigned int)183869683ULL),((unsigned int)1372549424ULL),((unsigned int)642000702ULL),((unsigned int)3432808773ULL),((unsigned int)2108444159ULL),((unsigned int)764514558ULL),((unsigned int)3353131550ULL),((unsigned int)755391800ULL)};
unsigned int b_0[16]={((unsigned int)108099230ULL),((unsigned int)1424846006ULL),((unsigned int)2331292254ULL),((unsigned int)3756677996ULL),((unsigned int)2500166534ULL),((unsigned int)1152417202ULL),((unsigned int)3625511272ULL),((unsigned int)858836348ULL),((unsigned int)183869683ULL),((unsigned int)1372549424ULL),((unsigned int)642000702ULL),((unsigned int)3432808773ULL),((unsigned int)2108444159ULL),((unsigned int)764514558ULL),((unsigned int)3353131550ULL),((unsigned int)755391800ULL)};
unsigned int a_1[4]={((unsigned int)3035858785ULL),((unsigned int)490832682ULL),((unsigned int)4254261876ULL),((unsigned int)1599140232ULL)};
unsigned int b_1[4]={((unsigned int)3035858785ULL),((unsigned int)490832682ULL),((unsigned int)4254261876ULL),((unsigned int)1599140232ULL)};
unsigned int a_2[4]={((unsigned int)1010864912ULL),((unsigned int)2781267850ULL),((unsigned int)3336340870ULL),((unsigned int)2787411344ULL)};
unsigned int b_2[4]={((unsigned int)1010864912ULL),((unsigned int)2781267850ULL),((unsigned int)3336340870ULL),((unsigned int)2787411344ULL)};
unsigned int a_3[4]={((unsigned int)2331319147ULL),((unsigned int)1636329956ULL),((unsigned int)2782087467ULL),((unsigned int)3585382415ULL)};
unsigned int b_3[4]={((unsigned int)2331319147ULL),((unsigned int)1636329956ULL),((unsigned int)2782087467ULL),((unsigned int)3585382415ULL)};
unsigned int a_4[4]={((unsigned int)1692124449ULL),((unsigned int)1672050639ULL),((unsigned int)1134422732ULL),((unsigned int)2417502499ULL)};
unsigned int b_4[4]={((unsigned int)1692124449ULL),((unsigned int)1672050639ULL),((unsigned int)1134422732ULL),((unsigned int)2417502499ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 260\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)1235637332ULL),((unsigned int)2434712122ULL),((unsigned int)271764880ULL),((unsigned int)4076878475ULL),((unsigned int)278481798ULL),((unsigned int)585415994ULL),((unsigned int)101676331ULL),((unsigned int)2991900634ULL),((unsigned int)2220975720ULL),((unsigned int)2987157697ULL),((unsigned int)3283463010ULL),((unsigned int)1430666988ULL),((unsigned int)2898837834ULL),((unsigned int)561006830ULL),((unsigned int)924056385ULL),((unsigned int)3071625852ULL)};
unsigned int b_0[16]={((unsigned int)1235637332ULL),((unsigned int)2434712122ULL),((unsigned int)271764880ULL),((unsigned int)4076878475ULL),((unsigned int)278481798ULL),((unsigned int)585415994ULL),((unsigned int)101676331ULL),((unsigned int)2991900634ULL),((unsigned int)2220975720ULL),((unsigned int)2987157697ULL),((unsigned int)3283463010ULL),((unsigned int)1430666988ULL),((unsigned int)2898837834ULL),((unsigned int)561006830ULL),((unsigned int)924056385ULL),((unsigned int)3071625852ULL)};
unsigned int a_1[4]={((unsigned int)2211826887ULL),((unsigned int)3573755387ULL),((unsigned int)3091092997ULL),((unsigned int)1569622543ULL)};
unsigned int b_1[4]={((unsigned int)2211826887ULL),((unsigned int)3573755387ULL),((unsigned int)3091092997ULL),((unsigned int)1569622543ULL)};
unsigned int a_2[4]={((unsigned int)1083175344ULL),((unsigned int)3957750881ULL),((unsigned int)3329155092ULL),((unsigned int)2835178276ULL)};
unsigned int b_2[4]={((unsigned int)1083175344ULL),((unsigned int)3957750881ULL),((unsigned int)3329155092ULL),((unsigned int)2835178276ULL)};
unsigned int a_3[4]={((unsigned int)3911404936ULL),((unsigned int)3272543110ULL),((unsigned int)2884021073ULL),((unsigned int)1915486893ULL)};
unsigned int b_3[4]={((unsigned int)3911404936ULL),((unsigned int)3272543110ULL),((unsigned int)2884021073ULL),((unsigned int)1915486893ULL)};
unsigned int a_4[4]={((unsigned int)2631122972ULL),((unsigned int)3594200169ULL),((unsigned int)544283765ULL),((unsigned int)418021520ULL)};
unsigned int b_4[4]={((unsigned int)2631122972ULL),((unsigned int)3594200169ULL),((unsigned int)544283765ULL),((unsigned int)418021520ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 261\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)2872886721ULL),((unsigned int)3375031957ULL),((unsigned int)2239651735ULL),((unsigned int)779396010ULL),((unsigned int)2863188380ULL),((unsigned int)2211513253ULL),((unsigned int)1631335578ULL),((unsigned int)1332508498ULL),((unsigned int)2429513887ULL),((unsigned int)2515483995ULL),((unsigned int)938544225ULL),((unsigned int)591687642ULL),((unsigned int)3868601014ULL),((unsigned int)2529052061ULL),((unsigned int)1734312124ULL),((unsigned int)2257960762ULL)};
unsigned int b_0[16]={((unsigned int)2872886721ULL),((unsigned int)3375031957ULL),((unsigned int)2239651735ULL),((unsigned int)779396010ULL),((unsigned int)2863188380ULL),((unsigned int)2211513253ULL),((unsigned int)1631335578ULL),((unsigned int)1332508498ULL),((unsigned int)2429513887ULL),((unsigned int)2515483995ULL),((unsigned int)938544225ULL),((unsigned int)591687642ULL),((unsigned int)3868601014ULL),((unsigned int)2529052061ULL),((unsigned int)1734312124ULL),((unsigned int)2257960762ULL)};
unsigned int a_1[4]={((unsigned int)215025873ULL),((unsigned int)1763812044ULL),((unsigned int)2766079676ULL),((unsigned int)94486545ULL)};
unsigned int b_1[4]={((unsigned int)215025873ULL),((unsigned int)1763812044ULL),((unsigned int)2766079676ULL),((unsigned int)94486545ULL)};
unsigned int a_2[4]={((unsigned int)2915699067ULL),((unsigned int)2277372818ULL),((unsigned int)824352450ULL),((unsigned int)3244560081ULL)};
unsigned int b_2[4]={((unsigned int)2915699067ULL),((unsigned int)2277372818ULL),((unsigned int)824352450ULL),((unsigned int)3244560081ULL)};
unsigned int a_3[4]={((unsigned int)3238371175ULL),((unsigned int)119391129ULL),((unsigned int)2189577489ULL),((unsigned int)4007663475ULL)};
unsigned int b_3[4]={((unsigned int)3238371175ULL),((unsigned int)119391129ULL),((unsigned int)2189577489ULL),((unsigned int)4007663475ULL)};
unsigned int a_4[4]={((unsigned int)1009980775ULL),((unsigned int)932927473ULL),((unsigned int)925449453ULL),((unsigned int)2305422510ULL)};
unsigned int b_4[4]={((unsigned int)1009980775ULL),((unsigned int)932927473ULL),((unsigned int)925449453ULL),((unsigned int)2305422510ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 262\n");return 1;}
}
{
unsigned int a_0[16]={((unsigned int)377809438ULL),((unsigned int)3184449197ULL),((unsigned int)2931267479ULL),((unsigned int)4058749271ULL),((unsigned int)3984724301ULL),((unsigned int)2390009622ULL),((unsigned int)2874628473ULL),((unsigned int)2668388015ULL),((unsigned int)3753482505ULL),((unsigned int)1720667501ULL),((unsigned int)735887460ULL),((unsigned int)600957953ULL),((unsigned int)897060601ULL),((unsigned int)1408759720ULL),((unsigned int)2888729491ULL),((unsigned int)2845006336ULL)};
unsigned int b_0[16]={((unsigned int)377809438ULL),((unsigned int)3184449197ULL),((unsigned int)2931267479ULL),((unsigned int)4058749271ULL),((unsigned int)3984724301ULL),((unsigned int)2390009622ULL),((unsigned int)2874628473ULL),((unsigned int)2668388015ULL),((unsigned int)3753482505ULL),((unsigned int)1720667501ULL),((unsigned int)735887460ULL),((unsigned int)600957953ULL),((unsigned int)897060601ULL),((unsigned int)1408759720ULL),((unsigned int)2888729491ULL),((unsigned int)2845006336ULL)};
unsigned int a_1[4]={((unsigned int)3542245015ULL),((unsigned int)3209524575ULL),((unsigned int)2681748058ULL),((unsigned int)2184294716ULL)};
unsigned int b_1[4]={((unsigned int)3542245015ULL),((unsigned int)3209524575ULL),((unsigned int)2681748058ULL),((unsigned int)2184294716ULL)};
unsigned int a_2[4]={((unsigned int)3011585200ULL),((unsigned int)3344435460ULL),((unsigned int)4215590531ULL),((unsigned int)3852679236ULL)};
unsigned int b_2[4]={((unsigned int)3011585200ULL),((unsigned int)3344435460ULL),((unsigned int)4215590531ULL),((unsigned int)3852679236ULL)};
unsigned int a_3[4]={((unsigned int)171056414ULL),((unsigned int)225848705ULL),((unsigned int)1336618946ULL),((unsigned int)250333864ULL)};
unsigned int b_3[4]={((unsigned int)171056414ULL),((unsigned int)225848705ULL),((unsigned int)1336618946ULL),((unsigned int)250333864ULL)};
unsigned int a_4[4]={((unsigned int)2336007938ULL),((unsigned int)1563604846ULL),((unsigned int)4094885171ULL),((unsigned int)3672496706ULL)};
unsigned int b_4[4]={((unsigned int)2336007938ULL),((unsigned int)1563604846ULL),((unsigned int)4094885171ULL),((unsigned int)3672496706ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
