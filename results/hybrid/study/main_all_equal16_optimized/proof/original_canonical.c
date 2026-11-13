unsigned int kernel(unsigned int a[16])
{
  unsigned int same = 1u;
  for (int i = 1; i < 16; i++)
    same &= (a[i] == a[0]) ? (1u) : (0u);

  return same;
}


