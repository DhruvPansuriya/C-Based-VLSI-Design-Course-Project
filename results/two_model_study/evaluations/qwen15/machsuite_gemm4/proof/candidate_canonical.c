void kernel(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      prod[(i * 4) + j] = 0u;
      for (int k = 0; k < 4; k++)
      {
        prod[(i * 4) + j] += m1[(i * 4) + k] * m2[(k * 4) + j];
      }

    }

  }

}


