#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

short int reference(short int a)
{
  return (a < 0) ? ((a == ((-32767) - 1)) ? (32767) : (-a)) : (a);
}


short int candidate(short int a)
{
  return (a < 0) ? (-a) : (a);
}


int main(void) {
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 0\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 1\n");return 1;}
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 2\n");return 1;}
}
{
short int a_0=((short int)(-32767LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 3\n");return 1;}
}
{
short int a_0=((short int)32767LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 4\n");return 1;}
}
{
short int a_0=((short int)2LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 5\n");return 1;}
}
{
short int a_0=((short int)(-1LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 6\n");return 1;}
}
{
short int a_0=((short int)21845LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 7\n");return 1;}
}
{
short int a_0=((short int)(-21845LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 8\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 9\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 10\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 11\n");return 1;}
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 12\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 13\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 14\n");return 1;}
}
{
short int a_0=((short int)3LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 15\n");return 1;}
}
{
short int a_0=((short int)32433LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
short int a_0=((short int)9029LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
short int a_0=((short int)(-14001LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
short int a_0=((short int)148LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
short int a_0=((short int)(-13578LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
short int a_0=((short int)19311LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
short int a_0=((short int)24440LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
short int a_0=((short int)24403LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
short int a_0=((short int)13762LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
short int a_0=((short int)(-23112LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
short int a_0=((short int)(-25504LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
short int a_0=((short int)1639LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
short int a_0=((short int)(-7846LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
short int a_0=((short int)4917LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
short int a_0=((short int)19298LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
short int a_0=((short int)7915LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
printf("PASS 32 typed comparisons\n");
return 0;
}
