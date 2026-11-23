unsigned int kernel(unsigned int a[16])
{
  unsigned int difference = 0u;
  unsigned int first = a[0];
  for (int i = 1; i < 16; i++)
    difference |= a[i] ^ first;

  return ((difference == 0u) ? (1u) : (0u)) ^ 1u;
}


