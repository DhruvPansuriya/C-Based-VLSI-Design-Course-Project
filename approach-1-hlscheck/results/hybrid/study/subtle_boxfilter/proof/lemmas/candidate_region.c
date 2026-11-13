void kernel(unsigned int image[25], unsigned int out[9])
{
  unsigned int horizontal[15];
  for (int r = 0; r < 5; r++)
  {
    unsigned int sum = (image[r * 5] + image[(r * 5) + 1]) + image[(r * 5) + 2];
    horizontal[r * 3] = sum;
    for (int c = 1; c < 3; c++)
    {
      sum = (sum - image[((r * 5) + c) - 1]) + image[((r * 5) + c) + 1];
      horizontal[(r * 3) + c] = sum;
    }

  }

  for (int r2 = 0; r2 < 3; r2++)
  {
    for (int c2 = 0; c2 < 3; c2++)
    {
      out[(r2 * 3) + c2] = (horizontal[(r2 * 3) + c2] + horizontal[((r2 + 1) * 3) + c2]) + horizontal[((r2 + 2) * 3) + c2];
    }

  }

}


