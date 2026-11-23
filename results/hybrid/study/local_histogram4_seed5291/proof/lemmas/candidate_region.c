void kernel(unsigned int a[16], unsigned int out[4])
{
  for (int bin = 0; bin < 4; bin++)
  {
    unsigned int count = 0u;
    for (int i = 0; i < 16; i++)
      count += ((a[i] & 3u) == ((unsigned int) bin)) ? (1u) : (0u);

    out[bin] = count;
  }

}


