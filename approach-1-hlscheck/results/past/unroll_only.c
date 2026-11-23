unsigned int a[8];
unsigned int out[8];
#pragma pocc-region-start
{
  for (int i = 0; i < 8; i += 2)
  {
    out[i] = (a[i] * 8u) + 3u;
    out[i + 1] = (a[i + 1] * 8u) + 3u;
  }

}

#pragma pocc-region-end
