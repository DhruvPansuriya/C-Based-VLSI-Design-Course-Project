void kernel(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j += 2)
    {
      unsigned int s0 = 0u;
      unsigned int s1 = 0u;
      for (int k = 0; k < 4; k++)
      {
        unsigned int value = m1[(i * 4) + k];
        s0 += value * m2[(k * 4) + j];
        s1 += value * m2[((k * 4) + j) + 1];
      }

      prod[(i * 4) + j] = s0;
      prod[((i * 4) + j) + 1] = s1;
    }

  }

}


