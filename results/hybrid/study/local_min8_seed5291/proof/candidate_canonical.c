unsigned int kernel(unsigned int a[8])
{
  unsigned int value = a[0];
  for (int i = 1; i < 8; i++)
  {
    if (a[i] < value)
    {
      value = a[i];
    }
  }

  return value;
}


