unsigned int kernel(unsigned int x)
{
  unsigned int count = 0u;
  for (int i = 0; i < 8; i++)
    count += (x >> i) & 1u;

  return count;
}


