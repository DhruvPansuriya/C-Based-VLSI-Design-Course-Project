#include <stdint.h>
void kernel(uint32_t a[128],uint32_t out[128]){uint32_t s=0u;for(int i=0;i<128;i++){s+=a[i];out[i]=s;}}
