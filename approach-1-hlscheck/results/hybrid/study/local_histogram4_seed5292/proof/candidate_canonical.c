void kernel(unsigned int a[16], unsigned int out[4])
{
  for (int bin = 0; bin < 4; bin++)
  {
    unsigned int count = 0u;
    for (int i = bin; i < 16; i += 4)
      count += ((a[i] & 3u) == bin) ? (1u) : (0u);

    for (int i = bin; i < 16; i += 4)
      count += ((a[i + 1] & 3u) == bin) ? (1u) : (0u);

    for (int i = bin; i < 16; i += 4)
      count += ((a[i + 2] & 3u) == bin) ? (1u) : (0u);

    for (int i = bin; i < 16; i += 4)
      count += ((a[i + 3] & 3u) == bin) ? (1u) : (0u);

    out[bin] = count;
  }

}


