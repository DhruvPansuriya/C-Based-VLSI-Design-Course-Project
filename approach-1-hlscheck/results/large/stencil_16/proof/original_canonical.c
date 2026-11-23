void kernel(unsigned int a[256], unsigned int filter[9], unsigned int out[256])
{
  for (int r = 0; r < 14; r++)
    for (int c = 0; c < 14; c++)
  {
    unsigned int s = 0u;
    for (int u = 0; u < 3; u++)
      for (int v = 0; v < 3; v++)
      s += filter[(u * 3) + v] * a[(((r + u) * 16) + c) + v];


    out[(r * 16) + c] = s;
  }


}


