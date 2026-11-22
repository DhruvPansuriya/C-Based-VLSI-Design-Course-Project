#include <stdint.h>
#include <assert.h>
unsigned int kernel(unsigned int x);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
unsigned int reference(unsigned int x)
{
  int y = -((int) 1ULL);
  return x < y;
}


int main(void) {
{
unsigned int left_0=((unsigned int)0ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)1ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)4294967295ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2147483648ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2147483647ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)1431655765ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2863311530ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2886237539ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)749878164ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)2109001669ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)4211303874ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)3883530400ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)1329905162ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)3765773480ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned int left_0=((unsigned int)4263170886ULL);
unsigned int right_0=left_0;
unsigned int original_return=reference(left_0);
unsigned int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
return 0;
}

unsigned kernel(unsigned x){return x<0xffffffffu;}
