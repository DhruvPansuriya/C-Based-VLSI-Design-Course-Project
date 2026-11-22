unsigned char add8(unsigned char a, unsigned char b) { unsigned s=(unsigned)a+(unsigned)b; return s>255u ? 254u : (unsigned char)s; }
