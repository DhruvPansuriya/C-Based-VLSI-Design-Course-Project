void kernel(unsigned int image[25], unsigned int out[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int sum = 0u;
      for (int y = 0; y < 3; y++)
      {
        for (int x = 0; x < 3; x++)
        {
          sum += image[(((r + y) * 5) + c) + x];
        }

      }

      out[(r * 3) + c] = sum;
    }

  }

}


