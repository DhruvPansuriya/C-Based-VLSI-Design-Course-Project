short int kernel(short int a, short int b)
{
  int sum = ((int) a) + ((int) b);
  unsigned int biased = ((unsigned int) sum) + 32768u;
  if (biased > 65535u)
    return (a < 0) ? ((-32767) - 1) : (32767);
  return (short int) sum;
}


