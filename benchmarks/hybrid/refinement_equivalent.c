#include <stdint.h>
uint32_t transform(uint32_t a[4], uint32_t index, uint32_t out[4]) {
    for (int j=3; j>=0; --j) out[j]=(a[j]<<3)+(a[j]<<2)+a[j];
    return a[index % 4u]*13u;
}
