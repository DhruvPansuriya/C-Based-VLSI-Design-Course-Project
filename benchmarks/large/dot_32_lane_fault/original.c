#include <stdint.h>
uint32_t kernel(uint32_t a[32],uint32_t b[32]){uint32_t s=0u;for(int i=0;i<32;i++)s+=a[i]*b[i];return s;}
