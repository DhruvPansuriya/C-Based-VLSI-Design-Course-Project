void kernel(unsigned int x1[4], unsigned int x2[4], unsigned int y_1[4], unsigned int y_2[4], unsigned int a[16])
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      x1[i] = x1[i] + (a[(i * 4) + j] * y_1[j]);
    }

  }

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      x2[i] = x2[i] + (a[(j * 4) + i] * y_2[j]);
    }

  }

}


