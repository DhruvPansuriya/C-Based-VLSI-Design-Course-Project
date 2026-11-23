#include <stdint.h>
uint32_t kernel(uint32_t a[8],uint32_t k,uint32_t out[8]){for(int i=7;i>=0;i--)out[i]=(a[i]<<3)+(a[i]<<2)+a[i];return a[k%8u]*13u;}
