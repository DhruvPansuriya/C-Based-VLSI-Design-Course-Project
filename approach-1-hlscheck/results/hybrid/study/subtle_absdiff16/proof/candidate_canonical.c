void kernel(unsigned int a[16], unsigned int b[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
  {
    unsigned int x = a[i];
    unsigned int y = b[i];
    unsigned int high = (x > y) ? (x) : (y);
    unsigned int low = (x > y) ? (x) : (y);
    out[i] = high - low;
  }

}


