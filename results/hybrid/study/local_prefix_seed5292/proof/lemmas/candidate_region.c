void kernel(unsigned int a[8], unsigned int out[8])
{
  for (int i = 0; i < 8; i++)
  {
    out[i] = a[0];
    for (int j = 1; j <= i; j++)
    {
      if ((a[j] + out[j - 1]) < 0)
      {
        out[j] = a[j] + out[j - 1];
      }
      else
      {
        break;
      }
    }

  }

}


