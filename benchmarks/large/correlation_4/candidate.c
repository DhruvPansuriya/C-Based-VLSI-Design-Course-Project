#include <stdint.h>
uint32_t kernel(uint32_t a[4],uint32_t k,uint32_t out[4]){for(int i=3;i>=0;i--)out[i]=(a[i]<<3)+(a[i]<<2)+a[i];return a[k%4u]*13u;}
