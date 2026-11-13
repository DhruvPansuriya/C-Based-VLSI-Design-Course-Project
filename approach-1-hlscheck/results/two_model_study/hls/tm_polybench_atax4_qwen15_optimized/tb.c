#include <stdint.h>
#include <assert.h>
void kernel(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int tmp[4]);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
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
kernel(b_0,b_1,b_2,b_3);
assert((a_0[0]==b_0[0]) && (a_0[1]==b_0[1]) && (a_0[2]==b_0[2]) && (a_0[3]==b_0[3]) && (a_0[4]==b_0[4]) && (a_0[5]==b_0[5]) && (a_0[6]==b_0[6]) && (a_0[7]==b_0[7]) && (a_0[8]==b_0[8]) && (a_0[9]==b_0[9]) && (a_0[10]==b_0[10]) && (a_0[11]==b_0[11]) && (a_0[12]==b_0[12]) && (a_0[13]==b_0[13]) && (a_0[14]==b_0[14]) && (a_0[15]==b_0[15]) && (a_1[0]==b_1[0]) && (a_1[1]==b_1[1]) && (a_1[2]==b_1[2]) && (a_1[3]==b_1[3]) && (a_2[0]==b_2[0]) && (a_2[1]==b_2[1]) && (a_2[2]==b_2[2]) && (a_2[3]==b_2[3]) && (a_3[0]==b_3[0]) && (a_3[1]==b_3[1]) && (a_3[2]==b_3[2]) && (a_3[3]==b_3[3]));
}
return 0;
}
