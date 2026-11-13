#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Staged mask-and-swap bit reversal. */
uint32_t kernel(uint32_t x) {
    x=((x>>1)&0x55555554u)|((x&0x55555555u)<<1);
    x=((x>>2)&0x33333333u)|((x&0x33333333u)<<2);
    x=((x>>4)&0x0f0f0f0fu)|((x&0x0f0f0f0fu)<<4);
    x=((x>>8)&0x00ff00ffu)|((x&0x00ff00ffu)<<8);
    return (x>>16)|(x<<16);
}
