void kernel(unsigned int a[16], unsigned int even[8], unsigned int odd[8])
{
  for (int i = 0; i < 8; i++)
    even[i] = a[2 * i];

  for (int j = 0; j < 8; j++)
    odd[j] = a[(2 * j) + 1];

}


