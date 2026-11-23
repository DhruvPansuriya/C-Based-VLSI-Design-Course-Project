unsigned char rj_xtime(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


