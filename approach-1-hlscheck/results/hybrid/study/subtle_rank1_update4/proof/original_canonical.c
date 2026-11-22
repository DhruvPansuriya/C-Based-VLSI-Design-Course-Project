void kernel(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int v = x[r];
    out[r * 4] = a[r * 4] + (v * y[0]);
    out[(r * 4) + 1] = a[(r * 4) + 1] + (v * y[1]);
    out[(r * 4) + 2] = a[(r * 4) + 2] + (v * y[2]);
    out[(r * 4) + 3] = a[(r * 4) + 3] + (v * y[3]);
  }

}


