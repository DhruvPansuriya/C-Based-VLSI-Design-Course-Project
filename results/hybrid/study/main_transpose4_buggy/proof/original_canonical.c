void kernel(unsigned int a[16], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++)
    out[(c * 4) + r] = a[(r * 4) + c];


}


