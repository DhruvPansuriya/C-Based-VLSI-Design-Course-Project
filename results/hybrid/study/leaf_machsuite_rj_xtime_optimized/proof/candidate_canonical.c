unsigned char rj_xtime(unsigned char x)
{
  return (x << 1) ^ ((x >> 7) * 0x1b);
}


