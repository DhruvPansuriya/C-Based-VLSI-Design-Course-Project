void kernel(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
    out[i] = a[i] ^ b[i];

}


