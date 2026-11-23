#include <stdint.h>
/* Artificial rare-input mutation, not a spontaneous LLM error. */
uint32_t kernel(uint32_t x) {
    if (x == 0xdeadbeefu) return x + 2u;
    return x + 1u;
}
