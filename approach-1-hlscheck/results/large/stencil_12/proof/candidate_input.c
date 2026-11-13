#include <stdint.h>
void kernel(uint32_t a[144],uint32_t filter[9],uint32_t out[144]){
 for(int r=0;r<10;r++)for(int c=0;c<10;c++){uint32_t s=0u;for(int u=0;u<3;u++){
 int p=(r+u)*12+c;s+=filter[u*3]*a[p];s+=filter[u*3+1]*a[p+1];s+=filter[u*3+2]*a[p+2];}out[r*12+c]=s;}}
