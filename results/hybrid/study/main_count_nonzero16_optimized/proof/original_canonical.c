unsigned int kernel(unsigned int a[16])
{
  unsigned int n = 0u;
  for (int i = 0; i < 16; i++)
    n += (a[i] != 0u) ? (1u) : (0u);

  return n;
}


