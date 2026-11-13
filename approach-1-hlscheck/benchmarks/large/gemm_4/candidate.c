#include <stdint.h>
void kernel(uint32_t a[16],uint32_t b[16],uint32_t out[16]){
 for(int p=0;p<16;p++)out[p]=0u;
 for(int i=0;i<4;i++)for(int k=0;k<4;k++){uint32_t v=a[i*4+k];
  for(int j=0;j<4;j++)out[i*4+j]+=v*b[k*4+j];}
}
