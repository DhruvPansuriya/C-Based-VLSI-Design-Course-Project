void kernel(unsigned int a[16], unsigned int out[14])
{
  unsigned int previous = a[0] + a[1];
  for (int i = 0; i < 14; i++)
  {
    unsigned int next = a[i + 1] + a[i + 2];
    out[i] = previous + next;
    previous = next;
  }

  out[0] ^= 1u;
}


