unsigned int kernel(unsigned int x, unsigned int y)
{
  return (x & 0x55555555u) | (x & 0xaaaaaaaau);
}


