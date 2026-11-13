#include <stdint.h>
#include <assert.h>
short int kernel(short int a);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
short int reference(short int a)
{
  return (a < 0) ? ((a == ((-32767) - 1)) ? (32767) : (-a)) : (a);
}


int main(void) {
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)(-32767LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)32767LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)2LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)(-1LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)21845LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)(-21845LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
{
short int a_0=((short int)3LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=kernel(b_0);
assert((ar==br));
}
return 0;
}
