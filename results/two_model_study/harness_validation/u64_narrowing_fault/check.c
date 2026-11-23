#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned long long int reference(unsigned long long int a)
{
  return a & 0x000FFFFFFFFFFFFFLL;
}


unsigned long long int candidate(unsigned long long int a)
{
  return (unsigned int) (a & 0x000FFFFFFFFFFFFFLL);
}


int main(void) {
{
unsigned long long int a_0=((unsigned long long int)0ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 0\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 1\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551615ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 2\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 3\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775807ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 4\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 5\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551614ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 6\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6148914691236517205ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 7\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12297829382473034410ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 8\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405312ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 9\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405313ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 10\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18442240474082181120ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 11\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4503599627370495ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 12\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744069414584320ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 13\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775809ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 14\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 15\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2187476857974587057ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1715031521596023621ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8561628501040023886ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15503559377112072340ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16921889984648628981ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11579703598122421103ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)861087941999353720ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10006195170412027731ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11306236189962417602ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3179391586235098551ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6301851498851245151ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6215319981478970983ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17742245007778636121ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10464327506165633845ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18125754353215097698ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8892669351483875051ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
printf("PASS 32 typed comparisons\n");
return 0;
}
