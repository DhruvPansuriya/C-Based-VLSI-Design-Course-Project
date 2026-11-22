#include <stdint.h>
#include <assert.h>
void kernel(unsigned int alpha, unsigned int beta, unsigned int c[16], unsigned int a[16]);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
void reference(unsigned int alpha, unsigned int beta, unsigned int c[16], unsigned int a[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      c[(i * 4) + j] *= beta;
    }

    for (int k = 0; k < 4; k++)
    {
      for (int j = 0; j <= i; j++)
      {
        c[(i * 4) + j] += (alpha * a[(i * 4) + k]) * a[(j * 4) + k];
      }

    }

  }

}


int main(void) {
{
unsigned int a_0=((unsigned int)0ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)0ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)1ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)1ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)4294967295ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)4294967295ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)2147483648ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)2147483648ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_2[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int a_3[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
unsigned int b_3[16]={((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL),((unsigned int)2147483648ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)2147483647ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)2147483647ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_2[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int a_3[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
unsigned int b_3[16]={((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL),((unsigned int)2147483647ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)2ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)2ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_2[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int a_3[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
unsigned int b_3[16]={((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL),((unsigned int)2ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)4294967294ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)4294967294ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_2[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int a_3[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
unsigned int b_3[16]={((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL),((unsigned int)4294967294ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)1431655765ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)1431655765ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_2[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int a_3[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
unsigned int b_3[16]={((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL),((unsigned int)1431655765ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)2863311530ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)2863311530ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_2[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int a_3[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
unsigned int b_3[16]={((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL),((unsigned int)2863311530ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)0ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)0ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)1ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)1ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)0ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)0ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)4294967295ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)4294967295ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_2[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int a_3[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
unsigned int b_3[16]={((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL),((unsigned int)4294967295ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)0ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)0ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_2[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int a_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
unsigned int b_3[16]={((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL),((unsigned int)0ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)1ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)1ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_2[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int a_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
unsigned int b_3[16]={((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL),((unsigned int)1ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
{
unsigned int a_0=((unsigned int)3ULL);
unsigned int b_0=a_0;
unsigned int a_1=((unsigned int)3ULL);
unsigned int b_1=a_1;
unsigned int a_2[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_2[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int a_3[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
unsigned int b_3[16]={((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL),((unsigned int)3ULL)};
reference(a_0,a_1,a_2,a_3);
kernel(b_0,b_1,b_2,b_3);
assert((a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_2[4]==b_2[4]) && (a_2[5]==b_2[5]) && (a_2[6]==b_2[6]) && (a_2[7]==b_2[7]) && (a_2[8]==b_2[8]) && (a_2[9]==b_2[9]) && (a_2[10]==b_2[10]) && (a_2[11]==b_2[11]) && (a_2[12]==b_2[12]) && (a_2[13]==b_2[13]) && (a_2[14]==b_2[14]) && (a_2[15]==b_2[15]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_3[4]==b_3[4]) && (a_3[5]==b_3[5]) && (a_3[6]==b_3[6]) && (a_3[7]==b_3[7]) && (a_3[8]==b_3[8]) && (a_3[9]==b_3[9]) && (a_3[10]==b_3[10]) && (a_3[11]==b_3[11]) && (a_3[12]==b_3[12]) && (a_3[13]==b_3[13]) && (a_3[14]==b_3[14]) && (a_3[15]==b_3[15]));
}
return 0;
}
