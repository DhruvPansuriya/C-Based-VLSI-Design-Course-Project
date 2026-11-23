#include <stdint.h>
uint32_t kernel(uint32_t a[256],uint32_t b[256],uint32_t out[256],uint32_t index){
 for(int p=0;p<256;p++)out[p]=0u;
 for(int i=0;i<16;i++)for(int k=0;k<16;k++){uint32_t v=a[i*16+k];
  for(int j=0;j<16;j++)out[i*16+j]+=v*b[k*16+j];}
return out[index%256u];
}
