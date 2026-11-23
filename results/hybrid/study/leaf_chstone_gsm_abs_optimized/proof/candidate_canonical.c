short int gsm_abs(short int a)
{
  if (a == ((-32767) - 1))
    return 32767;
  return (a < 0) ? (-a) : (a);
}


