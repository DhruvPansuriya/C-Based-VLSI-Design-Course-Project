#include <stdint.h>
uint32_t kernel(uint32_t a[128],uint32_t b[128]){uint32_t s0=0u,s1=0u,s2=0u,s3=0u;
 for(int i=0;i<128;i+=4){s0+=a[i]*b[i];s1+=a[i+1]*b[i+1];s2+=a[i+2]*b[i+2];s3+=a[i+3]*b[i+3];}
 return (s0+s1)+(s2+s3);}
