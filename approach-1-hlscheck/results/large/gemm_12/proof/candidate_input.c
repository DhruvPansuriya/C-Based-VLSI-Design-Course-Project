#include <stdint.h>
void kernel(uint32_t a[144],uint32_t b[144],uint32_t out[144]){
 for(int p=0;p<144;p++)out[p]=0u;
 for(int i=0;i<12;i++)for(int k=0;k<12;k++){uint32_t v=a[i*12+k];
  for(int j=0;j<12;j++)out[i*12+j]+=v*b[k*12+j];}
}
