void kernel(unsigned int a[144], unsigned int filter[9], unsigned int out[144])
{
  for (int r = 0; r < 10; r++)
    for (int c = 0; c < 10; c++)
  {
    unsigned int s = 0u;
    for (int u = 0; u < 3; u++)
      for (int v = 0; v < 3; v++)
      s += filter[(u * 3) + v] * a[(((r + u) * 12) + c) + v];


    out[(r * 12) + c] = s;
  }


}


