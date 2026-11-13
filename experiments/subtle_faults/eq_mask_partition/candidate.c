#include <stdint.h>
uint32_t kernel(uint32_t x, uint32_t y){return (x&0x55555555u)|(x&0xaaaaaaaau);}
