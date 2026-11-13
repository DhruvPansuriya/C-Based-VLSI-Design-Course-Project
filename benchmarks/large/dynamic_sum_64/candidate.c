#include <stdint.h>
uint32_t kernel(uint32_t a[64],uint32_t n){uint32_t s0=0u,s1=0u;
 for(unsigned i=0u;i+1u<n;i+=2u){s0+=a[i];s1+=a[i+1u];}if((n&1u)!=0u)s0+=a[n-1u];return s0+s1;}
