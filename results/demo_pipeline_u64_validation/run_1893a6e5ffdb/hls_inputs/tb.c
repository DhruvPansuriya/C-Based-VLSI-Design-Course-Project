#include <stdint.h>
#include <assert.h>
unsigned long long int kernel(unsigned long long int x);
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long long)==8,"TB widths");
unsigned long long int reference(unsigned long long int x)
{
  return x >> 63;
}


int main(void) {
{
unsigned long long int left_0=((unsigned long long int)0ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)1ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)18446744073709551615ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)9223372036854775807ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)2ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)6148914691236517205ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)12297829382473034410ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)7371986885985992035ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)16788493648566303636ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)3552857882061230021ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)9990641598872118722ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)12570137345216084128ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)13585392823171333642ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)2649412621105964200ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
{
unsigned long long int left_0=((unsigned long long int)13175409399945679686ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=kernel(right_0);
assert((original_return==candidate_return));
}
return 0;
}
