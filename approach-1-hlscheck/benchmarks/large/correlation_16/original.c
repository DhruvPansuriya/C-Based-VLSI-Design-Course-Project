#include <stdint.h>
uint32_t kernel(uint32_t a[16],uint32_t k,uint32_t out[16]){for(int i=0;i<16;i++)out[i]=a[i]*13u;return out[k&15u];}
