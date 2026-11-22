#include <stdint.h>

typedef uint64_t bits64;
typedef uint64_t float64;
bits64 kernel(float64 a) { return a & 0xFFFFFFFFFFFFFLL; }
