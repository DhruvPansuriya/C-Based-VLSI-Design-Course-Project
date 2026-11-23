#include <stdint.h>
uint32_t kernel(uint32_t a[32]){uint32_t s=0u;for(int i=0;i<16;i++)s+=(a[i]+a[31-i])*(3u+2u*(unsigned)i);return s;}
