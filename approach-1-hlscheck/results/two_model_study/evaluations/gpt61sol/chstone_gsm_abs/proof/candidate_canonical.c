short int kernel(short int a)
{
  unsigned short int bits = (unsigned short int) a;
  unsigned short int sign = (unsigned short int) (0u - (bits >> 15));
  unsigned short int magnitude = (unsigned short int) ((bits ^ sign) + (bits >> 15));
  return (short int) (magnitude - (magnitude >> 15));
}


