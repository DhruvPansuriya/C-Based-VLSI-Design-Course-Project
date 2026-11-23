void kernel(unsigned int a[16], unsigned int x[4], unsigned int out[4])
{
  for (int r = 0; r < 4; r++)
    out[r] = 0u;

  for (int r = 0; r < 4; r++)
    for (int c = 0; c <= r; c++)
  {
    unsigned int value = a[(r * 4) + c];
    out[r] += value * x[c];
    if (c != r)
      out[c] += value * x[r];
  }


  out[0] ^= 1u;
}


