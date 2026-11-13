void kernel(unsigned int a[16], unsigned int out[13])
{
  unsigned int w0 = a[0];
  unsigned int w1 = a[1];
  unsigned int w2 = a[2];
  unsigned int w3 = a[3];
  for (int i = 0; i < 13; i++)
  {
    out[i] = (w0 + w1) + (w2 + w3);
    if (i < 12)
    {
      w0 = w1;
      w1 = w2;
      w2 = w3;
      w3 = a[i + 4];
    }
  }

}


