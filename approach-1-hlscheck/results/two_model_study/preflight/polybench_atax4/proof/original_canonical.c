void kernel(unsigned int a[16], unsigned int x[4], unsigned int y[4], unsigned int tmp[4])
{
  for (int i = 0; i < 4; i++)
  {
    y[i] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    tmp[i] = 0u;
    for (int j = 0; j < 4; j++)
    {
      tmp[i] = tmp[i] + (a[(i * 4) + j] * x[j]);
    }

    for (int j = 0; j < 4; j++)
    {
      y[j] = y[j] + (a[(i * 4) + j] * tmp[i]);
    }

  }

}


