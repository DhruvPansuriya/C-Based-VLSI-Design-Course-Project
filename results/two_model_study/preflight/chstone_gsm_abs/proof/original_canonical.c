short int kernel(short int a)
{
  return (a < 0) ? ((a == ((-32767) - 1)) ? (32767) : (-a)) : (a);
}


