void kernel(unsigned int x1[4], unsigned int x2[4], unsigned int y_1[4], unsigned int y_2[4], unsigned int a[16])
{
  for (int i = 0; i < 4; ++i)
  {
    unsigned int p0 = a[4 * i] * y_1[0];
    unsigned int p1 = a[(4 * i) + 1] * y_1[1];
    unsigned int p2 = a[(4 * i) + 2] * y_1[2];
    unsigned int p3 = a[(4 * i) + 3] * y_1[3];
    unsigned int q0 = a[i] * y_2[0];
    unsigned int q1 = a[4 + i] * y_2[1];
    unsigned int q2 = a[8 + i] * y_2[2];
    unsigned int q3 = a[12 + i] * y_2[3];
    x1[i] += (p0 + p1) + (p2 + p3);
    x2[i] += (q0 + q1) + (q2 + q3);
  }

}


