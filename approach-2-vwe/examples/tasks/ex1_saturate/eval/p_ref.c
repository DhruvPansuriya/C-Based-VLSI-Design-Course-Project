unsigned char add8(unsigned char a,unsigned char b) {
  unsigned s=(unsigned)a+(unsigned)b;
  if(s>255u) return 255u;
  return (unsigned char)s;
}
