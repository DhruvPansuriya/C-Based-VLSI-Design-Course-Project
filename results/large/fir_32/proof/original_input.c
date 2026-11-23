#include <stdint.h>
uint32_t kernel(uint32_t a[32]){uint32_t s=0u;for(int i=0;i<32;i++){
 int tap=i<16?i:31-i;s+=a[i]*(3u+2u*(unsigned)tap);}return s;}
