#include <stdint.h>
#include <assert.h>
short int kernel(short int a, short int b);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
short int reference(short int a, short int b)
{
  int sum;
  sum = ((int) a) + ((int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


int main(void) {
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-0LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)(-32767LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32767LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)32767LL);
short int b_0=a_0;
short int a_1=((short int)32767LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)2LL);
short int b_0=a_0;
short int a_1=((short int)2LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)(-1LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-1LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)21845LL);
short int b_0=a_0;
short int a_1=((short int)21845LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)(-21845LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-21845LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-0LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
{
short int a_0=((short int)3LL);
short int b_0=a_0;
short int a_1=((short int)3LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=kernel(b_0,b_1);
assert((ar==br));
}
return 0;
}
