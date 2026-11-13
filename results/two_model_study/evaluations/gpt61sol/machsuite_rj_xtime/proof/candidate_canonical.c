unsigned char kernel(unsigned char x)
{
  return (unsigned char) ((x << 1) ^ ((x >> 7) * 0x1b));
}


