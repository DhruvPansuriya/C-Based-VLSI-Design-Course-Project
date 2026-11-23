void kernel(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
  if (x > 10u)
  {
    for (int i = 0; i < 4; i++)
    {
      a[i] = b[i] + c[i];
    }

  }
  else
  {
    for (int j = 0; j < 4; j++)
    {
      a[j] = b[j] - c[j];
    }

  }
}


