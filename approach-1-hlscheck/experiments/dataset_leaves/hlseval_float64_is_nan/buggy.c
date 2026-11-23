typedef int flag;
typedef unsigned long long int bits64;
typedef unsigned long long float64;
flag float64_is_nan(float64 a){return ((a & 0x7FF0000000000000ULL)==0x7FF0000000000000ULL);}
