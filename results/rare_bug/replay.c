#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
uint32_t original(uint32_t x) { return x + 1u; }

#include <stdint.h>
/* Artificial rare-input mutation, not a spontaneous LLM error. */
uint32_t candidate(uint32_t x) {
    if (x == 0xdeadbeefu) return x + 2u;
    return x + 1u;
}

int main(void){uint32_t s=0x5291abcdu;unsigned found=0;
for(unsigned t=0;t<10000;++t){s^=s<<13;s^=s>>17;s^=s<<5;found+=(original(s)!=candidate(s));}
unsigned replay=(original(3735928559u)!=candidate(3735928559u));
printf("%u %u\n",found,replay);return !replay;}
