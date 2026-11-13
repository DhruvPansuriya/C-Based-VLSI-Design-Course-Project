unsigned int kernel(unsigned int a[8], unsigned int b[8])
{
  unsigned int aa = 0u;
  unsigned int bb = 0u;
  unsigned int ab = 0u;
  for (int i = 0; i < 8; i++)
  {
    unsigned int x = a[i];
    unsigned int y = b[i];
    aa += x * x;
    bb += y * y;
    ab += x * y;
  }

  return (aa + bb) - ab;
}


