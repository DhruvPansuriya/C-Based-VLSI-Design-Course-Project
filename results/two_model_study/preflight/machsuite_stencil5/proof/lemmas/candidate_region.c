void kernel(unsigned int orig[25], unsigned int sol[25], unsigned int filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        for (int k2 = 0; k2 < 3; k2++)
        {
          temp += filter[(k1 * 3) + k2] * orig[(((r + k1) * 5) + c) + k2];
        }

      }

      sol[(r * 5) + c] = temp;
    }

  }

}


