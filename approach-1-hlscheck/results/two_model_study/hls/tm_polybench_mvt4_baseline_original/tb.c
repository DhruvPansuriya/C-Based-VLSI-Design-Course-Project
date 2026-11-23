#include <stdint.h>
#include <assert.h>
void kernel(unsigned int x1[4], unsigned int x2[4], unsigned int y_1[4], unsigned int y_2[4], unsigned int a[16]);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
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
kernel(b_0,b_1,b_2,b_3,b_4);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]) && (a_4[0]==b_4[0]) && (a_4[1]==b_4[1]) && (a_4[2]==b_4[2]) && (a_4[3]==b_4[3]) && (a_4[4]==b_4[4]) && (a_4[5]==b_4[5]) && (a_4[6]==b_4[6]) && (a_4[7]==b_4[7]) && (a_4[8]==b_4[8]) && (a_4[9]==b_4[9]) && (a_4[10]==b_4[10]) && (a_4[11]==b_4[11]) && (a_4[12]==b_4[12]) && (a_4[13]==b_4[13]) && (a_4[14]==b_4[14]) && (a_4[15]==b_4[15]));
}
return 0;
}
