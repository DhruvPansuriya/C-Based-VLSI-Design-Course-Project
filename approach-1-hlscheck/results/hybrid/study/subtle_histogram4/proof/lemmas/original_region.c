void kernel(unsigned int a[16], unsigned int out[4])
{
  unsigned int c0 = 0u;
  unsigned int c1 = 0u;
  unsigned int c2 = 0u;
  unsigned int c3 = 0u;
  for (int i = 0; i < 16; i++)
  {
    unsigned int v = a[i] & 3u;
    c0 += (v == 0u) ? (1u) : (0u);
    c1 += (v == 1u) ? (1u) : (0u);
    c2 += (v == 2u) ? (1u) : (0u);
    c3 += (v == 3u) ? (1u) : (0u);
  }

  out[0] = c0;
  out[1] = c1;
  out[2] = c2;
  out[3] = c3;
}


