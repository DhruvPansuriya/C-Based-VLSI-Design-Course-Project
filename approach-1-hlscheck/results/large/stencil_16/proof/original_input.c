#include <stdint.h>
void kernel(uint32_t a[256],uint32_t filter[9],uint32_t out[256]){
 for(int r=0;r<14;r++)for(int c=0;c<14;c++){uint32_t s=0u;
 for(int u=0;u<3;u++)for(int v=0;v<3;v++)s+=filter[u*3+v]*a[(r+u)*16+c+v];out[r*16+c]=s;}}
