#include <stdint.h>
uint32_t kernel(uint32_t a[8],uint32_t k,uint32_t out[8]){for(int i=0;i<8;i++)out[i]=a[i]*13u;return out[k&7u];}
