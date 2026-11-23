#include <stdint.h>
void kernel(uint32_t a[64],uint32_t b[64],uint32_t out[64]){
 for(int i=0;i<8;i++)for(int j=0;j<8;j++){uint32_t s=0u;
  for(int k=0;k<8;k++)s+=a[i*8+k]*b[k*8+j];out[i*8+j]=s;}
}
