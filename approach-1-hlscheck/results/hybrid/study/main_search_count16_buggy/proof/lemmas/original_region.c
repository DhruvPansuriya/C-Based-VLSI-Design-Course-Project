unsigned int kernel(unsigned int a[16], unsigned int key)
{
  unsigned int n = 0u;
  for (int i = 0; i < 16; i++)
    n += (a[i] == key) ? (1u) : (0u);

  return n;
}


