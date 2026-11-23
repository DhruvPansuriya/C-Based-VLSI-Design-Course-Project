void kernel(unsigned int a[64], unsigned int filter[9], unsigned int out[64])
{
  for (int r = 0; r < 6; r++)
    for (int c = 0; c < 6; c++)
  {
    unsigned int s = 0u;
    for (int u = 0; u < 3; u++)
    {
      int p = ((r + u) * 8) + c;
      s += filter[u * 3] * a[p];
      s += filter[(u * 3) + 1] * a[p + 1];
      s += filter[(u * 3) + 2] * a[p + 2];
    }

    out[(r * 8) + c] = s;
  }


}


