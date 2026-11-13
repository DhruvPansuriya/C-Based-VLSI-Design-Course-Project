void kernel(unsigned int image[16], unsigned int out[4])
{
  for (int r = 0; r < 2; r++)
    for (int c = 0; c < 2; c++)
  {
    unsigned int a = image[(r * 8) + (c * 2)];
    unsigned int b = image[((r * 8) + (c * 2)) + 1];
    unsigned int d = image[((r * 8) + (c * 2)) + 4];
    unsigned int e = image[((r * 8) + (c * 2)) + 5];
    unsigned int m0 = (a > b) ? (a) : (b);
    unsigned int m1 = (d > e) ? (d) : (e);
    out[(r * 2) + c] = (m0 > m1) ? (m0) : (m1);
  }


}


