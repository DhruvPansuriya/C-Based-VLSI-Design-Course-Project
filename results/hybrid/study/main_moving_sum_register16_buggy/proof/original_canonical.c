void kernel(unsigned int a[16], unsigned int out[13])
{
  for (int i = 0; i < 13; i++)
  {
    unsigned int sum = 0u;
    for (int j = 0; j < 4; j++)
      sum += a[i + j];

    out[i] = sum;
  }

}


