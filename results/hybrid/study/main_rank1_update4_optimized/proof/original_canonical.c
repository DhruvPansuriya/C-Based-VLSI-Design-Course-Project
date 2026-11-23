void kernel(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++)
    out[(r * 4) + c] = a[(r * 4) + c] + (x[r] * y[c]);


}


