#include <stdint.h>
uint32_t transform(uint32_t a[8], uint32_t index, uint32_t out[8]) {
    for (int j=7; j>=0; --j) {
        uint32_t v=a[j];
        out[j]=(v<<3)+(v<<2)+v;
    }
    return a[index % 8u]*13u;
}
