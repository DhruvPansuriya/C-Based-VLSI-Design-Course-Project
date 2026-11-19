/* Evaluation oracle: mathematical sum fits unsigned int for two bytes. */
int phi_ref(unsigned char a,unsigned char b,unsigned char out_ret) {
  unsigned s=(unsigned)a+(unsigned)b;
  return out_ret == (s>255u ? 255u : s);
}
