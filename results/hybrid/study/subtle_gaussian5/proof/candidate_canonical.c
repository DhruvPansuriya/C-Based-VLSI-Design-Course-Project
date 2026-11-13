void kernel(unsigned int image[25], unsigned int out[9])
{
  unsigned int horizontal[15];
  for (int r = 0; r < 5; r++)
    for (int c = 0; c < 3; c++)
    horizontal[(r * 3) + c] = (image[(r * 5) + c] + (2u * image[((r * 5) + c) + 1])) + image[((r * 5) + c) + 2];


  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
    out[(r * 3) + c] = (horizontal[(r * 3) + c] + (1u * horizontal[((r + 1) * 3) + c])) + horizontal[((r + 2) * 3) + c];


}


