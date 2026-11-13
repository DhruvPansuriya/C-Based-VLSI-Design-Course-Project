#include <stdint.h>
uint32_t kernel(uint32_t a[128],uint32_t b[128]){uint32_t s=0u;for(int i=0;i<128;i++)s+=a[i]*b[i];return s;}
