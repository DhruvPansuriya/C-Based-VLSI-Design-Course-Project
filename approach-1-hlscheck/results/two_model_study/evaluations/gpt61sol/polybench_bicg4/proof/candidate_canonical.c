void kernel(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  unsigned int s0 = 0u;
  unsigned int s1 = 0u;
  unsigned int s2 = 0u;
  unsigned int s3 = 0u;
  const unsigned int p0 = p[0];
  const unsigned int p1 = p[1];
  const unsigned int p2 = p[2];
  const unsigned int p3 = p[3];
  for (int i = 0; i < 4; ++i)
  {
    const unsigned int ri = r[i];
    const unsigned int a0 = a[4 * i];
    const unsigned int a1 = a[(4 * i) + 1];
    const unsigned int a2 = a[(4 * i) + 2];
    const unsigned int a3 = a[(4 * i) + 3];
    s0 += ri * a0;
    s1 += ri * a1;
    s2 += ri * a2;
    s3 += ri * a3;
    q[i] = ((a0 * p0) + (a1 * p1)) + ((a2 * p2) + (a3 * p3));
  }

  s[0] = s0;
  s[1] = s1;
  s[2] = s2;
  s[3] = s3;
}


