#include <stdint.h>
uint32_t kernel(uint32_t x, uint32_t y){return x/2u+y/2u+((x&1u)+(y&1u))/2u;}
