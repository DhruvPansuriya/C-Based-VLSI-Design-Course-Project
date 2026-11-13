unsigned int kernel(unsigned int x)
{
  unsigned int count = 0u;
  for (int i = 0; i < 8; i += 2)
  {
    count += (x >> i) & 3u;
    count += (x >> (i + 1)) & 3u;
  }

  return count;
}


