#include <stdint.h>
#include <assert.h>
int kernel(unsigned long long int a);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
int reference(unsigned long long int a)
{
  return 0xFFE0000000000000LL < ((unsigned long long int) (a << 1));
}


int main(void) {
{
unsigned long long int a_0=((unsigned long long int)0ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)1ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551615ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775807ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)2ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551614ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)6148914691236517205ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)12297829382473034410ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405312ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405313ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)18442240474082181120ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)4503599627370495ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)18446744069414584320ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775809ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
{
unsigned long long int a_0=((unsigned long long int)3ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=kernel(b_0);
assert((ar==br));
}
return 0;
}
