void kernel(unsigned int a[8], unsigned int out[6])
{
  out[0] = ((a[0] * 3u) + (a[1] * 5u)) + (a[2] * 3u);
  out[1] = ((a[3] * 3u) + (a[4] * 5u)) + (a[5] * 3u);
  for (int i = 2; i < 6; i++)
  {
    out[i] = (((a[i] * 3u) + (a[i + 1] * 5u)) + (a[i + 2] * 3u)) & 0xFFFFFFFF;
  }

}


