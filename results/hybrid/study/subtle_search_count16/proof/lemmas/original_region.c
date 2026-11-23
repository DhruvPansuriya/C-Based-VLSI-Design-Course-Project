unsigned int kernel(unsigned int a[16], unsigned int key)
{
  unsigned int even = 0u;
  unsigned int odd = 0u;
  for (int i = 0; i < 16; i += 2)
  {
    even += (a[i] == key) ? (1u) : (0u);
    odd += (a[i + 1] == key) ? (1u) : (0u);
  }

  return even + odd;
}


