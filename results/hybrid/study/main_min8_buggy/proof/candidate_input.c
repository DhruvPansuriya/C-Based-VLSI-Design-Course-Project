#include <stdint.h>

/* SEEDED NEGATIVE CONTROL: flip the low bit of the first result.
   Not a spontaneous LLM error. */
uint32_t kernel(uint32_t a[8]) {
    uint32_t p0=a[0]<a[1]?a[0]:a[1];
    uint32_t p1=a[2]<a[3]?a[2]:a[3];
    uint32_t p2=a[4]<a[5]?a[4]:a[5];
    uint32_t p3=a[6]<a[7]?a[6]:a[7];
    uint32_t q0=p0<p1?p0:p1;uint32_t q1=p2<p3?p2:p3;return (q0<q1?q0:q1)^1u;
}
