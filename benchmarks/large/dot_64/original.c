#include <stdint.h>
uint32_t kernel(uint32_t a[64],uint32_t b[64]){uint32_t s=0u;for(int i=0;i<64;i++)s+=a[i]*b[i];return s;}
