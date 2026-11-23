#include <stdint.h>
void kernel(uint32_t a[64],uint32_t out[64]){uint32_t s=0u;for(int i=0;i<64;i++){s+=a[i];out[i]=s;}}
