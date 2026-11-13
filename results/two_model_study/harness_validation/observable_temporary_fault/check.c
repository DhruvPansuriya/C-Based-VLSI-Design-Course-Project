#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

void reference(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int tmp[4])
{
  for (int i = 0; i < 4; i++)
  {
    y[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    tmp[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      tmp[i] = tmp[i] + (a[(i * 4) + j] * x[j]);
    }

    for (int j = 0; j < 4; j++)
    {
      y[j] = y[j] + (a[(i * 4) + j] * tmp[i]);
    }

  }

}


void candidate(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int tmp[4])
{
  for (int i = 0; i < 4; i++)
  {
    y[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    tmp[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      tmp[i] = tmp[i] + (a[(i * 4) + j] * x[j]);
    }

    for (int j = 0; j < 4; j++)
    {
      y[j] = y[j] + (a[(i * 4) + j] * tmp[i]);
    }

  }

  tmp[0] = 0u;
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 0\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 1\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 2\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 3\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 4\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 5\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 6\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 7\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 8\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 9\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 10\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 11\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 12\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 13\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 14\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 15\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 16\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 17\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 18\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 19\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 20\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 21\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 22\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 23\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 24\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 25\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 26\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 27\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 28\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 29\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 30\n");return 1;}
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
reference(a_0,a_1,a_2,a_3);
candidate(b_0,b_1,b_2,b_3);
if(!((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]))){printf("mismatch at test 31\n");return 1;}
}
printf("PASS 32 typed comparisons\n");
return 0;
}
