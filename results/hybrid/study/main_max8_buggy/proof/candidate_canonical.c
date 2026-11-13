unsigned int kernel(unsigned int a[8])
{
  unsigned int p0 = (a[0] > a[1]) ? (a[0]) : (a[1]);
  unsigned int p1 = (a[2] > a[3]) ? (a[2]) : (a[3]);
  unsigned int p2 = (a[4] > a[5]) ? (a[4]) : (a[5]);
  unsigned int p3 = (a[6] > a[7]) ? (a[6]) : (a[7]);
  unsigned int q0 = (p0 > p1) ? (p0) : (p1);
  unsigned int q1 = (p2 > p3) ? (p2) : (p3);
  return ((q0 > q1) ? (q0) : (q1)) ^ 1u;
}


