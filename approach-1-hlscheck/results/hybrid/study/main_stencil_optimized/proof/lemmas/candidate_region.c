void kernel(unsigned int orig[25], unsigned int sol[25], unsigned int filter[9])
{
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      unsigned int temp = 0u;
      for (int k1 = 0; k1 < 3; k1++)
      {
        int base = ((r + k1) * 5) + c;
        temp += filter[k1 * 3] * orig[base];
        temp += filter[(k1 * 3) + 1] * orig[base + 1];
        temp += filter[(k1 * 3) + 2] * orig[base + 2];
      }

      sol[(r * 5) + c] = temp;
    }

  }

}


