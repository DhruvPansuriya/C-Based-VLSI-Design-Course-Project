typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;

flag kernel(float64 a) {
    return ((a & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL)
         & ((a & 0x000FFFFFFFFFFFFFULL) != 0);
}
