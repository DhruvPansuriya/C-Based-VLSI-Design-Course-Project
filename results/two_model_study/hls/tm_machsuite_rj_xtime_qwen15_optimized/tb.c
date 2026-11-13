#include <stdint.h>
#include <assert.h>
unsigned char kernel(unsigned char x);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
unsigned char reference(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


int main(void) {
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)128ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)127ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)2ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)254ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)85ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)170ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
{
unsigned char a_0=((unsigned char)3ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=kernel(b_0);
assert((ar==br));
}
return 0;
}
