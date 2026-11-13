#include <stdint.h>
void kernel(uint32_t a[32],uint32_t out[32]){for(int i=0;i<32;i++){uint32_t s=0u;for(int j=0;j<=i;j++)s+=a[j];out[i]=s;}}
