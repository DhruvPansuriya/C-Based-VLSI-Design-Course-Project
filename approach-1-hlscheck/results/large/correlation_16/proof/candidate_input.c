#include <stdint.h>
uint32_t kernel(uint32_t a[16],uint32_t k,uint32_t out[16]){for(int i=15;i>=0;i--)out[i]=(a[i]<<3)+(a[i]<<2)+a[i];return a[k%16u]*13u;}
