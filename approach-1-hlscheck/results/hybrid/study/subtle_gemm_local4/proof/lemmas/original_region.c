void kernel(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    unsigned int s0 = 0u;
    unsigned int s1 = 0u;
    unsigned int s2 = 0u;
    unsigned int s3 = 0u;
    for (int k = 0; k < 4; k++)
    {
      unsigned int v = m1[(i * 4) + k];
      s0 += v * m2[k * 4];
      s1 += v * m2[(k * 4) + 1];
      s2 += v * m2[(k * 4) + 2];
      s3 += v * m2[(k * 4) + 3];
    }

    prod[i * 4] = s0;
    prod[(i * 4) + 1] = s1;
    prod[(i * 4) + 2] = s2;
    prod[(i * 4) + 3] = s3;
  }

}


