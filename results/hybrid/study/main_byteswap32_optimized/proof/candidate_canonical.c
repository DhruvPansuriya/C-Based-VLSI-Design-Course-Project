unsigned int kernel(unsigned int x)
{
  unsigned int t = ((x & 0x00ff00ffu) << 8) | ((x >> 8) & 0x00ff00ffu);
  return (t << 16) | (t >> 16);
}


