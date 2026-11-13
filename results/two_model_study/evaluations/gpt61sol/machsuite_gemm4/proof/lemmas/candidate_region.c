void kernel(unsigned int m1[16], unsigned int m2[16], unsigned int prod[16])
{
  for (int i = 0; i < 4; ++i)
  {
    const unsigned int a0 = m1[i * 4];
    const unsigned int a1 = m1[(i * 4) + 1];
    const unsigned int a2 = m1[(i * 4) + 2];
    const unsigned int a3 = m1[(i * 4) + 3];
    for (int j = 0; j < 4; ++j)
    {
      prod[(i * 4) + j] = ((a0 * m2[j]) + (a1 * m2[4 + j])) + ((a2 * m2[8 + j]) + (a3 * m2[12 + j]));
    }

  }

}


