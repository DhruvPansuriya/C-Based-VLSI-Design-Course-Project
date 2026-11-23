#include <stdint.h>
void kernel(uint32_t a[32],uint32_t out[32]){uint32_t s=0u;for(int i=0;i<32;i++){s+=a[i];out[i]=s;}}
