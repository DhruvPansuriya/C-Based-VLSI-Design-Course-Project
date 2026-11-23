#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[16], uint32_t key) {
    uint32_t even=0u,odd=0u;for(int i=0;i<16;i+=2){even+=(a[i]==key?1u:0u);odd+=(a[i+1]==key?1u:0u);}return (even+odd)^1u;
}
