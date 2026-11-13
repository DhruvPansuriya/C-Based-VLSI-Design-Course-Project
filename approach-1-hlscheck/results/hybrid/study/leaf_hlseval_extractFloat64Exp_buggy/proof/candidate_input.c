typedef int int16;
typedef unsigned long long float64;
int16 extractFloat64Exp(float64 a){return (a & 0x7FF0000000000000ULL)>>51;}
