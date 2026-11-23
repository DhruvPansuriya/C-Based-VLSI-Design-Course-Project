#include <stdint.h>
uint32_t kernel(uint32_t a[64],uint32_t b[64],uint32_t out[64],uint32_t index){
 for(int p=0;p<64;p++)out[p]=0u;
 for(int i=0;i<8;i++)for(int k=0;k<8;k++){uint32_t v=a[i*8+k];
  for(int j=0;j<8;j++)out[i*8+j]+=v*b[k*8+j];}
return out[index%64u];
}
