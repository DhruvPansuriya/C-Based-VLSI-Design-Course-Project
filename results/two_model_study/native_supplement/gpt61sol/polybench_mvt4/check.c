#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void reference(unsigned int x1[4], unsigned int x2[4], unsigned int y_1[4], unsigned int y_2[4], unsigned int a[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      x1[i] = x1[i] + (a[(i * 4) + j] * y_1[j]);
    }

  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      x2[i] = x2[i] + (a[(j * 4) + i] * y_2[j]);
    }

  }

}


void candidate(unsigned int x1[4], unsigned int x2[4], unsigned int y_1[4], unsigned int y_2[4], unsigned int a[16])
{
  for (int i = 0; i < 4; ++i)
  {
    unsigned int p0 = a[4 * i] * y_1[0];
    unsigned int p1 = a[(4 * i) + 1] * y_1[1];
    unsigned int p2 = a[(4 * i) + 2] * y_1[2];
    unsigned int p3 = a[(4 * i) + 3] * y_1[3];
    unsigned int q0 = a[i] * y_2[0];
    unsigned int q1 = a[4 + i] * y_2[1];
    unsigned int q2 = a[8 + i] * y_2[2];
    unsigned int q3 = a[12 + i] * y_2[3];
    x1[i] += (p0 + p1) + (p2 + p3);
    x2[i] += (q0 + q1) + (q2 + q3);
  }

}


int main(void) {
{
unsigned int a_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 0\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 1\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_0[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_4[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_4[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 2\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_0[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_1[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_1[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_2[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_2[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_3[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_3[4]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_4[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_4[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 3\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_0[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_1[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_1[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_2[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_2[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_3[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_3[4]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_4[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_4[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 4\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_0[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_1[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_1[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_2[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_2[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_3[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_3[4]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_4[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_4[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 5\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_0[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_1[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_1[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_2[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_2[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_3[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_3[4]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_4[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_4[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 6\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_0[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_1[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_1[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_2[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_2[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_3[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_3[4]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_4[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_4[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 7\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_0[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_1[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_1[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_2[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_2[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_3[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_3[4]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_4[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_4[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 8\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 9\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 10\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 11\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_0[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_1[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[4]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_4[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_4[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 12\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_0[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_1[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[4]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_4[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 13\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_0[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_1[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[4]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_4[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 14\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_0[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_1[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_1[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_2[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_2[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_3[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_3[4]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_4[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_4[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 15\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)479227941ULL),((unsigned int)961036823ULL),((unsigned int)3131799747ULL),((unsigned int)1529880420ULL)};
unsigned int b_0[4]={((unsigned int)479227941ULL),((unsigned int)961036823ULL),((unsigned int)3131799747ULL),((unsigned int)1529880420ULL)};
unsigned int a_1[4]={((unsigned int)3467963354ULL),((unsigned int)3891622656ULL),((unsigned int)588625831ULL),((unsigned int)3199978015ULL)};
unsigned int b_1[4]={((unsigned int)3467963354ULL),((unsigned int)3891622656ULL),((unsigned int)588625831ULL),((unsigned int)3199978015ULL)};
unsigned int a_2[4]={((unsigned int)80743164ULL),((unsigned int)3200478332ULL),((unsigned int)3027523336ULL),((unsigned int)1888882516ULL)};
unsigned int b_2[4]={((unsigned int)80743164ULL),((unsigned int)3200478332ULL),((unsigned int)3027523336ULL),((unsigned int)1888882516ULL)};
unsigned int a_3[4]={((unsigned int)759961514ULL),((unsigned int)739651291ULL),((unsigned int)3273085522ULL),((unsigned int)103976144ULL)};
unsigned int b_3[4]={((unsigned int)759961514ULL),((unsigned int)739651291ULL),((unsigned int)3273085522ULL),((unsigned int)103976144ULL)};
unsigned int a_4[16]={((unsigned int)316780586ULL),((unsigned int)3454962000ULL),((unsigned int)1157231535ULL),((unsigned int)3348527390ULL),((unsigned int)4281227967ULL),((unsigned int)1138877201ULL),((unsigned int)3064206287ULL),((unsigned int)1237452351ULL),((unsigned int)3741543761ULL),((unsigned int)1452469421ULL),((unsigned int)1439027729ULL),((unsigned int)2300191491ULL),((unsigned int)4094631903ULL),((unsigned int)1530016737ULL),((unsigned int)1008101905ULL),((unsigned int)1710205109ULL)};
unsigned int b_4[16]={((unsigned int)316780586ULL),((unsigned int)3454962000ULL),((unsigned int)1157231535ULL),((unsigned int)3348527390ULL),((unsigned int)4281227967ULL),((unsigned int)1138877201ULL),((unsigned int)3064206287ULL),((unsigned int)1237452351ULL),((unsigned int)3741543761ULL),((unsigned int)1452469421ULL),((unsigned int)1439027729ULL),((unsigned int)2300191491ULL),((unsigned int)4094631903ULL),((unsigned int)1530016737ULL),((unsigned int)1008101905ULL),((unsigned int)1710205109ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2441936281ULL),((unsigned int)680589375ULL),((unsigned int)3667576711ULL),((unsigned int)2082954026ULL)};
unsigned int b_0[4]={((unsigned int)2441936281ULL),((unsigned int)680589375ULL),((unsigned int)3667576711ULL),((unsigned int)2082954026ULL)};
unsigned int a_1[4]={((unsigned int)2484427038ULL),((unsigned int)1239340862ULL),((unsigned int)4240617900ULL),((unsigned int)61031398ULL)};
unsigned int b_1[4]={((unsigned int)2484427038ULL),((unsigned int)1239340862ULL),((unsigned int)4240617900ULL),((unsigned int)61031398ULL)};
unsigned int a_2[4]={((unsigned int)90831460ULL),((unsigned int)2825680879ULL),((unsigned int)3896850713ULL),((unsigned int)830625353ULL)};
unsigned int b_2[4]={((unsigned int)90831460ULL),((unsigned int)2825680879ULL),((unsigned int)3896850713ULL),((unsigned int)830625353ULL)};
unsigned int a_3[4]={((unsigned int)1472940502ULL),((unsigned int)2169042453ULL),((unsigned int)2225963561ULL),((unsigned int)2087549412ULL)};
unsigned int b_3[4]={((unsigned int)1472940502ULL),((unsigned int)2169042453ULL),((unsigned int)2225963561ULL),((unsigned int)2087549412ULL)};
unsigned int a_4[16]={((unsigned int)1077502832ULL),((unsigned int)3687530071ULL),((unsigned int)4103158290ULL),((unsigned int)3478202394ULL),((unsigned int)439437518ULL),((unsigned int)1650714139ULL),((unsigned int)737717063ULL),((unsigned int)2781641880ULL),((unsigned int)2470158229ULL),((unsigned int)4257016841ULL),((unsigned int)301984980ULL),((unsigned int)688669067ULL),((unsigned int)129264357ULL),((unsigned int)351980152ULL),((unsigned int)2608828485ULL),((unsigned int)3541059192ULL)};
unsigned int b_4[16]={((unsigned int)1077502832ULL),((unsigned int)3687530071ULL),((unsigned int)4103158290ULL),((unsigned int)3478202394ULL),((unsigned int)439437518ULL),((unsigned int)1650714139ULL),((unsigned int)737717063ULL),((unsigned int)2781641880ULL),((unsigned int)2470158229ULL),((unsigned int)4257016841ULL),((unsigned int)301984980ULL),((unsigned int)688669067ULL),((unsigned int)129264357ULL),((unsigned int)351980152ULL),((unsigned int)2608828485ULL),((unsigned int)3541059192ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1702775363ULL),((unsigned int)2561786604ULL),((unsigned int)1845485718ULL),((unsigned int)3797297609ULL)};
unsigned int b_0[4]={((unsigned int)1702775363ULL),((unsigned int)2561786604ULL),((unsigned int)1845485718ULL),((unsigned int)3797297609ULL)};
unsigned int a_1[4]={((unsigned int)168015342ULL),((unsigned int)3956723839ULL),((unsigned int)1927766391ULL),((unsigned int)4078106571ULL)};
unsigned int b_1[4]={((unsigned int)168015342ULL),((unsigned int)3956723839ULL),((unsigned int)1927766391ULL),((unsigned int)4078106571ULL)};
unsigned int a_2[4]={((unsigned int)2149033849ULL),((unsigned int)2769780823ULL),((unsigned int)972825351ULL),((unsigned int)3150426320ULL)};
unsigned int b_2[4]={((unsigned int)2149033849ULL),((unsigned int)2769780823ULL),((unsigned int)972825351ULL),((unsigned int)3150426320ULL)};
unsigned int a_3[4]={((unsigned int)3495668575ULL),((unsigned int)1090694404ULL),((unsigned int)1980768547ULL),((unsigned int)1054222716ULL)};
unsigned int b_3[4]={((unsigned int)3495668575ULL),((unsigned int)1090694404ULL),((unsigned int)1980768547ULL),((unsigned int)1054222716ULL)};
unsigned int a_4[16]={((unsigned int)2711835303ULL),((unsigned int)3100010292ULL),((unsigned int)3859707216ULL),((unsigned int)512410390ULL),((unsigned int)4153154265ULL),((unsigned int)4254218767ULL),((unsigned int)2026331612ULL),((unsigned int)2771984361ULL),((unsigned int)2479330353ULL),((unsigned int)2053298916ULL),((unsigned int)249475606ULL),((unsigned int)2884347842ULL),((unsigned int)3440537057ULL),((unsigned int)54182319ULL),((unsigned int)2691811790ULL),((unsigned int)1506377209ULL)};
unsigned int b_4[16]={((unsigned int)2711835303ULL),((unsigned int)3100010292ULL),((unsigned int)3859707216ULL),((unsigned int)512410390ULL),((unsigned int)4153154265ULL),((unsigned int)4254218767ULL),((unsigned int)2026331612ULL),((unsigned int)2771984361ULL),((unsigned int)2479330353ULL),((unsigned int)2053298916ULL),((unsigned int)249475606ULL),((unsigned int)2884347842ULL),((unsigned int)3440537057ULL),((unsigned int)54182319ULL),((unsigned int)2691811790ULL),((unsigned int)1506377209ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2639886980ULL),((unsigned int)2713974596ULL),((unsigned int)3748656563ULL),((unsigned int)3772924ULL)};
unsigned int b_0[4]={((unsigned int)2639886980ULL),((unsigned int)2713974596ULL),((unsigned int)3748656563ULL),((unsigned int)3772924ULL)};
unsigned int a_1[4]={((unsigned int)2737066912ULL),((unsigned int)945890245ULL),((unsigned int)1940002333ULL),((unsigned int)1613462701ULL)};
unsigned int b_1[4]={((unsigned int)2737066912ULL),((unsigned int)945890245ULL),((unsigned int)1940002333ULL),((unsigned int)1613462701ULL)};
unsigned int a_2[4]={((unsigned int)532219099ULL),((unsigned int)3313576852ULL),((unsigned int)372435278ULL),((unsigned int)93465491ULL)};
unsigned int b_2[4]={((unsigned int)532219099ULL),((unsigned int)3313576852ULL),((unsigned int)372435278ULL),((unsigned int)93465491ULL)};
unsigned int a_3[4]={((unsigned int)2507685757ULL),((unsigned int)4137251743ULL),((unsigned int)796083039ULL),((unsigned int)3721080400ULL)};
unsigned int b_3[4]={((unsigned int)2507685757ULL),((unsigned int)4137251743ULL),((unsigned int)796083039ULL),((unsigned int)3721080400ULL)};
unsigned int a_4[16]={((unsigned int)2375724143ULL),((unsigned int)3709809393ULL),((unsigned int)3787839310ULL),((unsigned int)4278680634ULL),((unsigned int)1002132595ULL),((unsigned int)3244202980ULL),((unsigned int)1669988301ULL),((unsigned int)1294587707ULL),((unsigned int)309889676ULL),((unsigned int)1396818837ULL),((unsigned int)677150969ULL),((unsigned int)1275361601ULL),((unsigned int)2459171508ULL),((unsigned int)1279559673ULL),((unsigned int)1069586869ULL),((unsigned int)2361743115ULL)};
unsigned int b_4[16]={((unsigned int)2375724143ULL),((unsigned int)3709809393ULL),((unsigned int)3787839310ULL),((unsigned int)4278680634ULL),((unsigned int)1002132595ULL),((unsigned int)3244202980ULL),((unsigned int)1669988301ULL),((unsigned int)1294587707ULL),((unsigned int)309889676ULL),((unsigned int)1396818837ULL),((unsigned int)677150969ULL),((unsigned int)1275361601ULL),((unsigned int)2459171508ULL),((unsigned int)1279559673ULL),((unsigned int)1069586869ULL),((unsigned int)2361743115ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)379284615ULL),((unsigned int)2066121468ULL),((unsigned int)2923316009ULL),((unsigned int)1624698753ULL)};
unsigned int b_0[4]={((unsigned int)379284615ULL),((unsigned int)2066121468ULL),((unsigned int)2923316009ULL),((unsigned int)1624698753ULL)};
unsigned int a_1[4]={((unsigned int)783231911ULL),((unsigned int)3311504561ULL),((unsigned int)3052838323ULL),((unsigned int)2505191021ULL)};
unsigned int b_1[4]={((unsigned int)783231911ULL),((unsigned int)3311504561ULL),((unsigned int)3052838323ULL),((unsigned int)2505191021ULL)};
unsigned int a_2[4]={((unsigned int)2162298582ULL),((unsigned int)2148013597ULL),((unsigned int)2345275556ULL),((unsigned int)2754292086ULL)};
unsigned int b_2[4]={((unsigned int)2162298582ULL),((unsigned int)2148013597ULL),((unsigned int)2345275556ULL),((unsigned int)2754292086ULL)};
unsigned int a_3[4]={((unsigned int)1882550016ULL),((unsigned int)128203795ULL),((unsigned int)352064560ULL),((unsigned int)2435225971ULL)};
unsigned int b_3[4]={((unsigned int)1882550016ULL),((unsigned int)128203795ULL),((unsigned int)352064560ULL),((unsigned int)2435225971ULL)};
unsigned int a_4[16]={((unsigned int)2081264604ULL),((unsigned int)1520492555ULL),((unsigned int)207406769ULL),((unsigned int)2202754689ULL),((unsigned int)2506562274ULL),((unsigned int)341361733ULL),((unsigned int)3216016532ULL),((unsigned int)614478673ULL),((unsigned int)3985418637ULL),((unsigned int)79774193ULL),((unsigned int)1174402949ULL),((unsigned int)1796417999ULL),((unsigned int)1573558610ULL),((unsigned int)2057303098ULL),((unsigned int)825803520ULL),((unsigned int)1057544785ULL)};
unsigned int b_4[16]={((unsigned int)2081264604ULL),((unsigned int)1520492555ULL),((unsigned int)207406769ULL),((unsigned int)2202754689ULL),((unsigned int)2506562274ULL),((unsigned int)341361733ULL),((unsigned int)3216016532ULL),((unsigned int)614478673ULL),((unsigned int)3985418637ULL),((unsigned int)79774193ULL),((unsigned int)1174402949ULL),((unsigned int)1796417999ULL),((unsigned int)1573558610ULL),((unsigned int)2057303098ULL),((unsigned int)825803520ULL),((unsigned int)1057544785ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3694418444ULL),((unsigned int)2150015149ULL),((unsigned int)1822356029ULL),((unsigned int)4199435790ULL)};
unsigned int b_0[4]={((unsigned int)3694418444ULL),((unsigned int)2150015149ULL),((unsigned int)1822356029ULL),((unsigned int)4199435790ULL)};
unsigned int a_1[4]={((unsigned int)1256634997ULL),((unsigned int)2771140737ULL),((unsigned int)4020891688ULL),((unsigned int)1486671454ULL)};
unsigned int b_1[4]={((unsigned int)1256634997ULL),((unsigned int)2771140737ULL),((unsigned int)4020891688ULL),((unsigned int)1486671454ULL)};
unsigned int a_2[4]={((unsigned int)2466855616ULL),((unsigned int)1267272575ULL),((unsigned int)2442849938ULL),((unsigned int)2375810618ULL)};
unsigned int b_2[4]={((unsigned int)2466855616ULL),((unsigned int)1267272575ULL),((unsigned int)2442849938ULL),((unsigned int)2375810618ULL)};
unsigned int a_3[4]={((unsigned int)992005118ULL),((unsigned int)4059113559ULL),((unsigned int)3614759976ULL),((unsigned int)3986460840ULL)};
unsigned int b_3[4]={((unsigned int)992005118ULL),((unsigned int)4059113559ULL),((unsigned int)3614759976ULL),((unsigned int)3986460840ULL)};
unsigned int a_4[16]={((unsigned int)2676591091ULL),((unsigned int)373914125ULL),((unsigned int)3547348502ULL),((unsigned int)3324144265ULL),((unsigned int)3495829249ULL),((unsigned int)1382267985ULL),((unsigned int)1524994680ULL),((unsigned int)3498000971ULL),((unsigned int)719791318ULL),((unsigned int)3611657659ULL),((unsigned int)527679754ULL),((unsigned int)308682971ULL),((unsigned int)1210754664ULL),((unsigned int)1223641244ULL),((unsigned int)2780273309ULL),((unsigned int)279928255ULL)};
unsigned int b_4[16]={((unsigned int)2676591091ULL),((unsigned int)373914125ULL),((unsigned int)3547348502ULL),((unsigned int)3324144265ULL),((unsigned int)3495829249ULL),((unsigned int)1382267985ULL),((unsigned int)1524994680ULL),((unsigned int)3498000971ULL),((unsigned int)719791318ULL),((unsigned int)3611657659ULL),((unsigned int)527679754ULL),((unsigned int)308682971ULL),((unsigned int)1210754664ULL),((unsigned int)1223641244ULL),((unsigned int)2780273309ULL),((unsigned int)279928255ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1078958717ULL),((unsigned int)3320189531ULL),((unsigned int)1720287306ULL),((unsigned int)3826538151ULL)};
unsigned int b_0[4]={((unsigned int)1078958717ULL),((unsigned int)3320189531ULL),((unsigned int)1720287306ULL),((unsigned int)3826538151ULL)};
unsigned int a_1[4]={((unsigned int)3390884121ULL),((unsigned int)2184149143ULL),((unsigned int)2815068295ULL),((unsigned int)3935158715ULL)};
unsigned int b_1[4]={((unsigned int)3390884121ULL),((unsigned int)2184149143ULL),((unsigned int)2815068295ULL),((unsigned int)3935158715ULL)};
unsigned int a_2[4]={((unsigned int)339876912ULL),((unsigned int)905807883ULL),((unsigned int)1962354424ULL),((unsigned int)4176810697ULL)};
unsigned int b_2[4]={((unsigned int)339876912ULL),((unsigned int)905807883ULL),((unsigned int)1962354424ULL),((unsigned int)4176810697ULL)};
unsigned int a_3[4]={((unsigned int)53784688ULL),((unsigned int)1780332685ULL),((unsigned int)3304747640ULL),((unsigned int)886406446ULL)};
unsigned int b_3[4]={((unsigned int)53784688ULL),((unsigned int)1780332685ULL),((unsigned int)3304747640ULL),((unsigned int)886406446ULL)};
unsigned int a_4[16]={((unsigned int)3156351304ULL),((unsigned int)3903579086ULL),((unsigned int)2436705812ULL),((unsigned int)3282277547ULL),((unsigned int)1555532340ULL),((unsigned int)1210123963ULL),((unsigned int)1529599086ULL),((unsigned int)3837883344ULL),((unsigned int)685404405ULL),((unsigned int)3287210586ULL),((unsigned int)553576571ULL),((unsigned int)3973972032ULL),((unsigned int)3056420655ULL),((unsigned int)3507131883ULL),((unsigned int)471141257ULL),((unsigned int)1409969104ULL)};
unsigned int b_4[16]={((unsigned int)3156351304ULL),((unsigned int)3903579086ULL),((unsigned int)2436705812ULL),((unsigned int)3282277547ULL),((unsigned int)1555532340ULL),((unsigned int)1210123963ULL),((unsigned int)1529599086ULL),((unsigned int)3837883344ULL),((unsigned int)685404405ULL),((unsigned int)3287210586ULL),((unsigned int)553576571ULL),((unsigned int)3973972032ULL),((unsigned int)3056420655ULL),((unsigned int)3507131883ULL),((unsigned int)471141257ULL),((unsigned int)1409969104ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)51226014ULL),((unsigned int)3841700916ULL),((unsigned int)1708001027ULL),((unsigned int)1794563770ULL)};
unsigned int b_0[4]={((unsigned int)51226014ULL),((unsigned int)3841700916ULL),((unsigned int)1708001027ULL),((unsigned int)1794563770ULL)};
unsigned int a_1[4]={((unsigned int)3977053438ULL),((unsigned int)1328854108ULL),((unsigned int)3045301547ULL),((unsigned int)1570976502ULL)};
unsigned int b_1[4]={((unsigned int)3977053438ULL),((unsigned int)1328854108ULL),((unsigned int)3045301547ULL),((unsigned int)1570976502ULL)};
unsigned int a_2[4]={((unsigned int)4216648133ULL),((unsigned int)1336509788ULL),((unsigned int)3578246280ULL),((unsigned int)3488125789ULL)};
unsigned int b_2[4]={((unsigned int)4216648133ULL),((unsigned int)1336509788ULL),((unsigned int)3578246280ULL),((unsigned int)3488125789ULL)};
unsigned int a_3[4]={((unsigned int)1462748170ULL),((unsigned int)3151448921ULL),((unsigned int)2675581615ULL),((unsigned int)3003506738ULL)};
unsigned int b_3[4]={((unsigned int)1462748170ULL),((unsigned int)3151448921ULL),((unsigned int)2675581615ULL),((unsigned int)3003506738ULL)};
unsigned int a_4[16]={((unsigned int)2715367072ULL),((unsigned int)4239011057ULL),((unsigned int)524074224ULL),((unsigned int)1039106400ULL),((unsigned int)814248987ULL),((unsigned int)1061026999ULL),((unsigned int)281424411ULL),((unsigned int)1328272623ULL),((unsigned int)2067760500ULL),((unsigned int)1477384918ULL),((unsigned int)876569895ULL),((unsigned int)119285407ULL),((unsigned int)3690004658ULL),((unsigned int)262429674ULL),((unsigned int)1054564191ULL),((unsigned int)2580094391ULL)};
unsigned int b_4[16]={((unsigned int)2715367072ULL),((unsigned int)4239011057ULL),((unsigned int)524074224ULL),((unsigned int)1039106400ULL),((unsigned int)814248987ULL),((unsigned int)1061026999ULL),((unsigned int)281424411ULL),((unsigned int)1328272623ULL),((unsigned int)2067760500ULL),((unsigned int)1477384918ULL),((unsigned int)876569895ULL),((unsigned int)119285407ULL),((unsigned int)3690004658ULL),((unsigned int)262429674ULL),((unsigned int)1054564191ULL),((unsigned int)2580094391ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3239960582ULL),((unsigned int)239715575ULL),((unsigned int)4185410684ULL),((unsigned int)3067778669ULL)};
unsigned int b_0[4]={((unsigned int)3239960582ULL),((unsigned int)239715575ULL),((unsigned int)4185410684ULL),((unsigned int)3067778669ULL)};
unsigned int a_1[4]={((unsigned int)1928571174ULL),((unsigned int)4278196005ULL),((unsigned int)2979258992ULL),((unsigned int)3735044759ULL)};
unsigned int b_1[4]={((unsigned int)1928571174ULL),((unsigned int)4278196005ULL),((unsigned int)2979258992ULL),((unsigned int)3735044759ULL)};
unsigned int a_2[4]={((unsigned int)3099796937ULL),((unsigned int)3782569999ULL),((unsigned int)2464405475ULL),((unsigned int)112080494ULL)};
unsigned int b_2[4]={((unsigned int)3099796937ULL),((unsigned int)3782569999ULL),((unsigned int)2464405475ULL),((unsigned int)112080494ULL)};
unsigned int a_3[4]={((unsigned int)3836045538ULL),((unsigned int)2113464977ULL),((unsigned int)1493885890ULL),((unsigned int)1707585530ULL)};
unsigned int b_3[4]={((unsigned int)3836045538ULL),((unsigned int)2113464977ULL),((unsigned int)1493885890ULL),((unsigned int)1707585530ULL)};
unsigned int a_4[16]={((unsigned int)1462689580ULL),((unsigned int)1590474877ULL),((unsigned int)2294735774ULL),((unsigned int)3475133461ULL),((unsigned int)995305800ULL),((unsigned int)281381255ULL),((unsigned int)196563113ULL),((unsigned int)946561648ULL),((unsigned int)3088710586ULL),((unsigned int)393455444ULL),((unsigned int)2993226195ULL),((unsigned int)66689950ULL),((unsigned int)550898163ULL),((unsigned int)1416324774ULL),((unsigned int)271082774ULL),((unsigned int)3801062547ULL)};
unsigned int b_4[16]={((unsigned int)1462689580ULL),((unsigned int)1590474877ULL),((unsigned int)2294735774ULL),((unsigned int)3475133461ULL),((unsigned int)995305800ULL),((unsigned int)281381255ULL),((unsigned int)196563113ULL),((unsigned int)946561648ULL),((unsigned int)3088710586ULL),((unsigned int)393455444ULL),((unsigned int)2993226195ULL),((unsigned int)66689950ULL),((unsigned int)550898163ULL),((unsigned int)1416324774ULL),((unsigned int)271082774ULL),((unsigned int)3801062547ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4020507144ULL),((unsigned int)283578553ULL),((unsigned int)3453705509ULL),((unsigned int)4141388890ULL)};
unsigned int b_0[4]={((unsigned int)4020507144ULL),((unsigned int)283578553ULL),((unsigned int)3453705509ULL),((unsigned int)4141388890ULL)};
unsigned int a_1[4]={((unsigned int)4035202878ULL),((unsigned int)2511395298ULL),((unsigned int)3225270102ULL),((unsigned int)3261208387ULL)};
unsigned int b_1[4]={((unsigned int)4035202878ULL),((unsigned int)2511395298ULL),((unsigned int)3225270102ULL),((unsigned int)3261208387ULL)};
unsigned int a_2[4]={((unsigned int)1718679480ULL),((unsigned int)3658446571ULL),((unsigned int)449770403ULL),((unsigned int)3128576026ULL)};
unsigned int b_2[4]={((unsigned int)1718679480ULL),((unsigned int)3658446571ULL),((unsigned int)449770403ULL),((unsigned int)3128576026ULL)};
unsigned int a_3[4]={((unsigned int)414224182ULL),((unsigned int)3467401633ULL),((unsigned int)3829892427ULL),((unsigned int)2358502768ULL)};
unsigned int b_3[4]={((unsigned int)414224182ULL),((unsigned int)3467401633ULL),((unsigned int)3829892427ULL),((unsigned int)2358502768ULL)};
unsigned int a_4[16]={((unsigned int)1555436547ULL),((unsigned int)4099800344ULL),((unsigned int)2308097477ULL),((unsigned int)1311859810ULL),((unsigned int)4272613604ULL),((unsigned int)4143072093ULL),((unsigned int)4282943730ULL),((unsigned int)496678886ULL),((unsigned int)4262473303ULL),((unsigned int)3421958428ULL),((unsigned int)446716117ULL),((unsigned int)4151534004ULL),((unsigned int)3538002959ULL),((unsigned int)852131607ULL),((unsigned int)2669746609ULL),((unsigned int)2135694260ULL)};
unsigned int b_4[16]={((unsigned int)1555436547ULL),((unsigned int)4099800344ULL),((unsigned int)2308097477ULL),((unsigned int)1311859810ULL),((unsigned int)4272613604ULL),((unsigned int)4143072093ULL),((unsigned int)4282943730ULL),((unsigned int)496678886ULL),((unsigned int)4262473303ULL),((unsigned int)3421958428ULL),((unsigned int)446716117ULL),((unsigned int)4151534004ULL),((unsigned int)3538002959ULL),((unsigned int)852131607ULL),((unsigned int)2669746609ULL),((unsigned int)2135694260ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)634392457ULL),((unsigned int)397896090ULL),((unsigned int)3065612135ULL),((unsigned int)1452859028ULL)};
unsigned int b_0[4]={((unsigned int)634392457ULL),((unsigned int)397896090ULL),((unsigned int)3065612135ULL),((unsigned int)1452859028ULL)};
unsigned int a_1[4]={((unsigned int)58575795ULL),((unsigned int)1765764158ULL),((unsigned int)3403331478ULL),((unsigned int)1108554603ULL)};
unsigned int b_1[4]={((unsigned int)58575795ULL),((unsigned int)1765764158ULL),((unsigned int)3403331478ULL),((unsigned int)1108554603ULL)};
unsigned int a_2[4]={((unsigned int)1806143213ULL),((unsigned int)1079066301ULL),((unsigned int)3571495546ULL),((unsigned int)2079177180ULL)};
unsigned int b_2[4]={((unsigned int)1806143213ULL),((unsigned int)1079066301ULL),((unsigned int)3571495546ULL),((unsigned int)2079177180ULL)};
unsigned int a_3[4]={((unsigned int)848236337ULL),((unsigned int)1238022530ULL),((unsigned int)1472155258ULL),((unsigned int)3822621571ULL)};
unsigned int b_3[4]={((unsigned int)848236337ULL),((unsigned int)1238022530ULL),((unsigned int)1472155258ULL),((unsigned int)3822621571ULL)};
unsigned int a_4[16]={((unsigned int)212059361ULL),((unsigned int)2397802455ULL),((unsigned int)2252934003ULL),((unsigned int)9556153ULL),((unsigned int)2664361966ULL),((unsigned int)1356494580ULL),((unsigned int)1093026939ULL),((unsigned int)524841203ULL),((unsigned int)4253360701ULL),((unsigned int)2218690424ULL),((unsigned int)1361447989ULL),((unsigned int)3717988075ULL),((unsigned int)1283763533ULL),((unsigned int)15635406ULL),((unsigned int)4207570532ULL),((unsigned int)2857421157ULL)};
unsigned int b_4[16]={((unsigned int)212059361ULL),((unsigned int)2397802455ULL),((unsigned int)2252934003ULL),((unsigned int)9556153ULL),((unsigned int)2664361966ULL),((unsigned int)1356494580ULL),((unsigned int)1093026939ULL),((unsigned int)524841203ULL),((unsigned int)4253360701ULL),((unsigned int)2218690424ULL),((unsigned int)1361447989ULL),((unsigned int)3717988075ULL),((unsigned int)1283763533ULL),((unsigned int)15635406ULL),((unsigned int)4207570532ULL),((unsigned int)2857421157ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)201036120ULL),((unsigned int)4046570399ULL),((unsigned int)3702490424ULL),((unsigned int)3500545940ULL)};
unsigned int b_0[4]={((unsigned int)201036120ULL),((unsigned int)4046570399ULL),((unsigned int)3702490424ULL),((unsigned int)3500545940ULL)};
unsigned int a_1[4]={((unsigned int)767439743ULL),((unsigned int)2065336567ULL),((unsigned int)1328045165ULL),((unsigned int)324170897ULL)};
unsigned int b_1[4]={((unsigned int)767439743ULL),((unsigned int)2065336567ULL),((unsigned int)1328045165ULL),((unsigned int)324170897ULL)};
unsigned int a_2[4]={((unsigned int)1571475806ULL),((unsigned int)1525599211ULL),((unsigned int)3078552926ULL),((unsigned int)3089703576ULL)};
unsigned int b_2[4]={((unsigned int)1571475806ULL),((unsigned int)1525599211ULL),((unsigned int)3078552926ULL),((unsigned int)3089703576ULL)};
unsigned int a_3[4]={((unsigned int)626610362ULL),((unsigned int)3757365641ULL),((unsigned int)3306197313ULL),((unsigned int)3723780835ULL)};
unsigned int b_3[4]={((unsigned int)626610362ULL),((unsigned int)3757365641ULL),((unsigned int)3306197313ULL),((unsigned int)3723780835ULL)};
unsigned int a_4[16]={((unsigned int)3092749354ULL),((unsigned int)3228982778ULL),((unsigned int)86102787ULL),((unsigned int)2521912441ULL),((unsigned int)1877375582ULL),((unsigned int)2526330480ULL),((unsigned int)996204508ULL),((unsigned int)3947787163ULL),((unsigned int)2749104046ULL),((unsigned int)2334997646ULL),((unsigned int)1050467586ULL),((unsigned int)3839866689ULL),((unsigned int)2810581283ULL),((unsigned int)3065491717ULL),((unsigned int)15306251ULL),((unsigned int)3589397868ULL)};
unsigned int b_4[16]={((unsigned int)3092749354ULL),((unsigned int)3228982778ULL),((unsigned int)86102787ULL),((unsigned int)2521912441ULL),((unsigned int)1877375582ULL),((unsigned int)2526330480ULL),((unsigned int)996204508ULL),((unsigned int)3947787163ULL),((unsigned int)2749104046ULL),((unsigned int)2334997646ULL),((unsigned int)1050467586ULL),((unsigned int)3839866689ULL),((unsigned int)2810581283ULL),((unsigned int)3065491717ULL),((unsigned int)15306251ULL),((unsigned int)3589397868ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2889584330ULL),((unsigned int)1844822254ULL),((unsigned int)3348966198ULL),((unsigned int)3943574692ULL)};
unsigned int b_0[4]={((unsigned int)2889584330ULL),((unsigned int)1844822254ULL),((unsigned int)3348966198ULL),((unsigned int)3943574692ULL)};
unsigned int a_1[4]={((unsigned int)2477253888ULL),((unsigned int)1648744844ULL),((unsigned int)4006840897ULL),((unsigned int)2052244090ULL)};
unsigned int b_1[4]={((unsigned int)2477253888ULL),((unsigned int)1648744844ULL),((unsigned int)4006840897ULL),((unsigned int)2052244090ULL)};
unsigned int a_2[4]={((unsigned int)3431523107ULL),((unsigned int)2261111238ULL),((unsigned int)4081479834ULL),((unsigned int)1218727578ULL)};
unsigned int b_2[4]={((unsigned int)3431523107ULL),((unsigned int)2261111238ULL),((unsigned int)4081479834ULL),((unsigned int)1218727578ULL)};
unsigned int a_3[4]={((unsigned int)3352548232ULL),((unsigned int)2052019591ULL),((unsigned int)3763119601ULL),((unsigned int)514813957ULL)};
unsigned int b_3[4]={((unsigned int)3352548232ULL),((unsigned int)2052019591ULL),((unsigned int)3763119601ULL),((unsigned int)514813957ULL)};
unsigned int a_4[16]={((unsigned int)1299175545ULL),((unsigned int)4187970490ULL),((unsigned int)778395454ULL),((unsigned int)2310741873ULL),((unsigned int)272349960ULL),((unsigned int)1981200489ULL),((unsigned int)3953815093ULL),((unsigned int)3840645449ULL),((unsigned int)2468795287ULL),((unsigned int)909721668ULL),((unsigned int)749327287ULL),((unsigned int)3598787651ULL),((unsigned int)1168765044ULL),((unsigned int)645839194ULL),((unsigned int)3396354233ULL),((unsigned int)759473744ULL)};
unsigned int b_4[16]={((unsigned int)1299175545ULL),((unsigned int)4187970490ULL),((unsigned int)778395454ULL),((unsigned int)2310741873ULL),((unsigned int)272349960ULL),((unsigned int)1981200489ULL),((unsigned int)3953815093ULL),((unsigned int)3840645449ULL),((unsigned int)2468795287ULL),((unsigned int)909721668ULL),((unsigned int)749327287ULL),((unsigned int)3598787651ULL),((unsigned int)1168765044ULL),((unsigned int)645839194ULL),((unsigned int)3396354233ULL),((unsigned int)759473744ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)636907440ULL),((unsigned int)1660109819ULL),((unsigned int)1039041336ULL),((unsigned int)4153336157ULL)};
unsigned int b_0[4]={((unsigned int)636907440ULL),((unsigned int)1660109819ULL),((unsigned int)1039041336ULL),((unsigned int)4153336157ULL)};
unsigned int a_1[4]={((unsigned int)504945249ULL),((unsigned int)1853872486ULL),((unsigned int)87355243ULL),((unsigned int)3145813150ULL)};
unsigned int b_1[4]={((unsigned int)504945249ULL),((unsigned int)1853872486ULL),((unsigned int)87355243ULL),((unsigned int)3145813150ULL)};
unsigned int a_2[4]={((unsigned int)4076309635ULL),((unsigned int)1240392964ULL),((unsigned int)1820456935ULL),((unsigned int)2418124134ULL)};
unsigned int b_2[4]={((unsigned int)4076309635ULL),((unsigned int)1240392964ULL),((unsigned int)1820456935ULL),((unsigned int)2418124134ULL)};
unsigned int a_3[4]={((unsigned int)415722905ULL),((unsigned int)3046891717ULL),((unsigned int)3116988344ULL),((unsigned int)1661175817ULL)};
unsigned int b_3[4]={((unsigned int)415722905ULL),((unsigned int)3046891717ULL),((unsigned int)3116988344ULL),((unsigned int)1661175817ULL)};
unsigned int a_4[16]={((unsigned int)851290595ULL),((unsigned int)1167526351ULL),((unsigned int)1207117916ULL),((unsigned int)3461435071ULL),((unsigned int)145134238ULL),((unsigned int)1393640388ULL),((unsigned int)631183400ULL),((unsigned int)3270976609ULL),((unsigned int)3945740746ULL),((unsigned int)2183192891ULL),((unsigned int)1552697751ULL),((unsigned int)401577038ULL),((unsigned int)2161933520ULL),((unsigned int)1149063545ULL),((unsigned int)2718670900ULL),((unsigned int)4082357099ULL)};
unsigned int b_4[16]={((unsigned int)851290595ULL),((unsigned int)1167526351ULL),((unsigned int)1207117916ULL),((unsigned int)3461435071ULL),((unsigned int)145134238ULL),((unsigned int)1393640388ULL),((unsigned int)631183400ULL),((unsigned int)3270976609ULL),((unsigned int)3945740746ULL),((unsigned int)2183192891ULL),((unsigned int)1552697751ULL),((unsigned int)401577038ULL),((unsigned int)2161933520ULL),((unsigned int)1149063545ULL),((unsigned int)2718670900ULL),((unsigned int)4082357099ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3409385865ULL),((unsigned int)1286583980ULL),((unsigned int)2996428110ULL),((unsigned int)2955909779ULL)};
unsigned int b_0[4]={((unsigned int)3409385865ULL),((unsigned int)1286583980ULL),((unsigned int)2996428110ULL),((unsigned int)2955909779ULL)};
unsigned int a_1[4]={((unsigned int)1860493534ULL),((unsigned int)2699373413ULL),((unsigned int)3279084496ULL),((unsigned int)4009321560ULL)};
unsigned int b_1[4]={((unsigned int)1860493534ULL),((unsigned int)2699373413ULL),((unsigned int)3279084496ULL),((unsigned int)4009321560ULL)};
unsigned int a_2[4]={((unsigned int)548072610ULL),((unsigned int)666222934ULL),((unsigned int)2864862684ULL),((unsigned int)3011703418ULL)};
unsigned int b_2[4]={((unsigned int)548072610ULL),((unsigned int)666222934ULL),((unsigned int)2864862684ULL),((unsigned int)3011703418ULL)};
unsigned int a_3[4]={((unsigned int)575874084ULL),((unsigned int)3481770050ULL),((unsigned int)1150693830ULL),((unsigned int)939448666ULL)};
unsigned int b_3[4]={((unsigned int)575874084ULL),((unsigned int)3481770050ULL),((unsigned int)1150693830ULL),((unsigned int)939448666ULL)};
unsigned int a_4[16]={((unsigned int)3059824246ULL),((unsigned int)662027313ULL),((unsigned int)217189136ULL),((unsigned int)1140519603ULL),((unsigned int)2385401936ULL),((unsigned int)89622323ULL),((unsigned int)2696712997ULL),((unsigned int)4286979120ULL),((unsigned int)3053590899ULL),((unsigned int)1225000130ULL),((unsigned int)4007137502ULL),((unsigned int)2909663224ULL),((unsigned int)3082152204ULL),((unsigned int)2676291900ULL),((unsigned int)2772510923ULL),((unsigned int)1988775589ULL)};
unsigned int b_4[16]={((unsigned int)3059824246ULL),((unsigned int)662027313ULL),((unsigned int)217189136ULL),((unsigned int)1140519603ULL),((unsigned int)2385401936ULL),((unsigned int)89622323ULL),((unsigned int)2696712997ULL),((unsigned int)4286979120ULL),((unsigned int)3053590899ULL),((unsigned int)1225000130ULL),((unsigned int)4007137502ULL),((unsigned int)2909663224ULL),((unsigned int)3082152204ULL),((unsigned int)2676291900ULL),((unsigned int)2772510923ULL),((unsigned int)1988775589ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2581694279ULL),((unsigned int)3002852043ULL),((unsigned int)1054206876ULL),((unsigned int)1612529279ULL)};
unsigned int b_0[4]={((unsigned int)2581694279ULL),((unsigned int)3002852043ULL),((unsigned int)1054206876ULL),((unsigned int)1612529279ULL)};
unsigned int a_1[4]={((unsigned int)288133852ULL),((unsigned int)2815716004ULL),((unsigned int)1800004692ULL),((unsigned int)2836080652ULL)};
unsigned int b_1[4]={((unsigned int)288133852ULL),((unsigned int)2815716004ULL),((unsigned int)1800004692ULL),((unsigned int)2836080652ULL)};
unsigned int a_2[4]={((unsigned int)2811271779ULL),((unsigned int)2582362046ULL),((unsigned int)735635315ULL),((unsigned int)3751998442ULL)};
unsigned int b_2[4]={((unsigned int)2811271779ULL),((unsigned int)2582362046ULL),((unsigned int)735635315ULL),((unsigned int)3751998442ULL)};
unsigned int a_3[4]={((unsigned int)2130094008ULL),((unsigned int)1996097097ULL),((unsigned int)78970169ULL),((unsigned int)741447460ULL)};
unsigned int b_3[4]={((unsigned int)2130094008ULL),((unsigned int)1996097097ULL),((unsigned int)78970169ULL),((unsigned int)741447460ULL)};
unsigned int a_4[16]={((unsigned int)2156067147ULL),((unsigned int)2121786564ULL),((unsigned int)270212310ULL),((unsigned int)1837110107ULL),((unsigned int)3356314622ULL),((unsigned int)3971973689ULL),((unsigned int)4167647973ULL),((unsigned int)590256133ULL),((unsigned int)95934000ULL),((unsigned int)3610733263ULL),((unsigned int)1390048014ULL),((unsigned int)3418923423ULL),((unsigned int)3728293267ULL),((unsigned int)5255812ULL),((unsigned int)2923699532ULL),((unsigned int)2663547793ULL)};
unsigned int b_4[16]={((unsigned int)2156067147ULL),((unsigned int)2121786564ULL),((unsigned int)270212310ULL),((unsigned int)1837110107ULL),((unsigned int)3356314622ULL),((unsigned int)3971973689ULL),((unsigned int)4167647973ULL),((unsigned int)590256133ULL),((unsigned int)95934000ULL),((unsigned int)3610733263ULL),((unsigned int)1390048014ULL),((unsigned int)3418923423ULL),((unsigned int)3728293267ULL),((unsigned int)5255812ULL),((unsigned int)2923699532ULL),((unsigned int)2663547793ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 31\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)457387849ULL),((unsigned int)474028643ULL),((unsigned int)556257621ULL),((unsigned int)3714612888ULL)};
unsigned int b_0[4]={((unsigned int)457387849ULL),((unsigned int)474028643ULL),((unsigned int)556257621ULL),((unsigned int)3714612888ULL)};
unsigned int a_1[4]={((unsigned int)2070480204ULL),((unsigned int)1424324750ULL),((unsigned int)3385122626ULL),((unsigned int)3552762725ULL)};
unsigned int b_1[4]={((unsigned int)2070480204ULL),((unsigned int)1424324750ULL),((unsigned int)3385122626ULL),((unsigned int)3552762725ULL)};
unsigned int a_2[4]={((unsigned int)3232267571ULL),((unsigned int)2192753205ULL),((unsigned int)4122220652ULL),((unsigned int)12281372ULL)};
unsigned int b_2[4]={((unsigned int)3232267571ULL),((unsigned int)2192753205ULL),((unsigned int)4122220652ULL),((unsigned int)12281372ULL)};
unsigned int a_3[4]={((unsigned int)3513897822ULL),((unsigned int)678549066ULL),((unsigned int)922508543ULL),((unsigned int)484335801ULL)};
unsigned int b_3[4]={((unsigned int)3513897822ULL),((unsigned int)678549066ULL),((unsigned int)922508543ULL),((unsigned int)484335801ULL)};
unsigned int a_4[16]={((unsigned int)2795216909ULL),((unsigned int)2254366247ULL),((unsigned int)2395753007ULL),((unsigned int)2838373618ULL),((unsigned int)2880019588ULL),((unsigned int)824724375ULL),((unsigned int)3459177442ULL),((unsigned int)934346914ULL),((unsigned int)2201954641ULL),((unsigned int)1688223790ULL),((unsigned int)1571507189ULL),((unsigned int)521511401ULL),((unsigned int)3039609907ULL),((unsigned int)3369569133ULL),((unsigned int)2998120985ULL),((unsigned int)670758729ULL)};
unsigned int b_4[16]={((unsigned int)2795216909ULL),((unsigned int)2254366247ULL),((unsigned int)2395753007ULL),((unsigned int)2838373618ULL),((unsigned int)2880019588ULL),((unsigned int)824724375ULL),((unsigned int)3459177442ULL),((unsigned int)934346914ULL),((unsigned int)2201954641ULL),((unsigned int)1688223790ULL),((unsigned int)1571507189ULL),((unsigned int)521511401ULL),((unsigned int)3039609907ULL),((unsigned int)3369569133ULL),((unsigned int)2998120985ULL),((unsigned int)670758729ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 32\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3738313341ULL),((unsigned int)561686460ULL),((unsigned int)681981120ULL),((unsigned int)2877520346ULL)};
unsigned int b_0[4]={((unsigned int)3738313341ULL),((unsigned int)561686460ULL),((unsigned int)681981120ULL),((unsigned int)2877520346ULL)};
unsigned int a_1[4]={((unsigned int)2230328118ULL),((unsigned int)3178919469ULL),((unsigned int)4253134292ULL),((unsigned int)1674344904ULL)};
unsigned int b_1[4]={((unsigned int)2230328118ULL),((unsigned int)3178919469ULL),((unsigned int)4253134292ULL),((unsigned int)1674344904ULL)};
unsigned int a_2[4]={((unsigned int)3277251699ULL),((unsigned int)335734496ULL),((unsigned int)3524175842ULL),((unsigned int)2871450126ULL)};
unsigned int b_2[4]={((unsigned int)3277251699ULL),((unsigned int)335734496ULL),((unsigned int)3524175842ULL),((unsigned int)2871450126ULL)};
unsigned int a_3[4]={((unsigned int)1458245136ULL),((unsigned int)1451152664ULL),((unsigned int)3060219244ULL),((unsigned int)2289338141ULL)};
unsigned int b_3[4]={((unsigned int)1458245136ULL),((unsigned int)1451152664ULL),((unsigned int)3060219244ULL),((unsigned int)2289338141ULL)};
unsigned int a_4[16]={((unsigned int)4154486815ULL),((unsigned int)3419170305ULL),((unsigned int)975622942ULL),((unsigned int)402909600ULL),((unsigned int)3850299720ULL),((unsigned int)2968219541ULL),((unsigned int)1328021469ULL),((unsigned int)3294925044ULL),((unsigned int)3890466776ULL),((unsigned int)2463990608ULL),((unsigned int)3108087525ULL),((unsigned int)2085612357ULL),((unsigned int)2070550294ULL),((unsigned int)2326465940ULL),((unsigned int)328305305ULL),((unsigned int)1951301989ULL)};
unsigned int b_4[16]={((unsigned int)4154486815ULL),((unsigned int)3419170305ULL),((unsigned int)975622942ULL),((unsigned int)402909600ULL),((unsigned int)3850299720ULL),((unsigned int)2968219541ULL),((unsigned int)1328021469ULL),((unsigned int)3294925044ULL),((unsigned int)3890466776ULL),((unsigned int)2463990608ULL),((unsigned int)3108087525ULL),((unsigned int)2085612357ULL),((unsigned int)2070550294ULL),((unsigned int)2326465940ULL),((unsigned int)328305305ULL),((unsigned int)1951301989ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 33\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1167113022ULL),((unsigned int)493879993ULL),((unsigned int)4040794490ULL),((unsigned int)4046676557ULL)};
unsigned int b_0[4]={((unsigned int)1167113022ULL),((unsigned int)493879993ULL),((unsigned int)4040794490ULL),((unsigned int)4046676557ULL)};
unsigned int a_1[4]={((unsigned int)3750448803ULL),((unsigned int)3062661365ULL),((unsigned int)710014498ULL),((unsigned int)2018390069ULL)};
unsigned int b_1[4]={((unsigned int)3750448803ULL),((unsigned int)3062661365ULL),((unsigned int)710014498ULL),((unsigned int)2018390069ULL)};
unsigned int a_2[4]={((unsigned int)4261150226ULL),((unsigned int)3381170286ULL),((unsigned int)3611408037ULL),((unsigned int)3048095724ULL)};
unsigned int b_2[4]={((unsigned int)4261150226ULL),((unsigned int)3381170286ULL),((unsigned int)3611408037ULL),((unsigned int)3048095724ULL)};
unsigned int a_3[4]={((unsigned int)3186670617ULL),((unsigned int)96410629ULL),((unsigned int)4278916726ULL),((unsigned int)3671981753ULL)};
unsigned int b_3[4]={((unsigned int)3186670617ULL),((unsigned int)96410629ULL),((unsigned int)4278916726ULL),((unsigned int)3671981753ULL)};
unsigned int a_4[16]={((unsigned int)4289349087ULL),((unsigned int)2873160009ULL),((unsigned int)408319541ULL),((unsigned int)1829414333ULL),((unsigned int)2750890035ULL),((unsigned int)2088518817ULL),((unsigned int)3352094663ULL),((unsigned int)258454509ULL),((unsigned int)794176231ULL),((unsigned int)3342498967ULL),((unsigned int)2880533351ULL),((unsigned int)3629128395ULL),((unsigned int)1123463617ULL),((unsigned int)3803153197ULL),((unsigned int)4153969705ULL),((unsigned int)4057223216ULL)};
unsigned int b_4[16]={((unsigned int)4289349087ULL),((unsigned int)2873160009ULL),((unsigned int)408319541ULL),((unsigned int)1829414333ULL),((unsigned int)2750890035ULL),((unsigned int)2088518817ULL),((unsigned int)3352094663ULL),((unsigned int)258454509ULL),((unsigned int)794176231ULL),((unsigned int)3342498967ULL),((unsigned int)2880533351ULL),((unsigned int)3629128395ULL),((unsigned int)1123463617ULL),((unsigned int)3803153197ULL),((unsigned int)4153969705ULL),((unsigned int)4057223216ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 34\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2258847464ULL),((unsigned int)855029215ULL),((unsigned int)2272911481ULL),((unsigned int)1876348122ULL)};
unsigned int b_0[4]={((unsigned int)2258847464ULL),((unsigned int)855029215ULL),((unsigned int)2272911481ULL),((unsigned int)1876348122ULL)};
unsigned int a_1[4]={((unsigned int)120624921ULL),((unsigned int)3691213964ULL),((unsigned int)2258184113ULL),((unsigned int)2879926368ULL)};
unsigned int b_1[4]={((unsigned int)120624921ULL),((unsigned int)3691213964ULL),((unsigned int)2258184113ULL),((unsigned int)2879926368ULL)};
unsigned int a_2[4]={((unsigned int)4070247863ULL),((unsigned int)3066312015ULL),((unsigned int)1714777429ULL),((unsigned int)3018581337ULL)};
unsigned int b_2[4]={((unsigned int)4070247863ULL),((unsigned int)3066312015ULL),((unsigned int)1714777429ULL),((unsigned int)3018581337ULL)};
unsigned int a_3[4]={((unsigned int)4152494175ULL),((unsigned int)2404249550ULL),((unsigned int)3656055795ULL),((unsigned int)1530851365ULL)};
unsigned int b_3[4]={((unsigned int)4152494175ULL),((unsigned int)2404249550ULL),((unsigned int)3656055795ULL),((unsigned int)1530851365ULL)};
unsigned int a_4[16]={((unsigned int)1060421912ULL),((unsigned int)3307524220ULL),((unsigned int)1149725351ULL),((unsigned int)366250290ULL),((unsigned int)1367584110ULL),((unsigned int)1551486464ULL),((unsigned int)2942305050ULL),((unsigned int)1606332437ULL),((unsigned int)3410431672ULL),((unsigned int)54589810ULL),((unsigned int)3333738673ULL),((unsigned int)351207807ULL),((unsigned int)1945449650ULL),((unsigned int)340359286ULL),((unsigned int)240055967ULL),((unsigned int)1490060720ULL)};
unsigned int b_4[16]={((unsigned int)1060421912ULL),((unsigned int)3307524220ULL),((unsigned int)1149725351ULL),((unsigned int)366250290ULL),((unsigned int)1367584110ULL),((unsigned int)1551486464ULL),((unsigned int)2942305050ULL),((unsigned int)1606332437ULL),((unsigned int)3410431672ULL),((unsigned int)54589810ULL),((unsigned int)3333738673ULL),((unsigned int)351207807ULL),((unsigned int)1945449650ULL),((unsigned int)340359286ULL),((unsigned int)240055967ULL),((unsigned int)1490060720ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 35\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3847925333ULL),((unsigned int)3934247315ULL),((unsigned int)392644939ULL),((unsigned int)2192402321ULL)};
unsigned int b_0[4]={((unsigned int)3847925333ULL),((unsigned int)3934247315ULL),((unsigned int)392644939ULL),((unsigned int)2192402321ULL)};
unsigned int a_1[4]={((unsigned int)2460493778ULL),((unsigned int)397245307ULL),((unsigned int)847446790ULL),((unsigned int)2769009677ULL)};
unsigned int b_1[4]={((unsigned int)2460493778ULL),((unsigned int)397245307ULL),((unsigned int)847446790ULL),((unsigned int)2769009677ULL)};
unsigned int a_2[4]={((unsigned int)3308538702ULL),((unsigned int)3667837158ULL),((unsigned int)3461026760ULL),((unsigned int)366742046ULL)};
unsigned int b_2[4]={((unsigned int)3308538702ULL),((unsigned int)3667837158ULL),((unsigned int)3461026760ULL),((unsigned int)366742046ULL)};
unsigned int a_3[4]={((unsigned int)2305726600ULL),((unsigned int)2894083694ULL),((unsigned int)3224625039ULL),((unsigned int)3436060637ULL)};
unsigned int b_3[4]={((unsigned int)2305726600ULL),((unsigned int)2894083694ULL),((unsigned int)3224625039ULL),((unsigned int)3436060637ULL)};
unsigned int a_4[16]={((unsigned int)832727763ULL),((unsigned int)3626967701ULL),((unsigned int)235474156ULL),((unsigned int)3896508341ULL),((unsigned int)2550956444ULL),((unsigned int)4143514026ULL),((unsigned int)41833238ULL),((unsigned int)1593161792ULL),((unsigned int)914185356ULL),((unsigned int)2279183235ULL),((unsigned int)999577002ULL),((unsigned int)2181200885ULL),((unsigned int)4236681543ULL),((unsigned int)1863416069ULL),((unsigned int)628956208ULL),((unsigned int)3822375829ULL)};
unsigned int b_4[16]={((unsigned int)832727763ULL),((unsigned int)3626967701ULL),((unsigned int)235474156ULL),((unsigned int)3896508341ULL),((unsigned int)2550956444ULL),((unsigned int)4143514026ULL),((unsigned int)41833238ULL),((unsigned int)1593161792ULL),((unsigned int)914185356ULL),((unsigned int)2279183235ULL),((unsigned int)999577002ULL),((unsigned int)2181200885ULL),((unsigned int)4236681543ULL),((unsigned int)1863416069ULL),((unsigned int)628956208ULL),((unsigned int)3822375829ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 36\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)407068708ULL),((unsigned int)1609304807ULL),((unsigned int)3549805797ULL),((unsigned int)2090621035ULL)};
unsigned int b_0[4]={((unsigned int)407068708ULL),((unsigned int)1609304807ULL),((unsigned int)3549805797ULL),((unsigned int)2090621035ULL)};
unsigned int a_1[4]={((unsigned int)2390953326ULL),((unsigned int)1219837758ULL),((unsigned int)3229392008ULL),((unsigned int)527706071ULL)};
unsigned int b_1[4]={((unsigned int)2390953326ULL),((unsigned int)1219837758ULL),((unsigned int)3229392008ULL),((unsigned int)527706071ULL)};
unsigned int a_2[4]={((unsigned int)2189626202ULL),((unsigned int)1437794479ULL),((unsigned int)236551883ULL),((unsigned int)2952875015ULL)};
unsigned int b_2[4]={((unsigned int)2189626202ULL),((unsigned int)1437794479ULL),((unsigned int)236551883ULL),((unsigned int)2952875015ULL)};
unsigned int a_3[4]={((unsigned int)458694500ULL),((unsigned int)526507612ULL),((unsigned int)1330979239ULL),((unsigned int)2613734232ULL)};
unsigned int b_3[4]={((unsigned int)458694500ULL),((unsigned int)526507612ULL),((unsigned int)1330979239ULL),((unsigned int)2613734232ULL)};
unsigned int a_4[16]={((unsigned int)2371902379ULL),((unsigned int)3338104302ULL),((unsigned int)2690478051ULL),((unsigned int)194984959ULL),((unsigned int)3352102809ULL),((unsigned int)246734990ULL),((unsigned int)3859305978ULL),((unsigned int)2829336399ULL),((unsigned int)1878712113ULL),((unsigned int)898863036ULL),((unsigned int)2538183966ULL),((unsigned int)1468271826ULL),((unsigned int)3191603478ULL),((unsigned int)1692494855ULL),((unsigned int)1290992474ULL),((unsigned int)3256502752ULL)};
unsigned int b_4[16]={((unsigned int)2371902379ULL),((unsigned int)3338104302ULL),((unsigned int)2690478051ULL),((unsigned int)194984959ULL),((unsigned int)3352102809ULL),((unsigned int)246734990ULL),((unsigned int)3859305978ULL),((unsigned int)2829336399ULL),((unsigned int)1878712113ULL),((unsigned int)898863036ULL),((unsigned int)2538183966ULL),((unsigned int)1468271826ULL),((unsigned int)3191603478ULL),((unsigned int)1692494855ULL),((unsigned int)1290992474ULL),((unsigned int)3256502752ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 37\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)851478206ULL),((unsigned int)2322526145ULL),((unsigned int)1721503810ULL),((unsigned int)833055392ULL)};
unsigned int b_0[4]={((unsigned int)851478206ULL),((unsigned int)2322526145ULL),((unsigned int)1721503810ULL),((unsigned int)833055392ULL)};
unsigned int a_1[4]={((unsigned int)1990416552ULL),((unsigned int)4120670631ULL),((unsigned int)3312035210ULL),((unsigned int)3479288648ULL)};
unsigned int b_1[4]={((unsigned int)1990416552ULL),((unsigned int)4120670631ULL),((unsigned int)3312035210ULL),((unsigned int)3479288648ULL)};
unsigned int a_2[4]={((unsigned int)3979996749ULL),((unsigned int)1108944211ULL),((unsigned int)3858175619ULL),((unsigned int)3914415977ULL)};
unsigned int b_2[4]={((unsigned int)3979996749ULL),((unsigned int)1108944211ULL),((unsigned int)3858175619ULL),((unsigned int)3914415977ULL)};
unsigned int a_3[4]={((unsigned int)1783943379ULL),((unsigned int)609602080ULL),((unsigned int)3146202534ULL),((unsigned int)4222541685ULL)};
unsigned int b_3[4]={((unsigned int)1783943379ULL),((unsigned int)609602080ULL),((unsigned int)3146202534ULL),((unsigned int)4222541685ULL)};
unsigned int a_4[16]={((unsigned int)912156361ULL),((unsigned int)1418258738ULL),((unsigned int)2999658945ULL),((unsigned int)3380003524ULL),((unsigned int)2785153434ULL),((unsigned int)1911948056ULL),((unsigned int)755376845ULL),((unsigned int)3249716138ULL),((unsigned int)363876059ULL),((unsigned int)3012219603ULL),((unsigned int)3664028485ULL),((unsigned int)195736938ULL),((unsigned int)3299311424ULL),((unsigned int)3372156121ULL),((unsigned int)2947507154ULL),((unsigned int)2263685190ULL)};
unsigned int b_4[16]={((unsigned int)912156361ULL),((unsigned int)1418258738ULL),((unsigned int)2999658945ULL),((unsigned int)3380003524ULL),((unsigned int)2785153434ULL),((unsigned int)1911948056ULL),((unsigned int)755376845ULL),((unsigned int)3249716138ULL),((unsigned int)363876059ULL),((unsigned int)3012219603ULL),((unsigned int)3664028485ULL),((unsigned int)195736938ULL),((unsigned int)3299311424ULL),((unsigned int)3372156121ULL),((unsigned int)2947507154ULL),((unsigned int)2263685190ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 38\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1167204593ULL),((unsigned int)4215571817ULL),((unsigned int)303086072ULL),((unsigned int)3075252337ULL)};
unsigned int b_0[4]={((unsigned int)1167204593ULL),((unsigned int)4215571817ULL),((unsigned int)303086072ULL),((unsigned int)3075252337ULL)};
unsigned int a_1[4]={((unsigned int)730107201ULL),((unsigned int)618911144ULL),((unsigned int)1387699514ULL),((unsigned int)171672644ULL)};
unsigned int b_1[4]={((unsigned int)730107201ULL),((unsigned int)618911144ULL),((unsigned int)1387699514ULL),((unsigned int)171672644ULL)};
unsigned int a_2[4]={((unsigned int)1218171443ULL),((unsigned int)869710159ULL),((unsigned int)2269610681ULL),((unsigned int)2274853657ULL)};
unsigned int b_2[4]={((unsigned int)1218171443ULL),((unsigned int)869710159ULL),((unsigned int)2269610681ULL),((unsigned int)2274853657ULL)};
unsigned int a_3[4]={((unsigned int)3699749616ULL),((unsigned int)685367575ULL),((unsigned int)4287025595ULL),((unsigned int)3520388815ULL)};
unsigned int b_3[4]={((unsigned int)3699749616ULL),((unsigned int)685367575ULL),((unsigned int)4287025595ULL),((unsigned int)3520388815ULL)};
unsigned int a_4[16]={((unsigned int)2573442906ULL),((unsigned int)4243340687ULL),((unsigned int)2178167393ULL),((unsigned int)3960903600ULL),((unsigned int)2637354585ULL),((unsigned int)1795676996ULL),((unsigned int)4013096538ULL),((unsigned int)930877197ULL),((unsigned int)780849466ULL),((unsigned int)1358606515ULL),((unsigned int)243299630ULL),((unsigned int)427186030ULL),((unsigned int)984314473ULL),((unsigned int)1490812942ULL),((unsigned int)221076262ULL),((unsigned int)735860097ULL)};
unsigned int b_4[16]={((unsigned int)2573442906ULL),((unsigned int)4243340687ULL),((unsigned int)2178167393ULL),((unsigned int)3960903600ULL),((unsigned int)2637354585ULL),((unsigned int)1795676996ULL),((unsigned int)4013096538ULL),((unsigned int)930877197ULL),((unsigned int)780849466ULL),((unsigned int)1358606515ULL),((unsigned int)243299630ULL),((unsigned int)427186030ULL),((unsigned int)984314473ULL),((unsigned int)1490812942ULL),((unsigned int)221076262ULL),((unsigned int)735860097ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 39\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)865486921ULL),((unsigned int)29922233ULL),((unsigned int)3833081296ULL),((unsigned int)2910710145ULL)};
unsigned int b_0[4]={((unsigned int)865486921ULL),((unsigned int)29922233ULL),((unsigned int)3833081296ULL),((unsigned int)2910710145ULL)};
unsigned int a_1[4]={((unsigned int)766788876ULL),((unsigned int)284597191ULL),((unsigned int)3761769795ULL),((unsigned int)253852893ULL)};
unsigned int b_1[4]={((unsigned int)766788876ULL),((unsigned int)284597191ULL),((unsigned int)3761769795ULL),((unsigned int)253852893ULL)};
unsigned int a_2[4]={((unsigned int)222400979ULL),((unsigned int)924212678ULL),((unsigned int)4181790091ULL),((unsigned int)3677827934ULL)};
unsigned int b_2[4]={((unsigned int)222400979ULL),((unsigned int)924212678ULL),((unsigned int)4181790091ULL),((unsigned int)3677827934ULL)};
unsigned int a_3[4]={((unsigned int)3955464577ULL),((unsigned int)2572965966ULL),((unsigned int)690451488ULL),((unsigned int)39151321ULL)};
unsigned int b_3[4]={((unsigned int)3955464577ULL),((unsigned int)2572965966ULL),((unsigned int)690451488ULL),((unsigned int)39151321ULL)};
unsigned int a_4[16]={((unsigned int)3653028490ULL),((unsigned int)2500047480ULL),((unsigned int)1114781713ULL),((unsigned int)1318686691ULL),((unsigned int)3886099741ULL),((unsigned int)1227050144ULL),((unsigned int)3217632318ULL),((unsigned int)1486579444ULL),((unsigned int)2708963747ULL),((unsigned int)1330806835ULL),((unsigned int)2895297602ULL),((unsigned int)2913366698ULL),((unsigned int)1290812764ULL),((unsigned int)2595108982ULL),((unsigned int)2574240872ULL),((unsigned int)801460226ULL)};
unsigned int b_4[16]={((unsigned int)3653028490ULL),((unsigned int)2500047480ULL),((unsigned int)1114781713ULL),((unsigned int)1318686691ULL),((unsigned int)3886099741ULL),((unsigned int)1227050144ULL),((unsigned int)3217632318ULL),((unsigned int)1486579444ULL),((unsigned int)2708963747ULL),((unsigned int)1330806835ULL),((unsigned int)2895297602ULL),((unsigned int)2913366698ULL),((unsigned int)1290812764ULL),((unsigned int)2595108982ULL),((unsigned int)2574240872ULL),((unsigned int)801460226ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 40\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3530690ULL),((unsigned int)3611555133ULL),((unsigned int)2200125310ULL),((unsigned int)1447490576ULL)};
unsigned int b_0[4]={((unsigned int)3530690ULL),((unsigned int)3611555133ULL),((unsigned int)2200125310ULL),((unsigned int)1447490576ULL)};
unsigned int a_1[4]={((unsigned int)214001180ULL),((unsigned int)305716812ULL),((unsigned int)3162105922ULL),((unsigned int)931584499ULL)};
unsigned int b_1[4]={((unsigned int)214001180ULL),((unsigned int)305716812ULL),((unsigned int)3162105922ULL),((unsigned int)931584499ULL)};
unsigned int a_2[4]={((unsigned int)1059784777ULL),((unsigned int)2922152820ULL),((unsigned int)1542762729ULL),((unsigned int)972995120ULL)};
unsigned int b_2[4]={((unsigned int)1059784777ULL),((unsigned int)2922152820ULL),((unsigned int)1542762729ULL),((unsigned int)972995120ULL)};
unsigned int a_3[4]={((unsigned int)3181383546ULL),((unsigned int)2776740719ULL),((unsigned int)4261252149ULL),((unsigned int)991883210ULL)};
unsigned int b_3[4]={((unsigned int)3181383546ULL),((unsigned int)2776740719ULL),((unsigned int)4261252149ULL),((unsigned int)991883210ULL)};
unsigned int a_4[16]={((unsigned int)3620829572ULL),((unsigned int)73120191ULL),((unsigned int)4112065693ULL),((unsigned int)3901578557ULL),((unsigned int)2000843679ULL),((unsigned int)2799467761ULL),((unsigned int)3451133268ULL),((unsigned int)1511611454ULL),((unsigned int)604724140ULL),((unsigned int)2460605257ULL),((unsigned int)2793971318ULL),((unsigned int)3587625751ULL),((unsigned int)508774117ULL),((unsigned int)907915861ULL),((unsigned int)2223468806ULL),((unsigned int)4266526096ULL)};
unsigned int b_4[16]={((unsigned int)3620829572ULL),((unsigned int)73120191ULL),((unsigned int)4112065693ULL),((unsigned int)3901578557ULL),((unsigned int)2000843679ULL),((unsigned int)2799467761ULL),((unsigned int)3451133268ULL),((unsigned int)1511611454ULL),((unsigned int)604724140ULL),((unsigned int)2460605257ULL),((unsigned int)2793971318ULL),((unsigned int)3587625751ULL),((unsigned int)508774117ULL),((unsigned int)907915861ULL),((unsigned int)2223468806ULL),((unsigned int)4266526096ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 41\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3125579201ULL),((unsigned int)2613248651ULL),((unsigned int)2622708054ULL),((unsigned int)3022551876ULL)};
unsigned int b_0[4]={((unsigned int)3125579201ULL),((unsigned int)2613248651ULL),((unsigned int)2622708054ULL),((unsigned int)3022551876ULL)};
unsigned int a_1[4]={((unsigned int)2198492700ULL),((unsigned int)1015176769ULL),((unsigned int)4203421752ULL),((unsigned int)4101322740ULL)};
unsigned int b_1[4]={((unsigned int)2198492700ULL),((unsigned int)1015176769ULL),((unsigned int)4203421752ULL),((unsigned int)4101322740ULL)};
unsigned int a_2[4]={((unsigned int)1577492747ULL),((unsigned int)3576089386ULL),((unsigned int)2890567736ULL),((unsigned int)3297813696ULL)};
unsigned int b_2[4]={((unsigned int)1577492747ULL),((unsigned int)3576089386ULL),((unsigned int)2890567736ULL),((unsigned int)3297813696ULL)};
unsigned int a_3[4]={((unsigned int)3812956830ULL),((unsigned int)3434381461ULL),((unsigned int)3887544873ULL),((unsigned int)448993712ULL)};
unsigned int b_3[4]={((unsigned int)3812956830ULL),((unsigned int)3434381461ULL),((unsigned int)3887544873ULL),((unsigned int)448993712ULL)};
unsigned int a_4[16]={((unsigned int)2449915827ULL),((unsigned int)1626367552ULL),((unsigned int)3779627296ULL),((unsigned int)1851418452ULL),((unsigned int)857078159ULL),((unsigned int)1899361319ULL),((unsigned int)1392366582ULL),((unsigned int)2417425203ULL),((unsigned int)1222373968ULL),((unsigned int)3547549472ULL),((unsigned int)4082058886ULL),((unsigned int)2549761587ULL),((unsigned int)2530372542ULL),((unsigned int)2660475811ULL),((unsigned int)3830732059ULL),((unsigned int)3575439491ULL)};
unsigned int b_4[16]={((unsigned int)2449915827ULL),((unsigned int)1626367552ULL),((unsigned int)3779627296ULL),((unsigned int)1851418452ULL),((unsigned int)857078159ULL),((unsigned int)1899361319ULL),((unsigned int)1392366582ULL),((unsigned int)2417425203ULL),((unsigned int)1222373968ULL),((unsigned int)3547549472ULL),((unsigned int)4082058886ULL),((unsigned int)2549761587ULL),((unsigned int)2530372542ULL),((unsigned int)2660475811ULL),((unsigned int)3830732059ULL),((unsigned int)3575439491ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 42\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)91379122ULL),((unsigned int)1543790755ULL),((unsigned int)2776362951ULL),((unsigned int)2841680355ULL)};
unsigned int b_0[4]={((unsigned int)91379122ULL),((unsigned int)1543790755ULL),((unsigned int)2776362951ULL),((unsigned int)2841680355ULL)};
unsigned int a_1[4]={((unsigned int)1834417554ULL),((unsigned int)675888632ULL),((unsigned int)1353726654ULL),((unsigned int)1946537808ULL)};
unsigned int b_1[4]={((unsigned int)1834417554ULL),((unsigned int)675888632ULL),((unsigned int)1353726654ULL),((unsigned int)1946537808ULL)};
unsigned int a_2[4]={((unsigned int)3617541125ULL),((unsigned int)1810652517ULL),((unsigned int)2680481989ULL),((unsigned int)4055012629ULL)};
unsigned int b_2[4]={((unsigned int)3617541125ULL),((unsigned int)1810652517ULL),((unsigned int)2680481989ULL),((unsigned int)4055012629ULL)};
unsigned int a_3[4]={((unsigned int)923314873ULL),((unsigned int)3375062507ULL),((unsigned int)3873035515ULL),((unsigned int)2183311676ULL)};
unsigned int b_3[4]={((unsigned int)923314873ULL),((unsigned int)3375062507ULL),((unsigned int)3873035515ULL),((unsigned int)2183311676ULL)};
unsigned int a_4[16]={((unsigned int)2372343744ULL),((unsigned int)1371622083ULL),((unsigned int)2444367397ULL),((unsigned int)2191319658ULL),((unsigned int)1823414112ULL),((unsigned int)3977547791ULL),((unsigned int)1634305663ULL),((unsigned int)1743392752ULL),((unsigned int)543129956ULL),((unsigned int)3434243977ULL),((unsigned int)3753034036ULL),((unsigned int)3912228757ULL),((unsigned int)4279223015ULL),((unsigned int)3282875495ULL),((unsigned int)2648039423ULL),((unsigned int)4005828782ULL)};
unsigned int b_4[16]={((unsigned int)2372343744ULL),((unsigned int)1371622083ULL),((unsigned int)2444367397ULL),((unsigned int)2191319658ULL),((unsigned int)1823414112ULL),((unsigned int)3977547791ULL),((unsigned int)1634305663ULL),((unsigned int)1743392752ULL),((unsigned int)543129956ULL),((unsigned int)3434243977ULL),((unsigned int)3753034036ULL),((unsigned int)3912228757ULL),((unsigned int)4279223015ULL),((unsigned int)3282875495ULL),((unsigned int)2648039423ULL),((unsigned int)4005828782ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 43\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)653746871ULL),((unsigned int)323354821ULL),((unsigned int)4217115391ULL),((unsigned int)370686315ULL)};
unsigned int b_0[4]={((unsigned int)653746871ULL),((unsigned int)323354821ULL),((unsigned int)4217115391ULL),((unsigned int)370686315ULL)};
unsigned int a_1[4]={((unsigned int)659495576ULL),((unsigned int)636039939ULL),((unsigned int)2189701272ULL),((unsigned int)1371764491ULL)};
unsigned int b_1[4]={((unsigned int)659495576ULL),((unsigned int)636039939ULL),((unsigned int)2189701272ULL),((unsigned int)1371764491ULL)};
unsigned int a_2[4]={((unsigned int)2956657978ULL),((unsigned int)691764211ULL),((unsigned int)2404029058ULL),((unsigned int)4100086182ULL)};
unsigned int b_2[4]={((unsigned int)2956657978ULL),((unsigned int)691764211ULL),((unsigned int)2404029058ULL),((unsigned int)4100086182ULL)};
unsigned int a_3[4]={((unsigned int)2290636847ULL),((unsigned int)1490683320ULL),((unsigned int)2379615129ULL),((unsigned int)4223524591ULL)};
unsigned int b_3[4]={((unsigned int)2290636847ULL),((unsigned int)1490683320ULL),((unsigned int)2379615129ULL),((unsigned int)4223524591ULL)};
unsigned int a_4[16]={((unsigned int)604045779ULL),((unsigned int)3964808971ULL),((unsigned int)886504205ULL),((unsigned int)3711154551ULL),((unsigned int)3975047420ULL),((unsigned int)523289575ULL),((unsigned int)312392477ULL),((unsigned int)4151088289ULL),((unsigned int)1808301025ULL),((unsigned int)3683875041ULL),((unsigned int)2683814105ULL),((unsigned int)1396948582ULL),((unsigned int)4259738767ULL),((unsigned int)4247614707ULL),((unsigned int)2797705882ULL),((unsigned int)1706370956ULL)};
unsigned int b_4[16]={((unsigned int)604045779ULL),((unsigned int)3964808971ULL),((unsigned int)886504205ULL),((unsigned int)3711154551ULL),((unsigned int)3975047420ULL),((unsigned int)523289575ULL),((unsigned int)312392477ULL),((unsigned int)4151088289ULL),((unsigned int)1808301025ULL),((unsigned int)3683875041ULL),((unsigned int)2683814105ULL),((unsigned int)1396948582ULL),((unsigned int)4259738767ULL),((unsigned int)4247614707ULL),((unsigned int)2797705882ULL),((unsigned int)1706370956ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 44\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2334356056ULL),((unsigned int)1063238540ULL),((unsigned int)3879490881ULL),((unsigned int)3742562818ULL)};
unsigned int b_0[4]={((unsigned int)2334356056ULL),((unsigned int)1063238540ULL),((unsigned int)3879490881ULL),((unsigned int)3742562818ULL)};
unsigned int a_1[4]={((unsigned int)111492916ULL),((unsigned int)2833492309ULL),((unsigned int)1379370882ULL),((unsigned int)1269363128ULL)};
unsigned int b_1[4]={((unsigned int)111492916ULL),((unsigned int)2833492309ULL),((unsigned int)1379370882ULL),((unsigned int)1269363128ULL)};
unsigned int a_2[4]={((unsigned int)2709673104ULL),((unsigned int)1633612905ULL),((unsigned int)1762994769ULL),((unsigned int)162122543ULL)};
unsigned int b_2[4]={((unsigned int)2709673104ULL),((unsigned int)1633612905ULL),((unsigned int)1762994769ULL),((unsigned int)162122543ULL)};
unsigned int a_3[4]={((unsigned int)842924949ULL),((unsigned int)1674752405ULL),((unsigned int)1605711882ULL),((unsigned int)2417748563ULL)};
unsigned int b_3[4]={((unsigned int)842924949ULL),((unsigned int)1674752405ULL),((unsigned int)1605711882ULL),((unsigned int)2417748563ULL)};
unsigned int a_4[16]={((unsigned int)2566289681ULL),((unsigned int)349777106ULL),((unsigned int)1049416677ULL),((unsigned int)741394052ULL),((unsigned int)1164028917ULL),((unsigned int)4181867322ULL),((unsigned int)2548889383ULL),((unsigned int)3277067064ULL),((unsigned int)3711853436ULL),((unsigned int)2714737523ULL),((unsigned int)2168641326ULL),((unsigned int)3318631803ULL),((unsigned int)1585552111ULL),((unsigned int)3178976469ULL),((unsigned int)2495231449ULL),((unsigned int)3694750745ULL)};
unsigned int b_4[16]={((unsigned int)2566289681ULL),((unsigned int)349777106ULL),((unsigned int)1049416677ULL),((unsigned int)741394052ULL),((unsigned int)1164028917ULL),((unsigned int)4181867322ULL),((unsigned int)2548889383ULL),((unsigned int)3277067064ULL),((unsigned int)3711853436ULL),((unsigned int)2714737523ULL),((unsigned int)2168641326ULL),((unsigned int)3318631803ULL),((unsigned int)1585552111ULL),((unsigned int)3178976469ULL),((unsigned int)2495231449ULL),((unsigned int)3694750745ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 45\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1419036557ULL),((unsigned int)3177818146ULL),((unsigned int)3529257751ULL),((unsigned int)3503138923ULL)};
unsigned int b_0[4]={((unsigned int)1419036557ULL),((unsigned int)3177818146ULL),((unsigned int)3529257751ULL),((unsigned int)3503138923ULL)};
unsigned int a_1[4]={((unsigned int)3023819926ULL),((unsigned int)4245805739ULL),((unsigned int)2807401117ULL),((unsigned int)2524905664ULL)};
unsigned int b_1[4]={((unsigned int)3023819926ULL),((unsigned int)4245805739ULL),((unsigned int)2807401117ULL),((unsigned int)2524905664ULL)};
unsigned int a_2[4]={((unsigned int)573701151ULL),((unsigned int)1041158994ULL),((unsigned int)3094584878ULL),((unsigned int)2332296740ULL)};
unsigned int b_2[4]={((unsigned int)573701151ULL),((unsigned int)1041158994ULL),((unsigned int)3094584878ULL),((unsigned int)2332296740ULL)};
unsigned int a_3[4]={((unsigned int)1159970563ULL),((unsigned int)3305095198ULL),((unsigned int)1012876530ULL),((unsigned int)3494244960ULL)};
unsigned int b_3[4]={((unsigned int)1159970563ULL),((unsigned int)3305095198ULL),((unsigned int)1012876530ULL),((unsigned int)3494244960ULL)};
unsigned int a_4[16]={((unsigned int)191200876ULL),((unsigned int)1486133201ULL),((unsigned int)957887597ULL),((unsigned int)3652277140ULL),((unsigned int)487077956ULL),((unsigned int)2021636507ULL),((unsigned int)3387216242ULL),((unsigned int)3258563693ULL),((unsigned int)1453607743ULL),((unsigned int)3459831515ULL),((unsigned int)794287451ULL),((unsigned int)3715899971ULL),((unsigned int)4235898428ULL),((unsigned int)2417339132ULL),((unsigned int)35181221ULL),((unsigned int)136634271ULL)};
unsigned int b_4[16]={((unsigned int)191200876ULL),((unsigned int)1486133201ULL),((unsigned int)957887597ULL),((unsigned int)3652277140ULL),((unsigned int)487077956ULL),((unsigned int)2021636507ULL),((unsigned int)3387216242ULL),((unsigned int)3258563693ULL),((unsigned int)1453607743ULL),((unsigned int)3459831515ULL),((unsigned int)794287451ULL),((unsigned int)3715899971ULL),((unsigned int)4235898428ULL),((unsigned int)2417339132ULL),((unsigned int)35181221ULL),((unsigned int)136634271ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 46\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2571630094ULL),((unsigned int)3052840541ULL),((unsigned int)1123517425ULL),((unsigned int)3016804289ULL)};
unsigned int b_0[4]={((unsigned int)2571630094ULL),((unsigned int)3052840541ULL),((unsigned int)1123517425ULL),((unsigned int)3016804289ULL)};
unsigned int a_1[4]={((unsigned int)3137683677ULL),((unsigned int)1790747352ULL),((unsigned int)2643231081ULL),((unsigned int)52035434ULL)};
unsigned int b_1[4]={((unsigned int)3137683677ULL),((unsigned int)1790747352ULL),((unsigned int)2643231081ULL),((unsigned int)52035434ULL)};
unsigned int a_2[4]={((unsigned int)2138711887ULL),((unsigned int)970160781ULL),((unsigned int)3204394935ULL),((unsigned int)3638813084ULL)};
unsigned int b_2[4]={((unsigned int)2138711887ULL),((unsigned int)970160781ULL),((unsigned int)3204394935ULL),((unsigned int)3638813084ULL)};
unsigned int a_3[4]={((unsigned int)3799497996ULL),((unsigned int)54570470ULL),((unsigned int)2671441960ULL),((unsigned int)3526835783ULL)};
unsigned int b_3[4]={((unsigned int)3799497996ULL),((unsigned int)54570470ULL),((unsigned int)2671441960ULL),((unsigned int)3526835783ULL)};
unsigned int a_4[16]={((unsigned int)1466375385ULL),((unsigned int)3188332239ULL),((unsigned int)2809723979ULL),((unsigned int)2853787797ULL),((unsigned int)1707543584ULL),((unsigned int)2809888019ULL),((unsigned int)894025938ULL),((unsigned int)4016214538ULL),((unsigned int)2172578655ULL),((unsigned int)2459235721ULL),((unsigned int)2482635657ULL),((unsigned int)4086203533ULL),((unsigned int)4102310176ULL),((unsigned int)32556976ULL),((unsigned int)222328366ULL),((unsigned int)1868822234ULL)};
unsigned int b_4[16]={((unsigned int)1466375385ULL),((unsigned int)3188332239ULL),((unsigned int)2809723979ULL),((unsigned int)2853787797ULL),((unsigned int)1707543584ULL),((unsigned int)2809888019ULL),((unsigned int)894025938ULL),((unsigned int)4016214538ULL),((unsigned int)2172578655ULL),((unsigned int)2459235721ULL),((unsigned int)2482635657ULL),((unsigned int)4086203533ULL),((unsigned int)4102310176ULL),((unsigned int)32556976ULL),((unsigned int)222328366ULL),((unsigned int)1868822234ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 47\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3904642397ULL),((unsigned int)2395760630ULL),((unsigned int)3343945864ULL),((unsigned int)3240675053ULL)};
unsigned int b_0[4]={((unsigned int)3904642397ULL),((unsigned int)2395760630ULL),((unsigned int)3343945864ULL),((unsigned int)3240675053ULL)};
unsigned int a_1[4]={((unsigned int)707484740ULL),((unsigned int)3387715375ULL),((unsigned int)4261913980ULL),((unsigned int)4143383253ULL)};
unsigned int b_1[4]={((unsigned int)707484740ULL),((unsigned int)3387715375ULL),((unsigned int)4261913980ULL),((unsigned int)4143383253ULL)};
unsigned int a_2[4]={((unsigned int)1956294484ULL),((unsigned int)891278751ULL),((unsigned int)3393343501ULL),((unsigned int)3631103234ULL)};
unsigned int b_2[4]={((unsigned int)1956294484ULL),((unsigned int)891278751ULL),((unsigned int)3393343501ULL),((unsigned int)3631103234ULL)};
unsigned int a_3[4]={((unsigned int)3544817562ULL),((unsigned int)2838266494ULL),((unsigned int)783546581ULL),((unsigned int)1693411344ULL)};
unsigned int b_3[4]={((unsigned int)3544817562ULL),((unsigned int)2838266494ULL),((unsigned int)783546581ULL),((unsigned int)1693411344ULL)};
unsigned int a_4[16]={((unsigned int)557402186ULL),((unsigned int)2485117676ULL),((unsigned int)1813852251ULL),((unsigned int)751718286ULL),((unsigned int)2339399878ULL),((unsigned int)1906997050ULL),((unsigned int)1271488819ULL),((unsigned int)1420161480ULL),((unsigned int)3184618460ULL),((unsigned int)3896058334ULL),((unsigned int)3087200997ULL),((unsigned int)3003991956ULL),((unsigned int)1618936940ULL),((unsigned int)1273516218ULL),((unsigned int)4098237578ULL),((unsigned int)2182263697ULL)};
unsigned int b_4[16]={((unsigned int)557402186ULL),((unsigned int)2485117676ULL),((unsigned int)1813852251ULL),((unsigned int)751718286ULL),((unsigned int)2339399878ULL),((unsigned int)1906997050ULL),((unsigned int)1271488819ULL),((unsigned int)1420161480ULL),((unsigned int)3184618460ULL),((unsigned int)3896058334ULL),((unsigned int)3087200997ULL),((unsigned int)3003991956ULL),((unsigned int)1618936940ULL),((unsigned int)1273516218ULL),((unsigned int)4098237578ULL),((unsigned int)2182263697ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 48\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2071342207ULL),((unsigned int)4092499544ULL),((unsigned int)782582374ULL),((unsigned int)2563926418ULL)};
unsigned int b_0[4]={((unsigned int)2071342207ULL),((unsigned int)4092499544ULL),((unsigned int)782582374ULL),((unsigned int)2563926418ULL)};
unsigned int a_1[4]={((unsigned int)3490839142ULL),((unsigned int)4071562328ULL),((unsigned int)1605674668ULL),((unsigned int)3563319457ULL)};
unsigned int b_1[4]={((unsigned int)3490839142ULL),((unsigned int)4071562328ULL),((unsigned int)1605674668ULL),((unsigned int)3563319457ULL)};
unsigned int a_2[4]={((unsigned int)3405007157ULL),((unsigned int)897348687ULL),((unsigned int)1269955090ULL),((unsigned int)3814843243ULL)};
unsigned int b_2[4]={((unsigned int)3405007157ULL),((unsigned int)897348687ULL),((unsigned int)1269955090ULL),((unsigned int)3814843243ULL)};
unsigned int a_3[4]={((unsigned int)1471855349ULL),((unsigned int)273172346ULL),((unsigned int)4286235857ULL),((unsigned int)1429206332ULL)};
unsigned int b_3[4]={((unsigned int)1471855349ULL),((unsigned int)273172346ULL),((unsigned int)4286235857ULL),((unsigned int)1429206332ULL)};
unsigned int a_4[16]={((unsigned int)2964623027ULL),((unsigned int)799902576ULL),((unsigned int)1138201196ULL),((unsigned int)227036567ULL),((unsigned int)3371970636ULL),((unsigned int)3144483596ULL),((unsigned int)4250451766ULL),((unsigned int)408798128ULL),((unsigned int)238453128ULL),((unsigned int)977886909ULL),((unsigned int)1250069016ULL),((unsigned int)3800471054ULL),((unsigned int)4112132840ULL),((unsigned int)1384655132ULL),((unsigned int)4257841151ULL),((unsigned int)3580785403ULL)};
unsigned int b_4[16]={((unsigned int)2964623027ULL),((unsigned int)799902576ULL),((unsigned int)1138201196ULL),((unsigned int)227036567ULL),((unsigned int)3371970636ULL),((unsigned int)3144483596ULL),((unsigned int)4250451766ULL),((unsigned int)408798128ULL),((unsigned int)238453128ULL),((unsigned int)977886909ULL),((unsigned int)1250069016ULL),((unsigned int)3800471054ULL),((unsigned int)4112132840ULL),((unsigned int)1384655132ULL),((unsigned int)4257841151ULL),((unsigned int)3580785403ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 49\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)391082848ULL),((unsigned int)2009229008ULL),((unsigned int)2066671922ULL),((unsigned int)2128109286ULL)};
unsigned int b_0[4]={((unsigned int)391082848ULL),((unsigned int)2009229008ULL),((unsigned int)2066671922ULL),((unsigned int)2128109286ULL)};
unsigned int a_1[4]={((unsigned int)177641870ULL),((unsigned int)268910916ULL),((unsigned int)1817001881ULL),((unsigned int)561783855ULL)};
unsigned int b_1[4]={((unsigned int)177641870ULL),((unsigned int)268910916ULL),((unsigned int)1817001881ULL),((unsigned int)561783855ULL)};
unsigned int a_2[4]={((unsigned int)1175019818ULL),((unsigned int)2999890141ULL),((unsigned int)1631136493ULL),((unsigned int)3676518142ULL)};
unsigned int b_2[4]={((unsigned int)1175019818ULL),((unsigned int)2999890141ULL),((unsigned int)1631136493ULL),((unsigned int)3676518142ULL)};
unsigned int a_3[4]={((unsigned int)2422377130ULL),((unsigned int)3191213415ULL),((unsigned int)2925816935ULL),((unsigned int)4115941915ULL)};
unsigned int b_3[4]={((unsigned int)2422377130ULL),((unsigned int)3191213415ULL),((unsigned int)2925816935ULL),((unsigned int)4115941915ULL)};
unsigned int a_4[16]={((unsigned int)1863315621ULL),((unsigned int)3917464984ULL),((unsigned int)2029326063ULL),((unsigned int)1367757835ULL),((unsigned int)1844846502ULL),((unsigned int)1589782950ULL),((unsigned int)3876513595ULL),((unsigned int)3953515749ULL),((unsigned int)2112247258ULL),((unsigned int)2401691102ULL),((unsigned int)3619922112ULL),((unsigned int)224254779ULL),((unsigned int)4200041273ULL),((unsigned int)1985913920ULL),((unsigned int)1313426948ULL),((unsigned int)2755837917ULL)};
unsigned int b_4[16]={((unsigned int)1863315621ULL),((unsigned int)3917464984ULL),((unsigned int)2029326063ULL),((unsigned int)1367757835ULL),((unsigned int)1844846502ULL),((unsigned int)1589782950ULL),((unsigned int)3876513595ULL),((unsigned int)3953515749ULL),((unsigned int)2112247258ULL),((unsigned int)2401691102ULL),((unsigned int)3619922112ULL),((unsigned int)224254779ULL),((unsigned int)4200041273ULL),((unsigned int)1985913920ULL),((unsigned int)1313426948ULL),((unsigned int)2755837917ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 50\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3415054236ULL),((unsigned int)4150589575ULL),((unsigned int)3859021744ULL),((unsigned int)2794241913ULL)};
unsigned int b_0[4]={((unsigned int)3415054236ULL),((unsigned int)4150589575ULL),((unsigned int)3859021744ULL),((unsigned int)2794241913ULL)};
unsigned int a_1[4]={((unsigned int)1613910380ULL),((unsigned int)2210117809ULL),((unsigned int)1759239399ULL),((unsigned int)2060514874ULL)};
unsigned int b_1[4]={((unsigned int)1613910380ULL),((unsigned int)2210117809ULL),((unsigned int)1759239399ULL),((unsigned int)2060514874ULL)};
unsigned int a_2[4]={((unsigned int)3360642022ULL),((unsigned int)2031159749ULL),((unsigned int)4235925294ULL),((unsigned int)515285282ULL)};
unsigned int b_2[4]={((unsigned int)3360642022ULL),((unsigned int)2031159749ULL),((unsigned int)4235925294ULL),((unsigned int)515285282ULL)};
unsigned int a_3[4]={((unsigned int)309693176ULL),((unsigned int)1857199650ULL),((unsigned int)3370420938ULL),((unsigned int)1385636482ULL)};
unsigned int b_3[4]={((unsigned int)309693176ULL),((unsigned int)1857199650ULL),((unsigned int)3370420938ULL),((unsigned int)1385636482ULL)};
unsigned int a_4[16]={((unsigned int)1404269327ULL),((unsigned int)2997025953ULL),((unsigned int)767768418ULL),((unsigned int)2444129219ULL),((unsigned int)4277446205ULL),((unsigned int)103907432ULL),((unsigned int)1469017209ULL),((unsigned int)2708938082ULL),((unsigned int)3659955222ULL),((unsigned int)4255639258ULL),((unsigned int)2010473138ULL),((unsigned int)986743924ULL),((unsigned int)2031055297ULL),((unsigned int)3383389057ULL),((unsigned int)556546995ULL),((unsigned int)1796063809ULL)};
unsigned int b_4[16]={((unsigned int)1404269327ULL),((unsigned int)2997025953ULL),((unsigned int)767768418ULL),((unsigned int)2444129219ULL),((unsigned int)4277446205ULL),((unsigned int)103907432ULL),((unsigned int)1469017209ULL),((unsigned int)2708938082ULL),((unsigned int)3659955222ULL),((unsigned int)4255639258ULL),((unsigned int)2010473138ULL),((unsigned int)986743924ULL),((unsigned int)2031055297ULL),((unsigned int)3383389057ULL),((unsigned int)556546995ULL),((unsigned int)1796063809ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 51\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1296218009ULL),((unsigned int)701795735ULL),((unsigned int)2493922740ULL),((unsigned int)2465797365ULL)};
unsigned int b_0[4]={((unsigned int)1296218009ULL),((unsigned int)701795735ULL),((unsigned int)2493922740ULL),((unsigned int)2465797365ULL)};
unsigned int a_1[4]={((unsigned int)2805645513ULL),((unsigned int)1898461203ULL),((unsigned int)2078569138ULL),((unsigned int)1582141588ULL)};
unsigned int b_1[4]={((unsigned int)2805645513ULL),((unsigned int)1898461203ULL),((unsigned int)2078569138ULL),((unsigned int)1582141588ULL)};
unsigned int a_2[4]={((unsigned int)1253230830ULL),((unsigned int)2735558351ULL),((unsigned int)1801807674ULL),((unsigned int)2936386195ULL)};
unsigned int b_2[4]={((unsigned int)1253230830ULL),((unsigned int)2735558351ULL),((unsigned int)1801807674ULL),((unsigned int)2936386195ULL)};
unsigned int a_3[4]={((unsigned int)573113490ULL),((unsigned int)2847214184ULL),((unsigned int)3366636633ULL),((unsigned int)4094026986ULL)};
unsigned int b_3[4]={((unsigned int)573113490ULL),((unsigned int)2847214184ULL),((unsigned int)3366636633ULL),((unsigned int)4094026986ULL)};
unsigned int a_4[16]={((unsigned int)3076103505ULL),((unsigned int)4276357448ULL),((unsigned int)2536123840ULL),((unsigned int)3233779064ULL),((unsigned int)3310884269ULL),((unsigned int)3726995453ULL),((unsigned int)1293621477ULL),((unsigned int)123103964ULL),((unsigned int)1548546279ULL),((unsigned int)3391616291ULL),((unsigned int)3033177620ULL),((unsigned int)2781587346ULL),((unsigned int)1885268049ULL),((unsigned int)2779112735ULL),((unsigned int)1218007532ULL),((unsigned int)740375822ULL)};
unsigned int b_4[16]={((unsigned int)3076103505ULL),((unsigned int)4276357448ULL),((unsigned int)2536123840ULL),((unsigned int)3233779064ULL),((unsigned int)3310884269ULL),((unsigned int)3726995453ULL),((unsigned int)1293621477ULL),((unsigned int)123103964ULL),((unsigned int)1548546279ULL),((unsigned int)3391616291ULL),((unsigned int)3033177620ULL),((unsigned int)2781587346ULL),((unsigned int)1885268049ULL),((unsigned int)2779112735ULL),((unsigned int)1218007532ULL),((unsigned int)740375822ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 52\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2849295304ULL),((unsigned int)1719644718ULL),((unsigned int)1791895824ULL),((unsigned int)3493387073ULL)};
unsigned int b_0[4]={((unsigned int)2849295304ULL),((unsigned int)1719644718ULL),((unsigned int)1791895824ULL),((unsigned int)3493387073ULL)};
unsigned int a_1[4]={((unsigned int)2972245505ULL),((unsigned int)972827178ULL),((unsigned int)1392568789ULL),((unsigned int)3881300004ULL)};
unsigned int b_1[4]={((unsigned int)2972245505ULL),((unsigned int)972827178ULL),((unsigned int)1392568789ULL),((unsigned int)3881300004ULL)};
unsigned int a_2[4]={((unsigned int)1872173076ULL),((unsigned int)2553753415ULL),((unsigned int)3501063809ULL),((unsigned int)1651189632ULL)};
unsigned int b_2[4]={((unsigned int)1872173076ULL),((unsigned int)2553753415ULL),((unsigned int)3501063809ULL),((unsigned int)1651189632ULL)};
unsigned int a_3[4]={((unsigned int)3898882626ULL),((unsigned int)2875302843ULL),((unsigned int)1020721602ULL),((unsigned int)762743374ULL)};
unsigned int b_3[4]={((unsigned int)3898882626ULL),((unsigned int)2875302843ULL),((unsigned int)1020721602ULL),((unsigned int)762743374ULL)};
unsigned int a_4[16]={((unsigned int)2392486184ULL),((unsigned int)4004926945ULL),((unsigned int)1780033241ULL),((unsigned int)3916920913ULL),((unsigned int)564169239ULL),((unsigned int)3209042820ULL),((unsigned int)3026030767ULL),((unsigned int)393268969ULL),((unsigned int)1320194040ULL),((unsigned int)1154489575ULL),((unsigned int)3299864062ULL),((unsigned int)1389066576ULL),((unsigned int)2654301180ULL),((unsigned int)4012253026ULL),((unsigned int)1254869931ULL),((unsigned int)691420016ULL)};
unsigned int b_4[16]={((unsigned int)2392486184ULL),((unsigned int)4004926945ULL),((unsigned int)1780033241ULL),((unsigned int)3916920913ULL),((unsigned int)564169239ULL),((unsigned int)3209042820ULL),((unsigned int)3026030767ULL),((unsigned int)393268969ULL),((unsigned int)1320194040ULL),((unsigned int)1154489575ULL),((unsigned int)3299864062ULL),((unsigned int)1389066576ULL),((unsigned int)2654301180ULL),((unsigned int)4012253026ULL),((unsigned int)1254869931ULL),((unsigned int)691420016ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 53\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1791369301ULL),((unsigned int)3317026519ULL),((unsigned int)523962735ULL),((unsigned int)2326511688ULL)};
unsigned int b_0[4]={((unsigned int)1791369301ULL),((unsigned int)3317026519ULL),((unsigned int)523962735ULL),((unsigned int)2326511688ULL)};
unsigned int a_1[4]={((unsigned int)312479239ULL),((unsigned int)2488724991ULL),((unsigned int)3934147117ULL),((unsigned int)2701799466ULL)};
unsigned int b_1[4]={((unsigned int)312479239ULL),((unsigned int)2488724991ULL),((unsigned int)3934147117ULL),((unsigned int)2701799466ULL)};
unsigned int a_2[4]={((unsigned int)651122287ULL),((unsigned int)1544728026ULL),((unsigned int)10616103ULL),((unsigned int)2777033682ULL)};
unsigned int b_2[4]={((unsigned int)651122287ULL),((unsigned int)1544728026ULL),((unsigned int)10616103ULL),((unsigned int)2777033682ULL)};
unsigned int a_3[4]={((unsigned int)366446814ULL),((unsigned int)2685867502ULL),((unsigned int)1233333436ULL),((unsigned int)2465355284ULL)};
unsigned int b_3[4]={((unsigned int)366446814ULL),((unsigned int)2685867502ULL),((unsigned int)1233333436ULL),((unsigned int)2465355284ULL)};
unsigned int a_4[16]={((unsigned int)3649556135ULL),((unsigned int)4243566274ULL),((unsigned int)2871663051ULL),((unsigned int)3391594396ULL),((unsigned int)1822897543ULL),((unsigned int)2420058627ULL),((unsigned int)2345000674ULL),((unsigned int)2934763722ULL),((unsigned int)160884629ULL),((unsigned int)304577973ULL),((unsigned int)3172796228ULL),((unsigned int)3582172845ULL),((unsigned int)273171133ULL),((unsigned int)1208497062ULL),((unsigned int)2314038702ULL),((unsigned int)3642817560ULL)};
unsigned int b_4[16]={((unsigned int)3649556135ULL),((unsigned int)4243566274ULL),((unsigned int)2871663051ULL),((unsigned int)3391594396ULL),((unsigned int)1822897543ULL),((unsigned int)2420058627ULL),((unsigned int)2345000674ULL),((unsigned int)2934763722ULL),((unsigned int)160884629ULL),((unsigned int)304577973ULL),((unsigned int)3172796228ULL),((unsigned int)3582172845ULL),((unsigned int)273171133ULL),((unsigned int)1208497062ULL),((unsigned int)2314038702ULL),((unsigned int)3642817560ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 54\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3018727493ULL),((unsigned int)1440112210ULL),((unsigned int)585351191ULL),((unsigned int)3620177548ULL)};
unsigned int b_0[4]={((unsigned int)3018727493ULL),((unsigned int)1440112210ULL),((unsigned int)585351191ULL),((unsigned int)3620177548ULL)};
unsigned int a_1[4]={((unsigned int)139851558ULL),((unsigned int)3485858218ULL),((unsigned int)2216165651ULL),((unsigned int)988815942ULL)};
unsigned int b_1[4]={((unsigned int)139851558ULL),((unsigned int)3485858218ULL),((unsigned int)2216165651ULL),((unsigned int)988815942ULL)};
unsigned int a_2[4]={((unsigned int)942639900ULL),((unsigned int)2719882297ULL),((unsigned int)3948013047ULL),((unsigned int)3078738920ULL)};
unsigned int b_2[4]={((unsigned int)942639900ULL),((unsigned int)2719882297ULL),((unsigned int)3948013047ULL),((unsigned int)3078738920ULL)};
unsigned int a_3[4]={((unsigned int)3118391414ULL),((unsigned int)3540859618ULL),((unsigned int)2524533598ULL),((unsigned int)3884959850ULL)};
unsigned int b_3[4]={((unsigned int)3118391414ULL),((unsigned int)3540859618ULL),((unsigned int)2524533598ULL),((unsigned int)3884959850ULL)};
unsigned int a_4[16]={((unsigned int)833969987ULL),((unsigned int)3524697166ULL),((unsigned int)1902527375ULL),((unsigned int)381696463ULL),((unsigned int)181858128ULL),((unsigned int)1617228144ULL),((unsigned int)1279718293ULL),((unsigned int)533487044ULL),((unsigned int)1135716580ULL),((unsigned int)1360154898ULL),((unsigned int)607019376ULL),((unsigned int)3723685945ULL),((unsigned int)4154187011ULL),((unsigned int)3024638832ULL),((unsigned int)4291717957ULL),((unsigned int)525739214ULL)};
unsigned int b_4[16]={((unsigned int)833969987ULL),((unsigned int)3524697166ULL),((unsigned int)1902527375ULL),((unsigned int)381696463ULL),((unsigned int)181858128ULL),((unsigned int)1617228144ULL),((unsigned int)1279718293ULL),((unsigned int)533487044ULL),((unsigned int)1135716580ULL),((unsigned int)1360154898ULL),((unsigned int)607019376ULL),((unsigned int)3723685945ULL),((unsigned int)4154187011ULL),((unsigned int)3024638832ULL),((unsigned int)4291717957ULL),((unsigned int)525739214ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 55\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3935517047ULL),((unsigned int)2066653395ULL),((unsigned int)1142247167ULL),((unsigned int)3276023726ULL)};
unsigned int b_0[4]={((unsigned int)3935517047ULL),((unsigned int)2066653395ULL),((unsigned int)1142247167ULL),((unsigned int)3276023726ULL)};
unsigned int a_1[4]={((unsigned int)3893545346ULL),((unsigned int)4218984677ULL),((unsigned int)1340469429ULL),((unsigned int)3930627623ULL)};
unsigned int b_1[4]={((unsigned int)3893545346ULL),((unsigned int)4218984677ULL),((unsigned int)1340469429ULL),((unsigned int)3930627623ULL)};
unsigned int a_2[4]={((unsigned int)2480666166ULL),((unsigned int)3987924381ULL),((unsigned int)4043094618ULL),((unsigned int)531610158ULL)};
unsigned int b_2[4]={((unsigned int)2480666166ULL),((unsigned int)3987924381ULL),((unsigned int)4043094618ULL),((unsigned int)531610158ULL)};
unsigned int a_3[4]={((unsigned int)981299726ULL),((unsigned int)2203583190ULL),((unsigned int)1442380638ULL),((unsigned int)2923023279ULL)};
unsigned int b_3[4]={((unsigned int)981299726ULL),((unsigned int)2203583190ULL),((unsigned int)1442380638ULL),((unsigned int)2923023279ULL)};
unsigned int a_4[16]={((unsigned int)2781720374ULL),((unsigned int)876192452ULL),((unsigned int)2438581462ULL),((unsigned int)2525349786ULL),((unsigned int)3569736047ULL),((unsigned int)1918390429ULL),((unsigned int)2963366461ULL),((unsigned int)120275408ULL),((unsigned int)2202309313ULL),((unsigned int)105934183ULL),((unsigned int)775027831ULL),((unsigned int)2198038874ULL),((unsigned int)54371312ULL),((unsigned int)1689526367ULL),((unsigned int)1401037684ULL),((unsigned int)3290893653ULL)};
unsigned int b_4[16]={((unsigned int)2781720374ULL),((unsigned int)876192452ULL),((unsigned int)2438581462ULL),((unsigned int)2525349786ULL),((unsigned int)3569736047ULL),((unsigned int)1918390429ULL),((unsigned int)2963366461ULL),((unsigned int)120275408ULL),((unsigned int)2202309313ULL),((unsigned int)105934183ULL),((unsigned int)775027831ULL),((unsigned int)2198038874ULL),((unsigned int)54371312ULL),((unsigned int)1689526367ULL),((unsigned int)1401037684ULL),((unsigned int)3290893653ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 56\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)885739361ULL),((unsigned int)231194942ULL),((unsigned int)2029298516ULL),((unsigned int)4064278956ULL)};
unsigned int b_0[4]={((unsigned int)885739361ULL),((unsigned int)231194942ULL),((unsigned int)2029298516ULL),((unsigned int)4064278956ULL)};
unsigned int a_1[4]={((unsigned int)46878570ULL),((unsigned int)251432839ULL),((unsigned int)3829613179ULL),((unsigned int)1857898567ULL)};
unsigned int b_1[4]={((unsigned int)46878570ULL),((unsigned int)251432839ULL),((unsigned int)3829613179ULL),((unsigned int)1857898567ULL)};
unsigned int a_2[4]={((unsigned int)2932836001ULL),((unsigned int)1185805704ULL),((unsigned int)597609889ULL),((unsigned int)2846820922ULL)};
unsigned int b_2[4]={((unsigned int)2932836001ULL),((unsigned int)1185805704ULL),((unsigned int)597609889ULL),((unsigned int)2846820922ULL)};
unsigned int a_3[4]={((unsigned int)2182866179ULL),((unsigned int)2093162719ULL),((unsigned int)1139473134ULL),((unsigned int)3574636864ULL)};
unsigned int b_3[4]={((unsigned int)2182866179ULL),((unsigned int)2093162719ULL),((unsigned int)1139473134ULL),((unsigned int)3574636864ULL)};
unsigned int a_4[16]={((unsigned int)3931790880ULL),((unsigned int)237548057ULL),((unsigned int)3382738432ULL),((unsigned int)404764630ULL),((unsigned int)3327985975ULL),((unsigned int)2022893870ULL),((unsigned int)1025572734ULL),((unsigned int)1678382363ULL),((unsigned int)1314185583ULL),((unsigned int)3546456805ULL),((unsigned int)301623718ULL),((unsigned int)1069189628ULL),((unsigned int)2997142129ULL),((unsigned int)3269158732ULL),((unsigned int)3543835201ULL),((unsigned int)1630954441ULL)};
unsigned int b_4[16]={((unsigned int)3931790880ULL),((unsigned int)237548057ULL),((unsigned int)3382738432ULL),((unsigned int)404764630ULL),((unsigned int)3327985975ULL),((unsigned int)2022893870ULL),((unsigned int)1025572734ULL),((unsigned int)1678382363ULL),((unsigned int)1314185583ULL),((unsigned int)3546456805ULL),((unsigned int)301623718ULL),((unsigned int)1069189628ULL),((unsigned int)2997142129ULL),((unsigned int)3269158732ULL),((unsigned int)3543835201ULL),((unsigned int)1630954441ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 57\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1175076928ULL),((unsigned int)929417830ULL),((unsigned int)1113127870ULL),((unsigned int)1982288045ULL)};
unsigned int b_0[4]={((unsigned int)1175076928ULL),((unsigned int)929417830ULL),((unsigned int)1113127870ULL),((unsigned int)1982288045ULL)};
unsigned int a_1[4]={((unsigned int)1390537768ULL),((unsigned int)1541154919ULL),((unsigned int)2235729332ULL),((unsigned int)3178604475ULL)};
unsigned int b_1[4]={((unsigned int)1390537768ULL),((unsigned int)1541154919ULL),((unsigned int)2235729332ULL),((unsigned int)3178604475ULL)};
unsigned int a_2[4]={((unsigned int)2668150386ULL),((unsigned int)4125313545ULL),((unsigned int)3009486975ULL),((unsigned int)675957749ULL)};
unsigned int b_2[4]={((unsigned int)2668150386ULL),((unsigned int)4125313545ULL),((unsigned int)3009486975ULL),((unsigned int)675957749ULL)};
unsigned int a_3[4]={((unsigned int)3958403505ULL),((unsigned int)1343207414ULL),((unsigned int)3897256680ULL),((unsigned int)2207313875ULL)};
unsigned int b_3[4]={((unsigned int)3958403505ULL),((unsigned int)1343207414ULL),((unsigned int)3897256680ULL),((unsigned int)2207313875ULL)};
unsigned int a_4[16]={((unsigned int)400937723ULL),((unsigned int)3729078877ULL),((unsigned int)3470964570ULL),((unsigned int)3052987181ULL),((unsigned int)1834458374ULL),((unsigned int)3506131612ULL),((unsigned int)3343374654ULL),((unsigned int)2752684053ULL),((unsigned int)2535578018ULL),((unsigned int)4023855700ULL),((unsigned int)1293420026ULL),((unsigned int)848574100ULL),((unsigned int)3668225697ULL),((unsigned int)4121431541ULL),((unsigned int)3263032703ULL),((unsigned int)1590763263ULL)};
unsigned int b_4[16]={((unsigned int)400937723ULL),((unsigned int)3729078877ULL),((unsigned int)3470964570ULL),((unsigned int)3052987181ULL),((unsigned int)1834458374ULL),((unsigned int)3506131612ULL),((unsigned int)3343374654ULL),((unsigned int)2752684053ULL),((unsigned int)2535578018ULL),((unsigned int)4023855700ULL),((unsigned int)1293420026ULL),((unsigned int)848574100ULL),((unsigned int)3668225697ULL),((unsigned int)4121431541ULL),((unsigned int)3263032703ULL),((unsigned int)1590763263ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 58\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3660571098ULL),((unsigned int)2519335049ULL),((unsigned int)2467221987ULL),((unsigned int)2175079037ULL)};
unsigned int b_0[4]={((unsigned int)3660571098ULL),((unsigned int)2519335049ULL),((unsigned int)2467221987ULL),((unsigned int)2175079037ULL)};
unsigned int a_1[4]={((unsigned int)228476662ULL),((unsigned int)921239016ULL),((unsigned int)2818818046ULL),((unsigned int)2060544048ULL)};
unsigned int b_1[4]={((unsigned int)228476662ULL),((unsigned int)921239016ULL),((unsigned int)2818818046ULL),((unsigned int)2060544048ULL)};
unsigned int a_2[4]={((unsigned int)48223258ULL),((unsigned int)3021700477ULL),((unsigned int)346508104ULL),((unsigned int)1078359032ULL)};
unsigned int b_2[4]={((unsigned int)48223258ULL),((unsigned int)3021700477ULL),((unsigned int)346508104ULL),((unsigned int)1078359032ULL)};
unsigned int a_3[4]={((unsigned int)610486766ULL),((unsigned int)118243993ULL),((unsigned int)502168113ULL),((unsigned int)85105336ULL)};
unsigned int b_3[4]={((unsigned int)610486766ULL),((unsigned int)118243993ULL),((unsigned int)502168113ULL),((unsigned int)85105336ULL)};
unsigned int a_4[16]={((unsigned int)3048591594ULL),((unsigned int)3544225888ULL),((unsigned int)162209202ULL),((unsigned int)20922121ULL),((unsigned int)2039639797ULL),((unsigned int)4028271187ULL),((unsigned int)996700021ULL),((unsigned int)131211557ULL),((unsigned int)3414106739ULL),((unsigned int)310479552ULL),((unsigned int)3329412017ULL),((unsigned int)3427738376ULL),((unsigned int)3665331088ULL),((unsigned int)1037822040ULL),((unsigned int)146360156ULL),((unsigned int)1984387412ULL)};
unsigned int b_4[16]={((unsigned int)3048591594ULL),((unsigned int)3544225888ULL),((unsigned int)162209202ULL),((unsigned int)20922121ULL),((unsigned int)2039639797ULL),((unsigned int)4028271187ULL),((unsigned int)996700021ULL),((unsigned int)131211557ULL),((unsigned int)3414106739ULL),((unsigned int)310479552ULL),((unsigned int)3329412017ULL),((unsigned int)3427738376ULL),((unsigned int)3665331088ULL),((unsigned int)1037822040ULL),((unsigned int)146360156ULL),((unsigned int)1984387412ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 59\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3489750485ULL),((unsigned int)382231740ULL),((unsigned int)3875942354ULL),((unsigned int)3052313734ULL)};
unsigned int b_0[4]={((unsigned int)3489750485ULL),((unsigned int)382231740ULL),((unsigned int)3875942354ULL),((unsigned int)3052313734ULL)};
unsigned int a_1[4]={((unsigned int)1357442545ULL),((unsigned int)3495750883ULL),((unsigned int)2570135578ULL),((unsigned int)3516364509ULL)};
unsigned int b_1[4]={((unsigned int)1357442545ULL),((unsigned int)3495750883ULL),((unsigned int)2570135578ULL),((unsigned int)3516364509ULL)};
unsigned int a_2[4]={((unsigned int)4210219351ULL),((unsigned int)3368102520ULL),((unsigned int)1893299800ULL),((unsigned int)571857901ULL)};
unsigned int b_2[4]={((unsigned int)4210219351ULL),((unsigned int)3368102520ULL),((unsigned int)1893299800ULL),((unsigned int)571857901ULL)};
unsigned int a_3[4]={((unsigned int)2495545347ULL),((unsigned int)2706479070ULL),((unsigned int)930469542ULL),((unsigned int)2304542093ULL)};
unsigned int b_3[4]={((unsigned int)2495545347ULL),((unsigned int)2706479070ULL),((unsigned int)930469542ULL),((unsigned int)2304542093ULL)};
unsigned int a_4[16]={((unsigned int)800135069ULL),((unsigned int)2221902641ULL),((unsigned int)2081952467ULL),((unsigned int)1896940136ULL),((unsigned int)576000182ULL),((unsigned int)456320226ULL),((unsigned int)844431109ULL),((unsigned int)3935402558ULL),((unsigned int)1972411010ULL),((unsigned int)2786822408ULL),((unsigned int)712728031ULL),((unsigned int)2422098255ULL),((unsigned int)3692363360ULL),((unsigned int)3109812645ULL),((unsigned int)3228102010ULL),((unsigned int)1865258979ULL)};
unsigned int b_4[16]={((unsigned int)800135069ULL),((unsigned int)2221902641ULL),((unsigned int)2081952467ULL),((unsigned int)1896940136ULL),((unsigned int)576000182ULL),((unsigned int)456320226ULL),((unsigned int)844431109ULL),((unsigned int)3935402558ULL),((unsigned int)1972411010ULL),((unsigned int)2786822408ULL),((unsigned int)712728031ULL),((unsigned int)2422098255ULL),((unsigned int)3692363360ULL),((unsigned int)3109812645ULL),((unsigned int)3228102010ULL),((unsigned int)1865258979ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 60\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4231983867ULL),((unsigned int)4282356035ULL),((unsigned int)2204996662ULL),((unsigned int)2808878366ULL)};
unsigned int b_0[4]={((unsigned int)4231983867ULL),((unsigned int)4282356035ULL),((unsigned int)2204996662ULL),((unsigned int)2808878366ULL)};
unsigned int a_1[4]={((unsigned int)3317037389ULL),((unsigned int)3374203509ULL),((unsigned int)1817470378ULL),((unsigned int)704766462ULL)};
unsigned int b_1[4]={((unsigned int)3317037389ULL),((unsigned int)3374203509ULL),((unsigned int)1817470378ULL),((unsigned int)704766462ULL)};
unsigned int a_2[4]={((unsigned int)815407891ULL),((unsigned int)533410658ULL),((unsigned int)494900049ULL),((unsigned int)3189125231ULL)};
unsigned int b_2[4]={((unsigned int)815407891ULL),((unsigned int)533410658ULL),((unsigned int)494900049ULL),((unsigned int)3189125231ULL)};
unsigned int a_3[4]={((unsigned int)2711420489ULL),((unsigned int)2155511928ULL),((unsigned int)1388830873ULL),((unsigned int)833449300ULL)};
unsigned int b_3[4]={((unsigned int)2711420489ULL),((unsigned int)2155511928ULL),((unsigned int)1388830873ULL),((unsigned int)833449300ULL)};
unsigned int a_4[16]={((unsigned int)256371190ULL),((unsigned int)3507317804ULL),((unsigned int)277070016ULL),((unsigned int)2310255272ULL),((unsigned int)2216437630ULL),((unsigned int)3037393392ULL),((unsigned int)4228027139ULL),((unsigned int)89228673ULL),((unsigned int)2184964090ULL),((unsigned int)1917567548ULL),((unsigned int)3601335231ULL),((unsigned int)118813359ULL),((unsigned int)2109312064ULL),((unsigned int)1267612868ULL),((unsigned int)2393097569ULL),((unsigned int)2236790671ULL)};
unsigned int b_4[16]={((unsigned int)256371190ULL),((unsigned int)3507317804ULL),((unsigned int)277070016ULL),((unsigned int)2310255272ULL),((unsigned int)2216437630ULL),((unsigned int)3037393392ULL),((unsigned int)4228027139ULL),((unsigned int)89228673ULL),((unsigned int)2184964090ULL),((unsigned int)1917567548ULL),((unsigned int)3601335231ULL),((unsigned int)118813359ULL),((unsigned int)2109312064ULL),((unsigned int)1267612868ULL),((unsigned int)2393097569ULL),((unsigned int)2236790671ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 61\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3868268157ULL),((unsigned int)290954273ULL),((unsigned int)1239689826ULL),((unsigned int)3329804496ULL)};
unsigned int b_0[4]={((unsigned int)3868268157ULL),((unsigned int)290954273ULL),((unsigned int)1239689826ULL),((unsigned int)3329804496ULL)};
unsigned int a_1[4]={((unsigned int)4092437424ULL),((unsigned int)4199791077ULL),((unsigned int)3056317304ULL),((unsigned int)3491111712ULL)};
unsigned int b_1[4]={((unsigned int)4092437424ULL),((unsigned int)4199791077ULL),((unsigned int)3056317304ULL),((unsigned int)3491111712ULL)};
unsigned int a_2[4]={((unsigned int)2287970304ULL),((unsigned int)2774147307ULL),((unsigned int)3126766612ULL),((unsigned int)3142291148ULL)};
unsigned int b_2[4]={((unsigned int)2287970304ULL),((unsigned int)2774147307ULL),((unsigned int)3126766612ULL),((unsigned int)3142291148ULL)};
unsigned int a_3[4]={((unsigned int)3867827818ULL),((unsigned int)1359382704ULL),((unsigned int)3924279864ULL),((unsigned int)3749315707ULL)};
unsigned int b_3[4]={((unsigned int)3867827818ULL),((unsigned int)1359382704ULL),((unsigned int)3924279864ULL),((unsigned int)3749315707ULL)};
unsigned int a_4[16]={((unsigned int)119973373ULL),((unsigned int)2059837922ULL),((unsigned int)3315592535ULL),((unsigned int)3432529203ULL),((unsigned int)454774777ULL),((unsigned int)4062323964ULL),((unsigned int)506564440ULL),((unsigned int)2987921623ULL),((unsigned int)3917364965ULL),((unsigned int)1213115001ULL),((unsigned int)1454286471ULL),((unsigned int)2528986302ULL),((unsigned int)2831173550ULL),((unsigned int)1231571993ULL),((unsigned int)3152119837ULL),((unsigned int)40877009ULL)};
unsigned int b_4[16]={((unsigned int)119973373ULL),((unsigned int)2059837922ULL),((unsigned int)3315592535ULL),((unsigned int)3432529203ULL),((unsigned int)454774777ULL),((unsigned int)4062323964ULL),((unsigned int)506564440ULL),((unsigned int)2987921623ULL),((unsigned int)3917364965ULL),((unsigned int)1213115001ULL),((unsigned int)1454286471ULL),((unsigned int)2528986302ULL),((unsigned int)2831173550ULL),((unsigned int)1231571993ULL),((unsigned int)3152119837ULL),((unsigned int)40877009ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 62\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3503571977ULL),((unsigned int)3759691757ULL),((unsigned int)1289262931ULL),((unsigned int)3032057102ULL)};
unsigned int b_0[4]={((unsigned int)3503571977ULL),((unsigned int)3759691757ULL),((unsigned int)1289262931ULL),((unsigned int)3032057102ULL)};
unsigned int a_1[4]={((unsigned int)1448492804ULL),((unsigned int)907735995ULL),((unsigned int)2728590142ULL),((unsigned int)3067368152ULL)};
unsigned int b_1[4]={((unsigned int)1448492804ULL),((unsigned int)907735995ULL),((unsigned int)2728590142ULL),((unsigned int)3067368152ULL)};
unsigned int a_2[4]={((unsigned int)555680703ULL),((unsigned int)3145281671ULL),((unsigned int)729942859ULL),((unsigned int)3872436854ULL)};
unsigned int b_2[4]={((unsigned int)555680703ULL),((unsigned int)3145281671ULL),((unsigned int)729942859ULL),((unsigned int)3872436854ULL)};
unsigned int a_3[4]={((unsigned int)1147495941ULL),((unsigned int)1054509103ULL),((unsigned int)3556863004ULL),((unsigned int)3153755942ULL)};
unsigned int b_3[4]={((unsigned int)1147495941ULL),((unsigned int)1054509103ULL),((unsigned int)3556863004ULL),((unsigned int)3153755942ULL)};
unsigned int a_4[16]={((unsigned int)2533043671ULL),((unsigned int)3382171266ULL),((unsigned int)1184921431ULL),((unsigned int)1205015937ULL),((unsigned int)2725539403ULL),((unsigned int)3988909948ULL),((unsigned int)1038219806ULL),((unsigned int)615237537ULL),((unsigned int)3337847242ULL),((unsigned int)3750468791ULL),((unsigned int)2789245324ULL),((unsigned int)1463758641ULL),((unsigned int)3837381795ULL),((unsigned int)1308182146ULL),((unsigned int)1208945973ULL),((unsigned int)3077011520ULL)};
unsigned int b_4[16]={((unsigned int)2533043671ULL),((unsigned int)3382171266ULL),((unsigned int)1184921431ULL),((unsigned int)1205015937ULL),((unsigned int)2725539403ULL),((unsigned int)3988909948ULL),((unsigned int)1038219806ULL),((unsigned int)615237537ULL),((unsigned int)3337847242ULL),((unsigned int)3750468791ULL),((unsigned int)2789245324ULL),((unsigned int)1463758641ULL),((unsigned int)3837381795ULL),((unsigned int)1308182146ULL),((unsigned int)1208945973ULL),((unsigned int)3077011520ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 63\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)449504020ULL),((unsigned int)3341497745ULL),((unsigned int)3185692970ULL),((unsigned int)891036672ULL)};
unsigned int b_0[4]={((unsigned int)449504020ULL),((unsigned int)3341497745ULL),((unsigned int)3185692970ULL),((unsigned int)891036672ULL)};
unsigned int a_1[4]={((unsigned int)194643845ULL),((unsigned int)2696800378ULL),((unsigned int)838831125ULL),((unsigned int)2398193493ULL)};
unsigned int b_1[4]={((unsigned int)194643845ULL),((unsigned int)2696800378ULL),((unsigned int)838831125ULL),((unsigned int)2398193493ULL)};
unsigned int a_2[4]={((unsigned int)3042198514ULL),((unsigned int)1575677583ULL),((unsigned int)2804094391ULL),((unsigned int)3077478789ULL)};
unsigned int b_2[4]={((unsigned int)3042198514ULL),((unsigned int)1575677583ULL),((unsigned int)2804094391ULL),((unsigned int)3077478789ULL)};
unsigned int a_3[4]={((unsigned int)2314125544ULL),((unsigned int)1971810093ULL),((unsigned int)737056074ULL),((unsigned int)381165377ULL)};
unsigned int b_3[4]={((unsigned int)2314125544ULL),((unsigned int)1971810093ULL),((unsigned int)737056074ULL),((unsigned int)381165377ULL)};
unsigned int a_4[16]={((unsigned int)4164871284ULL),((unsigned int)4292520255ULL),((unsigned int)2776361304ULL),((unsigned int)1375088650ULL),((unsigned int)3896461236ULL),((unsigned int)3320879673ULL),((unsigned int)821755876ULL),((unsigned int)3880083733ULL),((unsigned int)1727208245ULL),((unsigned int)351259855ULL),((unsigned int)3028529008ULL),((unsigned int)3775338455ULL),((unsigned int)1968074290ULL),((unsigned int)3805226595ULL),((unsigned int)4202810272ULL),((unsigned int)84193354ULL)};
unsigned int b_4[16]={((unsigned int)4164871284ULL),((unsigned int)4292520255ULL),((unsigned int)2776361304ULL),((unsigned int)1375088650ULL),((unsigned int)3896461236ULL),((unsigned int)3320879673ULL),((unsigned int)821755876ULL),((unsigned int)3880083733ULL),((unsigned int)1727208245ULL),((unsigned int)351259855ULL),((unsigned int)3028529008ULL),((unsigned int)3775338455ULL),((unsigned int)1968074290ULL),((unsigned int)3805226595ULL),((unsigned int)4202810272ULL),((unsigned int)84193354ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 64\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1732853239ULL),((unsigned int)3952147437ULL),((unsigned int)928125706ULL),((unsigned int)2907842667ULL)};
unsigned int b_0[4]={((unsigned int)1732853239ULL),((unsigned int)3952147437ULL),((unsigned int)928125706ULL),((unsigned int)2907842667ULL)};
unsigned int a_1[4]={((unsigned int)3562669113ULL),((unsigned int)1675531005ULL),((unsigned int)3788058480ULL),((unsigned int)115141657ULL)};
unsigned int b_1[4]={((unsigned int)3562669113ULL),((unsigned int)1675531005ULL),((unsigned int)3788058480ULL),((unsigned int)115141657ULL)};
unsigned int a_2[4]={((unsigned int)2325418194ULL),((unsigned int)3238034525ULL),((unsigned int)44507259ULL),((unsigned int)2309629182ULL)};
unsigned int b_2[4]={((unsigned int)2325418194ULL),((unsigned int)3238034525ULL),((unsigned int)44507259ULL),((unsigned int)2309629182ULL)};
unsigned int a_3[4]={((unsigned int)3409884098ULL),((unsigned int)695337562ULL),((unsigned int)3421238141ULL),((unsigned int)3886039680ULL)};
unsigned int b_3[4]={((unsigned int)3409884098ULL),((unsigned int)695337562ULL),((unsigned int)3421238141ULL),((unsigned int)3886039680ULL)};
unsigned int a_4[16]={((unsigned int)3044158158ULL),((unsigned int)1958478360ULL),((unsigned int)3247113989ULL),((unsigned int)2693336580ULL),((unsigned int)3272233751ULL),((unsigned int)874644097ULL),((unsigned int)1101980134ULL),((unsigned int)4213049135ULL),((unsigned int)71712740ULL),((unsigned int)233755600ULL),((unsigned int)3782198523ULL),((unsigned int)1038004483ULL),((unsigned int)699100767ULL),((unsigned int)875965924ULL),((unsigned int)3452599468ULL),((unsigned int)941553013ULL)};
unsigned int b_4[16]={((unsigned int)3044158158ULL),((unsigned int)1958478360ULL),((unsigned int)3247113989ULL),((unsigned int)2693336580ULL),((unsigned int)3272233751ULL),((unsigned int)874644097ULL),((unsigned int)1101980134ULL),((unsigned int)4213049135ULL),((unsigned int)71712740ULL),((unsigned int)233755600ULL),((unsigned int)3782198523ULL),((unsigned int)1038004483ULL),((unsigned int)699100767ULL),((unsigned int)875965924ULL),((unsigned int)3452599468ULL),((unsigned int)941553013ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 65\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1046119077ULL),((unsigned int)3376178501ULL),((unsigned int)758903265ULL),((unsigned int)1753695110ULL)};
unsigned int b_0[4]={((unsigned int)1046119077ULL),((unsigned int)3376178501ULL),((unsigned int)758903265ULL),((unsigned int)1753695110ULL)};
unsigned int a_1[4]={((unsigned int)3466678847ULL),((unsigned int)3718998219ULL),((unsigned int)1537282734ULL),((unsigned int)2469000256ULL)};
unsigned int b_1[4]={((unsigned int)3466678847ULL),((unsigned int)3718998219ULL),((unsigned int)1537282734ULL),((unsigned int)2469000256ULL)};
unsigned int a_2[4]={((unsigned int)317367059ULL),((unsigned int)2515815652ULL),((unsigned int)2263906307ULL),((unsigned int)2198688277ULL)};
unsigned int b_2[4]={((unsigned int)317367059ULL),((unsigned int)2515815652ULL),((unsigned int)2263906307ULL),((unsigned int)2198688277ULL)};
unsigned int a_3[4]={((unsigned int)464209346ULL),((unsigned int)2299493419ULL),((unsigned int)2979049864ULL),((unsigned int)1636342148ULL)};
unsigned int b_3[4]={((unsigned int)464209346ULL),((unsigned int)2299493419ULL),((unsigned int)2979049864ULL),((unsigned int)1636342148ULL)};
unsigned int a_4[16]={((unsigned int)2656837868ULL),((unsigned int)1810851392ULL),((unsigned int)4021675321ULL),((unsigned int)586544246ULL),((unsigned int)63425983ULL),((unsigned int)2266893529ULL),((unsigned int)823438081ULL),((unsigned int)3485408416ULL),((unsigned int)417890661ULL),((unsigned int)2059012935ULL),((unsigned int)2672298899ULL),((unsigned int)1997959327ULL),((unsigned int)1102698130ULL),((unsigned int)313811195ULL),((unsigned int)1332189990ULL),((unsigned int)3006611943ULL)};
unsigned int b_4[16]={((unsigned int)2656837868ULL),((unsigned int)1810851392ULL),((unsigned int)4021675321ULL),((unsigned int)586544246ULL),((unsigned int)63425983ULL),((unsigned int)2266893529ULL),((unsigned int)823438081ULL),((unsigned int)3485408416ULL),((unsigned int)417890661ULL),((unsigned int)2059012935ULL),((unsigned int)2672298899ULL),((unsigned int)1997959327ULL),((unsigned int)1102698130ULL),((unsigned int)313811195ULL),((unsigned int)1332189990ULL),((unsigned int)3006611943ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 66\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4135387513ULL),((unsigned int)267581118ULL),((unsigned int)822647846ULL),((unsigned int)3742909844ULL)};
unsigned int b_0[4]={((unsigned int)4135387513ULL),((unsigned int)267581118ULL),((unsigned int)822647846ULL),((unsigned int)3742909844ULL)};
unsigned int a_1[4]={((unsigned int)2552805138ULL),((unsigned int)3804897470ULL),((unsigned int)1080034745ULL),((unsigned int)556670961ULL)};
unsigned int b_1[4]={((unsigned int)2552805138ULL),((unsigned int)3804897470ULL),((unsigned int)1080034745ULL),((unsigned int)556670961ULL)};
unsigned int a_2[4]={((unsigned int)3584564242ULL),((unsigned int)3859376047ULL),((unsigned int)2537516012ULL),((unsigned int)1712155059ULL)};
unsigned int b_2[4]={((unsigned int)3584564242ULL),((unsigned int)3859376047ULL),((unsigned int)2537516012ULL),((unsigned int)1712155059ULL)};
unsigned int a_3[4]={((unsigned int)2585962291ULL),((unsigned int)1514362762ULL),((unsigned int)399050634ULL),((unsigned int)868755618ULL)};
unsigned int b_3[4]={((unsigned int)2585962291ULL),((unsigned int)1514362762ULL),((unsigned int)399050634ULL),((unsigned int)868755618ULL)};
unsigned int a_4[16]={((unsigned int)1688234697ULL),((unsigned int)4237155388ULL),((unsigned int)1537463570ULL),((unsigned int)568732226ULL),((unsigned int)3498830178ULL),((unsigned int)84862386ULL),((unsigned int)4246198240ULL),((unsigned int)3328689353ULL),((unsigned int)2866047915ULL),((unsigned int)2713612878ULL),((unsigned int)3651816703ULL),((unsigned int)3364245165ULL),((unsigned int)2313833316ULL),((unsigned int)286812047ULL),((unsigned int)229168199ULL),((unsigned int)2248987433ULL)};
unsigned int b_4[16]={((unsigned int)1688234697ULL),((unsigned int)4237155388ULL),((unsigned int)1537463570ULL),((unsigned int)568732226ULL),((unsigned int)3498830178ULL),((unsigned int)84862386ULL),((unsigned int)4246198240ULL),((unsigned int)3328689353ULL),((unsigned int)2866047915ULL),((unsigned int)2713612878ULL),((unsigned int)3651816703ULL),((unsigned int)3364245165ULL),((unsigned int)2313833316ULL),((unsigned int)286812047ULL),((unsigned int)229168199ULL),((unsigned int)2248987433ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 67\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2845923958ULL),((unsigned int)1329860392ULL),((unsigned int)3173027834ULL),((unsigned int)2496546043ULL)};
unsigned int b_0[4]={((unsigned int)2845923958ULL),((unsigned int)1329860392ULL),((unsigned int)3173027834ULL),((unsigned int)2496546043ULL)};
unsigned int a_1[4]={((unsigned int)1305796839ULL),((unsigned int)1949921921ULL),((unsigned int)3838216781ULL),((unsigned int)2860458029ULL)};
unsigned int b_1[4]={((unsigned int)1305796839ULL),((unsigned int)1949921921ULL),((unsigned int)3838216781ULL),((unsigned int)2860458029ULL)};
unsigned int a_2[4]={((unsigned int)412239362ULL),((unsigned int)1884171612ULL),((unsigned int)3721826506ULL),((unsigned int)645003650ULL)};
unsigned int b_2[4]={((unsigned int)412239362ULL),((unsigned int)1884171612ULL),((unsigned int)3721826506ULL),((unsigned int)645003650ULL)};
unsigned int a_3[4]={((unsigned int)2318874391ULL),((unsigned int)94572790ULL),((unsigned int)2726428217ULL),((unsigned int)2719623626ULL)};
unsigned int b_3[4]={((unsigned int)2318874391ULL),((unsigned int)94572790ULL),((unsigned int)2726428217ULL),((unsigned int)2719623626ULL)};
unsigned int a_4[16]={((unsigned int)3342294634ULL),((unsigned int)3626635816ULL),((unsigned int)4052812832ULL),((unsigned int)1991211228ULL),((unsigned int)2591618548ULL),((unsigned int)1927301953ULL),((unsigned int)1394775084ULL),((unsigned int)447598651ULL),((unsigned int)2569575239ULL),((unsigned int)4200343069ULL),((unsigned int)253531217ULL),((unsigned int)780444935ULL),((unsigned int)557993380ULL),((unsigned int)505160148ULL),((unsigned int)853564379ULL),((unsigned int)813975968ULL)};
unsigned int b_4[16]={((unsigned int)3342294634ULL),((unsigned int)3626635816ULL),((unsigned int)4052812832ULL),((unsigned int)1991211228ULL),((unsigned int)2591618548ULL),((unsigned int)1927301953ULL),((unsigned int)1394775084ULL),((unsigned int)447598651ULL),((unsigned int)2569575239ULL),((unsigned int)4200343069ULL),((unsigned int)253531217ULL),((unsigned int)780444935ULL),((unsigned int)557993380ULL),((unsigned int)505160148ULL),((unsigned int)853564379ULL),((unsigned int)813975968ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 68\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)498249871ULL),((unsigned int)768149875ULL),((unsigned int)2979416954ULL),((unsigned int)3186621046ULL)};
unsigned int b_0[4]={((unsigned int)498249871ULL),((unsigned int)768149875ULL),((unsigned int)2979416954ULL),((unsigned int)3186621046ULL)};
unsigned int a_1[4]={((unsigned int)790025424ULL),((unsigned int)2173571666ULL),((unsigned int)735488206ULL),((unsigned int)3621212409ULL)};
unsigned int b_1[4]={((unsigned int)790025424ULL),((unsigned int)2173571666ULL),((unsigned int)735488206ULL),((unsigned int)3621212409ULL)};
unsigned int a_2[4]={((unsigned int)2720195439ULL),((unsigned int)3976656209ULL),((unsigned int)648182474ULL),((unsigned int)3723933850ULL)};
unsigned int b_2[4]={((unsigned int)2720195439ULL),((unsigned int)3976656209ULL),((unsigned int)648182474ULL),((unsigned int)3723933850ULL)};
unsigned int a_3[4]={((unsigned int)3931302846ULL),((unsigned int)4170332957ULL),((unsigned int)766855897ULL),((unsigned int)106016459ULL)};
unsigned int b_3[4]={((unsigned int)3931302846ULL),((unsigned int)4170332957ULL),((unsigned int)766855897ULL),((unsigned int)106016459ULL)};
unsigned int a_4[16]={((unsigned int)1811829175ULL),((unsigned int)2426304200ULL),((unsigned int)3795684356ULL),((unsigned int)3260708091ULL),((unsigned int)1100972135ULL),((unsigned int)3778618543ULL),((unsigned int)3237748007ULL),((unsigned int)1674787510ULL),((unsigned int)1254823098ULL),((unsigned int)2691038135ULL),((unsigned int)1579068565ULL),((unsigned int)2481914089ULL),((unsigned int)1627254652ULL),((unsigned int)3813133213ULL),((unsigned int)1280377723ULL),((unsigned int)717103216ULL)};
unsigned int b_4[16]={((unsigned int)1811829175ULL),((unsigned int)2426304200ULL),((unsigned int)3795684356ULL),((unsigned int)3260708091ULL),((unsigned int)1100972135ULL),((unsigned int)3778618543ULL),((unsigned int)3237748007ULL),((unsigned int)1674787510ULL),((unsigned int)1254823098ULL),((unsigned int)2691038135ULL),((unsigned int)1579068565ULL),((unsigned int)2481914089ULL),((unsigned int)1627254652ULL),((unsigned int)3813133213ULL),((unsigned int)1280377723ULL),((unsigned int)717103216ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 69\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3775946534ULL),((unsigned int)1198199146ULL),((unsigned int)1648610236ULL),((unsigned int)2436465119ULL)};
unsigned int b_0[4]={((unsigned int)3775946534ULL),((unsigned int)1198199146ULL),((unsigned int)1648610236ULL),((unsigned int)2436465119ULL)};
unsigned int a_1[4]={((unsigned int)2926122517ULL),((unsigned int)3866588121ULL),((unsigned int)2536538887ULL),((unsigned int)2659667743ULL)};
unsigned int b_1[4]={((unsigned int)2926122517ULL),((unsigned int)3866588121ULL),((unsigned int)2536538887ULL),((unsigned int)2659667743ULL)};
unsigned int a_2[4]={((unsigned int)2436784478ULL),((unsigned int)2880758786ULL),((unsigned int)1531139571ULL),((unsigned int)1962325284ULL)};
unsigned int b_2[4]={((unsigned int)2436784478ULL),((unsigned int)2880758786ULL),((unsigned int)1531139571ULL),((unsigned int)1962325284ULL)};
unsigned int a_3[4]={((unsigned int)3847849592ULL),((unsigned int)1821692832ULL),((unsigned int)2651461384ULL),((unsigned int)3995145934ULL)};
unsigned int b_3[4]={((unsigned int)3847849592ULL),((unsigned int)1821692832ULL),((unsigned int)2651461384ULL),((unsigned int)3995145934ULL)};
unsigned int a_4[16]={((unsigned int)1419577906ULL),((unsigned int)66043597ULL),((unsigned int)1214477687ULL),((unsigned int)3774124364ULL),((unsigned int)3179686987ULL),((unsigned int)3374611518ULL),((unsigned int)2504691615ULL),((unsigned int)2208595690ULL),((unsigned int)1234989704ULL),((unsigned int)1252848999ULL),((unsigned int)411888940ULL),((unsigned int)1242774870ULL),((unsigned int)2351560416ULL),((unsigned int)3147000632ULL),((unsigned int)3920406746ULL),((unsigned int)1176458530ULL)};
unsigned int b_4[16]={((unsigned int)1419577906ULL),((unsigned int)66043597ULL),((unsigned int)1214477687ULL),((unsigned int)3774124364ULL),((unsigned int)3179686987ULL),((unsigned int)3374611518ULL),((unsigned int)2504691615ULL),((unsigned int)2208595690ULL),((unsigned int)1234989704ULL),((unsigned int)1252848999ULL),((unsigned int)411888940ULL),((unsigned int)1242774870ULL),((unsigned int)2351560416ULL),((unsigned int)3147000632ULL),((unsigned int)3920406746ULL),((unsigned int)1176458530ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 70\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)987094997ULL),((unsigned int)792587057ULL),((unsigned int)3886234529ULL),((unsigned int)1576939902ULL)};
unsigned int b_0[4]={((unsigned int)987094997ULL),((unsigned int)792587057ULL),((unsigned int)3886234529ULL),((unsigned int)1576939902ULL)};
unsigned int a_1[4]={((unsigned int)1870707989ULL),((unsigned int)282705474ULL),((unsigned int)571785254ULL),((unsigned int)1934197360ULL)};
unsigned int b_1[4]={((unsigned int)1870707989ULL),((unsigned int)282705474ULL),((unsigned int)571785254ULL),((unsigned int)1934197360ULL)};
unsigned int a_2[4]={((unsigned int)3886519892ULL),((unsigned int)4087665936ULL),((unsigned int)1514307312ULL),((unsigned int)2536754501ULL)};
unsigned int b_2[4]={((unsigned int)3886519892ULL),((unsigned int)4087665936ULL),((unsigned int)1514307312ULL),((unsigned int)2536754501ULL)};
unsigned int a_3[4]={((unsigned int)895150909ULL),((unsigned int)3135952214ULL),((unsigned int)4201891597ULL),((unsigned int)2605089288ULL)};
unsigned int b_3[4]={((unsigned int)895150909ULL),((unsigned int)3135952214ULL),((unsigned int)4201891597ULL),((unsigned int)2605089288ULL)};
unsigned int a_4[16]={((unsigned int)2232977051ULL),((unsigned int)2777030424ULL),((unsigned int)1169128683ULL),((unsigned int)2306989367ULL),((unsigned int)569973663ULL),((unsigned int)702571850ULL),((unsigned int)3082594686ULL),((unsigned int)3354412161ULL),((unsigned int)2538484470ULL),((unsigned int)1620136955ULL),((unsigned int)2815520759ULL),((unsigned int)2408603672ULL),((unsigned int)2412762227ULL),((unsigned int)4153510877ULL),((unsigned int)477342551ULL),((unsigned int)1212654328ULL)};
unsigned int b_4[16]={((unsigned int)2232977051ULL),((unsigned int)2777030424ULL),((unsigned int)1169128683ULL),((unsigned int)2306989367ULL),((unsigned int)569973663ULL),((unsigned int)702571850ULL),((unsigned int)3082594686ULL),((unsigned int)3354412161ULL),((unsigned int)2538484470ULL),((unsigned int)1620136955ULL),((unsigned int)2815520759ULL),((unsigned int)2408603672ULL),((unsigned int)2412762227ULL),((unsigned int)4153510877ULL),((unsigned int)477342551ULL),((unsigned int)1212654328ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 71\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2467043075ULL),((unsigned int)1164408472ULL),((unsigned int)2463834008ULL),((unsigned int)1738980761ULL)};
unsigned int b_0[4]={((unsigned int)2467043075ULL),((unsigned int)1164408472ULL),((unsigned int)2463834008ULL),((unsigned int)1738980761ULL)};
unsigned int a_1[4]={((unsigned int)1376793455ULL),((unsigned int)575610012ULL),((unsigned int)1723930106ULL),((unsigned int)1076349398ULL)};
unsigned int b_1[4]={((unsigned int)1376793455ULL),((unsigned int)575610012ULL),((unsigned int)1723930106ULL),((unsigned int)1076349398ULL)};
unsigned int a_2[4]={((unsigned int)4142462600ULL),((unsigned int)206207546ULL),((unsigned int)1466449209ULL),((unsigned int)3734374480ULL)};
unsigned int b_2[4]={((unsigned int)4142462600ULL),((unsigned int)206207546ULL),((unsigned int)1466449209ULL),((unsigned int)3734374480ULL)};
unsigned int a_3[4]={((unsigned int)1103837907ULL),((unsigned int)167773870ULL),((unsigned int)1172984639ULL),((unsigned int)1050416595ULL)};
unsigned int b_3[4]={((unsigned int)1103837907ULL),((unsigned int)167773870ULL),((unsigned int)1172984639ULL),((unsigned int)1050416595ULL)};
unsigned int a_4[16]={((unsigned int)1498191869ULL),((unsigned int)2100193684ULL),((unsigned int)725987581ULL),((unsigned int)4156775717ULL),((unsigned int)1771962341ULL),((unsigned int)4026283434ULL),((unsigned int)845141959ULL),((unsigned int)3275834736ULL),((unsigned int)2201355525ULL),((unsigned int)88841430ULL),((unsigned int)3196425692ULL),((unsigned int)319084146ULL),((unsigned int)1110829309ULL),((unsigned int)3055619151ULL),((unsigned int)860008726ULL),((unsigned int)767323633ULL)};
unsigned int b_4[16]={((unsigned int)1498191869ULL),((unsigned int)2100193684ULL),((unsigned int)725987581ULL),((unsigned int)4156775717ULL),((unsigned int)1771962341ULL),((unsigned int)4026283434ULL),((unsigned int)845141959ULL),((unsigned int)3275834736ULL),((unsigned int)2201355525ULL),((unsigned int)88841430ULL),((unsigned int)3196425692ULL),((unsigned int)319084146ULL),((unsigned int)1110829309ULL),((unsigned int)3055619151ULL),((unsigned int)860008726ULL),((unsigned int)767323633ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 72\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3849992284ULL),((unsigned int)1614673192ULL),((unsigned int)1881853841ULL),((unsigned int)1687252460ULL)};
unsigned int b_0[4]={((unsigned int)3849992284ULL),((unsigned int)1614673192ULL),((unsigned int)1881853841ULL),((unsigned int)1687252460ULL)};
unsigned int a_1[4]={((unsigned int)3129378049ULL),((unsigned int)329112440ULL),((unsigned int)2455823160ULL),((unsigned int)1527225660ULL)};
unsigned int b_1[4]={((unsigned int)3129378049ULL),((unsigned int)329112440ULL),((unsigned int)2455823160ULL),((unsigned int)1527225660ULL)};
unsigned int a_2[4]={((unsigned int)2581002624ULL),((unsigned int)2577740782ULL),((unsigned int)2348086714ULL),((unsigned int)2891939238ULL)};
unsigned int b_2[4]={((unsigned int)2581002624ULL),((unsigned int)2577740782ULL),((unsigned int)2348086714ULL),((unsigned int)2891939238ULL)};
unsigned int a_3[4]={((unsigned int)2162282774ULL),((unsigned int)3937857241ULL),((unsigned int)2932326373ULL),((unsigned int)1115354431ULL)};
unsigned int b_3[4]={((unsigned int)2162282774ULL),((unsigned int)3937857241ULL),((unsigned int)2932326373ULL),((unsigned int)1115354431ULL)};
unsigned int a_4[16]={((unsigned int)3074773154ULL),((unsigned int)250213997ULL),((unsigned int)1032901710ULL),((unsigned int)1845159566ULL),((unsigned int)131264481ULL),((unsigned int)2716230365ULL),((unsigned int)2632791989ULL),((unsigned int)3851203704ULL),((unsigned int)183837789ULL),((unsigned int)1669761440ULL),((unsigned int)253832113ULL),((unsigned int)380749103ULL),((unsigned int)2269164385ULL),((unsigned int)75317209ULL),((unsigned int)1856195673ULL),((unsigned int)2718229169ULL)};
unsigned int b_4[16]={((unsigned int)3074773154ULL),((unsigned int)250213997ULL),((unsigned int)1032901710ULL),((unsigned int)1845159566ULL),((unsigned int)131264481ULL),((unsigned int)2716230365ULL),((unsigned int)2632791989ULL),((unsigned int)3851203704ULL),((unsigned int)183837789ULL),((unsigned int)1669761440ULL),((unsigned int)253832113ULL),((unsigned int)380749103ULL),((unsigned int)2269164385ULL),((unsigned int)75317209ULL),((unsigned int)1856195673ULL),((unsigned int)2718229169ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 73\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)687519841ULL),((unsigned int)355370278ULL),((unsigned int)3533507364ULL),((unsigned int)141078434ULL)};
unsigned int b_0[4]={((unsigned int)687519841ULL),((unsigned int)355370278ULL),((unsigned int)3533507364ULL),((unsigned int)141078434ULL)};
unsigned int a_1[4]={((unsigned int)2665147541ULL),((unsigned int)1733073963ULL),((unsigned int)683367431ULL),((unsigned int)2734848429ULL)};
unsigned int b_1[4]={((unsigned int)2665147541ULL),((unsigned int)1733073963ULL),((unsigned int)683367431ULL),((unsigned int)2734848429ULL)};
unsigned int a_2[4]={((unsigned int)1689730507ULL),((unsigned int)4292895793ULL),((unsigned int)3098125318ULL),((unsigned int)1826331386ULL)};
unsigned int b_2[4]={((unsigned int)1689730507ULL),((unsigned int)4292895793ULL),((unsigned int)3098125318ULL),((unsigned int)1826331386ULL)};
unsigned int a_3[4]={((unsigned int)241698576ULL),((unsigned int)1578257728ULL),((unsigned int)3130407330ULL),((unsigned int)367373712ULL)};
unsigned int b_3[4]={((unsigned int)241698576ULL),((unsigned int)1578257728ULL),((unsigned int)3130407330ULL),((unsigned int)367373712ULL)};
unsigned int a_4[16]={((unsigned int)2420218806ULL),((unsigned int)4109675840ULL),((unsigned int)312109629ULL),((unsigned int)2540506586ULL),((unsigned int)1603584163ULL),((unsigned int)3476848816ULL),((unsigned int)3809030629ULL),((unsigned int)3997691751ULL),((unsigned int)1211241349ULL),((unsigned int)1946459130ULL),((unsigned int)1931217571ULL),((unsigned int)1412551146ULL),((unsigned int)2706491786ULL),((unsigned int)3467745524ULL),((unsigned int)2681252476ULL),((unsigned int)2592239660ULL)};
unsigned int b_4[16]={((unsigned int)2420218806ULL),((unsigned int)4109675840ULL),((unsigned int)312109629ULL),((unsigned int)2540506586ULL),((unsigned int)1603584163ULL),((unsigned int)3476848816ULL),((unsigned int)3809030629ULL),((unsigned int)3997691751ULL),((unsigned int)1211241349ULL),((unsigned int)1946459130ULL),((unsigned int)1931217571ULL),((unsigned int)1412551146ULL),((unsigned int)2706491786ULL),((unsigned int)3467745524ULL),((unsigned int)2681252476ULL),((unsigned int)2592239660ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 74\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3359480089ULL),((unsigned int)3181185087ULL),((unsigned int)2029097438ULL),((unsigned int)3346298354ULL)};
unsigned int b_0[4]={((unsigned int)3359480089ULL),((unsigned int)3181185087ULL),((unsigned int)2029097438ULL),((unsigned int)3346298354ULL)};
unsigned int a_1[4]={((unsigned int)244346237ULL),((unsigned int)2980635046ULL),((unsigned int)3935580873ULL),((unsigned int)584708952ULL)};
unsigned int b_1[4]={((unsigned int)244346237ULL),((unsigned int)2980635046ULL),((unsigned int)3935580873ULL),((unsigned int)584708952ULL)};
unsigned int a_2[4]={((unsigned int)1035535220ULL),((unsigned int)31511720ULL),((unsigned int)3729752028ULL),((unsigned int)1072325496ULL)};
unsigned int b_2[4]={((unsigned int)1035535220ULL),((unsigned int)31511720ULL),((unsigned int)3729752028ULL),((unsigned int)1072325496ULL)};
unsigned int a_3[4]={((unsigned int)1147704108ULL),((unsigned int)1832908455ULL),((unsigned int)692928320ULL),((unsigned int)4113933455ULL)};
unsigned int b_3[4]={((unsigned int)1147704108ULL),((unsigned int)1832908455ULL),((unsigned int)692928320ULL),((unsigned int)4113933455ULL)};
unsigned int a_4[16]={((unsigned int)470855939ULL),((unsigned int)3801415589ULL),((unsigned int)3767758968ULL),((unsigned int)908098621ULL),((unsigned int)817724352ULL),((unsigned int)807677181ULL),((unsigned int)3445330144ULL),((unsigned int)3536936685ULL),((unsigned int)3454232094ULL),((unsigned int)4063084709ULL),((unsigned int)7513115ULL),((unsigned int)1834738093ULL),((unsigned int)3812746365ULL),((unsigned int)1176427207ULL),((unsigned int)3355380860ULL),((unsigned int)392780038ULL)};
unsigned int b_4[16]={((unsigned int)470855939ULL),((unsigned int)3801415589ULL),((unsigned int)3767758968ULL),((unsigned int)908098621ULL),((unsigned int)817724352ULL),((unsigned int)807677181ULL),((unsigned int)3445330144ULL),((unsigned int)3536936685ULL),((unsigned int)3454232094ULL),((unsigned int)4063084709ULL),((unsigned int)7513115ULL),((unsigned int)1834738093ULL),((unsigned int)3812746365ULL),((unsigned int)1176427207ULL),((unsigned int)3355380860ULL),((unsigned int)392780038ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 75\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2470603094ULL),((unsigned int)2161560361ULL),((unsigned int)2682278849ULL),((unsigned int)2535346513ULL)};
unsigned int b_0[4]={((unsigned int)2470603094ULL),((unsigned int)2161560361ULL),((unsigned int)2682278849ULL),((unsigned int)2535346513ULL)};
unsigned int a_1[4]={((unsigned int)3680594254ULL),((unsigned int)4076683430ULL),((unsigned int)3268203776ULL),((unsigned int)4180949294ULL)};
unsigned int b_1[4]={((unsigned int)3680594254ULL),((unsigned int)4076683430ULL),((unsigned int)3268203776ULL),((unsigned int)4180949294ULL)};
unsigned int a_2[4]={((unsigned int)4260677457ULL),((unsigned int)201635482ULL),((unsigned int)2024024806ULL),((unsigned int)416337805ULL)};
unsigned int b_2[4]={((unsigned int)4260677457ULL),((unsigned int)201635482ULL),((unsigned int)2024024806ULL),((unsigned int)416337805ULL)};
unsigned int a_3[4]={((unsigned int)784667713ULL),((unsigned int)2624878482ULL),((unsigned int)1876365324ULL),((unsigned int)1441074354ULL)};
unsigned int b_3[4]={((unsigned int)784667713ULL),((unsigned int)2624878482ULL),((unsigned int)1876365324ULL),((unsigned int)1441074354ULL)};
unsigned int a_4[16]={((unsigned int)3692368188ULL),((unsigned int)4185834562ULL),((unsigned int)2791084943ULL),((unsigned int)1559618819ULL),((unsigned int)1558540785ULL),((unsigned int)480954532ULL),((unsigned int)2665821720ULL),((unsigned int)2831073703ULL),((unsigned int)4208570280ULL),((unsigned int)3049637693ULL),((unsigned int)291998059ULL),((unsigned int)3348308481ULL),((unsigned int)276901754ULL),((unsigned int)57410803ULL),((unsigned int)3463545275ULL),((unsigned int)959983353ULL)};
unsigned int b_4[16]={((unsigned int)3692368188ULL),((unsigned int)4185834562ULL),((unsigned int)2791084943ULL),((unsigned int)1559618819ULL),((unsigned int)1558540785ULL),((unsigned int)480954532ULL),((unsigned int)2665821720ULL),((unsigned int)2831073703ULL),((unsigned int)4208570280ULL),((unsigned int)3049637693ULL),((unsigned int)291998059ULL),((unsigned int)3348308481ULL),((unsigned int)276901754ULL),((unsigned int)57410803ULL),((unsigned int)3463545275ULL),((unsigned int)959983353ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 76\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2301210436ULL),((unsigned int)2116943920ULL),((unsigned int)587233189ULL),((unsigned int)2778910113ULL)};
unsigned int b_0[4]={((unsigned int)2301210436ULL),((unsigned int)2116943920ULL),((unsigned int)587233189ULL),((unsigned int)2778910113ULL)};
unsigned int a_1[4]={((unsigned int)3262454861ULL),((unsigned int)1865480830ULL),((unsigned int)989870537ULL),((unsigned int)1351629283ULL)};
unsigned int b_1[4]={((unsigned int)3262454861ULL),((unsigned int)1865480830ULL),((unsigned int)989870537ULL),((unsigned int)1351629283ULL)};
unsigned int a_2[4]={((unsigned int)1288444516ULL),((unsigned int)2989381873ULL),((unsigned int)3181914645ULL),((unsigned int)3258448981ULL)};
unsigned int b_2[4]={((unsigned int)1288444516ULL),((unsigned int)2989381873ULL),((unsigned int)3181914645ULL),((unsigned int)3258448981ULL)};
unsigned int a_3[4]={((unsigned int)4148578473ULL),((unsigned int)1655569213ULL),((unsigned int)970286953ULL),((unsigned int)1109779355ULL)};
unsigned int b_3[4]={((unsigned int)4148578473ULL),((unsigned int)1655569213ULL),((unsigned int)970286953ULL),((unsigned int)1109779355ULL)};
unsigned int a_4[16]={((unsigned int)158005774ULL),((unsigned int)1942363236ULL),((unsigned int)2564536268ULL),((unsigned int)4108068692ULL),((unsigned int)4080175061ULL),((unsigned int)2185138283ULL),((unsigned int)49229914ULL),((unsigned int)344052627ULL),((unsigned int)47541872ULL),((unsigned int)398217728ULL),((unsigned int)2989166812ULL),((unsigned int)3668063119ULL),((unsigned int)1874083597ULL),((unsigned int)2845890532ULL),((unsigned int)3175951000ULL),((unsigned int)3326092058ULL)};
unsigned int b_4[16]={((unsigned int)158005774ULL),((unsigned int)1942363236ULL),((unsigned int)2564536268ULL),((unsigned int)4108068692ULL),((unsigned int)4080175061ULL),((unsigned int)2185138283ULL),((unsigned int)49229914ULL),((unsigned int)344052627ULL),((unsigned int)47541872ULL),((unsigned int)398217728ULL),((unsigned int)2989166812ULL),((unsigned int)3668063119ULL),((unsigned int)1874083597ULL),((unsigned int)2845890532ULL),((unsigned int)3175951000ULL),((unsigned int)3326092058ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 77\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3360957116ULL),((unsigned int)174350697ULL),((unsigned int)675611496ULL),((unsigned int)2253489520ULL)};
unsigned int b_0[4]={((unsigned int)3360957116ULL),((unsigned int)174350697ULL),((unsigned int)675611496ULL),((unsigned int)2253489520ULL)};
unsigned int a_1[4]={((unsigned int)4292453912ULL),((unsigned int)2632551895ULL),((unsigned int)3645325137ULL),((unsigned int)4293918373ULL)};
unsigned int b_1[4]={((unsigned int)4292453912ULL),((unsigned int)2632551895ULL),((unsigned int)3645325137ULL),((unsigned int)4293918373ULL)};
unsigned int a_2[4]={((unsigned int)3072102379ULL),((unsigned int)2461999694ULL),((unsigned int)81248848ULL),((unsigned int)3903783000ULL)};
unsigned int b_2[4]={((unsigned int)3072102379ULL),((unsigned int)2461999694ULL),((unsigned int)81248848ULL),((unsigned int)3903783000ULL)};
unsigned int a_3[4]={((unsigned int)3147538508ULL),((unsigned int)1625234628ULL),((unsigned int)1924537068ULL),((unsigned int)4086906487ULL)};
unsigned int b_3[4]={((unsigned int)3147538508ULL),((unsigned int)1625234628ULL),((unsigned int)1924537068ULL),((unsigned int)4086906487ULL)};
unsigned int a_4[16]={((unsigned int)2434346667ULL),((unsigned int)517037307ULL),((unsigned int)2250465674ULL),((unsigned int)1134877136ULL),((unsigned int)1596656556ULL),((unsigned int)4164906818ULL),((unsigned int)2375103742ULL),((unsigned int)3903599022ULL),((unsigned int)3564844987ULL),((unsigned int)3244460656ULL),((unsigned int)1169930762ULL),((unsigned int)2950886672ULL),((unsigned int)616027243ULL),((unsigned int)3319584613ULL),((unsigned int)1325144877ULL),((unsigned int)384244412ULL)};
unsigned int b_4[16]={((unsigned int)2434346667ULL),((unsigned int)517037307ULL),((unsigned int)2250465674ULL),((unsigned int)1134877136ULL),((unsigned int)1596656556ULL),((unsigned int)4164906818ULL),((unsigned int)2375103742ULL),((unsigned int)3903599022ULL),((unsigned int)3564844987ULL),((unsigned int)3244460656ULL),((unsigned int)1169930762ULL),((unsigned int)2950886672ULL),((unsigned int)616027243ULL),((unsigned int)3319584613ULL),((unsigned int)1325144877ULL),((unsigned int)384244412ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 78\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2522196945ULL),((unsigned int)1405211117ULL),((unsigned int)3874084579ULL),((unsigned int)4125217225ULL)};
unsigned int b_0[4]={((unsigned int)2522196945ULL),((unsigned int)1405211117ULL),((unsigned int)3874084579ULL),((unsigned int)4125217225ULL)};
unsigned int a_1[4]={((unsigned int)2814292946ULL),((unsigned int)1149752742ULL),((unsigned int)650554667ULL),((unsigned int)1780231082ULL)};
unsigned int b_1[4]={((unsigned int)2814292946ULL),((unsigned int)1149752742ULL),((unsigned int)650554667ULL),((unsigned int)1780231082ULL)};
unsigned int a_2[4]={((unsigned int)1518877688ULL),((unsigned int)272318041ULL),((unsigned int)3902093778ULL),((unsigned int)553657284ULL)};
unsigned int b_2[4]={((unsigned int)1518877688ULL),((unsigned int)272318041ULL),((unsigned int)3902093778ULL),((unsigned int)553657284ULL)};
unsigned int a_3[4]={((unsigned int)358379855ULL),((unsigned int)1159302362ULL),((unsigned int)3344317390ULL),((unsigned int)2451906808ULL)};
unsigned int b_3[4]={((unsigned int)358379855ULL),((unsigned int)1159302362ULL),((unsigned int)3344317390ULL),((unsigned int)2451906808ULL)};
unsigned int a_4[16]={((unsigned int)2623037998ULL),((unsigned int)1244816256ULL),((unsigned int)1690966747ULL),((unsigned int)4085378387ULL),((unsigned int)2911061874ULL),((unsigned int)3986624338ULL),((unsigned int)377436951ULL),((unsigned int)4184056961ULL),((unsigned int)4012714771ULL),((unsigned int)1080413506ULL),((unsigned int)594956843ULL),((unsigned int)1281732137ULL),((unsigned int)4179454122ULL),((unsigned int)3431934962ULL),((unsigned int)3978490290ULL),((unsigned int)3577399200ULL)};
unsigned int b_4[16]={((unsigned int)2623037998ULL),((unsigned int)1244816256ULL),((unsigned int)1690966747ULL),((unsigned int)4085378387ULL),((unsigned int)2911061874ULL),((unsigned int)3986624338ULL),((unsigned int)377436951ULL),((unsigned int)4184056961ULL),((unsigned int)4012714771ULL),((unsigned int)1080413506ULL),((unsigned int)594956843ULL),((unsigned int)1281732137ULL),((unsigned int)4179454122ULL),((unsigned int)3431934962ULL),((unsigned int)3978490290ULL),((unsigned int)3577399200ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 79\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2505093703ULL),((unsigned int)1979250610ULL),((unsigned int)3974509139ULL),((unsigned int)3292754116ULL)};
unsigned int b_0[4]={((unsigned int)2505093703ULL),((unsigned int)1979250610ULL),((unsigned int)3974509139ULL),((unsigned int)3292754116ULL)};
unsigned int a_1[4]={((unsigned int)186253758ULL),((unsigned int)2786269384ULL),((unsigned int)939776825ULL),((unsigned int)1489616644ULL)};
unsigned int b_1[4]={((unsigned int)186253758ULL),((unsigned int)2786269384ULL),((unsigned int)939776825ULL),((unsigned int)1489616644ULL)};
unsigned int a_2[4]={((unsigned int)3898339151ULL),((unsigned int)1751352808ULL),((unsigned int)139591910ULL),((unsigned int)2568738450ULL)};
unsigned int b_2[4]={((unsigned int)3898339151ULL),((unsigned int)1751352808ULL),((unsigned int)139591910ULL),((unsigned int)2568738450ULL)};
unsigned int a_3[4]={((unsigned int)458289235ULL),((unsigned int)3656339513ULL),((unsigned int)262546116ULL),((unsigned int)2712925821ULL)};
unsigned int b_3[4]={((unsigned int)458289235ULL),((unsigned int)3656339513ULL),((unsigned int)262546116ULL),((unsigned int)2712925821ULL)};
unsigned int a_4[16]={((unsigned int)118936445ULL),((unsigned int)3410651376ULL),((unsigned int)3805650559ULL),((unsigned int)2315518664ULL),((unsigned int)3570513587ULL),((unsigned int)226895757ULL),((unsigned int)2531054017ULL),((unsigned int)3912897275ULL),((unsigned int)4001813548ULL),((unsigned int)2987000625ULL),((unsigned int)3965505011ULL),((unsigned int)3559380594ULL),((unsigned int)2945062527ULL),((unsigned int)1596532120ULL),((unsigned int)2171140203ULL),((unsigned int)914788268ULL)};
unsigned int b_4[16]={((unsigned int)118936445ULL),((unsigned int)3410651376ULL),((unsigned int)3805650559ULL),((unsigned int)2315518664ULL),((unsigned int)3570513587ULL),((unsigned int)226895757ULL),((unsigned int)2531054017ULL),((unsigned int)3912897275ULL),((unsigned int)4001813548ULL),((unsigned int)2987000625ULL),((unsigned int)3965505011ULL),((unsigned int)3559380594ULL),((unsigned int)2945062527ULL),((unsigned int)1596532120ULL),((unsigned int)2171140203ULL),((unsigned int)914788268ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 80\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1642348803ULL),((unsigned int)1443820429ULL),((unsigned int)220775756ULL),((unsigned int)2443454645ULL)};
unsigned int b_0[4]={((unsigned int)1642348803ULL),((unsigned int)1443820429ULL),((unsigned int)220775756ULL),((unsigned int)2443454645ULL)};
unsigned int a_1[4]={((unsigned int)642547343ULL),((unsigned int)4217016738ULL),((unsigned int)3996633073ULL),((unsigned int)2660166606ULL)};
unsigned int b_1[4]={((unsigned int)642547343ULL),((unsigned int)4217016738ULL),((unsigned int)3996633073ULL),((unsigned int)2660166606ULL)};
unsigned int a_2[4]={((unsigned int)523316052ULL),((unsigned int)2869569241ULL),((unsigned int)2382176605ULL),((unsigned int)1206756913ULL)};
unsigned int b_2[4]={((unsigned int)523316052ULL),((unsigned int)2869569241ULL),((unsigned int)2382176605ULL),((unsigned int)1206756913ULL)};
unsigned int a_3[4]={((unsigned int)807701831ULL),((unsigned int)3826629170ULL),((unsigned int)517911890ULL),((unsigned int)115565055ULL)};
unsigned int b_3[4]={((unsigned int)807701831ULL),((unsigned int)3826629170ULL),((unsigned int)517911890ULL),((unsigned int)115565055ULL)};
unsigned int a_4[16]={((unsigned int)2873537309ULL),((unsigned int)1565489460ULL),((unsigned int)4230017977ULL),((unsigned int)2984040279ULL),((unsigned int)3752181297ULL),((unsigned int)4084382406ULL),((unsigned int)464975856ULL),((unsigned int)2776700920ULL),((unsigned int)837485446ULL),((unsigned int)2181624119ULL),((unsigned int)984614446ULL),((unsigned int)1333939962ULL),((unsigned int)3419564116ULL),((unsigned int)3667748581ULL),((unsigned int)1510508370ULL),((unsigned int)1088332771ULL)};
unsigned int b_4[16]={((unsigned int)2873537309ULL),((unsigned int)1565489460ULL),((unsigned int)4230017977ULL),((unsigned int)2984040279ULL),((unsigned int)3752181297ULL),((unsigned int)4084382406ULL),((unsigned int)464975856ULL),((unsigned int)2776700920ULL),((unsigned int)837485446ULL),((unsigned int)2181624119ULL),((unsigned int)984614446ULL),((unsigned int)1333939962ULL),((unsigned int)3419564116ULL),((unsigned int)3667748581ULL),((unsigned int)1510508370ULL),((unsigned int)1088332771ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 81\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4123393376ULL),((unsigned int)564851152ULL),((unsigned int)1858529107ULL),((unsigned int)2399044039ULL)};
unsigned int b_0[4]={((unsigned int)4123393376ULL),((unsigned int)564851152ULL),((unsigned int)1858529107ULL),((unsigned int)2399044039ULL)};
unsigned int a_1[4]={((unsigned int)155445619ULL),((unsigned int)3828210462ULL),((unsigned int)345616295ULL),((unsigned int)1141679700ULL)};
unsigned int b_1[4]={((unsigned int)155445619ULL),((unsigned int)3828210462ULL),((unsigned int)345616295ULL),((unsigned int)1141679700ULL)};
unsigned int a_2[4]={((unsigned int)2214930258ULL),((unsigned int)2549348134ULL),((unsigned int)3279701093ULL),((unsigned int)1085090034ULL)};
unsigned int b_2[4]={((unsigned int)2214930258ULL),((unsigned int)2549348134ULL),((unsigned int)3279701093ULL),((unsigned int)1085090034ULL)};
unsigned int a_3[4]={((unsigned int)949781203ULL),((unsigned int)2036755117ULL),((unsigned int)3823237766ULL),((unsigned int)73268706ULL)};
unsigned int b_3[4]={((unsigned int)949781203ULL),((unsigned int)2036755117ULL),((unsigned int)3823237766ULL),((unsigned int)73268706ULL)};
unsigned int a_4[16]={((unsigned int)2849752786ULL),((unsigned int)3345875649ULL),((unsigned int)1736897627ULL),((unsigned int)1142964261ULL),((unsigned int)4069454611ULL),((unsigned int)2230644655ULL),((unsigned int)2174716691ULL),((unsigned int)3305606472ULL),((unsigned int)1011319072ULL),((unsigned int)1480441608ULL),((unsigned int)2902573626ULL),((unsigned int)1120267214ULL),((unsigned int)2925411563ULL),((unsigned int)3398484527ULL),((unsigned int)2460230878ULL),((unsigned int)4082237400ULL)};
unsigned int b_4[16]={((unsigned int)2849752786ULL),((unsigned int)3345875649ULL),((unsigned int)1736897627ULL),((unsigned int)1142964261ULL),((unsigned int)4069454611ULL),((unsigned int)2230644655ULL),((unsigned int)2174716691ULL),((unsigned int)3305606472ULL),((unsigned int)1011319072ULL),((unsigned int)1480441608ULL),((unsigned int)2902573626ULL),((unsigned int)1120267214ULL),((unsigned int)2925411563ULL),((unsigned int)3398484527ULL),((unsigned int)2460230878ULL),((unsigned int)4082237400ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 82\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2281859337ULL),((unsigned int)1824430365ULL),((unsigned int)4189200323ULL),((unsigned int)3939290732ULL)};
unsigned int b_0[4]={((unsigned int)2281859337ULL),((unsigned int)1824430365ULL),((unsigned int)4189200323ULL),((unsigned int)3939290732ULL)};
unsigned int a_1[4]={((unsigned int)802120454ULL),((unsigned int)2810587218ULL),((unsigned int)748373276ULL),((unsigned int)1659720070ULL)};
unsigned int b_1[4]={((unsigned int)802120454ULL),((unsigned int)2810587218ULL),((unsigned int)748373276ULL),((unsigned int)1659720070ULL)};
unsigned int a_2[4]={((unsigned int)659038423ULL),((unsigned int)4195343134ULL),((unsigned int)4048180011ULL),((unsigned int)496022790ULL)};
unsigned int b_2[4]={((unsigned int)659038423ULL),((unsigned int)4195343134ULL),((unsigned int)4048180011ULL),((unsigned int)496022790ULL)};
unsigned int a_3[4]={((unsigned int)2936688000ULL),((unsigned int)678703153ULL),((unsigned int)3094948926ULL),((unsigned int)3254787518ULL)};
unsigned int b_3[4]={((unsigned int)2936688000ULL),((unsigned int)678703153ULL),((unsigned int)3094948926ULL),((unsigned int)3254787518ULL)};
unsigned int a_4[16]={((unsigned int)3286674215ULL),((unsigned int)1628522107ULL),((unsigned int)3991546312ULL),((unsigned int)1765571010ULL),((unsigned int)2677255634ULL),((unsigned int)3492717137ULL),((unsigned int)304770158ULL),((unsigned int)1437879316ULL),((unsigned int)2021582608ULL),((unsigned int)2072672785ULL),((unsigned int)785074808ULL),((unsigned int)1949287642ULL),((unsigned int)599584842ULL),((unsigned int)3405073896ULL),((unsigned int)1644687366ULL),((unsigned int)3506111619ULL)};
unsigned int b_4[16]={((unsigned int)3286674215ULL),((unsigned int)1628522107ULL),((unsigned int)3991546312ULL),((unsigned int)1765571010ULL),((unsigned int)2677255634ULL),((unsigned int)3492717137ULL),((unsigned int)304770158ULL),((unsigned int)1437879316ULL),((unsigned int)2021582608ULL),((unsigned int)2072672785ULL),((unsigned int)785074808ULL),((unsigned int)1949287642ULL),((unsigned int)599584842ULL),((unsigned int)3405073896ULL),((unsigned int)1644687366ULL),((unsigned int)3506111619ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 83\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3913880727ULL),((unsigned int)3576860748ULL),((unsigned int)337614753ULL),((unsigned int)3701442885ULL)};
unsigned int b_0[4]={((unsigned int)3913880727ULL),((unsigned int)3576860748ULL),((unsigned int)337614753ULL),((unsigned int)3701442885ULL)};
unsigned int a_1[4]={((unsigned int)351896424ULL),((unsigned int)4065874817ULL),((unsigned int)2020946055ULL),((unsigned int)4211348540ULL)};
unsigned int b_1[4]={((unsigned int)351896424ULL),((unsigned int)4065874817ULL),((unsigned int)2020946055ULL),((unsigned int)4211348540ULL)};
unsigned int a_2[4]={((unsigned int)215622745ULL),((unsigned int)3608525628ULL),((unsigned int)4042940561ULL),((unsigned int)2584947922ULL)};
unsigned int b_2[4]={((unsigned int)215622745ULL),((unsigned int)3608525628ULL),((unsigned int)4042940561ULL),((unsigned int)2584947922ULL)};
unsigned int a_3[4]={((unsigned int)2656440668ULL),((unsigned int)468122560ULL),((unsigned int)194836045ULL),((unsigned int)4262836124ULL)};
unsigned int b_3[4]={((unsigned int)2656440668ULL),((unsigned int)468122560ULL),((unsigned int)194836045ULL),((unsigned int)4262836124ULL)};
unsigned int a_4[16]={((unsigned int)2195198473ULL),((unsigned int)684299438ULL),((unsigned int)748366693ULL),((unsigned int)2332807ULL),((unsigned int)197870851ULL),((unsigned int)1889341103ULL),((unsigned int)4071132215ULL),((unsigned int)2308385254ULL),((unsigned int)3661889731ULL),((unsigned int)2214157305ULL),((unsigned int)3984735139ULL),((unsigned int)1646428548ULL),((unsigned int)773464054ULL),((unsigned int)85773112ULL),((unsigned int)789446971ULL),((unsigned int)655721808ULL)};
unsigned int b_4[16]={((unsigned int)2195198473ULL),((unsigned int)684299438ULL),((unsigned int)748366693ULL),((unsigned int)2332807ULL),((unsigned int)197870851ULL),((unsigned int)1889341103ULL),((unsigned int)4071132215ULL),((unsigned int)2308385254ULL),((unsigned int)3661889731ULL),((unsigned int)2214157305ULL),((unsigned int)3984735139ULL),((unsigned int)1646428548ULL),((unsigned int)773464054ULL),((unsigned int)85773112ULL),((unsigned int)789446971ULL),((unsigned int)655721808ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 84\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3742408819ULL),((unsigned int)3938355857ULL),((unsigned int)1057797455ULL),((unsigned int)1091704901ULL)};
unsigned int b_0[4]={((unsigned int)3742408819ULL),((unsigned int)3938355857ULL),((unsigned int)1057797455ULL),((unsigned int)1091704901ULL)};
unsigned int a_1[4]={((unsigned int)2801867397ULL),((unsigned int)754667758ULL),((unsigned int)2657092143ULL),((unsigned int)3095364997ULL)};
unsigned int b_1[4]={((unsigned int)2801867397ULL),((unsigned int)754667758ULL),((unsigned int)2657092143ULL),((unsigned int)3095364997ULL)};
unsigned int a_2[4]={((unsigned int)3399022751ULL),((unsigned int)2890511308ULL),((unsigned int)2615985629ULL),((unsigned int)432749183ULL)};
unsigned int b_2[4]={((unsigned int)3399022751ULL),((unsigned int)2890511308ULL),((unsigned int)2615985629ULL),((unsigned int)432749183ULL)};
unsigned int a_3[4]={((unsigned int)1891572535ULL),((unsigned int)315519731ULL),((unsigned int)3464439623ULL),((unsigned int)2733660454ULL)};
unsigned int b_3[4]={((unsigned int)1891572535ULL),((unsigned int)315519731ULL),((unsigned int)3464439623ULL),((unsigned int)2733660454ULL)};
unsigned int a_4[16]={((unsigned int)3264497930ULL),((unsigned int)3955862046ULL),((unsigned int)3343067133ULL),((unsigned int)2170286991ULL),((unsigned int)626865895ULL),((unsigned int)3802196459ULL),((unsigned int)2701941692ULL),((unsigned int)3849432461ULL),((unsigned int)248192322ULL),((unsigned int)3966602995ULL),((unsigned int)228014002ULL),((unsigned int)748416628ULL),((unsigned int)787483734ULL),((unsigned int)221364260ULL),((unsigned int)2404734803ULL),((unsigned int)1737974675ULL)};
unsigned int b_4[16]={((unsigned int)3264497930ULL),((unsigned int)3955862046ULL),((unsigned int)3343067133ULL),((unsigned int)2170286991ULL),((unsigned int)626865895ULL),((unsigned int)3802196459ULL),((unsigned int)2701941692ULL),((unsigned int)3849432461ULL),((unsigned int)248192322ULL),((unsigned int)3966602995ULL),((unsigned int)228014002ULL),((unsigned int)748416628ULL),((unsigned int)787483734ULL),((unsigned int)221364260ULL),((unsigned int)2404734803ULL),((unsigned int)1737974675ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 85\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1724565074ULL),((unsigned int)2957495515ULL),((unsigned int)1383917379ULL),((unsigned int)1708751859ULL)};
unsigned int b_0[4]={((unsigned int)1724565074ULL),((unsigned int)2957495515ULL),((unsigned int)1383917379ULL),((unsigned int)1708751859ULL)};
unsigned int a_1[4]={((unsigned int)676242239ULL),((unsigned int)2113320825ULL),((unsigned int)124825116ULL),((unsigned int)3964692195ULL)};
unsigned int b_1[4]={((unsigned int)676242239ULL),((unsigned int)2113320825ULL),((unsigned int)124825116ULL),((unsigned int)3964692195ULL)};
unsigned int a_2[4]={((unsigned int)3797360843ULL),((unsigned int)929007358ULL),((unsigned int)3724437330ULL),((unsigned int)4149386615ULL)};
unsigned int b_2[4]={((unsigned int)3797360843ULL),((unsigned int)929007358ULL),((unsigned int)3724437330ULL),((unsigned int)4149386615ULL)};
unsigned int a_3[4]={((unsigned int)3540552342ULL),((unsigned int)1410286677ULL),((unsigned int)510001209ULL),((unsigned int)1395158622ULL)};
unsigned int b_3[4]={((unsigned int)3540552342ULL),((unsigned int)1410286677ULL),((unsigned int)510001209ULL),((unsigned int)1395158622ULL)};
unsigned int a_4[16]={((unsigned int)2631746992ULL),((unsigned int)1601074625ULL),((unsigned int)1402579852ULL),((unsigned int)3792309539ULL),((unsigned int)3587895097ULL),((unsigned int)370910467ULL),((unsigned int)3998121624ULL),((unsigned int)2567187169ULL),((unsigned int)3756258993ULL),((unsigned int)707503303ULL),((unsigned int)1636407800ULL),((unsigned int)963221608ULL),((unsigned int)4126156103ULL),((unsigned int)3220231341ULL),((unsigned int)2078561239ULL),((unsigned int)3993170024ULL)};
unsigned int b_4[16]={((unsigned int)2631746992ULL),((unsigned int)1601074625ULL),((unsigned int)1402579852ULL),((unsigned int)3792309539ULL),((unsigned int)3587895097ULL),((unsigned int)370910467ULL),((unsigned int)3998121624ULL),((unsigned int)2567187169ULL),((unsigned int)3756258993ULL),((unsigned int)707503303ULL),((unsigned int)1636407800ULL),((unsigned int)963221608ULL),((unsigned int)4126156103ULL),((unsigned int)3220231341ULL),((unsigned int)2078561239ULL),((unsigned int)3993170024ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 86\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1684118335ULL),((unsigned int)3058272302ULL),((unsigned int)543206994ULL),((unsigned int)213404767ULL)};
unsigned int b_0[4]={((unsigned int)1684118335ULL),((unsigned int)3058272302ULL),((unsigned int)543206994ULL),((unsigned int)213404767ULL)};
unsigned int a_1[4]={((unsigned int)1580905900ULL),((unsigned int)258735393ULL),((unsigned int)612886334ULL),((unsigned int)468566440ULL)};
unsigned int b_1[4]={((unsigned int)1580905900ULL),((unsigned int)258735393ULL),((unsigned int)612886334ULL),((unsigned int)468566440ULL)};
unsigned int a_2[4]={((unsigned int)3262807837ULL),((unsigned int)1588535777ULL),((unsigned int)2262097652ULL),((unsigned int)3075702148ULL)};
unsigned int b_2[4]={((unsigned int)3262807837ULL),((unsigned int)1588535777ULL),((unsigned int)2262097652ULL),((unsigned int)3075702148ULL)};
unsigned int a_3[4]={((unsigned int)3545215167ULL),((unsigned int)669225456ULL),((unsigned int)1936486329ULL),((unsigned int)3648169854ULL)};
unsigned int b_3[4]={((unsigned int)3545215167ULL),((unsigned int)669225456ULL),((unsigned int)1936486329ULL),((unsigned int)3648169854ULL)};
unsigned int a_4[16]={((unsigned int)2925945658ULL),((unsigned int)4280067910ULL),((unsigned int)1751593318ULL),((unsigned int)738313332ULL),((unsigned int)3448063658ULL),((unsigned int)603707370ULL),((unsigned int)765940162ULL),((unsigned int)2227853625ULL),((unsigned int)1517913075ULL),((unsigned int)3876368238ULL),((unsigned int)947798002ULL),((unsigned int)4168811904ULL),((unsigned int)1590551903ULL),((unsigned int)2872163002ULL),((unsigned int)1612359327ULL),((unsigned int)3557564896ULL)};
unsigned int b_4[16]={((unsigned int)2925945658ULL),((unsigned int)4280067910ULL),((unsigned int)1751593318ULL),((unsigned int)738313332ULL),((unsigned int)3448063658ULL),((unsigned int)603707370ULL),((unsigned int)765940162ULL),((unsigned int)2227853625ULL),((unsigned int)1517913075ULL),((unsigned int)3876368238ULL),((unsigned int)947798002ULL),((unsigned int)4168811904ULL),((unsigned int)1590551903ULL),((unsigned int)2872163002ULL),((unsigned int)1612359327ULL),((unsigned int)3557564896ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 87\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2474526627ULL),((unsigned int)262851453ULL),((unsigned int)2548238569ULL),((unsigned int)447511628ULL)};
unsigned int b_0[4]={((unsigned int)2474526627ULL),((unsigned int)262851453ULL),((unsigned int)2548238569ULL),((unsigned int)447511628ULL)};
unsigned int a_1[4]={((unsigned int)784684429ULL),((unsigned int)1849798100ULL),((unsigned int)2374593214ULL),((unsigned int)4015476597ULL)};
unsigned int b_1[4]={((unsigned int)784684429ULL),((unsigned int)1849798100ULL),((unsigned int)2374593214ULL),((unsigned int)4015476597ULL)};
unsigned int a_2[4]={((unsigned int)1272971878ULL),((unsigned int)4242293628ULL),((unsigned int)1744668468ULL),((unsigned int)3755168803ULL)};
unsigned int b_2[4]={((unsigned int)1272971878ULL),((unsigned int)4242293628ULL),((unsigned int)1744668468ULL),((unsigned int)3755168803ULL)};
unsigned int a_3[4]={((unsigned int)2951001455ULL),((unsigned int)2288553598ULL),((unsigned int)4277546942ULL),((unsigned int)3747245462ULL)};
unsigned int b_3[4]={((unsigned int)2951001455ULL),((unsigned int)2288553598ULL),((unsigned int)4277546942ULL),((unsigned int)3747245462ULL)};
unsigned int a_4[16]={((unsigned int)3750887482ULL),((unsigned int)1433985034ULL),((unsigned int)4051492172ULL),((unsigned int)2862539528ULL),((unsigned int)1319660535ULL),((unsigned int)4109653900ULL),((unsigned int)1031570063ULL),((unsigned int)3671090736ULL),((unsigned int)2504305030ULL),((unsigned int)787566855ULL),((unsigned int)3921154702ULL),((unsigned int)1596826794ULL),((unsigned int)2036177990ULL),((unsigned int)725685194ULL),((unsigned int)239493779ULL),((unsigned int)1416814309ULL)};
unsigned int b_4[16]={((unsigned int)3750887482ULL),((unsigned int)1433985034ULL),((unsigned int)4051492172ULL),((unsigned int)2862539528ULL),((unsigned int)1319660535ULL),((unsigned int)4109653900ULL),((unsigned int)1031570063ULL),((unsigned int)3671090736ULL),((unsigned int)2504305030ULL),((unsigned int)787566855ULL),((unsigned int)3921154702ULL),((unsigned int)1596826794ULL),((unsigned int)2036177990ULL),((unsigned int)725685194ULL),((unsigned int)239493779ULL),((unsigned int)1416814309ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 88\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)431176858ULL),((unsigned int)1890748617ULL),((unsigned int)1965485045ULL),((unsigned int)2112550059ULL)};
unsigned int b_0[4]={((unsigned int)431176858ULL),((unsigned int)1890748617ULL),((unsigned int)1965485045ULL),((unsigned int)2112550059ULL)};
unsigned int a_1[4]={((unsigned int)1588621251ULL),((unsigned int)3226763491ULL),((unsigned int)3544655750ULL),((unsigned int)3584210365ULL)};
unsigned int b_1[4]={((unsigned int)1588621251ULL),((unsigned int)3226763491ULL),((unsigned int)3544655750ULL),((unsigned int)3584210365ULL)};
unsigned int a_2[4]={((unsigned int)3627438094ULL),((unsigned int)1261058990ULL),((unsigned int)63195646ULL),((unsigned int)3809994642ULL)};
unsigned int b_2[4]={((unsigned int)3627438094ULL),((unsigned int)1261058990ULL),((unsigned int)63195646ULL),((unsigned int)3809994642ULL)};
unsigned int a_3[4]={((unsigned int)1287734106ULL),((unsigned int)2911024126ULL),((unsigned int)1932687911ULL),((unsigned int)599287487ULL)};
unsigned int b_3[4]={((unsigned int)1287734106ULL),((unsigned int)2911024126ULL),((unsigned int)1932687911ULL),((unsigned int)599287487ULL)};
unsigned int a_4[16]={((unsigned int)3043220002ULL),((unsigned int)408695889ULL),((unsigned int)3179061828ULL),((unsigned int)506598210ULL),((unsigned int)1193071477ULL),((unsigned int)2758079658ULL),((unsigned int)3735889379ULL),((unsigned int)3513341245ULL),((unsigned int)1598230195ULL),((unsigned int)278147493ULL),((unsigned int)4064335676ULL),((unsigned int)3719652387ULL),((unsigned int)3718108648ULL),((unsigned int)2159430634ULL),((unsigned int)2922405630ULL),((unsigned int)4026374431ULL)};
unsigned int b_4[16]={((unsigned int)3043220002ULL),((unsigned int)408695889ULL),((unsigned int)3179061828ULL),((unsigned int)506598210ULL),((unsigned int)1193071477ULL),((unsigned int)2758079658ULL),((unsigned int)3735889379ULL),((unsigned int)3513341245ULL),((unsigned int)1598230195ULL),((unsigned int)278147493ULL),((unsigned int)4064335676ULL),((unsigned int)3719652387ULL),((unsigned int)3718108648ULL),((unsigned int)2159430634ULL),((unsigned int)2922405630ULL),((unsigned int)4026374431ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 89\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1243517356ULL),((unsigned int)2190009245ULL),((unsigned int)1125477201ULL),((unsigned int)1960538486ULL)};
unsigned int b_0[4]={((unsigned int)1243517356ULL),((unsigned int)2190009245ULL),((unsigned int)1125477201ULL),((unsigned int)1960538486ULL)};
unsigned int a_1[4]={((unsigned int)2632882952ULL),((unsigned int)4172017422ULL),((unsigned int)1585991153ULL),((unsigned int)4023581535ULL)};
unsigned int b_1[4]={((unsigned int)2632882952ULL),((unsigned int)4172017422ULL),((unsigned int)1585991153ULL),((unsigned int)4023581535ULL)};
unsigned int a_2[4]={((unsigned int)4077200322ULL),((unsigned int)1240817946ULL),((unsigned int)3800095031ULL),((unsigned int)3118173898ULL)};
unsigned int b_2[4]={((unsigned int)4077200322ULL),((unsigned int)1240817946ULL),((unsigned int)3800095031ULL),((unsigned int)3118173898ULL)};
unsigned int a_3[4]={((unsigned int)4211747934ULL),((unsigned int)1290745359ULL),((unsigned int)2964740991ULL),((unsigned int)475871486ULL)};
unsigned int b_3[4]={((unsigned int)4211747934ULL),((unsigned int)1290745359ULL),((unsigned int)2964740991ULL),((unsigned int)475871486ULL)};
unsigned int a_4[16]={((unsigned int)29009696ULL),((unsigned int)1680905487ULL),((unsigned int)3057852337ULL),((unsigned int)1137413091ULL),((unsigned int)2847005782ULL),((unsigned int)2227380962ULL),((unsigned int)3534058108ULL),((unsigned int)880455589ULL),((unsigned int)1714083940ULL),((unsigned int)2922746876ULL),((unsigned int)3948310372ULL),((unsigned int)2425463741ULL),((unsigned int)3871672143ULL),((unsigned int)2441912208ULL),((unsigned int)2648099733ULL),((unsigned int)3805208954ULL)};
unsigned int b_4[16]={((unsigned int)29009696ULL),((unsigned int)1680905487ULL),((unsigned int)3057852337ULL),((unsigned int)1137413091ULL),((unsigned int)2847005782ULL),((unsigned int)2227380962ULL),((unsigned int)3534058108ULL),((unsigned int)880455589ULL),((unsigned int)1714083940ULL),((unsigned int)2922746876ULL),((unsigned int)3948310372ULL),((unsigned int)2425463741ULL),((unsigned int)3871672143ULL),((unsigned int)2441912208ULL),((unsigned int)2648099733ULL),((unsigned int)3805208954ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 90\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2636635166ULL),((unsigned int)2806236509ULL),((unsigned int)1186677426ULL),((unsigned int)757757682ULL)};
unsigned int b_0[4]={((unsigned int)2636635166ULL),((unsigned int)2806236509ULL),((unsigned int)1186677426ULL),((unsigned int)757757682ULL)};
unsigned int a_1[4]={((unsigned int)3880597243ULL),((unsigned int)3109772251ULL),((unsigned int)2202735738ULL),((unsigned int)3187736346ULL)};
unsigned int b_1[4]={((unsigned int)3880597243ULL),((unsigned int)3109772251ULL),((unsigned int)2202735738ULL),((unsigned int)3187736346ULL)};
unsigned int a_2[4]={((unsigned int)2253507501ULL),((unsigned int)891724357ULL),((unsigned int)692948681ULL),((unsigned int)2738986789ULL)};
unsigned int b_2[4]={((unsigned int)2253507501ULL),((unsigned int)891724357ULL),((unsigned int)692948681ULL),((unsigned int)2738986789ULL)};
unsigned int a_3[4]={((unsigned int)3139258437ULL),((unsigned int)2648046478ULL),((unsigned int)588886154ULL),((unsigned int)3116323780ULL)};
unsigned int b_3[4]={((unsigned int)3139258437ULL),((unsigned int)2648046478ULL),((unsigned int)588886154ULL),((unsigned int)3116323780ULL)};
unsigned int a_4[16]={((unsigned int)1760063300ULL),((unsigned int)1418225765ULL),((unsigned int)379521828ULL),((unsigned int)1863274952ULL),((unsigned int)4047836023ULL),((unsigned int)312802110ULL),((unsigned int)1591390661ULL),((unsigned int)240341697ULL),((unsigned int)2107803040ULL),((unsigned int)3584388208ULL),((unsigned int)1495452519ULL),((unsigned int)925755593ULL),((unsigned int)1766001784ULL),((unsigned int)2366685893ULL),((unsigned int)3232483825ULL),((unsigned int)2320630016ULL)};
unsigned int b_4[16]={((unsigned int)1760063300ULL),((unsigned int)1418225765ULL),((unsigned int)379521828ULL),((unsigned int)1863274952ULL),((unsigned int)4047836023ULL),((unsigned int)312802110ULL),((unsigned int)1591390661ULL),((unsigned int)240341697ULL),((unsigned int)2107803040ULL),((unsigned int)3584388208ULL),((unsigned int)1495452519ULL),((unsigned int)925755593ULL),((unsigned int)1766001784ULL),((unsigned int)2366685893ULL),((unsigned int)3232483825ULL),((unsigned int)2320630016ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 91\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2797672109ULL),((unsigned int)779773717ULL),((unsigned int)1602859859ULL),((unsigned int)4211969302ULL)};
unsigned int b_0[4]={((unsigned int)2797672109ULL),((unsigned int)779773717ULL),((unsigned int)1602859859ULL),((unsigned int)4211969302ULL)};
unsigned int a_1[4]={((unsigned int)3784644992ULL),((unsigned int)3958072076ULL),((unsigned int)3944472430ULL),((unsigned int)1206524322ULL)};
unsigned int b_1[4]={((unsigned int)3784644992ULL),((unsigned int)3958072076ULL),((unsigned int)3944472430ULL),((unsigned int)1206524322ULL)};
unsigned int a_2[4]={((unsigned int)1139783847ULL),((unsigned int)3671641333ULL),((unsigned int)2268667963ULL),((unsigned int)3627070787ULL)};
unsigned int b_2[4]={((unsigned int)1139783847ULL),((unsigned int)3671641333ULL),((unsigned int)2268667963ULL),((unsigned int)3627070787ULL)};
unsigned int a_3[4]={((unsigned int)1835196545ULL),((unsigned int)3644088932ULL),((unsigned int)606159489ULL),((unsigned int)2425189496ULL)};
unsigned int b_3[4]={((unsigned int)1835196545ULL),((unsigned int)3644088932ULL),((unsigned int)606159489ULL),((unsigned int)2425189496ULL)};
unsigned int a_4[16]={((unsigned int)464657253ULL),((unsigned int)3923330844ULL),((unsigned int)3883323310ULL),((unsigned int)4279791748ULL),((unsigned int)2524182405ULL),((unsigned int)2234433509ULL),((unsigned int)2326418923ULL),((unsigned int)681883013ULL),((unsigned int)569805541ULL),((unsigned int)542065846ULL),((unsigned int)3285811769ULL),((unsigned int)950822809ULL),((unsigned int)2028762714ULL),((unsigned int)1765201387ULL),((unsigned int)1011484315ULL),((unsigned int)3248626961ULL)};
unsigned int b_4[16]={((unsigned int)464657253ULL),((unsigned int)3923330844ULL),((unsigned int)3883323310ULL),((unsigned int)4279791748ULL),((unsigned int)2524182405ULL),((unsigned int)2234433509ULL),((unsigned int)2326418923ULL),((unsigned int)681883013ULL),((unsigned int)569805541ULL),((unsigned int)542065846ULL),((unsigned int)3285811769ULL),((unsigned int)950822809ULL),((unsigned int)2028762714ULL),((unsigned int)1765201387ULL),((unsigned int)1011484315ULL),((unsigned int)3248626961ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 92\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2542872915ULL),((unsigned int)2094324303ULL),((unsigned int)3665708471ULL),((unsigned int)4157994864ULL)};
unsigned int b_0[4]={((unsigned int)2542872915ULL),((unsigned int)2094324303ULL),((unsigned int)3665708471ULL),((unsigned int)4157994864ULL)};
unsigned int a_1[4]={((unsigned int)3679194767ULL),((unsigned int)869778994ULL),((unsigned int)2039106008ULL),((unsigned int)3279054353ULL)};
unsigned int b_1[4]={((unsigned int)3679194767ULL),((unsigned int)869778994ULL),((unsigned int)2039106008ULL),((unsigned int)3279054353ULL)};
unsigned int a_2[4]={((unsigned int)3982578913ULL),((unsigned int)3837543413ULL),((unsigned int)846217773ULL),((unsigned int)3330910769ULL)};
unsigned int b_2[4]={((unsigned int)3982578913ULL),((unsigned int)3837543413ULL),((unsigned int)846217773ULL),((unsigned int)3330910769ULL)};
unsigned int a_3[4]={((unsigned int)1494894691ULL),((unsigned int)508350787ULL),((unsigned int)62993247ULL),((unsigned int)2355369998ULL)};
unsigned int b_3[4]={((unsigned int)1494894691ULL),((unsigned int)508350787ULL),((unsigned int)62993247ULL),((unsigned int)2355369998ULL)};
unsigned int a_4[16]={((unsigned int)3966796263ULL),((unsigned int)1119477129ULL),((unsigned int)3620941446ULL),((unsigned int)1978911639ULL),((unsigned int)2356311094ULL),((unsigned int)1183817147ULL),((unsigned int)520268005ULL),((unsigned int)3653840580ULL),((unsigned int)3172347292ULL),((unsigned int)639937099ULL),((unsigned int)4033582302ULL),((unsigned int)1832806383ULL),((unsigned int)1776605135ULL),((unsigned int)275333603ULL),((unsigned int)155545624ULL),((unsigned int)1266436760ULL)};
unsigned int b_4[16]={((unsigned int)3966796263ULL),((unsigned int)1119477129ULL),((unsigned int)3620941446ULL),((unsigned int)1978911639ULL),((unsigned int)2356311094ULL),((unsigned int)1183817147ULL),((unsigned int)520268005ULL),((unsigned int)3653840580ULL),((unsigned int)3172347292ULL),((unsigned int)639937099ULL),((unsigned int)4033582302ULL),((unsigned int)1832806383ULL),((unsigned int)1776605135ULL),((unsigned int)275333603ULL),((unsigned int)155545624ULL),((unsigned int)1266436760ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 93\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2085859720ULL),((unsigned int)965889072ULL),((unsigned int)2815301856ULL),((unsigned int)3097205257ULL)};
unsigned int b_0[4]={((unsigned int)2085859720ULL),((unsigned int)965889072ULL),((unsigned int)2815301856ULL),((unsigned int)3097205257ULL)};
unsigned int a_1[4]={((unsigned int)2123058245ULL),((unsigned int)858076221ULL),((unsigned int)2629908353ULL),((unsigned int)421911697ULL)};
unsigned int b_1[4]={((unsigned int)2123058245ULL),((unsigned int)858076221ULL),((unsigned int)2629908353ULL),((unsigned int)421911697ULL)};
unsigned int a_2[4]={((unsigned int)3907431521ULL),((unsigned int)3728095466ULL),((unsigned int)2175451711ULL),((unsigned int)3503184280ULL)};
unsigned int b_2[4]={((unsigned int)3907431521ULL),((unsigned int)3728095466ULL),((unsigned int)2175451711ULL),((unsigned int)3503184280ULL)};
unsigned int a_3[4]={((unsigned int)3730291192ULL),((unsigned int)7590086ULL),((unsigned int)2727776443ULL),((unsigned int)927122651ULL)};
unsigned int b_3[4]={((unsigned int)3730291192ULL),((unsigned int)7590086ULL),((unsigned int)2727776443ULL),((unsigned int)927122651ULL)};
unsigned int a_4[16]={((unsigned int)3308777306ULL),((unsigned int)265548907ULL),((unsigned int)1465404177ULL),((unsigned int)1493592427ULL),((unsigned int)2745582057ULL),((unsigned int)1884758115ULL),((unsigned int)538057134ULL),((unsigned int)457891063ULL),((unsigned int)3386021833ULL),((unsigned int)3953446317ULL),((unsigned int)3375443943ULL),((unsigned int)2782658673ULL),((unsigned int)1952610240ULL),((unsigned int)466069048ULL),((unsigned int)1534408635ULL),((unsigned int)3188251529ULL)};
unsigned int b_4[16]={((unsigned int)3308777306ULL),((unsigned int)265548907ULL),((unsigned int)1465404177ULL),((unsigned int)1493592427ULL),((unsigned int)2745582057ULL),((unsigned int)1884758115ULL),((unsigned int)538057134ULL),((unsigned int)457891063ULL),((unsigned int)3386021833ULL),((unsigned int)3953446317ULL),((unsigned int)3375443943ULL),((unsigned int)2782658673ULL),((unsigned int)1952610240ULL),((unsigned int)466069048ULL),((unsigned int)1534408635ULL),((unsigned int)3188251529ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 94\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4246036887ULL),((unsigned int)593509624ULL),((unsigned int)281884970ULL),((unsigned int)2747767159ULL)};
unsigned int b_0[4]={((unsigned int)4246036887ULL),((unsigned int)593509624ULL),((unsigned int)281884970ULL),((unsigned int)2747767159ULL)};
unsigned int a_1[4]={((unsigned int)1742405068ULL),((unsigned int)201401651ULL),((unsigned int)3912010880ULL),((unsigned int)2096502466ULL)};
unsigned int b_1[4]={((unsigned int)1742405068ULL),((unsigned int)201401651ULL),((unsigned int)3912010880ULL),((unsigned int)2096502466ULL)};
unsigned int a_2[4]={((unsigned int)1429331395ULL),((unsigned int)3724938265ULL),((unsigned int)2847124794ULL),((unsigned int)2198573449ULL)};
unsigned int b_2[4]={((unsigned int)1429331395ULL),((unsigned int)3724938265ULL),((unsigned int)2847124794ULL),((unsigned int)2198573449ULL)};
unsigned int a_3[4]={((unsigned int)2801201946ULL),((unsigned int)3263573985ULL),((unsigned int)2319329572ULL),((unsigned int)3870629569ULL)};
unsigned int b_3[4]={((unsigned int)2801201946ULL),((unsigned int)3263573985ULL),((unsigned int)2319329572ULL),((unsigned int)3870629569ULL)};
unsigned int a_4[16]={((unsigned int)2877107506ULL),((unsigned int)2411673498ULL),((unsigned int)656347396ULL),((unsigned int)3971800268ULL),((unsigned int)1087981982ULL),((unsigned int)1748827551ULL),((unsigned int)410085186ULL),((unsigned int)1565062940ULL),((unsigned int)1906617683ULL),((unsigned int)3848797747ULL),((unsigned int)3769677822ULL),((unsigned int)291379365ULL),((unsigned int)4160271580ULL),((unsigned int)3499708735ULL),((unsigned int)526038528ULL),((unsigned int)188266761ULL)};
unsigned int b_4[16]={((unsigned int)2877107506ULL),((unsigned int)2411673498ULL),((unsigned int)656347396ULL),((unsigned int)3971800268ULL),((unsigned int)1087981982ULL),((unsigned int)1748827551ULL),((unsigned int)410085186ULL),((unsigned int)1565062940ULL),((unsigned int)1906617683ULL),((unsigned int)3848797747ULL),((unsigned int)3769677822ULL),((unsigned int)291379365ULL),((unsigned int)4160271580ULL),((unsigned int)3499708735ULL),((unsigned int)526038528ULL),((unsigned int)188266761ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 95\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3158974276ULL),((unsigned int)2103706722ULL),((unsigned int)1789232179ULL),((unsigned int)3212092698ULL)};
unsigned int b_0[4]={((unsigned int)3158974276ULL),((unsigned int)2103706722ULL),((unsigned int)1789232179ULL),((unsigned int)3212092698ULL)};
unsigned int a_1[4]={((unsigned int)3545683585ULL),((unsigned int)2290751118ULL),((unsigned int)542522564ULL),((unsigned int)85930070ULL)};
unsigned int b_1[4]={((unsigned int)3545683585ULL),((unsigned int)2290751118ULL),((unsigned int)542522564ULL),((unsigned int)85930070ULL)};
unsigned int a_2[4]={((unsigned int)3805221284ULL),((unsigned int)657659562ULL),((unsigned int)2399780110ULL),((unsigned int)424349554ULL)};
unsigned int b_2[4]={((unsigned int)3805221284ULL),((unsigned int)657659562ULL),((unsigned int)2399780110ULL),((unsigned int)424349554ULL)};
unsigned int a_3[4]={((unsigned int)3883741605ULL),((unsigned int)2039941663ULL),((unsigned int)2369065045ULL),((unsigned int)3101394222ULL)};
unsigned int b_3[4]={((unsigned int)3883741605ULL),((unsigned int)2039941663ULL),((unsigned int)2369065045ULL),((unsigned int)3101394222ULL)};
unsigned int a_4[16]={((unsigned int)1704508834ULL),((unsigned int)4011865835ULL),((unsigned int)3645813462ULL),((unsigned int)3308876348ULL),((unsigned int)1080116351ULL),((unsigned int)3575271250ULL),((unsigned int)2605889848ULL),((unsigned int)3740580078ULL),((unsigned int)3349099009ULL),((unsigned int)2957649781ULL),((unsigned int)3860380303ULL),((unsigned int)374240586ULL),((unsigned int)1176502379ULL),((unsigned int)2522638542ULL),((unsigned int)2923803790ULL),((unsigned int)254335010ULL)};
unsigned int b_4[16]={((unsigned int)1704508834ULL),((unsigned int)4011865835ULL),((unsigned int)3645813462ULL),((unsigned int)3308876348ULL),((unsigned int)1080116351ULL),((unsigned int)3575271250ULL),((unsigned int)2605889848ULL),((unsigned int)3740580078ULL),((unsigned int)3349099009ULL),((unsigned int)2957649781ULL),((unsigned int)3860380303ULL),((unsigned int)374240586ULL),((unsigned int)1176502379ULL),((unsigned int)2522638542ULL),((unsigned int)2923803790ULL),((unsigned int)254335010ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 96\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)835089805ULL),((unsigned int)2551828778ULL),((unsigned int)1016985438ULL),((unsigned int)3596699517ULL)};
unsigned int b_0[4]={((unsigned int)835089805ULL),((unsigned int)2551828778ULL),((unsigned int)1016985438ULL),((unsigned int)3596699517ULL)};
unsigned int a_1[4]={((unsigned int)3437062777ULL),((unsigned int)191608062ULL),((unsigned int)3823798674ULL),((unsigned int)2092894526ULL)};
unsigned int b_1[4]={((unsigned int)3437062777ULL),((unsigned int)191608062ULL),((unsigned int)3823798674ULL),((unsigned int)2092894526ULL)};
unsigned int a_2[4]={((unsigned int)1616155470ULL),((unsigned int)1704503069ULL),((unsigned int)2965817963ULL),((unsigned int)2176919840ULL)};
unsigned int b_2[4]={((unsigned int)1616155470ULL),((unsigned int)1704503069ULL),((unsigned int)2965817963ULL),((unsigned int)2176919840ULL)};
unsigned int a_3[4]={((unsigned int)4129088993ULL),((unsigned int)2139902817ULL),((unsigned int)831494526ULL),((unsigned int)2905803302ULL)};
unsigned int b_3[4]={((unsigned int)4129088993ULL),((unsigned int)2139902817ULL),((unsigned int)831494526ULL),((unsigned int)2905803302ULL)};
unsigned int a_4[16]={((unsigned int)1795299994ULL),((unsigned int)3523963187ULL),((unsigned int)3360600420ULL),((unsigned int)1245765880ULL),((unsigned int)820962457ULL),((unsigned int)2635360237ULL),((unsigned int)2044451209ULL),((unsigned int)3184936975ULL),((unsigned int)583458203ULL),((unsigned int)2788432636ULL),((unsigned int)289751426ULL),((unsigned int)2743741686ULL),((unsigned int)2469921188ULL),((unsigned int)3042345156ULL),((unsigned int)1804207181ULL),((unsigned int)222851268ULL)};
unsigned int b_4[16]={((unsigned int)1795299994ULL),((unsigned int)3523963187ULL),((unsigned int)3360600420ULL),((unsigned int)1245765880ULL),((unsigned int)820962457ULL),((unsigned int)2635360237ULL),((unsigned int)2044451209ULL),((unsigned int)3184936975ULL),((unsigned int)583458203ULL),((unsigned int)2788432636ULL),((unsigned int)289751426ULL),((unsigned int)2743741686ULL),((unsigned int)2469921188ULL),((unsigned int)3042345156ULL),((unsigned int)1804207181ULL),((unsigned int)222851268ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 97\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3629206971ULL),((unsigned int)1596556906ULL),((unsigned int)1019941607ULL),((unsigned int)2772997629ULL)};
unsigned int b_0[4]={((unsigned int)3629206971ULL),((unsigned int)1596556906ULL),((unsigned int)1019941607ULL),((unsigned int)2772997629ULL)};
unsigned int a_1[4]={((unsigned int)1177410384ULL),((unsigned int)556578605ULL),((unsigned int)1348975256ULL),((unsigned int)3978541090ULL)};
unsigned int b_1[4]={((unsigned int)1177410384ULL),((unsigned int)556578605ULL),((unsigned int)1348975256ULL),((unsigned int)3978541090ULL)};
unsigned int a_2[4]={((unsigned int)3782018585ULL),((unsigned int)3958361059ULL),((unsigned int)1999675306ULL),((unsigned int)2308898645ULL)};
unsigned int b_2[4]={((unsigned int)3782018585ULL),((unsigned int)3958361059ULL),((unsigned int)1999675306ULL),((unsigned int)2308898645ULL)};
unsigned int a_3[4]={((unsigned int)2513194214ULL),((unsigned int)2545933213ULL),((unsigned int)2755170779ULL),((unsigned int)615357023ULL)};
unsigned int b_3[4]={((unsigned int)2513194214ULL),((unsigned int)2545933213ULL),((unsigned int)2755170779ULL),((unsigned int)615357023ULL)};
unsigned int a_4[16]={((unsigned int)639590737ULL),((unsigned int)4033747742ULL),((unsigned int)2146913583ULL),((unsigned int)680955252ULL),((unsigned int)2381513409ULL),((unsigned int)4050020680ULL),((unsigned int)1735664638ULL),((unsigned int)4219281996ULL),((unsigned int)44215138ULL),((unsigned int)2104079081ULL),((unsigned int)235246396ULL),((unsigned int)4223615083ULL),((unsigned int)2407647227ULL),((unsigned int)2231601934ULL),((unsigned int)2186369503ULL),((unsigned int)2056133683ULL)};
unsigned int b_4[16]={((unsigned int)639590737ULL),((unsigned int)4033747742ULL),((unsigned int)2146913583ULL),((unsigned int)680955252ULL),((unsigned int)2381513409ULL),((unsigned int)4050020680ULL),((unsigned int)1735664638ULL),((unsigned int)4219281996ULL),((unsigned int)44215138ULL),((unsigned int)2104079081ULL),((unsigned int)235246396ULL),((unsigned int)4223615083ULL),((unsigned int)2407647227ULL),((unsigned int)2231601934ULL),((unsigned int)2186369503ULL),((unsigned int)2056133683ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 98\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1341525148ULL),((unsigned int)662030415ULL),((unsigned int)4118835589ULL),((unsigned int)52899305ULL)};
unsigned int b_0[4]={((unsigned int)1341525148ULL),((unsigned int)662030415ULL),((unsigned int)4118835589ULL),((unsigned int)52899305ULL)};
unsigned int a_1[4]={((unsigned int)1882852203ULL),((unsigned int)851606466ULL),((unsigned int)4110627811ULL),((unsigned int)781710080ULL)};
unsigned int b_1[4]={((unsigned int)1882852203ULL),((unsigned int)851606466ULL),((unsigned int)4110627811ULL),((unsigned int)781710080ULL)};
unsigned int a_2[4]={((unsigned int)1502440410ULL),((unsigned int)1871052229ULL),((unsigned int)940513187ULL),((unsigned int)1284465171ULL)};
unsigned int b_2[4]={((unsigned int)1502440410ULL),((unsigned int)1871052229ULL),((unsigned int)940513187ULL),((unsigned int)1284465171ULL)};
unsigned int a_3[4]={((unsigned int)4186969648ULL),((unsigned int)4166371370ULL),((unsigned int)3648059981ULL),((unsigned int)513762655ULL)};
unsigned int b_3[4]={((unsigned int)4186969648ULL),((unsigned int)4166371370ULL),((unsigned int)3648059981ULL),((unsigned int)513762655ULL)};
unsigned int a_4[16]={((unsigned int)1544010284ULL),((unsigned int)3237387521ULL),((unsigned int)3064095865ULL),((unsigned int)1176585710ULL),((unsigned int)2016285544ULL),((unsigned int)2505950129ULL),((unsigned int)169811695ULL),((unsigned int)1716214407ULL),((unsigned int)3765055872ULL),((unsigned int)1502329216ULL),((unsigned int)2582607776ULL),((unsigned int)1875129030ULL),((unsigned int)485903238ULL),((unsigned int)4210713697ULL),((unsigned int)656461460ULL),((unsigned int)3181818857ULL)};
unsigned int b_4[16]={((unsigned int)1544010284ULL),((unsigned int)3237387521ULL),((unsigned int)3064095865ULL),((unsigned int)1176585710ULL),((unsigned int)2016285544ULL),((unsigned int)2505950129ULL),((unsigned int)169811695ULL),((unsigned int)1716214407ULL),((unsigned int)3765055872ULL),((unsigned int)1502329216ULL),((unsigned int)2582607776ULL),((unsigned int)1875129030ULL),((unsigned int)485903238ULL),((unsigned int)4210713697ULL),((unsigned int)656461460ULL),((unsigned int)3181818857ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 99\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)897955643ULL),((unsigned int)3062482071ULL),((unsigned int)574011455ULL),((unsigned int)3308514084ULL)};
unsigned int b_0[4]={((unsigned int)897955643ULL),((unsigned int)3062482071ULL),((unsigned int)574011455ULL),((unsigned int)3308514084ULL)};
unsigned int a_1[4]={((unsigned int)1744181366ULL),((unsigned int)2579788690ULL),((unsigned int)2949971828ULL),((unsigned int)3035181316ULL)};
unsigned int b_1[4]={((unsigned int)1744181366ULL),((unsigned int)2579788690ULL),((unsigned int)2949971828ULL),((unsigned int)3035181316ULL)};
unsigned int a_2[4]={((unsigned int)1334589195ULL),((unsigned int)3821540053ULL),((unsigned int)465648189ULL),((unsigned int)3878194638ULL)};
unsigned int b_2[4]={((unsigned int)1334589195ULL),((unsigned int)3821540053ULL),((unsigned int)465648189ULL),((unsigned int)3878194638ULL)};
unsigned int a_3[4]={((unsigned int)228465134ULL),((unsigned int)3027534700ULL),((unsigned int)357676692ULL),((unsigned int)2237841805ULL)};
unsigned int b_3[4]={((unsigned int)228465134ULL),((unsigned int)3027534700ULL),((unsigned int)357676692ULL),((unsigned int)2237841805ULL)};
unsigned int a_4[16]={((unsigned int)3665149937ULL),((unsigned int)2392092013ULL),((unsigned int)2014438333ULL),((unsigned int)3225362203ULL),((unsigned int)368210331ULL),((unsigned int)1930096314ULL),((unsigned int)4030533578ULL),((unsigned int)1370067568ULL),((unsigned int)2522214088ULL),((unsigned int)3794517635ULL),((unsigned int)4101648464ULL),((unsigned int)2506275129ULL),((unsigned int)837761584ULL),((unsigned int)3025917607ULL),((unsigned int)1746778755ULL),((unsigned int)1880727711ULL)};
unsigned int b_4[16]={((unsigned int)3665149937ULL),((unsigned int)2392092013ULL),((unsigned int)2014438333ULL),((unsigned int)3225362203ULL),((unsigned int)368210331ULL),((unsigned int)1930096314ULL),((unsigned int)4030533578ULL),((unsigned int)1370067568ULL),((unsigned int)2522214088ULL),((unsigned int)3794517635ULL),((unsigned int)4101648464ULL),((unsigned int)2506275129ULL),((unsigned int)837761584ULL),((unsigned int)3025917607ULL),((unsigned int)1746778755ULL),((unsigned int)1880727711ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 100\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3480689996ULL),((unsigned int)1865693510ULL),((unsigned int)3999558702ULL),((unsigned int)3175427225ULL)};
unsigned int b_0[4]={((unsigned int)3480689996ULL),((unsigned int)1865693510ULL),((unsigned int)3999558702ULL),((unsigned int)3175427225ULL)};
unsigned int a_1[4]={((unsigned int)2925790724ULL),((unsigned int)3644012513ULL),((unsigned int)2269659112ULL),((unsigned int)52624871ULL)};
unsigned int b_1[4]={((unsigned int)2925790724ULL),((unsigned int)3644012513ULL),((unsigned int)2269659112ULL),((unsigned int)52624871ULL)};
unsigned int a_2[4]={((unsigned int)4051206545ULL),((unsigned int)3880332138ULL),((unsigned int)463187099ULL),((unsigned int)1595801171ULL)};
unsigned int b_2[4]={((unsigned int)4051206545ULL),((unsigned int)3880332138ULL),((unsigned int)463187099ULL),((unsigned int)1595801171ULL)};
unsigned int a_3[4]={((unsigned int)4090154254ULL),((unsigned int)245740352ULL),((unsigned int)2622132552ULL),((unsigned int)4052681955ULL)};
unsigned int b_3[4]={((unsigned int)4090154254ULL),((unsigned int)245740352ULL),((unsigned int)2622132552ULL),((unsigned int)4052681955ULL)};
unsigned int a_4[16]={((unsigned int)3216750029ULL),((unsigned int)3625238871ULL),((unsigned int)611966317ULL),((unsigned int)2368525907ULL),((unsigned int)1569045394ULL),((unsigned int)1043119142ULL),((unsigned int)3087891140ULL),((unsigned int)1383074814ULL),((unsigned int)3138863512ULL),((unsigned int)3023216395ULL),((unsigned int)1684675980ULL),((unsigned int)2816439078ULL),((unsigned int)2613007892ULL),((unsigned int)2937223354ULL),((unsigned int)1741155129ULL),((unsigned int)363250612ULL)};
unsigned int b_4[16]={((unsigned int)3216750029ULL),((unsigned int)3625238871ULL),((unsigned int)611966317ULL),((unsigned int)2368525907ULL),((unsigned int)1569045394ULL),((unsigned int)1043119142ULL),((unsigned int)3087891140ULL),((unsigned int)1383074814ULL),((unsigned int)3138863512ULL),((unsigned int)3023216395ULL),((unsigned int)1684675980ULL),((unsigned int)2816439078ULL),((unsigned int)2613007892ULL),((unsigned int)2937223354ULL),((unsigned int)1741155129ULL),((unsigned int)363250612ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 101\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)132849301ULL),((unsigned int)3873132797ULL),((unsigned int)2470894682ULL),((unsigned int)1366607051ULL)};
unsigned int b_0[4]={((unsigned int)132849301ULL),((unsigned int)3873132797ULL),((unsigned int)2470894682ULL),((unsigned int)1366607051ULL)};
unsigned int a_1[4]={((unsigned int)1273579711ULL),((unsigned int)8440790ULL),((unsigned int)3028784606ULL),((unsigned int)3375223730ULL)};
unsigned int b_1[4]={((unsigned int)1273579711ULL),((unsigned int)8440790ULL),((unsigned int)3028784606ULL),((unsigned int)3375223730ULL)};
unsigned int a_2[4]={((unsigned int)2731120558ULL),((unsigned int)3472502904ULL),((unsigned int)2718143723ULL),((unsigned int)2091604148ULL)};
unsigned int b_2[4]={((unsigned int)2731120558ULL),((unsigned int)3472502904ULL),((unsigned int)2718143723ULL),((unsigned int)2091604148ULL)};
unsigned int a_3[4]={((unsigned int)1845941690ULL),((unsigned int)991420651ULL),((unsigned int)2547025143ULL),((unsigned int)917267660ULL)};
unsigned int b_3[4]={((unsigned int)1845941690ULL),((unsigned int)991420651ULL),((unsigned int)2547025143ULL),((unsigned int)917267660ULL)};
unsigned int a_4[16]={((unsigned int)192540714ULL),((unsigned int)3591777822ULL),((unsigned int)2002132888ULL),((unsigned int)2650602747ULL),((unsigned int)1299552107ULL),((unsigned int)2507515445ULL),((unsigned int)920592553ULL),((unsigned int)827206186ULL),((unsigned int)536514454ULL),((unsigned int)2705342535ULL),((unsigned int)1259177988ULL),((unsigned int)727251523ULL),((unsigned int)4091139095ULL),((unsigned int)2478778324ULL),((unsigned int)648744104ULL),((unsigned int)3715104415ULL)};
unsigned int b_4[16]={((unsigned int)192540714ULL),((unsigned int)3591777822ULL),((unsigned int)2002132888ULL),((unsigned int)2650602747ULL),((unsigned int)1299552107ULL),((unsigned int)2507515445ULL),((unsigned int)920592553ULL),((unsigned int)827206186ULL),((unsigned int)536514454ULL),((unsigned int)2705342535ULL),((unsigned int)1259177988ULL),((unsigned int)727251523ULL),((unsigned int)4091139095ULL),((unsigned int)2478778324ULL),((unsigned int)648744104ULL),((unsigned int)3715104415ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 102\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2524535438ULL),((unsigned int)849081684ULL),((unsigned int)2033222805ULL),((unsigned int)916026858ULL)};
unsigned int b_0[4]={((unsigned int)2524535438ULL),((unsigned int)849081684ULL),((unsigned int)2033222805ULL),((unsigned int)916026858ULL)};
unsigned int a_1[4]={((unsigned int)3252366760ULL),((unsigned int)334273952ULL),((unsigned int)2572989750ULL),((unsigned int)2793385613ULL)};
unsigned int b_1[4]={((unsigned int)3252366760ULL),((unsigned int)334273952ULL),((unsigned int)2572989750ULL),((unsigned int)2793385613ULL)};
unsigned int a_2[4]={((unsigned int)1036364141ULL),((unsigned int)3067702840ULL),((unsigned int)886287043ULL),((unsigned int)351112651ULL)};
unsigned int b_2[4]={((unsigned int)1036364141ULL),((unsigned int)3067702840ULL),((unsigned int)886287043ULL),((unsigned int)351112651ULL)};
unsigned int a_3[4]={((unsigned int)2198563149ULL),((unsigned int)3765029713ULL),((unsigned int)1461603206ULL),((unsigned int)2551812270ULL)};
unsigned int b_3[4]={((unsigned int)2198563149ULL),((unsigned int)3765029713ULL),((unsigned int)1461603206ULL),((unsigned int)2551812270ULL)};
unsigned int a_4[16]={((unsigned int)4299612ULL),((unsigned int)2516760081ULL),((unsigned int)434166604ULL),((unsigned int)3368945727ULL),((unsigned int)1698719881ULL),((unsigned int)3118163319ULL),((unsigned int)2903659250ULL),((unsigned int)1081986710ULL),((unsigned int)949478866ULL),((unsigned int)967154335ULL),((unsigned int)1574355271ULL),((unsigned int)2046065274ULL),((unsigned int)2689749954ULL),((unsigned int)3274191262ULL),((unsigned int)3106486725ULL),((unsigned int)3035023645ULL)};
unsigned int b_4[16]={((unsigned int)4299612ULL),((unsigned int)2516760081ULL),((unsigned int)434166604ULL),((unsigned int)3368945727ULL),((unsigned int)1698719881ULL),((unsigned int)3118163319ULL),((unsigned int)2903659250ULL),((unsigned int)1081986710ULL),((unsigned int)949478866ULL),((unsigned int)967154335ULL),((unsigned int)1574355271ULL),((unsigned int)2046065274ULL),((unsigned int)2689749954ULL),((unsigned int)3274191262ULL),((unsigned int)3106486725ULL),((unsigned int)3035023645ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 103\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1166512591ULL),((unsigned int)2307593709ULL),((unsigned int)3413053104ULL),((unsigned int)578285054ULL)};
unsigned int b_0[4]={((unsigned int)1166512591ULL),((unsigned int)2307593709ULL),((unsigned int)3413053104ULL),((unsigned int)578285054ULL)};
unsigned int a_1[4]={((unsigned int)2460548714ULL),((unsigned int)4240025865ULL),((unsigned int)3823626641ULL),((unsigned int)1952980952ULL)};
unsigned int b_1[4]={((unsigned int)2460548714ULL),((unsigned int)4240025865ULL),((unsigned int)3823626641ULL),((unsigned int)1952980952ULL)};
unsigned int a_2[4]={((unsigned int)1011196051ULL),((unsigned int)1815558413ULL),((unsigned int)3256937450ULL),((unsigned int)1363614470ULL)};
unsigned int b_2[4]={((unsigned int)1011196051ULL),((unsigned int)1815558413ULL),((unsigned int)3256937450ULL),((unsigned int)1363614470ULL)};
unsigned int a_3[4]={((unsigned int)911655999ULL),((unsigned int)717023432ULL),((unsigned int)2955260661ULL),((unsigned int)1646194663ULL)};
unsigned int b_3[4]={((unsigned int)911655999ULL),((unsigned int)717023432ULL),((unsigned int)2955260661ULL),((unsigned int)1646194663ULL)};
unsigned int a_4[16]={((unsigned int)385408168ULL),((unsigned int)2827598076ULL),((unsigned int)3279665835ULL),((unsigned int)2040577967ULL),((unsigned int)1079831925ULL),((unsigned int)2105286555ULL),((unsigned int)4260007732ULL),((unsigned int)2133338657ULL),((unsigned int)1623573628ULL),((unsigned int)1543113005ULL),((unsigned int)2391571179ULL),((unsigned int)1212032700ULL),((unsigned int)2715748551ULL),((unsigned int)1584816958ULL),((unsigned int)902557895ULL),((unsigned int)3924854895ULL)};
unsigned int b_4[16]={((unsigned int)385408168ULL),((unsigned int)2827598076ULL),((unsigned int)3279665835ULL),((unsigned int)2040577967ULL),((unsigned int)1079831925ULL),((unsigned int)2105286555ULL),((unsigned int)4260007732ULL),((unsigned int)2133338657ULL),((unsigned int)1623573628ULL),((unsigned int)1543113005ULL),((unsigned int)2391571179ULL),((unsigned int)1212032700ULL),((unsigned int)2715748551ULL),((unsigned int)1584816958ULL),((unsigned int)902557895ULL),((unsigned int)3924854895ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 104\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2825169264ULL),((unsigned int)2076433392ULL),((unsigned int)2193844072ULL),((unsigned int)479136446ULL)};
unsigned int b_0[4]={((unsigned int)2825169264ULL),((unsigned int)2076433392ULL),((unsigned int)2193844072ULL),((unsigned int)479136446ULL)};
unsigned int a_1[4]={((unsigned int)508610623ULL),((unsigned int)3835499241ULL),((unsigned int)248143685ULL),((unsigned int)2621605548ULL)};
unsigned int b_1[4]={((unsigned int)508610623ULL),((unsigned int)3835499241ULL),((unsigned int)248143685ULL),((unsigned int)2621605548ULL)};
unsigned int a_2[4]={((unsigned int)799097812ULL),((unsigned int)151183011ULL),((unsigned int)1586194716ULL),((unsigned int)91903069ULL)};
unsigned int b_2[4]={((unsigned int)799097812ULL),((unsigned int)151183011ULL),((unsigned int)1586194716ULL),((unsigned int)91903069ULL)};
unsigned int a_3[4]={((unsigned int)187117799ULL),((unsigned int)1647009093ULL),((unsigned int)766349032ULL),((unsigned int)3963003387ULL)};
unsigned int b_3[4]={((unsigned int)187117799ULL),((unsigned int)1647009093ULL),((unsigned int)766349032ULL),((unsigned int)3963003387ULL)};
unsigned int a_4[16]={((unsigned int)546811325ULL),((unsigned int)1338568408ULL),((unsigned int)273729884ULL),((unsigned int)1222237402ULL),((unsigned int)2013572437ULL),((unsigned int)89785300ULL),((unsigned int)2462450397ULL),((unsigned int)2713070534ULL),((unsigned int)2194480722ULL),((unsigned int)1787304853ULL),((unsigned int)3591592296ULL),((unsigned int)2536362819ULL),((unsigned int)613540055ULL),((unsigned int)2895009821ULL),((unsigned int)3642967188ULL),((unsigned int)3529835353ULL)};
unsigned int b_4[16]={((unsigned int)546811325ULL),((unsigned int)1338568408ULL),((unsigned int)273729884ULL),((unsigned int)1222237402ULL),((unsigned int)2013572437ULL),((unsigned int)89785300ULL),((unsigned int)2462450397ULL),((unsigned int)2713070534ULL),((unsigned int)2194480722ULL),((unsigned int)1787304853ULL),((unsigned int)3591592296ULL),((unsigned int)2536362819ULL),((unsigned int)613540055ULL),((unsigned int)2895009821ULL),((unsigned int)3642967188ULL),((unsigned int)3529835353ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 105\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4247686982ULL),((unsigned int)3201743145ULL),((unsigned int)3229817573ULL),((unsigned int)3709462071ULL)};
unsigned int b_0[4]={((unsigned int)4247686982ULL),((unsigned int)3201743145ULL),((unsigned int)3229817573ULL),((unsigned int)3709462071ULL)};
unsigned int a_1[4]={((unsigned int)3376358184ULL),((unsigned int)973643545ULL),((unsigned int)1451572062ULL),((unsigned int)2394595730ULL)};
unsigned int b_1[4]={((unsigned int)3376358184ULL),((unsigned int)973643545ULL),((unsigned int)1451572062ULL),((unsigned int)2394595730ULL)};
unsigned int a_2[4]={((unsigned int)3397125769ULL),((unsigned int)285207497ULL),((unsigned int)3863196467ULL),((unsigned int)393106983ULL)};
unsigned int b_2[4]={((unsigned int)3397125769ULL),((unsigned int)285207497ULL),((unsigned int)3863196467ULL),((unsigned int)393106983ULL)};
unsigned int a_3[4]={((unsigned int)3480406675ULL),((unsigned int)208486953ULL),((unsigned int)1541272481ULL),((unsigned int)1184887538ULL)};
unsigned int b_3[4]={((unsigned int)3480406675ULL),((unsigned int)208486953ULL),((unsigned int)1541272481ULL),((unsigned int)1184887538ULL)};
unsigned int a_4[16]={((unsigned int)1627893340ULL),((unsigned int)3110865972ULL),((unsigned int)1101278203ULL),((unsigned int)3837909728ULL),((unsigned int)315716245ULL),((unsigned int)4257879428ULL),((unsigned int)398227784ULL),((unsigned int)3444201055ULL),((unsigned int)2572627169ULL),((unsigned int)2572747888ULL),((unsigned int)2080639068ULL),((unsigned int)3601338607ULL),((unsigned int)423334157ULL),((unsigned int)3124871249ULL),((unsigned int)2143736136ULL),((unsigned int)1055261503ULL)};
unsigned int b_4[16]={((unsigned int)1627893340ULL),((unsigned int)3110865972ULL),((unsigned int)1101278203ULL),((unsigned int)3837909728ULL),((unsigned int)315716245ULL),((unsigned int)4257879428ULL),((unsigned int)398227784ULL),((unsigned int)3444201055ULL),((unsigned int)2572627169ULL),((unsigned int)2572747888ULL),((unsigned int)2080639068ULL),((unsigned int)3601338607ULL),((unsigned int)423334157ULL),((unsigned int)3124871249ULL),((unsigned int)2143736136ULL),((unsigned int)1055261503ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 106\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)395851242ULL),((unsigned int)465959998ULL),((unsigned int)220876154ULL),((unsigned int)2214425949ULL)};
unsigned int b_0[4]={((unsigned int)395851242ULL),((unsigned int)465959998ULL),((unsigned int)220876154ULL),((unsigned int)2214425949ULL)};
unsigned int a_1[4]={((unsigned int)3924237269ULL),((unsigned int)177198348ULL),((unsigned int)2757078141ULL),((unsigned int)1554966673ULL)};
unsigned int b_1[4]={((unsigned int)3924237269ULL),((unsigned int)177198348ULL),((unsigned int)2757078141ULL),((unsigned int)1554966673ULL)};
unsigned int a_2[4]={((unsigned int)1217407748ULL),((unsigned int)2758177275ULL),((unsigned int)3298562158ULL),((unsigned int)4256540203ULL)};
unsigned int b_2[4]={((unsigned int)1217407748ULL),((unsigned int)2758177275ULL),((unsigned int)3298562158ULL),((unsigned int)4256540203ULL)};
unsigned int a_3[4]={((unsigned int)3573399819ULL),((unsigned int)4008679067ULL),((unsigned int)973652775ULL),((unsigned int)1098903087ULL)};
unsigned int b_3[4]={((unsigned int)3573399819ULL),((unsigned int)4008679067ULL),((unsigned int)973652775ULL),((unsigned int)1098903087ULL)};
unsigned int a_4[16]={((unsigned int)3729698934ULL),((unsigned int)656151934ULL),((unsigned int)2728237547ULL),((unsigned int)572972778ULL),((unsigned int)2703977278ULL),((unsigned int)140802920ULL),((unsigned int)3205407071ULL),((unsigned int)1656194019ULL),((unsigned int)2151060892ULL),((unsigned int)918538042ULL),((unsigned int)133700128ULL),((unsigned int)887602044ULL),((unsigned int)1176471017ULL),((unsigned int)1204741444ULL),((unsigned int)3616902307ULL),((unsigned int)2096882235ULL)};
unsigned int b_4[16]={((unsigned int)3729698934ULL),((unsigned int)656151934ULL),((unsigned int)2728237547ULL),((unsigned int)572972778ULL),((unsigned int)2703977278ULL),((unsigned int)140802920ULL),((unsigned int)3205407071ULL),((unsigned int)1656194019ULL),((unsigned int)2151060892ULL),((unsigned int)918538042ULL),((unsigned int)133700128ULL),((unsigned int)887602044ULL),((unsigned int)1176471017ULL),((unsigned int)1204741444ULL),((unsigned int)3616902307ULL),((unsigned int)2096882235ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 107\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2044327040ULL),((unsigned int)181418610ULL),((unsigned int)4074350667ULL),((unsigned int)3765785122ULL)};
unsigned int b_0[4]={((unsigned int)2044327040ULL),((unsigned int)181418610ULL),((unsigned int)4074350667ULL),((unsigned int)3765785122ULL)};
unsigned int a_1[4]={((unsigned int)3029178287ULL),((unsigned int)3997463155ULL),((unsigned int)619720824ULL),((unsigned int)2363787421ULL)};
unsigned int b_1[4]={((unsigned int)3029178287ULL),((unsigned int)3997463155ULL),((unsigned int)619720824ULL),((unsigned int)2363787421ULL)};
unsigned int a_2[4]={((unsigned int)2809766094ULL),((unsigned int)3002990547ULL),((unsigned int)2979618704ULL),((unsigned int)1104733022ULL)};
unsigned int b_2[4]={((unsigned int)2809766094ULL),((unsigned int)3002990547ULL),((unsigned int)2979618704ULL),((unsigned int)1104733022ULL)};
unsigned int a_3[4]={((unsigned int)440739735ULL),((unsigned int)2248581652ULL),((unsigned int)1918134242ULL),((unsigned int)133864109ULL)};
unsigned int b_3[4]={((unsigned int)440739735ULL),((unsigned int)2248581652ULL),((unsigned int)1918134242ULL),((unsigned int)133864109ULL)};
unsigned int a_4[16]={((unsigned int)2161043383ULL),((unsigned int)687684824ULL),((unsigned int)3553663485ULL),((unsigned int)12811538ULL),((unsigned int)1850069334ULL),((unsigned int)1499350242ULL),((unsigned int)3636857970ULL),((unsigned int)4273798562ULL),((unsigned int)1389530755ULL),((unsigned int)3998622658ULL),((unsigned int)248123176ULL),((unsigned int)1400450248ULL),((unsigned int)79182970ULL),((unsigned int)2794946299ULL),((unsigned int)2165209606ULL),((unsigned int)2254913478ULL)};
unsigned int b_4[16]={((unsigned int)2161043383ULL),((unsigned int)687684824ULL),((unsigned int)3553663485ULL),((unsigned int)12811538ULL),((unsigned int)1850069334ULL),((unsigned int)1499350242ULL),((unsigned int)3636857970ULL),((unsigned int)4273798562ULL),((unsigned int)1389530755ULL),((unsigned int)3998622658ULL),((unsigned int)248123176ULL),((unsigned int)1400450248ULL),((unsigned int)79182970ULL),((unsigned int)2794946299ULL),((unsigned int)2165209606ULL),((unsigned int)2254913478ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 108\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)170835933ULL),((unsigned int)3171586370ULL),((unsigned int)1595604268ULL),((unsigned int)1861677201ULL)};
unsigned int b_0[4]={((unsigned int)170835933ULL),((unsigned int)3171586370ULL),((unsigned int)1595604268ULL),((unsigned int)1861677201ULL)};
unsigned int a_1[4]={((unsigned int)605424862ULL),((unsigned int)1262383673ULL),((unsigned int)3948925402ULL),((unsigned int)1316425750ULL)};
unsigned int b_1[4]={((unsigned int)605424862ULL),((unsigned int)1262383673ULL),((unsigned int)3948925402ULL),((unsigned int)1316425750ULL)};
unsigned int a_2[4]={((unsigned int)52477526ULL),((unsigned int)1896950638ULL),((unsigned int)3043959997ULL),((unsigned int)3146147721ULL)};
unsigned int b_2[4]={((unsigned int)52477526ULL),((unsigned int)1896950638ULL),((unsigned int)3043959997ULL),((unsigned int)3146147721ULL)};
unsigned int a_3[4]={((unsigned int)3290276210ULL),((unsigned int)3824171890ULL),((unsigned int)4171202888ULL),((unsigned int)1946564448ULL)};
unsigned int b_3[4]={((unsigned int)3290276210ULL),((unsigned int)3824171890ULL),((unsigned int)4171202888ULL),((unsigned int)1946564448ULL)};
unsigned int a_4[16]={((unsigned int)4060115693ULL),((unsigned int)2359738518ULL),((unsigned int)3722543389ULL),((unsigned int)2699817440ULL),((unsigned int)1389831510ULL),((unsigned int)2212504548ULL),((unsigned int)3585900649ULL),((unsigned int)1137511815ULL),((unsigned int)1515870927ULL),((unsigned int)241729136ULL),((unsigned int)2076305451ULL),((unsigned int)2211303998ULL),((unsigned int)1526874759ULL),((unsigned int)3644303527ULL),((unsigned int)125756612ULL),((unsigned int)3559942475ULL)};
unsigned int b_4[16]={((unsigned int)4060115693ULL),((unsigned int)2359738518ULL),((unsigned int)3722543389ULL),((unsigned int)2699817440ULL),((unsigned int)1389831510ULL),((unsigned int)2212504548ULL),((unsigned int)3585900649ULL),((unsigned int)1137511815ULL),((unsigned int)1515870927ULL),((unsigned int)241729136ULL),((unsigned int)2076305451ULL),((unsigned int)2211303998ULL),((unsigned int)1526874759ULL),((unsigned int)3644303527ULL),((unsigned int)125756612ULL),((unsigned int)3559942475ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 109\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1181684457ULL),((unsigned int)1160615924ULL),((unsigned int)2396727966ULL),((unsigned int)2992560605ULL)};
unsigned int b_0[4]={((unsigned int)1181684457ULL),((unsigned int)1160615924ULL),((unsigned int)2396727966ULL),((unsigned int)2992560605ULL)};
unsigned int a_1[4]={((unsigned int)3083959146ULL),((unsigned int)2270303766ULL),((unsigned int)2249665955ULL),((unsigned int)1289074562ULL)};
unsigned int b_1[4]={((unsigned int)3083959146ULL),((unsigned int)2270303766ULL),((unsigned int)2249665955ULL),((unsigned int)1289074562ULL)};
unsigned int a_2[4]={((unsigned int)3348382168ULL),((unsigned int)1128768466ULL),((unsigned int)3951722731ULL),((unsigned int)392372828ULL)};
unsigned int b_2[4]={((unsigned int)3348382168ULL),((unsigned int)1128768466ULL),((unsigned int)3951722731ULL),((unsigned int)392372828ULL)};
unsigned int a_3[4]={((unsigned int)2044212767ULL),((unsigned int)1596731048ULL),((unsigned int)2563471924ULL),((unsigned int)1990546186ULL)};
unsigned int b_3[4]={((unsigned int)2044212767ULL),((unsigned int)1596731048ULL),((unsigned int)2563471924ULL),((unsigned int)1990546186ULL)};
unsigned int a_4[16]={((unsigned int)3647593301ULL),((unsigned int)4095108350ULL),((unsigned int)1663579310ULL),((unsigned int)2938974706ULL),((unsigned int)3900794754ULL),((unsigned int)3774334296ULL),((unsigned int)4094654612ULL),((unsigned int)2154818991ULL),((unsigned int)3075377362ULL),((unsigned int)432539581ULL),((unsigned int)3256638603ULL),((unsigned int)1360357115ULL),((unsigned int)2926594647ULL),((unsigned int)48625617ULL),((unsigned int)2186087791ULL),((unsigned int)3428514418ULL)};
unsigned int b_4[16]={((unsigned int)3647593301ULL),((unsigned int)4095108350ULL),((unsigned int)1663579310ULL),((unsigned int)2938974706ULL),((unsigned int)3900794754ULL),((unsigned int)3774334296ULL),((unsigned int)4094654612ULL),((unsigned int)2154818991ULL),((unsigned int)3075377362ULL),((unsigned int)432539581ULL),((unsigned int)3256638603ULL),((unsigned int)1360357115ULL),((unsigned int)2926594647ULL),((unsigned int)48625617ULL),((unsigned int)2186087791ULL),((unsigned int)3428514418ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 110\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)386902161ULL),((unsigned int)4198791913ULL),((unsigned int)1640645113ULL),((unsigned int)1988948550ULL)};
unsigned int b_0[4]={((unsigned int)386902161ULL),((unsigned int)4198791913ULL),((unsigned int)1640645113ULL),((unsigned int)1988948550ULL)};
unsigned int a_1[4]={((unsigned int)1597302232ULL),((unsigned int)1357519376ULL),((unsigned int)1409916118ULL),((unsigned int)3158308483ULL)};
unsigned int b_1[4]={((unsigned int)1597302232ULL),((unsigned int)1357519376ULL),((unsigned int)1409916118ULL),((unsigned int)3158308483ULL)};
unsigned int a_2[4]={((unsigned int)2263044423ULL),((unsigned int)2255331331ULL),((unsigned int)385236672ULL),((unsigned int)1327138688ULL)};
unsigned int b_2[4]={((unsigned int)2263044423ULL),((unsigned int)2255331331ULL),((unsigned int)385236672ULL),((unsigned int)1327138688ULL)};
unsigned int a_3[4]={((unsigned int)2109617254ULL),((unsigned int)2525437400ULL),((unsigned int)217725043ULL),((unsigned int)1313188182ULL)};
unsigned int b_3[4]={((unsigned int)2109617254ULL),((unsigned int)2525437400ULL),((unsigned int)217725043ULL),((unsigned int)1313188182ULL)};
unsigned int a_4[16]={((unsigned int)34509848ULL),((unsigned int)392998468ULL),((unsigned int)1123259274ULL),((unsigned int)2793356521ULL),((unsigned int)1472839712ULL),((unsigned int)2741800121ULL),((unsigned int)1349809266ULL),((unsigned int)1703722603ULL),((unsigned int)481418190ULL),((unsigned int)188306753ULL),((unsigned int)2562104915ULL),((unsigned int)4097004399ULL),((unsigned int)334285440ULL),((unsigned int)3850137681ULL),((unsigned int)3012612062ULL),((unsigned int)3234524695ULL)};
unsigned int b_4[16]={((unsigned int)34509848ULL),((unsigned int)392998468ULL),((unsigned int)1123259274ULL),((unsigned int)2793356521ULL),((unsigned int)1472839712ULL),((unsigned int)2741800121ULL),((unsigned int)1349809266ULL),((unsigned int)1703722603ULL),((unsigned int)481418190ULL),((unsigned int)188306753ULL),((unsigned int)2562104915ULL),((unsigned int)4097004399ULL),((unsigned int)334285440ULL),((unsigned int)3850137681ULL),((unsigned int)3012612062ULL),((unsigned int)3234524695ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 111\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)758900177ULL),((unsigned int)296458506ULL),((unsigned int)2925669664ULL),((unsigned int)1879529018ULL)};
unsigned int b_0[4]={((unsigned int)758900177ULL),((unsigned int)296458506ULL),((unsigned int)2925669664ULL),((unsigned int)1879529018ULL)};
unsigned int a_1[4]={((unsigned int)4150054518ULL),((unsigned int)1157898456ULL),((unsigned int)4009955196ULL),((unsigned int)1017229340ULL)};
unsigned int b_1[4]={((unsigned int)4150054518ULL),((unsigned int)1157898456ULL),((unsigned int)4009955196ULL),((unsigned int)1017229340ULL)};
unsigned int a_2[4]={((unsigned int)1265014626ULL),((unsigned int)3527253733ULL),((unsigned int)212294717ULL),((unsigned int)3882397625ULL)};
unsigned int b_2[4]={((unsigned int)1265014626ULL),((unsigned int)3527253733ULL),((unsigned int)212294717ULL),((unsigned int)3882397625ULL)};
unsigned int a_3[4]={((unsigned int)2895585306ULL),((unsigned int)1674155952ULL),((unsigned int)516502138ULL),((unsigned int)4069761533ULL)};
unsigned int b_3[4]={((unsigned int)2895585306ULL),((unsigned int)1674155952ULL),((unsigned int)516502138ULL),((unsigned int)4069761533ULL)};
unsigned int a_4[16]={((unsigned int)717001308ULL),((unsigned int)603381277ULL),((unsigned int)375811660ULL),((unsigned int)828488777ULL),((unsigned int)3926812356ULL),((unsigned int)783532787ULL),((unsigned int)945765180ULL),((unsigned int)1769126010ULL),((unsigned int)3619989701ULL),((unsigned int)3624488076ULL),((unsigned int)2332483537ULL),((unsigned int)3858549535ULL),((unsigned int)2582982317ULL),((unsigned int)1267455408ULL),((unsigned int)3564792971ULL),((unsigned int)1569933296ULL)};
unsigned int b_4[16]={((unsigned int)717001308ULL),((unsigned int)603381277ULL),((unsigned int)375811660ULL),((unsigned int)828488777ULL),((unsigned int)3926812356ULL),((unsigned int)783532787ULL),((unsigned int)945765180ULL),((unsigned int)1769126010ULL),((unsigned int)3619989701ULL),((unsigned int)3624488076ULL),((unsigned int)2332483537ULL),((unsigned int)3858549535ULL),((unsigned int)2582982317ULL),((unsigned int)1267455408ULL),((unsigned int)3564792971ULL),((unsigned int)1569933296ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 112\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3022164002ULL),((unsigned int)81517264ULL),((unsigned int)552103132ULL),((unsigned int)2604707551ULL)};
unsigned int b_0[4]={((unsigned int)3022164002ULL),((unsigned int)81517264ULL),((unsigned int)552103132ULL),((unsigned int)2604707551ULL)};
unsigned int a_1[4]={((unsigned int)3380866362ULL),((unsigned int)2731718706ULL),((unsigned int)4134471149ULL),((unsigned int)1762812845ULL)};
unsigned int b_1[4]={((unsigned int)3380866362ULL),((unsigned int)2731718706ULL),((unsigned int)4134471149ULL),((unsigned int)1762812845ULL)};
unsigned int a_2[4]={((unsigned int)2794392022ULL),((unsigned int)3620804823ULL),((unsigned int)574175599ULL),((unsigned int)2166983824ULL)};
unsigned int b_2[4]={((unsigned int)2794392022ULL),((unsigned int)3620804823ULL),((unsigned int)574175599ULL),((unsigned int)2166983824ULL)};
unsigned int a_3[4]={((unsigned int)1833978209ULL),((unsigned int)1999260468ULL),((unsigned int)3110097468ULL),((unsigned int)841270948ULL)};
unsigned int b_3[4]={((unsigned int)1833978209ULL),((unsigned int)1999260468ULL),((unsigned int)3110097468ULL),((unsigned int)841270948ULL)};
unsigned int a_4[16]={((unsigned int)1352249714ULL),((unsigned int)1006413280ULL),((unsigned int)2877159604ULL),((unsigned int)3810993324ULL),((unsigned int)3503642264ULL),((unsigned int)2247910833ULL),((unsigned int)2985813728ULL),((unsigned int)480067427ULL),((unsigned int)4253617452ULL),((unsigned int)2418719908ULL),((unsigned int)489850554ULL),((unsigned int)1228388980ULL),((unsigned int)2902502130ULL),((unsigned int)1277815249ULL),((unsigned int)2561374438ULL),((unsigned int)3908004360ULL)};
unsigned int b_4[16]={((unsigned int)1352249714ULL),((unsigned int)1006413280ULL),((unsigned int)2877159604ULL),((unsigned int)3810993324ULL),((unsigned int)3503642264ULL),((unsigned int)2247910833ULL),((unsigned int)2985813728ULL),((unsigned int)480067427ULL),((unsigned int)4253617452ULL),((unsigned int)2418719908ULL),((unsigned int)489850554ULL),((unsigned int)1228388980ULL),((unsigned int)2902502130ULL),((unsigned int)1277815249ULL),((unsigned int)2561374438ULL),((unsigned int)3908004360ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 113\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1149098858ULL),((unsigned int)2198746612ULL),((unsigned int)3568108174ULL),((unsigned int)29040324ULL)};
unsigned int b_0[4]={((unsigned int)1149098858ULL),((unsigned int)2198746612ULL),((unsigned int)3568108174ULL),((unsigned int)29040324ULL)};
unsigned int a_1[4]={((unsigned int)2874681744ULL),((unsigned int)727333583ULL),((unsigned int)2101749338ULL),((unsigned int)1511789247ULL)};
unsigned int b_1[4]={((unsigned int)2874681744ULL),((unsigned int)727333583ULL),((unsigned int)2101749338ULL),((unsigned int)1511789247ULL)};
unsigned int a_2[4]={((unsigned int)3364302263ULL),((unsigned int)181486166ULL),((unsigned int)3971378326ULL),((unsigned int)744658924ULL)};
unsigned int b_2[4]={((unsigned int)3364302263ULL),((unsigned int)181486166ULL),((unsigned int)3971378326ULL),((unsigned int)744658924ULL)};
unsigned int a_3[4]={((unsigned int)3002433233ULL),((unsigned int)1349053544ULL),((unsigned int)3361263521ULL),((unsigned int)225345255ULL)};
unsigned int b_3[4]={((unsigned int)3002433233ULL),((unsigned int)1349053544ULL),((unsigned int)3361263521ULL),((unsigned int)225345255ULL)};
unsigned int a_4[16]={((unsigned int)2240215809ULL),((unsigned int)3375168681ULL),((unsigned int)1455777809ULL),((unsigned int)3201753351ULL),((unsigned int)1754641522ULL),((unsigned int)3540003891ULL),((unsigned int)1605849929ULL),((unsigned int)322471825ULL),((unsigned int)3607349243ULL),((unsigned int)4271601671ULL),((unsigned int)3331877549ULL),((unsigned int)681549554ULL),((unsigned int)843292311ULL),((unsigned int)362301664ULL),((unsigned int)457022441ULL),((unsigned int)2370495041ULL)};
unsigned int b_4[16]={((unsigned int)2240215809ULL),((unsigned int)3375168681ULL),((unsigned int)1455777809ULL),((unsigned int)3201753351ULL),((unsigned int)1754641522ULL),((unsigned int)3540003891ULL),((unsigned int)1605849929ULL),((unsigned int)322471825ULL),((unsigned int)3607349243ULL),((unsigned int)4271601671ULL),((unsigned int)3331877549ULL),((unsigned int)681549554ULL),((unsigned int)843292311ULL),((unsigned int)362301664ULL),((unsigned int)457022441ULL),((unsigned int)2370495041ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 114\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3500380401ULL),((unsigned int)1243334911ULL),((unsigned int)1527960545ULL),((unsigned int)3425038812ULL)};
unsigned int b_0[4]={((unsigned int)3500380401ULL),((unsigned int)1243334911ULL),((unsigned int)1527960545ULL),((unsigned int)3425038812ULL)};
unsigned int a_1[4]={((unsigned int)1571155432ULL),((unsigned int)2875592951ULL),((unsigned int)3635436300ULL),((unsigned int)3025709492ULL)};
unsigned int b_1[4]={((unsigned int)1571155432ULL),((unsigned int)2875592951ULL),((unsigned int)3635436300ULL),((unsigned int)3025709492ULL)};
unsigned int a_2[4]={((unsigned int)2116916ULL),((unsigned int)1387802131ULL),((unsigned int)3689520446ULL),((unsigned int)1647452915ULL)};
unsigned int b_2[4]={((unsigned int)2116916ULL),((unsigned int)1387802131ULL),((unsigned int)3689520446ULL),((unsigned int)1647452915ULL)};
unsigned int a_3[4]={((unsigned int)3102239690ULL),((unsigned int)554016893ULL),((unsigned int)1585337876ULL),((unsigned int)3841080838ULL)};
unsigned int b_3[4]={((unsigned int)3102239690ULL),((unsigned int)554016893ULL),((unsigned int)1585337876ULL),((unsigned int)3841080838ULL)};
unsigned int a_4[16]={((unsigned int)1542929339ULL),((unsigned int)4270000059ULL),((unsigned int)797429582ULL),((unsigned int)3018835312ULL),((unsigned int)1707594942ULL),((unsigned int)3765110050ULL),((unsigned int)3088356542ULL),((unsigned int)1748483723ULL),((unsigned int)2599926874ULL),((unsigned int)2221600486ULL),((unsigned int)1170997371ULL),((unsigned int)2202163095ULL),((unsigned int)4109664722ULL),((unsigned int)58179224ULL),((unsigned int)362367027ULL),((unsigned int)2136632935ULL)};
unsigned int b_4[16]={((unsigned int)1542929339ULL),((unsigned int)4270000059ULL),((unsigned int)797429582ULL),((unsigned int)3018835312ULL),((unsigned int)1707594942ULL),((unsigned int)3765110050ULL),((unsigned int)3088356542ULL),((unsigned int)1748483723ULL),((unsigned int)2599926874ULL),((unsigned int)2221600486ULL),((unsigned int)1170997371ULL),((unsigned int)2202163095ULL),((unsigned int)4109664722ULL),((unsigned int)58179224ULL),((unsigned int)362367027ULL),((unsigned int)2136632935ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 115\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3525804579ULL),((unsigned int)4256475667ULL),((unsigned int)3713501231ULL),((unsigned int)1578044301ULL)};
unsigned int b_0[4]={((unsigned int)3525804579ULL),((unsigned int)4256475667ULL),((unsigned int)3713501231ULL),((unsigned int)1578044301ULL)};
unsigned int a_1[4]={((unsigned int)2105700238ULL),((unsigned int)1046641712ULL),((unsigned int)3751870869ULL),((unsigned int)3628163163ULL)};
unsigned int b_1[4]={((unsigned int)2105700238ULL),((unsigned int)1046641712ULL),((unsigned int)3751870869ULL),((unsigned int)3628163163ULL)};
unsigned int a_2[4]={((unsigned int)2694109929ULL),((unsigned int)2441090251ULL),((unsigned int)3674145432ULL),((unsigned int)995267319ULL)};
unsigned int b_2[4]={((unsigned int)2694109929ULL),((unsigned int)2441090251ULL),((unsigned int)3674145432ULL),((unsigned int)995267319ULL)};
unsigned int a_3[4]={((unsigned int)2157871304ULL),((unsigned int)812939407ULL),((unsigned int)3930442788ULL),((unsigned int)2213359181ULL)};
unsigned int b_3[4]={((unsigned int)2157871304ULL),((unsigned int)812939407ULL),((unsigned int)3930442788ULL),((unsigned int)2213359181ULL)};
unsigned int a_4[16]={((unsigned int)2170860453ULL),((unsigned int)978108910ULL),((unsigned int)2901220775ULL),((unsigned int)1900916436ULL),((unsigned int)185141752ULL),((unsigned int)1583512842ULL),((unsigned int)1051875339ULL),((unsigned int)3812332960ULL),((unsigned int)1828256026ULL),((unsigned int)271845368ULL),((unsigned int)1181369153ULL),((unsigned int)377550749ULL),((unsigned int)975878574ULL),((unsigned int)434197260ULL),((unsigned int)1258528842ULL),((unsigned int)4019023411ULL)};
unsigned int b_4[16]={((unsigned int)2170860453ULL),((unsigned int)978108910ULL),((unsigned int)2901220775ULL),((unsigned int)1900916436ULL),((unsigned int)185141752ULL),((unsigned int)1583512842ULL),((unsigned int)1051875339ULL),((unsigned int)3812332960ULL),((unsigned int)1828256026ULL),((unsigned int)271845368ULL),((unsigned int)1181369153ULL),((unsigned int)377550749ULL),((unsigned int)975878574ULL),((unsigned int)434197260ULL),((unsigned int)1258528842ULL),((unsigned int)4019023411ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 116\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)420464791ULL),((unsigned int)2514578076ULL),((unsigned int)2492051522ULL),((unsigned int)1046095506ULL)};
unsigned int b_0[4]={((unsigned int)420464791ULL),((unsigned int)2514578076ULL),((unsigned int)2492051522ULL),((unsigned int)1046095506ULL)};
unsigned int a_1[4]={((unsigned int)3107552070ULL),((unsigned int)1873996571ULL),((unsigned int)3638534015ULL),((unsigned int)1725605234ULL)};
unsigned int b_1[4]={((unsigned int)3107552070ULL),((unsigned int)1873996571ULL),((unsigned int)3638534015ULL),((unsigned int)1725605234ULL)};
unsigned int a_2[4]={((unsigned int)3051676936ULL),((unsigned int)2266292519ULL),((unsigned int)1102989219ULL),((unsigned int)1410947999ULL)};
unsigned int b_2[4]={((unsigned int)3051676936ULL),((unsigned int)2266292519ULL),((unsigned int)1102989219ULL),((unsigned int)1410947999ULL)};
unsigned int a_3[4]={((unsigned int)1358387485ULL),((unsigned int)1257842564ULL),((unsigned int)3818869466ULL),((unsigned int)2725841914ULL)};
unsigned int b_3[4]={((unsigned int)1358387485ULL),((unsigned int)1257842564ULL),((unsigned int)3818869466ULL),((unsigned int)2725841914ULL)};
unsigned int a_4[16]={((unsigned int)4038708285ULL),((unsigned int)3888949885ULL),((unsigned int)2538641676ULL),((unsigned int)256714972ULL),((unsigned int)3397050648ULL),((unsigned int)3138161612ULL),((unsigned int)941226465ULL),((unsigned int)1395423343ULL),((unsigned int)2761968484ULL),((unsigned int)182153428ULL),((unsigned int)3402268490ULL),((unsigned int)2402460950ULL),((unsigned int)1107592438ULL),((unsigned int)3699627116ULL),((unsigned int)344038250ULL),((unsigned int)3805331560ULL)};
unsigned int b_4[16]={((unsigned int)4038708285ULL),((unsigned int)3888949885ULL),((unsigned int)2538641676ULL),((unsigned int)256714972ULL),((unsigned int)3397050648ULL),((unsigned int)3138161612ULL),((unsigned int)941226465ULL),((unsigned int)1395423343ULL),((unsigned int)2761968484ULL),((unsigned int)182153428ULL),((unsigned int)3402268490ULL),((unsigned int)2402460950ULL),((unsigned int)1107592438ULL),((unsigned int)3699627116ULL),((unsigned int)344038250ULL),((unsigned int)3805331560ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 117\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2949849163ULL),((unsigned int)1472252144ULL),((unsigned int)1759261720ULL),((unsigned int)4079198582ULL)};
unsigned int b_0[4]={((unsigned int)2949849163ULL),((unsigned int)1472252144ULL),((unsigned int)1759261720ULL),((unsigned int)4079198582ULL)};
unsigned int a_1[4]={((unsigned int)2590435338ULL),((unsigned int)4000685529ULL),((unsigned int)3223128647ULL),((unsigned int)3827424893ULL)};
unsigned int b_1[4]={((unsigned int)2590435338ULL),((unsigned int)4000685529ULL),((unsigned int)3223128647ULL),((unsigned int)3827424893ULL)};
unsigned int a_2[4]={((unsigned int)497963684ULL),((unsigned int)2209287286ULL),((unsigned int)3040028241ULL),((unsigned int)660098013ULL)};
unsigned int b_2[4]={((unsigned int)497963684ULL),((unsigned int)2209287286ULL),((unsigned int)3040028241ULL),((unsigned int)660098013ULL)};
unsigned int a_3[4]={((unsigned int)1692275926ULL),((unsigned int)1236755480ULL),((unsigned int)985929034ULL),((unsigned int)3716237923ULL)};
unsigned int b_3[4]={((unsigned int)1692275926ULL),((unsigned int)1236755480ULL),((unsigned int)985929034ULL),((unsigned int)3716237923ULL)};
unsigned int a_4[16]={((unsigned int)1876710137ULL),((unsigned int)1570517736ULL),((unsigned int)3330943397ULL),((unsigned int)774913244ULL),((unsigned int)2443648686ULL),((unsigned int)1167649011ULL),((unsigned int)2157026067ULL),((unsigned int)3459832224ULL),((unsigned int)2312412389ULL),((unsigned int)906060044ULL),((unsigned int)3523189887ULL),((unsigned int)4206405880ULL),((unsigned int)3481348240ULL),((unsigned int)3799433678ULL),((unsigned int)3227938116ULL),((unsigned int)2197741538ULL)};
unsigned int b_4[16]={((unsigned int)1876710137ULL),((unsigned int)1570517736ULL),((unsigned int)3330943397ULL),((unsigned int)774913244ULL),((unsigned int)2443648686ULL),((unsigned int)1167649011ULL),((unsigned int)2157026067ULL),((unsigned int)3459832224ULL),((unsigned int)2312412389ULL),((unsigned int)906060044ULL),((unsigned int)3523189887ULL),((unsigned int)4206405880ULL),((unsigned int)3481348240ULL),((unsigned int)3799433678ULL),((unsigned int)3227938116ULL),((unsigned int)2197741538ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 118\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3588003970ULL),((unsigned int)937122691ULL),((unsigned int)3119767610ULL),((unsigned int)1708214375ULL)};
unsigned int b_0[4]={((unsigned int)3588003970ULL),((unsigned int)937122691ULL),((unsigned int)3119767610ULL),((unsigned int)1708214375ULL)};
unsigned int a_1[4]={((unsigned int)66825710ULL),((unsigned int)270169930ULL),((unsigned int)659740061ULL),((unsigned int)1501013508ULL)};
unsigned int b_1[4]={((unsigned int)66825710ULL),((unsigned int)270169930ULL),((unsigned int)659740061ULL),((unsigned int)1501013508ULL)};
unsigned int a_2[4]={((unsigned int)3654701429ULL),((unsigned int)1596570075ULL),((unsigned int)2565557527ULL),((unsigned int)331107345ULL)};
unsigned int b_2[4]={((unsigned int)3654701429ULL),((unsigned int)1596570075ULL),((unsigned int)2565557527ULL),((unsigned int)331107345ULL)};
unsigned int a_3[4]={((unsigned int)4012710311ULL),((unsigned int)3302995735ULL),((unsigned int)2647689688ULL),((unsigned int)2049596568ULL)};
unsigned int b_3[4]={((unsigned int)4012710311ULL),((unsigned int)3302995735ULL),((unsigned int)2647689688ULL),((unsigned int)2049596568ULL)};
unsigned int a_4[16]={((unsigned int)1243244333ULL),((unsigned int)1061553156ULL),((unsigned int)1867174900ULL),((unsigned int)1588130492ULL),((unsigned int)2552088454ULL),((unsigned int)182465478ULL),((unsigned int)1628827556ULL),((unsigned int)4012869887ULL),((unsigned int)3245637174ULL),((unsigned int)1240061915ULL),((unsigned int)1360837313ULL),((unsigned int)1760206193ULL),((unsigned int)1037871640ULL),((unsigned int)798168458ULL),((unsigned int)4159468343ULL),((unsigned int)2423061961ULL)};
unsigned int b_4[16]={((unsigned int)1243244333ULL),((unsigned int)1061553156ULL),((unsigned int)1867174900ULL),((unsigned int)1588130492ULL),((unsigned int)2552088454ULL),((unsigned int)182465478ULL),((unsigned int)1628827556ULL),((unsigned int)4012869887ULL),((unsigned int)3245637174ULL),((unsigned int)1240061915ULL),((unsigned int)1360837313ULL),((unsigned int)1760206193ULL),((unsigned int)1037871640ULL),((unsigned int)798168458ULL),((unsigned int)4159468343ULL),((unsigned int)2423061961ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 119\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3010699087ULL),((unsigned int)669644053ULL),((unsigned int)1320316631ULL),((unsigned int)1782924953ULL)};
unsigned int b_0[4]={((unsigned int)3010699087ULL),((unsigned int)669644053ULL),((unsigned int)1320316631ULL),((unsigned int)1782924953ULL)};
unsigned int a_1[4]={((unsigned int)1763589150ULL),((unsigned int)93968438ULL),((unsigned int)1488519323ULL),((unsigned int)4159200038ULL)};
unsigned int b_1[4]={((unsigned int)1763589150ULL),((unsigned int)93968438ULL),((unsigned int)1488519323ULL),((unsigned int)4159200038ULL)};
unsigned int a_2[4]={((unsigned int)1252758847ULL),((unsigned int)1590903542ULL),((unsigned int)1527303952ULL),((unsigned int)3975829184ULL)};
unsigned int b_2[4]={((unsigned int)1252758847ULL),((unsigned int)1590903542ULL),((unsigned int)1527303952ULL),((unsigned int)3975829184ULL)};
unsigned int a_3[4]={((unsigned int)3700335225ULL),((unsigned int)1012339889ULL),((unsigned int)856974403ULL),((unsigned int)4181745744ULL)};
unsigned int b_3[4]={((unsigned int)3700335225ULL),((unsigned int)1012339889ULL),((unsigned int)856974403ULL),((unsigned int)4181745744ULL)};
unsigned int a_4[16]={((unsigned int)2150959817ULL),((unsigned int)3990885508ULL),((unsigned int)1295334632ULL),((unsigned int)3820270981ULL),((unsigned int)470098577ULL),((unsigned int)1413229550ULL),((unsigned int)2261374149ULL),((unsigned int)3441915647ULL),((unsigned int)1014618389ULL),((unsigned int)2226728830ULL),((unsigned int)1592378286ULL),((unsigned int)743173359ULL),((unsigned int)3212516643ULL),((unsigned int)1727358596ULL),((unsigned int)2381771972ULL),((unsigned int)2685471658ULL)};
unsigned int b_4[16]={((unsigned int)2150959817ULL),((unsigned int)3990885508ULL),((unsigned int)1295334632ULL),((unsigned int)3820270981ULL),((unsigned int)470098577ULL),((unsigned int)1413229550ULL),((unsigned int)2261374149ULL),((unsigned int)3441915647ULL),((unsigned int)1014618389ULL),((unsigned int)2226728830ULL),((unsigned int)1592378286ULL),((unsigned int)743173359ULL),((unsigned int)3212516643ULL),((unsigned int)1727358596ULL),((unsigned int)2381771972ULL),((unsigned int)2685471658ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 120\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3060240512ULL),((unsigned int)680926753ULL),((unsigned int)2414442544ULL),((unsigned int)1520578485ULL)};
unsigned int b_0[4]={((unsigned int)3060240512ULL),((unsigned int)680926753ULL),((unsigned int)2414442544ULL),((unsigned int)1520578485ULL)};
unsigned int a_1[4]={((unsigned int)873810177ULL),((unsigned int)1940902491ULL),((unsigned int)2774756093ULL),((unsigned int)2404523270ULL)};
unsigned int b_1[4]={((unsigned int)873810177ULL),((unsigned int)1940902491ULL),((unsigned int)2774756093ULL),((unsigned int)2404523270ULL)};
unsigned int a_2[4]={((unsigned int)3509137354ULL),((unsigned int)1527297992ULL),((unsigned int)1111243739ULL),((unsigned int)858978413ULL)};
unsigned int b_2[4]={((unsigned int)3509137354ULL),((unsigned int)1527297992ULL),((unsigned int)1111243739ULL),((unsigned int)858978413ULL)};
unsigned int a_3[4]={((unsigned int)1386775335ULL),((unsigned int)1386600242ULL),((unsigned int)238456995ULL),((unsigned int)28341447ULL)};
unsigned int b_3[4]={((unsigned int)1386775335ULL),((unsigned int)1386600242ULL),((unsigned int)238456995ULL),((unsigned int)28341447ULL)};
unsigned int a_4[16]={((unsigned int)4104963675ULL),((unsigned int)2834626186ULL),((unsigned int)51855958ULL),((unsigned int)661480884ULL),((unsigned int)3765052414ULL),((unsigned int)674210650ULL),((unsigned int)3454693399ULL),((unsigned int)4183040328ULL),((unsigned int)2427247743ULL),((unsigned int)158631887ULL),((unsigned int)653818022ULL),((unsigned int)3865367268ULL),((unsigned int)2880964004ULL),((unsigned int)3001607876ULL),((unsigned int)3790328207ULL),((unsigned int)1876531608ULL)};
unsigned int b_4[16]={((unsigned int)4104963675ULL),((unsigned int)2834626186ULL),((unsigned int)51855958ULL),((unsigned int)661480884ULL),((unsigned int)3765052414ULL),((unsigned int)674210650ULL),((unsigned int)3454693399ULL),((unsigned int)4183040328ULL),((unsigned int)2427247743ULL),((unsigned int)158631887ULL),((unsigned int)653818022ULL),((unsigned int)3865367268ULL),((unsigned int)2880964004ULL),((unsigned int)3001607876ULL),((unsigned int)3790328207ULL),((unsigned int)1876531608ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 121\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)669725314ULL),((unsigned int)2727250473ULL),((unsigned int)2994896440ULL),((unsigned int)791914990ULL)};
unsigned int b_0[4]={((unsigned int)669725314ULL),((unsigned int)2727250473ULL),((unsigned int)2994896440ULL),((unsigned int)791914990ULL)};
unsigned int a_1[4]={((unsigned int)2622101363ULL),((unsigned int)3953469236ULL),((unsigned int)1997018239ULL),((unsigned int)1910530635ULL)};
unsigned int b_1[4]={((unsigned int)2622101363ULL),((unsigned int)3953469236ULL),((unsigned int)1997018239ULL),((unsigned int)1910530635ULL)};
unsigned int a_2[4]={((unsigned int)2127009207ULL),((unsigned int)2470504955ULL),((unsigned int)2097033717ULL),((unsigned int)3476019483ULL)};
unsigned int b_2[4]={((unsigned int)2127009207ULL),((unsigned int)2470504955ULL),((unsigned int)2097033717ULL),((unsigned int)3476019483ULL)};
unsigned int a_3[4]={((unsigned int)955032542ULL),((unsigned int)4263948421ULL),((unsigned int)3572103510ULL),((unsigned int)1124529902ULL)};
unsigned int b_3[4]={((unsigned int)955032542ULL),((unsigned int)4263948421ULL),((unsigned int)3572103510ULL),((unsigned int)1124529902ULL)};
unsigned int a_4[16]={((unsigned int)2096330666ULL),((unsigned int)3645470156ULL),((unsigned int)1247895692ULL),((unsigned int)3811892989ULL),((unsigned int)221439614ULL),((unsigned int)4291628061ULL),((unsigned int)3819954738ULL),((unsigned int)1957151486ULL),((unsigned int)2177681134ULL),((unsigned int)3659597262ULL),((unsigned int)1795705961ULL),((unsigned int)262220578ULL),((unsigned int)2395527459ULL),((unsigned int)698758786ULL),((unsigned int)292251508ULL),((unsigned int)605011936ULL)};
unsigned int b_4[16]={((unsigned int)2096330666ULL),((unsigned int)3645470156ULL),((unsigned int)1247895692ULL),((unsigned int)3811892989ULL),((unsigned int)221439614ULL),((unsigned int)4291628061ULL),((unsigned int)3819954738ULL),((unsigned int)1957151486ULL),((unsigned int)2177681134ULL),((unsigned int)3659597262ULL),((unsigned int)1795705961ULL),((unsigned int)262220578ULL),((unsigned int)2395527459ULL),((unsigned int)698758786ULL),((unsigned int)292251508ULL),((unsigned int)605011936ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 122\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)336464135ULL),((unsigned int)602140359ULL),((unsigned int)1006546602ULL),((unsigned int)2740362751ULL)};
unsigned int b_0[4]={((unsigned int)336464135ULL),((unsigned int)602140359ULL),((unsigned int)1006546602ULL),((unsigned int)2740362751ULL)};
unsigned int a_1[4]={((unsigned int)1497445308ULL),((unsigned int)3304850660ULL),((unsigned int)4005021282ULL),((unsigned int)2686753227ULL)};
unsigned int b_1[4]={((unsigned int)1497445308ULL),((unsigned int)3304850660ULL),((unsigned int)4005021282ULL),((unsigned int)2686753227ULL)};
unsigned int a_2[4]={((unsigned int)2117567167ULL),((unsigned int)3411821061ULL),((unsigned int)258453586ULL),((unsigned int)2985454570ULL)};
unsigned int b_2[4]={((unsigned int)2117567167ULL),((unsigned int)3411821061ULL),((unsigned int)258453586ULL),((unsigned int)2985454570ULL)};
unsigned int a_3[4]={((unsigned int)4063951928ULL),((unsigned int)3048589193ULL),((unsigned int)3587412854ULL),((unsigned int)459168587ULL)};
unsigned int b_3[4]={((unsigned int)4063951928ULL),((unsigned int)3048589193ULL),((unsigned int)3587412854ULL),((unsigned int)459168587ULL)};
unsigned int a_4[16]={((unsigned int)4099037883ULL),((unsigned int)1518858447ULL),((unsigned int)3720083407ULL),((unsigned int)3009772461ULL),((unsigned int)2764316255ULL),((unsigned int)2201032201ULL),((unsigned int)668772964ULL),((unsigned int)286285485ULL),((unsigned int)3107867484ULL),((unsigned int)1042151378ULL),((unsigned int)1705761719ULL),((unsigned int)736720189ULL),((unsigned int)2152531300ULL),((unsigned int)746419613ULL),((unsigned int)862319724ULL),((unsigned int)3610526818ULL)};
unsigned int b_4[16]={((unsigned int)4099037883ULL),((unsigned int)1518858447ULL),((unsigned int)3720083407ULL),((unsigned int)3009772461ULL),((unsigned int)2764316255ULL),((unsigned int)2201032201ULL),((unsigned int)668772964ULL),((unsigned int)286285485ULL),((unsigned int)3107867484ULL),((unsigned int)1042151378ULL),((unsigned int)1705761719ULL),((unsigned int)736720189ULL),((unsigned int)2152531300ULL),((unsigned int)746419613ULL),((unsigned int)862319724ULL),((unsigned int)3610526818ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 123\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4221705674ULL),((unsigned int)3240196234ULL),((unsigned int)305077978ULL),((unsigned int)2985101799ULL)};
unsigned int b_0[4]={((unsigned int)4221705674ULL),((unsigned int)3240196234ULL),((unsigned int)305077978ULL),((unsigned int)2985101799ULL)};
unsigned int a_1[4]={((unsigned int)802919704ULL),((unsigned int)1901550589ULL),((unsigned int)2499626142ULL),((unsigned int)759490493ULL)};
unsigned int b_1[4]={((unsigned int)802919704ULL),((unsigned int)1901550589ULL),((unsigned int)2499626142ULL),((unsigned int)759490493ULL)};
unsigned int a_2[4]={((unsigned int)2271542235ULL),((unsigned int)3008831389ULL),((unsigned int)2556922743ULL),((unsigned int)1548069288ULL)};
unsigned int b_2[4]={((unsigned int)2271542235ULL),((unsigned int)3008831389ULL),((unsigned int)2556922743ULL),((unsigned int)1548069288ULL)};
unsigned int a_3[4]={((unsigned int)3870133545ULL),((unsigned int)392395906ULL),((unsigned int)503773ULL),((unsigned int)2285549630ULL)};
unsigned int b_3[4]={((unsigned int)3870133545ULL),((unsigned int)392395906ULL),((unsigned int)503773ULL),((unsigned int)2285549630ULL)};
unsigned int a_4[16]={((unsigned int)1925977726ULL),((unsigned int)367688077ULL),((unsigned int)713685524ULL),((unsigned int)208004778ULL),((unsigned int)546282746ULL),((unsigned int)3129284883ULL),((unsigned int)3399136701ULL),((unsigned int)4220886743ULL),((unsigned int)1866689002ULL),((unsigned int)3377939431ULL),((unsigned int)1111514702ULL),((unsigned int)357092460ULL),((unsigned int)2151560643ULL),((unsigned int)2876607585ULL),((unsigned int)737677907ULL),((unsigned int)1037280551ULL)};
unsigned int b_4[16]={((unsigned int)1925977726ULL),((unsigned int)367688077ULL),((unsigned int)713685524ULL),((unsigned int)208004778ULL),((unsigned int)546282746ULL),((unsigned int)3129284883ULL),((unsigned int)3399136701ULL),((unsigned int)4220886743ULL),((unsigned int)1866689002ULL),((unsigned int)3377939431ULL),((unsigned int)1111514702ULL),((unsigned int)357092460ULL),((unsigned int)2151560643ULL),((unsigned int)2876607585ULL),((unsigned int)737677907ULL),((unsigned int)1037280551ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 124\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)648908345ULL),((unsigned int)122708135ULL),((unsigned int)2937341203ULL),((unsigned int)4019151576ULL)};
unsigned int b_0[4]={((unsigned int)648908345ULL),((unsigned int)122708135ULL),((unsigned int)2937341203ULL),((unsigned int)4019151576ULL)};
unsigned int a_1[4]={((unsigned int)2837681856ULL),((unsigned int)945022278ULL),((unsigned int)812631615ULL),((unsigned int)1169464198ULL)};
unsigned int b_1[4]={((unsigned int)2837681856ULL),((unsigned int)945022278ULL),((unsigned int)812631615ULL),((unsigned int)1169464198ULL)};
unsigned int a_2[4]={((unsigned int)3915221070ULL),((unsigned int)3037398868ULL),((unsigned int)989973839ULL),((unsigned int)1856784969ULL)};
unsigned int b_2[4]={((unsigned int)3915221070ULL),((unsigned int)3037398868ULL),((unsigned int)989973839ULL),((unsigned int)1856784969ULL)};
unsigned int a_3[4]={((unsigned int)1518213365ULL),((unsigned int)538126707ULL),((unsigned int)400292112ULL),((unsigned int)2252268030ULL)};
unsigned int b_3[4]={((unsigned int)1518213365ULL),((unsigned int)538126707ULL),((unsigned int)400292112ULL),((unsigned int)2252268030ULL)};
unsigned int a_4[16]={((unsigned int)2244759185ULL),((unsigned int)3425325644ULL),((unsigned int)2432733975ULL),((unsigned int)1125465252ULL),((unsigned int)4058614164ULL),((unsigned int)3870131733ULL),((unsigned int)1955407061ULL),((unsigned int)3133323554ULL),((unsigned int)189602658ULL),((unsigned int)3473504802ULL),((unsigned int)3159895218ULL),((unsigned int)81990290ULL),((unsigned int)4224703787ULL),((unsigned int)3154850801ULL),((unsigned int)868436974ULL),((unsigned int)2315237041ULL)};
unsigned int b_4[16]={((unsigned int)2244759185ULL),((unsigned int)3425325644ULL),((unsigned int)2432733975ULL),((unsigned int)1125465252ULL),((unsigned int)4058614164ULL),((unsigned int)3870131733ULL),((unsigned int)1955407061ULL),((unsigned int)3133323554ULL),((unsigned int)189602658ULL),((unsigned int)3473504802ULL),((unsigned int)3159895218ULL),((unsigned int)81990290ULL),((unsigned int)4224703787ULL),((unsigned int)3154850801ULL),((unsigned int)868436974ULL),((unsigned int)2315237041ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 125\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1139658664ULL),((unsigned int)3336974802ULL),((unsigned int)1301904760ULL),((unsigned int)841493211ULL)};
unsigned int b_0[4]={((unsigned int)1139658664ULL),((unsigned int)3336974802ULL),((unsigned int)1301904760ULL),((unsigned int)841493211ULL)};
unsigned int a_1[4]={((unsigned int)1147098791ULL),((unsigned int)2428354757ULL),((unsigned int)4083777342ULL),((unsigned int)407979578ULL)};
unsigned int b_1[4]={((unsigned int)1147098791ULL),((unsigned int)2428354757ULL),((unsigned int)4083777342ULL),((unsigned int)407979578ULL)};
unsigned int a_2[4]={((unsigned int)558145443ULL),((unsigned int)1235859706ULL),((unsigned int)638293110ULL),((unsigned int)3649700246ULL)};
unsigned int b_2[4]={((unsigned int)558145443ULL),((unsigned int)1235859706ULL),((unsigned int)638293110ULL),((unsigned int)3649700246ULL)};
unsigned int a_3[4]={((unsigned int)1384465381ULL),((unsigned int)3336355343ULL),((unsigned int)1678402130ULL),((unsigned int)2238284348ULL)};
unsigned int b_3[4]={((unsigned int)1384465381ULL),((unsigned int)3336355343ULL),((unsigned int)1678402130ULL),((unsigned int)2238284348ULL)};
unsigned int a_4[16]={((unsigned int)3481689460ULL),((unsigned int)1876463565ULL),((unsigned int)2646513181ULL),((unsigned int)70809408ULL),((unsigned int)1657181885ULL),((unsigned int)1061353783ULL),((unsigned int)728665305ULL),((unsigned int)2603092007ULL),((unsigned int)3206316056ULL),((unsigned int)3579126955ULL),((unsigned int)78387707ULL),((unsigned int)403880413ULL),((unsigned int)3329905889ULL),((unsigned int)2531823085ULL),((unsigned int)2844789174ULL),((unsigned int)4229105557ULL)};
unsigned int b_4[16]={((unsigned int)3481689460ULL),((unsigned int)1876463565ULL),((unsigned int)2646513181ULL),((unsigned int)70809408ULL),((unsigned int)1657181885ULL),((unsigned int)1061353783ULL),((unsigned int)728665305ULL),((unsigned int)2603092007ULL),((unsigned int)3206316056ULL),((unsigned int)3579126955ULL),((unsigned int)78387707ULL),((unsigned int)403880413ULL),((unsigned int)3329905889ULL),((unsigned int)2531823085ULL),((unsigned int)2844789174ULL),((unsigned int)4229105557ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 126\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3181684093ULL),((unsigned int)3300866565ULL),((unsigned int)2887999662ULL),((unsigned int)3099775907ULL)};
unsigned int b_0[4]={((unsigned int)3181684093ULL),((unsigned int)3300866565ULL),((unsigned int)2887999662ULL),((unsigned int)3099775907ULL)};
unsigned int a_1[4]={((unsigned int)1331267459ULL),((unsigned int)981633805ULL),((unsigned int)3251637282ULL),((unsigned int)4126945977ULL)};
unsigned int b_1[4]={((unsigned int)1331267459ULL),((unsigned int)981633805ULL),((unsigned int)3251637282ULL),((unsigned int)4126945977ULL)};
unsigned int a_2[4]={((unsigned int)3531899770ULL),((unsigned int)1768397293ULL),((unsigned int)3210344832ULL),((unsigned int)2159517126ULL)};
unsigned int b_2[4]={((unsigned int)3531899770ULL),((unsigned int)1768397293ULL),((unsigned int)3210344832ULL),((unsigned int)2159517126ULL)};
unsigned int a_3[4]={((unsigned int)844636692ULL),((unsigned int)1876649473ULL),((unsigned int)4047266921ULL),((unsigned int)2471884275ULL)};
unsigned int b_3[4]={((unsigned int)844636692ULL),((unsigned int)1876649473ULL),((unsigned int)4047266921ULL),((unsigned int)2471884275ULL)};
unsigned int a_4[16]={((unsigned int)3570899003ULL),((unsigned int)855037445ULL),((unsigned int)2096724802ULL),((unsigned int)1208590972ULL),((unsigned int)1890399231ULL),((unsigned int)3520500336ULL),((unsigned int)3306197723ULL),((unsigned int)103696112ULL),((unsigned int)1819200802ULL),((unsigned int)1858885009ULL),((unsigned int)3817709803ULL),((unsigned int)2993055618ULL),((unsigned int)3092964067ULL),((unsigned int)3572695991ULL),((unsigned int)1799255294ULL),((unsigned int)1681772725ULL)};
unsigned int b_4[16]={((unsigned int)3570899003ULL),((unsigned int)855037445ULL),((unsigned int)2096724802ULL),((unsigned int)1208590972ULL),((unsigned int)1890399231ULL),((unsigned int)3520500336ULL),((unsigned int)3306197723ULL),((unsigned int)103696112ULL),((unsigned int)1819200802ULL),((unsigned int)1858885009ULL),((unsigned int)3817709803ULL),((unsigned int)2993055618ULL),((unsigned int)3092964067ULL),((unsigned int)3572695991ULL),((unsigned int)1799255294ULL),((unsigned int)1681772725ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 127\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1266277006ULL),((unsigned int)4020456127ULL),((unsigned int)2231883410ULL),((unsigned int)2195388823ULL)};
unsigned int b_0[4]={((unsigned int)1266277006ULL),((unsigned int)4020456127ULL),((unsigned int)2231883410ULL),((unsigned int)2195388823ULL)};
unsigned int a_1[4]={((unsigned int)2233609093ULL),((unsigned int)1788469041ULL),((unsigned int)4250035300ULL),((unsigned int)2740275267ULL)};
unsigned int b_1[4]={((unsigned int)2233609093ULL),((unsigned int)1788469041ULL),((unsigned int)4250035300ULL),((unsigned int)2740275267ULL)};
unsigned int a_2[4]={((unsigned int)1752224407ULL),((unsigned int)3265909455ULL),((unsigned int)1168166844ULL),((unsigned int)3988501551ULL)};
unsigned int b_2[4]={((unsigned int)1752224407ULL),((unsigned int)3265909455ULL),((unsigned int)1168166844ULL),((unsigned int)3988501551ULL)};
unsigned int a_3[4]={((unsigned int)2752788585ULL),((unsigned int)250888619ULL),((unsigned int)4055778364ULL),((unsigned int)4081902997ULL)};
unsigned int b_3[4]={((unsigned int)2752788585ULL),((unsigned int)250888619ULL),((unsigned int)4055778364ULL),((unsigned int)4081902997ULL)};
unsigned int a_4[16]={((unsigned int)1391743110ULL),((unsigned int)1178742418ULL),((unsigned int)3303173646ULL),((unsigned int)2921230840ULL),((unsigned int)2360231363ULL),((unsigned int)169117478ULL),((unsigned int)1146380600ULL),((unsigned int)202340361ULL),((unsigned int)4243588484ULL),((unsigned int)2162900407ULL),((unsigned int)677508801ULL),((unsigned int)761393104ULL),((unsigned int)4088915357ULL),((unsigned int)1416328576ULL),((unsigned int)1024969288ULL),((unsigned int)1014951384ULL)};
unsigned int b_4[16]={((unsigned int)1391743110ULL),((unsigned int)1178742418ULL),((unsigned int)3303173646ULL),((unsigned int)2921230840ULL),((unsigned int)2360231363ULL),((unsigned int)169117478ULL),((unsigned int)1146380600ULL),((unsigned int)202340361ULL),((unsigned int)4243588484ULL),((unsigned int)2162900407ULL),((unsigned int)677508801ULL),((unsigned int)761393104ULL),((unsigned int)4088915357ULL),((unsigned int)1416328576ULL),((unsigned int)1024969288ULL),((unsigned int)1014951384ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 128\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2170455067ULL),((unsigned int)386539940ULL),((unsigned int)2361107912ULL),((unsigned int)1542188600ULL)};
unsigned int b_0[4]={((unsigned int)2170455067ULL),((unsigned int)386539940ULL),((unsigned int)2361107912ULL),((unsigned int)1542188600ULL)};
unsigned int a_1[4]={((unsigned int)1172508828ULL),((unsigned int)2533669137ULL),((unsigned int)3365935663ULL),((unsigned int)2312848084ULL)};
unsigned int b_1[4]={((unsigned int)1172508828ULL),((unsigned int)2533669137ULL),((unsigned int)3365935663ULL),((unsigned int)2312848084ULL)};
unsigned int a_2[4]={((unsigned int)2610880833ULL),((unsigned int)1442905847ULL),((unsigned int)3299181962ULL),((unsigned int)2304636975ULL)};
unsigned int b_2[4]={((unsigned int)2610880833ULL),((unsigned int)1442905847ULL),((unsigned int)3299181962ULL),((unsigned int)2304636975ULL)};
unsigned int a_3[4]={((unsigned int)4042936827ULL),((unsigned int)1212194444ULL),((unsigned int)4016469724ULL),((unsigned int)2776829568ULL)};
unsigned int b_3[4]={((unsigned int)4042936827ULL),((unsigned int)1212194444ULL),((unsigned int)4016469724ULL),((unsigned int)2776829568ULL)};
unsigned int a_4[16]={((unsigned int)3232123571ULL),((unsigned int)2557023434ULL),((unsigned int)2277351591ULL),((unsigned int)2750286049ULL),((unsigned int)2331890875ULL),((unsigned int)2765165162ULL),((unsigned int)4102329566ULL),((unsigned int)2825429172ULL),((unsigned int)536420493ULL),((unsigned int)2956701817ULL),((unsigned int)1710648138ULL),((unsigned int)2938708494ULL),((unsigned int)1614609936ULL),((unsigned int)3212466430ULL),((unsigned int)3334671253ULL),((unsigned int)1718670855ULL)};
unsigned int b_4[16]={((unsigned int)3232123571ULL),((unsigned int)2557023434ULL),((unsigned int)2277351591ULL),((unsigned int)2750286049ULL),((unsigned int)2331890875ULL),((unsigned int)2765165162ULL),((unsigned int)4102329566ULL),((unsigned int)2825429172ULL),((unsigned int)536420493ULL),((unsigned int)2956701817ULL),((unsigned int)1710648138ULL),((unsigned int)2938708494ULL),((unsigned int)1614609936ULL),((unsigned int)3212466430ULL),((unsigned int)3334671253ULL),((unsigned int)1718670855ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 129\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1702507424ULL),((unsigned int)998228710ULL),((unsigned int)2530042019ULL),((unsigned int)2999528396ULL)};
unsigned int b_0[4]={((unsigned int)1702507424ULL),((unsigned int)998228710ULL),((unsigned int)2530042019ULL),((unsigned int)2999528396ULL)};
unsigned int a_1[4]={((unsigned int)3914049008ULL),((unsigned int)1945860120ULL),((unsigned int)3967638353ULL),((unsigned int)1998239496ULL)};
unsigned int b_1[4]={((unsigned int)3914049008ULL),((unsigned int)1945860120ULL),((unsigned int)3967638353ULL),((unsigned int)1998239496ULL)};
unsigned int a_2[4]={((unsigned int)1155181806ULL),((unsigned int)4188598664ULL),((unsigned int)3123504610ULL),((unsigned int)3333148613ULL)};
unsigned int b_2[4]={((unsigned int)1155181806ULL),((unsigned int)4188598664ULL),((unsigned int)3123504610ULL),((unsigned int)3333148613ULL)};
unsigned int a_3[4]={((unsigned int)1608738618ULL),((unsigned int)1536462613ULL),((unsigned int)495172391ULL),((unsigned int)2233920668ULL)};
unsigned int b_3[4]={((unsigned int)1608738618ULL),((unsigned int)1536462613ULL),((unsigned int)495172391ULL),((unsigned int)2233920668ULL)};
unsigned int a_4[16]={((unsigned int)806919506ULL),((unsigned int)3875069892ULL),((unsigned int)3669540034ULL),((unsigned int)3361415878ULL),((unsigned int)1160125962ULL),((unsigned int)252386840ULL),((unsigned int)3876981818ULL),((unsigned int)367181503ULL),((unsigned int)700627805ULL),((unsigned int)2840808102ULL),((unsigned int)2522674433ULL),((unsigned int)4005815837ULL),((unsigned int)3939817764ULL),((unsigned int)2416577090ULL),((unsigned int)1057996342ULL),((unsigned int)3193910125ULL)};
unsigned int b_4[16]={((unsigned int)806919506ULL),((unsigned int)3875069892ULL),((unsigned int)3669540034ULL),((unsigned int)3361415878ULL),((unsigned int)1160125962ULL),((unsigned int)252386840ULL),((unsigned int)3876981818ULL),((unsigned int)367181503ULL),((unsigned int)700627805ULL),((unsigned int)2840808102ULL),((unsigned int)2522674433ULL),((unsigned int)4005815837ULL),((unsigned int)3939817764ULL),((unsigned int)2416577090ULL),((unsigned int)1057996342ULL),((unsigned int)3193910125ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 130\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3075406173ULL),((unsigned int)3309461710ULL),((unsigned int)3646833885ULL),((unsigned int)358176660ULL)};
unsigned int b_0[4]={((unsigned int)3075406173ULL),((unsigned int)3309461710ULL),((unsigned int)3646833885ULL),((unsigned int)358176660ULL)};
unsigned int a_1[4]={((unsigned int)1158896397ULL),((unsigned int)1658556790ULL),((unsigned int)463130472ULL),((unsigned int)514876518ULL)};
unsigned int b_1[4]={((unsigned int)1158896397ULL),((unsigned int)1658556790ULL),((unsigned int)463130472ULL),((unsigned int)514876518ULL)};
unsigned int a_2[4]={((unsigned int)626954309ULL),((unsigned int)3731553832ULL),((unsigned int)210740273ULL),((unsigned int)2533268490ULL)};
unsigned int b_2[4]={((unsigned int)626954309ULL),((unsigned int)3731553832ULL),((unsigned int)210740273ULL),((unsigned int)2533268490ULL)};
unsigned int a_3[4]={((unsigned int)666773678ULL),((unsigned int)3619245844ULL),((unsigned int)3264637454ULL),((unsigned int)3823028422ULL)};
unsigned int b_3[4]={((unsigned int)666773678ULL),((unsigned int)3619245844ULL),((unsigned int)3264637454ULL),((unsigned int)3823028422ULL)};
unsigned int a_4[16]={((unsigned int)2835989652ULL),((unsigned int)3879323354ULL),((unsigned int)1510857326ULL),((unsigned int)3472995178ULL),((unsigned int)5000228ULL),((unsigned int)1835062455ULL),((unsigned int)3375992417ULL),((unsigned int)2435806295ULL),((unsigned int)3985513633ULL),((unsigned int)2609052852ULL),((unsigned int)4224078781ULL),((unsigned int)4122349672ULL),((unsigned int)2361238928ULL),((unsigned int)2247377471ULL),((unsigned int)188928776ULL),((unsigned int)2982775672ULL)};
unsigned int b_4[16]={((unsigned int)2835989652ULL),((unsigned int)3879323354ULL),((unsigned int)1510857326ULL),((unsigned int)3472995178ULL),((unsigned int)5000228ULL),((unsigned int)1835062455ULL),((unsigned int)3375992417ULL),((unsigned int)2435806295ULL),((unsigned int)3985513633ULL),((unsigned int)2609052852ULL),((unsigned int)4224078781ULL),((unsigned int)4122349672ULL),((unsigned int)2361238928ULL),((unsigned int)2247377471ULL),((unsigned int)188928776ULL),((unsigned int)2982775672ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 131\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3008045006ULL),((unsigned int)2376144196ULL),((unsigned int)2588178254ULL),((unsigned int)4136666199ULL)};
unsigned int b_0[4]={((unsigned int)3008045006ULL),((unsigned int)2376144196ULL),((unsigned int)2588178254ULL),((unsigned int)4136666199ULL)};
unsigned int a_1[4]={((unsigned int)2357648699ULL),((unsigned int)1757536308ULL),((unsigned int)3796422639ULL),((unsigned int)836645776ULL)};
unsigned int b_1[4]={((unsigned int)2357648699ULL),((unsigned int)1757536308ULL),((unsigned int)3796422639ULL),((unsigned int)836645776ULL)};
unsigned int a_2[4]={((unsigned int)2188147090ULL),((unsigned int)454244400ULL),((unsigned int)2846362937ULL),((unsigned int)2990422400ULL)};
unsigned int b_2[4]={((unsigned int)2188147090ULL),((unsigned int)454244400ULL),((unsigned int)2846362937ULL),((unsigned int)2990422400ULL)};
unsigned int a_3[4]={((unsigned int)3073848533ULL),((unsigned int)485951693ULL),((unsigned int)331271137ULL),((unsigned int)289021044ULL)};
unsigned int b_3[4]={((unsigned int)3073848533ULL),((unsigned int)485951693ULL),((unsigned int)331271137ULL),((unsigned int)289021044ULL)};
unsigned int a_4[16]={((unsigned int)862788215ULL),((unsigned int)1865759615ULL),((unsigned int)281142371ULL),((unsigned int)3173272247ULL),((unsigned int)1728184612ULL),((unsigned int)359049761ULL),((unsigned int)315663240ULL),((unsigned int)113504270ULL),((unsigned int)724378106ULL),((unsigned int)3582070690ULL),((unsigned int)2946402506ULL),((unsigned int)2836865577ULL),((unsigned int)1255552528ULL),((unsigned int)2633473029ULL),((unsigned int)2826502126ULL),((unsigned int)4002196561ULL)};
unsigned int b_4[16]={((unsigned int)862788215ULL),((unsigned int)1865759615ULL),((unsigned int)281142371ULL),((unsigned int)3173272247ULL),((unsigned int)1728184612ULL),((unsigned int)359049761ULL),((unsigned int)315663240ULL),((unsigned int)113504270ULL),((unsigned int)724378106ULL),((unsigned int)3582070690ULL),((unsigned int)2946402506ULL),((unsigned int)2836865577ULL),((unsigned int)1255552528ULL),((unsigned int)2633473029ULL),((unsigned int)2826502126ULL),((unsigned int)4002196561ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 132\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3123653385ULL),((unsigned int)490925230ULL),((unsigned int)2887900497ULL),((unsigned int)2234997222ULL)};
unsigned int b_0[4]={((unsigned int)3123653385ULL),((unsigned int)490925230ULL),((unsigned int)2887900497ULL),((unsigned int)2234997222ULL)};
unsigned int a_1[4]={((unsigned int)813775058ULL),((unsigned int)113285432ULL),((unsigned int)3986386712ULL),((unsigned int)3847014983ULL)};
unsigned int b_1[4]={((unsigned int)813775058ULL),((unsigned int)113285432ULL),((unsigned int)3986386712ULL),((unsigned int)3847014983ULL)};
unsigned int a_2[4]={((unsigned int)3395800672ULL),((unsigned int)816076366ULL),((unsigned int)2727606558ULL),((unsigned int)504216462ULL)};
unsigned int b_2[4]={((unsigned int)3395800672ULL),((unsigned int)816076366ULL),((unsigned int)2727606558ULL),((unsigned int)504216462ULL)};
unsigned int a_3[4]={((unsigned int)774051441ULL),((unsigned int)2421944107ULL),((unsigned int)308514778ULL),((unsigned int)602000706ULL)};
unsigned int b_3[4]={((unsigned int)774051441ULL),((unsigned int)2421944107ULL),((unsigned int)308514778ULL),((unsigned int)602000706ULL)};
unsigned int a_4[16]={((unsigned int)4176880751ULL),((unsigned int)3568757353ULL),((unsigned int)142023947ULL),((unsigned int)4286787391ULL),((unsigned int)2604353266ULL),((unsigned int)3746508822ULL),((unsigned int)2797185561ULL),((unsigned int)3564094133ULL),((unsigned int)3320923869ULL),((unsigned int)2728841817ULL),((unsigned int)3159714882ULL),((unsigned int)2590104737ULL),((unsigned int)4086194598ULL),((unsigned int)2327662418ULL),((unsigned int)2417615986ULL),((unsigned int)4212767074ULL)};
unsigned int b_4[16]={((unsigned int)4176880751ULL),((unsigned int)3568757353ULL),((unsigned int)142023947ULL),((unsigned int)4286787391ULL),((unsigned int)2604353266ULL),((unsigned int)3746508822ULL),((unsigned int)2797185561ULL),((unsigned int)3564094133ULL),((unsigned int)3320923869ULL),((unsigned int)2728841817ULL),((unsigned int)3159714882ULL),((unsigned int)2590104737ULL),((unsigned int)4086194598ULL),((unsigned int)2327662418ULL),((unsigned int)2417615986ULL),((unsigned int)4212767074ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 133\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3012582757ULL),((unsigned int)495447424ULL),((unsigned int)3698239588ULL),((unsigned int)2613069927ULL)};
unsigned int b_0[4]={((unsigned int)3012582757ULL),((unsigned int)495447424ULL),((unsigned int)3698239588ULL),((unsigned int)2613069927ULL)};
unsigned int a_1[4]={((unsigned int)2480030914ULL),((unsigned int)3034640149ULL),((unsigned int)2942396878ULL),((unsigned int)1514939248ULL)};
unsigned int b_1[4]={((unsigned int)2480030914ULL),((unsigned int)3034640149ULL),((unsigned int)2942396878ULL),((unsigned int)1514939248ULL)};
unsigned int a_2[4]={((unsigned int)1550428078ULL),((unsigned int)2754504989ULL),((unsigned int)3221099538ULL),((unsigned int)3097750765ULL)};
unsigned int b_2[4]={((unsigned int)1550428078ULL),((unsigned int)2754504989ULL),((unsigned int)3221099538ULL),((unsigned int)3097750765ULL)};
unsigned int a_3[4]={((unsigned int)2715434139ULL),((unsigned int)2093777990ULL),((unsigned int)2327309197ULL),((unsigned int)264527504ULL)};
unsigned int b_3[4]={((unsigned int)2715434139ULL),((unsigned int)2093777990ULL),((unsigned int)2327309197ULL),((unsigned int)264527504ULL)};
unsigned int a_4[16]={((unsigned int)741035942ULL),((unsigned int)2583921429ULL),((unsigned int)2605345865ULL),((unsigned int)899429622ULL),((unsigned int)3672039238ULL),((unsigned int)3263129319ULL),((unsigned int)429219089ULL),((unsigned int)4282677284ULL),((unsigned int)375267491ULL),((unsigned int)3506754174ULL),((unsigned int)2523842364ULL),((unsigned int)2656849316ULL),((unsigned int)572974011ULL),((unsigned int)3404397010ULL),((unsigned int)1711386401ULL),((unsigned int)3326349200ULL)};
unsigned int b_4[16]={((unsigned int)741035942ULL),((unsigned int)2583921429ULL),((unsigned int)2605345865ULL),((unsigned int)899429622ULL),((unsigned int)3672039238ULL),((unsigned int)3263129319ULL),((unsigned int)429219089ULL),((unsigned int)4282677284ULL),((unsigned int)375267491ULL),((unsigned int)3506754174ULL),((unsigned int)2523842364ULL),((unsigned int)2656849316ULL),((unsigned int)572974011ULL),((unsigned int)3404397010ULL),((unsigned int)1711386401ULL),((unsigned int)3326349200ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 134\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)576608529ULL),((unsigned int)2982129451ULL),((unsigned int)2321441758ULL),((unsigned int)2761167582ULL)};
unsigned int b_0[4]={((unsigned int)576608529ULL),((unsigned int)2982129451ULL),((unsigned int)2321441758ULL),((unsigned int)2761167582ULL)};
unsigned int a_1[4]={((unsigned int)4146260895ULL),((unsigned int)2521761177ULL),((unsigned int)2876088229ULL),((unsigned int)2293936415ULL)};
unsigned int b_1[4]={((unsigned int)4146260895ULL),((unsigned int)2521761177ULL),((unsigned int)2876088229ULL),((unsigned int)2293936415ULL)};
unsigned int a_2[4]={((unsigned int)4267882547ULL),((unsigned int)1901823894ULL),((unsigned int)1221435518ULL),((unsigned int)3046479833ULL)};
unsigned int b_2[4]={((unsigned int)4267882547ULL),((unsigned int)1901823894ULL),((unsigned int)1221435518ULL),((unsigned int)3046479833ULL)};
unsigned int a_3[4]={((unsigned int)1980229756ULL),((unsigned int)1846051352ULL),((unsigned int)1304399628ULL),((unsigned int)1204927629ULL)};
unsigned int b_3[4]={((unsigned int)1980229756ULL),((unsigned int)1846051352ULL),((unsigned int)1304399628ULL),((unsigned int)1204927629ULL)};
unsigned int a_4[16]={((unsigned int)2221803030ULL),((unsigned int)3861805526ULL),((unsigned int)3081406706ULL),((unsigned int)2048138628ULL),((unsigned int)4162760502ULL),((unsigned int)2502196933ULL),((unsigned int)1326941717ULL),((unsigned int)4160608252ULL),((unsigned int)3369599578ULL),((unsigned int)45210836ULL),((unsigned int)698044938ULL),((unsigned int)1216554438ULL),((unsigned int)3189872035ULL),((unsigned int)2507402032ULL),((unsigned int)1924610592ULL),((unsigned int)2474938904ULL)};
unsigned int b_4[16]={((unsigned int)2221803030ULL),((unsigned int)3861805526ULL),((unsigned int)3081406706ULL),((unsigned int)2048138628ULL),((unsigned int)4162760502ULL),((unsigned int)2502196933ULL),((unsigned int)1326941717ULL),((unsigned int)4160608252ULL),((unsigned int)3369599578ULL),((unsigned int)45210836ULL),((unsigned int)698044938ULL),((unsigned int)1216554438ULL),((unsigned int)3189872035ULL),((unsigned int)2507402032ULL),((unsigned int)1924610592ULL),((unsigned int)2474938904ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 135\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3538857472ULL),((unsigned int)2132819277ULL),((unsigned int)3666365069ULL),((unsigned int)3733798682ULL)};
unsigned int b_0[4]={((unsigned int)3538857472ULL),((unsigned int)2132819277ULL),((unsigned int)3666365069ULL),((unsigned int)3733798682ULL)};
unsigned int a_1[4]={((unsigned int)1012223761ULL),((unsigned int)3450788339ULL),((unsigned int)391410924ULL),((unsigned int)3859260567ULL)};
unsigned int b_1[4]={((unsigned int)1012223761ULL),((unsigned int)3450788339ULL),((unsigned int)391410924ULL),((unsigned int)3859260567ULL)};
unsigned int a_2[4]={((unsigned int)426732485ULL),((unsigned int)2103228733ULL),((unsigned int)424458973ULL),((unsigned int)1563265999ULL)};
unsigned int b_2[4]={((unsigned int)426732485ULL),((unsigned int)2103228733ULL),((unsigned int)424458973ULL),((unsigned int)1563265999ULL)};
unsigned int a_3[4]={((unsigned int)699644849ULL),((unsigned int)205477626ULL),((unsigned int)3982893550ULL),((unsigned int)3761879036ULL)};
unsigned int b_3[4]={((unsigned int)699644849ULL),((unsigned int)205477626ULL),((unsigned int)3982893550ULL),((unsigned int)3761879036ULL)};
unsigned int a_4[16]={((unsigned int)253237126ULL),((unsigned int)81977282ULL),((unsigned int)983799346ULL),((unsigned int)17787017ULL),((unsigned int)4010947033ULL),((unsigned int)1300688298ULL),((unsigned int)2761631523ULL),((unsigned int)1592088867ULL),((unsigned int)1010468437ULL),((unsigned int)3054906118ULL),((unsigned int)3945608941ULL),((unsigned int)1240458101ULL),((unsigned int)1879130155ULL),((unsigned int)978615360ULL),((unsigned int)480664585ULL),((unsigned int)3837991337ULL)};
unsigned int b_4[16]={((unsigned int)253237126ULL),((unsigned int)81977282ULL),((unsigned int)983799346ULL),((unsigned int)17787017ULL),((unsigned int)4010947033ULL),((unsigned int)1300688298ULL),((unsigned int)2761631523ULL),((unsigned int)1592088867ULL),((unsigned int)1010468437ULL),((unsigned int)3054906118ULL),((unsigned int)3945608941ULL),((unsigned int)1240458101ULL),((unsigned int)1879130155ULL),((unsigned int)978615360ULL),((unsigned int)480664585ULL),((unsigned int)3837991337ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 136\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3744535762ULL),((unsigned int)562442343ULL),((unsigned int)2040442223ULL),((unsigned int)4170473927ULL)};
unsigned int b_0[4]={((unsigned int)3744535762ULL),((unsigned int)562442343ULL),((unsigned int)2040442223ULL),((unsigned int)4170473927ULL)};
unsigned int a_1[4]={((unsigned int)2976539863ULL),((unsigned int)3320630692ULL),((unsigned int)975072820ULL),((unsigned int)2420103510ULL)};
unsigned int b_1[4]={((unsigned int)2976539863ULL),((unsigned int)3320630692ULL),((unsigned int)975072820ULL),((unsigned int)2420103510ULL)};
unsigned int a_2[4]={((unsigned int)1544046488ULL),((unsigned int)4260234700ULL),((unsigned int)711560190ULL),((unsigned int)2080318944ULL)};
unsigned int b_2[4]={((unsigned int)1544046488ULL),((unsigned int)4260234700ULL),((unsigned int)711560190ULL),((unsigned int)2080318944ULL)};
unsigned int a_3[4]={((unsigned int)662482196ULL),((unsigned int)2442829359ULL),((unsigned int)3079314076ULL),((unsigned int)638420924ULL)};
unsigned int b_3[4]={((unsigned int)662482196ULL),((unsigned int)2442829359ULL),((unsigned int)3079314076ULL),((unsigned int)638420924ULL)};
unsigned int a_4[16]={((unsigned int)1569185037ULL),((unsigned int)2281157614ULL),((unsigned int)1320290488ULL),((unsigned int)481034797ULL),((unsigned int)2713369532ULL),((unsigned int)2053479256ULL),((unsigned int)3770756109ULL),((unsigned int)2645863660ULL),((unsigned int)2970310017ULL),((unsigned int)2248977072ULL),((unsigned int)2601538215ULL),((unsigned int)350537292ULL),((unsigned int)40519820ULL),((unsigned int)3075966341ULL),((unsigned int)3747120554ULL),((unsigned int)3071629633ULL)};
unsigned int b_4[16]={((unsigned int)1569185037ULL),((unsigned int)2281157614ULL),((unsigned int)1320290488ULL),((unsigned int)481034797ULL),((unsigned int)2713369532ULL),((unsigned int)2053479256ULL),((unsigned int)3770756109ULL),((unsigned int)2645863660ULL),((unsigned int)2970310017ULL),((unsigned int)2248977072ULL),((unsigned int)2601538215ULL),((unsigned int)350537292ULL),((unsigned int)40519820ULL),((unsigned int)3075966341ULL),((unsigned int)3747120554ULL),((unsigned int)3071629633ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 137\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)756225200ULL),((unsigned int)1766538606ULL),((unsigned int)839512752ULL),((unsigned int)1150281461ULL)};
unsigned int b_0[4]={((unsigned int)756225200ULL),((unsigned int)1766538606ULL),((unsigned int)839512752ULL),((unsigned int)1150281461ULL)};
unsigned int a_1[4]={((unsigned int)874378064ULL),((unsigned int)1453599230ULL),((unsigned int)3465525032ULL),((unsigned int)838954986ULL)};
unsigned int b_1[4]={((unsigned int)874378064ULL),((unsigned int)1453599230ULL),((unsigned int)3465525032ULL),((unsigned int)838954986ULL)};
unsigned int a_2[4]={((unsigned int)2911875554ULL),((unsigned int)486689723ULL),((unsigned int)290259130ULL),((unsigned int)4047324216ULL)};
unsigned int b_2[4]={((unsigned int)2911875554ULL),((unsigned int)486689723ULL),((unsigned int)290259130ULL),((unsigned int)4047324216ULL)};
unsigned int a_3[4]={((unsigned int)2469992673ULL),((unsigned int)4163000304ULL),((unsigned int)1052835686ULL),((unsigned int)3413727533ULL)};
unsigned int b_3[4]={((unsigned int)2469992673ULL),((unsigned int)4163000304ULL),((unsigned int)1052835686ULL),((unsigned int)3413727533ULL)};
unsigned int a_4[16]={((unsigned int)3518352884ULL),((unsigned int)1972196253ULL),((unsigned int)656178242ULL),((unsigned int)4029468630ULL),((unsigned int)442979323ULL),((unsigned int)2284085759ULL),((unsigned int)1862988660ULL),((unsigned int)4235077696ULL),((unsigned int)1661939089ULL),((unsigned int)2060988640ULL),((unsigned int)1030434670ULL),((unsigned int)2047359862ULL),((unsigned int)192678263ULL),((unsigned int)3428447653ULL),((unsigned int)1236044039ULL),((unsigned int)4203100665ULL)};
unsigned int b_4[16]={((unsigned int)3518352884ULL),((unsigned int)1972196253ULL),((unsigned int)656178242ULL),((unsigned int)4029468630ULL),((unsigned int)442979323ULL),((unsigned int)2284085759ULL),((unsigned int)1862988660ULL),((unsigned int)4235077696ULL),((unsigned int)1661939089ULL),((unsigned int)2060988640ULL),((unsigned int)1030434670ULL),((unsigned int)2047359862ULL),((unsigned int)192678263ULL),((unsigned int)3428447653ULL),((unsigned int)1236044039ULL),((unsigned int)4203100665ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 138\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4095042548ULL),((unsigned int)1539516982ULL),((unsigned int)3835904840ULL),((unsigned int)2202558382ULL)};
unsigned int b_0[4]={((unsigned int)4095042548ULL),((unsigned int)1539516982ULL),((unsigned int)3835904840ULL),((unsigned int)2202558382ULL)};
unsigned int a_1[4]={((unsigned int)4174383831ULL),((unsigned int)3942131822ULL),((unsigned int)2737662516ULL),((unsigned int)889623130ULL)};
unsigned int b_1[4]={((unsigned int)4174383831ULL),((unsigned int)3942131822ULL),((unsigned int)2737662516ULL),((unsigned int)889623130ULL)};
unsigned int a_2[4]={((unsigned int)35704960ULL),((unsigned int)2348711881ULL),((unsigned int)222682432ULL),((unsigned int)2895675534ULL)};
unsigned int b_2[4]={((unsigned int)35704960ULL),((unsigned int)2348711881ULL),((unsigned int)222682432ULL),((unsigned int)2895675534ULL)};
unsigned int a_3[4]={((unsigned int)2616138055ULL),((unsigned int)1292080138ULL),((unsigned int)594251343ULL),((unsigned int)143995980ULL)};
unsigned int b_3[4]={((unsigned int)2616138055ULL),((unsigned int)1292080138ULL),((unsigned int)594251343ULL),((unsigned int)143995980ULL)};
unsigned int a_4[16]={((unsigned int)2349916740ULL),((unsigned int)1517968824ULL),((unsigned int)2268951174ULL),((unsigned int)4010210496ULL),((unsigned int)3991021624ULL),((unsigned int)1697231154ULL),((unsigned int)3868191159ULL),((unsigned int)3169056347ULL),((unsigned int)3177522258ULL),((unsigned int)2906941944ULL),((unsigned int)3568056513ULL),((unsigned int)3699054478ULL),((unsigned int)973431944ULL),((unsigned int)882503666ULL),((unsigned int)2565857607ULL),((unsigned int)3572903382ULL)};
unsigned int b_4[16]={((unsigned int)2349916740ULL),((unsigned int)1517968824ULL),((unsigned int)2268951174ULL),((unsigned int)4010210496ULL),((unsigned int)3991021624ULL),((unsigned int)1697231154ULL),((unsigned int)3868191159ULL),((unsigned int)3169056347ULL),((unsigned int)3177522258ULL),((unsigned int)2906941944ULL),((unsigned int)3568056513ULL),((unsigned int)3699054478ULL),((unsigned int)973431944ULL),((unsigned int)882503666ULL),((unsigned int)2565857607ULL),((unsigned int)3572903382ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 139\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)580312564ULL),((unsigned int)206234998ULL),((unsigned int)58246148ULL),((unsigned int)1514362422ULL)};
unsigned int b_0[4]={((unsigned int)580312564ULL),((unsigned int)206234998ULL),((unsigned int)58246148ULL),((unsigned int)1514362422ULL)};
unsigned int a_1[4]={((unsigned int)1343426228ULL),((unsigned int)744588131ULL),((unsigned int)908223057ULL),((unsigned int)3246368341ULL)};
unsigned int b_1[4]={((unsigned int)1343426228ULL),((unsigned int)744588131ULL),((unsigned int)908223057ULL),((unsigned int)3246368341ULL)};
unsigned int a_2[4]={((unsigned int)400808395ULL),((unsigned int)1881161767ULL),((unsigned int)2361833027ULL),((unsigned int)292719024ULL)};
unsigned int b_2[4]={((unsigned int)400808395ULL),((unsigned int)1881161767ULL),((unsigned int)2361833027ULL),((unsigned int)292719024ULL)};
unsigned int a_3[4]={((unsigned int)3868517805ULL),((unsigned int)3449596417ULL),((unsigned int)2811893358ULL),((unsigned int)2464625269ULL)};
unsigned int b_3[4]={((unsigned int)3868517805ULL),((unsigned int)3449596417ULL),((unsigned int)2811893358ULL),((unsigned int)2464625269ULL)};
unsigned int a_4[16]={((unsigned int)2505827426ULL),((unsigned int)1525370769ULL),((unsigned int)2063442032ULL),((unsigned int)290966790ULL),((unsigned int)27464227ULL),((unsigned int)2139032585ULL),((unsigned int)3478220007ULL),((unsigned int)3964788758ULL),((unsigned int)2976263947ULL),((unsigned int)2220037739ULL),((unsigned int)1295498188ULL),((unsigned int)3847200492ULL),((unsigned int)1152907839ULL),((unsigned int)1939445354ULL),((unsigned int)1815623756ULL),((unsigned int)2197457819ULL)};
unsigned int b_4[16]={((unsigned int)2505827426ULL),((unsigned int)1525370769ULL),((unsigned int)2063442032ULL),((unsigned int)290966790ULL),((unsigned int)27464227ULL),((unsigned int)2139032585ULL),((unsigned int)3478220007ULL),((unsigned int)3964788758ULL),((unsigned int)2976263947ULL),((unsigned int)2220037739ULL),((unsigned int)1295498188ULL),((unsigned int)3847200492ULL),((unsigned int)1152907839ULL),((unsigned int)1939445354ULL),((unsigned int)1815623756ULL),((unsigned int)2197457819ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 140\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3911611274ULL),((unsigned int)1675507973ULL),((unsigned int)1446222741ULL),((unsigned int)2429719953ULL)};
unsigned int b_0[4]={((unsigned int)3911611274ULL),((unsigned int)1675507973ULL),((unsigned int)1446222741ULL),((unsigned int)2429719953ULL)};
unsigned int a_1[4]={((unsigned int)582634040ULL),((unsigned int)3661674131ULL),((unsigned int)4124880293ULL),((unsigned int)3449226611ULL)};
unsigned int b_1[4]={((unsigned int)582634040ULL),((unsigned int)3661674131ULL),((unsigned int)4124880293ULL),((unsigned int)3449226611ULL)};
unsigned int a_2[4]={((unsigned int)906833145ULL),((unsigned int)4206236152ULL),((unsigned int)2798066868ULL),((unsigned int)4050680288ULL)};
unsigned int b_2[4]={((unsigned int)906833145ULL),((unsigned int)4206236152ULL),((unsigned int)2798066868ULL),((unsigned int)4050680288ULL)};
unsigned int a_3[4]={((unsigned int)4115699182ULL),((unsigned int)2016487350ULL),((unsigned int)3170951355ULL),((unsigned int)1751797041ULL)};
unsigned int b_3[4]={((unsigned int)4115699182ULL),((unsigned int)2016487350ULL),((unsigned int)3170951355ULL),((unsigned int)1751797041ULL)};
unsigned int a_4[16]={((unsigned int)854112580ULL),((unsigned int)1937948630ULL),((unsigned int)88091898ULL),((unsigned int)2873504906ULL),((unsigned int)2536624510ULL),((unsigned int)2888117689ULL),((unsigned int)2128496702ULL),((unsigned int)106804894ULL),((unsigned int)1618435530ULL),((unsigned int)1617787908ULL),((unsigned int)3661774452ULL),((unsigned int)2629416741ULL),((unsigned int)2088294683ULL),((unsigned int)2957464733ULL),((unsigned int)2973394014ULL),((unsigned int)1350793211ULL)};
unsigned int b_4[16]={((unsigned int)854112580ULL),((unsigned int)1937948630ULL),((unsigned int)88091898ULL),((unsigned int)2873504906ULL),((unsigned int)2536624510ULL),((unsigned int)2888117689ULL),((unsigned int)2128496702ULL),((unsigned int)106804894ULL),((unsigned int)1618435530ULL),((unsigned int)1617787908ULL),((unsigned int)3661774452ULL),((unsigned int)2629416741ULL),((unsigned int)2088294683ULL),((unsigned int)2957464733ULL),((unsigned int)2973394014ULL),((unsigned int)1350793211ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 141\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1999411563ULL),((unsigned int)1992080093ULL),((unsigned int)537325963ULL),((unsigned int)752530129ULL)};
unsigned int b_0[4]={((unsigned int)1999411563ULL),((unsigned int)1992080093ULL),((unsigned int)537325963ULL),((unsigned int)752530129ULL)};
unsigned int a_1[4]={((unsigned int)2299036110ULL),((unsigned int)2297510478ULL),((unsigned int)155618343ULL),((unsigned int)1814974227ULL)};
unsigned int b_1[4]={((unsigned int)2299036110ULL),((unsigned int)2297510478ULL),((unsigned int)155618343ULL),((unsigned int)1814974227ULL)};
unsigned int a_2[4]={((unsigned int)3468771991ULL),((unsigned int)2505758233ULL),((unsigned int)987999483ULL),((unsigned int)3450749690ULL)};
unsigned int b_2[4]={((unsigned int)3468771991ULL),((unsigned int)2505758233ULL),((unsigned int)987999483ULL),((unsigned int)3450749690ULL)};
unsigned int a_3[4]={((unsigned int)2312003191ULL),((unsigned int)1652321391ULL),((unsigned int)2870507922ULL),((unsigned int)1880666667ULL)};
unsigned int b_3[4]={((unsigned int)2312003191ULL),((unsigned int)1652321391ULL),((unsigned int)2870507922ULL),((unsigned int)1880666667ULL)};
unsigned int a_4[16]={((unsigned int)275998620ULL),((unsigned int)2400774501ULL),((unsigned int)523891869ULL),((unsigned int)1157671764ULL),((unsigned int)2140879045ULL),((unsigned int)2024767949ULL),((unsigned int)297651147ULL),((unsigned int)3874826385ULL),((unsigned int)3946245072ULL),((unsigned int)2463622825ULL),((unsigned int)1001551004ULL),((unsigned int)3048901371ULL),((unsigned int)2486239447ULL),((unsigned int)490051899ULL),((unsigned int)2230827376ULL),((unsigned int)2897223637ULL)};
unsigned int b_4[16]={((unsigned int)275998620ULL),((unsigned int)2400774501ULL),((unsigned int)523891869ULL),((unsigned int)1157671764ULL),((unsigned int)2140879045ULL),((unsigned int)2024767949ULL),((unsigned int)297651147ULL),((unsigned int)3874826385ULL),((unsigned int)3946245072ULL),((unsigned int)2463622825ULL),((unsigned int)1001551004ULL),((unsigned int)3048901371ULL),((unsigned int)2486239447ULL),((unsigned int)490051899ULL),((unsigned int)2230827376ULL),((unsigned int)2897223637ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 142\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2602960192ULL),((unsigned int)2529765342ULL),((unsigned int)1649987392ULL),((unsigned int)2093106333ULL)};
unsigned int b_0[4]={((unsigned int)2602960192ULL),((unsigned int)2529765342ULL),((unsigned int)1649987392ULL),((unsigned int)2093106333ULL)};
unsigned int a_1[4]={((unsigned int)2275944274ULL),((unsigned int)375190810ULL),((unsigned int)1461555866ULL),((unsigned int)1984619648ULL)};
unsigned int b_1[4]={((unsigned int)2275944274ULL),((unsigned int)375190810ULL),((unsigned int)1461555866ULL),((unsigned int)1984619648ULL)};
unsigned int a_2[4]={((unsigned int)4230108101ULL),((unsigned int)1367757964ULL),((unsigned int)1380624997ULL),((unsigned int)729276088ULL)};
unsigned int b_2[4]={((unsigned int)4230108101ULL),((unsigned int)1367757964ULL),((unsigned int)1380624997ULL),((unsigned int)729276088ULL)};
unsigned int a_3[4]={((unsigned int)1067297402ULL),((unsigned int)2103176507ULL),((unsigned int)1596069522ULL),((unsigned int)4024524796ULL)};
unsigned int b_3[4]={((unsigned int)1067297402ULL),((unsigned int)2103176507ULL),((unsigned int)1596069522ULL),((unsigned int)4024524796ULL)};
unsigned int a_4[16]={((unsigned int)130082652ULL),((unsigned int)1247913742ULL),((unsigned int)413868101ULL),((unsigned int)3743206289ULL),((unsigned int)3536779022ULL),((unsigned int)1875548386ULL),((unsigned int)419573439ULL),((unsigned int)761318973ULL),((unsigned int)1396982680ULL),((unsigned int)2567043403ULL),((unsigned int)556294805ULL),((unsigned int)2662094478ULL),((unsigned int)3973970586ULL),((unsigned int)3210146850ULL),((unsigned int)1386882376ULL),((unsigned int)338810101ULL)};
unsigned int b_4[16]={((unsigned int)130082652ULL),((unsigned int)1247913742ULL),((unsigned int)413868101ULL),((unsigned int)3743206289ULL),((unsigned int)3536779022ULL),((unsigned int)1875548386ULL),((unsigned int)419573439ULL),((unsigned int)761318973ULL),((unsigned int)1396982680ULL),((unsigned int)2567043403ULL),((unsigned int)556294805ULL),((unsigned int)2662094478ULL),((unsigned int)3973970586ULL),((unsigned int)3210146850ULL),((unsigned int)1386882376ULL),((unsigned int)338810101ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 143\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)25388192ULL),((unsigned int)2348891696ULL),((unsigned int)277426928ULL),((unsigned int)469258234ULL)};
unsigned int b_0[4]={((unsigned int)25388192ULL),((unsigned int)2348891696ULL),((unsigned int)277426928ULL),((unsigned int)469258234ULL)};
unsigned int a_1[4]={((unsigned int)402038189ULL),((unsigned int)2235714087ULL),((unsigned int)1948123180ULL),((unsigned int)119344796ULL)};
unsigned int b_1[4]={((unsigned int)402038189ULL),((unsigned int)2235714087ULL),((unsigned int)1948123180ULL),((unsigned int)119344796ULL)};
unsigned int a_2[4]={((unsigned int)2346986410ULL),((unsigned int)2950771268ULL),((unsigned int)3522744102ULL),((unsigned int)4197564990ULL)};
unsigned int b_2[4]={((unsigned int)2346986410ULL),((unsigned int)2950771268ULL),((unsigned int)3522744102ULL),((unsigned int)4197564990ULL)};
unsigned int a_3[4]={((unsigned int)3638365153ULL),((unsigned int)2311994803ULL),((unsigned int)3086621829ULL),((unsigned int)828357464ULL)};
unsigned int b_3[4]={((unsigned int)3638365153ULL),((unsigned int)2311994803ULL),((unsigned int)3086621829ULL),((unsigned int)828357464ULL)};
unsigned int a_4[16]={((unsigned int)2436756165ULL),((unsigned int)2117729797ULL),((unsigned int)3384912988ULL),((unsigned int)2370184299ULL),((unsigned int)1643710244ULL),((unsigned int)3745738930ULL),((unsigned int)866047489ULL),((unsigned int)3247345197ULL),((unsigned int)1265139401ULL),((unsigned int)3849660892ULL),((unsigned int)2965248287ULL),((unsigned int)3568659591ULL),((unsigned int)3338295738ULL),((unsigned int)4144512115ULL),((unsigned int)3496756897ULL),((unsigned int)1441396097ULL)};
unsigned int b_4[16]={((unsigned int)2436756165ULL),((unsigned int)2117729797ULL),((unsigned int)3384912988ULL),((unsigned int)2370184299ULL),((unsigned int)1643710244ULL),((unsigned int)3745738930ULL),((unsigned int)866047489ULL),((unsigned int)3247345197ULL),((unsigned int)1265139401ULL),((unsigned int)3849660892ULL),((unsigned int)2965248287ULL),((unsigned int)3568659591ULL),((unsigned int)3338295738ULL),((unsigned int)4144512115ULL),((unsigned int)3496756897ULL),((unsigned int)1441396097ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 144\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4036584756ULL),((unsigned int)3893247608ULL),((unsigned int)3893596659ULL),((unsigned int)3387533491ULL)};
unsigned int b_0[4]={((unsigned int)4036584756ULL),((unsigned int)3893247608ULL),((unsigned int)3893596659ULL),((unsigned int)3387533491ULL)};
unsigned int a_1[4]={((unsigned int)1069836741ULL),((unsigned int)35369375ULL),((unsigned int)1532469717ULL),((unsigned int)2232251491ULL)};
unsigned int b_1[4]={((unsigned int)1069836741ULL),((unsigned int)35369375ULL),((unsigned int)1532469717ULL),((unsigned int)2232251491ULL)};
unsigned int a_2[4]={((unsigned int)2790281257ULL),((unsigned int)1836438263ULL),((unsigned int)3921530996ULL),((unsigned int)3299918494ULL)};
unsigned int b_2[4]={((unsigned int)2790281257ULL),((unsigned int)1836438263ULL),((unsigned int)3921530996ULL),((unsigned int)3299918494ULL)};
unsigned int a_3[4]={((unsigned int)583387389ULL),((unsigned int)2673036631ULL),((unsigned int)1351473588ULL),((unsigned int)3701756581ULL)};
unsigned int b_3[4]={((unsigned int)583387389ULL),((unsigned int)2673036631ULL),((unsigned int)1351473588ULL),((unsigned int)3701756581ULL)};
unsigned int a_4[16]={((unsigned int)1400070384ULL),((unsigned int)570462900ULL),((unsigned int)1712964748ULL),((unsigned int)4238159122ULL),((unsigned int)1781044867ULL),((unsigned int)508978367ULL),((unsigned int)2707437730ULL),((unsigned int)3221067047ULL),((unsigned int)3052034956ULL),((unsigned int)1801086069ULL),((unsigned int)1482968761ULL),((unsigned int)1622665514ULL),((unsigned int)1310521428ULL),((unsigned int)1268496410ULL),((unsigned int)826685977ULL),((unsigned int)3495365687ULL)};
unsigned int b_4[16]={((unsigned int)1400070384ULL),((unsigned int)570462900ULL),((unsigned int)1712964748ULL),((unsigned int)4238159122ULL),((unsigned int)1781044867ULL),((unsigned int)508978367ULL),((unsigned int)2707437730ULL),((unsigned int)3221067047ULL),((unsigned int)3052034956ULL),((unsigned int)1801086069ULL),((unsigned int)1482968761ULL),((unsigned int)1622665514ULL),((unsigned int)1310521428ULL),((unsigned int)1268496410ULL),((unsigned int)826685977ULL),((unsigned int)3495365687ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 145\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2232541906ULL),((unsigned int)2286740519ULL),((unsigned int)1863810528ULL),((unsigned int)2666917738ULL)};
unsigned int b_0[4]={((unsigned int)2232541906ULL),((unsigned int)2286740519ULL),((unsigned int)1863810528ULL),((unsigned int)2666917738ULL)};
unsigned int a_1[4]={((unsigned int)2125222180ULL),((unsigned int)1590995071ULL),((unsigned int)850150121ULL),((unsigned int)4204649260ULL)};
unsigned int b_1[4]={((unsigned int)2125222180ULL),((unsigned int)1590995071ULL),((unsigned int)850150121ULL),((unsigned int)4204649260ULL)};
unsigned int a_2[4]={((unsigned int)1665190351ULL),((unsigned int)1346254687ULL),((unsigned int)3984083453ULL),((unsigned int)3765895791ULL)};
unsigned int b_2[4]={((unsigned int)1665190351ULL),((unsigned int)1346254687ULL),((unsigned int)3984083453ULL),((unsigned int)3765895791ULL)};
unsigned int a_3[4]={((unsigned int)109900495ULL),((unsigned int)168777798ULL),((unsigned int)139888280ULL),((unsigned int)2708649803ULL)};
unsigned int b_3[4]={((unsigned int)109900495ULL),((unsigned int)168777798ULL),((unsigned int)139888280ULL),((unsigned int)2708649803ULL)};
unsigned int a_4[16]={((unsigned int)3512848456ULL),((unsigned int)3519187211ULL),((unsigned int)1921110419ULL),((unsigned int)1965419405ULL),((unsigned int)916315548ULL),((unsigned int)4035981510ULL),((unsigned int)1914702599ULL),((unsigned int)3922193829ULL),((unsigned int)2735097218ULL),((unsigned int)2412121053ULL),((unsigned int)2436591630ULL),((unsigned int)394077598ULL),((unsigned int)2785905349ULL),((unsigned int)3836672468ULL),((unsigned int)263235061ULL),((unsigned int)289960552ULL)};
unsigned int b_4[16]={((unsigned int)3512848456ULL),((unsigned int)3519187211ULL),((unsigned int)1921110419ULL),((unsigned int)1965419405ULL),((unsigned int)916315548ULL),((unsigned int)4035981510ULL),((unsigned int)1914702599ULL),((unsigned int)3922193829ULL),((unsigned int)2735097218ULL),((unsigned int)2412121053ULL),((unsigned int)2436591630ULL),((unsigned int)394077598ULL),((unsigned int)2785905349ULL),((unsigned int)3836672468ULL),((unsigned int)263235061ULL),((unsigned int)289960552ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 146\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3204613675ULL),((unsigned int)3708055610ULL),((unsigned int)2202264321ULL),((unsigned int)445114581ULL)};
unsigned int b_0[4]={((unsigned int)3204613675ULL),((unsigned int)3708055610ULL),((unsigned int)2202264321ULL),((unsigned int)445114581ULL)};
unsigned int a_1[4]={((unsigned int)1376569291ULL),((unsigned int)1057882504ULL),((unsigned int)1617841661ULL),((unsigned int)1773326718ULL)};
unsigned int b_1[4]={((unsigned int)1376569291ULL),((unsigned int)1057882504ULL),((unsigned int)1617841661ULL),((unsigned int)1773326718ULL)};
unsigned int a_2[4]={((unsigned int)3062179261ULL),((unsigned int)4043543502ULL),((unsigned int)3194007344ULL),((unsigned int)929055754ULL)};
unsigned int b_2[4]={((unsigned int)3062179261ULL),((unsigned int)4043543502ULL),((unsigned int)3194007344ULL),((unsigned int)929055754ULL)};
unsigned int a_3[4]={((unsigned int)4077877418ULL),((unsigned int)2038195001ULL),((unsigned int)1804253516ULL),((unsigned int)1254514227ULL)};
unsigned int b_3[4]={((unsigned int)4077877418ULL),((unsigned int)2038195001ULL),((unsigned int)1804253516ULL),((unsigned int)1254514227ULL)};
unsigned int a_4[16]={((unsigned int)1191197958ULL),((unsigned int)3257781855ULL),((unsigned int)3067884395ULL),((unsigned int)3722831169ULL),((unsigned int)4226251476ULL),((unsigned int)3546206690ULL),((unsigned int)2707877115ULL),((unsigned int)1945854072ULL),((unsigned int)3984794000ULL),((unsigned int)337721135ULL),((unsigned int)699538697ULL),((unsigned int)2139992744ULL),((unsigned int)4029083361ULL),((unsigned int)4167526080ULL),((unsigned int)1246159638ULL),((unsigned int)2380708110ULL)};
unsigned int b_4[16]={((unsigned int)1191197958ULL),((unsigned int)3257781855ULL),((unsigned int)3067884395ULL),((unsigned int)3722831169ULL),((unsigned int)4226251476ULL),((unsigned int)3546206690ULL),((unsigned int)2707877115ULL),((unsigned int)1945854072ULL),((unsigned int)3984794000ULL),((unsigned int)337721135ULL),((unsigned int)699538697ULL),((unsigned int)2139992744ULL),((unsigned int)4029083361ULL),((unsigned int)4167526080ULL),((unsigned int)1246159638ULL),((unsigned int)2380708110ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 147\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2199807334ULL),((unsigned int)1571311678ULL),((unsigned int)3964861486ULL),((unsigned int)3030795847ULL)};
unsigned int b_0[4]={((unsigned int)2199807334ULL),((unsigned int)1571311678ULL),((unsigned int)3964861486ULL),((unsigned int)3030795847ULL)};
unsigned int a_1[4]={((unsigned int)3830736122ULL),((unsigned int)2569906116ULL),((unsigned int)3204290279ULL),((unsigned int)1969985902ULL)};
unsigned int b_1[4]={((unsigned int)3830736122ULL),((unsigned int)2569906116ULL),((unsigned int)3204290279ULL),((unsigned int)1969985902ULL)};
unsigned int a_2[4]={((unsigned int)3902627634ULL),((unsigned int)1252799457ULL),((unsigned int)966143294ULL),((unsigned int)1903741758ULL)};
unsigned int b_2[4]={((unsigned int)3902627634ULL),((unsigned int)1252799457ULL),((unsigned int)966143294ULL),((unsigned int)1903741758ULL)};
unsigned int a_3[4]={((unsigned int)4024269894ULL),((unsigned int)3022172898ULL),((unsigned int)3854823625ULL),((unsigned int)546390406ULL)};
unsigned int b_3[4]={((unsigned int)4024269894ULL),((unsigned int)3022172898ULL),((unsigned int)3854823625ULL),((unsigned int)546390406ULL)};
unsigned int a_4[16]={((unsigned int)4176022617ULL),((unsigned int)688402679ULL),((unsigned int)1260069996ULL),((unsigned int)958046654ULL),((unsigned int)4287379915ULL),((unsigned int)1728266329ULL),((unsigned int)210076544ULL),((unsigned int)3358202697ULL),((unsigned int)3933837660ULL),((unsigned int)2242885839ULL),((unsigned int)2466110986ULL),((unsigned int)1227213280ULL),((unsigned int)970369242ULL),((unsigned int)3120664829ULL),((unsigned int)3241955005ULL),((unsigned int)3552734734ULL)};
unsigned int b_4[16]={((unsigned int)4176022617ULL),((unsigned int)688402679ULL),((unsigned int)1260069996ULL),((unsigned int)958046654ULL),((unsigned int)4287379915ULL),((unsigned int)1728266329ULL),((unsigned int)210076544ULL),((unsigned int)3358202697ULL),((unsigned int)3933837660ULL),((unsigned int)2242885839ULL),((unsigned int)2466110986ULL),((unsigned int)1227213280ULL),((unsigned int)970369242ULL),((unsigned int)3120664829ULL),((unsigned int)3241955005ULL),((unsigned int)3552734734ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 148\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1771901252ULL),((unsigned int)2856893253ULL),((unsigned int)1959515558ULL),((unsigned int)626097477ULL)};
unsigned int b_0[4]={((unsigned int)1771901252ULL),((unsigned int)2856893253ULL),((unsigned int)1959515558ULL),((unsigned int)626097477ULL)};
unsigned int a_1[4]={((unsigned int)3380413623ULL),((unsigned int)2487371585ULL),((unsigned int)3655641476ULL),((unsigned int)2722176618ULL)};
unsigned int b_1[4]={((unsigned int)3380413623ULL),((unsigned int)2487371585ULL),((unsigned int)3655641476ULL),((unsigned int)2722176618ULL)};
unsigned int a_2[4]={((unsigned int)1578124750ULL),((unsigned int)4134070270ULL),((unsigned int)847239472ULL),((unsigned int)844618319ULL)};
unsigned int b_2[4]={((unsigned int)1578124750ULL),((unsigned int)4134070270ULL),((unsigned int)847239472ULL),((unsigned int)844618319ULL)};
unsigned int a_3[4]={((unsigned int)3957768496ULL),((unsigned int)1458365695ULL),((unsigned int)1376026416ULL),((unsigned int)1120826940ULL)};
unsigned int b_3[4]={((unsigned int)3957768496ULL),((unsigned int)1458365695ULL),((unsigned int)1376026416ULL),((unsigned int)1120826940ULL)};
unsigned int a_4[16]={((unsigned int)1035747930ULL),((unsigned int)1161842639ULL),((unsigned int)4219938213ULL),((unsigned int)3251262884ULL),((unsigned int)1699578433ULL),((unsigned int)3359565811ULL),((unsigned int)1568316665ULL),((unsigned int)419094797ULL),((unsigned int)3465968012ULL),((unsigned int)2614891927ULL),((unsigned int)3058477620ULL),((unsigned int)860163617ULL),((unsigned int)1848589034ULL),((unsigned int)181948574ULL),((unsigned int)1277975447ULL),((unsigned int)2070939166ULL)};
unsigned int b_4[16]={((unsigned int)1035747930ULL),((unsigned int)1161842639ULL),((unsigned int)4219938213ULL),((unsigned int)3251262884ULL),((unsigned int)1699578433ULL),((unsigned int)3359565811ULL),((unsigned int)1568316665ULL),((unsigned int)419094797ULL),((unsigned int)3465968012ULL),((unsigned int)2614891927ULL),((unsigned int)3058477620ULL),((unsigned int)860163617ULL),((unsigned int)1848589034ULL),((unsigned int)181948574ULL),((unsigned int)1277975447ULL),((unsigned int)2070939166ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 149\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3616920201ULL),((unsigned int)291982182ULL),((unsigned int)3086079022ULL),((unsigned int)2509510904ULL)};
unsigned int b_0[4]={((unsigned int)3616920201ULL),((unsigned int)291982182ULL),((unsigned int)3086079022ULL),((unsigned int)2509510904ULL)};
unsigned int a_1[4]={((unsigned int)2116892837ULL),((unsigned int)2629219579ULL),((unsigned int)2946025140ULL),((unsigned int)3344679737ULL)};
unsigned int b_1[4]={((unsigned int)2116892837ULL),((unsigned int)2629219579ULL),((unsigned int)2946025140ULL),((unsigned int)3344679737ULL)};
unsigned int a_2[4]={((unsigned int)2783488969ULL),((unsigned int)927353129ULL),((unsigned int)3193555158ULL),((unsigned int)4249243163ULL)};
unsigned int b_2[4]={((unsigned int)2783488969ULL),((unsigned int)927353129ULL),((unsigned int)3193555158ULL),((unsigned int)4249243163ULL)};
unsigned int a_3[4]={((unsigned int)2791525246ULL),((unsigned int)2527267166ULL),((unsigned int)3556370549ULL),((unsigned int)719739820ULL)};
unsigned int b_3[4]={((unsigned int)2791525246ULL),((unsigned int)2527267166ULL),((unsigned int)3556370549ULL),((unsigned int)719739820ULL)};
unsigned int a_4[16]={((unsigned int)2863943974ULL),((unsigned int)4216464933ULL),((unsigned int)394644625ULL),((unsigned int)799524740ULL),((unsigned int)1946218112ULL),((unsigned int)1781609557ULL),((unsigned int)618812319ULL),((unsigned int)1490922876ULL),((unsigned int)1821005314ULL),((unsigned int)3693007046ULL),((unsigned int)545730872ULL),((unsigned int)3854054994ULL),((unsigned int)2325442935ULL),((unsigned int)2300069887ULL),((unsigned int)3668269365ULL),((unsigned int)3646942016ULL)};
unsigned int b_4[16]={((unsigned int)2863943974ULL),((unsigned int)4216464933ULL),((unsigned int)394644625ULL),((unsigned int)799524740ULL),((unsigned int)1946218112ULL),((unsigned int)1781609557ULL),((unsigned int)618812319ULL),((unsigned int)1490922876ULL),((unsigned int)1821005314ULL),((unsigned int)3693007046ULL),((unsigned int)545730872ULL),((unsigned int)3854054994ULL),((unsigned int)2325442935ULL),((unsigned int)2300069887ULL),((unsigned int)3668269365ULL),((unsigned int)3646942016ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 150\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3343655565ULL),((unsigned int)3093764442ULL),((unsigned int)1148137924ULL),((unsigned int)967708232ULL)};
unsigned int b_0[4]={((unsigned int)3343655565ULL),((unsigned int)3093764442ULL),((unsigned int)1148137924ULL),((unsigned int)967708232ULL)};
unsigned int a_1[4]={((unsigned int)3076570155ULL),((unsigned int)1849301526ULL),((unsigned int)334734081ULL),((unsigned int)2447876206ULL)};
unsigned int b_1[4]={((unsigned int)3076570155ULL),((unsigned int)1849301526ULL),((unsigned int)334734081ULL),((unsigned int)2447876206ULL)};
unsigned int a_2[4]={((unsigned int)2077991639ULL),((unsigned int)3877526169ULL),((unsigned int)2760801465ULL),((unsigned int)224301270ULL)};
unsigned int b_2[4]={((unsigned int)2077991639ULL),((unsigned int)3877526169ULL),((unsigned int)2760801465ULL),((unsigned int)224301270ULL)};
unsigned int a_3[4]={((unsigned int)3766564474ULL),((unsigned int)3553758289ULL),((unsigned int)3871773360ULL),((unsigned int)4187033656ULL)};
unsigned int b_3[4]={((unsigned int)3766564474ULL),((unsigned int)3553758289ULL),((unsigned int)3871773360ULL),((unsigned int)4187033656ULL)};
unsigned int a_4[16]={((unsigned int)612494062ULL),((unsigned int)1411531400ULL),((unsigned int)1101948643ULL),((unsigned int)50333557ULL),((unsigned int)1585471869ULL),((unsigned int)2979783809ULL),((unsigned int)1036037219ULL),((unsigned int)2416261436ULL),((unsigned int)2369553618ULL),((unsigned int)3561957598ULL),((unsigned int)602168692ULL),((unsigned int)1331191484ULL),((unsigned int)1587083136ULL),((unsigned int)3762817886ULL),((unsigned int)3383329138ULL),((unsigned int)1579412446ULL)};
unsigned int b_4[16]={((unsigned int)612494062ULL),((unsigned int)1411531400ULL),((unsigned int)1101948643ULL),((unsigned int)50333557ULL),((unsigned int)1585471869ULL),((unsigned int)2979783809ULL),((unsigned int)1036037219ULL),((unsigned int)2416261436ULL),((unsigned int)2369553618ULL),((unsigned int)3561957598ULL),((unsigned int)602168692ULL),((unsigned int)1331191484ULL),((unsigned int)1587083136ULL),((unsigned int)3762817886ULL),((unsigned int)3383329138ULL),((unsigned int)1579412446ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 151\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)244453644ULL),((unsigned int)380560647ULL),((unsigned int)3120861886ULL),((unsigned int)811677049ULL)};
unsigned int b_0[4]={((unsigned int)244453644ULL),((unsigned int)380560647ULL),((unsigned int)3120861886ULL),((unsigned int)811677049ULL)};
unsigned int a_1[4]={((unsigned int)2318103763ULL),((unsigned int)2410672766ULL),((unsigned int)2744778083ULL),((unsigned int)3662909152ULL)};
unsigned int b_1[4]={((unsigned int)2318103763ULL),((unsigned int)2410672766ULL),((unsigned int)2744778083ULL),((unsigned int)3662909152ULL)};
unsigned int a_2[4]={((unsigned int)2868729457ULL),((unsigned int)2106833194ULL),((unsigned int)1715497941ULL),((unsigned int)1882902433ULL)};
unsigned int b_2[4]={((unsigned int)2868729457ULL),((unsigned int)2106833194ULL),((unsigned int)1715497941ULL),((unsigned int)1882902433ULL)};
unsigned int a_3[4]={((unsigned int)731248651ULL),((unsigned int)2947204533ULL),((unsigned int)4169359268ULL),((unsigned int)2269054447ULL)};
unsigned int b_3[4]={((unsigned int)731248651ULL),((unsigned int)2947204533ULL),((unsigned int)4169359268ULL),((unsigned int)2269054447ULL)};
unsigned int a_4[16]={((unsigned int)827244313ULL),((unsigned int)1711282959ULL),((unsigned int)862878529ULL),((unsigned int)2845733309ULL),((unsigned int)1567355585ULL),((unsigned int)4276876340ULL),((unsigned int)3396242930ULL),((unsigned int)2830636073ULL),((unsigned int)1761926578ULL),((unsigned int)3719683011ULL),((unsigned int)1969976767ULL),((unsigned int)339861178ULL),((unsigned int)878756347ULL),((unsigned int)2688452406ULL),((unsigned int)6326972ULL),((unsigned int)3145325687ULL)};
unsigned int b_4[16]={((unsigned int)827244313ULL),((unsigned int)1711282959ULL),((unsigned int)862878529ULL),((unsigned int)2845733309ULL),((unsigned int)1567355585ULL),((unsigned int)4276876340ULL),((unsigned int)3396242930ULL),((unsigned int)2830636073ULL),((unsigned int)1761926578ULL),((unsigned int)3719683011ULL),((unsigned int)1969976767ULL),((unsigned int)339861178ULL),((unsigned int)878756347ULL),((unsigned int)2688452406ULL),((unsigned int)6326972ULL),((unsigned int)3145325687ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 152\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)974130580ULL),((unsigned int)2823218329ULL),((unsigned int)246335274ULL),((unsigned int)162357451ULL)};
unsigned int b_0[4]={((unsigned int)974130580ULL),((unsigned int)2823218329ULL),((unsigned int)246335274ULL),((unsigned int)162357451ULL)};
unsigned int a_1[4]={((unsigned int)1030938620ULL),((unsigned int)629624936ULL),((unsigned int)384239835ULL),((unsigned int)285237221ULL)};
unsigned int b_1[4]={((unsigned int)1030938620ULL),((unsigned int)629624936ULL),((unsigned int)384239835ULL),((unsigned int)285237221ULL)};
unsigned int a_2[4]={((unsigned int)507251019ULL),((unsigned int)2378617163ULL),((unsigned int)1685384471ULL),((unsigned int)2933411264ULL)};
unsigned int b_2[4]={((unsigned int)507251019ULL),((unsigned int)2378617163ULL),((unsigned int)1685384471ULL),((unsigned int)2933411264ULL)};
unsigned int a_3[4]={((unsigned int)1458728046ULL),((unsigned int)276418009ULL),((unsigned int)1319892463ULL),((unsigned int)2247191612ULL)};
unsigned int b_3[4]={((unsigned int)1458728046ULL),((unsigned int)276418009ULL),((unsigned int)1319892463ULL),((unsigned int)2247191612ULL)};
unsigned int a_4[16]={((unsigned int)3989927ULL),((unsigned int)1981983795ULL),((unsigned int)385451122ULL),((unsigned int)657634439ULL),((unsigned int)3331993917ULL),((unsigned int)4155211034ULL),((unsigned int)1302152406ULL),((unsigned int)2763779627ULL),((unsigned int)970086896ULL),((unsigned int)2958863890ULL),((unsigned int)2903320733ULL),((unsigned int)707485217ULL),((unsigned int)2742807934ULL),((unsigned int)1827325502ULL),((unsigned int)1103893165ULL),((unsigned int)404996582ULL)};
unsigned int b_4[16]={((unsigned int)3989927ULL),((unsigned int)1981983795ULL),((unsigned int)385451122ULL),((unsigned int)657634439ULL),((unsigned int)3331993917ULL),((unsigned int)4155211034ULL),((unsigned int)1302152406ULL),((unsigned int)2763779627ULL),((unsigned int)970086896ULL),((unsigned int)2958863890ULL),((unsigned int)2903320733ULL),((unsigned int)707485217ULL),((unsigned int)2742807934ULL),((unsigned int)1827325502ULL),((unsigned int)1103893165ULL),((unsigned int)404996582ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 153\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3258711741ULL),((unsigned int)2526894130ULL),((unsigned int)3463984937ULL),((unsigned int)3935075074ULL)};
unsigned int b_0[4]={((unsigned int)3258711741ULL),((unsigned int)2526894130ULL),((unsigned int)3463984937ULL),((unsigned int)3935075074ULL)};
unsigned int a_1[4]={((unsigned int)1123355821ULL),((unsigned int)806817165ULL),((unsigned int)436582804ULL),((unsigned int)4069858890ULL)};
unsigned int b_1[4]={((unsigned int)1123355821ULL),((unsigned int)806817165ULL),((unsigned int)436582804ULL),((unsigned int)4069858890ULL)};
unsigned int a_2[4]={((unsigned int)1993304904ULL),((unsigned int)3030676192ULL),((unsigned int)451088323ULL),((unsigned int)2219360593ULL)};
unsigned int b_2[4]={((unsigned int)1993304904ULL),((unsigned int)3030676192ULL),((unsigned int)451088323ULL),((unsigned int)2219360593ULL)};
unsigned int a_3[4]={((unsigned int)3072455345ULL),((unsigned int)510439499ULL),((unsigned int)779154030ULL),((unsigned int)4222390436ULL)};
unsigned int b_3[4]={((unsigned int)3072455345ULL),((unsigned int)510439499ULL),((unsigned int)779154030ULL),((unsigned int)4222390436ULL)};
unsigned int a_4[16]={((unsigned int)2937261121ULL),((unsigned int)3624283773ULL),((unsigned int)2820557886ULL),((unsigned int)1804598523ULL),((unsigned int)1930532258ULL),((unsigned int)2500200815ULL),((unsigned int)1119686897ULL),((unsigned int)2822269431ULL),((unsigned int)4172921349ULL),((unsigned int)1058278948ULL),((unsigned int)2569992508ULL),((unsigned int)2576585240ULL),((unsigned int)2404314562ULL),((unsigned int)2793970452ULL),((unsigned int)3916485334ULL),((unsigned int)2698954081ULL)};
unsigned int b_4[16]={((unsigned int)2937261121ULL),((unsigned int)3624283773ULL),((unsigned int)2820557886ULL),((unsigned int)1804598523ULL),((unsigned int)1930532258ULL),((unsigned int)2500200815ULL),((unsigned int)1119686897ULL),((unsigned int)2822269431ULL),((unsigned int)4172921349ULL),((unsigned int)1058278948ULL),((unsigned int)2569992508ULL),((unsigned int)2576585240ULL),((unsigned int)2404314562ULL),((unsigned int)2793970452ULL),((unsigned int)3916485334ULL),((unsigned int)2698954081ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 154\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)341343058ULL),((unsigned int)1346929421ULL),((unsigned int)1579433188ULL),((unsigned int)1344254796ULL)};
unsigned int b_0[4]={((unsigned int)341343058ULL),((unsigned int)1346929421ULL),((unsigned int)1579433188ULL),((unsigned int)1344254796ULL)};
unsigned int a_1[4]={((unsigned int)374948766ULL),((unsigned int)483836531ULL),((unsigned int)3434693796ULL),((unsigned int)3777987181ULL)};
unsigned int b_1[4]={((unsigned int)374948766ULL),((unsigned int)483836531ULL),((unsigned int)3434693796ULL),((unsigned int)3777987181ULL)};
unsigned int a_2[4]={((unsigned int)3259117173ULL),((unsigned int)2954595848ULL),((unsigned int)3778352166ULL),((unsigned int)1597777097ULL)};
unsigned int b_2[4]={((unsigned int)3259117173ULL),((unsigned int)2954595848ULL),((unsigned int)3778352166ULL),((unsigned int)1597777097ULL)};
unsigned int a_3[4]={((unsigned int)1069630888ULL),((unsigned int)4188832207ULL),((unsigned int)1448122044ULL),((unsigned int)2651055068ULL)};
unsigned int b_3[4]={((unsigned int)1069630888ULL),((unsigned int)4188832207ULL),((unsigned int)1448122044ULL),((unsigned int)2651055068ULL)};
unsigned int a_4[16]={((unsigned int)576511032ULL),((unsigned int)1858034696ULL),((unsigned int)1028252148ULL),((unsigned int)374407680ULL),((unsigned int)3052613194ULL),((unsigned int)2003827812ULL),((unsigned int)2699598151ULL),((unsigned int)1502501615ULL),((unsigned int)669744266ULL),((unsigned int)4068587670ULL),((unsigned int)3381794301ULL),((unsigned int)3072700689ULL),((unsigned int)661233447ULL),((unsigned int)2260383261ULL),((unsigned int)4116398352ULL),((unsigned int)1446946466ULL)};
unsigned int b_4[16]={((unsigned int)576511032ULL),((unsigned int)1858034696ULL),((unsigned int)1028252148ULL),((unsigned int)374407680ULL),((unsigned int)3052613194ULL),((unsigned int)2003827812ULL),((unsigned int)2699598151ULL),((unsigned int)1502501615ULL),((unsigned int)669744266ULL),((unsigned int)4068587670ULL),((unsigned int)3381794301ULL),((unsigned int)3072700689ULL),((unsigned int)661233447ULL),((unsigned int)2260383261ULL),((unsigned int)4116398352ULL),((unsigned int)1446946466ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 155\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1876463145ULL),((unsigned int)3282827456ULL),((unsigned int)3426561813ULL),((unsigned int)3793805422ULL)};
unsigned int b_0[4]={((unsigned int)1876463145ULL),((unsigned int)3282827456ULL),((unsigned int)3426561813ULL),((unsigned int)3793805422ULL)};
unsigned int a_1[4]={((unsigned int)313425160ULL),((unsigned int)225263119ULL),((unsigned int)119865099ULL),((unsigned int)1866422478ULL)};
unsigned int b_1[4]={((unsigned int)313425160ULL),((unsigned int)225263119ULL),((unsigned int)119865099ULL),((unsigned int)1866422478ULL)};
unsigned int a_2[4]={((unsigned int)1437264195ULL),((unsigned int)766217400ULL),((unsigned int)168418620ULL),((unsigned int)3153815392ULL)};
unsigned int b_2[4]={((unsigned int)1437264195ULL),((unsigned int)766217400ULL),((unsigned int)168418620ULL),((unsigned int)3153815392ULL)};
unsigned int a_3[4]={((unsigned int)2291540292ULL),((unsigned int)1527818791ULL),((unsigned int)3880055732ULL),((unsigned int)3825391214ULL)};
unsigned int b_3[4]={((unsigned int)2291540292ULL),((unsigned int)1527818791ULL),((unsigned int)3880055732ULL),((unsigned int)3825391214ULL)};
unsigned int a_4[16]={((unsigned int)3804562174ULL),((unsigned int)1970588868ULL),((unsigned int)3894759004ULL),((unsigned int)1499399545ULL),((unsigned int)103838222ULL),((unsigned int)3885962768ULL),((unsigned int)1989963781ULL),((unsigned int)882631084ULL),((unsigned int)2798079007ULL),((unsigned int)3611502450ULL),((unsigned int)2058018697ULL),((unsigned int)2397461648ULL),((unsigned int)3885884331ULL),((unsigned int)1990825716ULL),((unsigned int)2713259338ULL),((unsigned int)766736307ULL)};
unsigned int b_4[16]={((unsigned int)3804562174ULL),((unsigned int)1970588868ULL),((unsigned int)3894759004ULL),((unsigned int)1499399545ULL),((unsigned int)103838222ULL),((unsigned int)3885962768ULL),((unsigned int)1989963781ULL),((unsigned int)882631084ULL),((unsigned int)2798079007ULL),((unsigned int)3611502450ULL),((unsigned int)2058018697ULL),((unsigned int)2397461648ULL),((unsigned int)3885884331ULL),((unsigned int)1990825716ULL),((unsigned int)2713259338ULL),((unsigned int)766736307ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 156\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3588715953ULL),((unsigned int)324694705ULL),((unsigned int)2584193806ULL),((unsigned int)3315250709ULL)};
unsigned int b_0[4]={((unsigned int)3588715953ULL),((unsigned int)324694705ULL),((unsigned int)2584193806ULL),((unsigned int)3315250709ULL)};
unsigned int a_1[4]={((unsigned int)174029060ULL),((unsigned int)3155648262ULL),((unsigned int)86659495ULL),((unsigned int)493656647ULL)};
unsigned int b_1[4]={((unsigned int)174029060ULL),((unsigned int)3155648262ULL),((unsigned int)86659495ULL),((unsigned int)493656647ULL)};
unsigned int a_2[4]={((unsigned int)277249941ULL),((unsigned int)1293976050ULL),((unsigned int)1724672343ULL),((unsigned int)2111122739ULL)};
unsigned int b_2[4]={((unsigned int)277249941ULL),((unsigned int)1293976050ULL),((unsigned int)1724672343ULL),((unsigned int)2111122739ULL)};
unsigned int a_3[4]={((unsigned int)2217530215ULL),((unsigned int)1971761912ULL),((unsigned int)833524262ULL),((unsigned int)217398963ULL)};
unsigned int b_3[4]={((unsigned int)2217530215ULL),((unsigned int)1971761912ULL),((unsigned int)833524262ULL),((unsigned int)217398963ULL)};
unsigned int a_4[16]={((unsigned int)402287193ULL),((unsigned int)1776455604ULL),((unsigned int)288298048ULL),((unsigned int)155668381ULL),((unsigned int)3038846260ULL),((unsigned int)3065192521ULL),((unsigned int)3743673149ULL),((unsigned int)4207728290ULL),((unsigned int)1836447382ULL),((unsigned int)272153805ULL),((unsigned int)1018640638ULL),((unsigned int)1824837039ULL),((unsigned int)3018085880ULL),((unsigned int)3597276479ULL),((unsigned int)1197242136ULL),((unsigned int)3935685415ULL)};
unsigned int b_4[16]={((unsigned int)402287193ULL),((unsigned int)1776455604ULL),((unsigned int)288298048ULL),((unsigned int)155668381ULL),((unsigned int)3038846260ULL),((unsigned int)3065192521ULL),((unsigned int)3743673149ULL),((unsigned int)4207728290ULL),((unsigned int)1836447382ULL),((unsigned int)272153805ULL),((unsigned int)1018640638ULL),((unsigned int)1824837039ULL),((unsigned int)3018085880ULL),((unsigned int)3597276479ULL),((unsigned int)1197242136ULL),((unsigned int)3935685415ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 157\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2108817036ULL),((unsigned int)1164388259ULL),((unsigned int)4030026056ULL),((unsigned int)1565944970ULL)};
unsigned int b_0[4]={((unsigned int)2108817036ULL),((unsigned int)1164388259ULL),((unsigned int)4030026056ULL),((unsigned int)1565944970ULL)};
unsigned int a_1[4]={((unsigned int)510518919ULL),((unsigned int)1297966668ULL),((unsigned int)2183276996ULL),((unsigned int)1884516876ULL)};
unsigned int b_1[4]={((unsigned int)510518919ULL),((unsigned int)1297966668ULL),((unsigned int)2183276996ULL),((unsigned int)1884516876ULL)};
unsigned int a_2[4]={((unsigned int)3961229713ULL),((unsigned int)2379016685ULL),((unsigned int)1395700828ULL),((unsigned int)3943346925ULL)};
unsigned int b_2[4]={((unsigned int)3961229713ULL),((unsigned int)2379016685ULL),((unsigned int)1395700828ULL),((unsigned int)3943346925ULL)};
unsigned int a_3[4]={((unsigned int)1776472553ULL),((unsigned int)3193957572ULL),((unsigned int)1261962715ULL),((unsigned int)3411903363ULL)};
unsigned int b_3[4]={((unsigned int)1776472553ULL),((unsigned int)3193957572ULL),((unsigned int)1261962715ULL),((unsigned int)3411903363ULL)};
unsigned int a_4[16]={((unsigned int)580934676ULL),((unsigned int)871479843ULL),((unsigned int)3897819721ULL),((unsigned int)2146403019ULL),((unsigned int)485042777ULL),((unsigned int)3757996194ULL),((unsigned int)2681974399ULL),((unsigned int)4119832523ULL),((unsigned int)1755757923ULL),((unsigned int)2323060960ULL),((unsigned int)1943492384ULL),((unsigned int)1920762974ULL),((unsigned int)3006660692ULL),((unsigned int)298757687ULL),((unsigned int)3303211835ULL),((unsigned int)952220539ULL)};
unsigned int b_4[16]={((unsigned int)580934676ULL),((unsigned int)871479843ULL),((unsigned int)3897819721ULL),((unsigned int)2146403019ULL),((unsigned int)485042777ULL),((unsigned int)3757996194ULL),((unsigned int)2681974399ULL),((unsigned int)4119832523ULL),((unsigned int)1755757923ULL),((unsigned int)2323060960ULL),((unsigned int)1943492384ULL),((unsigned int)1920762974ULL),((unsigned int)3006660692ULL),((unsigned int)298757687ULL),((unsigned int)3303211835ULL),((unsigned int)952220539ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 158\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1367226154ULL),((unsigned int)1710712481ULL),((unsigned int)2110142406ULL),((unsigned int)3064829186ULL)};
unsigned int b_0[4]={((unsigned int)1367226154ULL),((unsigned int)1710712481ULL),((unsigned int)2110142406ULL),((unsigned int)3064829186ULL)};
unsigned int a_1[4]={((unsigned int)3246655892ULL),((unsigned int)695544333ULL),((unsigned int)2915549753ULL),((unsigned int)578705074ULL)};
unsigned int b_1[4]={((unsigned int)3246655892ULL),((unsigned int)695544333ULL),((unsigned int)2915549753ULL),((unsigned int)578705074ULL)};
unsigned int a_2[4]={((unsigned int)1229654074ULL),((unsigned int)2661235683ULL),((unsigned int)1623831359ULL),((unsigned int)4178973719ULL)};
unsigned int b_2[4]={((unsigned int)1229654074ULL),((unsigned int)2661235683ULL),((unsigned int)1623831359ULL),((unsigned int)4178973719ULL)};
unsigned int a_3[4]={((unsigned int)1127965805ULL),((unsigned int)571304291ULL),((unsigned int)3454358103ULL),((unsigned int)2611185153ULL)};
unsigned int b_3[4]={((unsigned int)1127965805ULL),((unsigned int)571304291ULL),((unsigned int)3454358103ULL),((unsigned int)2611185153ULL)};
unsigned int a_4[16]={((unsigned int)3893846403ULL),((unsigned int)3500511619ULL),((unsigned int)3095009434ULL),((unsigned int)236109334ULL),((unsigned int)539887922ULL),((unsigned int)2560991539ULL),((unsigned int)2491098738ULL),((unsigned int)2916435202ULL),((unsigned int)1016355321ULL),((unsigned int)580462309ULL),((unsigned int)3572734041ULL),((unsigned int)3405505297ULL),((unsigned int)2118745179ULL),((unsigned int)2241982326ULL),((unsigned int)1641403183ULL),((unsigned int)1969953385ULL)};
unsigned int b_4[16]={((unsigned int)3893846403ULL),((unsigned int)3500511619ULL),((unsigned int)3095009434ULL),((unsigned int)236109334ULL),((unsigned int)539887922ULL),((unsigned int)2560991539ULL),((unsigned int)2491098738ULL),((unsigned int)2916435202ULL),((unsigned int)1016355321ULL),((unsigned int)580462309ULL),((unsigned int)3572734041ULL),((unsigned int)3405505297ULL),((unsigned int)2118745179ULL),((unsigned int)2241982326ULL),((unsigned int)1641403183ULL),((unsigned int)1969953385ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 159\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4179626955ULL),((unsigned int)1957576973ULL),((unsigned int)2362455655ULL),((unsigned int)2887419398ULL)};
unsigned int b_0[4]={((unsigned int)4179626955ULL),((unsigned int)1957576973ULL),((unsigned int)2362455655ULL),((unsigned int)2887419398ULL)};
unsigned int a_1[4]={((unsigned int)4147710672ULL),((unsigned int)3840535656ULL),((unsigned int)716491539ULL),((unsigned int)386526798ULL)};
unsigned int b_1[4]={((unsigned int)4147710672ULL),((unsigned int)3840535656ULL),((unsigned int)716491539ULL),((unsigned int)386526798ULL)};
unsigned int a_2[4]={((unsigned int)3115604848ULL),((unsigned int)924072392ULL),((unsigned int)3450543081ULL),((unsigned int)1445961409ULL)};
unsigned int b_2[4]={((unsigned int)3115604848ULL),((unsigned int)924072392ULL),((unsigned int)3450543081ULL),((unsigned int)1445961409ULL)};
unsigned int a_3[4]={((unsigned int)617740594ULL),((unsigned int)703239483ULL),((unsigned int)2835820933ULL),((unsigned int)1091423570ULL)};
unsigned int b_3[4]={((unsigned int)617740594ULL),((unsigned int)703239483ULL),((unsigned int)2835820933ULL),((unsigned int)1091423570ULL)};
unsigned int a_4[16]={((unsigned int)2692124496ULL),((unsigned int)608076659ULL),((unsigned int)3438995111ULL),((unsigned int)1893167442ULL),((unsigned int)3104965468ULL),((unsigned int)731943574ULL),((unsigned int)955072751ULL),((unsigned int)405266529ULL),((unsigned int)649571666ULL),((unsigned int)1019856772ULL),((unsigned int)2633924859ULL),((unsigned int)3410518238ULL),((unsigned int)2690230482ULL),((unsigned int)4028675257ULL),((unsigned int)504615754ULL),((unsigned int)57669524ULL)};
unsigned int b_4[16]={((unsigned int)2692124496ULL),((unsigned int)608076659ULL),((unsigned int)3438995111ULL),((unsigned int)1893167442ULL),((unsigned int)3104965468ULL),((unsigned int)731943574ULL),((unsigned int)955072751ULL),((unsigned int)405266529ULL),((unsigned int)649571666ULL),((unsigned int)1019856772ULL),((unsigned int)2633924859ULL),((unsigned int)3410518238ULL),((unsigned int)2690230482ULL),((unsigned int)4028675257ULL),((unsigned int)504615754ULL),((unsigned int)57669524ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 160\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1939876451ULL),((unsigned int)3058641940ULL),((unsigned int)178712028ULL),((unsigned int)2897673909ULL)};
unsigned int b_0[4]={((unsigned int)1939876451ULL),((unsigned int)3058641940ULL),((unsigned int)178712028ULL),((unsigned int)2897673909ULL)};
unsigned int a_1[4]={((unsigned int)2985831470ULL),((unsigned int)3986852495ULL),((unsigned int)288174440ULL),((unsigned int)2292041272ULL)};
unsigned int b_1[4]={((unsigned int)2985831470ULL),((unsigned int)3986852495ULL),((unsigned int)288174440ULL),((unsigned int)2292041272ULL)};
unsigned int a_2[4]={((unsigned int)857127930ULL),((unsigned int)2774722434ULL),((unsigned int)313639232ULL),((unsigned int)416383612ULL)};
unsigned int b_2[4]={((unsigned int)857127930ULL),((unsigned int)2774722434ULL),((unsigned int)313639232ULL),((unsigned int)416383612ULL)};
unsigned int a_3[4]={((unsigned int)388219374ULL),((unsigned int)3221637415ULL),((unsigned int)3673193181ULL),((unsigned int)50854966ULL)};
unsigned int b_3[4]={((unsigned int)388219374ULL),((unsigned int)3221637415ULL),((unsigned int)3673193181ULL),((unsigned int)50854966ULL)};
unsigned int a_4[16]={((unsigned int)3872070381ULL),((unsigned int)4024446967ULL),((unsigned int)3454517290ULL),((unsigned int)1123049775ULL),((unsigned int)3354438514ULL),((unsigned int)2315165691ULL),((unsigned int)3482867956ULL),((unsigned int)3401562623ULL),((unsigned int)2921607273ULL),((unsigned int)725399914ULL),((unsigned int)4096892983ULL),((unsigned int)3452680208ULL),((unsigned int)1844012934ULL),((unsigned int)3155047459ULL),((unsigned int)617615749ULL),((unsigned int)369617551ULL)};
unsigned int b_4[16]={((unsigned int)3872070381ULL),((unsigned int)4024446967ULL),((unsigned int)3454517290ULL),((unsigned int)1123049775ULL),((unsigned int)3354438514ULL),((unsigned int)2315165691ULL),((unsigned int)3482867956ULL),((unsigned int)3401562623ULL),((unsigned int)2921607273ULL),((unsigned int)725399914ULL),((unsigned int)4096892983ULL),((unsigned int)3452680208ULL),((unsigned int)1844012934ULL),((unsigned int)3155047459ULL),((unsigned int)617615749ULL),((unsigned int)369617551ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 161\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4017677756ULL),((unsigned int)1230011805ULL),((unsigned int)1640211220ULL),((unsigned int)1048112883ULL)};
unsigned int b_0[4]={((unsigned int)4017677756ULL),((unsigned int)1230011805ULL),((unsigned int)1640211220ULL),((unsigned int)1048112883ULL)};
unsigned int a_1[4]={((unsigned int)1948746264ULL),((unsigned int)251475245ULL),((unsigned int)1044850171ULL),((unsigned int)1299925098ULL)};
unsigned int b_1[4]={((unsigned int)1948746264ULL),((unsigned int)251475245ULL),((unsigned int)1044850171ULL),((unsigned int)1299925098ULL)};
unsigned int a_2[4]={((unsigned int)1385346873ULL),((unsigned int)834811905ULL),((unsigned int)3173168924ULL),((unsigned int)4236377873ULL)};
unsigned int b_2[4]={((unsigned int)1385346873ULL),((unsigned int)834811905ULL),((unsigned int)3173168924ULL),((unsigned int)4236377873ULL)};
unsigned int a_3[4]={((unsigned int)3676505517ULL),((unsigned int)3840055633ULL),((unsigned int)828228099ULL),((unsigned int)27530480ULL)};
unsigned int b_3[4]={((unsigned int)3676505517ULL),((unsigned int)3840055633ULL),((unsigned int)828228099ULL),((unsigned int)27530480ULL)};
unsigned int a_4[16]={((unsigned int)3592398767ULL),((unsigned int)1669107990ULL),((unsigned int)1587667916ULL),((unsigned int)3497872509ULL),((unsigned int)513471522ULL),((unsigned int)1431793496ULL),((unsigned int)3295591420ULL),((unsigned int)2650807523ULL),((unsigned int)3346702032ULL),((unsigned int)29091716ULL),((unsigned int)1393050515ULL),((unsigned int)3262444580ULL),((unsigned int)24739874ULL),((unsigned int)2254385554ULL),((unsigned int)3264105142ULL),((unsigned int)976588454ULL)};
unsigned int b_4[16]={((unsigned int)3592398767ULL),((unsigned int)1669107990ULL),((unsigned int)1587667916ULL),((unsigned int)3497872509ULL),((unsigned int)513471522ULL),((unsigned int)1431793496ULL),((unsigned int)3295591420ULL),((unsigned int)2650807523ULL),((unsigned int)3346702032ULL),((unsigned int)29091716ULL),((unsigned int)1393050515ULL),((unsigned int)3262444580ULL),((unsigned int)24739874ULL),((unsigned int)2254385554ULL),((unsigned int)3264105142ULL),((unsigned int)976588454ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 162\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)33030009ULL),((unsigned int)1033045892ULL),((unsigned int)3341504086ULL),((unsigned int)204151215ULL)};
unsigned int b_0[4]={((unsigned int)33030009ULL),((unsigned int)1033045892ULL),((unsigned int)3341504086ULL),((unsigned int)204151215ULL)};
unsigned int a_1[4]={((unsigned int)1323880946ULL),((unsigned int)3826763167ULL),((unsigned int)3527054915ULL),((unsigned int)2160127104ULL)};
unsigned int b_1[4]={((unsigned int)1323880946ULL),((unsigned int)3826763167ULL),((unsigned int)3527054915ULL),((unsigned int)2160127104ULL)};
unsigned int a_2[4]={((unsigned int)1023309364ULL),((unsigned int)2224672494ULL),((unsigned int)2792303600ULL),((unsigned int)2827824092ULL)};
unsigned int b_2[4]={((unsigned int)1023309364ULL),((unsigned int)2224672494ULL),((unsigned int)2792303600ULL),((unsigned int)2827824092ULL)};
unsigned int a_3[4]={((unsigned int)2037596905ULL),((unsigned int)543288689ULL),((unsigned int)783985703ULL),((unsigned int)795764045ULL)};
unsigned int b_3[4]={((unsigned int)2037596905ULL),((unsigned int)543288689ULL),((unsigned int)783985703ULL),((unsigned int)795764045ULL)};
unsigned int a_4[16]={((unsigned int)435729388ULL),((unsigned int)2699248961ULL),((unsigned int)734564699ULL),((unsigned int)2103777956ULL),((unsigned int)3305681623ULL),((unsigned int)1012064778ULL),((unsigned int)3815987619ULL),((unsigned int)4125697663ULL),((unsigned int)3487371432ULL),((unsigned int)3975748129ULL),((unsigned int)1386692087ULL),((unsigned int)2116299871ULL),((unsigned int)1226547600ULL),((unsigned int)1035253460ULL),((unsigned int)3803132830ULL),((unsigned int)915108802ULL)};
unsigned int b_4[16]={((unsigned int)435729388ULL),((unsigned int)2699248961ULL),((unsigned int)734564699ULL),((unsigned int)2103777956ULL),((unsigned int)3305681623ULL),((unsigned int)1012064778ULL),((unsigned int)3815987619ULL),((unsigned int)4125697663ULL),((unsigned int)3487371432ULL),((unsigned int)3975748129ULL),((unsigned int)1386692087ULL),((unsigned int)2116299871ULL),((unsigned int)1226547600ULL),((unsigned int)1035253460ULL),((unsigned int)3803132830ULL),((unsigned int)915108802ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 163\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)284918451ULL),((unsigned int)3860961408ULL),((unsigned int)1657680062ULL),((unsigned int)3209879054ULL)};
unsigned int b_0[4]={((unsigned int)284918451ULL),((unsigned int)3860961408ULL),((unsigned int)1657680062ULL),((unsigned int)3209879054ULL)};
unsigned int a_1[4]={((unsigned int)1718136655ULL),((unsigned int)997625063ULL),((unsigned int)1449354895ULL),((unsigned int)771447093ULL)};
unsigned int b_1[4]={((unsigned int)1718136655ULL),((unsigned int)997625063ULL),((unsigned int)1449354895ULL),((unsigned int)771447093ULL)};
unsigned int a_2[4]={((unsigned int)1783184545ULL),((unsigned int)1330275937ULL),((unsigned int)2416706343ULL),((unsigned int)837135752ULL)};
unsigned int b_2[4]={((unsigned int)1783184545ULL),((unsigned int)1330275937ULL),((unsigned int)2416706343ULL),((unsigned int)837135752ULL)};
unsigned int a_3[4]={((unsigned int)105211290ULL),((unsigned int)2299012800ULL),((unsigned int)1732860539ULL),((unsigned int)3234451189ULL)};
unsigned int b_3[4]={((unsigned int)105211290ULL),((unsigned int)2299012800ULL),((unsigned int)1732860539ULL),((unsigned int)3234451189ULL)};
unsigned int a_4[16]={((unsigned int)3057356448ULL),((unsigned int)3914995085ULL),((unsigned int)71773269ULL),((unsigned int)3864078927ULL),((unsigned int)1886939859ULL),((unsigned int)3787043868ULL),((unsigned int)3442948385ULL),((unsigned int)1462650428ULL),((unsigned int)3765575358ULL),((unsigned int)4065621258ULL),((unsigned int)1870592385ULL),((unsigned int)2757721478ULL),((unsigned int)3518293626ULL),((unsigned int)3841437801ULL),((unsigned int)1867001693ULL),((unsigned int)473185276ULL)};
unsigned int b_4[16]={((unsigned int)3057356448ULL),((unsigned int)3914995085ULL),((unsigned int)71773269ULL),((unsigned int)3864078927ULL),((unsigned int)1886939859ULL),((unsigned int)3787043868ULL),((unsigned int)3442948385ULL),((unsigned int)1462650428ULL),((unsigned int)3765575358ULL),((unsigned int)4065621258ULL),((unsigned int)1870592385ULL),((unsigned int)2757721478ULL),((unsigned int)3518293626ULL),((unsigned int)3841437801ULL),((unsigned int)1867001693ULL),((unsigned int)473185276ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 164\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)957931705ULL),((unsigned int)501615732ULL),((unsigned int)3862296148ULL),((unsigned int)1319464981ULL)};
unsigned int b_0[4]={((unsigned int)957931705ULL),((unsigned int)501615732ULL),((unsigned int)3862296148ULL),((unsigned int)1319464981ULL)};
unsigned int a_1[4]={((unsigned int)4130512047ULL),((unsigned int)638445975ULL),((unsigned int)1574237619ULL),((unsigned int)3163793796ULL)};
unsigned int b_1[4]={((unsigned int)4130512047ULL),((unsigned int)638445975ULL),((unsigned int)1574237619ULL),((unsigned int)3163793796ULL)};
unsigned int a_2[4]={((unsigned int)1775468969ULL),((unsigned int)3656730448ULL),((unsigned int)222485477ULL),((unsigned int)1733777335ULL)};
unsigned int b_2[4]={((unsigned int)1775468969ULL),((unsigned int)3656730448ULL),((unsigned int)222485477ULL),((unsigned int)1733777335ULL)};
unsigned int a_3[4]={((unsigned int)1391089422ULL),((unsigned int)96777003ULL),((unsigned int)2208330902ULL),((unsigned int)3027801016ULL)};
unsigned int b_3[4]={((unsigned int)1391089422ULL),((unsigned int)96777003ULL),((unsigned int)2208330902ULL),((unsigned int)3027801016ULL)};
unsigned int a_4[16]={((unsigned int)1477747418ULL),((unsigned int)3093070630ULL),((unsigned int)3329864425ULL),((unsigned int)1334859500ULL),((unsigned int)1736707301ULL),((unsigned int)874955364ULL),((unsigned int)4250472509ULL),((unsigned int)1671836726ULL),((unsigned int)110238933ULL),((unsigned int)3367818912ULL),((unsigned int)1086636638ULL),((unsigned int)1639786137ULL),((unsigned int)433839104ULL),((unsigned int)230502389ULL),((unsigned int)2708410318ULL),((unsigned int)3610159144ULL)};
unsigned int b_4[16]={((unsigned int)1477747418ULL),((unsigned int)3093070630ULL),((unsigned int)3329864425ULL),((unsigned int)1334859500ULL),((unsigned int)1736707301ULL),((unsigned int)874955364ULL),((unsigned int)4250472509ULL),((unsigned int)1671836726ULL),((unsigned int)110238933ULL),((unsigned int)3367818912ULL),((unsigned int)1086636638ULL),((unsigned int)1639786137ULL),((unsigned int)433839104ULL),((unsigned int)230502389ULL),((unsigned int)2708410318ULL),((unsigned int)3610159144ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 165\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1131567719ULL),((unsigned int)3018760517ULL),((unsigned int)1282120273ULL),((unsigned int)3431392620ULL)};
unsigned int b_0[4]={((unsigned int)1131567719ULL),((unsigned int)3018760517ULL),((unsigned int)1282120273ULL),((unsigned int)3431392620ULL)};
unsigned int a_1[4]={((unsigned int)556364604ULL),((unsigned int)3998748437ULL),((unsigned int)519409629ULL),((unsigned int)1991287486ULL)};
unsigned int b_1[4]={((unsigned int)556364604ULL),((unsigned int)3998748437ULL),((unsigned int)519409629ULL),((unsigned int)1991287486ULL)};
unsigned int a_2[4]={((unsigned int)3427892673ULL),((unsigned int)4131657383ULL),((unsigned int)2038180043ULL),((unsigned int)1536568308ULL)};
unsigned int b_2[4]={((unsigned int)3427892673ULL),((unsigned int)4131657383ULL),((unsigned int)2038180043ULL),((unsigned int)1536568308ULL)};
unsigned int a_3[4]={((unsigned int)3707268325ULL),((unsigned int)2672700434ULL),((unsigned int)1836737798ULL),((unsigned int)1995053256ULL)};
unsigned int b_3[4]={((unsigned int)3707268325ULL),((unsigned int)2672700434ULL),((unsigned int)1836737798ULL),((unsigned int)1995053256ULL)};
unsigned int a_4[16]={((unsigned int)178909493ULL),((unsigned int)884151639ULL),((unsigned int)2280007406ULL),((unsigned int)1009357230ULL),((unsigned int)1920686911ULL),((unsigned int)4043790637ULL),((unsigned int)263823028ULL),((unsigned int)555040769ULL),((unsigned int)51883129ULL),((unsigned int)3327193003ULL),((unsigned int)1205664383ULL),((unsigned int)1044418822ULL),((unsigned int)4283477895ULL),((unsigned int)460076059ULL),((unsigned int)1047351590ULL),((unsigned int)3819056982ULL)};
unsigned int b_4[16]={((unsigned int)178909493ULL),((unsigned int)884151639ULL),((unsigned int)2280007406ULL),((unsigned int)1009357230ULL),((unsigned int)1920686911ULL),((unsigned int)4043790637ULL),((unsigned int)263823028ULL),((unsigned int)555040769ULL),((unsigned int)51883129ULL),((unsigned int)3327193003ULL),((unsigned int)1205664383ULL),((unsigned int)1044418822ULL),((unsigned int)4283477895ULL),((unsigned int)460076059ULL),((unsigned int)1047351590ULL),((unsigned int)3819056982ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 166\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)351575243ULL),((unsigned int)1840402002ULL),((unsigned int)2659193590ULL),((unsigned int)2608940247ULL)};
unsigned int b_0[4]={((unsigned int)351575243ULL),((unsigned int)1840402002ULL),((unsigned int)2659193590ULL),((unsigned int)2608940247ULL)};
unsigned int a_1[4]={((unsigned int)4057199523ULL),((unsigned int)321618998ULL),((unsigned int)1498893138ULL),((unsigned int)3216451267ULL)};
unsigned int b_1[4]={((unsigned int)4057199523ULL),((unsigned int)321618998ULL),((unsigned int)1498893138ULL),((unsigned int)3216451267ULL)};
unsigned int a_2[4]={((unsigned int)3791759995ULL),((unsigned int)3360914746ULL),((unsigned int)3890173833ULL),((unsigned int)102416776ULL)};
unsigned int b_2[4]={((unsigned int)3791759995ULL),((unsigned int)3360914746ULL),((unsigned int)3890173833ULL),((unsigned int)102416776ULL)};
unsigned int a_3[4]={((unsigned int)1482143296ULL),((unsigned int)4116544825ULL),((unsigned int)867183946ULL),((unsigned int)683880833ULL)};
unsigned int b_3[4]={((unsigned int)1482143296ULL),((unsigned int)4116544825ULL),((unsigned int)867183946ULL),((unsigned int)683880833ULL)};
unsigned int a_4[16]={((unsigned int)2752391197ULL),((unsigned int)3929378478ULL),((unsigned int)4066284072ULL),((unsigned int)2764735204ULL),((unsigned int)2349806866ULL),((unsigned int)2263401399ULL),((unsigned int)1582948540ULL),((unsigned int)1544211758ULL),((unsigned int)168036951ULL),((unsigned int)1914359899ULL),((unsigned int)382965199ULL),((unsigned int)2309713135ULL),((unsigned int)3815228575ULL),((unsigned int)211899813ULL),((unsigned int)84245534ULL),((unsigned int)3156042422ULL)};
unsigned int b_4[16]={((unsigned int)2752391197ULL),((unsigned int)3929378478ULL),((unsigned int)4066284072ULL),((unsigned int)2764735204ULL),((unsigned int)2349806866ULL),((unsigned int)2263401399ULL),((unsigned int)1582948540ULL),((unsigned int)1544211758ULL),((unsigned int)168036951ULL),((unsigned int)1914359899ULL),((unsigned int)382965199ULL),((unsigned int)2309713135ULL),((unsigned int)3815228575ULL),((unsigned int)211899813ULL),((unsigned int)84245534ULL),((unsigned int)3156042422ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 167\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2578892516ULL),((unsigned int)438902707ULL),((unsigned int)1730826252ULL),((unsigned int)2268128619ULL)};
unsigned int b_0[4]={((unsigned int)2578892516ULL),((unsigned int)438902707ULL),((unsigned int)1730826252ULL),((unsigned int)2268128619ULL)};
unsigned int a_1[4]={((unsigned int)3155925912ULL),((unsigned int)4234462339ULL),((unsigned int)2417444298ULL),((unsigned int)3328620814ULL)};
unsigned int b_1[4]={((unsigned int)3155925912ULL),((unsigned int)4234462339ULL),((unsigned int)2417444298ULL),((unsigned int)3328620814ULL)};
unsigned int a_2[4]={((unsigned int)2828547997ULL),((unsigned int)2960645985ULL),((unsigned int)1338102123ULL),((unsigned int)1344993040ULL)};
unsigned int b_2[4]={((unsigned int)2828547997ULL),((unsigned int)2960645985ULL),((unsigned int)1338102123ULL),((unsigned int)1344993040ULL)};
unsigned int a_3[4]={((unsigned int)2228463622ULL),((unsigned int)3829910581ULL),((unsigned int)337702047ULL),((unsigned int)3747178361ULL)};
unsigned int b_3[4]={((unsigned int)2228463622ULL),((unsigned int)3829910581ULL),((unsigned int)337702047ULL),((unsigned int)3747178361ULL)};
unsigned int a_4[16]={((unsigned int)746149981ULL),((unsigned int)587175726ULL),((unsigned int)2077362486ULL),((unsigned int)404738254ULL),((unsigned int)2675763702ULL),((unsigned int)1793008503ULL),((unsigned int)400496765ULL),((unsigned int)596690077ULL),((unsigned int)1909208146ULL),((unsigned int)3298618105ULL),((unsigned int)737368944ULL),((unsigned int)1298951934ULL),((unsigned int)36587346ULL),((unsigned int)273306964ULL),((unsigned int)3958042640ULL),((unsigned int)2749857573ULL)};
unsigned int b_4[16]={((unsigned int)746149981ULL),((unsigned int)587175726ULL),((unsigned int)2077362486ULL),((unsigned int)404738254ULL),((unsigned int)2675763702ULL),((unsigned int)1793008503ULL),((unsigned int)400496765ULL),((unsigned int)596690077ULL),((unsigned int)1909208146ULL),((unsigned int)3298618105ULL),((unsigned int)737368944ULL),((unsigned int)1298951934ULL),((unsigned int)36587346ULL),((unsigned int)273306964ULL),((unsigned int)3958042640ULL),((unsigned int)2749857573ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 168\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)9788833ULL),((unsigned int)1618822930ULL),((unsigned int)282090034ULL),((unsigned int)2202278734ULL)};
unsigned int b_0[4]={((unsigned int)9788833ULL),((unsigned int)1618822930ULL),((unsigned int)282090034ULL),((unsigned int)2202278734ULL)};
unsigned int a_1[4]={((unsigned int)75692306ULL),((unsigned int)3140545219ULL),((unsigned int)1147269214ULL),((unsigned int)4134063558ULL)};
unsigned int b_1[4]={((unsigned int)75692306ULL),((unsigned int)3140545219ULL),((unsigned int)1147269214ULL),((unsigned int)4134063558ULL)};
unsigned int a_2[4]={((unsigned int)1563330009ULL),((unsigned int)4269012276ULL),((unsigned int)3743118491ULL),((unsigned int)343870764ULL)};
unsigned int b_2[4]={((unsigned int)1563330009ULL),((unsigned int)4269012276ULL),((unsigned int)3743118491ULL),((unsigned int)343870764ULL)};
unsigned int a_3[4]={((unsigned int)2645947934ULL),((unsigned int)1011053170ULL),((unsigned int)1059878456ULL),((unsigned int)3186592547ULL)};
unsigned int b_3[4]={((unsigned int)2645947934ULL),((unsigned int)1011053170ULL),((unsigned int)1059878456ULL),((unsigned int)3186592547ULL)};
unsigned int a_4[16]={((unsigned int)1439762133ULL),((unsigned int)610178071ULL),((unsigned int)3421502978ULL),((unsigned int)3280355890ULL),((unsigned int)2837948938ULL),((unsigned int)215030140ULL),((unsigned int)1513256973ULL),((unsigned int)2073676777ULL),((unsigned int)2695399519ULL),((unsigned int)4061984960ULL),((unsigned int)3532065002ULL),((unsigned int)1694303149ULL),((unsigned int)2059193832ULL),((unsigned int)3714752536ULL),((unsigned int)2005406683ULL),((unsigned int)2363023863ULL)};
unsigned int b_4[16]={((unsigned int)1439762133ULL),((unsigned int)610178071ULL),((unsigned int)3421502978ULL),((unsigned int)3280355890ULL),((unsigned int)2837948938ULL),((unsigned int)215030140ULL),((unsigned int)1513256973ULL),((unsigned int)2073676777ULL),((unsigned int)2695399519ULL),((unsigned int)4061984960ULL),((unsigned int)3532065002ULL),((unsigned int)1694303149ULL),((unsigned int)2059193832ULL),((unsigned int)3714752536ULL),((unsigned int)2005406683ULL),((unsigned int)2363023863ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 169\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2109023158ULL),((unsigned int)1460798049ULL),((unsigned int)2627453494ULL),((unsigned int)1165604682ULL)};
unsigned int b_0[4]={((unsigned int)2109023158ULL),((unsigned int)1460798049ULL),((unsigned int)2627453494ULL),((unsigned int)1165604682ULL)};
unsigned int a_1[4]={((unsigned int)3354801763ULL),((unsigned int)3769670055ULL),((unsigned int)256589796ULL),((unsigned int)1476872820ULL)};
unsigned int b_1[4]={((unsigned int)3354801763ULL),((unsigned int)3769670055ULL),((unsigned int)256589796ULL),((unsigned int)1476872820ULL)};
unsigned int a_2[4]={((unsigned int)3621888962ULL),((unsigned int)3223334795ULL),((unsigned int)2993682251ULL),((unsigned int)2746956404ULL)};
unsigned int b_2[4]={((unsigned int)3621888962ULL),((unsigned int)3223334795ULL),((unsigned int)2993682251ULL),((unsigned int)2746956404ULL)};
unsigned int a_3[4]={((unsigned int)3717913761ULL),((unsigned int)352579337ULL),((unsigned int)427653211ULL),((unsigned int)2843176367ULL)};
unsigned int b_3[4]={((unsigned int)3717913761ULL),((unsigned int)352579337ULL),((unsigned int)427653211ULL),((unsigned int)2843176367ULL)};
unsigned int a_4[16]={((unsigned int)1459651206ULL),((unsigned int)279368091ULL),((unsigned int)3156005553ULL),((unsigned int)386612295ULL),((unsigned int)3169061984ULL),((unsigned int)2011969243ULL),((unsigned int)854371418ULL),((unsigned int)2405458351ULL),((unsigned int)1299945185ULL),((unsigned int)2122380245ULL),((unsigned int)1303743492ULL),((unsigned int)1954701674ULL),((unsigned int)1510488545ULL),((unsigned int)1716616803ULL),((unsigned int)785154397ULL),((unsigned int)3424675050ULL)};
unsigned int b_4[16]={((unsigned int)1459651206ULL),((unsigned int)279368091ULL),((unsigned int)3156005553ULL),((unsigned int)386612295ULL),((unsigned int)3169061984ULL),((unsigned int)2011969243ULL),((unsigned int)854371418ULL),((unsigned int)2405458351ULL),((unsigned int)1299945185ULL),((unsigned int)2122380245ULL),((unsigned int)1303743492ULL),((unsigned int)1954701674ULL),((unsigned int)1510488545ULL),((unsigned int)1716616803ULL),((unsigned int)785154397ULL),((unsigned int)3424675050ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 170\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3196815285ULL),((unsigned int)713417988ULL),((unsigned int)4142398601ULL),((unsigned int)3658921604ULL)};
unsigned int b_0[4]={((unsigned int)3196815285ULL),((unsigned int)713417988ULL),((unsigned int)4142398601ULL),((unsigned int)3658921604ULL)};
unsigned int a_1[4]={((unsigned int)916184699ULL),((unsigned int)3261909485ULL),((unsigned int)406228139ULL),((unsigned int)3301016773ULL)};
unsigned int b_1[4]={((unsigned int)916184699ULL),((unsigned int)3261909485ULL),((unsigned int)406228139ULL),((unsigned int)3301016773ULL)};
unsigned int a_2[4]={((unsigned int)1417412815ULL),((unsigned int)2217841569ULL),((unsigned int)1174183942ULL),((unsigned int)2330018842ULL)};
unsigned int b_2[4]={((unsigned int)1417412815ULL),((unsigned int)2217841569ULL),((unsigned int)1174183942ULL),((unsigned int)2330018842ULL)};
unsigned int a_3[4]={((unsigned int)2785058166ULL),((unsigned int)2302081199ULL),((unsigned int)630994513ULL),((unsigned int)1560024697ULL)};
unsigned int b_3[4]={((unsigned int)2785058166ULL),((unsigned int)2302081199ULL),((unsigned int)630994513ULL),((unsigned int)1560024697ULL)};
unsigned int a_4[16]={((unsigned int)2056323745ULL),((unsigned int)668987030ULL),((unsigned int)4242367149ULL),((unsigned int)2710532555ULL),((unsigned int)4189284426ULL),((unsigned int)2307223757ULL),((unsigned int)3810576251ULL),((unsigned int)3011944456ULL),((unsigned int)4012127935ULL),((unsigned int)1734719398ULL),((unsigned int)1555773430ULL),((unsigned int)1231516983ULL),((unsigned int)2658614403ULL),((unsigned int)4260819052ULL),((unsigned int)3710899321ULL),((unsigned int)1704285912ULL)};
unsigned int b_4[16]={((unsigned int)2056323745ULL),((unsigned int)668987030ULL),((unsigned int)4242367149ULL),((unsigned int)2710532555ULL),((unsigned int)4189284426ULL),((unsigned int)2307223757ULL),((unsigned int)3810576251ULL),((unsigned int)3011944456ULL),((unsigned int)4012127935ULL),((unsigned int)1734719398ULL),((unsigned int)1555773430ULL),((unsigned int)1231516983ULL),((unsigned int)2658614403ULL),((unsigned int)4260819052ULL),((unsigned int)3710899321ULL),((unsigned int)1704285912ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 171\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1180927828ULL),((unsigned int)125273750ULL),((unsigned int)115167882ULL),((unsigned int)2551116713ULL)};
unsigned int b_0[4]={((unsigned int)1180927828ULL),((unsigned int)125273750ULL),((unsigned int)115167882ULL),((unsigned int)2551116713ULL)};
unsigned int a_1[4]={((unsigned int)597682737ULL),((unsigned int)927358912ULL),((unsigned int)253973990ULL),((unsigned int)944990511ULL)};
unsigned int b_1[4]={((unsigned int)597682737ULL),((unsigned int)927358912ULL),((unsigned int)253973990ULL),((unsigned int)944990511ULL)};
unsigned int a_2[4]={((unsigned int)60366707ULL),((unsigned int)3155369473ULL),((unsigned int)3114752744ULL),((unsigned int)620147623ULL)};
unsigned int b_2[4]={((unsigned int)60366707ULL),((unsigned int)3155369473ULL),((unsigned int)3114752744ULL),((unsigned int)620147623ULL)};
unsigned int a_3[4]={((unsigned int)2702791143ULL),((unsigned int)1867499392ULL),((unsigned int)3563609796ULL),((unsigned int)1735610315ULL)};
unsigned int b_3[4]={((unsigned int)2702791143ULL),((unsigned int)1867499392ULL),((unsigned int)3563609796ULL),((unsigned int)1735610315ULL)};
unsigned int a_4[16]={((unsigned int)2947272045ULL),((unsigned int)3577279786ULL),((unsigned int)1962733733ULL),((unsigned int)2209942563ULL),((unsigned int)3313972284ULL),((unsigned int)1271764320ULL),((unsigned int)1532913016ULL),((unsigned int)1039304024ULL),((unsigned int)2909562962ULL),((unsigned int)1746452034ULL),((unsigned int)1838149385ULL),((unsigned int)527828440ULL),((unsigned int)3596761570ULL),((unsigned int)353807156ULL),((unsigned int)2696941210ULL),((unsigned int)3666468460ULL)};
unsigned int b_4[16]={((unsigned int)2947272045ULL),((unsigned int)3577279786ULL),((unsigned int)1962733733ULL),((unsigned int)2209942563ULL),((unsigned int)3313972284ULL),((unsigned int)1271764320ULL),((unsigned int)1532913016ULL),((unsigned int)1039304024ULL),((unsigned int)2909562962ULL),((unsigned int)1746452034ULL),((unsigned int)1838149385ULL),((unsigned int)527828440ULL),((unsigned int)3596761570ULL),((unsigned int)353807156ULL),((unsigned int)2696941210ULL),((unsigned int)3666468460ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 172\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2640499758ULL),((unsigned int)1308073313ULL),((unsigned int)1502285395ULL),((unsigned int)383121948ULL)};
unsigned int b_0[4]={((unsigned int)2640499758ULL),((unsigned int)1308073313ULL),((unsigned int)1502285395ULL),((unsigned int)383121948ULL)};
unsigned int a_1[4]={((unsigned int)1288806914ULL),((unsigned int)1944474605ULL),((unsigned int)1066301982ULL),((unsigned int)2314400448ULL)};
unsigned int b_1[4]={((unsigned int)1288806914ULL),((unsigned int)1944474605ULL),((unsigned int)1066301982ULL),((unsigned int)2314400448ULL)};
unsigned int a_2[4]={((unsigned int)756820924ULL),((unsigned int)3010056512ULL),((unsigned int)87740665ULL),((unsigned int)454179016ULL)};
unsigned int b_2[4]={((unsigned int)756820924ULL),((unsigned int)3010056512ULL),((unsigned int)87740665ULL),((unsigned int)454179016ULL)};
unsigned int a_3[4]={((unsigned int)757247938ULL),((unsigned int)1361651782ULL),((unsigned int)3301880374ULL),((unsigned int)2319104400ULL)};
unsigned int b_3[4]={((unsigned int)757247938ULL),((unsigned int)1361651782ULL),((unsigned int)3301880374ULL),((unsigned int)2319104400ULL)};
unsigned int a_4[16]={((unsigned int)2264775587ULL),((unsigned int)3374772716ULL),((unsigned int)3518927407ULL),((unsigned int)3145767253ULL),((unsigned int)3068798793ULL),((unsigned int)2222212862ULL),((unsigned int)1840564970ULL),((unsigned int)4186815370ULL),((unsigned int)305634878ULL),((unsigned int)2148942412ULL),((unsigned int)1799388876ULL),((unsigned int)2351169720ULL),((unsigned int)4084606017ULL),((unsigned int)2047657003ULL),((unsigned int)271735154ULL),((unsigned int)3813515168ULL)};
unsigned int b_4[16]={((unsigned int)2264775587ULL),((unsigned int)3374772716ULL),((unsigned int)3518927407ULL),((unsigned int)3145767253ULL),((unsigned int)3068798793ULL),((unsigned int)2222212862ULL),((unsigned int)1840564970ULL),((unsigned int)4186815370ULL),((unsigned int)305634878ULL),((unsigned int)2148942412ULL),((unsigned int)1799388876ULL),((unsigned int)2351169720ULL),((unsigned int)4084606017ULL),((unsigned int)2047657003ULL),((unsigned int)271735154ULL),((unsigned int)3813515168ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 173\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2416784098ULL),((unsigned int)1386380641ULL),((unsigned int)1252640822ULL),((unsigned int)1857789943ULL)};
unsigned int b_0[4]={((unsigned int)2416784098ULL),((unsigned int)1386380641ULL),((unsigned int)1252640822ULL),((unsigned int)1857789943ULL)};
unsigned int a_1[4]={((unsigned int)1003945642ULL),((unsigned int)3741894689ULL),((unsigned int)2000684398ULL),((unsigned int)744859327ULL)};
unsigned int b_1[4]={((unsigned int)1003945642ULL),((unsigned int)3741894689ULL),((unsigned int)2000684398ULL),((unsigned int)744859327ULL)};
unsigned int a_2[4]={((unsigned int)4060246028ULL),((unsigned int)259569438ULL),((unsigned int)172659869ULL),((unsigned int)615830005ULL)};
unsigned int b_2[4]={((unsigned int)4060246028ULL),((unsigned int)259569438ULL),((unsigned int)172659869ULL),((unsigned int)615830005ULL)};
unsigned int a_3[4]={((unsigned int)3587304387ULL),((unsigned int)1943220979ULL),((unsigned int)608016302ULL),((unsigned int)1677166291ULL)};
unsigned int b_3[4]={((unsigned int)3587304387ULL),((unsigned int)1943220979ULL),((unsigned int)608016302ULL),((unsigned int)1677166291ULL)};
unsigned int a_4[16]={((unsigned int)100148612ULL),((unsigned int)3428215408ULL),((unsigned int)1629339587ULL),((unsigned int)3278430304ULL),((unsigned int)622924345ULL),((unsigned int)204368305ULL),((unsigned int)750253295ULL),((unsigned int)4238078191ULL),((unsigned int)3195283141ULL),((unsigned int)2709534960ULL),((unsigned int)745974885ULL),((unsigned int)1344684282ULL),((unsigned int)778481526ULL),((unsigned int)3461113095ULL),((unsigned int)3560147736ULL),((unsigned int)2581496071ULL)};
unsigned int b_4[16]={((unsigned int)100148612ULL),((unsigned int)3428215408ULL),((unsigned int)1629339587ULL),((unsigned int)3278430304ULL),((unsigned int)622924345ULL),((unsigned int)204368305ULL),((unsigned int)750253295ULL),((unsigned int)4238078191ULL),((unsigned int)3195283141ULL),((unsigned int)2709534960ULL),((unsigned int)745974885ULL),((unsigned int)1344684282ULL),((unsigned int)778481526ULL),((unsigned int)3461113095ULL),((unsigned int)3560147736ULL),((unsigned int)2581496071ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 174\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2753686606ULL),((unsigned int)4082699890ULL),((unsigned int)443498649ULL),((unsigned int)3224411066ULL)};
unsigned int b_0[4]={((unsigned int)2753686606ULL),((unsigned int)4082699890ULL),((unsigned int)443498649ULL),((unsigned int)3224411066ULL)};
unsigned int a_1[4]={((unsigned int)2874854019ULL),((unsigned int)1408972770ULL),((unsigned int)444367204ULL),((unsigned int)622207439ULL)};
unsigned int b_1[4]={((unsigned int)2874854019ULL),((unsigned int)1408972770ULL),((unsigned int)444367204ULL),((unsigned int)622207439ULL)};
unsigned int a_2[4]={((unsigned int)2902599369ULL),((unsigned int)3564113740ULL),((unsigned int)864405528ULL),((unsigned int)3055340738ULL)};
unsigned int b_2[4]={((unsigned int)2902599369ULL),((unsigned int)3564113740ULL),((unsigned int)864405528ULL),((unsigned int)3055340738ULL)};
unsigned int a_3[4]={((unsigned int)3927762742ULL),((unsigned int)3627444073ULL),((unsigned int)3077974132ULL),((unsigned int)222603042ULL)};
unsigned int b_3[4]={((unsigned int)3927762742ULL),((unsigned int)3627444073ULL),((unsigned int)3077974132ULL),((unsigned int)222603042ULL)};
unsigned int a_4[16]={((unsigned int)4202109445ULL),((unsigned int)643973653ULL),((unsigned int)2210382523ULL),((unsigned int)3098227441ULL),((unsigned int)3383863529ULL),((unsigned int)1810502344ULL),((unsigned int)2542703727ULL),((unsigned int)43700242ULL),((unsigned int)26617169ULL),((unsigned int)4094259789ULL),((unsigned int)2332464403ULL),((unsigned int)1292904957ULL),((unsigned int)2943369965ULL),((unsigned int)2612407556ULL),((unsigned int)2582911320ULL),((unsigned int)3048067174ULL)};
unsigned int b_4[16]={((unsigned int)4202109445ULL),((unsigned int)643973653ULL),((unsigned int)2210382523ULL),((unsigned int)3098227441ULL),((unsigned int)3383863529ULL),((unsigned int)1810502344ULL),((unsigned int)2542703727ULL),((unsigned int)43700242ULL),((unsigned int)26617169ULL),((unsigned int)4094259789ULL),((unsigned int)2332464403ULL),((unsigned int)1292904957ULL),((unsigned int)2943369965ULL),((unsigned int)2612407556ULL),((unsigned int)2582911320ULL),((unsigned int)3048067174ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 175\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3380454359ULL),((unsigned int)402906850ULL),((unsigned int)3463818978ULL),((unsigned int)84001731ULL)};
unsigned int b_0[4]={((unsigned int)3380454359ULL),((unsigned int)402906850ULL),((unsigned int)3463818978ULL),((unsigned int)84001731ULL)};
unsigned int a_1[4]={((unsigned int)3282546752ULL),((unsigned int)1554388435ULL),((unsigned int)471985721ULL),((unsigned int)1840772438ULL)};
unsigned int b_1[4]={((unsigned int)3282546752ULL),((unsigned int)1554388435ULL),((unsigned int)471985721ULL),((unsigned int)1840772438ULL)};
unsigned int a_2[4]={((unsigned int)3762808689ULL),((unsigned int)3375966317ULL),((unsigned int)1860940682ULL),((unsigned int)2698788767ULL)};
unsigned int b_2[4]={((unsigned int)3762808689ULL),((unsigned int)3375966317ULL),((unsigned int)1860940682ULL),((unsigned int)2698788767ULL)};
unsigned int a_3[4]={((unsigned int)1573392767ULL),((unsigned int)1944694783ULL),((unsigned int)3737926542ULL),((unsigned int)3795798960ULL)};
unsigned int b_3[4]={((unsigned int)1573392767ULL),((unsigned int)1944694783ULL),((unsigned int)3737926542ULL),((unsigned int)3795798960ULL)};
unsigned int a_4[16]={((unsigned int)2040763377ULL),((unsigned int)1432437240ULL),((unsigned int)1409961597ULL),((unsigned int)3117631462ULL),((unsigned int)1092057928ULL),((unsigned int)4224010878ULL),((unsigned int)3261432534ULL),((unsigned int)1552690053ULL),((unsigned int)2036707257ULL),((unsigned int)3749262624ULL),((unsigned int)537201997ULL),((unsigned int)948395500ULL),((unsigned int)250092128ULL),((unsigned int)1523900753ULL),((unsigned int)2636389368ULL),((unsigned int)579345910ULL)};
unsigned int b_4[16]={((unsigned int)2040763377ULL),((unsigned int)1432437240ULL),((unsigned int)1409961597ULL),((unsigned int)3117631462ULL),((unsigned int)1092057928ULL),((unsigned int)4224010878ULL),((unsigned int)3261432534ULL),((unsigned int)1552690053ULL),((unsigned int)2036707257ULL),((unsigned int)3749262624ULL),((unsigned int)537201997ULL),((unsigned int)948395500ULL),((unsigned int)250092128ULL),((unsigned int)1523900753ULL),((unsigned int)2636389368ULL),((unsigned int)579345910ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 176\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)113371284ULL),((unsigned int)1730798763ULL),((unsigned int)4116449108ULL),((unsigned int)3986121568ULL)};
unsigned int b_0[4]={((unsigned int)113371284ULL),((unsigned int)1730798763ULL),((unsigned int)4116449108ULL),((unsigned int)3986121568ULL)};
unsigned int a_1[4]={((unsigned int)1647568027ULL),((unsigned int)2356038317ULL),((unsigned int)768518395ULL),((unsigned int)649203897ULL)};
unsigned int b_1[4]={((unsigned int)1647568027ULL),((unsigned int)2356038317ULL),((unsigned int)768518395ULL),((unsigned int)649203897ULL)};
unsigned int a_2[4]={((unsigned int)1037744474ULL),((unsigned int)1883968820ULL),((unsigned int)3173555070ULL),((unsigned int)1890848177ULL)};
unsigned int b_2[4]={((unsigned int)1037744474ULL),((unsigned int)1883968820ULL),((unsigned int)3173555070ULL),((unsigned int)1890848177ULL)};
unsigned int a_3[4]={((unsigned int)2608214621ULL),((unsigned int)86804687ULL),((unsigned int)3450371231ULL),((unsigned int)3169100983ULL)};
unsigned int b_3[4]={((unsigned int)2608214621ULL),((unsigned int)86804687ULL),((unsigned int)3450371231ULL),((unsigned int)3169100983ULL)};
unsigned int a_4[16]={((unsigned int)3573737595ULL),((unsigned int)3206706411ULL),((unsigned int)3909488308ULL),((unsigned int)196326220ULL),((unsigned int)4166539018ULL),((unsigned int)3360745782ULL),((unsigned int)4005214597ULL),((unsigned int)2979408379ULL),((unsigned int)392405937ULL),((unsigned int)480272318ULL),((unsigned int)2482320856ULL),((unsigned int)2255325226ULL),((unsigned int)267456805ULL),((unsigned int)1581323397ULL),((unsigned int)4290089585ULL),((unsigned int)458269919ULL)};
unsigned int b_4[16]={((unsigned int)3573737595ULL),((unsigned int)3206706411ULL),((unsigned int)3909488308ULL),((unsigned int)196326220ULL),((unsigned int)4166539018ULL),((unsigned int)3360745782ULL),((unsigned int)4005214597ULL),((unsigned int)2979408379ULL),((unsigned int)392405937ULL),((unsigned int)480272318ULL),((unsigned int)2482320856ULL),((unsigned int)2255325226ULL),((unsigned int)267456805ULL),((unsigned int)1581323397ULL),((unsigned int)4290089585ULL),((unsigned int)458269919ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 177\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3212869252ULL),((unsigned int)1708984901ULL),((unsigned int)2124641535ULL),((unsigned int)747090886ULL)};
unsigned int b_0[4]={((unsigned int)3212869252ULL),((unsigned int)1708984901ULL),((unsigned int)2124641535ULL),((unsigned int)747090886ULL)};
unsigned int a_1[4]={((unsigned int)3573413313ULL),((unsigned int)3828377605ULL),((unsigned int)2513640596ULL),((unsigned int)1248382025ULL)};
unsigned int b_1[4]={((unsigned int)3573413313ULL),((unsigned int)3828377605ULL),((unsigned int)2513640596ULL),((unsigned int)1248382025ULL)};
unsigned int a_2[4]={((unsigned int)1320906499ULL),((unsigned int)81017180ULL),((unsigned int)3247345000ULL),((unsigned int)901587993ULL)};
unsigned int b_2[4]={((unsigned int)1320906499ULL),((unsigned int)81017180ULL),((unsigned int)3247345000ULL),((unsigned int)901587993ULL)};
unsigned int a_3[4]={((unsigned int)3113051556ULL),((unsigned int)929765847ULL),((unsigned int)2506071469ULL),((unsigned int)3243474658ULL)};
unsigned int b_3[4]={((unsigned int)3113051556ULL),((unsigned int)929765847ULL),((unsigned int)2506071469ULL),((unsigned int)3243474658ULL)};
unsigned int a_4[16]={((unsigned int)3096576486ULL),((unsigned int)3062483567ULL),((unsigned int)831448241ULL),((unsigned int)3145577649ULL),((unsigned int)3638552972ULL),((unsigned int)3068220222ULL),((unsigned int)657602908ULL),((unsigned int)420846131ULL),((unsigned int)622405141ULL),((unsigned int)2237682470ULL),((unsigned int)1148903921ULL),((unsigned int)1060521016ULL),((unsigned int)44860512ULL),((unsigned int)2214521197ULL),((unsigned int)4017533948ULL),((unsigned int)2251582620ULL)};
unsigned int b_4[16]={((unsigned int)3096576486ULL),((unsigned int)3062483567ULL),((unsigned int)831448241ULL),((unsigned int)3145577649ULL),((unsigned int)3638552972ULL),((unsigned int)3068220222ULL),((unsigned int)657602908ULL),((unsigned int)420846131ULL),((unsigned int)622405141ULL),((unsigned int)2237682470ULL),((unsigned int)1148903921ULL),((unsigned int)1060521016ULL),((unsigned int)44860512ULL),((unsigned int)2214521197ULL),((unsigned int)4017533948ULL),((unsigned int)2251582620ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 178\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1758834323ULL),((unsigned int)317224606ULL),((unsigned int)3040982137ULL),((unsigned int)739502201ULL)};
unsigned int b_0[4]={((unsigned int)1758834323ULL),((unsigned int)317224606ULL),((unsigned int)3040982137ULL),((unsigned int)739502201ULL)};
unsigned int a_1[4]={((unsigned int)2668943164ULL),((unsigned int)980494752ULL),((unsigned int)4144360272ULL),((unsigned int)2194866833ULL)};
unsigned int b_1[4]={((unsigned int)2668943164ULL),((unsigned int)980494752ULL),((unsigned int)4144360272ULL),((unsigned int)2194866833ULL)};
unsigned int a_2[4]={((unsigned int)545196275ULL),((unsigned int)2862722794ULL),((unsigned int)966808317ULL),((unsigned int)1623410408ULL)};
unsigned int b_2[4]={((unsigned int)545196275ULL),((unsigned int)2862722794ULL),((unsigned int)966808317ULL),((unsigned int)1623410408ULL)};
unsigned int a_3[4]={((unsigned int)147102647ULL),((unsigned int)4121888811ULL),((unsigned int)2474884794ULL),((unsigned int)3023751717ULL)};
unsigned int b_3[4]={((unsigned int)147102647ULL),((unsigned int)4121888811ULL),((unsigned int)2474884794ULL),((unsigned int)3023751717ULL)};
unsigned int a_4[16]={((unsigned int)1856392318ULL),((unsigned int)2618383859ULL),((unsigned int)1249318768ULL),((unsigned int)1932374314ULL),((unsigned int)3261794178ULL),((unsigned int)2240457368ULL),((unsigned int)3912079117ULL),((unsigned int)2040668450ULL),((unsigned int)333270897ULL),((unsigned int)4061090403ULL),((unsigned int)3904193338ULL),((unsigned int)1273507742ULL),((unsigned int)930217743ULL),((unsigned int)2351607255ULL),((unsigned int)640234800ULL),((unsigned int)3668483022ULL)};
unsigned int b_4[16]={((unsigned int)1856392318ULL),((unsigned int)2618383859ULL),((unsigned int)1249318768ULL),((unsigned int)1932374314ULL),((unsigned int)3261794178ULL),((unsigned int)2240457368ULL),((unsigned int)3912079117ULL),((unsigned int)2040668450ULL),((unsigned int)333270897ULL),((unsigned int)4061090403ULL),((unsigned int)3904193338ULL),((unsigned int)1273507742ULL),((unsigned int)930217743ULL),((unsigned int)2351607255ULL),((unsigned int)640234800ULL),((unsigned int)3668483022ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 179\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1243662531ULL),((unsigned int)2765310369ULL),((unsigned int)197073760ULL),((unsigned int)3734279884ULL)};
unsigned int b_0[4]={((unsigned int)1243662531ULL),((unsigned int)2765310369ULL),((unsigned int)197073760ULL),((unsigned int)3734279884ULL)};
unsigned int a_1[4]={((unsigned int)1522831708ULL),((unsigned int)3571712986ULL),((unsigned int)3381065179ULL),((unsigned int)2997125536ULL)};
unsigned int b_1[4]={((unsigned int)1522831708ULL),((unsigned int)3571712986ULL),((unsigned int)3381065179ULL),((unsigned int)2997125536ULL)};
unsigned int a_2[4]={((unsigned int)4230558684ULL),((unsigned int)3947617172ULL),((unsigned int)2829678991ULL),((unsigned int)690673892ULL)};
unsigned int b_2[4]={((unsigned int)4230558684ULL),((unsigned int)3947617172ULL),((unsigned int)2829678991ULL),((unsigned int)690673892ULL)};
unsigned int a_3[4]={((unsigned int)1882274835ULL),((unsigned int)1060625897ULL),((unsigned int)677395323ULL),((unsigned int)3110927046ULL)};
unsigned int b_3[4]={((unsigned int)1882274835ULL),((unsigned int)1060625897ULL),((unsigned int)677395323ULL),((unsigned int)3110927046ULL)};
unsigned int a_4[16]={((unsigned int)1874639639ULL),((unsigned int)714262302ULL),((unsigned int)3639675454ULL),((unsigned int)2884154331ULL),((unsigned int)2845854108ULL),((unsigned int)2193786536ULL),((unsigned int)518241809ULL),((unsigned int)4004853506ULL),((unsigned int)226725630ULL),((unsigned int)178196015ULL),((unsigned int)2089098895ULL),((unsigned int)2083055915ULL),((unsigned int)1131982894ULL),((unsigned int)4169600754ULL),((unsigned int)1730310613ULL),((unsigned int)883387639ULL)};
unsigned int b_4[16]={((unsigned int)1874639639ULL),((unsigned int)714262302ULL),((unsigned int)3639675454ULL),((unsigned int)2884154331ULL),((unsigned int)2845854108ULL),((unsigned int)2193786536ULL),((unsigned int)518241809ULL),((unsigned int)4004853506ULL),((unsigned int)226725630ULL),((unsigned int)178196015ULL),((unsigned int)2089098895ULL),((unsigned int)2083055915ULL),((unsigned int)1131982894ULL),((unsigned int)4169600754ULL),((unsigned int)1730310613ULL),((unsigned int)883387639ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 180\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)575577514ULL),((unsigned int)3419578390ULL),((unsigned int)72905737ULL),((unsigned int)3999487585ULL)};
unsigned int b_0[4]={((unsigned int)575577514ULL),((unsigned int)3419578390ULL),((unsigned int)72905737ULL),((unsigned int)3999487585ULL)};
unsigned int a_1[4]={((unsigned int)3671616694ULL),((unsigned int)886718584ULL),((unsigned int)1566979643ULL),((unsigned int)3350296857ULL)};
unsigned int b_1[4]={((unsigned int)3671616694ULL),((unsigned int)886718584ULL),((unsigned int)1566979643ULL),((unsigned int)3350296857ULL)};
unsigned int a_2[4]={((unsigned int)3512105524ULL),((unsigned int)1335141596ULL),((unsigned int)4266401829ULL),((unsigned int)3130068823ULL)};
unsigned int b_2[4]={((unsigned int)3512105524ULL),((unsigned int)1335141596ULL),((unsigned int)4266401829ULL),((unsigned int)3130068823ULL)};
unsigned int a_3[4]={((unsigned int)1586094769ULL),((unsigned int)2889765193ULL),((unsigned int)2217620480ULL),((unsigned int)3169507526ULL)};
unsigned int b_3[4]={((unsigned int)1586094769ULL),((unsigned int)2889765193ULL),((unsigned int)2217620480ULL),((unsigned int)3169507526ULL)};
unsigned int a_4[16]={((unsigned int)3570484856ULL),((unsigned int)336872053ULL),((unsigned int)1502818015ULL),((unsigned int)2456399850ULL),((unsigned int)385511794ULL),((unsigned int)4161978749ULL),((unsigned int)3557902054ULL),((unsigned int)104929511ULL),((unsigned int)3353885332ULL),((unsigned int)1735666971ULL),((unsigned int)1200618864ULL),((unsigned int)3051360174ULL),((unsigned int)2520157507ULL),((unsigned int)1815594817ULL),((unsigned int)2070383193ULL),((unsigned int)61363239ULL)};
unsigned int b_4[16]={((unsigned int)3570484856ULL),((unsigned int)336872053ULL),((unsigned int)1502818015ULL),((unsigned int)2456399850ULL),((unsigned int)385511794ULL),((unsigned int)4161978749ULL),((unsigned int)3557902054ULL),((unsigned int)104929511ULL),((unsigned int)3353885332ULL),((unsigned int)1735666971ULL),((unsigned int)1200618864ULL),((unsigned int)3051360174ULL),((unsigned int)2520157507ULL),((unsigned int)1815594817ULL),((unsigned int)2070383193ULL),((unsigned int)61363239ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 181\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1133623010ULL),((unsigned int)2435585692ULL),((unsigned int)1030696535ULL),((unsigned int)2388409641ULL)};
unsigned int b_0[4]={((unsigned int)1133623010ULL),((unsigned int)2435585692ULL),((unsigned int)1030696535ULL),((unsigned int)2388409641ULL)};
unsigned int a_1[4]={((unsigned int)2625942978ULL),((unsigned int)552213977ULL),((unsigned int)993336802ULL),((unsigned int)3951622769ULL)};
unsigned int b_1[4]={((unsigned int)2625942978ULL),((unsigned int)552213977ULL),((unsigned int)993336802ULL),((unsigned int)3951622769ULL)};
unsigned int a_2[4]={((unsigned int)2901132381ULL),((unsigned int)1773753163ULL),((unsigned int)854208738ULL),((unsigned int)3353949687ULL)};
unsigned int b_2[4]={((unsigned int)2901132381ULL),((unsigned int)1773753163ULL),((unsigned int)854208738ULL),((unsigned int)3353949687ULL)};
unsigned int a_3[4]={((unsigned int)2433927755ULL),((unsigned int)3218642499ULL),((unsigned int)2657236671ULL),((unsigned int)1448584779ULL)};
unsigned int b_3[4]={((unsigned int)2433927755ULL),((unsigned int)3218642499ULL),((unsigned int)2657236671ULL),((unsigned int)1448584779ULL)};
unsigned int a_4[16]={((unsigned int)4070971080ULL),((unsigned int)1700091870ULL),((unsigned int)969561242ULL),((unsigned int)1471068673ULL),((unsigned int)3782476637ULL),((unsigned int)39756130ULL),((unsigned int)1133046453ULL),((unsigned int)2771707628ULL),((unsigned int)176801392ULL),((unsigned int)2141446957ULL),((unsigned int)417332834ULL),((unsigned int)1512930618ULL),((unsigned int)2373672829ULL),((unsigned int)3895741678ULL),((unsigned int)689633686ULL),((unsigned int)1288496755ULL)};
unsigned int b_4[16]={((unsigned int)4070971080ULL),((unsigned int)1700091870ULL),((unsigned int)969561242ULL),((unsigned int)1471068673ULL),((unsigned int)3782476637ULL),((unsigned int)39756130ULL),((unsigned int)1133046453ULL),((unsigned int)2771707628ULL),((unsigned int)176801392ULL),((unsigned int)2141446957ULL),((unsigned int)417332834ULL),((unsigned int)1512930618ULL),((unsigned int)2373672829ULL),((unsigned int)3895741678ULL),((unsigned int)689633686ULL),((unsigned int)1288496755ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 182\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)513307631ULL),((unsigned int)3696139986ULL),((unsigned int)1943434597ULL),((unsigned int)1376458737ULL)};
unsigned int b_0[4]={((unsigned int)513307631ULL),((unsigned int)3696139986ULL),((unsigned int)1943434597ULL),((unsigned int)1376458737ULL)};
unsigned int a_1[4]={((unsigned int)300475496ULL),((unsigned int)2497234215ULL),((unsigned int)2859636595ULL),((unsigned int)503206690ULL)};
unsigned int b_1[4]={((unsigned int)300475496ULL),((unsigned int)2497234215ULL),((unsigned int)2859636595ULL),((unsigned int)503206690ULL)};
unsigned int a_2[4]={((unsigned int)4283346296ULL),((unsigned int)161429848ULL),((unsigned int)3682326506ULL),((unsigned int)1190965771ULL)};
unsigned int b_2[4]={((unsigned int)4283346296ULL),((unsigned int)161429848ULL),((unsigned int)3682326506ULL),((unsigned int)1190965771ULL)};
unsigned int a_3[4]={((unsigned int)362351322ULL),((unsigned int)2298301706ULL),((unsigned int)825520582ULL),((unsigned int)1787571402ULL)};
unsigned int b_3[4]={((unsigned int)362351322ULL),((unsigned int)2298301706ULL),((unsigned int)825520582ULL),((unsigned int)1787571402ULL)};
unsigned int a_4[16]={((unsigned int)3315284338ULL),((unsigned int)224061406ULL),((unsigned int)275552164ULL),((unsigned int)3473288849ULL),((unsigned int)3109309702ULL),((unsigned int)2438869312ULL),((unsigned int)4238269373ULL),((unsigned int)2415764644ULL),((unsigned int)400112196ULL),((unsigned int)3543731551ULL),((unsigned int)3991663391ULL),((unsigned int)3538848436ULL),((unsigned int)4109177002ULL),((unsigned int)4123374275ULL),((unsigned int)1383045486ULL),((unsigned int)757158552ULL)};
unsigned int b_4[16]={((unsigned int)3315284338ULL),((unsigned int)224061406ULL),((unsigned int)275552164ULL),((unsigned int)3473288849ULL),((unsigned int)3109309702ULL),((unsigned int)2438869312ULL),((unsigned int)4238269373ULL),((unsigned int)2415764644ULL),((unsigned int)400112196ULL),((unsigned int)3543731551ULL),((unsigned int)3991663391ULL),((unsigned int)3538848436ULL),((unsigned int)4109177002ULL),((unsigned int)4123374275ULL),((unsigned int)1383045486ULL),((unsigned int)757158552ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 183\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)968721966ULL),((unsigned int)713669408ULL),((unsigned int)105274302ULL),((unsigned int)4172401065ULL)};
unsigned int b_0[4]={((unsigned int)968721966ULL),((unsigned int)713669408ULL),((unsigned int)105274302ULL),((unsigned int)4172401065ULL)};
unsigned int a_1[4]={((unsigned int)1311849109ULL),((unsigned int)4204907054ULL),((unsigned int)2585766619ULL),((unsigned int)1175875591ULL)};
unsigned int b_1[4]={((unsigned int)1311849109ULL),((unsigned int)4204907054ULL),((unsigned int)2585766619ULL),((unsigned int)1175875591ULL)};
unsigned int a_2[4]={((unsigned int)256603182ULL),((unsigned int)3931816384ULL),((unsigned int)1718842067ULL),((unsigned int)2307513570ULL)};
unsigned int b_2[4]={((unsigned int)256603182ULL),((unsigned int)3931816384ULL),((unsigned int)1718842067ULL),((unsigned int)2307513570ULL)};
unsigned int a_3[4]={((unsigned int)172124338ULL),((unsigned int)1537618099ULL),((unsigned int)1457884134ULL),((unsigned int)2274948919ULL)};
unsigned int b_3[4]={((unsigned int)172124338ULL),((unsigned int)1537618099ULL),((unsigned int)1457884134ULL),((unsigned int)2274948919ULL)};
unsigned int a_4[16]={((unsigned int)438131796ULL),((unsigned int)2140801512ULL),((unsigned int)1095329278ULL),((unsigned int)1246501369ULL),((unsigned int)3500024774ULL),((unsigned int)2448092377ULL),((unsigned int)4093409495ULL),((unsigned int)2832486576ULL),((unsigned int)543522188ULL),((unsigned int)249466400ULL),((unsigned int)4024753639ULL),((unsigned int)2796766714ULL),((unsigned int)3478903770ULL),((unsigned int)393106812ULL),((unsigned int)1466603943ULL),((unsigned int)3411179499ULL)};
unsigned int b_4[16]={((unsigned int)438131796ULL),((unsigned int)2140801512ULL),((unsigned int)1095329278ULL),((unsigned int)1246501369ULL),((unsigned int)3500024774ULL),((unsigned int)2448092377ULL),((unsigned int)4093409495ULL),((unsigned int)2832486576ULL),((unsigned int)543522188ULL),((unsigned int)249466400ULL),((unsigned int)4024753639ULL),((unsigned int)2796766714ULL),((unsigned int)3478903770ULL),((unsigned int)393106812ULL),((unsigned int)1466603943ULL),((unsigned int)3411179499ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 184\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)498091811ULL),((unsigned int)817537611ULL),((unsigned int)3302455583ULL),((unsigned int)821501179ULL)};
unsigned int b_0[4]={((unsigned int)498091811ULL),((unsigned int)817537611ULL),((unsigned int)3302455583ULL),((unsigned int)821501179ULL)};
unsigned int a_1[4]={((unsigned int)2456691665ULL),((unsigned int)4118605183ULL),((unsigned int)3912577200ULL),((unsigned int)2743572761ULL)};
unsigned int b_1[4]={((unsigned int)2456691665ULL),((unsigned int)4118605183ULL),((unsigned int)3912577200ULL),((unsigned int)2743572761ULL)};
unsigned int a_2[4]={((unsigned int)2325363994ULL),((unsigned int)1209783196ULL),((unsigned int)3448715836ULL),((unsigned int)3914912489ULL)};
unsigned int b_2[4]={((unsigned int)2325363994ULL),((unsigned int)1209783196ULL),((unsigned int)3448715836ULL),((unsigned int)3914912489ULL)};
unsigned int a_3[4]={((unsigned int)2114735360ULL),((unsigned int)489308679ULL),((unsigned int)2563373144ULL),((unsigned int)1498318629ULL)};
unsigned int b_3[4]={((unsigned int)2114735360ULL),((unsigned int)489308679ULL),((unsigned int)2563373144ULL),((unsigned int)1498318629ULL)};
unsigned int a_4[16]={((unsigned int)1042049499ULL),((unsigned int)741862523ULL),((unsigned int)2142440018ULL),((unsigned int)2033030169ULL),((unsigned int)1916861711ULL),((unsigned int)2034047043ULL),((unsigned int)1582764593ULL),((unsigned int)4139679356ULL),((unsigned int)1231558832ULL),((unsigned int)2553592649ULL),((unsigned int)2861486758ULL),((unsigned int)2775520960ULL),((unsigned int)3472861699ULL),((unsigned int)1096350212ULL),((unsigned int)4005390006ULL),((unsigned int)2251088318ULL)};
unsigned int b_4[16]={((unsigned int)1042049499ULL),((unsigned int)741862523ULL),((unsigned int)2142440018ULL),((unsigned int)2033030169ULL),((unsigned int)1916861711ULL),((unsigned int)2034047043ULL),((unsigned int)1582764593ULL),((unsigned int)4139679356ULL),((unsigned int)1231558832ULL),((unsigned int)2553592649ULL),((unsigned int)2861486758ULL),((unsigned int)2775520960ULL),((unsigned int)3472861699ULL),((unsigned int)1096350212ULL),((unsigned int)4005390006ULL),((unsigned int)2251088318ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 185\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3764652647ULL),((unsigned int)993806388ULL),((unsigned int)2912186687ULL),((unsigned int)1768141966ULL)};
unsigned int b_0[4]={((unsigned int)3764652647ULL),((unsigned int)993806388ULL),((unsigned int)2912186687ULL),((unsigned int)1768141966ULL)};
unsigned int a_1[4]={((unsigned int)1245192375ULL),((unsigned int)2052190813ULL),((unsigned int)1490762517ULL),((unsigned int)2628177710ULL)};
unsigned int b_1[4]={((unsigned int)1245192375ULL),((unsigned int)2052190813ULL),((unsigned int)1490762517ULL),((unsigned int)2628177710ULL)};
unsigned int a_2[4]={((unsigned int)3354837946ULL),((unsigned int)3469655426ULL),((unsigned int)3641545695ULL),((unsigned int)906138740ULL)};
unsigned int b_2[4]={((unsigned int)3354837946ULL),((unsigned int)3469655426ULL),((unsigned int)3641545695ULL),((unsigned int)906138740ULL)};
unsigned int a_3[4]={((unsigned int)2757867676ULL),((unsigned int)4259738920ULL),((unsigned int)2684291331ULL),((unsigned int)713235352ULL)};
unsigned int b_3[4]={((unsigned int)2757867676ULL),((unsigned int)4259738920ULL),((unsigned int)2684291331ULL),((unsigned int)713235352ULL)};
unsigned int a_4[16]={((unsigned int)1074623802ULL),((unsigned int)3250391642ULL),((unsigned int)1917530388ULL),((unsigned int)3605841377ULL),((unsigned int)2620340690ULL),((unsigned int)2538005247ULL),((unsigned int)501600392ULL),((unsigned int)3855221771ULL),((unsigned int)800363343ULL),((unsigned int)2353586647ULL),((unsigned int)2514731450ULL),((unsigned int)385153200ULL),((unsigned int)3242777716ULL),((unsigned int)3977424028ULL),((unsigned int)541498720ULL),((unsigned int)3012995460ULL)};
unsigned int b_4[16]={((unsigned int)1074623802ULL),((unsigned int)3250391642ULL),((unsigned int)1917530388ULL),((unsigned int)3605841377ULL),((unsigned int)2620340690ULL),((unsigned int)2538005247ULL),((unsigned int)501600392ULL),((unsigned int)3855221771ULL),((unsigned int)800363343ULL),((unsigned int)2353586647ULL),((unsigned int)2514731450ULL),((unsigned int)385153200ULL),((unsigned int)3242777716ULL),((unsigned int)3977424028ULL),((unsigned int)541498720ULL),((unsigned int)3012995460ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 186\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1754981226ULL),((unsigned int)1226031715ULL),((unsigned int)4220552765ULL),((unsigned int)2651495628ULL)};
unsigned int b_0[4]={((unsigned int)1754981226ULL),((unsigned int)1226031715ULL),((unsigned int)4220552765ULL),((unsigned int)2651495628ULL)};
unsigned int a_1[4]={((unsigned int)3084838616ULL),((unsigned int)2649431752ULL),((unsigned int)3902500191ULL),((unsigned int)2252652149ULL)};
unsigned int b_1[4]={((unsigned int)3084838616ULL),((unsigned int)2649431752ULL),((unsigned int)3902500191ULL),((unsigned int)2252652149ULL)};
unsigned int a_2[4]={((unsigned int)846956767ULL),((unsigned int)1421576729ULL),((unsigned int)4235991419ULL),((unsigned int)3485611541ULL)};
unsigned int b_2[4]={((unsigned int)846956767ULL),((unsigned int)1421576729ULL),((unsigned int)4235991419ULL),((unsigned int)3485611541ULL)};
unsigned int a_3[4]={((unsigned int)2504728504ULL),((unsigned int)195070253ULL),((unsigned int)2946547196ULL),((unsigned int)2972346853ULL)};
unsigned int b_3[4]={((unsigned int)2504728504ULL),((unsigned int)195070253ULL),((unsigned int)2946547196ULL),((unsigned int)2972346853ULL)};
unsigned int a_4[16]={((unsigned int)3408661590ULL),((unsigned int)3689218710ULL),((unsigned int)2292067796ULL),((unsigned int)3759630240ULL),((unsigned int)3829734559ULL),((unsigned int)3868583338ULL),((unsigned int)1719330605ULL),((unsigned int)2295591016ULL),((unsigned int)286610368ULL),((unsigned int)3940632437ULL),((unsigned int)743355386ULL),((unsigned int)228754616ULL),((unsigned int)4241220303ULL),((unsigned int)483794388ULL),((unsigned int)2901245624ULL),((unsigned int)1391498191ULL)};
unsigned int b_4[16]={((unsigned int)3408661590ULL),((unsigned int)3689218710ULL),((unsigned int)2292067796ULL),((unsigned int)3759630240ULL),((unsigned int)3829734559ULL),((unsigned int)3868583338ULL),((unsigned int)1719330605ULL),((unsigned int)2295591016ULL),((unsigned int)286610368ULL),((unsigned int)3940632437ULL),((unsigned int)743355386ULL),((unsigned int)228754616ULL),((unsigned int)4241220303ULL),((unsigned int)483794388ULL),((unsigned int)2901245624ULL),((unsigned int)1391498191ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 187\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3044186516ULL),((unsigned int)2050299956ULL),((unsigned int)3156878157ULL),((unsigned int)1872367127ULL)};
unsigned int b_0[4]={((unsigned int)3044186516ULL),((unsigned int)2050299956ULL),((unsigned int)3156878157ULL),((unsigned int)1872367127ULL)};
unsigned int a_1[4]={((unsigned int)3512421549ULL),((unsigned int)1763294698ULL),((unsigned int)3435666858ULL),((unsigned int)2295364090ULL)};
unsigned int b_1[4]={((unsigned int)3512421549ULL),((unsigned int)1763294698ULL),((unsigned int)3435666858ULL),((unsigned int)2295364090ULL)};
unsigned int a_2[4]={((unsigned int)1283471428ULL),((unsigned int)4130700716ULL),((unsigned int)4195851082ULL),((unsigned int)3005332939ULL)};
unsigned int b_2[4]={((unsigned int)1283471428ULL),((unsigned int)4130700716ULL),((unsigned int)4195851082ULL),((unsigned int)3005332939ULL)};
unsigned int a_3[4]={((unsigned int)1052373674ULL),((unsigned int)3424467687ULL),((unsigned int)1581180957ULL),((unsigned int)1992907932ULL)};
unsigned int b_3[4]={((unsigned int)1052373674ULL),((unsigned int)3424467687ULL),((unsigned int)1581180957ULL),((unsigned int)1992907932ULL)};
unsigned int a_4[16]={((unsigned int)3357207471ULL),((unsigned int)1181381057ULL),((unsigned int)2033543625ULL),((unsigned int)169630380ULL),((unsigned int)124966165ULL),((unsigned int)1951929334ULL),((unsigned int)2855907946ULL),((unsigned int)990502410ULL),((unsigned int)750194779ULL),((unsigned int)3314840376ULL),((unsigned int)2671713976ULL),((unsigned int)1803893998ULL),((unsigned int)2700589497ULL),((unsigned int)75401165ULL),((unsigned int)2762624884ULL),((unsigned int)800679976ULL)};
unsigned int b_4[16]={((unsigned int)3357207471ULL),((unsigned int)1181381057ULL),((unsigned int)2033543625ULL),((unsigned int)169630380ULL),((unsigned int)124966165ULL),((unsigned int)1951929334ULL),((unsigned int)2855907946ULL),((unsigned int)990502410ULL),((unsigned int)750194779ULL),((unsigned int)3314840376ULL),((unsigned int)2671713976ULL),((unsigned int)1803893998ULL),((unsigned int)2700589497ULL),((unsigned int)75401165ULL),((unsigned int)2762624884ULL),((unsigned int)800679976ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 188\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3940616844ULL),((unsigned int)138888476ULL),((unsigned int)2614393760ULL),((unsigned int)1446418699ULL)};
unsigned int b_0[4]={((unsigned int)3940616844ULL),((unsigned int)138888476ULL),((unsigned int)2614393760ULL),((unsigned int)1446418699ULL)};
unsigned int a_1[4]={((unsigned int)4108954324ULL),((unsigned int)571888051ULL),((unsigned int)2109105352ULL),((unsigned int)3777235166ULL)};
unsigned int b_1[4]={((unsigned int)4108954324ULL),((unsigned int)571888051ULL),((unsigned int)2109105352ULL),((unsigned int)3777235166ULL)};
unsigned int a_2[4]={((unsigned int)2423214117ULL),((unsigned int)4033166236ULL),((unsigned int)1466998867ULL),((unsigned int)588117088ULL)};
unsigned int b_2[4]={((unsigned int)2423214117ULL),((unsigned int)4033166236ULL),((unsigned int)1466998867ULL),((unsigned int)588117088ULL)};
unsigned int a_3[4]={((unsigned int)646182592ULL),((unsigned int)233976840ULL),((unsigned int)3018365690ULL),((unsigned int)3401919389ULL)};
unsigned int b_3[4]={((unsigned int)646182592ULL),((unsigned int)233976840ULL),((unsigned int)3018365690ULL),((unsigned int)3401919389ULL)};
unsigned int a_4[16]={((unsigned int)2394958879ULL),((unsigned int)1963023642ULL),((unsigned int)73529204ULL),((unsigned int)3446797816ULL),((unsigned int)1539907052ULL),((unsigned int)211063192ULL),((unsigned int)2276125518ULL),((unsigned int)2948531810ULL),((unsigned int)2125635903ULL),((unsigned int)1576805098ULL),((unsigned int)2105624408ULL),((unsigned int)2387708018ULL),((unsigned int)4030211100ULL),((unsigned int)1284910782ULL),((unsigned int)2805149705ULL),((unsigned int)48242283ULL)};
unsigned int b_4[16]={((unsigned int)2394958879ULL),((unsigned int)1963023642ULL),((unsigned int)73529204ULL),((unsigned int)3446797816ULL),((unsigned int)1539907052ULL),((unsigned int)211063192ULL),((unsigned int)2276125518ULL),((unsigned int)2948531810ULL),((unsigned int)2125635903ULL),((unsigned int)1576805098ULL),((unsigned int)2105624408ULL),((unsigned int)2387708018ULL),((unsigned int)4030211100ULL),((unsigned int)1284910782ULL),((unsigned int)2805149705ULL),((unsigned int)48242283ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 189\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)308478979ULL),((unsigned int)636980860ULL),((unsigned int)3723043587ULL),((unsigned int)2137399158ULL)};
unsigned int b_0[4]={((unsigned int)308478979ULL),((unsigned int)636980860ULL),((unsigned int)3723043587ULL),((unsigned int)2137399158ULL)};
unsigned int a_1[4]={((unsigned int)727383937ULL),((unsigned int)3365239413ULL),((unsigned int)2057510751ULL),((unsigned int)3170695157ULL)};
unsigned int b_1[4]={((unsigned int)727383937ULL),((unsigned int)3365239413ULL),((unsigned int)2057510751ULL),((unsigned int)3170695157ULL)};
unsigned int a_2[4]={((unsigned int)570823261ULL),((unsigned int)4049486402ULL),((unsigned int)3757433973ULL),((unsigned int)968877566ULL)};
unsigned int b_2[4]={((unsigned int)570823261ULL),((unsigned int)4049486402ULL),((unsigned int)3757433973ULL),((unsigned int)968877566ULL)};
unsigned int a_3[4]={((unsigned int)644353889ULL),((unsigned int)1864189946ULL),((unsigned int)1291395688ULL),((unsigned int)1544210188ULL)};
unsigned int b_3[4]={((unsigned int)644353889ULL),((unsigned int)1864189946ULL),((unsigned int)1291395688ULL),((unsigned int)1544210188ULL)};
unsigned int a_4[16]={((unsigned int)1490076414ULL),((unsigned int)2697324340ULL),((unsigned int)756789433ULL),((unsigned int)939052989ULL),((unsigned int)1300905838ULL),((unsigned int)451635787ULL),((unsigned int)1544795118ULL),((unsigned int)906849481ULL),((unsigned int)1368285493ULL),((unsigned int)372706068ULL),((unsigned int)455412862ULL),((unsigned int)1420935332ULL),((unsigned int)304787732ULL),((unsigned int)3492028154ULL),((unsigned int)1764490290ULL),((unsigned int)3576101404ULL)};
unsigned int b_4[16]={((unsigned int)1490076414ULL),((unsigned int)2697324340ULL),((unsigned int)756789433ULL),((unsigned int)939052989ULL),((unsigned int)1300905838ULL),((unsigned int)451635787ULL),((unsigned int)1544795118ULL),((unsigned int)906849481ULL),((unsigned int)1368285493ULL),((unsigned int)372706068ULL),((unsigned int)455412862ULL),((unsigned int)1420935332ULL),((unsigned int)304787732ULL),((unsigned int)3492028154ULL),((unsigned int)1764490290ULL),((unsigned int)3576101404ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 190\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4047878612ULL),((unsigned int)3122089811ULL),((unsigned int)817891412ULL),((unsigned int)621086024ULL)};
unsigned int b_0[4]={((unsigned int)4047878612ULL),((unsigned int)3122089811ULL),((unsigned int)817891412ULL),((unsigned int)621086024ULL)};
unsigned int a_1[4]={((unsigned int)4127771360ULL),((unsigned int)1609851831ULL),((unsigned int)1126439496ULL),((unsigned int)1282840186ULL)};
unsigned int b_1[4]={((unsigned int)4127771360ULL),((unsigned int)1609851831ULL),((unsigned int)1126439496ULL),((unsigned int)1282840186ULL)};
unsigned int a_2[4]={((unsigned int)1422139533ULL),((unsigned int)3531813629ULL),((unsigned int)3632458885ULL),((unsigned int)3889393188ULL)};
unsigned int b_2[4]={((unsigned int)1422139533ULL),((unsigned int)3531813629ULL),((unsigned int)3632458885ULL),((unsigned int)3889393188ULL)};
unsigned int a_3[4]={((unsigned int)3866909004ULL),((unsigned int)2511813027ULL),((unsigned int)2551642771ULL),((unsigned int)872396079ULL)};
unsigned int b_3[4]={((unsigned int)3866909004ULL),((unsigned int)2511813027ULL),((unsigned int)2551642771ULL),((unsigned int)872396079ULL)};
unsigned int a_4[16]={((unsigned int)2702759751ULL),((unsigned int)1789973351ULL),((unsigned int)4287454966ULL),((unsigned int)3555337150ULL),((unsigned int)2799807061ULL),((unsigned int)1291395343ULL),((unsigned int)3777219125ULL),((unsigned int)3791974959ULL),((unsigned int)1276259137ULL),((unsigned int)854860131ULL),((unsigned int)2565188029ULL),((unsigned int)4142886311ULL),((unsigned int)3829221932ULL),((unsigned int)4159221728ULL),((unsigned int)1651965115ULL),((unsigned int)2397310392ULL)};
unsigned int b_4[16]={((unsigned int)2702759751ULL),((unsigned int)1789973351ULL),((unsigned int)4287454966ULL),((unsigned int)3555337150ULL),((unsigned int)2799807061ULL),((unsigned int)1291395343ULL),((unsigned int)3777219125ULL),((unsigned int)3791974959ULL),((unsigned int)1276259137ULL),((unsigned int)854860131ULL),((unsigned int)2565188029ULL),((unsigned int)4142886311ULL),((unsigned int)3829221932ULL),((unsigned int)4159221728ULL),((unsigned int)1651965115ULL),((unsigned int)2397310392ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 191\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3191105372ULL),((unsigned int)4117184711ULL),((unsigned int)3923668456ULL),((unsigned int)1924859089ULL)};
unsigned int b_0[4]={((unsigned int)3191105372ULL),((unsigned int)4117184711ULL),((unsigned int)3923668456ULL),((unsigned int)1924859089ULL)};
unsigned int a_1[4]={((unsigned int)856799438ULL),((unsigned int)2563563919ULL),((unsigned int)2023462382ULL),((unsigned int)837497325ULL)};
unsigned int b_1[4]={((unsigned int)856799438ULL),((unsigned int)2563563919ULL),((unsigned int)2023462382ULL),((unsigned int)837497325ULL)};
unsigned int a_2[4]={((unsigned int)3540161779ULL),((unsigned int)4205441683ULL),((unsigned int)2307679361ULL),((unsigned int)3952017136ULL)};
unsigned int b_2[4]={((unsigned int)3540161779ULL),((unsigned int)4205441683ULL),((unsigned int)2307679361ULL),((unsigned int)3952017136ULL)};
unsigned int a_3[4]={((unsigned int)1698924595ULL),((unsigned int)2015371548ULL),((unsigned int)4130768019ULL),((unsigned int)650325164ULL)};
unsigned int b_3[4]={((unsigned int)1698924595ULL),((unsigned int)2015371548ULL),((unsigned int)4130768019ULL),((unsigned int)650325164ULL)};
unsigned int a_4[16]={((unsigned int)1037348972ULL),((unsigned int)817476425ULL),((unsigned int)634275545ULL),((unsigned int)241257049ULL),((unsigned int)1444089605ULL),((unsigned int)2628082805ULL),((unsigned int)3171453042ULL),((unsigned int)3243237185ULL),((unsigned int)3245088867ULL),((unsigned int)3711246130ULL),((unsigned int)64216509ULL),((unsigned int)477335453ULL),((unsigned int)3050547657ULL),((unsigned int)567114729ULL),((unsigned int)1217923739ULL),((unsigned int)2533251723ULL)};
unsigned int b_4[16]={((unsigned int)1037348972ULL),((unsigned int)817476425ULL),((unsigned int)634275545ULL),((unsigned int)241257049ULL),((unsigned int)1444089605ULL),((unsigned int)2628082805ULL),((unsigned int)3171453042ULL),((unsigned int)3243237185ULL),((unsigned int)3245088867ULL),((unsigned int)3711246130ULL),((unsigned int)64216509ULL),((unsigned int)477335453ULL),((unsigned int)3050547657ULL),((unsigned int)567114729ULL),((unsigned int)1217923739ULL),((unsigned int)2533251723ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 192\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)195832879ULL),((unsigned int)1694568071ULL),((unsigned int)143767745ULL),((unsigned int)3900275530ULL)};
unsigned int b_0[4]={((unsigned int)195832879ULL),((unsigned int)1694568071ULL),((unsigned int)143767745ULL),((unsigned int)3900275530ULL)};
unsigned int a_1[4]={((unsigned int)3701994999ULL),((unsigned int)2130119700ULL),((unsigned int)3839665943ULL),((unsigned int)485423117ULL)};
unsigned int b_1[4]={((unsigned int)3701994999ULL),((unsigned int)2130119700ULL),((unsigned int)3839665943ULL),((unsigned int)485423117ULL)};
unsigned int a_2[4]={((unsigned int)1883353508ULL),((unsigned int)1713057281ULL),((unsigned int)3047489346ULL),((unsigned int)1375818379ULL)};
unsigned int b_2[4]={((unsigned int)1883353508ULL),((unsigned int)1713057281ULL),((unsigned int)3047489346ULL),((unsigned int)1375818379ULL)};
unsigned int a_3[4]={((unsigned int)3786140638ULL),((unsigned int)2125982344ULL),((unsigned int)3560832020ULL),((unsigned int)1773788573ULL)};
unsigned int b_3[4]={((unsigned int)3786140638ULL),((unsigned int)2125982344ULL),((unsigned int)3560832020ULL),((unsigned int)1773788573ULL)};
unsigned int a_4[16]={((unsigned int)3169064977ULL),((unsigned int)3818148266ULL),((unsigned int)4203613658ULL),((unsigned int)3583695701ULL),((unsigned int)3086891813ULL),((unsigned int)1253945651ULL),((unsigned int)589199116ULL),((unsigned int)2951939609ULL),((unsigned int)2818375446ULL),((unsigned int)1156362169ULL),((unsigned int)2787117529ULL),((unsigned int)2838883978ULL),((unsigned int)1932528015ULL),((unsigned int)2378043931ULL),((unsigned int)630204023ULL),((unsigned int)873041167ULL)};
unsigned int b_4[16]={((unsigned int)3169064977ULL),((unsigned int)3818148266ULL),((unsigned int)4203613658ULL),((unsigned int)3583695701ULL),((unsigned int)3086891813ULL),((unsigned int)1253945651ULL),((unsigned int)589199116ULL),((unsigned int)2951939609ULL),((unsigned int)2818375446ULL),((unsigned int)1156362169ULL),((unsigned int)2787117529ULL),((unsigned int)2838883978ULL),((unsigned int)1932528015ULL),((unsigned int)2378043931ULL),((unsigned int)630204023ULL),((unsigned int)873041167ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 193\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2115497896ULL),((unsigned int)1182162793ULL),((unsigned int)2747089290ULL),((unsigned int)3380388754ULL)};
unsigned int b_0[4]={((unsigned int)2115497896ULL),((unsigned int)1182162793ULL),((unsigned int)2747089290ULL),((unsigned int)3380388754ULL)};
unsigned int a_1[4]={((unsigned int)3522091082ULL),((unsigned int)3758431996ULL),((unsigned int)1558841900ULL),((unsigned int)2416809665ULL)};
unsigned int b_1[4]={((unsigned int)3522091082ULL),((unsigned int)3758431996ULL),((unsigned int)1558841900ULL),((unsigned int)2416809665ULL)};
unsigned int a_2[4]={((unsigned int)3262699810ULL),((unsigned int)1548721859ULL),((unsigned int)1034101986ULL),((unsigned int)2468017926ULL)};
unsigned int b_2[4]={((unsigned int)3262699810ULL),((unsigned int)1548721859ULL),((unsigned int)1034101986ULL),((unsigned int)2468017926ULL)};
unsigned int a_3[4]={((unsigned int)705778994ULL),((unsigned int)3611901775ULL),((unsigned int)103356234ULL),((unsigned int)997081122ULL)};
unsigned int b_3[4]={((unsigned int)705778994ULL),((unsigned int)3611901775ULL),((unsigned int)103356234ULL),((unsigned int)997081122ULL)};
unsigned int a_4[16]={((unsigned int)841250285ULL),((unsigned int)143461478ULL),((unsigned int)3529274426ULL),((unsigned int)2773135196ULL),((unsigned int)193616676ULL),((unsigned int)896903341ULL),((unsigned int)2678589200ULL),((unsigned int)3704671690ULL),((unsigned int)267107154ULL),((unsigned int)4161771152ULL),((unsigned int)3325759379ULL),((unsigned int)3529930403ULL),((unsigned int)4115127376ULL),((unsigned int)775543672ULL),((unsigned int)718158373ULL),((unsigned int)3218593360ULL)};
unsigned int b_4[16]={((unsigned int)841250285ULL),((unsigned int)143461478ULL),((unsigned int)3529274426ULL),((unsigned int)2773135196ULL),((unsigned int)193616676ULL),((unsigned int)896903341ULL),((unsigned int)2678589200ULL),((unsigned int)3704671690ULL),((unsigned int)267107154ULL),((unsigned int)4161771152ULL),((unsigned int)3325759379ULL),((unsigned int)3529930403ULL),((unsigned int)4115127376ULL),((unsigned int)775543672ULL),((unsigned int)718158373ULL),((unsigned int)3218593360ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 194\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)145727617ULL),((unsigned int)2705044613ULL),((unsigned int)835480997ULL),((unsigned int)4093080824ULL)};
unsigned int b_0[4]={((unsigned int)145727617ULL),((unsigned int)2705044613ULL),((unsigned int)835480997ULL),((unsigned int)4093080824ULL)};
unsigned int a_1[4]={((unsigned int)90576436ULL),((unsigned int)1775175763ULL),((unsigned int)734258234ULL),((unsigned int)1615035340ULL)};
unsigned int b_1[4]={((unsigned int)90576436ULL),((unsigned int)1775175763ULL),((unsigned int)734258234ULL),((unsigned int)1615035340ULL)};
unsigned int a_2[4]={((unsigned int)1286570065ULL),((unsigned int)1677302609ULL),((unsigned int)3161995984ULL),((unsigned int)597558827ULL)};
unsigned int b_2[4]={((unsigned int)1286570065ULL),((unsigned int)1677302609ULL),((unsigned int)3161995984ULL),((unsigned int)597558827ULL)};
unsigned int a_3[4]={((unsigned int)1807450370ULL),((unsigned int)675791994ULL),((unsigned int)330963865ULL),((unsigned int)3085032972ULL)};
unsigned int b_3[4]={((unsigned int)1807450370ULL),((unsigned int)675791994ULL),((unsigned int)330963865ULL),((unsigned int)3085032972ULL)};
unsigned int a_4[16]={((unsigned int)3123234464ULL),((unsigned int)3190068497ULL),((unsigned int)2335500422ULL),((unsigned int)3996835567ULL),((unsigned int)1443835914ULL),((unsigned int)4073813185ULL),((unsigned int)956676568ULL),((unsigned int)2363199255ULL),((unsigned int)1054526627ULL),((unsigned int)2405303454ULL),((unsigned int)547589542ULL),((unsigned int)3052319536ULL),((unsigned int)3609112177ULL),((unsigned int)571595282ULL),((unsigned int)1152455727ULL),((unsigned int)2511057517ULL)};
unsigned int b_4[16]={((unsigned int)3123234464ULL),((unsigned int)3190068497ULL),((unsigned int)2335500422ULL),((unsigned int)3996835567ULL),((unsigned int)1443835914ULL),((unsigned int)4073813185ULL),((unsigned int)956676568ULL),((unsigned int)2363199255ULL),((unsigned int)1054526627ULL),((unsigned int)2405303454ULL),((unsigned int)547589542ULL),((unsigned int)3052319536ULL),((unsigned int)3609112177ULL),((unsigned int)571595282ULL),((unsigned int)1152455727ULL),((unsigned int)2511057517ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 195\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4074503149ULL),((unsigned int)1312464457ULL),((unsigned int)644768838ULL),((unsigned int)3945774519ULL)};
unsigned int b_0[4]={((unsigned int)4074503149ULL),((unsigned int)1312464457ULL),((unsigned int)644768838ULL),((unsigned int)3945774519ULL)};
unsigned int a_1[4]={((unsigned int)3187579565ULL),((unsigned int)4009396229ULL),((unsigned int)902275892ULL),((unsigned int)233569456ULL)};
unsigned int b_1[4]={((unsigned int)3187579565ULL),((unsigned int)4009396229ULL),((unsigned int)902275892ULL),((unsigned int)233569456ULL)};
unsigned int a_2[4]={((unsigned int)2660576572ULL),((unsigned int)2614360083ULL),((unsigned int)2284940813ULL),((unsigned int)3876851479ULL)};
unsigned int b_2[4]={((unsigned int)2660576572ULL),((unsigned int)2614360083ULL),((unsigned int)2284940813ULL),((unsigned int)3876851479ULL)};
unsigned int a_3[4]={((unsigned int)1194748407ULL),((unsigned int)2229185168ULL),((unsigned int)4195267649ULL),((unsigned int)2620735118ULL)};
unsigned int b_3[4]={((unsigned int)1194748407ULL),((unsigned int)2229185168ULL),((unsigned int)4195267649ULL),((unsigned int)2620735118ULL)};
unsigned int a_4[16]={((unsigned int)140218991ULL),((unsigned int)1917147275ULL),((unsigned int)3542116235ULL),((unsigned int)1428072276ULL),((unsigned int)925318949ULL),((unsigned int)4266718678ULL),((unsigned int)308215643ULL),((unsigned int)2607154954ULL),((unsigned int)4054193809ULL),((unsigned int)2348290061ULL),((unsigned int)405065206ULL),((unsigned int)2600451803ULL),((unsigned int)3718756489ULL),((unsigned int)2517469643ULL),((unsigned int)1457670923ULL),((unsigned int)1988944703ULL)};
unsigned int b_4[16]={((unsigned int)140218991ULL),((unsigned int)1917147275ULL),((unsigned int)3542116235ULL),((unsigned int)1428072276ULL),((unsigned int)925318949ULL),((unsigned int)4266718678ULL),((unsigned int)308215643ULL),((unsigned int)2607154954ULL),((unsigned int)4054193809ULL),((unsigned int)2348290061ULL),((unsigned int)405065206ULL),((unsigned int)2600451803ULL),((unsigned int)3718756489ULL),((unsigned int)2517469643ULL),((unsigned int)1457670923ULL),((unsigned int)1988944703ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 196\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4066258369ULL),((unsigned int)3647634366ULL),((unsigned int)1039311780ULL),((unsigned int)1445083657ULL)};
unsigned int b_0[4]={((unsigned int)4066258369ULL),((unsigned int)3647634366ULL),((unsigned int)1039311780ULL),((unsigned int)1445083657ULL)};
unsigned int a_1[4]={((unsigned int)1919778779ULL),((unsigned int)1956944098ULL),((unsigned int)3822790195ULL),((unsigned int)2870456370ULL)};
unsigned int b_1[4]={((unsigned int)1919778779ULL),((unsigned int)1956944098ULL),((unsigned int)3822790195ULL),((unsigned int)2870456370ULL)};
unsigned int a_2[4]={((unsigned int)3813596801ULL),((unsigned int)1073861246ULL),((unsigned int)681307670ULL),((unsigned int)2224709228ULL)};
unsigned int b_2[4]={((unsigned int)3813596801ULL),((unsigned int)1073861246ULL),((unsigned int)681307670ULL),((unsigned int)2224709228ULL)};
unsigned int a_3[4]={((unsigned int)2403566880ULL),((unsigned int)4294832125ULL),((unsigned int)4076521328ULL),((unsigned int)3766180900ULL)};
unsigned int b_3[4]={((unsigned int)2403566880ULL),((unsigned int)4294832125ULL),((unsigned int)4076521328ULL),((unsigned int)3766180900ULL)};
unsigned int a_4[16]={((unsigned int)752929039ULL),((unsigned int)1548144968ULL),((unsigned int)35101703ULL),((unsigned int)1614161505ULL),((unsigned int)2931453778ULL),((unsigned int)121762434ULL),((unsigned int)1079373017ULL),((unsigned int)3245379296ULL),((unsigned int)680886107ULL),((unsigned int)1761107520ULL),((unsigned int)9493264ULL),((unsigned int)3796967649ULL),((unsigned int)2943698198ULL),((unsigned int)2077075239ULL),((unsigned int)3614920670ULL),((unsigned int)3230155874ULL)};
unsigned int b_4[16]={((unsigned int)752929039ULL),((unsigned int)1548144968ULL),((unsigned int)35101703ULL),((unsigned int)1614161505ULL),((unsigned int)2931453778ULL),((unsigned int)121762434ULL),((unsigned int)1079373017ULL),((unsigned int)3245379296ULL),((unsigned int)680886107ULL),((unsigned int)1761107520ULL),((unsigned int)9493264ULL),((unsigned int)3796967649ULL),((unsigned int)2943698198ULL),((unsigned int)2077075239ULL),((unsigned int)3614920670ULL),((unsigned int)3230155874ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 197\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2144574107ULL),((unsigned int)1218688021ULL),((unsigned int)3479067840ULL),((unsigned int)1341195755ULL)};
unsigned int b_0[4]={((unsigned int)2144574107ULL),((unsigned int)1218688021ULL),((unsigned int)3479067840ULL),((unsigned int)1341195755ULL)};
unsigned int a_1[4]={((unsigned int)3603288664ULL),((unsigned int)1192237652ULL),((unsigned int)3203773031ULL),((unsigned int)1121219937ULL)};
unsigned int b_1[4]={((unsigned int)3603288664ULL),((unsigned int)1192237652ULL),((unsigned int)3203773031ULL),((unsigned int)1121219937ULL)};
unsigned int a_2[4]={((unsigned int)3336095881ULL),((unsigned int)4090304648ULL),((unsigned int)3567021207ULL),((unsigned int)1219112207ULL)};
unsigned int b_2[4]={((unsigned int)3336095881ULL),((unsigned int)4090304648ULL),((unsigned int)3567021207ULL),((unsigned int)1219112207ULL)};
unsigned int a_3[4]={((unsigned int)57870027ULL),((unsigned int)2311169819ULL),((unsigned int)100882195ULL),((unsigned int)1626258832ULL)};
unsigned int b_3[4]={((unsigned int)57870027ULL),((unsigned int)2311169819ULL),((unsigned int)100882195ULL),((unsigned int)1626258832ULL)};
unsigned int a_4[16]={((unsigned int)2353285686ULL),((unsigned int)3182069420ULL),((unsigned int)1869084133ULL),((unsigned int)1755946872ULL),((unsigned int)2001753430ULL),((unsigned int)1396699424ULL),((unsigned int)1025049264ULL),((unsigned int)1149322098ULL),((unsigned int)1587935886ULL),((unsigned int)3361125832ULL),((unsigned int)1662569932ULL),((unsigned int)2184387161ULL),((unsigned int)1113256744ULL),((unsigned int)594534382ULL),((unsigned int)2596987730ULL),((unsigned int)624113095ULL)};
unsigned int b_4[16]={((unsigned int)2353285686ULL),((unsigned int)3182069420ULL),((unsigned int)1869084133ULL),((unsigned int)1755946872ULL),((unsigned int)2001753430ULL),((unsigned int)1396699424ULL),((unsigned int)1025049264ULL),((unsigned int)1149322098ULL),((unsigned int)1587935886ULL),((unsigned int)3361125832ULL),((unsigned int)1662569932ULL),((unsigned int)2184387161ULL),((unsigned int)1113256744ULL),((unsigned int)594534382ULL),((unsigned int)2596987730ULL),((unsigned int)624113095ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 198\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)488850966ULL),((unsigned int)2257084548ULL),((unsigned int)2194384540ULL),((unsigned int)3558227553ULL)};
unsigned int b_0[4]={((unsigned int)488850966ULL),((unsigned int)2257084548ULL),((unsigned int)2194384540ULL),((unsigned int)3558227553ULL)};
unsigned int a_1[4]={((unsigned int)1893912100ULL),((unsigned int)4051865036ULL),((unsigned int)1587215397ULL),((unsigned int)1368815970ULL)};
unsigned int b_1[4]={((unsigned int)1893912100ULL),((unsigned int)4051865036ULL),((unsigned int)1587215397ULL),((unsigned int)1368815970ULL)};
unsigned int a_2[4]={((unsigned int)3470844778ULL),((unsigned int)2415280340ULL),((unsigned int)4175417929ULL),((unsigned int)2375405762ULL)};
unsigned int b_2[4]={((unsigned int)3470844778ULL),((unsigned int)2415280340ULL),((unsigned int)4175417929ULL),((unsigned int)2375405762ULL)};
unsigned int a_3[4]={((unsigned int)3028850282ULL),((unsigned int)128055198ULL),((unsigned int)1521585870ULL),((unsigned int)2960051073ULL)};
unsigned int b_3[4]={((unsigned int)3028850282ULL),((unsigned int)128055198ULL),((unsigned int)1521585870ULL),((unsigned int)2960051073ULL)};
unsigned int a_4[16]={((unsigned int)3519986027ULL),((unsigned int)2709348430ULL),((unsigned int)1235828895ULL),((unsigned int)1883407733ULL),((unsigned int)2107570939ULL),((unsigned int)2556159656ULL),((unsigned int)3946109543ULL),((unsigned int)3776472036ULL),((unsigned int)3019033376ULL),((unsigned int)1361491115ULL),((unsigned int)2211309984ULL),((unsigned int)1451277429ULL),((unsigned int)2987425042ULL),((unsigned int)2051851456ULL),((unsigned int)1144045910ULL),((unsigned int)2429690130ULL)};
unsigned int b_4[16]={((unsigned int)3519986027ULL),((unsigned int)2709348430ULL),((unsigned int)1235828895ULL),((unsigned int)1883407733ULL),((unsigned int)2107570939ULL),((unsigned int)2556159656ULL),((unsigned int)3946109543ULL),((unsigned int)3776472036ULL),((unsigned int)3019033376ULL),((unsigned int)1361491115ULL),((unsigned int)2211309984ULL),((unsigned int)1451277429ULL),((unsigned int)2987425042ULL),((unsigned int)2051851456ULL),((unsigned int)1144045910ULL),((unsigned int)2429690130ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 199\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)853955253ULL),((unsigned int)3214061414ULL),((unsigned int)2641747703ULL),((unsigned int)2348838032ULL)};
unsigned int b_0[4]={((unsigned int)853955253ULL),((unsigned int)3214061414ULL),((unsigned int)2641747703ULL),((unsigned int)2348838032ULL)};
unsigned int a_1[4]={((unsigned int)1440038709ULL),((unsigned int)1766562274ULL),((unsigned int)3580314676ULL),((unsigned int)1177230979ULL)};
unsigned int b_1[4]={((unsigned int)1440038709ULL),((unsigned int)1766562274ULL),((unsigned int)3580314676ULL),((unsigned int)1177230979ULL)};
unsigned int a_2[4]={((unsigned int)1752369170ULL),((unsigned int)1970281571ULL),((unsigned int)2259788388ULL),((unsigned int)3990949123ULL)};
unsigned int b_2[4]={((unsigned int)1752369170ULL),((unsigned int)1970281571ULL),((unsigned int)2259788388ULL),((unsigned int)3990949123ULL)};
unsigned int a_3[4]={((unsigned int)2572144705ULL),((unsigned int)1259801118ULL),((unsigned int)876520440ULL),((unsigned int)3564469520ULL)};
unsigned int b_3[4]={((unsigned int)2572144705ULL),((unsigned int)1259801118ULL),((unsigned int)876520440ULL),((unsigned int)3564469520ULL)};
unsigned int a_4[16]={((unsigned int)1833406358ULL),((unsigned int)2650019325ULL),((unsigned int)1431585605ULL),((unsigned int)1273068068ULL),((unsigned int)1455229870ULL),((unsigned int)301246025ULL),((unsigned int)4281523406ULL),((unsigned int)1414914807ULL),((unsigned int)3562599918ULL),((unsigned int)1717416527ULL),((unsigned int)3273216437ULL),((unsigned int)2405364230ULL),((unsigned int)513798800ULL),((unsigned int)639550037ULL),((unsigned int)1841153986ULL),((unsigned int)3173353453ULL)};
unsigned int b_4[16]={((unsigned int)1833406358ULL),((unsigned int)2650019325ULL),((unsigned int)1431585605ULL),((unsigned int)1273068068ULL),((unsigned int)1455229870ULL),((unsigned int)301246025ULL),((unsigned int)4281523406ULL),((unsigned int)1414914807ULL),((unsigned int)3562599918ULL),((unsigned int)1717416527ULL),((unsigned int)3273216437ULL),((unsigned int)2405364230ULL),((unsigned int)513798800ULL),((unsigned int)639550037ULL),((unsigned int)1841153986ULL),((unsigned int)3173353453ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 200\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2797936728ULL),((unsigned int)2667785899ULL),((unsigned int)2569717147ULL),((unsigned int)1583339330ULL)};
unsigned int b_0[4]={((unsigned int)2797936728ULL),((unsigned int)2667785899ULL),((unsigned int)2569717147ULL),((unsigned int)1583339330ULL)};
unsigned int a_1[4]={((unsigned int)858683596ULL),((unsigned int)2793443401ULL),((unsigned int)2297351261ULL),((unsigned int)2352384859ULL)};
unsigned int b_1[4]={((unsigned int)858683596ULL),((unsigned int)2793443401ULL),((unsigned int)2297351261ULL),((unsigned int)2352384859ULL)};
unsigned int a_2[4]={((unsigned int)3553460220ULL),((unsigned int)2948562848ULL),((unsigned int)1814770541ULL),((unsigned int)984917971ULL)};
unsigned int b_2[4]={((unsigned int)3553460220ULL),((unsigned int)2948562848ULL),((unsigned int)1814770541ULL),((unsigned int)984917971ULL)};
unsigned int a_3[4]={((unsigned int)3156064675ULL),((unsigned int)4047358229ULL),((unsigned int)2470419568ULL),((unsigned int)1582608340ULL)};
unsigned int b_3[4]={((unsigned int)3156064675ULL),((unsigned int)4047358229ULL),((unsigned int)2470419568ULL),((unsigned int)1582608340ULL)};
unsigned int a_4[16]={((unsigned int)555813180ULL),((unsigned int)4158222501ULL),((unsigned int)2257338577ULL),((unsigned int)4176962824ULL),((unsigned int)2674619844ULL),((unsigned int)35631510ULL),((unsigned int)847627600ULL),((unsigned int)1761911130ULL),((unsigned int)3502783701ULL),((unsigned int)2351433917ULL),((unsigned int)2160392486ULL),((unsigned int)642379555ULL),((unsigned int)1652233011ULL),((unsigned int)666722683ULL),((unsigned int)3143236304ULL),((unsigned int)251570370ULL)};
unsigned int b_4[16]={((unsigned int)555813180ULL),((unsigned int)4158222501ULL),((unsigned int)2257338577ULL),((unsigned int)4176962824ULL),((unsigned int)2674619844ULL),((unsigned int)35631510ULL),((unsigned int)847627600ULL),((unsigned int)1761911130ULL),((unsigned int)3502783701ULL),((unsigned int)2351433917ULL),((unsigned int)2160392486ULL),((unsigned int)642379555ULL),((unsigned int)1652233011ULL),((unsigned int)666722683ULL),((unsigned int)3143236304ULL),((unsigned int)251570370ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 201\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2756223367ULL),((unsigned int)3488259764ULL),((unsigned int)4153574444ULL),((unsigned int)3185276358ULL)};
unsigned int b_0[4]={((unsigned int)2756223367ULL),((unsigned int)3488259764ULL),((unsigned int)4153574444ULL),((unsigned int)3185276358ULL)};
unsigned int a_1[4]={((unsigned int)265217870ULL),((unsigned int)4283737467ULL),((unsigned int)2734937191ULL),((unsigned int)2318242753ULL)};
unsigned int b_1[4]={((unsigned int)265217870ULL),((unsigned int)4283737467ULL),((unsigned int)2734937191ULL),((unsigned int)2318242753ULL)};
unsigned int a_2[4]={((unsigned int)13725403ULL),((unsigned int)2414571745ULL),((unsigned int)1496360559ULL),((unsigned int)3162620285ULL)};
unsigned int b_2[4]={((unsigned int)13725403ULL),((unsigned int)2414571745ULL),((unsigned int)1496360559ULL),((unsigned int)3162620285ULL)};
unsigned int a_3[4]={((unsigned int)3849292433ULL),((unsigned int)3113803344ULL),((unsigned int)273017135ULL),((unsigned int)3140980663ULL)};
unsigned int b_3[4]={((unsigned int)3849292433ULL),((unsigned int)3113803344ULL),((unsigned int)273017135ULL),((unsigned int)3140980663ULL)};
unsigned int a_4[16]={((unsigned int)716493877ULL),((unsigned int)1930976265ULL),((unsigned int)4073506211ULL),((unsigned int)3367330284ULL),((unsigned int)661326293ULL),((unsigned int)3843228936ULL),((unsigned int)2322968535ULL),((unsigned int)2586487882ULL),((unsigned int)3567433576ULL),((unsigned int)2393028953ULL),((unsigned int)1378107405ULL),((unsigned int)1631790641ULL),((unsigned int)2743603432ULL),((unsigned int)1737742261ULL),((unsigned int)1000748817ULL),((unsigned int)74982883ULL)};
unsigned int b_4[16]={((unsigned int)716493877ULL),((unsigned int)1930976265ULL),((unsigned int)4073506211ULL),((unsigned int)3367330284ULL),((unsigned int)661326293ULL),((unsigned int)3843228936ULL),((unsigned int)2322968535ULL),((unsigned int)2586487882ULL),((unsigned int)3567433576ULL),((unsigned int)2393028953ULL),((unsigned int)1378107405ULL),((unsigned int)1631790641ULL),((unsigned int)2743603432ULL),((unsigned int)1737742261ULL),((unsigned int)1000748817ULL),((unsigned int)74982883ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 202\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3002703801ULL),((unsigned int)3269387076ULL),((unsigned int)2858200640ULL),((unsigned int)2753317124ULL)};
unsigned int b_0[4]={((unsigned int)3002703801ULL),((unsigned int)3269387076ULL),((unsigned int)2858200640ULL),((unsigned int)2753317124ULL)};
unsigned int a_1[4]={((unsigned int)2573670917ULL),((unsigned int)2610681862ULL),((unsigned int)2576632104ULL),((unsigned int)4168597031ULL)};
unsigned int b_1[4]={((unsigned int)2573670917ULL),((unsigned int)2610681862ULL),((unsigned int)2576632104ULL),((unsigned int)4168597031ULL)};
unsigned int a_2[4]={((unsigned int)2011450202ULL),((unsigned int)435918395ULL),((unsigned int)1528443819ULL),((unsigned int)3837575289ULL)};
unsigned int b_2[4]={((unsigned int)2011450202ULL),((unsigned int)435918395ULL),((unsigned int)1528443819ULL),((unsigned int)3837575289ULL)};
unsigned int a_3[4]={((unsigned int)2870900213ULL),((unsigned int)7616860ULL),((unsigned int)2805964214ULL),((unsigned int)1832380119ULL)};
unsigned int b_3[4]={((unsigned int)2870900213ULL),((unsigned int)7616860ULL),((unsigned int)2805964214ULL),((unsigned int)1832380119ULL)};
unsigned int a_4[16]={((unsigned int)3262526783ULL),((unsigned int)3459873490ULL),((unsigned int)2536585237ULL),((unsigned int)2457580718ULL),((unsigned int)3586897728ULL),((unsigned int)3150137259ULL),((unsigned int)3744229497ULL),((unsigned int)1591388465ULL),((unsigned int)2712689676ULL),((unsigned int)1189136390ULL),((unsigned int)2031162415ULL),((unsigned int)3807743671ULL),((unsigned int)1984456843ULL),((unsigned int)2895224417ULL),((unsigned int)3913754340ULL),((unsigned int)4284966223ULL)};
unsigned int b_4[16]={((unsigned int)3262526783ULL),((unsigned int)3459873490ULL),((unsigned int)2536585237ULL),((unsigned int)2457580718ULL),((unsigned int)3586897728ULL),((unsigned int)3150137259ULL),((unsigned int)3744229497ULL),((unsigned int)1591388465ULL),((unsigned int)2712689676ULL),((unsigned int)1189136390ULL),((unsigned int)2031162415ULL),((unsigned int)3807743671ULL),((unsigned int)1984456843ULL),((unsigned int)2895224417ULL),((unsigned int)3913754340ULL),((unsigned int)4284966223ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 203\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3011457860ULL),((unsigned int)2609325995ULL),((unsigned int)1664782559ULL),((unsigned int)986604779ULL)};
unsigned int b_0[4]={((unsigned int)3011457860ULL),((unsigned int)2609325995ULL),((unsigned int)1664782559ULL),((unsigned int)986604779ULL)};
unsigned int a_1[4]={((unsigned int)2341775092ULL),((unsigned int)114347482ULL),((unsigned int)1111354260ULL),((unsigned int)4293303266ULL)};
unsigned int b_1[4]={((unsigned int)2341775092ULL),((unsigned int)114347482ULL),((unsigned int)1111354260ULL),((unsigned int)4293303266ULL)};
unsigned int a_2[4]={((unsigned int)2254237478ULL),((unsigned int)2241631316ULL),((unsigned int)1683836172ULL),((unsigned int)3101556733ULL)};
unsigned int b_2[4]={((unsigned int)2254237478ULL),((unsigned int)2241631316ULL),((unsigned int)1683836172ULL),((unsigned int)3101556733ULL)};
unsigned int a_3[4]={((unsigned int)2460043813ULL),((unsigned int)3675061723ULL),((unsigned int)48555884ULL),((unsigned int)2339133271ULL)};
unsigned int b_3[4]={((unsigned int)2460043813ULL),((unsigned int)3675061723ULL),((unsigned int)48555884ULL),((unsigned int)2339133271ULL)};
unsigned int a_4[16]={((unsigned int)922656375ULL),((unsigned int)1402404822ULL),((unsigned int)2541554028ULL),((unsigned int)2973164317ULL),((unsigned int)2878665506ULL),((unsigned int)4182453034ULL),((unsigned int)120832402ULL),((unsigned int)765675142ULL),((unsigned int)366068086ULL),((unsigned int)1163426272ULL),((unsigned int)3007216775ULL),((unsigned int)3077220472ULL),((unsigned int)3664182203ULL),((unsigned int)1297572554ULL),((unsigned int)537003049ULL),((unsigned int)3508078208ULL)};
unsigned int b_4[16]={((unsigned int)922656375ULL),((unsigned int)1402404822ULL),((unsigned int)2541554028ULL),((unsigned int)2973164317ULL),((unsigned int)2878665506ULL),((unsigned int)4182453034ULL),((unsigned int)120832402ULL),((unsigned int)765675142ULL),((unsigned int)366068086ULL),((unsigned int)1163426272ULL),((unsigned int)3007216775ULL),((unsigned int)3077220472ULL),((unsigned int)3664182203ULL),((unsigned int)1297572554ULL),((unsigned int)537003049ULL),((unsigned int)3508078208ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 204\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1959216203ULL),((unsigned int)1597479597ULL),((unsigned int)3423287677ULL),((unsigned int)1148213225ULL)};
unsigned int b_0[4]={((unsigned int)1959216203ULL),((unsigned int)1597479597ULL),((unsigned int)3423287677ULL),((unsigned int)1148213225ULL)};
unsigned int a_1[4]={((unsigned int)3999170870ULL),((unsigned int)1268965261ULL),((unsigned int)3388583277ULL),((unsigned int)3958607304ULL)};
unsigned int b_1[4]={((unsigned int)3999170870ULL),((unsigned int)1268965261ULL),((unsigned int)3388583277ULL),((unsigned int)3958607304ULL)};
unsigned int a_2[4]={((unsigned int)2646040377ULL),((unsigned int)2831629546ULL),((unsigned int)2760801380ULL),((unsigned int)2900128818ULL)};
unsigned int b_2[4]={((unsigned int)2646040377ULL),((unsigned int)2831629546ULL),((unsigned int)2760801380ULL),((unsigned int)2900128818ULL)};
unsigned int a_3[4]={((unsigned int)3739030152ULL),((unsigned int)4281463760ULL),((unsigned int)1478791810ULL),((unsigned int)240753103ULL)};
unsigned int b_3[4]={((unsigned int)3739030152ULL),((unsigned int)4281463760ULL),((unsigned int)1478791810ULL),((unsigned int)240753103ULL)};
unsigned int a_4[16]={((unsigned int)303391914ULL),((unsigned int)3847764535ULL),((unsigned int)3752622255ULL),((unsigned int)1674125654ULL),((unsigned int)1018560516ULL),((unsigned int)1859203584ULL),((unsigned int)3978009680ULL),((unsigned int)2034331780ULL),((unsigned int)3421701097ULL),((unsigned int)3768483330ULL),((unsigned int)390647487ULL),((unsigned int)1672793205ULL),((unsigned int)835956124ULL),((unsigned int)3576066515ULL),((unsigned int)541380087ULL),((unsigned int)4095657742ULL)};
unsigned int b_4[16]={((unsigned int)303391914ULL),((unsigned int)3847764535ULL),((unsigned int)3752622255ULL),((unsigned int)1674125654ULL),((unsigned int)1018560516ULL),((unsigned int)1859203584ULL),((unsigned int)3978009680ULL),((unsigned int)2034331780ULL),((unsigned int)3421701097ULL),((unsigned int)3768483330ULL),((unsigned int)390647487ULL),((unsigned int)1672793205ULL),((unsigned int)835956124ULL),((unsigned int)3576066515ULL),((unsigned int)541380087ULL),((unsigned int)4095657742ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 205\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3683491359ULL),((unsigned int)526980449ULL),((unsigned int)3027951336ULL),((unsigned int)3762116887ULL)};
unsigned int b_0[4]={((unsigned int)3683491359ULL),((unsigned int)526980449ULL),((unsigned int)3027951336ULL),((unsigned int)3762116887ULL)};
unsigned int a_1[4]={((unsigned int)882274290ULL),((unsigned int)1359017202ULL),((unsigned int)4174513005ULL),((unsigned int)1924096056ULL)};
unsigned int b_1[4]={((unsigned int)882274290ULL),((unsigned int)1359017202ULL),((unsigned int)4174513005ULL),((unsigned int)1924096056ULL)};
unsigned int a_2[4]={((unsigned int)1388184862ULL),((unsigned int)266302791ULL),((unsigned int)3950494461ULL),((unsigned int)267572410ULL)};
unsigned int b_2[4]={((unsigned int)1388184862ULL),((unsigned int)266302791ULL),((unsigned int)3950494461ULL),((unsigned int)267572410ULL)};
unsigned int a_3[4]={((unsigned int)1445892419ULL),((unsigned int)2618949961ULL),((unsigned int)4183792731ULL),((unsigned int)4232453442ULL)};
unsigned int b_3[4]={((unsigned int)1445892419ULL),((unsigned int)2618949961ULL),((unsigned int)4183792731ULL),((unsigned int)4232453442ULL)};
unsigned int a_4[16]={((unsigned int)2977663331ULL),((unsigned int)1015974216ULL),((unsigned int)291796608ULL),((unsigned int)1427697853ULL),((unsigned int)2395410725ULL),((unsigned int)4035047514ULL),((unsigned int)4157586553ULL),((unsigned int)3725183307ULL),((unsigned int)1724059894ULL),((unsigned int)2541933978ULL),((unsigned int)2144351062ULL),((unsigned int)2378934837ULL),((unsigned int)3222717796ULL),((unsigned int)2804143777ULL),((unsigned int)1293293432ULL),((unsigned int)2267860593ULL)};
unsigned int b_4[16]={((unsigned int)2977663331ULL),((unsigned int)1015974216ULL),((unsigned int)291796608ULL),((unsigned int)1427697853ULL),((unsigned int)2395410725ULL),((unsigned int)4035047514ULL),((unsigned int)4157586553ULL),((unsigned int)3725183307ULL),((unsigned int)1724059894ULL),((unsigned int)2541933978ULL),((unsigned int)2144351062ULL),((unsigned int)2378934837ULL),((unsigned int)3222717796ULL),((unsigned int)2804143777ULL),((unsigned int)1293293432ULL),((unsigned int)2267860593ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 206\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1065630180ULL),((unsigned int)2132561119ULL),((unsigned int)3193500640ULL),((unsigned int)822547177ULL)};
unsigned int b_0[4]={((unsigned int)1065630180ULL),((unsigned int)2132561119ULL),((unsigned int)3193500640ULL),((unsigned int)822547177ULL)};
unsigned int a_1[4]={((unsigned int)189745893ULL),((unsigned int)739790482ULL),((unsigned int)3297480060ULL),((unsigned int)2967645488ULL)};
unsigned int b_1[4]={((unsigned int)189745893ULL),((unsigned int)739790482ULL),((unsigned int)3297480060ULL),((unsigned int)2967645488ULL)};
unsigned int a_2[4]={((unsigned int)855588946ULL),((unsigned int)585315481ULL),((unsigned int)3328918540ULL),((unsigned int)2581850920ULL)};
unsigned int b_2[4]={((unsigned int)855588946ULL),((unsigned int)585315481ULL),((unsigned int)3328918540ULL),((unsigned int)2581850920ULL)};
unsigned int a_3[4]={((unsigned int)2482850329ULL),((unsigned int)3923379445ULL),((unsigned int)2087682345ULL),((unsigned int)1716391944ULL)};
unsigned int b_3[4]={((unsigned int)2482850329ULL),((unsigned int)3923379445ULL),((unsigned int)2087682345ULL),((unsigned int)1716391944ULL)};
unsigned int a_4[16]={((unsigned int)2185851302ULL),((unsigned int)2093580070ULL),((unsigned int)1538357742ULL),((unsigned int)2722854808ULL),((unsigned int)1887377788ULL),((unsigned int)4293486982ULL),((unsigned int)3367688030ULL),((unsigned int)3181705192ULL),((unsigned int)2775184246ULL),((unsigned int)401122333ULL),((unsigned int)4097877520ULL),((unsigned int)3435113313ULL),((unsigned int)3608209385ULL),((unsigned int)3938166567ULL),((unsigned int)3523929189ULL),((unsigned int)3846565009ULL)};
unsigned int b_4[16]={((unsigned int)2185851302ULL),((unsigned int)2093580070ULL),((unsigned int)1538357742ULL),((unsigned int)2722854808ULL),((unsigned int)1887377788ULL),((unsigned int)4293486982ULL),((unsigned int)3367688030ULL),((unsigned int)3181705192ULL),((unsigned int)2775184246ULL),((unsigned int)401122333ULL),((unsigned int)4097877520ULL),((unsigned int)3435113313ULL),((unsigned int)3608209385ULL),((unsigned int)3938166567ULL),((unsigned int)3523929189ULL),((unsigned int)3846565009ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 207\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2614409049ULL),((unsigned int)2091565606ULL),((unsigned int)3665292823ULL),((unsigned int)4068934896ULL)};
unsigned int b_0[4]={((unsigned int)2614409049ULL),((unsigned int)2091565606ULL),((unsigned int)3665292823ULL),((unsigned int)4068934896ULL)};
unsigned int a_1[4]={((unsigned int)2381424034ULL),((unsigned int)1330872552ULL),((unsigned int)425797155ULL),((unsigned int)1227109547ULL)};
unsigned int b_1[4]={((unsigned int)2381424034ULL),((unsigned int)1330872552ULL),((unsigned int)425797155ULL),((unsigned int)1227109547ULL)};
unsigned int a_2[4]={((unsigned int)400412101ULL),((unsigned int)1294477845ULL),((unsigned int)3622410102ULL),((unsigned int)3943779736ULL)};
unsigned int b_2[4]={((unsigned int)400412101ULL),((unsigned int)1294477845ULL),((unsigned int)3622410102ULL),((unsigned int)3943779736ULL)};
unsigned int a_3[4]={((unsigned int)1502765217ULL),((unsigned int)1887058935ULL),((unsigned int)870841371ULL),((unsigned int)1537459941ULL)};
unsigned int b_3[4]={((unsigned int)1502765217ULL),((unsigned int)1887058935ULL),((unsigned int)870841371ULL),((unsigned int)1537459941ULL)};
unsigned int a_4[16]={((unsigned int)3477131178ULL),((unsigned int)937897882ULL),((unsigned int)1301015345ULL),((unsigned int)3072123456ULL),((unsigned int)110849517ULL),((unsigned int)2053804505ULL),((unsigned int)3340566196ULL),((unsigned int)605072309ULL),((unsigned int)2640459363ULL),((unsigned int)4248548939ULL),((unsigned int)1681054961ULL),((unsigned int)2200126626ULL),((unsigned int)35524879ULL),((unsigned int)3426582248ULL),((unsigned int)255435792ULL),((unsigned int)415908928ULL)};
unsigned int b_4[16]={((unsigned int)3477131178ULL),((unsigned int)937897882ULL),((unsigned int)1301015345ULL),((unsigned int)3072123456ULL),((unsigned int)110849517ULL),((unsigned int)2053804505ULL),((unsigned int)3340566196ULL),((unsigned int)605072309ULL),((unsigned int)2640459363ULL),((unsigned int)4248548939ULL),((unsigned int)1681054961ULL),((unsigned int)2200126626ULL),((unsigned int)35524879ULL),((unsigned int)3426582248ULL),((unsigned int)255435792ULL),((unsigned int)415908928ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 208\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)590180491ULL),((unsigned int)3073107586ULL),((unsigned int)3783033615ULL),((unsigned int)1709119842ULL)};
unsigned int b_0[4]={((unsigned int)590180491ULL),((unsigned int)3073107586ULL),((unsigned int)3783033615ULL),((unsigned int)1709119842ULL)};
unsigned int a_1[4]={((unsigned int)3975685767ULL),((unsigned int)3947479117ULL),((unsigned int)2546805262ULL),((unsigned int)1738853001ULL)};
unsigned int b_1[4]={((unsigned int)3975685767ULL),((unsigned int)3947479117ULL),((unsigned int)2546805262ULL),((unsigned int)1738853001ULL)};
unsigned int a_2[4]={((unsigned int)592174406ULL),((unsigned int)3720081080ULL),((unsigned int)967581451ULL),((unsigned int)1015285739ULL)};
unsigned int b_2[4]={((unsigned int)592174406ULL),((unsigned int)3720081080ULL),((unsigned int)967581451ULL),((unsigned int)1015285739ULL)};
unsigned int a_3[4]={((unsigned int)4134985737ULL),((unsigned int)4035464930ULL),((unsigned int)4188694877ULL),((unsigned int)491118165ULL)};
unsigned int b_3[4]={((unsigned int)4134985737ULL),((unsigned int)4035464930ULL),((unsigned int)4188694877ULL),((unsigned int)491118165ULL)};
unsigned int a_4[16]={((unsigned int)2730516497ULL),((unsigned int)3395292896ULL),((unsigned int)2074449916ULL),((unsigned int)2851770942ULL),((unsigned int)2961727268ULL),((unsigned int)1838923359ULL),((unsigned int)3680224688ULL),((unsigned int)4086418902ULL),((unsigned int)1883459051ULL),((unsigned int)93060679ULL),((unsigned int)2010727328ULL),((unsigned int)641896309ULL),((unsigned int)658861091ULL),((unsigned int)2962935819ULL),((unsigned int)804202210ULL),((unsigned int)3343567620ULL)};
unsigned int b_4[16]={((unsigned int)2730516497ULL),((unsigned int)3395292896ULL),((unsigned int)2074449916ULL),((unsigned int)2851770942ULL),((unsigned int)2961727268ULL),((unsigned int)1838923359ULL),((unsigned int)3680224688ULL),((unsigned int)4086418902ULL),((unsigned int)1883459051ULL),((unsigned int)93060679ULL),((unsigned int)2010727328ULL),((unsigned int)641896309ULL),((unsigned int)658861091ULL),((unsigned int)2962935819ULL),((unsigned int)804202210ULL),((unsigned int)3343567620ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 209\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2410225221ULL),((unsigned int)4089935636ULL),((unsigned int)582403468ULL),((unsigned int)1894883292ULL)};
unsigned int b_0[4]={((unsigned int)2410225221ULL),((unsigned int)4089935636ULL),((unsigned int)582403468ULL),((unsigned int)1894883292ULL)};
unsigned int a_1[4]={((unsigned int)3904815630ULL),((unsigned int)1042566845ULL),((unsigned int)3526713587ULL),((unsigned int)3575976197ULL)};
unsigned int b_1[4]={((unsigned int)3904815630ULL),((unsigned int)1042566845ULL),((unsigned int)3526713587ULL),((unsigned int)3575976197ULL)};
unsigned int a_2[4]={((unsigned int)3743830957ULL),((unsigned int)602703353ULL),((unsigned int)2786321810ULL),((unsigned int)872563726ULL)};
unsigned int b_2[4]={((unsigned int)3743830957ULL),((unsigned int)602703353ULL),((unsigned int)2786321810ULL),((unsigned int)872563726ULL)};
unsigned int a_3[4]={((unsigned int)2298936325ULL),((unsigned int)3282294900ULL),((unsigned int)2619775616ULL),((unsigned int)1149922451ULL)};
unsigned int b_3[4]={((unsigned int)2298936325ULL),((unsigned int)3282294900ULL),((unsigned int)2619775616ULL),((unsigned int)1149922451ULL)};
unsigned int a_4[16]={((unsigned int)991075136ULL),((unsigned int)3041458384ULL),((unsigned int)899995946ULL),((unsigned int)1269908078ULL),((unsigned int)3692432442ULL),((unsigned int)1861801488ULL),((unsigned int)1388338245ULL),((unsigned int)1321101105ULL),((unsigned int)2519525753ULL),((unsigned int)1386021506ULL),((unsigned int)1812640039ULL),((unsigned int)3285255544ULL),((unsigned int)1479572364ULL),((unsigned int)2511593960ULL),((unsigned int)2342142019ULL),((unsigned int)3356973667ULL)};
unsigned int b_4[16]={((unsigned int)991075136ULL),((unsigned int)3041458384ULL),((unsigned int)899995946ULL),((unsigned int)1269908078ULL),((unsigned int)3692432442ULL),((unsigned int)1861801488ULL),((unsigned int)1388338245ULL),((unsigned int)1321101105ULL),((unsigned int)2519525753ULL),((unsigned int)1386021506ULL),((unsigned int)1812640039ULL),((unsigned int)3285255544ULL),((unsigned int)1479572364ULL),((unsigned int)2511593960ULL),((unsigned int)2342142019ULL),((unsigned int)3356973667ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 210\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2168009597ULL),((unsigned int)1353753350ULL),((unsigned int)1857149439ULL),((unsigned int)235013683ULL)};
unsigned int b_0[4]={((unsigned int)2168009597ULL),((unsigned int)1353753350ULL),((unsigned int)1857149439ULL),((unsigned int)235013683ULL)};
unsigned int a_1[4]={((unsigned int)1369083396ULL),((unsigned int)3955833191ULL),((unsigned int)1957947751ULL),((unsigned int)2573220365ULL)};
unsigned int b_1[4]={((unsigned int)1369083396ULL),((unsigned int)3955833191ULL),((unsigned int)1957947751ULL),((unsigned int)2573220365ULL)};
unsigned int a_2[4]={((unsigned int)1896270160ULL),((unsigned int)4117956084ULL),((unsigned int)2932611954ULL),((unsigned int)2704723700ULL)};
unsigned int b_2[4]={((unsigned int)1896270160ULL),((unsigned int)4117956084ULL),((unsigned int)2932611954ULL),((unsigned int)2704723700ULL)};
unsigned int a_3[4]={((unsigned int)3388967637ULL),((unsigned int)781515890ULL),((unsigned int)1183489754ULL),((unsigned int)2402580320ULL)};
unsigned int b_3[4]={((unsigned int)3388967637ULL),((unsigned int)781515890ULL),((unsigned int)1183489754ULL),((unsigned int)2402580320ULL)};
unsigned int a_4[16]={((unsigned int)446997376ULL),((unsigned int)2026092360ULL),((unsigned int)160016793ULL),((unsigned int)132625294ULL),((unsigned int)2354089745ULL),((unsigned int)586551452ULL),((unsigned int)3830443889ULL),((unsigned int)3641805973ULL),((unsigned int)1269322978ULL),((unsigned int)3037887875ULL),((unsigned int)3041473466ULL),((unsigned int)1870514894ULL),((unsigned int)2826268204ULL),((unsigned int)2004419050ULL),((unsigned int)3837446681ULL),((unsigned int)1558344338ULL)};
unsigned int b_4[16]={((unsigned int)446997376ULL),((unsigned int)2026092360ULL),((unsigned int)160016793ULL),((unsigned int)132625294ULL),((unsigned int)2354089745ULL),((unsigned int)586551452ULL),((unsigned int)3830443889ULL),((unsigned int)3641805973ULL),((unsigned int)1269322978ULL),((unsigned int)3037887875ULL),((unsigned int)3041473466ULL),((unsigned int)1870514894ULL),((unsigned int)2826268204ULL),((unsigned int)2004419050ULL),((unsigned int)3837446681ULL),((unsigned int)1558344338ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 211\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)934131050ULL),((unsigned int)3746152633ULL),((unsigned int)1566000422ULL),((unsigned int)1662411945ULL)};
unsigned int b_0[4]={((unsigned int)934131050ULL),((unsigned int)3746152633ULL),((unsigned int)1566000422ULL),((unsigned int)1662411945ULL)};
unsigned int a_1[4]={((unsigned int)3835152113ULL),((unsigned int)482295930ULL),((unsigned int)1988554071ULL),((unsigned int)4192930105ULL)};
unsigned int b_1[4]={((unsigned int)3835152113ULL),((unsigned int)482295930ULL),((unsigned int)1988554071ULL),((unsigned int)4192930105ULL)};
unsigned int a_2[4]={((unsigned int)3628469658ULL),((unsigned int)2666633341ULL),((unsigned int)2548395321ULL),((unsigned int)3800399954ULL)};
unsigned int b_2[4]={((unsigned int)3628469658ULL),((unsigned int)2666633341ULL),((unsigned int)2548395321ULL),((unsigned int)3800399954ULL)};
unsigned int a_3[4]={((unsigned int)2331585842ULL),((unsigned int)1715188188ULL),((unsigned int)4091887771ULL),((unsigned int)2752798014ULL)};
unsigned int b_3[4]={((unsigned int)2331585842ULL),((unsigned int)1715188188ULL),((unsigned int)4091887771ULL),((unsigned int)2752798014ULL)};
unsigned int a_4[16]={((unsigned int)495831983ULL),((unsigned int)4191987499ULL),((unsigned int)2449716212ULL),((unsigned int)2996666278ULL),((unsigned int)4193445312ULL),((unsigned int)677213517ULL),((unsigned int)3854168219ULL),((unsigned int)2699932010ULL),((unsigned int)1424188708ULL),((unsigned int)1589771227ULL),((unsigned int)3655509739ULL),((unsigned int)3955551198ULL),((unsigned int)771794656ULL),((unsigned int)1397032131ULL),((unsigned int)1474397124ULL),((unsigned int)832317473ULL)};
unsigned int b_4[16]={((unsigned int)495831983ULL),((unsigned int)4191987499ULL),((unsigned int)2449716212ULL),((unsigned int)2996666278ULL),((unsigned int)4193445312ULL),((unsigned int)677213517ULL),((unsigned int)3854168219ULL),((unsigned int)2699932010ULL),((unsigned int)1424188708ULL),((unsigned int)1589771227ULL),((unsigned int)3655509739ULL),((unsigned int)3955551198ULL),((unsigned int)771794656ULL),((unsigned int)1397032131ULL),((unsigned int)1474397124ULL),((unsigned int)832317473ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 212\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2391512497ULL),((unsigned int)3710309531ULL),((unsigned int)1658601330ULL),((unsigned int)252216220ULL)};
unsigned int b_0[4]={((unsigned int)2391512497ULL),((unsigned int)3710309531ULL),((unsigned int)1658601330ULL),((unsigned int)252216220ULL)};
unsigned int a_1[4]={((unsigned int)873534450ULL),((unsigned int)954117266ULL),((unsigned int)2090230580ULL),((unsigned int)1550893094ULL)};
unsigned int b_1[4]={((unsigned int)873534450ULL),((unsigned int)954117266ULL),((unsigned int)2090230580ULL),((unsigned int)1550893094ULL)};
unsigned int a_2[4]={((unsigned int)1723211806ULL),((unsigned int)1443054486ULL),((unsigned int)1445548796ULL),((unsigned int)759670132ULL)};
unsigned int b_2[4]={((unsigned int)1723211806ULL),((unsigned int)1443054486ULL),((unsigned int)1445548796ULL),((unsigned int)759670132ULL)};
unsigned int a_3[4]={((unsigned int)213949194ULL),((unsigned int)3912212433ULL),((unsigned int)2948155221ULL),((unsigned int)2163166664ULL)};
unsigned int b_3[4]={((unsigned int)213949194ULL),((unsigned int)3912212433ULL),((unsigned int)2948155221ULL),((unsigned int)2163166664ULL)};
unsigned int a_4[16]={((unsigned int)2576249592ULL),((unsigned int)1446322552ULL),((unsigned int)386350706ULL),((unsigned int)3092473391ULL),((unsigned int)2844369916ULL),((unsigned int)3460575325ULL),((unsigned int)1268282979ULL),((unsigned int)3125079427ULL),((unsigned int)3740577181ULL),((unsigned int)2887850793ULL),((unsigned int)3297940952ULL),((unsigned int)697180883ULL),((unsigned int)3694795702ULL),((unsigned int)1080425746ULL),((unsigned int)4212190898ULL),((unsigned int)1305363576ULL)};
unsigned int b_4[16]={((unsigned int)2576249592ULL),((unsigned int)1446322552ULL),((unsigned int)386350706ULL),((unsigned int)3092473391ULL),((unsigned int)2844369916ULL),((unsigned int)3460575325ULL),((unsigned int)1268282979ULL),((unsigned int)3125079427ULL),((unsigned int)3740577181ULL),((unsigned int)2887850793ULL),((unsigned int)3297940952ULL),((unsigned int)697180883ULL),((unsigned int)3694795702ULL),((unsigned int)1080425746ULL),((unsigned int)4212190898ULL),((unsigned int)1305363576ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 213\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1218986115ULL),((unsigned int)2666876507ULL),((unsigned int)2147271302ULL),((unsigned int)3110677982ULL)};
unsigned int b_0[4]={((unsigned int)1218986115ULL),((unsigned int)2666876507ULL),((unsigned int)2147271302ULL),((unsigned int)3110677982ULL)};
unsigned int a_1[4]={((unsigned int)243648175ULL),((unsigned int)1439763098ULL),((unsigned int)3782321471ULL),((unsigned int)3288646991ULL)};
unsigned int b_1[4]={((unsigned int)243648175ULL),((unsigned int)1439763098ULL),((unsigned int)3782321471ULL),((unsigned int)3288646991ULL)};
unsigned int a_2[4]={((unsigned int)2326594217ULL),((unsigned int)3267699997ULL),((unsigned int)1796240471ULL),((unsigned int)1049973938ULL)};
unsigned int b_2[4]={((unsigned int)2326594217ULL),((unsigned int)3267699997ULL),((unsigned int)1796240471ULL),((unsigned int)1049973938ULL)};
unsigned int a_3[4]={((unsigned int)2644613641ULL),((unsigned int)707862709ULL),((unsigned int)903112666ULL),((unsigned int)2543019481ULL)};
unsigned int b_3[4]={((unsigned int)2644613641ULL),((unsigned int)707862709ULL),((unsigned int)903112666ULL),((unsigned int)2543019481ULL)};
unsigned int a_4[16]={((unsigned int)3710751583ULL),((unsigned int)3993204394ULL),((unsigned int)2169812768ULL),((unsigned int)336117991ULL),((unsigned int)1077292347ULL),((unsigned int)338409867ULL),((unsigned int)995422420ULL),((unsigned int)2185251388ULL),((unsigned int)1210980324ULL),((unsigned int)3706007963ULL),((unsigned int)1826080937ULL),((unsigned int)1972766813ULL),((unsigned int)3030364743ULL),((unsigned int)3060191885ULL),((unsigned int)3802298013ULL),((unsigned int)1120808911ULL)};
unsigned int b_4[16]={((unsigned int)3710751583ULL),((unsigned int)3993204394ULL),((unsigned int)2169812768ULL),((unsigned int)336117991ULL),((unsigned int)1077292347ULL),((unsigned int)338409867ULL),((unsigned int)995422420ULL),((unsigned int)2185251388ULL),((unsigned int)1210980324ULL),((unsigned int)3706007963ULL),((unsigned int)1826080937ULL),((unsigned int)1972766813ULL),((unsigned int)3030364743ULL),((unsigned int)3060191885ULL),((unsigned int)3802298013ULL),((unsigned int)1120808911ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 214\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3850394795ULL),((unsigned int)974233962ULL),((unsigned int)2931146447ULL),((unsigned int)403367966ULL)};
unsigned int b_0[4]={((unsigned int)3850394795ULL),((unsigned int)974233962ULL),((unsigned int)2931146447ULL),((unsigned int)403367966ULL)};
unsigned int a_1[4]={((unsigned int)2801504017ULL),((unsigned int)3498636869ULL),((unsigned int)2986836780ULL),((unsigned int)2934488872ULL)};
unsigned int b_1[4]={((unsigned int)2801504017ULL),((unsigned int)3498636869ULL),((unsigned int)2986836780ULL),((unsigned int)2934488872ULL)};
unsigned int a_2[4]={((unsigned int)2367397451ULL),((unsigned int)2628994235ULL),((unsigned int)2922155025ULL),((unsigned int)3871335887ULL)};
unsigned int b_2[4]={((unsigned int)2367397451ULL),((unsigned int)2628994235ULL),((unsigned int)2922155025ULL),((unsigned int)3871335887ULL)};
unsigned int a_3[4]={((unsigned int)1163267423ULL),((unsigned int)979825752ULL),((unsigned int)1180074471ULL),((unsigned int)2576861239ULL)};
unsigned int b_3[4]={((unsigned int)1163267423ULL),((unsigned int)979825752ULL),((unsigned int)1180074471ULL),((unsigned int)2576861239ULL)};
unsigned int a_4[16]={((unsigned int)1975013647ULL),((unsigned int)526558844ULL),((unsigned int)3309099849ULL),((unsigned int)2314595976ULL),((unsigned int)2810099322ULL),((unsigned int)929274982ULL),((unsigned int)3576489956ULL),((unsigned int)4151274123ULL),((unsigned int)3447207565ULL),((unsigned int)1433736407ULL),((unsigned int)791384752ULL),((unsigned int)2320028774ULL),((unsigned int)1105591026ULL),((unsigned int)3315367492ULL),((unsigned int)1736114870ULL),((unsigned int)1238064799ULL)};
unsigned int b_4[16]={((unsigned int)1975013647ULL),((unsigned int)526558844ULL),((unsigned int)3309099849ULL),((unsigned int)2314595976ULL),((unsigned int)2810099322ULL),((unsigned int)929274982ULL),((unsigned int)3576489956ULL),((unsigned int)4151274123ULL),((unsigned int)3447207565ULL),((unsigned int)1433736407ULL),((unsigned int)791384752ULL),((unsigned int)2320028774ULL),((unsigned int)1105591026ULL),((unsigned int)3315367492ULL),((unsigned int)1736114870ULL),((unsigned int)1238064799ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 215\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3739088626ULL),((unsigned int)22272645ULL),((unsigned int)1937963022ULL),((unsigned int)4287911401ULL)};
unsigned int b_0[4]={((unsigned int)3739088626ULL),((unsigned int)22272645ULL),((unsigned int)1937963022ULL),((unsigned int)4287911401ULL)};
unsigned int a_1[4]={((unsigned int)3850237643ULL),((unsigned int)737471667ULL),((unsigned int)3243137612ULL),((unsigned int)3865706011ULL)};
unsigned int b_1[4]={((unsigned int)3850237643ULL),((unsigned int)737471667ULL),((unsigned int)3243137612ULL),((unsigned int)3865706011ULL)};
unsigned int a_2[4]={((unsigned int)2746714780ULL),((unsigned int)1119047257ULL),((unsigned int)2289593530ULL),((unsigned int)3705293610ULL)};
unsigned int b_2[4]={((unsigned int)2746714780ULL),((unsigned int)1119047257ULL),((unsigned int)2289593530ULL),((unsigned int)3705293610ULL)};
unsigned int a_3[4]={((unsigned int)2203956259ULL),((unsigned int)1191613197ULL),((unsigned int)3693345885ULL),((unsigned int)4103652385ULL)};
unsigned int b_3[4]={((unsigned int)2203956259ULL),((unsigned int)1191613197ULL),((unsigned int)3693345885ULL),((unsigned int)4103652385ULL)};
unsigned int a_4[16]={((unsigned int)881976023ULL),((unsigned int)1516707706ULL),((unsigned int)460033242ULL),((unsigned int)3135741537ULL),((unsigned int)1927401999ULL),((unsigned int)916679479ULL),((unsigned int)2165370038ULL),((unsigned int)2066431724ULL),((unsigned int)1773660771ULL),((unsigned int)856447071ULL),((unsigned int)770482779ULL),((unsigned int)3650744670ULL),((unsigned int)2228847775ULL),((unsigned int)1619877228ULL),((unsigned int)3147415321ULL),((unsigned int)3129527647ULL)};
unsigned int b_4[16]={((unsigned int)881976023ULL),((unsigned int)1516707706ULL),((unsigned int)460033242ULL),((unsigned int)3135741537ULL),((unsigned int)1927401999ULL),((unsigned int)916679479ULL),((unsigned int)2165370038ULL),((unsigned int)2066431724ULL),((unsigned int)1773660771ULL),((unsigned int)856447071ULL),((unsigned int)770482779ULL),((unsigned int)3650744670ULL),((unsigned int)2228847775ULL),((unsigned int)1619877228ULL),((unsigned int)3147415321ULL),((unsigned int)3129527647ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 216\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)4026550368ULL),((unsigned int)476906531ULL),((unsigned int)2734299260ULL),((unsigned int)866388770ULL)};
unsigned int b_0[4]={((unsigned int)4026550368ULL),((unsigned int)476906531ULL),((unsigned int)2734299260ULL),((unsigned int)866388770ULL)};
unsigned int a_1[4]={((unsigned int)373253805ULL),((unsigned int)567578701ULL),((unsigned int)2099682644ULL),((unsigned int)3345150997ULL)};
unsigned int b_1[4]={((unsigned int)373253805ULL),((unsigned int)567578701ULL),((unsigned int)2099682644ULL),((unsigned int)3345150997ULL)};
unsigned int a_2[4]={((unsigned int)61489754ULL),((unsigned int)261521383ULL),((unsigned int)3630715154ULL),((unsigned int)2032764667ULL)};
unsigned int b_2[4]={((unsigned int)61489754ULL),((unsigned int)261521383ULL),((unsigned int)3630715154ULL),((unsigned int)2032764667ULL)};
unsigned int a_3[4]={((unsigned int)1710881072ULL),((unsigned int)1051591966ULL),((unsigned int)416499611ULL),((unsigned int)3989913509ULL)};
unsigned int b_3[4]={((unsigned int)1710881072ULL),((unsigned int)1051591966ULL),((unsigned int)416499611ULL),((unsigned int)3989913509ULL)};
unsigned int a_4[16]={((unsigned int)3274233705ULL),((unsigned int)321580135ULL),((unsigned int)1529668785ULL),((unsigned int)3602629921ULL),((unsigned int)1635292879ULL),((unsigned int)2635270626ULL),((unsigned int)623903923ULL),((unsigned int)1082097684ULL),((unsigned int)3311601429ULL),((unsigned int)454054837ULL),((unsigned int)1159929037ULL),((unsigned int)1505294778ULL),((unsigned int)2045307218ULL),((unsigned int)4131052892ULL),((unsigned int)2972580373ULL),((unsigned int)3924799994ULL)};
unsigned int b_4[16]={((unsigned int)3274233705ULL),((unsigned int)321580135ULL),((unsigned int)1529668785ULL),((unsigned int)3602629921ULL),((unsigned int)1635292879ULL),((unsigned int)2635270626ULL),((unsigned int)623903923ULL),((unsigned int)1082097684ULL),((unsigned int)3311601429ULL),((unsigned int)454054837ULL),((unsigned int)1159929037ULL),((unsigned int)1505294778ULL),((unsigned int)2045307218ULL),((unsigned int)4131052892ULL),((unsigned int)2972580373ULL),((unsigned int)3924799994ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 217\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)904633268ULL),((unsigned int)2597375502ULL),((unsigned int)2109503871ULL),((unsigned int)914799536ULL)};
unsigned int b_0[4]={((unsigned int)904633268ULL),((unsigned int)2597375502ULL),((unsigned int)2109503871ULL),((unsigned int)914799536ULL)};
unsigned int a_1[4]={((unsigned int)923094664ULL),((unsigned int)2904551927ULL),((unsigned int)1097864471ULL),((unsigned int)1326059771ULL)};
unsigned int b_1[4]={((unsigned int)923094664ULL),((unsigned int)2904551927ULL),((unsigned int)1097864471ULL),((unsigned int)1326059771ULL)};
unsigned int a_2[4]={((unsigned int)632542993ULL),((unsigned int)1961466418ULL),((unsigned int)1784330663ULL),((unsigned int)3511710145ULL)};
unsigned int b_2[4]={((unsigned int)632542993ULL),((unsigned int)1961466418ULL),((unsigned int)1784330663ULL),((unsigned int)3511710145ULL)};
unsigned int a_3[4]={((unsigned int)2736885847ULL),((unsigned int)239700957ULL),((unsigned int)3720185637ULL),((unsigned int)2582434801ULL)};
unsigned int b_3[4]={((unsigned int)2736885847ULL),((unsigned int)239700957ULL),((unsigned int)3720185637ULL),((unsigned int)2582434801ULL)};
unsigned int a_4[16]={((unsigned int)1038964235ULL),((unsigned int)2682031137ULL),((unsigned int)1165604215ULL),((unsigned int)2968437741ULL),((unsigned int)3759887457ULL),((unsigned int)3113860565ULL),((unsigned int)1281920968ULL),((unsigned int)3886301674ULL),((unsigned int)3317552964ULL),((unsigned int)3766947248ULL),((unsigned int)486149993ULL),((unsigned int)989207318ULL),((unsigned int)4191580252ULL),((unsigned int)230491302ULL),((unsigned int)2575015715ULL),((unsigned int)3424846117ULL)};
unsigned int b_4[16]={((unsigned int)1038964235ULL),((unsigned int)2682031137ULL),((unsigned int)1165604215ULL),((unsigned int)2968437741ULL),((unsigned int)3759887457ULL),((unsigned int)3113860565ULL),((unsigned int)1281920968ULL),((unsigned int)3886301674ULL),((unsigned int)3317552964ULL),((unsigned int)3766947248ULL),((unsigned int)486149993ULL),((unsigned int)989207318ULL),((unsigned int)4191580252ULL),((unsigned int)230491302ULL),((unsigned int)2575015715ULL),((unsigned int)3424846117ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 218\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1744821849ULL),((unsigned int)4220809813ULL),((unsigned int)1381725270ULL),((unsigned int)1027298576ULL)};
unsigned int b_0[4]={((unsigned int)1744821849ULL),((unsigned int)4220809813ULL),((unsigned int)1381725270ULL),((unsigned int)1027298576ULL)};
unsigned int a_1[4]={((unsigned int)82116856ULL),((unsigned int)287743045ULL),((unsigned int)1820899540ULL),((unsigned int)3076123207ULL)};
unsigned int b_1[4]={((unsigned int)82116856ULL),((unsigned int)287743045ULL),((unsigned int)1820899540ULL),((unsigned int)3076123207ULL)};
unsigned int a_2[4]={((unsigned int)3443240752ULL),((unsigned int)851788080ULL),((unsigned int)762758345ULL),((unsigned int)4112794326ULL)};
unsigned int b_2[4]={((unsigned int)3443240752ULL),((unsigned int)851788080ULL),((unsigned int)762758345ULL),((unsigned int)4112794326ULL)};
unsigned int a_3[4]={((unsigned int)2893337520ULL),((unsigned int)1343910073ULL),((unsigned int)3428990147ULL),((unsigned int)140765685ULL)};
unsigned int b_3[4]={((unsigned int)2893337520ULL),((unsigned int)1343910073ULL),((unsigned int)3428990147ULL),((unsigned int)140765685ULL)};
unsigned int a_4[16]={((unsigned int)3378141167ULL),((unsigned int)872645447ULL),((unsigned int)1155229687ULL),((unsigned int)951656628ULL),((unsigned int)89712369ULL),((unsigned int)936747288ULL),((unsigned int)988508023ULL),((unsigned int)3372039993ULL),((unsigned int)1303881925ULL),((unsigned int)917648750ULL),((unsigned int)965767710ULL),((unsigned int)231556194ULL),((unsigned int)326989414ULL),((unsigned int)117758915ULL),((unsigned int)3736430997ULL),((unsigned int)247860777ULL)};
unsigned int b_4[16]={((unsigned int)3378141167ULL),((unsigned int)872645447ULL),((unsigned int)1155229687ULL),((unsigned int)951656628ULL),((unsigned int)89712369ULL),((unsigned int)936747288ULL),((unsigned int)988508023ULL),((unsigned int)3372039993ULL),((unsigned int)1303881925ULL),((unsigned int)917648750ULL),((unsigned int)965767710ULL),((unsigned int)231556194ULL),((unsigned int)326989414ULL),((unsigned int)117758915ULL),((unsigned int)3736430997ULL),((unsigned int)247860777ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 219\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3625622019ULL),((unsigned int)4106920299ULL),((unsigned int)165261065ULL),((unsigned int)527706347ULL)};
unsigned int b_0[4]={((unsigned int)3625622019ULL),((unsigned int)4106920299ULL),((unsigned int)165261065ULL),((unsigned int)527706347ULL)};
unsigned int a_1[4]={((unsigned int)2571046836ULL),((unsigned int)2532498628ULL),((unsigned int)2099584624ULL),((unsigned int)986128128ULL)};
unsigned int b_1[4]={((unsigned int)2571046836ULL),((unsigned int)2532498628ULL),((unsigned int)2099584624ULL),((unsigned int)986128128ULL)};
unsigned int a_2[4]={((unsigned int)509009296ULL),((unsigned int)2546253099ULL),((unsigned int)1174415880ULL),((unsigned int)614999227ULL)};
unsigned int b_2[4]={((unsigned int)509009296ULL),((unsigned int)2546253099ULL),((unsigned int)1174415880ULL),((unsigned int)614999227ULL)};
unsigned int a_3[4]={((unsigned int)510698411ULL),((unsigned int)3824605863ULL),((unsigned int)2177012280ULL),((unsigned int)1478257735ULL)};
unsigned int b_3[4]={((unsigned int)510698411ULL),((unsigned int)3824605863ULL),((unsigned int)2177012280ULL),((unsigned int)1478257735ULL)};
unsigned int a_4[16]={((unsigned int)1731024851ULL),((unsigned int)3212576252ULL),((unsigned int)114204033ULL),((unsigned int)74005713ULL),((unsigned int)3578188756ULL),((unsigned int)4018572904ULL),((unsigned int)880076582ULL),((unsigned int)2853710307ULL),((unsigned int)2604007739ULL),((unsigned int)1900058219ULL),((unsigned int)2172261572ULL),((unsigned int)256204269ULL),((unsigned int)3004459165ULL),((unsigned int)1278188386ULL),((unsigned int)173602396ULL),((unsigned int)209558933ULL)};
unsigned int b_4[16]={((unsigned int)1731024851ULL),((unsigned int)3212576252ULL),((unsigned int)114204033ULL),((unsigned int)74005713ULL),((unsigned int)3578188756ULL),((unsigned int)4018572904ULL),((unsigned int)880076582ULL),((unsigned int)2853710307ULL),((unsigned int)2604007739ULL),((unsigned int)1900058219ULL),((unsigned int)2172261572ULL),((unsigned int)256204269ULL),((unsigned int)3004459165ULL),((unsigned int)1278188386ULL),((unsigned int)173602396ULL),((unsigned int)209558933ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 220\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)577679607ULL),((unsigned int)251718449ULL),((unsigned int)1717666277ULL),((unsigned int)2100930822ULL)};
unsigned int b_0[4]={((unsigned int)577679607ULL),((unsigned int)251718449ULL),((unsigned int)1717666277ULL),((unsigned int)2100930822ULL)};
unsigned int a_1[4]={((unsigned int)2729040026ULL),((unsigned int)3344592315ULL),((unsigned int)1984311246ULL),((unsigned int)1141172613ULL)};
unsigned int b_1[4]={((unsigned int)2729040026ULL),((unsigned int)3344592315ULL),((unsigned int)1984311246ULL),((unsigned int)1141172613ULL)};
unsigned int a_2[4]={((unsigned int)2831585632ULL),((unsigned int)1095130698ULL),((unsigned int)161738656ULL),((unsigned int)4152188083ULL)};
unsigned int b_2[4]={((unsigned int)2831585632ULL),((unsigned int)1095130698ULL),((unsigned int)161738656ULL),((unsigned int)4152188083ULL)};
unsigned int a_3[4]={((unsigned int)3446924994ULL),((unsigned int)2477125228ULL),((unsigned int)767295801ULL),((unsigned int)3060453192ULL)};
unsigned int b_3[4]={((unsigned int)3446924994ULL),((unsigned int)2477125228ULL),((unsigned int)767295801ULL),((unsigned int)3060453192ULL)};
unsigned int a_4[16]={((unsigned int)267979896ULL),((unsigned int)911112818ULL),((unsigned int)3877975645ULL),((unsigned int)2303164049ULL),((unsigned int)635703375ULL),((unsigned int)3319800120ULL),((unsigned int)2667030346ULL),((unsigned int)2978610825ULL),((unsigned int)4116177581ULL),((unsigned int)2381970952ULL),((unsigned int)930520099ULL),((unsigned int)1212483347ULL),((unsigned int)2748264994ULL),((unsigned int)3129844154ULL),((unsigned int)835510977ULL),((unsigned int)3738970382ULL)};
unsigned int b_4[16]={((unsigned int)267979896ULL),((unsigned int)911112818ULL),((unsigned int)3877975645ULL),((unsigned int)2303164049ULL),((unsigned int)635703375ULL),((unsigned int)3319800120ULL),((unsigned int)2667030346ULL),((unsigned int)2978610825ULL),((unsigned int)4116177581ULL),((unsigned int)2381970952ULL),((unsigned int)930520099ULL),((unsigned int)1212483347ULL),((unsigned int)2748264994ULL),((unsigned int)3129844154ULL),((unsigned int)835510977ULL),((unsigned int)3738970382ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 221\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3525745613ULL),((unsigned int)4183987466ULL),((unsigned int)2815104938ULL),((unsigned int)474986532ULL)};
unsigned int b_0[4]={((unsigned int)3525745613ULL),((unsigned int)4183987466ULL),((unsigned int)2815104938ULL),((unsigned int)474986532ULL)};
unsigned int a_1[4]={((unsigned int)3037492537ULL),((unsigned int)3636171681ULL),((unsigned int)1789798300ULL),((unsigned int)814324277ULL)};
unsigned int b_1[4]={((unsigned int)3037492537ULL),((unsigned int)3636171681ULL),((unsigned int)1789798300ULL),((unsigned int)814324277ULL)};
unsigned int a_2[4]={((unsigned int)547524661ULL),((unsigned int)1528875852ULL),((unsigned int)1322402403ULL),((unsigned int)3502314817ULL)};
unsigned int b_2[4]={((unsigned int)547524661ULL),((unsigned int)1528875852ULL),((unsigned int)1322402403ULL),((unsigned int)3502314817ULL)};
unsigned int a_3[4]={((unsigned int)3823036005ULL),((unsigned int)1305211599ULL),((unsigned int)3420663382ULL),((unsigned int)370812620ULL)};
unsigned int b_3[4]={((unsigned int)3823036005ULL),((unsigned int)1305211599ULL),((unsigned int)3420663382ULL),((unsigned int)370812620ULL)};
unsigned int a_4[16]={((unsigned int)3128845272ULL),((unsigned int)2492659171ULL),((unsigned int)2223177931ULL),((unsigned int)2418929748ULL),((unsigned int)805541940ULL),((unsigned int)1891557868ULL),((unsigned int)1446565426ULL),((unsigned int)2235922675ULL),((unsigned int)3397401550ULL),((unsigned int)2507917905ULL),((unsigned int)2683564410ULL),((unsigned int)3491400402ULL),((unsigned int)446036663ULL),((unsigned int)1110589764ULL),((unsigned int)3117505242ULL),((unsigned int)2614504196ULL)};
unsigned int b_4[16]={((unsigned int)3128845272ULL),((unsigned int)2492659171ULL),((unsigned int)2223177931ULL),((unsigned int)2418929748ULL),((unsigned int)805541940ULL),((unsigned int)1891557868ULL),((unsigned int)1446565426ULL),((unsigned int)2235922675ULL),((unsigned int)3397401550ULL),((unsigned int)2507917905ULL),((unsigned int)2683564410ULL),((unsigned int)3491400402ULL),((unsigned int)446036663ULL),((unsigned int)1110589764ULL),((unsigned int)3117505242ULL),((unsigned int)2614504196ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 222\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3378687256ULL),((unsigned int)1731450022ULL),((unsigned int)1994658324ULL),((unsigned int)839656209ULL)};
unsigned int b_0[4]={((unsigned int)3378687256ULL),((unsigned int)1731450022ULL),((unsigned int)1994658324ULL),((unsigned int)839656209ULL)};
unsigned int a_1[4]={((unsigned int)1490009151ULL),((unsigned int)2399293191ULL),((unsigned int)3069473025ULL),((unsigned int)1488038954ULL)};
unsigned int b_1[4]={((unsigned int)1490009151ULL),((unsigned int)2399293191ULL),((unsigned int)3069473025ULL),((unsigned int)1488038954ULL)};
unsigned int a_2[4]={((unsigned int)2694965055ULL),((unsigned int)250416457ULL),((unsigned int)1394914274ULL),((unsigned int)3384238646ULL)};
unsigned int b_2[4]={((unsigned int)2694965055ULL),((unsigned int)250416457ULL),((unsigned int)1394914274ULL),((unsigned int)3384238646ULL)};
unsigned int a_3[4]={((unsigned int)914968102ULL),((unsigned int)36903792ULL),((unsigned int)374631615ULL),((unsigned int)584386290ULL)};
unsigned int b_3[4]={((unsigned int)914968102ULL),((unsigned int)36903792ULL),((unsigned int)374631615ULL),((unsigned int)584386290ULL)};
unsigned int a_4[16]={((unsigned int)344097781ULL),((unsigned int)215448860ULL),((unsigned int)3681083613ULL),((unsigned int)398191240ULL),((unsigned int)3583328483ULL),((unsigned int)2951057500ULL),((unsigned int)558539300ULL),((unsigned int)3795973298ULL),((unsigned int)1979969075ULL),((unsigned int)1729375910ULL),((unsigned int)214402717ULL),((unsigned int)589439381ULL),((unsigned int)1008872198ULL),((unsigned int)1204791122ULL),((unsigned int)2859546081ULL),((unsigned int)3652544184ULL)};
unsigned int b_4[16]={((unsigned int)344097781ULL),((unsigned int)215448860ULL),((unsigned int)3681083613ULL),((unsigned int)398191240ULL),((unsigned int)3583328483ULL),((unsigned int)2951057500ULL),((unsigned int)558539300ULL),((unsigned int)3795973298ULL),((unsigned int)1979969075ULL),((unsigned int)1729375910ULL),((unsigned int)214402717ULL),((unsigned int)589439381ULL),((unsigned int)1008872198ULL),((unsigned int)1204791122ULL),((unsigned int)2859546081ULL),((unsigned int)3652544184ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 223\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1971864775ULL),((unsigned int)359530898ULL),((unsigned int)2201765197ULL),((unsigned int)1983513897ULL)};
unsigned int b_0[4]={((unsigned int)1971864775ULL),((unsigned int)359530898ULL),((unsigned int)2201765197ULL),((unsigned int)1983513897ULL)};
unsigned int a_1[4]={((unsigned int)1401228170ULL),((unsigned int)2497066828ULL),((unsigned int)1149335426ULL),((unsigned int)1892622511ULL)};
unsigned int b_1[4]={((unsigned int)1401228170ULL),((unsigned int)2497066828ULL),((unsigned int)1149335426ULL),((unsigned int)1892622511ULL)};
unsigned int a_2[4]={((unsigned int)1025304494ULL),((unsigned int)1422672971ULL),((unsigned int)190641498ULL),((unsigned int)1734698305ULL)};
unsigned int b_2[4]={((unsigned int)1025304494ULL),((unsigned int)1422672971ULL),((unsigned int)190641498ULL),((unsigned int)1734698305ULL)};
unsigned int a_3[4]={((unsigned int)3462104312ULL),((unsigned int)3378404865ULL),((unsigned int)3112820660ULL),((unsigned int)2163837291ULL)};
unsigned int b_3[4]={((unsigned int)3462104312ULL),((unsigned int)3378404865ULL),((unsigned int)3112820660ULL),((unsigned int)2163837291ULL)};
unsigned int a_4[16]={((unsigned int)3380468746ULL),((unsigned int)739231995ULL),((unsigned int)2165879841ULL),((unsigned int)1796727443ULL),((unsigned int)1266292693ULL),((unsigned int)1453614876ULL),((unsigned int)3600875577ULL),((unsigned int)163881432ULL),((unsigned int)1891958039ULL),((unsigned int)1056821491ULL),((unsigned int)1884949733ULL),((unsigned int)1964081312ULL),((unsigned int)1915104338ULL),((unsigned int)3340242747ULL),((unsigned int)2274774408ULL),((unsigned int)4235151838ULL)};
unsigned int b_4[16]={((unsigned int)3380468746ULL),((unsigned int)739231995ULL),((unsigned int)2165879841ULL),((unsigned int)1796727443ULL),((unsigned int)1266292693ULL),((unsigned int)1453614876ULL),((unsigned int)3600875577ULL),((unsigned int)163881432ULL),((unsigned int)1891958039ULL),((unsigned int)1056821491ULL),((unsigned int)1884949733ULL),((unsigned int)1964081312ULL),((unsigned int)1915104338ULL),((unsigned int)3340242747ULL),((unsigned int)2274774408ULL),((unsigned int)4235151838ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 224\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1056912962ULL),((unsigned int)185105393ULL),((unsigned int)1520420163ULL),((unsigned int)2464807899ULL)};
unsigned int b_0[4]={((unsigned int)1056912962ULL),((unsigned int)185105393ULL),((unsigned int)1520420163ULL),((unsigned int)2464807899ULL)};
unsigned int a_1[4]={((unsigned int)1858458946ULL),((unsigned int)3528453946ULL),((unsigned int)4059153241ULL),((unsigned int)2276607826ULL)};
unsigned int b_1[4]={((unsigned int)1858458946ULL),((unsigned int)3528453946ULL),((unsigned int)4059153241ULL),((unsigned int)2276607826ULL)};
unsigned int a_2[4]={((unsigned int)4112682661ULL),((unsigned int)2288288766ULL),((unsigned int)1774566152ULL),((unsigned int)2038645738ULL)};
unsigned int b_2[4]={((unsigned int)4112682661ULL),((unsigned int)2288288766ULL),((unsigned int)1774566152ULL),((unsigned int)2038645738ULL)};
unsigned int a_3[4]={((unsigned int)1672735522ULL),((unsigned int)2510434127ULL),((unsigned int)1103727984ULL),((unsigned int)3615443226ULL)};
unsigned int b_3[4]={((unsigned int)1672735522ULL),((unsigned int)2510434127ULL),((unsigned int)1103727984ULL),((unsigned int)3615443226ULL)};
unsigned int a_4[16]={((unsigned int)1337469057ULL),((unsigned int)1224240942ULL),((unsigned int)4291784829ULL),((unsigned int)3463361320ULL),((unsigned int)3632449382ULL),((unsigned int)3789901662ULL),((unsigned int)2556900738ULL),((unsigned int)3692745849ULL),((unsigned int)3079959619ULL),((unsigned int)4120524036ULL),((unsigned int)1905848799ULL),((unsigned int)585837386ULL),((unsigned int)3332145541ULL),((unsigned int)1759044256ULL),((unsigned int)1645388150ULL),((unsigned int)2498986617ULL)};
unsigned int b_4[16]={((unsigned int)1337469057ULL),((unsigned int)1224240942ULL),((unsigned int)4291784829ULL),((unsigned int)3463361320ULL),((unsigned int)3632449382ULL),((unsigned int)3789901662ULL),((unsigned int)2556900738ULL),((unsigned int)3692745849ULL),((unsigned int)3079959619ULL),((unsigned int)4120524036ULL),((unsigned int)1905848799ULL),((unsigned int)585837386ULL),((unsigned int)3332145541ULL),((unsigned int)1759044256ULL),((unsigned int)1645388150ULL),((unsigned int)2498986617ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 225\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1468345090ULL),((unsigned int)4137801212ULL),((unsigned int)3638410740ULL),((unsigned int)2124070318ULL)};
unsigned int b_0[4]={((unsigned int)1468345090ULL),((unsigned int)4137801212ULL),((unsigned int)3638410740ULL),((unsigned int)2124070318ULL)};
unsigned int a_1[4]={((unsigned int)3486518300ULL),((unsigned int)2752992532ULL),((unsigned int)1941645540ULL),((unsigned int)2599210674ULL)};
unsigned int b_1[4]={((unsigned int)3486518300ULL),((unsigned int)2752992532ULL),((unsigned int)1941645540ULL),((unsigned int)2599210674ULL)};
unsigned int a_2[4]={((unsigned int)531134790ULL),((unsigned int)1714264536ULL),((unsigned int)399991968ULL),((unsigned int)1099260600ULL)};
unsigned int b_2[4]={((unsigned int)531134790ULL),((unsigned int)1714264536ULL),((unsigned int)399991968ULL),((unsigned int)1099260600ULL)};
unsigned int a_3[4]={((unsigned int)3686252304ULL),((unsigned int)1850683168ULL),((unsigned int)3647365978ULL),((unsigned int)40041063ULL)};
unsigned int b_3[4]={((unsigned int)3686252304ULL),((unsigned int)1850683168ULL),((unsigned int)3647365978ULL),((unsigned int)40041063ULL)};
unsigned int a_4[16]={((unsigned int)1015079434ULL),((unsigned int)1472815309ULL),((unsigned int)1815945701ULL),((unsigned int)1871549258ULL),((unsigned int)3664761586ULL),((unsigned int)4078325966ULL),((unsigned int)3329095395ULL),((unsigned int)3607125115ULL),((unsigned int)1824954738ULL),((unsigned int)1142713350ULL),((unsigned int)4251986253ULL),((unsigned int)3523865625ULL),((unsigned int)2459633419ULL),((unsigned int)797979205ULL),((unsigned int)1221766592ULL),((unsigned int)1047569056ULL)};
unsigned int b_4[16]={((unsigned int)1015079434ULL),((unsigned int)1472815309ULL),((unsigned int)1815945701ULL),((unsigned int)1871549258ULL),((unsigned int)3664761586ULL),((unsigned int)4078325966ULL),((unsigned int)3329095395ULL),((unsigned int)3607125115ULL),((unsigned int)1824954738ULL),((unsigned int)1142713350ULL),((unsigned int)4251986253ULL),((unsigned int)3523865625ULL),((unsigned int)2459633419ULL),((unsigned int)797979205ULL),((unsigned int)1221766592ULL),((unsigned int)1047569056ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 226\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)845635403ULL),((unsigned int)477791159ULL),((unsigned int)1341443392ULL),((unsigned int)1103666866ULL)};
unsigned int b_0[4]={((unsigned int)845635403ULL),((unsigned int)477791159ULL),((unsigned int)1341443392ULL),((unsigned int)1103666866ULL)};
unsigned int a_1[4]={((unsigned int)3597567036ULL),((unsigned int)2516825537ULL),((unsigned int)754752085ULL),((unsigned int)1114343117ULL)};
unsigned int b_1[4]={((unsigned int)3597567036ULL),((unsigned int)2516825537ULL),((unsigned int)754752085ULL),((unsigned int)1114343117ULL)};
unsigned int a_2[4]={((unsigned int)1504834118ULL),((unsigned int)1313306460ULL),((unsigned int)2529241006ULL),((unsigned int)2797536183ULL)};
unsigned int b_2[4]={((unsigned int)1504834118ULL),((unsigned int)1313306460ULL),((unsigned int)2529241006ULL),((unsigned int)2797536183ULL)};
unsigned int a_3[4]={((unsigned int)434883351ULL),((unsigned int)1892868879ULL),((unsigned int)3827627091ULL),((unsigned int)3976925273ULL)};
unsigned int b_3[4]={((unsigned int)434883351ULL),((unsigned int)1892868879ULL),((unsigned int)3827627091ULL),((unsigned int)3976925273ULL)};
unsigned int a_4[16]={((unsigned int)3371244435ULL),((unsigned int)4166870939ULL),((unsigned int)376203340ULL),((unsigned int)3840914839ULL),((unsigned int)1726185428ULL),((unsigned int)3579820249ULL),((unsigned int)704086224ULL),((unsigned int)40181324ULL),((unsigned int)3830483090ULL),((unsigned int)4292490946ULL),((unsigned int)1433408317ULL),((unsigned int)619720975ULL),((unsigned int)30437777ULL),((unsigned int)2325048357ULL),((unsigned int)133630472ULL),((unsigned int)863996801ULL)};
unsigned int b_4[16]={((unsigned int)3371244435ULL),((unsigned int)4166870939ULL),((unsigned int)376203340ULL),((unsigned int)3840914839ULL),((unsigned int)1726185428ULL),((unsigned int)3579820249ULL),((unsigned int)704086224ULL),((unsigned int)40181324ULL),((unsigned int)3830483090ULL),((unsigned int)4292490946ULL),((unsigned int)1433408317ULL),((unsigned int)619720975ULL),((unsigned int)30437777ULL),((unsigned int)2325048357ULL),((unsigned int)133630472ULL),((unsigned int)863996801ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 227\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3252868053ULL),((unsigned int)794542909ULL),((unsigned int)4104854575ULL),((unsigned int)3992194728ULL)};
unsigned int b_0[4]={((unsigned int)3252868053ULL),((unsigned int)794542909ULL),((unsigned int)4104854575ULL),((unsigned int)3992194728ULL)};
unsigned int a_1[4]={((unsigned int)243598904ULL),((unsigned int)3621895594ULL),((unsigned int)655973636ULL),((unsigned int)1104685037ULL)};
unsigned int b_1[4]={((unsigned int)243598904ULL),((unsigned int)3621895594ULL),((unsigned int)655973636ULL),((unsigned int)1104685037ULL)};
unsigned int a_2[4]={((unsigned int)1914386671ULL),((unsigned int)2287034807ULL),((unsigned int)3888353758ULL),((unsigned int)1847578101ULL)};
unsigned int b_2[4]={((unsigned int)1914386671ULL),((unsigned int)2287034807ULL),((unsigned int)3888353758ULL),((unsigned int)1847578101ULL)};
unsigned int a_3[4]={((unsigned int)1536765923ULL),((unsigned int)3003643806ULL),((unsigned int)4109787637ULL),((unsigned int)498949142ULL)};
unsigned int b_3[4]={((unsigned int)1536765923ULL),((unsigned int)3003643806ULL),((unsigned int)4109787637ULL),((unsigned int)498949142ULL)};
unsigned int a_4[16]={((unsigned int)2754359199ULL),((unsigned int)2176400774ULL),((unsigned int)1456411255ULL),((unsigned int)1868706645ULL),((unsigned int)2916481278ULL),((unsigned int)3631716711ULL),((unsigned int)887815656ULL),((unsigned int)2165317789ULL),((unsigned int)905275518ULL),((unsigned int)4121779296ULL),((unsigned int)2945174249ULL),((unsigned int)112916242ULL),((unsigned int)2878481208ULL),((unsigned int)3762544189ULL),((unsigned int)2780971615ULL),((unsigned int)2979958514ULL)};
unsigned int b_4[16]={((unsigned int)2754359199ULL),((unsigned int)2176400774ULL),((unsigned int)1456411255ULL),((unsigned int)1868706645ULL),((unsigned int)2916481278ULL),((unsigned int)3631716711ULL),((unsigned int)887815656ULL),((unsigned int)2165317789ULL),((unsigned int)905275518ULL),((unsigned int)4121779296ULL),((unsigned int)2945174249ULL),((unsigned int)112916242ULL),((unsigned int)2878481208ULL),((unsigned int)3762544189ULL),((unsigned int)2780971615ULL),((unsigned int)2979958514ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 228\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1991221623ULL),((unsigned int)598993158ULL),((unsigned int)2609789768ULL),((unsigned int)1191686416ULL)};
unsigned int b_0[4]={((unsigned int)1991221623ULL),((unsigned int)598993158ULL),((unsigned int)2609789768ULL),((unsigned int)1191686416ULL)};
unsigned int a_1[4]={((unsigned int)2005198767ULL),((unsigned int)2112190209ULL),((unsigned int)450243765ULL),((unsigned int)3013596876ULL)};
unsigned int b_1[4]={((unsigned int)2005198767ULL),((unsigned int)2112190209ULL),((unsigned int)450243765ULL),((unsigned int)3013596876ULL)};
unsigned int a_2[4]={((unsigned int)2501660790ULL),((unsigned int)2858103287ULL),((unsigned int)2315297423ULL),((unsigned int)3651480319ULL)};
unsigned int b_2[4]={((unsigned int)2501660790ULL),((unsigned int)2858103287ULL),((unsigned int)2315297423ULL),((unsigned int)3651480319ULL)};
unsigned int a_3[4]={((unsigned int)3854969146ULL),((unsigned int)871857056ULL),((unsigned int)3767396178ULL),((unsigned int)1900949758ULL)};
unsigned int b_3[4]={((unsigned int)3854969146ULL),((unsigned int)871857056ULL),((unsigned int)3767396178ULL),((unsigned int)1900949758ULL)};
unsigned int a_4[16]={((unsigned int)2985750114ULL),((unsigned int)1442129483ULL),((unsigned int)3345212834ULL),((unsigned int)1235861748ULL),((unsigned int)2991053631ULL),((unsigned int)3125659471ULL),((unsigned int)3527154223ULL),((unsigned int)3428737643ULL),((unsigned int)256581822ULL),((unsigned int)4065724103ULL),((unsigned int)3369611070ULL),((unsigned int)1092013583ULL),((unsigned int)2214689983ULL),((unsigned int)2875193337ULL),((unsigned int)2904180747ULL),((unsigned int)2771504950ULL)};
unsigned int b_4[16]={((unsigned int)2985750114ULL),((unsigned int)1442129483ULL),((unsigned int)3345212834ULL),((unsigned int)1235861748ULL),((unsigned int)2991053631ULL),((unsigned int)3125659471ULL),((unsigned int)3527154223ULL),((unsigned int)3428737643ULL),((unsigned int)256581822ULL),((unsigned int)4065724103ULL),((unsigned int)3369611070ULL),((unsigned int)1092013583ULL),((unsigned int)2214689983ULL),((unsigned int)2875193337ULL),((unsigned int)2904180747ULL),((unsigned int)2771504950ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 229\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2336958816ULL),((unsigned int)403102456ULL),((unsigned int)2274167528ULL),((unsigned int)3550915112ULL)};
unsigned int b_0[4]={((unsigned int)2336958816ULL),((unsigned int)403102456ULL),((unsigned int)2274167528ULL),((unsigned int)3550915112ULL)};
unsigned int a_1[4]={((unsigned int)265668072ULL),((unsigned int)2580638013ULL),((unsigned int)3673231632ULL),((unsigned int)3597495525ULL)};
unsigned int b_1[4]={((unsigned int)265668072ULL),((unsigned int)2580638013ULL),((unsigned int)3673231632ULL),((unsigned int)3597495525ULL)};
unsigned int a_2[4]={((unsigned int)380668286ULL),((unsigned int)1597840938ULL),((unsigned int)662180588ULL),((unsigned int)2160505927ULL)};
unsigned int b_2[4]={((unsigned int)380668286ULL),((unsigned int)1597840938ULL),((unsigned int)662180588ULL),((unsigned int)2160505927ULL)};
unsigned int a_3[4]={((unsigned int)3608475340ULL),((unsigned int)1528660820ULL),((unsigned int)3763807430ULL),((unsigned int)922897563ULL)};
unsigned int b_3[4]={((unsigned int)3608475340ULL),((unsigned int)1528660820ULL),((unsigned int)3763807430ULL),((unsigned int)922897563ULL)};
unsigned int a_4[16]={((unsigned int)821632633ULL),((unsigned int)3837253537ULL),((unsigned int)4102371586ULL),((unsigned int)2915585532ULL),((unsigned int)1387081517ULL),((unsigned int)2404555463ULL),((unsigned int)3205876833ULL),((unsigned int)1966043443ULL),((unsigned int)1092570059ULL),((unsigned int)2876541732ULL),((unsigned int)1145572650ULL),((unsigned int)2193435942ULL),((unsigned int)293384872ULL),((unsigned int)3281348519ULL),((unsigned int)4040549831ULL),((unsigned int)1996452940ULL)};
unsigned int b_4[16]={((unsigned int)821632633ULL),((unsigned int)3837253537ULL),((unsigned int)4102371586ULL),((unsigned int)2915585532ULL),((unsigned int)1387081517ULL),((unsigned int)2404555463ULL),((unsigned int)3205876833ULL),((unsigned int)1966043443ULL),((unsigned int)1092570059ULL),((unsigned int)2876541732ULL),((unsigned int)1145572650ULL),((unsigned int)2193435942ULL),((unsigned int)293384872ULL),((unsigned int)3281348519ULL),((unsigned int)4040549831ULL),((unsigned int)1996452940ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 230\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)640688499ULL),((unsigned int)4081210023ULL),((unsigned int)4081968620ULL),((unsigned int)1309906043ULL)};
unsigned int b_0[4]={((unsigned int)640688499ULL),((unsigned int)4081210023ULL),((unsigned int)4081968620ULL),((unsigned int)1309906043ULL)};
unsigned int a_1[4]={((unsigned int)2103173412ULL),((unsigned int)3049206233ULL),((unsigned int)1396452ULL),((unsigned int)3708893036ULL)};
unsigned int b_1[4]={((unsigned int)2103173412ULL),((unsigned int)3049206233ULL),((unsigned int)1396452ULL),((unsigned int)3708893036ULL)};
unsigned int a_2[4]={((unsigned int)4020701196ULL),((unsigned int)170262846ULL),((unsigned int)2531159118ULL),((unsigned int)3626188365ULL)};
unsigned int b_2[4]={((unsigned int)4020701196ULL),((unsigned int)170262846ULL),((unsigned int)2531159118ULL),((unsigned int)3626188365ULL)};
unsigned int a_3[4]={((unsigned int)461693827ULL),((unsigned int)1627813533ULL),((unsigned int)3312958538ULL),((unsigned int)402094306ULL)};
unsigned int b_3[4]={((unsigned int)461693827ULL),((unsigned int)1627813533ULL),((unsigned int)3312958538ULL),((unsigned int)402094306ULL)};
unsigned int a_4[16]={((unsigned int)2453836666ULL),((unsigned int)190280238ULL),((unsigned int)3710701299ULL),((unsigned int)2573506170ULL),((unsigned int)3452131198ULL),((unsigned int)3182414289ULL),((unsigned int)2885893778ULL),((unsigned int)870659240ULL),((unsigned int)2091710312ULL),((unsigned int)319484265ULL),((unsigned int)2580257808ULL),((unsigned int)1886546724ULL),((unsigned int)2599984323ULL),((unsigned int)1486956180ULL),((unsigned int)2096603127ULL),((unsigned int)88435116ULL)};
unsigned int b_4[16]={((unsigned int)2453836666ULL),((unsigned int)190280238ULL),((unsigned int)3710701299ULL),((unsigned int)2573506170ULL),((unsigned int)3452131198ULL),((unsigned int)3182414289ULL),((unsigned int)2885893778ULL),((unsigned int)870659240ULL),((unsigned int)2091710312ULL),((unsigned int)319484265ULL),((unsigned int)2580257808ULL),((unsigned int)1886546724ULL),((unsigned int)2599984323ULL),((unsigned int)1486956180ULL),((unsigned int)2096603127ULL),((unsigned int)88435116ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 231\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2276533668ULL),((unsigned int)2592823819ULL),((unsigned int)589147145ULL),((unsigned int)2839188587ULL)};
unsigned int b_0[4]={((unsigned int)2276533668ULL),((unsigned int)2592823819ULL),((unsigned int)589147145ULL),((unsigned int)2839188587ULL)};
unsigned int a_1[4]={((unsigned int)3640118461ULL),((unsigned int)907133252ULL),((unsigned int)140843127ULL),((unsigned int)1795857770ULL)};
unsigned int b_1[4]={((unsigned int)3640118461ULL),((unsigned int)907133252ULL),((unsigned int)140843127ULL),((unsigned int)1795857770ULL)};
unsigned int a_2[4]={((unsigned int)3072370537ULL),((unsigned int)1260580517ULL),((unsigned int)2279910217ULL),((unsigned int)2340869197ULL)};
unsigned int b_2[4]={((unsigned int)3072370537ULL),((unsigned int)1260580517ULL),((unsigned int)2279910217ULL),((unsigned int)2340869197ULL)};
unsigned int a_3[4]={((unsigned int)1933793708ULL),((unsigned int)1933633015ULL),((unsigned int)1732209795ULL),((unsigned int)3589857649ULL)};
unsigned int b_3[4]={((unsigned int)1933793708ULL),((unsigned int)1933633015ULL),((unsigned int)1732209795ULL),((unsigned int)3589857649ULL)};
unsigned int a_4[16]={((unsigned int)2627626824ULL),((unsigned int)1342806980ULL),((unsigned int)2083345772ULL),((unsigned int)772040030ULL),((unsigned int)1258780830ULL),((unsigned int)2402767244ULL),((unsigned int)2387817873ULL),((unsigned int)3721713896ULL),((unsigned int)689860202ULL),((unsigned int)2700970623ULL),((unsigned int)1372905562ULL),((unsigned int)340762924ULL),((unsigned int)763277045ULL),((unsigned int)3082129308ULL),((unsigned int)3977056603ULL),((unsigned int)2786755063ULL)};
unsigned int b_4[16]={((unsigned int)2627626824ULL),((unsigned int)1342806980ULL),((unsigned int)2083345772ULL),((unsigned int)772040030ULL),((unsigned int)1258780830ULL),((unsigned int)2402767244ULL),((unsigned int)2387817873ULL),((unsigned int)3721713896ULL),((unsigned int)689860202ULL),((unsigned int)2700970623ULL),((unsigned int)1372905562ULL),((unsigned int)340762924ULL),((unsigned int)763277045ULL),((unsigned int)3082129308ULL),((unsigned int)3977056603ULL),((unsigned int)2786755063ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 232\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1557921991ULL),((unsigned int)4231898529ULL),((unsigned int)1583573936ULL),((unsigned int)4086136079ULL)};
unsigned int b_0[4]={((unsigned int)1557921991ULL),((unsigned int)4231898529ULL),((unsigned int)1583573936ULL),((unsigned int)4086136079ULL)};
unsigned int a_1[4]={((unsigned int)494834947ULL),((unsigned int)3452145093ULL),((unsigned int)4037322103ULL),((unsigned int)1988808695ULL)};
unsigned int b_1[4]={((unsigned int)494834947ULL),((unsigned int)3452145093ULL),((unsigned int)4037322103ULL),((unsigned int)1988808695ULL)};
unsigned int a_2[4]={((unsigned int)1932256785ULL),((unsigned int)2723574514ULL),((unsigned int)562239230ULL),((unsigned int)3255631890ULL)};
unsigned int b_2[4]={((unsigned int)1932256785ULL),((unsigned int)2723574514ULL),((unsigned int)562239230ULL),((unsigned int)3255631890ULL)};
unsigned int a_3[4]={((unsigned int)1446186435ULL),((unsigned int)1814830759ULL),((unsigned int)728543081ULL),((unsigned int)1654470432ULL)};
unsigned int b_3[4]={((unsigned int)1446186435ULL),((unsigned int)1814830759ULL),((unsigned int)728543081ULL),((unsigned int)1654470432ULL)};
unsigned int a_4[16]={((unsigned int)2404619015ULL),((unsigned int)4010326495ULL),((unsigned int)618409590ULL),((unsigned int)1159054920ULL),((unsigned int)3654272766ULL),((unsigned int)1435591251ULL),((unsigned int)1934414333ULL),((unsigned int)99601033ULL),((unsigned int)4029722529ULL),((unsigned int)1341890617ULL),((unsigned int)1387082387ULL),((unsigned int)1343755867ULL),((unsigned int)628886995ULL),((unsigned int)3231436457ULL),((unsigned int)2178360868ULL),((unsigned int)2037916163ULL)};
unsigned int b_4[16]={((unsigned int)2404619015ULL),((unsigned int)4010326495ULL),((unsigned int)618409590ULL),((unsigned int)1159054920ULL),((unsigned int)3654272766ULL),((unsigned int)1435591251ULL),((unsigned int)1934414333ULL),((unsigned int)99601033ULL),((unsigned int)4029722529ULL),((unsigned int)1341890617ULL),((unsigned int)1387082387ULL),((unsigned int)1343755867ULL),((unsigned int)628886995ULL),((unsigned int)3231436457ULL),((unsigned int)2178360868ULL),((unsigned int)2037916163ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 233\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)781286126ULL),((unsigned int)1730545940ULL),((unsigned int)2070820136ULL),((unsigned int)1859029788ULL)};
unsigned int b_0[4]={((unsigned int)781286126ULL),((unsigned int)1730545940ULL),((unsigned int)2070820136ULL),((unsigned int)1859029788ULL)};
unsigned int a_1[4]={((unsigned int)1548422427ULL),((unsigned int)2572245354ULL),((unsigned int)1613280479ULL),((unsigned int)2241159787ULL)};
unsigned int b_1[4]={((unsigned int)1548422427ULL),((unsigned int)2572245354ULL),((unsigned int)1613280479ULL),((unsigned int)2241159787ULL)};
unsigned int a_2[4]={((unsigned int)2286839338ULL),((unsigned int)1770458659ULL),((unsigned int)2194471585ULL),((unsigned int)2243818526ULL)};
unsigned int b_2[4]={((unsigned int)2286839338ULL),((unsigned int)1770458659ULL),((unsigned int)2194471585ULL),((unsigned int)2243818526ULL)};
unsigned int a_3[4]={((unsigned int)441686517ULL),((unsigned int)3169249999ULL),((unsigned int)1094786028ULL),((unsigned int)752850858ULL)};
unsigned int b_3[4]={((unsigned int)441686517ULL),((unsigned int)3169249999ULL),((unsigned int)1094786028ULL),((unsigned int)752850858ULL)};
unsigned int a_4[16]={((unsigned int)3645791182ULL),((unsigned int)1445635470ULL),((unsigned int)2807003883ULL),((unsigned int)251894523ULL),((unsigned int)1441860725ULL),((unsigned int)316457144ULL),((unsigned int)3541245889ULL),((unsigned int)1116283620ULL),((unsigned int)2338386920ULL),((unsigned int)3974061401ULL),((unsigned int)2395022618ULL),((unsigned int)1408296394ULL),((unsigned int)3829132050ULL),((unsigned int)3107411186ULL),((unsigned int)4102914545ULL),((unsigned int)2074862426ULL)};
unsigned int b_4[16]={((unsigned int)3645791182ULL),((unsigned int)1445635470ULL),((unsigned int)2807003883ULL),((unsigned int)251894523ULL),((unsigned int)1441860725ULL),((unsigned int)316457144ULL),((unsigned int)3541245889ULL),((unsigned int)1116283620ULL),((unsigned int)2338386920ULL),((unsigned int)3974061401ULL),((unsigned int)2395022618ULL),((unsigned int)1408296394ULL),((unsigned int)3829132050ULL),((unsigned int)3107411186ULL),((unsigned int)4102914545ULL),((unsigned int)2074862426ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 234\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1152698340ULL),((unsigned int)3625606705ULL),((unsigned int)1893143818ULL),((unsigned int)175896150ULL)};
unsigned int b_0[4]={((unsigned int)1152698340ULL),((unsigned int)3625606705ULL),((unsigned int)1893143818ULL),((unsigned int)175896150ULL)};
unsigned int a_1[4]={((unsigned int)453255833ULL),((unsigned int)4239520031ULL),((unsigned int)3439941972ULL),((unsigned int)4189002176ULL)};
unsigned int b_1[4]={((unsigned int)453255833ULL),((unsigned int)4239520031ULL),((unsigned int)3439941972ULL),((unsigned int)4189002176ULL)};
unsigned int a_2[4]={((unsigned int)761430562ULL),((unsigned int)175223893ULL),((unsigned int)3868338504ULL),((unsigned int)1175555041ULL)};
unsigned int b_2[4]={((unsigned int)761430562ULL),((unsigned int)175223893ULL),((unsigned int)3868338504ULL),((unsigned int)1175555041ULL)};
unsigned int a_3[4]={((unsigned int)2022775522ULL),((unsigned int)543929087ULL),((unsigned int)354052745ULL),((unsigned int)1141839457ULL)};
unsigned int b_3[4]={((unsigned int)2022775522ULL),((unsigned int)543929087ULL),((unsigned int)354052745ULL),((unsigned int)1141839457ULL)};
unsigned int a_4[16]={((unsigned int)2718928387ULL),((unsigned int)34017454ULL),((unsigned int)764207364ULL),((unsigned int)2161624554ULL),((unsigned int)2286556812ULL),((unsigned int)124005745ULL),((unsigned int)1115815055ULL),((unsigned int)2987273928ULL),((unsigned int)4084379585ULL),((unsigned int)3579536207ULL),((unsigned int)3585063563ULL),((unsigned int)511660463ULL),((unsigned int)1037006905ULL),((unsigned int)196289327ULL),((unsigned int)4120475057ULL),((unsigned int)2179543862ULL)};
unsigned int b_4[16]={((unsigned int)2718928387ULL),((unsigned int)34017454ULL),((unsigned int)764207364ULL),((unsigned int)2161624554ULL),((unsigned int)2286556812ULL),((unsigned int)124005745ULL),((unsigned int)1115815055ULL),((unsigned int)2987273928ULL),((unsigned int)4084379585ULL),((unsigned int)3579536207ULL),((unsigned int)3585063563ULL),((unsigned int)511660463ULL),((unsigned int)1037006905ULL),((unsigned int)196289327ULL),((unsigned int)4120475057ULL),((unsigned int)2179543862ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 235\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)833232797ULL),((unsigned int)1866961557ULL),((unsigned int)1009368667ULL),((unsigned int)3162568342ULL)};
unsigned int b_0[4]={((unsigned int)833232797ULL),((unsigned int)1866961557ULL),((unsigned int)1009368667ULL),((unsigned int)3162568342ULL)};
unsigned int a_1[4]={((unsigned int)1554449875ULL),((unsigned int)1276392801ULL),((unsigned int)3302047394ULL),((unsigned int)3193635188ULL)};
unsigned int b_1[4]={((unsigned int)1554449875ULL),((unsigned int)1276392801ULL),((unsigned int)3302047394ULL),((unsigned int)3193635188ULL)};
unsigned int a_2[4]={((unsigned int)964661638ULL),((unsigned int)1996184704ULL),((unsigned int)910989471ULL),((unsigned int)3712380321ULL)};
unsigned int b_2[4]={((unsigned int)964661638ULL),((unsigned int)1996184704ULL),((unsigned int)910989471ULL),((unsigned int)3712380321ULL)};
unsigned int a_3[4]={((unsigned int)148158169ULL),((unsigned int)2898082982ULL),((unsigned int)4134425856ULL),((unsigned int)3913540017ULL)};
unsigned int b_3[4]={((unsigned int)148158169ULL),((unsigned int)2898082982ULL),((unsigned int)4134425856ULL),((unsigned int)3913540017ULL)};
unsigned int a_4[16]={((unsigned int)1162950813ULL),((unsigned int)2122385385ULL),((unsigned int)2571253559ULL),((unsigned int)2444364220ULL),((unsigned int)3689641170ULL),((unsigned int)3808366503ULL),((unsigned int)1047021626ULL),((unsigned int)2000618898ULL),((unsigned int)1295277125ULL),((unsigned int)2462897452ULL),((unsigned int)295875056ULL),((unsigned int)288679523ULL),((unsigned int)2181680903ULL),((unsigned int)2356117610ULL),((unsigned int)596904224ULL),((unsigned int)4200707947ULL)};
unsigned int b_4[16]={((unsigned int)1162950813ULL),((unsigned int)2122385385ULL),((unsigned int)2571253559ULL),((unsigned int)2444364220ULL),((unsigned int)3689641170ULL),((unsigned int)3808366503ULL),((unsigned int)1047021626ULL),((unsigned int)2000618898ULL),((unsigned int)1295277125ULL),((unsigned int)2462897452ULL),((unsigned int)295875056ULL),((unsigned int)288679523ULL),((unsigned int)2181680903ULL),((unsigned int)2356117610ULL),((unsigned int)596904224ULL),((unsigned int)4200707947ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 236\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)423989545ULL),((unsigned int)2056019090ULL),((unsigned int)2193091366ULL),((unsigned int)3912510201ULL)};
unsigned int b_0[4]={((unsigned int)423989545ULL),((unsigned int)2056019090ULL),((unsigned int)2193091366ULL),((unsigned int)3912510201ULL)};
unsigned int a_1[4]={((unsigned int)356539119ULL),((unsigned int)1228101114ULL),((unsigned int)2649063077ULL),((unsigned int)3283611206ULL)};
unsigned int b_1[4]={((unsigned int)356539119ULL),((unsigned int)1228101114ULL),((unsigned int)2649063077ULL),((unsigned int)3283611206ULL)};
unsigned int a_2[4]={((unsigned int)2859017602ULL),((unsigned int)2003202086ULL),((unsigned int)3702125097ULL),((unsigned int)3482392070ULL)};
unsigned int b_2[4]={((unsigned int)2859017602ULL),((unsigned int)2003202086ULL),((unsigned int)3702125097ULL),((unsigned int)3482392070ULL)};
unsigned int a_3[4]={((unsigned int)1052345015ULL),((unsigned int)1710596995ULL),((unsigned int)820827100ULL),((unsigned int)2042772429ULL)};
unsigned int b_3[4]={((unsigned int)1052345015ULL),((unsigned int)1710596995ULL),((unsigned int)820827100ULL),((unsigned int)2042772429ULL)};
unsigned int a_4[16]={((unsigned int)3944089966ULL),((unsigned int)3643326422ULL),((unsigned int)427643337ULL),((unsigned int)3605066872ULL),((unsigned int)4230167437ULL),((unsigned int)74933026ULL),((unsigned int)4116406268ULL),((unsigned int)1608316282ULL),((unsigned int)263524800ULL),((unsigned int)3994851238ULL),((unsigned int)3148037360ULL),((unsigned int)523023225ULL),((unsigned int)4274486361ULL),((unsigned int)948874930ULL),((unsigned int)2769119555ULL),((unsigned int)1680011697ULL)};
unsigned int b_4[16]={((unsigned int)3944089966ULL),((unsigned int)3643326422ULL),((unsigned int)427643337ULL),((unsigned int)3605066872ULL),((unsigned int)4230167437ULL),((unsigned int)74933026ULL),((unsigned int)4116406268ULL),((unsigned int)1608316282ULL),((unsigned int)263524800ULL),((unsigned int)3994851238ULL),((unsigned int)3148037360ULL),((unsigned int)523023225ULL),((unsigned int)4274486361ULL),((unsigned int)948874930ULL),((unsigned int)2769119555ULL),((unsigned int)1680011697ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 237\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1316170597ULL),((unsigned int)3524918661ULL),((unsigned int)1213090195ULL),((unsigned int)3996689739ULL)};
unsigned int b_0[4]={((unsigned int)1316170597ULL),((unsigned int)3524918661ULL),((unsigned int)1213090195ULL),((unsigned int)3996689739ULL)};
unsigned int a_1[4]={((unsigned int)1444090850ULL),((unsigned int)26963657ULL),((unsigned int)895411996ULL),((unsigned int)2867916631ULL)};
unsigned int b_1[4]={((unsigned int)1444090850ULL),((unsigned int)26963657ULL),((unsigned int)895411996ULL),((unsigned int)2867916631ULL)};
unsigned int a_2[4]={((unsigned int)3934462907ULL),((unsigned int)3881013495ULL),((unsigned int)1688722902ULL),((unsigned int)1456089326ULL)};
unsigned int b_2[4]={((unsigned int)3934462907ULL),((unsigned int)3881013495ULL),((unsigned int)1688722902ULL),((unsigned int)1456089326ULL)};
unsigned int a_3[4]={((unsigned int)2004111078ULL),((unsigned int)871100198ULL),((unsigned int)3019785454ULL),((unsigned int)2463279971ULL)};
unsigned int b_3[4]={((unsigned int)2004111078ULL),((unsigned int)871100198ULL),((unsigned int)3019785454ULL),((unsigned int)2463279971ULL)};
unsigned int a_4[16]={((unsigned int)766184468ULL),((unsigned int)575084542ULL),((unsigned int)2779538432ULL),((unsigned int)2303184976ULL),((unsigned int)4136569736ULL),((unsigned int)3740218164ULL),((unsigned int)4222029829ULL),((unsigned int)577034687ULL),((unsigned int)2734967517ULL),((unsigned int)568909723ULL),((unsigned int)3825734214ULL),((unsigned int)423920512ULL),((unsigned int)3620445603ULL),((unsigned int)992919967ULL),((unsigned int)3271484063ULL),((unsigned int)2910098490ULL)};
unsigned int b_4[16]={((unsigned int)766184468ULL),((unsigned int)575084542ULL),((unsigned int)2779538432ULL),((unsigned int)2303184976ULL),((unsigned int)4136569736ULL),((unsigned int)3740218164ULL),((unsigned int)4222029829ULL),((unsigned int)577034687ULL),((unsigned int)2734967517ULL),((unsigned int)568909723ULL),((unsigned int)3825734214ULL),((unsigned int)423920512ULL),((unsigned int)3620445603ULL),((unsigned int)992919967ULL),((unsigned int)3271484063ULL),((unsigned int)2910098490ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 238\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)285699818ULL),((unsigned int)4265043282ULL),((unsigned int)3684517188ULL),((unsigned int)1337641314ULL)};
unsigned int b_0[4]={((unsigned int)285699818ULL),((unsigned int)4265043282ULL),((unsigned int)3684517188ULL),((unsigned int)1337641314ULL)};
unsigned int a_1[4]={((unsigned int)4103716784ULL),((unsigned int)4001799137ULL),((unsigned int)1652038827ULL),((unsigned int)2528383025ULL)};
unsigned int b_1[4]={((unsigned int)4103716784ULL),((unsigned int)4001799137ULL),((unsigned int)1652038827ULL),((unsigned int)2528383025ULL)};
unsigned int a_2[4]={((unsigned int)3413471006ULL),((unsigned int)2792590328ULL),((unsigned int)1518468993ULL),((unsigned int)2702593866ULL)};
unsigned int b_2[4]={((unsigned int)3413471006ULL),((unsigned int)2792590328ULL),((unsigned int)1518468993ULL),((unsigned int)2702593866ULL)};
unsigned int a_3[4]={((unsigned int)1571027882ULL),((unsigned int)3186587098ULL),((unsigned int)3231569710ULL),((unsigned int)116769608ULL)};
unsigned int b_3[4]={((unsigned int)1571027882ULL),((unsigned int)3186587098ULL),((unsigned int)3231569710ULL),((unsigned int)116769608ULL)};
unsigned int a_4[16]={((unsigned int)1946819557ULL),((unsigned int)1456945111ULL),((unsigned int)4138212952ULL),((unsigned int)2159051367ULL),((unsigned int)3855838246ULL),((unsigned int)774425166ULL),((unsigned int)2172088207ULL),((unsigned int)4272511648ULL),((unsigned int)1964546049ULL),((unsigned int)1197846912ULL),((unsigned int)3318625052ULL),((unsigned int)2394408599ULL),((unsigned int)2498476003ULL),((unsigned int)967161433ULL),((unsigned int)2432050878ULL),((unsigned int)4181362217ULL)};
unsigned int b_4[16]={((unsigned int)1946819557ULL),((unsigned int)1456945111ULL),((unsigned int)4138212952ULL),((unsigned int)2159051367ULL),((unsigned int)3855838246ULL),((unsigned int)774425166ULL),((unsigned int)2172088207ULL),((unsigned int)4272511648ULL),((unsigned int)1964546049ULL),((unsigned int)1197846912ULL),((unsigned int)3318625052ULL),((unsigned int)2394408599ULL),((unsigned int)2498476003ULL),((unsigned int)967161433ULL),((unsigned int)2432050878ULL),((unsigned int)4181362217ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 239\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)594043855ULL),((unsigned int)1984691029ULL),((unsigned int)912304556ULL),((unsigned int)3842290732ULL)};
unsigned int b_0[4]={((unsigned int)594043855ULL),((unsigned int)1984691029ULL),((unsigned int)912304556ULL),((unsigned int)3842290732ULL)};
unsigned int a_1[4]={((unsigned int)3765105968ULL),((unsigned int)1187215907ULL),((unsigned int)264577832ULL),((unsigned int)2910413750ULL)};
unsigned int b_1[4]={((unsigned int)3765105968ULL),((unsigned int)1187215907ULL),((unsigned int)264577832ULL),((unsigned int)2910413750ULL)};
unsigned int a_2[4]={((unsigned int)1844803457ULL),((unsigned int)2948789678ULL),((unsigned int)4009149979ULL),((unsigned int)1818734429ULL)};
unsigned int b_2[4]={((unsigned int)1844803457ULL),((unsigned int)2948789678ULL),((unsigned int)4009149979ULL),((unsigned int)1818734429ULL)};
unsigned int a_3[4]={((unsigned int)1618713581ULL),((unsigned int)2341015864ULL),((unsigned int)1058707070ULL),((unsigned int)980782162ULL)};
unsigned int b_3[4]={((unsigned int)1618713581ULL),((unsigned int)2341015864ULL),((unsigned int)1058707070ULL),((unsigned int)980782162ULL)};
unsigned int a_4[16]={((unsigned int)1511414097ULL),((unsigned int)1435345501ULL),((unsigned int)2341646060ULL),((unsigned int)2555604553ULL),((unsigned int)2451457132ULL),((unsigned int)1141109564ULL),((unsigned int)1413405626ULL),((unsigned int)1950392990ULL),((unsigned int)3122519311ULL),((unsigned int)3480048179ULL),((unsigned int)1060547189ULL),((unsigned int)1000191306ULL),((unsigned int)2596096538ULL),((unsigned int)2941464409ULL),((unsigned int)192348984ULL),((unsigned int)4262938755ULL)};
unsigned int b_4[16]={((unsigned int)1511414097ULL),((unsigned int)1435345501ULL),((unsigned int)2341646060ULL),((unsigned int)2555604553ULL),((unsigned int)2451457132ULL),((unsigned int)1141109564ULL),((unsigned int)1413405626ULL),((unsigned int)1950392990ULL),((unsigned int)3122519311ULL),((unsigned int)3480048179ULL),((unsigned int)1060547189ULL),((unsigned int)1000191306ULL),((unsigned int)2596096538ULL),((unsigned int)2941464409ULL),((unsigned int)192348984ULL),((unsigned int)4262938755ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 240\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1072670235ULL),((unsigned int)4280629695ULL),((unsigned int)3501187487ULL),((unsigned int)342190353ULL)};
unsigned int b_0[4]={((unsigned int)1072670235ULL),((unsigned int)4280629695ULL),((unsigned int)3501187487ULL),((unsigned int)342190353ULL)};
unsigned int a_1[4]={((unsigned int)290506264ULL),((unsigned int)3805224368ULL),((unsigned int)682649580ULL),((unsigned int)2629684862ULL)};
unsigned int b_1[4]={((unsigned int)290506264ULL),((unsigned int)3805224368ULL),((unsigned int)682649580ULL),((unsigned int)2629684862ULL)};
unsigned int a_2[4]={((unsigned int)3709417232ULL),((unsigned int)3563781911ULL),((unsigned int)1671524560ULL),((unsigned int)2727114731ULL)};
unsigned int b_2[4]={((unsigned int)3709417232ULL),((unsigned int)3563781911ULL),((unsigned int)1671524560ULL),((unsigned int)2727114731ULL)};
unsigned int a_3[4]={((unsigned int)3145849056ULL),((unsigned int)422248624ULL),((unsigned int)3466889725ULL),((unsigned int)1514981742ULL)};
unsigned int b_3[4]={((unsigned int)3145849056ULL),((unsigned int)422248624ULL),((unsigned int)3466889725ULL),((unsigned int)1514981742ULL)};
unsigned int a_4[16]={((unsigned int)2355035882ULL),((unsigned int)1583260650ULL),((unsigned int)577303028ULL),((unsigned int)1299884180ULL),((unsigned int)964463009ULL),((unsigned int)3291408520ULL),((unsigned int)3024435539ULL),((unsigned int)1504622213ULL),((unsigned int)115056841ULL),((unsigned int)3677058458ULL),((unsigned int)1233403174ULL),((unsigned int)3903458035ULL),((unsigned int)906734162ULL),((unsigned int)2783138513ULL),((unsigned int)1091071305ULL),((unsigned int)2890852572ULL)};
unsigned int b_4[16]={((unsigned int)2355035882ULL),((unsigned int)1583260650ULL),((unsigned int)577303028ULL),((unsigned int)1299884180ULL),((unsigned int)964463009ULL),((unsigned int)3291408520ULL),((unsigned int)3024435539ULL),((unsigned int)1504622213ULL),((unsigned int)115056841ULL),((unsigned int)3677058458ULL),((unsigned int)1233403174ULL),((unsigned int)3903458035ULL),((unsigned int)906734162ULL),((unsigned int)2783138513ULL),((unsigned int)1091071305ULL),((unsigned int)2890852572ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 241\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1030444721ULL),((unsigned int)1488713119ULL),((unsigned int)2093217646ULL),((unsigned int)3696731396ULL)};
unsigned int b_0[4]={((unsigned int)1030444721ULL),((unsigned int)1488713119ULL),((unsigned int)2093217646ULL),((unsigned int)3696731396ULL)};
unsigned int a_1[4]={((unsigned int)27424624ULL),((unsigned int)2808649638ULL),((unsigned int)32218760ULL),((unsigned int)2585819973ULL)};
unsigned int b_1[4]={((unsigned int)27424624ULL),((unsigned int)2808649638ULL),((unsigned int)32218760ULL),((unsigned int)2585819973ULL)};
unsigned int a_2[4]={((unsigned int)27835790ULL),((unsigned int)2928566883ULL),((unsigned int)2922004880ULL),((unsigned int)272337948ULL)};
unsigned int b_2[4]={((unsigned int)27835790ULL),((unsigned int)2928566883ULL),((unsigned int)2922004880ULL),((unsigned int)272337948ULL)};
unsigned int a_3[4]={((unsigned int)4278585407ULL),((unsigned int)1042479128ULL),((unsigned int)1371731614ULL),((unsigned int)3784790985ULL)};
unsigned int b_3[4]={((unsigned int)4278585407ULL),((unsigned int)1042479128ULL),((unsigned int)1371731614ULL),((unsigned int)3784790985ULL)};
unsigned int a_4[16]={((unsigned int)2808186640ULL),((unsigned int)721357400ULL),((unsigned int)250174316ULL),((unsigned int)619045104ULL),((unsigned int)4030221747ULL),((unsigned int)2884131404ULL),((unsigned int)3645389613ULL),((unsigned int)2316336011ULL),((unsigned int)3186106887ULL),((unsigned int)3300539581ULL),((unsigned int)2750426741ULL),((unsigned int)2980067012ULL),((unsigned int)457207733ULL),((unsigned int)2889220271ULL),((unsigned int)4147138178ULL),((unsigned int)1491836315ULL)};
unsigned int b_4[16]={((unsigned int)2808186640ULL),((unsigned int)721357400ULL),((unsigned int)250174316ULL),((unsigned int)619045104ULL),((unsigned int)4030221747ULL),((unsigned int)2884131404ULL),((unsigned int)3645389613ULL),((unsigned int)2316336011ULL),((unsigned int)3186106887ULL),((unsigned int)3300539581ULL),((unsigned int)2750426741ULL),((unsigned int)2980067012ULL),((unsigned int)457207733ULL),((unsigned int)2889220271ULL),((unsigned int)4147138178ULL),((unsigned int)1491836315ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 242\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2505688944ULL),((unsigned int)597305487ULL),((unsigned int)2572288197ULL),((unsigned int)3792235116ULL)};
unsigned int b_0[4]={((unsigned int)2505688944ULL),((unsigned int)597305487ULL),((unsigned int)2572288197ULL),((unsigned int)3792235116ULL)};
unsigned int a_1[4]={((unsigned int)1685430089ULL),((unsigned int)278525203ULL),((unsigned int)3355226396ULL),((unsigned int)1704676358ULL)};
unsigned int b_1[4]={((unsigned int)1685430089ULL),((unsigned int)278525203ULL),((unsigned int)3355226396ULL),((unsigned int)1704676358ULL)};
unsigned int a_2[4]={((unsigned int)1626968903ULL),((unsigned int)3011666236ULL),((unsigned int)94582490ULL),((unsigned int)1032692950ULL)};
unsigned int b_2[4]={((unsigned int)1626968903ULL),((unsigned int)3011666236ULL),((unsigned int)94582490ULL),((unsigned int)1032692950ULL)};
unsigned int a_3[4]={((unsigned int)795554359ULL),((unsigned int)833789387ULL),((unsigned int)4266308328ULL),((unsigned int)1615543109ULL)};
unsigned int b_3[4]={((unsigned int)795554359ULL),((unsigned int)833789387ULL),((unsigned int)4266308328ULL),((unsigned int)1615543109ULL)};
unsigned int a_4[16]={((unsigned int)1423454267ULL),((unsigned int)3268300294ULL),((unsigned int)1634155307ULL),((unsigned int)2118059122ULL),((unsigned int)4106959334ULL),((unsigned int)1040303939ULL),((unsigned int)3204366172ULL),((unsigned int)707234719ULL),((unsigned int)1038918195ULL),((unsigned int)2675431719ULL),((unsigned int)3915643933ULL),((unsigned int)3607107575ULL),((unsigned int)809678154ULL),((unsigned int)4034678778ULL),((unsigned int)2000637667ULL),((unsigned int)3388312910ULL)};
unsigned int b_4[16]={((unsigned int)1423454267ULL),((unsigned int)3268300294ULL),((unsigned int)1634155307ULL),((unsigned int)2118059122ULL),((unsigned int)4106959334ULL),((unsigned int)1040303939ULL),((unsigned int)3204366172ULL),((unsigned int)707234719ULL),((unsigned int)1038918195ULL),((unsigned int)2675431719ULL),((unsigned int)3915643933ULL),((unsigned int)3607107575ULL),((unsigned int)809678154ULL),((unsigned int)4034678778ULL),((unsigned int)2000637667ULL),((unsigned int)3388312910ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 243\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1007814906ULL),((unsigned int)1807517198ULL),((unsigned int)2571601600ULL),((unsigned int)1726823492ULL)};
unsigned int b_0[4]={((unsigned int)1007814906ULL),((unsigned int)1807517198ULL),((unsigned int)2571601600ULL),((unsigned int)1726823492ULL)};
unsigned int a_1[4]={((unsigned int)1809485154ULL),((unsigned int)2861996292ULL),((unsigned int)486665657ULL),((unsigned int)4278370520ULL)};
unsigned int b_1[4]={((unsigned int)1809485154ULL),((unsigned int)2861996292ULL),((unsigned int)486665657ULL),((unsigned int)4278370520ULL)};
unsigned int a_2[4]={((unsigned int)1245741401ULL),((unsigned int)1941156719ULL),((unsigned int)4104418824ULL),((unsigned int)2709384545ULL)};
unsigned int b_2[4]={((unsigned int)1245741401ULL),((unsigned int)1941156719ULL),((unsigned int)4104418824ULL),((unsigned int)2709384545ULL)};
unsigned int a_3[4]={((unsigned int)4160653450ULL),((unsigned int)2345927287ULL),((unsigned int)2981015298ULL),((unsigned int)1098760015ULL)};
unsigned int b_3[4]={((unsigned int)4160653450ULL),((unsigned int)2345927287ULL),((unsigned int)2981015298ULL),((unsigned int)1098760015ULL)};
unsigned int a_4[16]={((unsigned int)3281725997ULL),((unsigned int)2676487865ULL),((unsigned int)3109303327ULL),((unsigned int)1029305261ULL),((unsigned int)895357486ULL),((unsigned int)3879562732ULL),((unsigned int)3199939163ULL),((unsigned int)2315424839ULL),((unsigned int)4247142804ULL),((unsigned int)2572074161ULL),((unsigned int)1729089684ULL),((unsigned int)2489770633ULL),((unsigned int)4266570304ULL),((unsigned int)710676475ULL),((unsigned int)3570021625ULL),((unsigned int)971785890ULL)};
unsigned int b_4[16]={((unsigned int)3281725997ULL),((unsigned int)2676487865ULL),((unsigned int)3109303327ULL),((unsigned int)1029305261ULL),((unsigned int)895357486ULL),((unsigned int)3879562732ULL),((unsigned int)3199939163ULL),((unsigned int)2315424839ULL),((unsigned int)4247142804ULL),((unsigned int)2572074161ULL),((unsigned int)1729089684ULL),((unsigned int)2489770633ULL),((unsigned int)4266570304ULL),((unsigned int)710676475ULL),((unsigned int)3570021625ULL),((unsigned int)971785890ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 244\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2402885056ULL),((unsigned int)1412433624ULL),((unsigned int)3887674884ULL),((unsigned int)225534796ULL)};
unsigned int b_0[4]={((unsigned int)2402885056ULL),((unsigned int)1412433624ULL),((unsigned int)3887674884ULL),((unsigned int)225534796ULL)};
unsigned int a_1[4]={((unsigned int)3027729936ULL),((unsigned int)1940782986ULL),((unsigned int)4062807393ULL),((unsigned int)3073576995ULL)};
unsigned int b_1[4]={((unsigned int)3027729936ULL),((unsigned int)1940782986ULL),((unsigned int)4062807393ULL),((unsigned int)3073576995ULL)};
unsigned int a_2[4]={((unsigned int)3562524700ULL),((unsigned int)2306036857ULL),((unsigned int)2859530945ULL),((unsigned int)2962426098ULL)};
unsigned int b_2[4]={((unsigned int)3562524700ULL),((unsigned int)2306036857ULL),((unsigned int)2859530945ULL),((unsigned int)2962426098ULL)};
unsigned int a_3[4]={((unsigned int)502000838ULL),((unsigned int)897563328ULL),((unsigned int)2995213560ULL),((unsigned int)3343677558ULL)};
unsigned int b_3[4]={((unsigned int)502000838ULL),((unsigned int)897563328ULL),((unsigned int)2995213560ULL),((unsigned int)3343677558ULL)};
unsigned int a_4[16]={((unsigned int)927340964ULL),((unsigned int)2112932174ULL),((unsigned int)1362187423ULL),((unsigned int)462704690ULL),((unsigned int)1814704798ULL),((unsigned int)3768648242ULL),((unsigned int)2972820332ULL),((unsigned int)935901487ULL),((unsigned int)3223150445ULL),((unsigned int)1278100486ULL),((unsigned int)3666099908ULL),((unsigned int)978961479ULL),((unsigned int)561530382ULL),((unsigned int)645624590ULL),((unsigned int)3167137457ULL),((unsigned int)2474893366ULL)};
unsigned int b_4[16]={((unsigned int)927340964ULL),((unsigned int)2112932174ULL),((unsigned int)1362187423ULL),((unsigned int)462704690ULL),((unsigned int)1814704798ULL),((unsigned int)3768648242ULL),((unsigned int)2972820332ULL),((unsigned int)935901487ULL),((unsigned int)3223150445ULL),((unsigned int)1278100486ULL),((unsigned int)3666099908ULL),((unsigned int)978961479ULL),((unsigned int)561530382ULL),((unsigned int)645624590ULL),((unsigned int)3167137457ULL),((unsigned int)2474893366ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 245\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3612816739ULL),((unsigned int)3521713889ULL),((unsigned int)1463312847ULL),((unsigned int)3115457372ULL)};
unsigned int b_0[4]={((unsigned int)3612816739ULL),((unsigned int)3521713889ULL),((unsigned int)1463312847ULL),((unsigned int)3115457372ULL)};
unsigned int a_1[4]={((unsigned int)371323412ULL),((unsigned int)3591333488ULL),((unsigned int)2703580360ULL),((unsigned int)2231533335ULL)};
unsigned int b_1[4]={((unsigned int)371323412ULL),((unsigned int)3591333488ULL),((unsigned int)2703580360ULL),((unsigned int)2231533335ULL)};
unsigned int a_2[4]={((unsigned int)2408760769ULL),((unsigned int)1930375580ULL),((unsigned int)1790580463ULL),((unsigned int)2863649779ULL)};
unsigned int b_2[4]={((unsigned int)2408760769ULL),((unsigned int)1930375580ULL),((unsigned int)1790580463ULL),((unsigned int)2863649779ULL)};
unsigned int a_3[4]={((unsigned int)2427116685ULL),((unsigned int)2190762527ULL),((unsigned int)125877316ULL),((unsigned int)1180040497ULL)};
unsigned int b_3[4]={((unsigned int)2427116685ULL),((unsigned int)2190762527ULL),((unsigned int)125877316ULL),((unsigned int)1180040497ULL)};
unsigned int a_4[16]={((unsigned int)3307434901ULL),((unsigned int)3776575884ULL),((unsigned int)1202292363ULL),((unsigned int)3365592811ULL),((unsigned int)1887227731ULL),((unsigned int)2283985864ULL),((unsigned int)541066895ULL),((unsigned int)152040516ULL),((unsigned int)719938390ULL),((unsigned int)3719234828ULL),((unsigned int)1947804563ULL),((unsigned int)80019239ULL),((unsigned int)1002654676ULL),((unsigned int)3335309402ULL),((unsigned int)1685107515ULL),((unsigned int)1339264225ULL)};
unsigned int b_4[16]={((unsigned int)3307434901ULL),((unsigned int)3776575884ULL),((unsigned int)1202292363ULL),((unsigned int)3365592811ULL),((unsigned int)1887227731ULL),((unsigned int)2283985864ULL),((unsigned int)541066895ULL),((unsigned int)152040516ULL),((unsigned int)719938390ULL),((unsigned int)3719234828ULL),((unsigned int)1947804563ULL),((unsigned int)80019239ULL),((unsigned int)1002654676ULL),((unsigned int)3335309402ULL),((unsigned int)1685107515ULL),((unsigned int)1339264225ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 246\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2290729104ULL),((unsigned int)326866509ULL),((unsigned int)431212616ULL),((unsigned int)3679432188ULL)};
unsigned int b_0[4]={((unsigned int)2290729104ULL),((unsigned int)326866509ULL),((unsigned int)431212616ULL),((unsigned int)3679432188ULL)};
unsigned int a_1[4]={((unsigned int)653686678ULL),((unsigned int)350413857ULL),((unsigned int)2481360431ULL),((unsigned int)3458252830ULL)};
unsigned int b_1[4]={((unsigned int)653686678ULL),((unsigned int)350413857ULL),((unsigned int)2481360431ULL),((unsigned int)3458252830ULL)};
unsigned int a_2[4]={((unsigned int)1906647516ULL),((unsigned int)2930550044ULL),((unsigned int)3641476442ULL),((unsigned int)1005676682ULL)};
unsigned int b_2[4]={((unsigned int)1906647516ULL),((unsigned int)2930550044ULL),((unsigned int)3641476442ULL),((unsigned int)1005676682ULL)};
unsigned int a_3[4]={((unsigned int)96256504ULL),((unsigned int)1607987075ULL),((unsigned int)2418905978ULL),((unsigned int)3776940679ULL)};
unsigned int b_3[4]={((unsigned int)96256504ULL),((unsigned int)1607987075ULL),((unsigned int)2418905978ULL),((unsigned int)3776940679ULL)};
unsigned int a_4[16]={((unsigned int)1224227508ULL),((unsigned int)947503885ULL),((unsigned int)3732388183ULL),((unsigned int)208250633ULL),((unsigned int)4157461731ULL),((unsigned int)4013583308ULL),((unsigned int)1414791310ULL),((unsigned int)953704129ULL),((unsigned int)697076199ULL),((unsigned int)2523740929ULL),((unsigned int)512667845ULL),((unsigned int)3934617993ULL),((unsigned int)1799497602ULL),((unsigned int)117431073ULL),((unsigned int)838168130ULL),((unsigned int)961384058ULL)};
unsigned int b_4[16]={((unsigned int)1224227508ULL),((unsigned int)947503885ULL),((unsigned int)3732388183ULL),((unsigned int)208250633ULL),((unsigned int)4157461731ULL),((unsigned int)4013583308ULL),((unsigned int)1414791310ULL),((unsigned int)953704129ULL),((unsigned int)697076199ULL),((unsigned int)2523740929ULL),((unsigned int)512667845ULL),((unsigned int)3934617993ULL),((unsigned int)1799497602ULL),((unsigned int)117431073ULL),((unsigned int)838168130ULL),((unsigned int)961384058ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 247\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)281011269ULL),((unsigned int)1779642123ULL),((unsigned int)4242853184ULL),((unsigned int)1987834477ULL)};
unsigned int b_0[4]={((unsigned int)281011269ULL),((unsigned int)1779642123ULL),((unsigned int)4242853184ULL),((unsigned int)1987834477ULL)};
unsigned int a_1[4]={((unsigned int)1297641507ULL),((unsigned int)3684011557ULL),((unsigned int)2129357765ULL),((unsigned int)535856026ULL)};
unsigned int b_1[4]={((unsigned int)1297641507ULL),((unsigned int)3684011557ULL),((unsigned int)2129357765ULL),((unsigned int)535856026ULL)};
unsigned int a_2[4]={((unsigned int)1489596517ULL),((unsigned int)2792211627ULL),((unsigned int)731284406ULL),((unsigned int)1875985586ULL)};
unsigned int b_2[4]={((unsigned int)1489596517ULL),((unsigned int)2792211627ULL),((unsigned int)731284406ULL),((unsigned int)1875985586ULL)};
unsigned int a_3[4]={((unsigned int)4225387389ULL),((unsigned int)1903768118ULL),((unsigned int)887651049ULL),((unsigned int)1810299311ULL)};
unsigned int b_3[4]={((unsigned int)4225387389ULL),((unsigned int)1903768118ULL),((unsigned int)887651049ULL),((unsigned int)1810299311ULL)};
unsigned int a_4[16]={((unsigned int)3277513506ULL),((unsigned int)928845188ULL),((unsigned int)283235482ULL),((unsigned int)931584383ULL),((unsigned int)1466766169ULL),((unsigned int)2711417007ULL),((unsigned int)2835901663ULL),((unsigned int)2660250273ULL),((unsigned int)1689669334ULL),((unsigned int)3906665960ULL),((unsigned int)3187545065ULL),((unsigned int)1047468757ULL),((unsigned int)906852265ULL),((unsigned int)2302627599ULL),((unsigned int)1006588483ULL),((unsigned int)1861708961ULL)};
unsigned int b_4[16]={((unsigned int)3277513506ULL),((unsigned int)928845188ULL),((unsigned int)283235482ULL),((unsigned int)931584383ULL),((unsigned int)1466766169ULL),((unsigned int)2711417007ULL),((unsigned int)2835901663ULL),((unsigned int)2660250273ULL),((unsigned int)1689669334ULL),((unsigned int)3906665960ULL),((unsigned int)3187545065ULL),((unsigned int)1047468757ULL),((unsigned int)906852265ULL),((unsigned int)2302627599ULL),((unsigned int)1006588483ULL),((unsigned int)1861708961ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 248\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1917087339ULL),((unsigned int)1239226592ULL),((unsigned int)3786314677ULL),((unsigned int)1300177666ULL)};
unsigned int b_0[4]={((unsigned int)1917087339ULL),((unsigned int)1239226592ULL),((unsigned int)3786314677ULL),((unsigned int)1300177666ULL)};
unsigned int a_1[4]={((unsigned int)2962005117ULL),((unsigned int)117567984ULL),((unsigned int)3653860632ULL),((unsigned int)2913710013ULL)};
unsigned int b_1[4]={((unsigned int)2962005117ULL),((unsigned int)117567984ULL),((unsigned int)3653860632ULL),((unsigned int)2913710013ULL)};
unsigned int a_2[4]={((unsigned int)2589838125ULL),((unsigned int)2237075050ULL),((unsigned int)1351948386ULL),((unsigned int)2702959711ULL)};
unsigned int b_2[4]={((unsigned int)2589838125ULL),((unsigned int)2237075050ULL),((unsigned int)1351948386ULL),((unsigned int)2702959711ULL)};
unsigned int a_3[4]={((unsigned int)1608050827ULL),((unsigned int)546836941ULL),((unsigned int)659928524ULL),((unsigned int)1160686846ULL)};
unsigned int b_3[4]={((unsigned int)1608050827ULL),((unsigned int)546836941ULL),((unsigned int)659928524ULL),((unsigned int)1160686846ULL)};
unsigned int a_4[16]={((unsigned int)1053275744ULL),((unsigned int)3610928090ULL),((unsigned int)3546163175ULL),((unsigned int)1426963931ULL),((unsigned int)313905756ULL),((unsigned int)2742843716ULL),((unsigned int)292720834ULL),((unsigned int)2337186335ULL),((unsigned int)3690753915ULL),((unsigned int)666127265ULL),((unsigned int)4212953980ULL),((unsigned int)2882934497ULL),((unsigned int)2770563824ULL),((unsigned int)467014464ULL),((unsigned int)3267143480ULL),((unsigned int)1679258262ULL)};
unsigned int b_4[16]={((unsigned int)1053275744ULL),((unsigned int)3610928090ULL),((unsigned int)3546163175ULL),((unsigned int)1426963931ULL),((unsigned int)313905756ULL),((unsigned int)2742843716ULL),((unsigned int)292720834ULL),((unsigned int)2337186335ULL),((unsigned int)3690753915ULL),((unsigned int)666127265ULL),((unsigned int)4212953980ULL),((unsigned int)2882934497ULL),((unsigned int)2770563824ULL),((unsigned int)467014464ULL),((unsigned int)3267143480ULL),((unsigned int)1679258262ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 249\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3126261ULL),((unsigned int)1624897571ULL),((unsigned int)4182393503ULL),((unsigned int)1002154954ULL)};
unsigned int b_0[4]={((unsigned int)3126261ULL),((unsigned int)1624897571ULL),((unsigned int)4182393503ULL),((unsigned int)1002154954ULL)};
unsigned int a_1[4]={((unsigned int)2958065338ULL),((unsigned int)2497338892ULL),((unsigned int)810528183ULL),((unsigned int)4073859635ULL)};
unsigned int b_1[4]={((unsigned int)2958065338ULL),((unsigned int)2497338892ULL),((unsigned int)810528183ULL),((unsigned int)4073859635ULL)};
unsigned int a_2[4]={((unsigned int)3795389565ULL),((unsigned int)2567922741ULL),((unsigned int)536038614ULL),((unsigned int)3987740938ULL)};
unsigned int b_2[4]={((unsigned int)3795389565ULL),((unsigned int)2567922741ULL),((unsigned int)536038614ULL),((unsigned int)3987740938ULL)};
unsigned int a_3[4]={((unsigned int)3360873799ULL),((unsigned int)792937664ULL),((unsigned int)29588687ULL),((unsigned int)1259178268ULL)};
unsigned int b_3[4]={((unsigned int)3360873799ULL),((unsigned int)792937664ULL),((unsigned int)29588687ULL),((unsigned int)1259178268ULL)};
unsigned int a_4[16]={((unsigned int)1210484926ULL),((unsigned int)4144410250ULL),((unsigned int)3194917994ULL),((unsigned int)851601721ULL),((unsigned int)1506466476ULL),((unsigned int)1698855694ULL),((unsigned int)3646033557ULL),((unsigned int)3907241508ULL),((unsigned int)289254427ULL),((unsigned int)1518975324ULL),((unsigned int)677922189ULL),((unsigned int)2350317013ULL),((unsigned int)3368114492ULL),((unsigned int)2565917353ULL),((unsigned int)4223180767ULL),((unsigned int)1164956425ULL)};
unsigned int b_4[16]={((unsigned int)1210484926ULL),((unsigned int)4144410250ULL),((unsigned int)3194917994ULL),((unsigned int)851601721ULL),((unsigned int)1506466476ULL),((unsigned int)1698855694ULL),((unsigned int)3646033557ULL),((unsigned int)3907241508ULL),((unsigned int)289254427ULL),((unsigned int)1518975324ULL),((unsigned int)677922189ULL),((unsigned int)2350317013ULL),((unsigned int)3368114492ULL),((unsigned int)2565917353ULL),((unsigned int)4223180767ULL),((unsigned int)1164956425ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 250\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2434507494ULL),((unsigned int)3357357276ULL),((unsigned int)1210601642ULL),((unsigned int)3209692495ULL)};
unsigned int b_0[4]={((unsigned int)2434507494ULL),((unsigned int)3357357276ULL),((unsigned int)1210601642ULL),((unsigned int)3209692495ULL)};
unsigned int a_1[4]={((unsigned int)3886713819ULL),((unsigned int)4005138099ULL),((unsigned int)422865563ULL),((unsigned int)2302531400ULL)};
unsigned int b_1[4]={((unsigned int)3886713819ULL),((unsigned int)4005138099ULL),((unsigned int)422865563ULL),((unsigned int)2302531400ULL)};
unsigned int a_2[4]={((unsigned int)233181320ULL),((unsigned int)170897527ULL),((unsigned int)960155235ULL),((unsigned int)4067884758ULL)};
unsigned int b_2[4]={((unsigned int)233181320ULL),((unsigned int)170897527ULL),((unsigned int)960155235ULL),((unsigned int)4067884758ULL)};
unsigned int a_3[4]={((unsigned int)3787563299ULL),((unsigned int)2671442836ULL),((unsigned int)1327902315ULL),((unsigned int)1156801059ULL)};
unsigned int b_3[4]={((unsigned int)3787563299ULL),((unsigned int)2671442836ULL),((unsigned int)1327902315ULL),((unsigned int)1156801059ULL)};
unsigned int a_4[16]={((unsigned int)2957593661ULL),((unsigned int)2621321751ULL),((unsigned int)2123241181ULL),((unsigned int)1900892860ULL),((unsigned int)2634592574ULL),((unsigned int)1160144580ULL),((unsigned int)1111121873ULL),((unsigned int)1059510660ULL),((unsigned int)3202821935ULL),((unsigned int)3345135536ULL),((unsigned int)1205029846ULL),((unsigned int)4200072634ULL),((unsigned int)291644506ULL),((unsigned int)1505304515ULL),((unsigned int)2934724614ULL),((unsigned int)1212937476ULL)};
unsigned int b_4[16]={((unsigned int)2957593661ULL),((unsigned int)2621321751ULL),((unsigned int)2123241181ULL),((unsigned int)1900892860ULL),((unsigned int)2634592574ULL),((unsigned int)1160144580ULL),((unsigned int)1111121873ULL),((unsigned int)1059510660ULL),((unsigned int)3202821935ULL),((unsigned int)3345135536ULL),((unsigned int)1205029846ULL),((unsigned int)4200072634ULL),((unsigned int)291644506ULL),((unsigned int)1505304515ULL),((unsigned int)2934724614ULL),((unsigned int)1212937476ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 251\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2311128517ULL),((unsigned int)232162471ULL),((unsigned int)39325047ULL),((unsigned int)3107446734ULL)};
unsigned int b_0[4]={((unsigned int)2311128517ULL),((unsigned int)232162471ULL),((unsigned int)39325047ULL),((unsigned int)3107446734ULL)};
unsigned int a_1[4]={((unsigned int)2056263174ULL),((unsigned int)4236782132ULL),((unsigned int)2379964213ULL),((unsigned int)2272439148ULL)};
unsigned int b_1[4]={((unsigned int)2056263174ULL),((unsigned int)4236782132ULL),((unsigned int)2379964213ULL),((unsigned int)2272439148ULL)};
unsigned int a_2[4]={((unsigned int)522488140ULL),((unsigned int)112912800ULL),((unsigned int)1116165676ULL),((unsigned int)1005955133ULL)};
unsigned int b_2[4]={((unsigned int)522488140ULL),((unsigned int)112912800ULL),((unsigned int)1116165676ULL),((unsigned int)1005955133ULL)};
unsigned int a_3[4]={((unsigned int)1109698614ULL),((unsigned int)1616406006ULL),((unsigned int)1369370343ULL),((unsigned int)2107197748ULL)};
unsigned int b_3[4]={((unsigned int)1109698614ULL),((unsigned int)1616406006ULL),((unsigned int)1369370343ULL),((unsigned int)2107197748ULL)};
unsigned int a_4[16]={((unsigned int)3964461449ULL),((unsigned int)2273056260ULL),((unsigned int)246605099ULL),((unsigned int)1675372241ULL),((unsigned int)366309883ULL),((unsigned int)9108526ULL),((unsigned int)1998771061ULL),((unsigned int)2221486061ULL),((unsigned int)3401390464ULL),((unsigned int)2479562381ULL),((unsigned int)518593692ULL),((unsigned int)2422300759ULL),((unsigned int)303835113ULL),((unsigned int)618428658ULL),((unsigned int)3309102446ULL),((unsigned int)2473951155ULL)};
unsigned int b_4[16]={((unsigned int)3964461449ULL),((unsigned int)2273056260ULL),((unsigned int)246605099ULL),((unsigned int)1675372241ULL),((unsigned int)366309883ULL),((unsigned int)9108526ULL),((unsigned int)1998771061ULL),((unsigned int)2221486061ULL),((unsigned int)3401390464ULL),((unsigned int)2479562381ULL),((unsigned int)518593692ULL),((unsigned int)2422300759ULL),((unsigned int)303835113ULL),((unsigned int)618428658ULL),((unsigned int)3309102446ULL),((unsigned int)2473951155ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 252\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1563284887ULL),((unsigned int)690467217ULL),((unsigned int)2490891285ULL),((unsigned int)1849071056ULL)};
unsigned int b_0[4]={((unsigned int)1563284887ULL),((unsigned int)690467217ULL),((unsigned int)2490891285ULL),((unsigned int)1849071056ULL)};
unsigned int a_1[4]={((unsigned int)4161844847ULL),((unsigned int)232780373ULL),((unsigned int)2415818042ULL),((unsigned int)2952512838ULL)};
unsigned int b_1[4]={((unsigned int)4161844847ULL),((unsigned int)232780373ULL),((unsigned int)2415818042ULL),((unsigned int)2952512838ULL)};
unsigned int a_2[4]={((unsigned int)1127809826ULL),((unsigned int)1007001494ULL),((unsigned int)3462913874ULL),((unsigned int)107244033ULL)};
unsigned int b_2[4]={((unsigned int)1127809826ULL),((unsigned int)1007001494ULL),((unsigned int)3462913874ULL),((unsigned int)107244033ULL)};
unsigned int a_3[4]={((unsigned int)3643279259ULL),((unsigned int)1605346570ULL),((unsigned int)2860554234ULL),((unsigned int)469113118ULL)};
unsigned int b_3[4]={((unsigned int)3643279259ULL),((unsigned int)1605346570ULL),((unsigned int)2860554234ULL),((unsigned int)469113118ULL)};
unsigned int a_4[16]={((unsigned int)3440094615ULL),((unsigned int)2359173409ULL),((unsigned int)976517380ULL),((unsigned int)2956526276ULL),((unsigned int)1689341856ULL),((unsigned int)1269108136ULL),((unsigned int)695594373ULL),((unsigned int)4025159213ULL),((unsigned int)1325615059ULL),((unsigned int)3912846170ULL),((unsigned int)4016569269ULL),((unsigned int)3718566075ULL),((unsigned int)2484037538ULL),((unsigned int)3634106481ULL),((unsigned int)798039797ULL),((unsigned int)1095059963ULL)};
unsigned int b_4[16]={((unsigned int)3440094615ULL),((unsigned int)2359173409ULL),((unsigned int)976517380ULL),((unsigned int)2956526276ULL),((unsigned int)1689341856ULL),((unsigned int)1269108136ULL),((unsigned int)695594373ULL),((unsigned int)4025159213ULL),((unsigned int)1325615059ULL),((unsigned int)3912846170ULL),((unsigned int)4016569269ULL),((unsigned int)3718566075ULL),((unsigned int)2484037538ULL),((unsigned int)3634106481ULL),((unsigned int)798039797ULL),((unsigned int)1095059963ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 253\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1698447141ULL),((unsigned int)646881563ULL),((unsigned int)3897100919ULL),((unsigned int)931468961ULL)};
unsigned int b_0[4]={((unsigned int)1698447141ULL),((unsigned int)646881563ULL),((unsigned int)3897100919ULL),((unsigned int)931468961ULL)};
unsigned int a_1[4]={((unsigned int)1608379905ULL),((unsigned int)4280577944ULL),((unsigned int)675640827ULL),((unsigned int)1839688570ULL)};
unsigned int b_1[4]={((unsigned int)1608379905ULL),((unsigned int)4280577944ULL),((unsigned int)675640827ULL),((unsigned int)1839688570ULL)};
unsigned int a_2[4]={((unsigned int)2892197482ULL),((unsigned int)717537587ULL),((unsigned int)4192069504ULL),((unsigned int)118672764ULL)};
unsigned int b_2[4]={((unsigned int)2892197482ULL),((unsigned int)717537587ULL),((unsigned int)4192069504ULL),((unsigned int)118672764ULL)};
unsigned int a_3[4]={((unsigned int)1033164354ULL),((unsigned int)2494266404ULL),((unsigned int)1689722841ULL),((unsigned int)688515578ULL)};
unsigned int b_3[4]={((unsigned int)1033164354ULL),((unsigned int)2494266404ULL),((unsigned int)1689722841ULL),((unsigned int)688515578ULL)};
unsigned int a_4[16]={((unsigned int)1230911779ULL),((unsigned int)3743419304ULL),((unsigned int)2112673294ULL),((unsigned int)3686223876ULL),((unsigned int)91552995ULL),((unsigned int)605754617ULL),((unsigned int)1708806798ULL),((unsigned int)2940338926ULL),((unsigned int)3453900050ULL),((unsigned int)3425099606ULL),((unsigned int)3986752894ULL),((unsigned int)4079830920ULL),((unsigned int)3828942237ULL),((unsigned int)2035233164ULL),((unsigned int)3245800002ULL),((unsigned int)4115116623ULL)};
unsigned int b_4[16]={((unsigned int)1230911779ULL),((unsigned int)3743419304ULL),((unsigned int)2112673294ULL),((unsigned int)3686223876ULL),((unsigned int)91552995ULL),((unsigned int)605754617ULL),((unsigned int)1708806798ULL),((unsigned int)2940338926ULL),((unsigned int)3453900050ULL),((unsigned int)3425099606ULL),((unsigned int)3986752894ULL),((unsigned int)4079830920ULL),((unsigned int)3828942237ULL),((unsigned int)2035233164ULL),((unsigned int)3245800002ULL),((unsigned int)4115116623ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 254\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)730915071ULL),((unsigned int)3094255052ULL),((unsigned int)1698141387ULL),((unsigned int)402236507ULL)};
unsigned int b_0[4]={((unsigned int)730915071ULL),((unsigned int)3094255052ULL),((unsigned int)1698141387ULL),((unsigned int)402236507ULL)};
unsigned int a_1[4]={((unsigned int)1621795884ULL),((unsigned int)3625733386ULL),((unsigned int)2293814772ULL),((unsigned int)3010971667ULL)};
unsigned int b_1[4]={((unsigned int)1621795884ULL),((unsigned int)3625733386ULL),((unsigned int)2293814772ULL),((unsigned int)3010971667ULL)};
unsigned int a_2[4]={((unsigned int)2313231132ULL),((unsigned int)4035348713ULL),((unsigned int)2927017282ULL),((unsigned int)837722942ULL)};
unsigned int b_2[4]={((unsigned int)2313231132ULL),((unsigned int)4035348713ULL),((unsigned int)2927017282ULL),((unsigned int)837722942ULL)};
unsigned int a_3[4]={((unsigned int)945907788ULL),((unsigned int)935577822ULL),((unsigned int)3217282123ULL),((unsigned int)3353354574ULL)};
unsigned int b_3[4]={((unsigned int)945907788ULL),((unsigned int)935577822ULL),((unsigned int)3217282123ULL),((unsigned int)3353354574ULL)};
unsigned int a_4[16]={((unsigned int)3554996165ULL),((unsigned int)3935976206ULL),((unsigned int)3357901010ULL),((unsigned int)14816638ULL),((unsigned int)3328944017ULL),((unsigned int)3863699611ULL),((unsigned int)272655858ULL),((unsigned int)2235664544ULL),((unsigned int)462357427ULL),((unsigned int)3970267992ULL),((unsigned int)1561587944ULL),((unsigned int)1339506044ULL),((unsigned int)2794496900ULL),((unsigned int)1125553183ULL),((unsigned int)1888208435ULL),((unsigned int)597401825ULL)};
unsigned int b_4[16]={((unsigned int)3554996165ULL),((unsigned int)3935976206ULL),((unsigned int)3357901010ULL),((unsigned int)14816638ULL),((unsigned int)3328944017ULL),((unsigned int)3863699611ULL),((unsigned int)272655858ULL),((unsigned int)2235664544ULL),((unsigned int)462357427ULL),((unsigned int)3970267992ULL),((unsigned int)1561587944ULL),((unsigned int)1339506044ULL),((unsigned int)2794496900ULL),((unsigned int)1125553183ULL),((unsigned int)1888208435ULL),((unsigned int)597401825ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 255\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3434025652ULL),((unsigned int)3924215033ULL),((unsigned int)3221939526ULL),((unsigned int)3607349713ULL)};
unsigned int b_0[4]={((unsigned int)3434025652ULL),((unsigned int)3924215033ULL),((unsigned int)3221939526ULL),((unsigned int)3607349713ULL)};
unsigned int a_1[4]={((unsigned int)3102474408ULL),((unsigned int)1395080793ULL),((unsigned int)3697801452ULL),((unsigned int)1125215166ULL)};
unsigned int b_1[4]={((unsigned int)3102474408ULL),((unsigned int)1395080793ULL),((unsigned int)3697801452ULL),((unsigned int)1125215166ULL)};
unsigned int a_2[4]={((unsigned int)3675536573ULL),((unsigned int)1257009164ULL),((unsigned int)2355063161ULL),((unsigned int)1084915154ULL)};
unsigned int b_2[4]={((unsigned int)3675536573ULL),((unsigned int)1257009164ULL),((unsigned int)2355063161ULL),((unsigned int)1084915154ULL)};
unsigned int a_3[4]={((unsigned int)3996570105ULL),((unsigned int)249654158ULL),((unsigned int)502297438ULL),((unsigned int)3627475362ULL)};
unsigned int b_3[4]={((unsigned int)3996570105ULL),((unsigned int)249654158ULL),((unsigned int)502297438ULL),((unsigned int)3627475362ULL)};
unsigned int a_4[16]={((unsigned int)3178737443ULL),((unsigned int)2663959555ULL),((unsigned int)3207153688ULL),((unsigned int)3862353448ULL),((unsigned int)3753554057ULL),((unsigned int)1699779982ULL),((unsigned int)3694045483ULL),((unsigned int)593547155ULL),((unsigned int)2438259440ULL),((unsigned int)719128515ULL),((unsigned int)171404306ULL),((unsigned int)2160944610ULL),((unsigned int)3046308013ULL),((unsigned int)879897812ULL),((unsigned int)456582321ULL),((unsigned int)2382527841ULL)};
unsigned int b_4[16]={((unsigned int)3178737443ULL),((unsigned int)2663959555ULL),((unsigned int)3207153688ULL),((unsigned int)3862353448ULL),((unsigned int)3753554057ULL),((unsigned int)1699779982ULL),((unsigned int)3694045483ULL),((unsigned int)593547155ULL),((unsigned int)2438259440ULL),((unsigned int)719128515ULL),((unsigned int)171404306ULL),((unsigned int)2160944610ULL),((unsigned int)3046308013ULL),((unsigned int)879897812ULL),((unsigned int)456582321ULL),((unsigned int)2382527841ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 256\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)3751392601ULL),((unsigned int)1433307432ULL),((unsigned int)1007701792ULL),((unsigned int)2741248882ULL)};
unsigned int b_0[4]={((unsigned int)3751392601ULL),((unsigned int)1433307432ULL),((unsigned int)1007701792ULL),((unsigned int)2741248882ULL)};
unsigned int a_1[4]={((unsigned int)428544634ULL),((unsigned int)3294362408ULL),((unsigned int)1434653745ULL),((unsigned int)107715418ULL)};
unsigned int b_1[4]={((unsigned int)428544634ULL),((unsigned int)3294362408ULL),((unsigned int)1434653745ULL),((unsigned int)107715418ULL)};
unsigned int a_2[4]={((unsigned int)4066689672ULL),((unsigned int)920081518ULL),((unsigned int)3824152125ULL),((unsigned int)966263124ULL)};
unsigned int b_2[4]={((unsigned int)4066689672ULL),((unsigned int)920081518ULL),((unsigned int)3824152125ULL),((unsigned int)966263124ULL)};
unsigned int a_3[4]={((unsigned int)3084793626ULL),((unsigned int)2977347133ULL),((unsigned int)1234353516ULL),((unsigned int)563789982ULL)};
unsigned int b_3[4]={((unsigned int)3084793626ULL),((unsigned int)2977347133ULL),((unsigned int)1234353516ULL),((unsigned int)563789982ULL)};
unsigned int a_4[16]={((unsigned int)220910774ULL),((unsigned int)2891431197ULL),((unsigned int)3686875316ULL),((unsigned int)781050407ULL),((unsigned int)117086225ULL),((unsigned int)2402821222ULL),((unsigned int)3070979964ULL),((unsigned int)4150183466ULL),((unsigned int)2105272459ULL),((unsigned int)3754545928ULL),((unsigned int)3088214198ULL),((unsigned int)1791140720ULL),((unsigned int)2449801510ULL),((unsigned int)590202117ULL),((unsigned int)2739548312ULL),((unsigned int)846015672ULL)};
unsigned int b_4[16]={((unsigned int)220910774ULL),((unsigned int)2891431197ULL),((unsigned int)3686875316ULL),((unsigned int)781050407ULL),((unsigned int)117086225ULL),((unsigned int)2402821222ULL),((unsigned int)3070979964ULL),((unsigned int)4150183466ULL),((unsigned int)2105272459ULL),((unsigned int)3754545928ULL),((unsigned int)3088214198ULL),((unsigned int)1791140720ULL),((unsigned int)2449801510ULL),((unsigned int)590202117ULL),((unsigned int)2739548312ULL),((unsigned int)846015672ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 257\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2899200637ULL),((unsigned int)1190770567ULL),((unsigned int)961634620ULL),((unsigned int)4216014291ULL)};
unsigned int b_0[4]={((unsigned int)2899200637ULL),((unsigned int)1190770567ULL),((unsigned int)961634620ULL),((unsigned int)4216014291ULL)};
unsigned int a_1[4]={((unsigned int)1502798245ULL),((unsigned int)660244826ULL),((unsigned int)1787468518ULL),((unsigned int)3347882531ULL)};
unsigned int b_1[4]={((unsigned int)1502798245ULL),((unsigned int)660244826ULL),((unsigned int)1787468518ULL),((unsigned int)3347882531ULL)};
unsigned int a_2[4]={((unsigned int)1152306518ULL),((unsigned int)3415396948ULL),((unsigned int)3359068656ULL),((unsigned int)3302921276ULL)};
unsigned int b_2[4]={((unsigned int)1152306518ULL),((unsigned int)3415396948ULL),((unsigned int)3359068656ULL),((unsigned int)3302921276ULL)};
unsigned int a_3[4]={((unsigned int)3846461936ULL),((unsigned int)95745592ULL),((unsigned int)883725544ULL),((unsigned int)589752611ULL)};
unsigned int b_3[4]={((unsigned int)3846461936ULL),((unsigned int)95745592ULL),((unsigned int)883725544ULL),((unsigned int)589752611ULL)};
unsigned int a_4[16]={((unsigned int)2986510800ULL),((unsigned int)3293902277ULL),((unsigned int)3015190309ULL),((unsigned int)2344144757ULL),((unsigned int)2820849858ULL),((unsigned int)4044954837ULL),((unsigned int)50156261ULL),((unsigned int)2931599005ULL),((unsigned int)1879541555ULL),((unsigned int)4077551091ULL),((unsigned int)3750330041ULL),((unsigned int)766459757ULL),((unsigned int)4073698697ULL),((unsigned int)3447618489ULL),((unsigned int)2055666255ULL),((unsigned int)38594126ULL)};
unsigned int b_4[16]={((unsigned int)2986510800ULL),((unsigned int)3293902277ULL),((unsigned int)3015190309ULL),((unsigned int)2344144757ULL),((unsigned int)2820849858ULL),((unsigned int)4044954837ULL),((unsigned int)50156261ULL),((unsigned int)2931599005ULL),((unsigned int)1879541555ULL),((unsigned int)4077551091ULL),((unsigned int)3750330041ULL),((unsigned int)766459757ULL),((unsigned int)4073698697ULL),((unsigned int)3447618489ULL),((unsigned int)2055666255ULL),((unsigned int)38594126ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 258\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)549079423ULL),((unsigned int)728178295ULL),((unsigned int)3868937811ULL),((unsigned int)2475439285ULL)};
unsigned int b_0[4]={((unsigned int)549079423ULL),((unsigned int)728178295ULL),((unsigned int)3868937811ULL),((unsigned int)2475439285ULL)};
unsigned int a_1[4]={((unsigned int)369049581ULL),((unsigned int)164124146ULL),((unsigned int)1092632146ULL),((unsigned int)1035845914ULL)};
unsigned int b_1[4]={((unsigned int)369049581ULL),((unsigned int)164124146ULL),((unsigned int)1092632146ULL),((unsigned int)1035845914ULL)};
unsigned int a_2[4]={((unsigned int)272177406ULL),((unsigned int)2699712484ULL),((unsigned int)41402389ULL),((unsigned int)4060006230ULL)};
unsigned int b_2[4]={((unsigned int)272177406ULL),((unsigned int)2699712484ULL),((unsigned int)41402389ULL),((unsigned int)4060006230ULL)};
unsigned int a_3[4]={((unsigned int)3020438007ULL),((unsigned int)1439882792ULL),((unsigned int)1546282349ULL),((unsigned int)3017356564ULL)};
unsigned int b_3[4]={((unsigned int)3020438007ULL),((unsigned int)1439882792ULL),((unsigned int)1546282349ULL),((unsigned int)3017356564ULL)};
unsigned int a_4[16]={((unsigned int)3191616540ULL),((unsigned int)3056831996ULL),((unsigned int)2838237713ULL),((unsigned int)3798863753ULL),((unsigned int)937027864ULL),((unsigned int)4023322570ULL),((unsigned int)1667266251ULL),((unsigned int)3093086417ULL),((unsigned int)2300177440ULL),((unsigned int)1318876910ULL),((unsigned int)2280246841ULL),((unsigned int)2488118403ULL),((unsigned int)2313750727ULL),((unsigned int)799302633ULL),((unsigned int)201106123ULL),((unsigned int)1921661353ULL)};
unsigned int b_4[16]={((unsigned int)3191616540ULL),((unsigned int)3056831996ULL),((unsigned int)2838237713ULL),((unsigned int)3798863753ULL),((unsigned int)937027864ULL),((unsigned int)4023322570ULL),((unsigned int)1667266251ULL),((unsigned int)3093086417ULL),((unsigned int)2300177440ULL),((unsigned int)1318876910ULL),((unsigned int)2280246841ULL),((unsigned int)2488118403ULL),((unsigned int)2313750727ULL),((unsigned int)799302633ULL),((unsigned int)201106123ULL),((unsigned int)1921661353ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 259\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)108099230ULL),((unsigned int)1424846006ULL),((unsigned int)2331292254ULL),((unsigned int)3756677996ULL)};
unsigned int b_0[4]={((unsigned int)108099230ULL),((unsigned int)1424846006ULL),((unsigned int)2331292254ULL),((unsigned int)3756677996ULL)};
unsigned int a_1[4]={((unsigned int)3035858785ULL),((unsigned int)490832682ULL),((unsigned int)4254261876ULL),((unsigned int)1599140232ULL)};
unsigned int b_1[4]={((unsigned int)3035858785ULL),((unsigned int)490832682ULL),((unsigned int)4254261876ULL),((unsigned int)1599140232ULL)};
unsigned int a_2[4]={((unsigned int)1010864912ULL),((unsigned int)2781267850ULL),((unsigned int)3336340870ULL),((unsigned int)2787411344ULL)};
unsigned int b_2[4]={((unsigned int)1010864912ULL),((unsigned int)2781267850ULL),((unsigned int)3336340870ULL),((unsigned int)2787411344ULL)};
unsigned int a_3[4]={((unsigned int)2331319147ULL),((unsigned int)1636329956ULL),((unsigned int)2782087467ULL),((unsigned int)3585382415ULL)};
unsigned int b_3[4]={((unsigned int)2331319147ULL),((unsigned int)1636329956ULL),((unsigned int)2782087467ULL),((unsigned int)3585382415ULL)};
unsigned int a_4[16]={((unsigned int)1692124449ULL),((unsigned int)1672050639ULL),((unsigned int)1134422732ULL),((unsigned int)2417502499ULL),((unsigned int)514198300ULL),((unsigned int)1940936522ULL),((unsigned int)886905097ULL),((unsigned int)1985247155ULL),((unsigned int)3722252582ULL),((unsigned int)483623833ULL),((unsigned int)2965933477ULL),((unsigned int)3827099374ULL),((unsigned int)1040163062ULL),((unsigned int)2097177409ULL),((unsigned int)2639179097ULL),((unsigned int)1119739590ULL)};
unsigned int b_4[16]={((unsigned int)1692124449ULL),((unsigned int)1672050639ULL),((unsigned int)1134422732ULL),((unsigned int)2417502499ULL),((unsigned int)514198300ULL),((unsigned int)1940936522ULL),((unsigned int)886905097ULL),((unsigned int)1985247155ULL),((unsigned int)3722252582ULL),((unsigned int)483623833ULL),((unsigned int)2965933477ULL),((unsigned int)3827099374ULL),((unsigned int)1040163062ULL),((unsigned int)2097177409ULL),((unsigned int)2639179097ULL),((unsigned int)1119739590ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 260\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)1235637332ULL),((unsigned int)2434712122ULL),((unsigned int)271764880ULL),((unsigned int)4076878475ULL)};
unsigned int b_0[4]={((unsigned int)1235637332ULL),((unsigned int)2434712122ULL),((unsigned int)271764880ULL),((unsigned int)4076878475ULL)};
unsigned int a_1[4]={((unsigned int)2211826887ULL),((unsigned int)3573755387ULL),((unsigned int)3091092997ULL),((unsigned int)1569622543ULL)};
unsigned int b_1[4]={((unsigned int)2211826887ULL),((unsigned int)3573755387ULL),((unsigned int)3091092997ULL),((unsigned int)1569622543ULL)};
unsigned int a_2[4]={((unsigned int)1083175344ULL),((unsigned int)3957750881ULL),((unsigned int)3329155092ULL),((unsigned int)2835178276ULL)};
unsigned int b_2[4]={((unsigned int)1083175344ULL),((unsigned int)3957750881ULL),((unsigned int)3329155092ULL),((unsigned int)2835178276ULL)};
unsigned int a_3[4]={((unsigned int)3911404936ULL),((unsigned int)3272543110ULL),((unsigned int)2884021073ULL),((unsigned int)1915486893ULL)};
unsigned int b_3[4]={((unsigned int)3911404936ULL),((unsigned int)3272543110ULL),((unsigned int)2884021073ULL),((unsigned int)1915486893ULL)};
unsigned int a_4[16]={((unsigned int)2631122972ULL),((unsigned int)3594200169ULL),((unsigned int)544283765ULL),((unsigned int)418021520ULL),((unsigned int)4016147822ULL),((unsigned int)4272116542ULL),((unsigned int)4200550063ULL),((unsigned int)2850636449ULL),((unsigned int)1529421331ULL),((unsigned int)2149381824ULL),((unsigned int)3405972981ULL),((unsigned int)3473571572ULL),((unsigned int)202680963ULL),((unsigned int)578766701ULL),((unsigned int)3278771199ULL),((unsigned int)981177882ULL)};
unsigned int b_4[16]={((unsigned int)2631122972ULL),((unsigned int)3594200169ULL),((unsigned int)544283765ULL),((unsigned int)418021520ULL),((unsigned int)4016147822ULL),((unsigned int)4272116542ULL),((unsigned int)4200550063ULL),((unsigned int)2850636449ULL),((unsigned int)1529421331ULL),((unsigned int)2149381824ULL),((unsigned int)3405972981ULL),((unsigned int)3473571572ULL),((unsigned int)202680963ULL),((unsigned int)578766701ULL),((unsigned int)3278771199ULL),((unsigned int)981177882ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 261\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)2872886721ULL),((unsigned int)3375031957ULL),((unsigned int)2239651735ULL),((unsigned int)779396010ULL)};
unsigned int b_0[4]={((unsigned int)2872886721ULL),((unsigned int)3375031957ULL),((unsigned int)2239651735ULL),((unsigned int)779396010ULL)};
unsigned int a_1[4]={((unsigned int)215025873ULL),((unsigned int)1763812044ULL),((unsigned int)2766079676ULL),((unsigned int)94486545ULL)};
unsigned int b_1[4]={((unsigned int)215025873ULL),((unsigned int)1763812044ULL),((unsigned int)2766079676ULL),((unsigned int)94486545ULL)};
unsigned int a_2[4]={((unsigned int)2915699067ULL),((unsigned int)2277372818ULL),((unsigned int)824352450ULL),((unsigned int)3244560081ULL)};
unsigned int b_2[4]={((unsigned int)2915699067ULL),((unsigned int)2277372818ULL),((unsigned int)824352450ULL),((unsigned int)3244560081ULL)};
unsigned int a_3[4]={((unsigned int)3238371175ULL),((unsigned int)119391129ULL),((unsigned int)2189577489ULL),((unsigned int)4007663475ULL)};
unsigned int b_3[4]={((unsigned int)3238371175ULL),((unsigned int)119391129ULL),((unsigned int)2189577489ULL),((unsigned int)4007663475ULL)};
unsigned int a_4[16]={((unsigned int)1009980775ULL),((unsigned int)932927473ULL),((unsigned int)925449453ULL),((unsigned int)2305422510ULL),((unsigned int)697235439ULL),((unsigned int)2210499282ULL),((unsigned int)2076733859ULL),((unsigned int)1017937242ULL),((unsigned int)576327020ULL),((unsigned int)3047378072ULL),((unsigned int)517219924ULL),((unsigned int)3415306718ULL),((unsigned int)2739062170ULL),((unsigned int)3409304482ULL),((unsigned int)2157872052ULL),((unsigned int)1773859444ULL)};
unsigned int b_4[16]={((unsigned int)1009980775ULL),((unsigned int)932927473ULL),((unsigned int)925449453ULL),((unsigned int)2305422510ULL),((unsigned int)697235439ULL),((unsigned int)2210499282ULL),((unsigned int)2076733859ULL),((unsigned int)1017937242ULL),((unsigned int)576327020ULL),((unsigned int)3047378072ULL),((unsigned int)517219924ULL),((unsigned int)3415306718ULL),((unsigned int)2739062170ULL),((unsigned int)3409304482ULL),((unsigned int)2157872052ULL),((unsigned int)1773859444ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 262\n");return 1;}
}
{
unsigned int a_0[4]={((unsigned int)377809438ULL),((unsigned int)3184449197ULL),((unsigned int)2931267479ULL),((unsigned int)4058749271ULL)};
unsigned int b_0[4]={((unsigned int)377809438ULL),((unsigned int)3184449197ULL),((unsigned int)2931267479ULL),((unsigned int)4058749271ULL)};
unsigned int a_1[4]={((unsigned int)3542245015ULL),((unsigned int)3209524575ULL),((unsigned int)2681748058ULL),((unsigned int)2184294716ULL)};
unsigned int b_1[4]={((unsigned int)3542245015ULL),((unsigned int)3209524575ULL),((unsigned int)2681748058ULL),((unsigned int)2184294716ULL)};
unsigned int a_2[4]={((unsigned int)3011585200ULL),((unsigned int)3344435460ULL),((unsigned int)4215590531ULL),((unsigned int)3852679236ULL)};
unsigned int b_2[4]={((unsigned int)3011585200ULL),((unsigned int)3344435460ULL),((unsigned int)4215590531ULL),((unsigned int)3852679236ULL)};
unsigned int a_3[4]={((unsigned int)171056414ULL),((unsigned int)225848705ULL),((unsigned int)1336618946ULL),((unsigned int)250333864ULL)};
unsigned int b_3[4]={((unsigned int)171056414ULL),((unsigned int)225848705ULL),((unsigned int)1336618946ULL),((unsigned int)250333864ULL)};
unsigned int a_4[16]={((unsigned int)2336007938ULL),((unsigned int)1563604846ULL),((unsigned int)4094885171ULL),((unsigned int)3672496706ULL),((unsigned int)3878704987ULL),((unsigned int)67897558ULL),((unsigned int)3396078586ULL),((unsigned int)3992249488ULL),((unsigned int)2132551137ULL),((unsigned int)3932720394ULL),((unsigned int)1963023772ULL),((unsigned int)930179520ULL),((unsigned int)263331186ULL),((unsigned int)495184435ULL),((unsigned int)398855917ULL),((unsigned int)2041370179ULL)};
unsigned int b_4[16]={((unsigned int)2336007938ULL),((unsigned int)1563604846ULL),((unsigned int)4094885171ULL),((unsigned int)3672496706ULL),((unsigned int)3878704987ULL),((unsigned int)67897558ULL),((unsigned int)3396078586ULL),((unsigned int)3992249488ULL),((unsigned int)2132551137ULL),((unsigned int)3932720394ULL),((unsigned int)1963023772ULL),((unsigned int)930179520ULL),((unsigned int)263331186ULL),((unsigned int)495184435ULL),((unsigned int)398855917ULL),((unsigned int)2041370179ULL)};
reference(a_0,a_1,a_2,a_3,a_4);
candidate(b_0,b_1,b_2,b_3,b_4);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
