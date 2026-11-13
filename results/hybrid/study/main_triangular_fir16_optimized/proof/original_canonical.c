void kernel(unsigned int a[16], unsigned int out[14])
{
  for (int i = 0; i < 14; i++)
    out[i] = (a[i] + (2u * a[i + 1])) + a[i + 2];

}


