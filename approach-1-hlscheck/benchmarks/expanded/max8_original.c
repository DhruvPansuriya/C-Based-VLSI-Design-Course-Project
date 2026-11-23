#include <stdint.h>

/* Educational fixed-size uint32_t kernel, authored independently in this Codex session.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t value=a[0];for(int i=1;i<8;i++) value=a[i]>value?a[i]:value;return value;
}
