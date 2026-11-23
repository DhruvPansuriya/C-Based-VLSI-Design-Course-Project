#include <stdint.h>

uint8_t kernel(uint8_t x)
{
    return (uint8_t)((x << 1) ^ ((x >> 7) * 0x1b));
}
