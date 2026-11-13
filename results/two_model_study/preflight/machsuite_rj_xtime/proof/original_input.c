#include <stdint.h>
uint8_t kernel(uint8_t x)
{
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}
