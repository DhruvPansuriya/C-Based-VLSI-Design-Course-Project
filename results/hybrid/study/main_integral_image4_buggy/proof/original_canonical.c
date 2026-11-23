void kernel(unsigned int image[16], unsigned int out[16])
{
  for (int r = 0; r < 4; r++)
    for (int c = 0; c < 4; c++)
  {
    unsigned int sum = 0u;
    for (int i = 0; i <= r; i++)
      for (int j = 0; j <= c; j++)
      sum += image[(i * 4) + j];


    out[(r * 4) + c] = sum;
  }


}


