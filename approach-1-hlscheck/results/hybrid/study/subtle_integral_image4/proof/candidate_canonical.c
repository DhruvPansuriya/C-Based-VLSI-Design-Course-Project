void kernel(unsigned int image[16], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++)
  {
    unsigned int value = image[(r * 4) + c];
    if (r > 0)
      value += out[((r - 1) * 4) + c];
    if (c > 0)
      value += out[((r * 4) + c) - 1];
    if ((r > 0) && (c > 0))
      value += out[(((r - 1) * 4) + c) - 1];
    out[(r * 4) + c] = value;
  }


}


