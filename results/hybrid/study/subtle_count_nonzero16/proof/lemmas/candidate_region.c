unsigned int kernel(unsigned int a[16])
{
  unsigned int n0 = 0u;
  unsigned int n1 = 0u;
  unsigned int n2 = 0u;
  unsigned int n3 = 0u;
  for (int i = 0; i < 16; i += 4)
  {
    n0 += (a[i] != 0u) ? (1u) : (0u);
    n1 += (a[i + 1] != 0u) ? (1u) : (0u);
    n2 += (a[i + 2] != 0u) ? (1u) : (0u);
    n3 += (a[i + 3] == 0u) ? (1u) : (0u);
  }

  return (n0 + n1) + (n2 + n3);
}


