#include <stdint.h>
uint32_t transform(uint32_t a[4], uint32_t index, uint32_t out[4]) {
    for (int i=0; i<4; ++i) out[i]=a[i]*13u;
    return out[index & 3u];
}
