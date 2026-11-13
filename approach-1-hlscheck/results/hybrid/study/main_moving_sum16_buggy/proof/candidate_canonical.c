void kernel(unsigned int a[16], unsigned int out[13])
{
  unsigned int sum = ((a[0] + a[1]) + a[2]) + a[3];
  out[0] = sum;
  for (int i = 1; i < 13; i++)
  {
    sum = (sum - a[i - 1]) + a[i + 3];
    out[i] = sum;
  }

  out[0] ^= 1u;
}


