unsigned int kernel(unsigned int a[16])
{
  unsigned int sum = 0u;
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++)
    if (r == c)
    sum += a[(r * 4) + c];


  return sum;
}


