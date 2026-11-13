unsigned int kernel(unsigned int x, unsigned int y)
{
  return ((x / 2u) + (y / 2u)) + (((x & 1u) + (y & 1u)) / 2u);
}


