typedef int flag;
typedef unsigned long long float64;

flag kernel(float64 a) {
    return (flag)(a >> 63);
}
