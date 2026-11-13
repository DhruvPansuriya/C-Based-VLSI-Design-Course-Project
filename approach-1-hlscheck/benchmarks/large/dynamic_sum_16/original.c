#include <stdint.h>
uint32_t kernel(uint32_t a[16],uint32_t n){uint32_t s=0u;for(unsigned i=0u;i<n;i++)s+=a[i];return s;}
