typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;
flag float64_is_nan(float64 a) {
    return (0xFFE0000000000000LL < (bits64)(a << 1));
}
