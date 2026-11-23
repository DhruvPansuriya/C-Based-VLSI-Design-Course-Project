unsigned int kernel(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 8; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc;
}


