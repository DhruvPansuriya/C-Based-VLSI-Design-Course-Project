void kernel(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int tmp[4])
{
  const unsigned int x0 = x[0];
  const unsigned int x1 = x[1];
  const unsigned int x2 = x[2];
  const unsigned int x3 = x[3];
  unsigned int y0 = 0u;
  unsigned int y1 = 0u;
  unsigned int y2 = 0u;
  unsigned int y3 = 0u;
  for (int i = 0; i < 4; ++i)
  {
    const unsigned int a0 = a[4 * i];
    const unsigned int a1 = a[(4 * i) + 1];
    const unsigned int a2 = a[(4 * i) + 2];
    const unsigned int a3 = a[(4 * i) + 3];
    const unsigned int t = ((a0 * x0) + (a1 * x1)) + ((a2 * x2) + (a3 * x3));
    tmp[i] = t;
    y0 += a0 * t;
    y1 += a1 * t;
    y2 += a2 * t;
    y3 += a3 * t;
  }

  y[0] = y0;
  y[1] = y1;
  y[2] = y2;
  y[3] = y3;
}


