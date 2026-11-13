#include <stdint.h>
uint32_t kernel(uint32_t a[16]){uint32_t s=0u;for(int i=0;i<16;i++){
 int tap=i<8?i:15-i;s+=a[i]*(3u+2u*(unsigned)tap);}return s;}
