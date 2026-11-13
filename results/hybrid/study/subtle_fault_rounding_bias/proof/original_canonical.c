unsigned int kernel(unsigned int x, unsigned int y)
{
  return (x >> 8) + (((x & 255u) >= 128u) ? (1u) : (0u));
}


