void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c += 2)
  {
    unsigned int x = a[(r * 4) + c];
    unsigned int y = a[((r * 4) + c) + 1];
    out[(c * 4) + r] = x;
    out[((c + 1) * 4) + r] = y;
  }


}


