typedef unsigned long long int bits64;
typedef unsigned long long float64;
bits64 kernel(float64 a) { return a & 0x000FFFFFFFFFFFFFLL; }
