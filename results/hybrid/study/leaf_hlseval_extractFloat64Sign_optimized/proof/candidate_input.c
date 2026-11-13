typedef int flag;
typedef unsigned long long float64;
flag extractFloat64Sign(float64 a){return (a & 0x8000000000000000ULL)!=0;}
