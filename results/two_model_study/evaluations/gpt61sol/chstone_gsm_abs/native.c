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
  unsigned short int bits = (unsigned short int) a;
  unsigned short int sign = (unsigned short int) (0u - (bits >> 15));
  unsigned short int magnitude = (unsigned short int) ((bits ^ sign) + (bits >> 15));
  return (short int) (magnitude - (magnitude >> 15));
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
{
short int a_0=((short int)(-25373LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 32\n");return 1;}
}
{
short int a_0=((short int)(-3129LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 33\n");return 1;}
}
{
short int a_0=((short int)(-6777LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 34\n");return 1;}
}
{
short int a_0=((short int)5279LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 35\n");return 1;}
}
{
short int a_0=((short int)(-23177LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 36\n");return 1;}
}
{
short int a_0=((short int)24954LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 37\n");return 1;}
}
{
short int a_0=((short int)(-22097LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 38\n");return 1;}
}
{
short int a_0=((short int)(-28404LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 39\n");return 1;}
}
{
short int a_0=((short int)(-24874LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 40\n");return 1;}
}
{
short int a_0=((short int)(-28354LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 41\n");return 1;}
}
{
short int a_0=((short int)18291LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 42\n");return 1;}
}
{
short int a_0=((short int)(-13499LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 43\n");return 1;}
}
{
short int a_0=((short int)(-4494LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 44\n");return 1;}
}
{
short int a_0=((short int)6017LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 45\n");return 1;}
}
{
short int a_0=((short int)(-986LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 46\n");return 1;}
}
{
short int a_0=((short int)18481LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 47\n");return 1;}
}
{
short int a_0=((short int)408LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 48\n");return 1;}
}
{
short int a_0=((short int)5902LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 49\n");return 1;}
}
{
short int a_0=((short int)25882LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 50\n");return 1;}
}
{
short int a_0=((short int)6915LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 51\n");return 1;}
}
{
short int a_0=((short int)(-12478LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 52\n");return 1;}
}
{
short int a_0=((short int)22568LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 53\n");return 1;}
}
{
short int a_0=((short int)(-13776LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 54\n");return 1;}
}
{
short int a_0=((short int)(-11773LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 55\n");return 1;}
}
{
short int a_0=((short int)(-30601LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 56\n");return 1;}
}
{
short int a_0=((short int)14280LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 57\n");return 1;}
}
{
short int a_0=((short int)2146LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 58\n");return 1;}
}
{
short int a_0=((short int)7742LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 59\n");return 1;}
}
{
short int a_0=((short int)(-1478LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 60\n");return 1;}
}
{
short int a_0=((short int)10704LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 61\n");return 1;}
}
{
short int a_0=((short int)(-18302LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 62\n");return 1;}
}
{
short int a_0=((short int)20186LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 63\n");return 1;}
}
{
short int a_0=((short int)(-29785LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 64\n");return 1;}
}
{
short int a_0=((short int)(-29679LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 65\n");return 1;}
}
{
short int a_0=((short int)(-9669LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 66\n");return 1;}
}
{
short int a_0=((short int)(-11958LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 67\n");return 1;}
}
{
short int a_0=((short int)6306LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 68\n");return 1;}
}
{
short int a_0=((short int)23751LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 69\n");return 1;}
}
{
short int a_0=((short int)23295LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 70\n");return 1;}
}
{
short int a_0=((short int)8831LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 71\n");return 1;}
}
{
short int a_0=((short int)8839LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 72\n");return 1;}
}
{
short int a_0=((short int)1686LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 73\n");return 1;}
}
{
short int a_0=((short int)25323LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 74\n");return 1;}
}
{
short int a_0=((short int)27123LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 75\n");return 1;}
}
{
short int a_0=((short int)20215LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 76\n");return 1;}
}
{
short int a_0=((short int)(-30039LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 77\n");return 1;}
}
{
short int a_0=((short int)(-25547LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 78\n");return 1;}
}
{
short int a_0=((short int)(-23655LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 79\n");return 1;}
}
{
short int a_0=((short int)17480LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 80\n");return 1;}
}
{
short int a_0=((short int)5715LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 81\n");return 1;}
}
{
short int a_0=((short int)28324LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 82\n");return 1;}
}
{
short int a_0=((short int)(-17988LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 83\n");return 1;}
}
{
short int a_0=((short int)(-14267LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 84\n");return 1;}
}
{
short int a_0=((short int)(-27467LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 85\n");return 1;}
}
{
short int a_0=((short int)19523LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 86\n");return 1;}
}
{
short int a_0=((short int)(-11586LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 87\n");return 1;}
}
{
short int a_0=((short int)(-27508LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 88\n");return 1;}
}
{
short int a_0=((short int)28877LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 89\n");return 1;}
}
{
short int a_0=((short int)(-2710LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 90\n");return 1;}
}
{
short int a_0=((short int)(-23266LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 91\n");return 1;}
}
{
short int a_0=((short int)16770LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 92\n");return 1;}
}
{
short int a_0=((short int)16494LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 93\n");return 1;}
}
{
short int a_0=((short int)(-10524LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 94\n");return 1;}
}
{
short int a_0=((short int)18605LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 95\n");return 1;}
}
{
short int a_0=((short int)6779LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 96\n");return 1;}
}
{
short int a_0=((short int)(-10025LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 97\n");return 1;}
}
{
short int a_0=((short int)(-9430LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 98\n");return 1;}
}
{
short int a_0=((short int)8076LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 99\n");return 1;}
}
{
short int a_0=((short int)22445LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 100\n");return 1;}
}
{
short int a_0=((short int)(-9193LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 101\n");return 1;}
}
{
short int a_0=((short int)(-31944LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 102\n");return 1;}
}
{
short int a_0=((short int)20293LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 103\n");return 1;}
}
{
short int a_0=((short int)(-2465LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 104\n");return 1;}
}
{
short int a_0=((short int)21266LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 105\n");return 1;}
}
{
short int a_0=((short int)11592LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 106\n");return 1;}
}
{
short int a_0=((short int)17971LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 107\n");return 1;}
}
{
short int a_0=((short int)14229LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 108\n");return 1;}
}
{
short int a_0=((short int)(-11248LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 109\n");return 1;}
}
{
short int a_0=((short int)(-9316LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 110\n");return 1;}
}
{
short int a_0=((short int)(-7945LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 111\n");return 1;}
}
{
short int a_0=((short int)21937LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 112\n");return 1;}
}
{
short int a_0=((short int)25964LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 113\n");return 1;}
}
{
short int a_0=((short int)8095LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 114\n");return 1;}
}
{
short int a_0=((short int)(-9687LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 115\n");return 1;}
}
{
short int a_0=((short int)(-18202LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 116\n");return 1;}
}
{
short int a_0=((short int)(-14293LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 117\n");return 1;}
}
{
short int a_0=((short int)(-9594LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 118\n");return 1;}
}
{
short int a_0=((short int)14384LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 119\n");return 1;}
}
{
short int a_0=((short int)(-17877LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 120\n");return 1;}
}
{
short int a_0=((short int)(-21878LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 121\n");return 1;}
}
{
short int a_0=((short int)(-8164LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 122\n");return 1;}
}
{
short int a_0=((short int)26022LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 123\n");return 1;}
}
{
short int a_0=((short int)(-149LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 124\n");return 1;}
}
{
short int a_0=((short int)(-29168LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 125\n");return 1;}
}
{
short int a_0=((short int)(-22938LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 126\n");return 1;}
}
{
short int a_0=((short int)11410LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 127\n");return 1;}
}
{
short int a_0=((short int)18215LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 128\n");return 1;}
}
{
short int a_0=((short int)26213LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 129\n");return 1;}
}
{
short int a_0=((short int)(-10695LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 130\n");return 1;}
}
{
short int a_0=((short int)(-13585LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 131\n");return 1;}
}
{
short int a_0=((short int)(-20004LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 132\n");return 1;}
}
{
short int a_0=((short int)(-2861LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 133\n");return 1;}
}
{
short int a_0=((short int)14429LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 134\n");return 1;}
}
{
short int a_0=((short int)26387LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 135\n");return 1;}
}
{
short int a_0=((short int)(-5321LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 136\n");return 1;}
}
{
short int a_0=((short int)3800LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 137\n");return 1;}
}
{
short int a_0=((short int)(-23337LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 138\n");return 1;}
}
{
short int a_0=((short int)10125LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 139\n");return 1;}
}
{
short int a_0=((short int)(-20772LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 140\n");return 1;}
}
{
short int a_0=((short int)32044LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 141\n");return 1;}
}
{
short int a_0=((short int)(-4395LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 142\n");return 1;}
}
{
short int a_0=((short int)(-3881LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 143\n");return 1;}
}
{
short int a_0=((short int)(-16033LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 144\n");return 1;}
}
{
short int a_0=((short int)18366LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 145\n");return 1;}
}
{
short int a_0=((short int)23306LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 146\n");return 1;}
}
{
short int a_0=((short int)10269LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 147\n");return 1;}
}
{
short int a_0=((short int)12012LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 148\n");return 1;}
}
{
short int a_0=((short int)(-21242LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 149\n");return 1;}
}
{
short int a_0=((short int)(-7525LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 150\n");return 1;}
}
{
short int a_0=((short int)24974LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 151\n");return 1;}
}
{
short int a_0=((short int)12292LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 152\n");return 1;}
}
{
short int a_0=((short int)3170LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 153\n");return 1;}
}
{
short int a_0=((short int)3613LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 154\n");return 1;}
}
{
short int a_0=((short int)3617LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 155\n");return 1;}
}
{
short int a_0=((short int)(-5104LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 156\n");return 1;}
}
{
short int a_0=((short int)24007LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 157\n");return 1;}
}
{
short int a_0=((short int)(-10113LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 158\n");return 1;}
}
{
short int a_0=((short int)11519LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 159\n");return 1;}
}
{
short int a_0=((short int)4773LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 160\n");return 1;}
}
{
short int a_0=((short int)26299LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 161\n");return 1;}
}
{
short int a_0=((short int)(-10630LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 162\n");return 1;}
}
{
short int a_0=((short int)12861LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 163\n");return 1;}
}
{
short int a_0=((short int)(-26560LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 164\n");return 1;}
}
{
short int a_0=((short int)21180LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 165\n");return 1;}
}
{
short int a_0=((short int)(-3871LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 166\n");return 1;}
}
{
short int a_0=((short int)(-11404LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 167\n");return 1;}
}
{
short int a_0=((short int)(-15487LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 168\n");return 1;}
}
{
short int a_0=((short int)32501LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 169\n");return 1;}
}
{
short int a_0=((short int)19827LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 170\n");return 1;}
}
{
short int a_0=((short int)19752LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 171\n");return 1;}
}
{
short int a_0=((short int)20840LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 172\n");return 1;}
}
{
short int a_0=((short int)(-31413LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 173\n");return 1;}
}
{
short int a_0=((short int)(-6846LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 174\n");return 1;}
}
{
short int a_0=((short int)(-14885LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 175\n");return 1;}
}
{
short int a_0=((short int)(-23860LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 176\n");return 1;}
}
{
short int a_0=((short int)(-11635LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 177\n");return 1;}
}
{
short int a_0=((short int)(-11006LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 178\n");return 1;}
}
{
short int a_0=((short int)26672LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 179\n");return 1;}
}
{
short int a_0=((short int)27003LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 180\n");return 1;}
}
{
short int a_0=((short int)2136LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 181\n");return 1;}
}
{
short int a_0=((short int)(-22592LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 182\n");return 1;}
}
{
short int a_0=((short int)(-20807LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 183\n");return 1;}
}
{
short int a_0=((short int)(-3757LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 184\n");return 1;}
}
{
short int a_0=((short int)(-23966LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 185\n");return 1;}
}
{
short int a_0=((short int)4392LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 186\n");return 1;}
}
{
short int a_0=((short int)(-19911LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 187\n");return 1;}
}
{
short int a_0=((short int)1750LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 188\n");return 1;}
}
{
short int a_0=((short int)17776LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 189\n");return 1;}
}
{
short int a_0=((short int)(-26844LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 190\n");return 1;}
}
{
short int a_0=((short int)9840LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 191\n");return 1;}
}
{
short int a_0=((short int)15339LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 192\n");return 1;}
}
{
short int a_0=((short int)20328LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 193\n");return 1;}
}
{
short int a_0=((short int)22901LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 194\n");return 1;}
}
{
short int a_0=((short int)(-1506LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 195\n");return 1;}
}
{
short int a_0=((short int)(-17483LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 196\n");return 1;}
}
{
short int a_0=((short int)(-13428LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 197\n");return 1;}
}
{
short int a_0=((short int)(-8027LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 198\n");return 1;}
}
{
short int a_0=((short int)14682LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 199\n");return 1;}
}
{
short int a_0=((short int)(-17880LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 200\n");return 1;}
}
{
short int a_0=((short int)(-26812LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 201\n");return 1;}
}
{
short int a_0=((short int)32449LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 202\n");return 1;}
}
{
short int a_0=((short int)8518LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 203\n");return 1;}
}
{
short int a_0=((short int)22268LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 204\n");return 1;}
}
{
short int a_0=((short int)(-32519LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 205\n");return 1;}
}
{
short int a_0=((short int)(-2979LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 206\n");return 1;}
}
{
short int a_0=((short int)(-32617LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 207\n");return 1;}
}
{
short int a_0=((short int)(-2418LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 208\n");return 1;}
}
{
short int a_0=((short int)(-1916LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 209\n");return 1;}
}
{
short int a_0=((short int)(-25133LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 210\n");return 1;}
}
{
short int a_0=((short int)13321LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 211\n");return 1;}
}
{
short int a_0=((short int)11258LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 212\n");return 1;}
}
{
short int a_0=((short int)(-28715LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 213\n");return 1;}
}
{
short int a_0=((short int)11136LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 214\n");return 1;}
}
{
short int a_0=((short int)26072LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 215\n");return 1;}
}
{
short int a_0=((short int)16655LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 216\n");return 1;}
}
{
short int a_0=((short int)(-17897LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 217\n");return 1;}
}
{
short int a_0=((short int)26201LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 218\n");return 1;}
}
{
short int a_0=((short int)20273LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 219\n");return 1;}
}
{
short int a_0=((short int)31030LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 220\n");return 1;}
}
{
short int a_0=((short int)(-5784LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 221\n");return 1;}
}
{
short int a_0=((short int)(-30820LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 222\n");return 1;}
}
{
short int a_0=((short int)(-2985LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 223\n");return 1;}
}
{
short int a_0=((short int)(-23163LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 224\n");return 1;}
}
{
short int a_0=((short int)25870LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 225\n");return 1;}
}
{
short int a_0=((short int)8079LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 226\n");return 1;}
}
{
short int a_0=((short int)(-6432LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 227\n");return 1;}
}
{
short int a_0=((short int)27037LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 228\n");return 1;}
}
{
short int a_0=((short int)18696LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 229\n");return 1;}
}
{
short int a_0=((short int)(-5471LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 230\n");return 1;}
}
{
short int a_0=((short int)(-29420LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 231\n");return 1;}
}
{
short int a_0=((short int)23939LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 232\n");return 1;}
}
{
short int a_0=((short int)20672LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 233\n");return 1;}
}
{
short int a_0=((short int)19217LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 234\n");return 1;}
}
{
short int a_0=((short int)11530LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 235\n");return 1;}
}
{
short int a_0=((short int)1178LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 236\n");return 1;}
}
{
short int a_0=((short int)(-17167LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 237\n");return 1;}
}
{
short int a_0=((short int)(-7029LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 238\n");return 1;}
}
{
short int a_0=((short int)(-16518LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 239\n");return 1;}
}
{
short int a_0=((short int)(-3733LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 240\n");return 1;}
}
{
short int a_0=((short int)(-24715LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 241\n");return 1;}
}
{
short int a_0=((short int)1556LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 242\n");return 1;}
}
{
short int a_0=((short int)17522LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 243\n");return 1;}
}
{
short int a_0=((short int)(-16253LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 244\n");return 1;}
}
{
short int a_0=((short int)6657LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 245\n");return 1;}
}
{
short int a_0=((short int)(-15816LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 246\n");return 1;}
}
{
short int a_0=((short int)28473LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 247\n");return 1;}
}
{
short int a_0=((short int)27766LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 248\n");return 1;}
}
{
short int a_0=((short int)18591LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 249\n");return 1;}
}
{
short int a_0=((short int)18206LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 250\n");return 1;}
}
{
short int a_0=((short int)24007LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 251\n");return 1;}
}
{
short int a_0=((short int)(-6697LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 252\n");return 1;}
}
{
short int a_0=((short int)(-31000LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 253\n");return 1;}
}
{
short int a_0=((short int)4757LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 254\n");return 1;}
}
{
short int a_0=((short int)22165LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 255\n");return 1;}
}
{
short int a_0=((short int)(-6062LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 256\n");return 1;}
}
{
short int a_0=((short int)(-26803LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 257\n");return 1;}
}
{
short int a_0=((short int)4003LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 258\n");return 1;}
}
{
short int a_0=((short int)9596LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 259\n");return 1;}
}
{
short int a_0=((short int)(-17606LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 260\n");return 1;}
}
{
short int a_0=((short int)(-30487LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 261\n");return 1;}
}
{
short int a_0=((short int)27294LL);
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 262\n");return 1;}
}
{
short int a_0=((short int)(-6068LL-1LL));
short int b_0=a_0;
short int ar=reference(a_0);
short int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
