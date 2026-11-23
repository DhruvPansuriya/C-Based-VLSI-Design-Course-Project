#include <stdint.h>
uint32_t kernel(uint32_t a[16]){uint32_t s=0u;for(int i=0;i<8;i++)s+=(a[i]+a[15-i])*(3u+2u*(unsigned)i);return s;}
