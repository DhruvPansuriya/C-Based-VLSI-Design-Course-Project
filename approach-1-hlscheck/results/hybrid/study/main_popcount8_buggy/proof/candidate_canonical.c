unsigned int kernel(unsigned int x)
{
  unsigned int v = x & 255u;
  v = v - ((v >> 1) & 0x55u);
  v = (v & 0x33u) + ((v >> 2) & 0x33u);
  return ((v + (v >> 4)) & 15u) ^ 1u;
}


