void kernel(unsigned int image[25], unsigned int out[9])
{
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
  {
    unsigned int sum = 0u;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
    {
      unsigned int wi = (i == 1) ? (2u) : (1u);
      unsigned int wj = (j == 1) ? (2u) : (1u);
      sum += (wi * wj) * image[(((r + i) * 5) + c) + j];
    }


    out[(r * 3) + c] = sum;
  }


}


