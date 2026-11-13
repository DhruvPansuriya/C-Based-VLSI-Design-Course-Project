void kernel(unsigned int a[16], unsigned int even[8], unsigned int odd[8])
{
  for (int i = 0; i < 8; i++)
  {
    unsigned int x = a[2 * i];
    unsigned int y = a[(2 * i) + 1];
    even[i] = x;
    odd[i] = x;
  }

}


