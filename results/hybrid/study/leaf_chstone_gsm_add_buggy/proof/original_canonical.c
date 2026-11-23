short int gsm_add(short int a, short int b)
{
  long int sum;
  sum = ((long int) a) + ((long int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


