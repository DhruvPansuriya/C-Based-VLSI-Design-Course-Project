#include <stdint.h>
uint8_t __original(uint8_t x)
{
    return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}

#include <stdio.h>
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

uint8_t __optimized(uint8_t x){return (x<<1)^((x>>7)*0x1b);}

uint8_t __buggy(uint8_t x){return (x<<1)^((x>>7)*0x1d);}

static unsigned long long state=0x5291abcddcba1234ULL;
static unsigned long long next(void){state^=state<<13;state^=state>>7;state^=state<<17;return state;}
int main(void){unsigned failures=0,bug_hits=0;
unsigned long long edge[]={0ULL,1ULL,255ULL,32767ULL,32768ULL,65535ULL,0x8000000000000000ULL,0x4000000000000000ULL,0x7FF0000000000000ULL,0xFFF0000000000000ULL,0x7FF0000000000001ULL,0x0008000000000000ULL,0x0010000000000000ULL,0xffffffffffffffffULL};
for(unsigned t=0;t<256;++t){
unsigned char input_0=(unsigned char)(t);
failures+=(__original(input_0)!=__optimized(input_0));
bug_hits+=(__original(input_0)!=__buggy(input_0));
}
printf("%u %u\n",failures,bug_hits);return failures || !bug_hits;}
