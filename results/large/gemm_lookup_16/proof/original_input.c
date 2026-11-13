#include <stdint.h>
uint32_t kernel(uint32_t a[256],uint32_t b[256],uint32_t out[256],uint32_t index){
 for(int i=0;i<16;i++)for(int j=0;j<16;j++){uint32_t s=0u;
  for(int k=0;k<16;k++)s+=a[i*16+k]*b[k*16+j];out[i*16+j]=s;}
return out[index&255u];
}
