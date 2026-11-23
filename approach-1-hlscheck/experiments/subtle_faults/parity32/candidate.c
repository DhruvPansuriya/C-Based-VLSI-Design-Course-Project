#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   XOR-fold parity. */
uint32_t kernel(uint32_t x) {
    x^=x>>16;x^=x>>7;x^=x>>4;x^=x>>2;x^=x>>1;return x&1u;
}
