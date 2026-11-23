unsigned int kernel(unsigned int x)
{
  x ^= x >> 16;
  x ^= x >> 7;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 1u;
}


