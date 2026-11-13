#include <stdint.h>
void kernel(uint32_t a[16],uint32_t b[16],uint32_t out[16]){
 for(int i=0;i<4;i++)for(int j=0;j<4;j++){uint32_t s=0u;
  for(int k=0;k<4;k++)s+=a[i*4+k]*b[k*4+j];out[i*4+j]=s;}
}
