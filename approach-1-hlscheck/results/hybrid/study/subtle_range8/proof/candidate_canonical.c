unsigned int kernel(unsigned int a[8])
{
  unsigned int low = a[0];
  unsigned int high = a[0];
  for (int i = 1; i < 8; i++)
  {
    unsigned int v = a[i];
    low = (v < low) ? (v) : (low);
    high = (v > high) ? (v) : (high);
  }

  return low - high;
}


