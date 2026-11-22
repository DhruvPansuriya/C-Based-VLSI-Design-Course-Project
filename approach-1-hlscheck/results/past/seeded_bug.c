unsigned int a[8];
unsigned int out[8];
#pragma pocc-region-start
{
  for (int i = 0; i < 8; i += 2)
  {
    out[i] = (a[i] << 3) + 3u;
    out[i + 1] = (a[i + 1] << 2) + 3u;
  }

}

#pragma pocc-region-end
