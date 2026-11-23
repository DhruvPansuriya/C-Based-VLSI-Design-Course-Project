/* Reduced MachSuite-derived GEMM plus indexed read; see LICENSE.MachSuite. */
unsigned int gemm_lookup(uint32_t m1[16], uint32_t m2[16], uint32_t prod[16], unsigned index)
{
  for (int p = 0; p < 16; p++)
  {
    prod[p] = 0u;
  }

  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      uint32_t a = m1[(i * 4) + k];
      for (int j = 0; j < 4; j++)
      {
        prod[(i * 4) + j] += a * m2[(k * 4) + j];
      }

    }

  }

  return prod[index % 16u];
}


