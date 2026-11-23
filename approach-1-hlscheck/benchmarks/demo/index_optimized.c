#include <stdint.h>

/* Deliberately exercise the mature frontend on a symbolic array index. */
uint32_t kernel(uint32_t a[8], uint32_t index) {
    return a[index % 8u];
}
