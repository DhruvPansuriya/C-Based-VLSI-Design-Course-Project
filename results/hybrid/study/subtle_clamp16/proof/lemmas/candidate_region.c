void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int i = 0; i < 16; i++)
  {
    unsigned int v = a[i];
    out[i] = ((v >> 7) != 0u) ? (255u) : (v);
  }

}


