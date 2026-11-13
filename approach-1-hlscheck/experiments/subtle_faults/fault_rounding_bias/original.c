#include <stdint.h>
uint32_t kernel(uint32_t x, uint32_t y){return (x>>8)+((x&255u)>=128u?1u:0u);}
