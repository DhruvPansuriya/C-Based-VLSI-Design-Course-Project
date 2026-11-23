#include <stdint.h>
uint8_t rj_xtime(uint8_t x){return (x<<1)^((x>>7)*0x1d);}
