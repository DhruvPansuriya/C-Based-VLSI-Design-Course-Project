void kernel(unsigned int a[16], unsigned int x[4], unsigned int out[4])
{
  for (int r = 0; r < 4; r++)
  {
    unsigned int p0 = a[r * 4] * x[0];
    unsigned int p1 = a[(r * 4) + 1] * x[1];
    unsigned int p2 = a[(r * 4) + 2] * x[2];
    unsigned int p3 = a[(r * 4) + 3] * x[3];
    out[r] = (p0 + p1) + (p2 + p3);
  }

}


