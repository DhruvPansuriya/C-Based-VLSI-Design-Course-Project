void kernel(unsigned int x, unsigned int b[4], unsigned int c[4], unsigned int a[4])
{
  for (int i = 0; i < 4; i++)
  {
    if (x > 10u)
    {
      a[i] = b[i] + c[i];
    }
    else
    {
      a[i] = b[i] - c[i];
    }
  }

}


