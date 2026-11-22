void kernel(unsigned int a[64], unsigned int filter[9], unsigned int out[64])
{
  for (int r = 0; r < 6; r++)
    for (int c = 0; c < 6; c++)
  {
    unsigned int s = 0u;
    for (int u = 0; u < 3; u++)
      for (int v = 0; v < 3; v++)
      s += filter[(u * 3) + v] * a[(((r + u) * 8) + c) + v];


    out[(r * 8) + c] = s;
  }


}


