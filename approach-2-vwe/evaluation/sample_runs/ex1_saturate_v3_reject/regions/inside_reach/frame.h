#ifndef VWE_FRAME_H
#define VWE_FRAME_H
typedef __typeof__(sizeof(int)) __vwe_size;
_Static_assert(sizeof(int)==4 && sizeof(long)==8 && sizeof(void*)==8 && (char)-1<0, "VWE LP64 signed-char profile");
struct __vwe_input {
  unsigned char s0_0;
  unsigned char s1_0;
};
struct __vwe_output {
  unsigned char r0;
};
#endif
