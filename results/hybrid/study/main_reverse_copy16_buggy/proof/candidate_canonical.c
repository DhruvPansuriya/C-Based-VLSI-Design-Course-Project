void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 8; i++)
  {
    unsigned int x = a[i];
    unsigned int y = a[15 - i];
    out[i] = y;
    out[15 - i] = x;
  }

  out[0] ^= 1u;
}


