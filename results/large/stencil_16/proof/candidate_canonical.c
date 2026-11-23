void kernel(unsigned int a[256], unsigned int filter[9], unsigned int out[256])
{
  for (int r = 0; r < 14; r++)
    for (int c = 0; c < 14; c++)
  {
    unsigned int s = 0u;
    for (int u = 0; u < 3; u++)
    {
      int p = ((r + u) * 16) + c;
      s += filter[u * 3] * a[p];
      s += filter[(u * 3) + 1] * a[p + 1];
      s += filter[(u * 3) + 2] * a[p + 2];
    }

    out[(r * 16) + c] = s;
  }


}


