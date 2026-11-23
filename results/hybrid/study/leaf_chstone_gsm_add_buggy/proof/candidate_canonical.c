short int gsm_add(short int a, short int b)
{
  long int s = ((long int) a) + ((long int) b);
  if (s >= 32767)
    return 32767 - 1;
  if (s < ((-32767) - 1))
    return (-32767) - 1;
  return s;
}


