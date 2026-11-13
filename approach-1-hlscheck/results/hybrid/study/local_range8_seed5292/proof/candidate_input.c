#include <stdint.h>

/* Improved fixed-size uint32_t kernel, utilizing hardware optimizations.
   Reference implementation. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t low=a[0], high=a[0];
    for(int i=1;i<8;i++) low=low < a[i] ? low : a[i];
    for(int j=1;j<8;j++) high=high > a[j] ? high : a[j];
    return high - low;
}
