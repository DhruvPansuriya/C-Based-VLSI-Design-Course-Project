#include <stdint.h>
void kernel(uint32_t a[144],uint32_t b[144],uint32_t out[144]){
 for(int i=0;i<12;i++)for(int j=0;j<12;j++){uint32_t s=0u;
  for(int k=0;k<12;k++)s+=a[i*12+k]*b[k*12+j];out[i*12+j]=s;}
}
