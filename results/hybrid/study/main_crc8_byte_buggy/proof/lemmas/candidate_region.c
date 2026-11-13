unsigned int kernel(unsigned int x)
{
  unsigned int crc = x & 255u;
  for (int i = 0; i < 4; i++)
  {
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
    crc = ((crc << 1) ^ (((crc & 128u) != 0u) ? (7u) : (0u))) & 255u;
  }

  return crc ^ 1u;
}


