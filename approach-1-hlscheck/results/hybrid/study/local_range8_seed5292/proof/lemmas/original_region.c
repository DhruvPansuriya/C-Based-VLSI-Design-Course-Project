unsigned int kernel(unsigned int a[8])
{
  unsigned int low = a[0];
  unsigned int high = a[0];
  for (int i = 1; i < 8; i++)
    low = (a[i] < low) ? (a[i]) : (low);

  for (int j = 1; j < 8; j++)
    high = (a[j] > high) ? (a[j]) : (high);

  return high - low;
}


