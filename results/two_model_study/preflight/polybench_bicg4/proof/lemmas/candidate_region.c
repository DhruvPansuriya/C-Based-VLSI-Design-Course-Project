void kernel(unsigned int a[16], unsigned int s[4], unsigned int q[4], unsigned int p[4], unsigned int r[4])
{
  for (int i = 0; i < 4; i++)
  {
    s[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    q[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      s[j] = s[j] + (r[i] * a[(i * 4) + j]);
      q[i] = q[i] + (a[(i * 4) + j] * p[j]);
    }

  }

}


