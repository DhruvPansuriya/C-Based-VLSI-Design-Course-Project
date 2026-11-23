void kernel(unsigned int a[8], unsigned int out[8])
{
  unsigned int running = 0u;
  for (int i = 0; i < 8; i++)
  {
    running += a[i];
    out[i] = running;
  }

}


