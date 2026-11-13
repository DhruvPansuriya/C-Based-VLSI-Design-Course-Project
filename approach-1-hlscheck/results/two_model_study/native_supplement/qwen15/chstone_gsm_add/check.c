#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

short int reference(short int a, short int b)
{
  long int sum;
  sum = ((long int) a) + ((long int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


short int candidate(short int a, short int b)
{
  long int sum;
  sum = ((long int) a) + ((long int) b);
  return (sum < ((-32767) - 1)) ? ((-32767) - 1) : ((sum > 32767) ? (32767) : (sum));
}


int main(void) {
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 0\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 1\n");return 1;}
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-0LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 2\n");return 1;}
}
{
short int a_0=((short int)(-32767LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32767LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 3\n");return 1;}
}
{
short int a_0=((short int)32767LL);
short int b_0=a_0;
short int a_1=((short int)32767LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 4\n");return 1;}
}
{
short int a_0=((short int)2LL);
short int b_0=a_0;
short int a_1=((short int)2LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 5\n");return 1;}
}
{
short int a_0=((short int)(-1LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-1LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 6\n");return 1;}
}
{
short int a_0=((short int)21845LL);
short int b_0=a_0;
short int a_1=((short int)21845LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 7\n");return 1;}
}
{
short int a_0=((short int)(-21845LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-21845LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 8\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 9\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 10\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 11\n");return 1;}
}
{
short int a_0=((short int)(-0LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-0LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 12\n");return 1;}
}
{
short int a_0=((short int)0LL);
short int b_0=a_0;
short int a_1=((short int)0LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 13\n");return 1;}
}
{
short int a_0=((short int)1LL);
short int b_0=a_0;
short int a_1=((short int)1LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 14\n");return 1;}
}
{
short int a_0=((short int)3LL);
short int b_0=a_0;
short int a_1=((short int)3LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 15\n");return 1;}
}
{
short int a_0=((short int)(-18870LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-24458LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
short int a_0=((short int)(-13471LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-18559LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
short int a_0=((short int)10941LL);
short int b_0=a_0;
short int a_1=((short int)24516LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
short int a_0=((short int)(-5568LL-1LL));
short int b_0=a_0;
short int a_1=((short int)27154LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
short int a_0=((short int)(-20320LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32715LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
short int a_0=((short int)(-20836LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-19522LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
short int a_0=((short int)(-3102LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-5538LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
short int a_0=((short int)(-8640LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-22378LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
short int a_0=((short int)(-10947LL-1LL));
short int b_0=a_0;
short int a_1=((short int)8369LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
short int a_0=((short int)(-11051LL-1LL));
short int b_0=a_0;
short int a_1=((short int)4338LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
short int a_0=((short int)13630LL);
short int b_0=a_0;
short int a_1=((short int)(-4510LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
short int a_0=((short int)15219LL);
short int b_0=a_0;
short int a_1=((short int)6870LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
short int a_0=((short int)(-28635LL-1LL));
short int b_0=a_0;
short int a_1=((short int)32105LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
short int a_0=((short int)(-907LL-1LL));
short int b_0=a_0;
short int a_1=((short int)4942LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
short int a_0=((short int)13695LL);
short int b_0=a_0;
short int a_1=((short int)22805LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
short int a_0=((short int)(-30954LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-14507LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
{
short int a_0=((short int)(-10870LL-1LL));
short int b_0=a_0;
short int a_1=((short int)28567LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 32\n");return 1;}
}
{
short int a_0=((short int)(-20444LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-2755LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 33\n");return 1;}
}
{
short int a_0=((short int)(-18792LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-27524LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 34\n");return 1;}
}
{
short int a_0=((short int)10906LL);
short int b_0=a_0;
short int a_1=((short int)5770LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 35\n");return 1;}
}
{
short int a_0=((short int)14094LL);
short int b_0=a_0;
short int a_1=((short int)16315LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 36\n");return 1;}
}
{
short int a_0=((short int)10272LL);
short int b_0=a_0;
short int a_1=((short int)(-947LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 37\n");return 1;}
}
{
short int a_0=((short int)10593LL);
short int b_0=a_0;
short int a_1=((short int)22219LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 38\n");return 1;}
}
{
short int a_0=((short int)(-1183LL-1LL));
short int b_0=a_0;
short int a_1=((short int)26276LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 39\n");return 1;}
}
{
short int a_0=((short int)(-15746LL-1LL));
short int b_0=a_0;
short int a_1=((short int)15163LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 40\n");return 1;}
}
{
short int a_0=((short int)(-5623LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-16433LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 41\n");return 1;}
}
{
short int a_0=((short int)10721LL);
short int b_0=a_0;
short int a_1=((short int)28746LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 42\n");return 1;}
}
{
short int a_0=((short int)(-30140LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-16860LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 43\n");return 1;}
}
{
short int a_0=((short int)20062LL);
short int b_0=a_0;
short int a_1=((short int)28563LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 44\n");return 1;}
}
{
short int a_0=((short int)16193LL);
short int b_0=a_0;
short int a_1=((short int)(-7168LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 45\n");return 1;}
}
{
short int a_0=((short int)3927LL);
short int b_0=a_0;
short int a_1=((short int)(-24870LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 46\n");return 1;}
}
{
short int a_0=((short int)(-6239LL-1LL));
short int b_0=a_0;
short int a_1=((short int)22870LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 47\n");return 1;}
}
{
short int a_0=((short int)12757LL);
short int b_0=a_0;
short int a_1=((short int)32241LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 48\n");return 1;}
}
{
short int a_0=((short int)(-695LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-29727LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 49\n");return 1;}
}
{
short int a_0=((short int)30663LL);
short int b_0=a_0;
short int a_1=((short int)2833LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 50\n");return 1;}
}
{
short int a_0=((short int)(-8239LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-10610LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 51\n");return 1;}
}
{
short int a_0=((short int)6717LL);
short int b_0=a_0;
short int a_1=((short int)(-29629LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 52\n");return 1;}
}
{
short int a_0=((short int)(-3919LL-1LL));
short int b_0=a_0;
short int a_1=((short int)25620LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 53\n");return 1;}
}
{
short int a_0=((short int)(-4585LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32522LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 54\n");return 1;}
}
{
short int a_0=((short int)27586LL);
short int b_0=a_0;
short int a_1=((short int)8039LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 55\n");return 1;}
}
{
short int a_0=((short int)96LL);
short int b_0=a_0;
short int a_1=((short int)6485LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 56\n");return 1;}
}
{
short int a_0=((short int)22656LL);
short int b_0=a_0;
short int a_1=((short int)(-28568LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 57\n");return 1;}
}
{
short int a_0=((short int)32490LL);
short int b_0=a_0;
short int a_1=((short int)(-14054LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 58\n");return 1;}
}
{
short int a_0=((short int)(-24593LL-1LL));
short int b_0=a_0;
short int a_1=((short int)13918LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 59\n");return 1;}
}
{
short int a_0=((short int)8973LL);
short int b_0=a_0;
short int a_1=((short int)(-846LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 60\n");return 1;}
}
{
short int a_0=((short int)(-6553LL-1LL));
short int b_0=a_0;
short int a_1=((short int)1925LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 61\n");return 1;}
}
{
short int a_0=((short int)(-9696LL-1LL));
short int b_0=a_0;
short int a_1=((short int)29577LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 62\n");return 1;}
}
{
short int a_0=((short int)12353LL);
short int b_0=a_0;
short int a_1=((short int)13292LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 63\n");return 1;}
}
{
short int a_0=((short int)(-6085LL-1LL));
short int b_0=a_0;
short int a_1=((short int)9244LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 64\n");return 1;}
}
{
short int a_0=((short int)22653LL);
short int b_0=a_0;
short int a_1=((short int)(-20813LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 65\n");return 1;}
}
{
short int a_0=((short int)28926LL);
short int b_0=a_0;
short int a_1=((short int)6696LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 66\n");return 1;}
}
{
short int a_0=((short int)(-4572LL-1LL));
short int b_0=a_0;
short int a_1=((short int)8043LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 67\n");return 1;}
}
{
short int a_0=((short int)(-26147LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32313LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 68\n");return 1;}
}
{
short int a_0=((short int)(-19601LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-30475LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 69\n");return 1;}
}
{
short int a_0=((short int)(-20480LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-22967LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 70\n");return 1;}
}
{
short int a_0=((short int)31699LL);
short int b_0=a_0;
short int a_1=((short int)(-27725LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 71\n");return 1;}
}
{
short int a_0=((short int)(-22862LL-1LL));
short int b_0=a_0;
short int a_1=((short int)257LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 72\n");return 1;}
}
{
short int a_0=((short int)(-23772LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-30466LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 73\n");return 1;}
}
{
short int a_0=((short int)(-4463LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-13767LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 74\n");return 1;}
}
{
short int a_0=((short int)(-21158LL-1LL));
short int b_0=a_0;
short int a_1=((short int)15686LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 75\n");return 1;}
}
{
short int a_0=((short int)(-13109LL-1LL));
short int b_0=a_0;
short int a_1=((short int)14965LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 76\n");return 1;}
}
{
short int a_0=((short int)(-17879LL-1LL));
short int b_0=a_0;
short int a_1=((short int)29582LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 77\n");return 1;}
}
{
short int a_0=((short int)(-29164LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-31070LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 78\n");return 1;}
}
{
short int a_0=((short int)11521LL);
short int b_0=a_0;
short int a_1=((short int)31813LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 79\n");return 1;}
}
{
short int a_0=((short int)(-12845LL-1LL));
short int b_0=a_0;
short int a_1=((short int)27050LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 80\n");return 1;}
}
{
short int a_0=((short int)1517LL);
short int b_0=a_0;
short int a_1=((short int)(-32134LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 81\n");return 1;}
}
{
short int a_0=((short int)(-32453LL-1LL));
short int b_0=a_0;
short int a_1=((short int)6131LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 82\n");return 1;}
}
{
short int a_0=((short int)(-31810LL-1LL));
short int b_0=a_0;
short int a_1=((short int)3317LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 83\n");return 1;}
}
{
short int a_0=((short int)(-9298LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-30282LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 84\n");return 1;}
}
{
short int a_0=((short int)25473LL);
short int b_0=a_0;
short int a_1=((short int)(-18126LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 85\n");return 1;}
}
{
short int a_0=((short int)26390LL);
short int b_0=a_0;
short int a_1=((short int)(-6484LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 86\n");return 1;}
}
{
short int a_0=((short int)18489LL);
short int b_0=a_0;
short int a_1=((short int)(-21306LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 87\n");return 1;}
}
{
short int a_0=((short int)(-25356LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-3691LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 88\n");return 1;}
}
{
short int a_0=((short int)24069LL);
short int b_0=a_0;
short int a_1=((short int)(-23853LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 89\n");return 1;}
}
{
short int a_0=((short int)(-4966LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-14431LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 90\n");return 1;}
}
{
short int a_0=((short int)(-27169LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-2457LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 91\n");return 1;}
}
{
short int a_0=((short int)(-9702LL-1LL));
short int b_0=a_0;
short int a_1=((short int)8033LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 92\n");return 1;}
}
{
short int a_0=((short int)(-20363LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-8382LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 93\n");return 1;}
}
{
short int a_0=((short int)11124LL);
short int b_0=a_0;
short int a_1=((short int)(-10998LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 94\n");return 1;}
}
{
short int a_0=((short int)(-26201LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-23263LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 95\n");return 1;}
}
{
short int a_0=((short int)(-16678LL-1LL));
short int b_0=a_0;
short int a_1=((short int)22621LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 96\n");return 1;}
}
{
short int a_0=((short int)(-11464LL-1LL));
short int b_0=a_0;
short int a_1=((short int)13856LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 97\n");return 1;}
}
{
short int a_0=((short int)27320LL);
short int b_0=a_0;
short int a_1=((short int)(-31852LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 98\n");return 1;}
}
{
short int a_0=((short int)9083LL);
short int b_0=a_0;
short int a_1=((short int)(-30875LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 99\n");return 1;}
}
{
short int a_0=((short int)(-10686LL-1LL));
short int b_0=a_0;
short int a_1=((short int)24710LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 100\n");return 1;}
}
{
short int a_0=((short int)192LL);
short int b_0=a_0;
short int a_1=((short int)(-5473LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 101\n");return 1;}
}
{
short int a_0=((short int)(-6618LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-8160LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 102\n");return 1;}
}
{
short int a_0=((short int)8980LL);
short int b_0=a_0;
short int a_1=((short int)(-9005LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 103\n");return 1;}
}
{
short int a_0=((short int)(-10692LL-1LL));
short int b_0=a_0;
short int a_1=((short int)9258LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 104\n");return 1;}
}
{
short int a_0=((short int)20630LL);
short int b_0=a_0;
short int a_1=((short int)(-9383LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 105\n");return 1;}
}
{
short int a_0=((short int)(-2120LL-1LL));
short int b_0=a_0;
short int a_1=((short int)14636LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 106\n");return 1;}
}
{
short int a_0=((short int)9229LL);
short int b_0=a_0;
short int a_1=((short int)10480LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 107\n");return 1;}
}
{
short int a_0=((short int)2933LL);
short int b_0=a_0;
short int a_1=((short int)(-31952LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 108\n");return 1;}
}
{
short int a_0=((short int)(-5799LL-1LL));
short int b_0=a_0;
short int a_1=((short int)28137LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 109\n");return 1;}
}
{
short int a_0=((short int)13292LL);
short int b_0=a_0;
short int a_1=((short int)(-15387LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 110\n");return 1;}
}
{
short int a_0=((short int)(-22134LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-3571LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 111\n");return 1;}
}
{
short int a_0=((short int)16318LL);
short int b_0=a_0;
short int a_1=((short int)32344LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 112\n");return 1;}
}
{
short int a_0=((short int)(-26848LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-32594LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 113\n");return 1;}
}
{
short int a_0=((short int)(-26506LL-1LL));
short int b_0=a_0;
short int a_1=((short int)23765LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 114\n");return 1;}
}
{
short int a_0=((short int)(-7557LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-5204LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 115\n");return 1;}
}
{
short int a_0=((short int)(-23521LL-1LL));
short int b_0=a_0;
short int a_1=((short int)13443LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 116\n");return 1;}
}
{
short int a_0=((short int)26854LL);
short int b_0=a_0;
short int a_1=((short int)(-30107LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 117\n");return 1;}
}
{
short int a_0=((short int)(-28104LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-19553LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 118\n");return 1;}
}
{
short int a_0=((short int)(-29089LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-9597LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 119\n");return 1;}
}
{
short int a_0=((short int)4017LL);
short int b_0=a_0;
short int a_1=((short int)(-13224LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 120\n");return 1;}
}
{
short int a_0=((short int)(-17324LL-1LL));
short int b_0=a_0;
short int a_1=((short int)23335LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 121\n");return 1;}
}
{
short int a_0=((short int)(-11124LL-1LL));
short int b_0=a_0;
short int a_1=((short int)31776LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 122\n");return 1;}
}
{
short int a_0=((short int)30996LL);
short int b_0=a_0;
short int a_1=((short int)(-15832LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 123\n");return 1;}
}
{
short int a_0=((short int)(-11905LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-8390LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 124\n");return 1;}
}
{
short int a_0=((short int)1277LL);
short int b_0=a_0;
short int a_1=((short int)8020LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 125\n");return 1;}
}
{
short int a_0=((short int)(-1771LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-640LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 126\n");return 1;}
}
{
short int a_0=((short int)15909LL);
short int b_0=a_0;
short int a_1=((short int)(-86LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 127\n");return 1;}
}
{
short int a_0=((short int)(-10582LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-24763LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 128\n");return 1;}
}
{
short int a_0=((short int)300LL);
short int b_0=a_0;
short int a_1=((short int)(-224LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 129\n");return 1;}
}
{
short int a_0=((short int)(-7599LL-1LL));
short int b_0=a_0;
short int a_1=((short int)3646LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 130\n");return 1;}
}
{
short int a_0=((short int)28816LL);
short int b_0=a_0;
short int a_1=((short int)(-16680LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 131\n");return 1;}
}
{
short int a_0=((short int)(-21154LL-1LL));
short int b_0=a_0;
short int a_1=((short int)15859LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 132\n");return 1;}
}
{
short int a_0=((short int)(-28015LL-1LL));
short int b_0=a_0;
short int a_1=((short int)27401LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 133\n");return 1;}
}
{
short int a_0=((short int)9664LL);
short int b_0=a_0;
short int a_1=((short int)30887LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 134\n");return 1;}
}
{
short int a_0=((short int)8862LL);
short int b_0=a_0;
short int a_1=((short int)25406LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 135\n");return 1;}
}
{
short int a_0=((short int)(-21786LL-1LL));
short int b_0=a_0;
short int a_1=((short int)19459LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 136\n");return 1;}
}
{
short int a_0=((short int)14095LL);
short int b_0=a_0;
short int a_1=((short int)7063LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 137\n");return 1;}
}
{
short int a_0=((short int)(-10917LL-1LL));
short int b_0=a_0;
short int a_1=((short int)23367LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 138\n");return 1;}
}
{
short int a_0=((short int)7487LL);
short int b_0=a_0;
short int a_1=((short int)(-28824LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 139\n");return 1;}
}
{
short int a_0=((short int)2739LL);
short int b_0=a_0;
short int a_1=((short int)(-26311LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 140\n");return 1;}
}
{
short int a_0=((short int)(-652LL-1LL));
short int b_0=a_0;
short int a_1=((short int)12051LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 141\n");return 1;}
}
{
short int a_0=((short int)(-32397LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-27315LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 142\n");return 1;}
}
{
short int a_0=((short int)21662LL);
short int b_0=a_0;
short int a_1=((short int)(-17145LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 143\n");return 1;}
}
{
short int a_0=((short int)(-20682LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-14304LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 144\n");return 1;}
}
{
short int a_0=((short int)(-29985LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-14083LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 145\n");return 1;}
}
{
short int a_0=((short int)(-26827LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-29664LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 146\n");return 1;}
}
{
short int a_0=((short int)(-1989LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-177LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 147\n");return 1;}
}
{
short int a_0=((short int)15354LL);
short int b_0=a_0;
short int a_1=((short int)(-16594LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 148\n");return 1;}
}
{
short int a_0=((short int)2831LL);
short int b_0=a_0;
short int a_1=((short int)20396LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 149\n");return 1;}
}
{
short int a_0=((short int)579LL);
short int b_0=a_0;
short int a_1=((short int)(-6765LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 150\n");return 1;}
}
{
short int a_0=((short int)494LL);
short int b_0=a_0;
short int a_1=((short int)(-3827LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 151\n");return 1;}
}
{
short int a_0=((short int)15057LL);
short int b_0=a_0;
short int a_1=((short int)11889LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 152\n");return 1;}
}
{
short int a_0=((short int)11963LL);
short int b_0=a_0;
short int a_1=((short int)(-28832LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 153\n");return 1;}
}
{
short int a_0=((short int)(-29319LL-1LL));
short int b_0=a_0;
short int a_1=((short int)7960LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 154\n");return 1;}
}
{
short int a_0=((short int)(-26391LL-1LL));
short int b_0=a_0;
short int a_1=((short int)8324LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 155\n");return 1;}
}
{
short int a_0=((short int)11019LL);
short int b_0=a_0;
short int a_1=((short int)(-27682LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 156\n");return 1;}
}
{
short int a_0=((short int)3069LL);
short int b_0=a_0;
short int a_1=((short int)22299LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 157\n");return 1;}
}
{
short int a_0=((short int)(-3862LL-1LL));
short int b_0=a_0;
short int a_1=((short int)32301LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 158\n");return 1;}
}
{
short int a_0=((short int)14293LL);
short int b_0=a_0;
short int a_1=((short int)19162LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 159\n");return 1;}
}
{
short int a_0=((short int)(-29903LL-1LL));
short int b_0=a_0;
short int a_1=((short int)14718LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 160\n");return 1;}
}
{
short int a_0=((short int)5707LL);
short int b_0=a_0;
short int a_1=((short int)(-10777LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 161\n");return 1;}
}
{
short int a_0=((short int)26227LL);
short int b_0=a_0;
short int a_1=((short int)(-28990LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 162\n");return 1;}
}
{
short int a_0=((short int)22296LL);
short int b_0=a_0;
short int a_1=((short int)14093LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 163\n");return 1;}
}
{
short int a_0=((short int)19636LL);
short int b_0=a_0;
short int a_1=((short int)(-6679LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 164\n");return 1;}
}
{
short int a_0=((short int)(-14052LL-1LL));
short int b_0=a_0;
short int a_1=((short int)11628LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 165\n");return 1;}
}
{
short int a_0=((short int)23528LL);
short int b_0=a_0;
short int a_1=((short int)11728LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 166\n");return 1;}
}
{
short int a_0=((short int)(-29791LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-27656LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 167\n");return 1;}
}
{
short int a_0=((short int)(-849LL-1LL));
short int b_0=a_0;
short int a_1=((short int)15683LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 168\n");return 1;}
}
{
short int a_0=((short int)(-31236LL-1LL));
short int b_0=a_0;
short int a_1=((short int)21589LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 169\n");return 1;}
}
{
short int a_0=((short int)31948LL);
short int b_0=a_0;
short int a_1=((short int)2800LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 170\n");return 1;}
}
{
short int a_0=((short int)23898LL);
short int b_0=a_0;
short int a_1=((short int)19978LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 171\n");return 1;}
}
{
short int a_0=((short int)(-19902LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-30461LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 172\n");return 1;}
}
{
short int a_0=((short int)26634LL);
short int b_0=a_0;
short int a_1=((short int)30602LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 173\n");return 1;}
}
{
short int a_0=((short int)(-3914LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-15779LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 174\n");return 1;}
}
{
short int a_0=((short int)(-4396LL-1LL));
short int b_0=a_0;
short int a_1=((short int)22007LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 175\n");return 1;}
}
{
short int a_0=((short int)(-29668LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-18152LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 176\n");return 1;}
}
{
short int a_0=((short int)3403LL);
short int b_0=a_0;
short int a_1=((short int)(-20853LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 177\n");return 1;}
}
{
short int a_0=((short int)751LL);
short int b_0=a_0;
short int a_1=((short int)(-31116LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 178\n");return 1;}
}
{
short int a_0=((short int)16135LL);
short int b_0=a_0;
short int a_1=((short int)20973LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 179\n");return 1;}
}
{
short int a_0=((short int)9051LL);
short int b_0=a_0;
short int a_1=((short int)(-8013LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 180\n");return 1;}
}
{
short int a_0=((short int)15387LL);
short int b_0=a_0;
short int a_1=((short int)(-26649LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 181\n");return 1;}
}
{
short int a_0=((short int)18644LL);
short int b_0=a_0;
short int a_1=((short int)(-26849LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 182\n");return 1;}
}
{
short int a_0=((short int)(-3191LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-27150LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 183\n");return 1;}
}
{
short int a_0=((short int)25555LL);
short int b_0=a_0;
short int a_1=((short int)3283LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 184\n");return 1;}
}
{
short int a_0=((short int)(-10968LL-1LL));
short int b_0=a_0;
short int a_1=((short int)7362LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 185\n");return 1;}
}
{
short int a_0=((short int)22011LL);
short int b_0=a_0;
short int a_1=((short int)23551LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 186\n");return 1;}
}
{
short int a_0=((short int)15500LL);
short int b_0=a_0;
short int a_1=((short int)(-6917LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 187\n");return 1;}
}
{
short int a_0=((short int)(-446LL-1LL));
short int b_0=a_0;
short int a_1=((short int)1476LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 188\n");return 1;}
}
{
short int a_0=((short int)(-1713LL-1LL));
short int b_0=a_0;
short int a_1=((short int)21870LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 189\n");return 1;}
}
{
short int a_0=((short int)6722LL);
short int b_0=a_0;
short int a_1=((short int)22557LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 190\n");return 1;}
}
{
short int a_0=((short int)20424LL);
short int b_0=a_0;
short int a_1=((short int)23105LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 191\n");return 1;}
}
{
short int a_0=((short int)(-6051LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-30490LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 192\n");return 1;}
}
{
short int a_0=((short int)13739LL);
short int b_0=a_0;
short int a_1=((short int)19287LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 193\n");return 1;}
}
{
short int a_0=((short int)8264LL);
short int b_0=a_0;
short int a_1=((short int)(-28750LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 194\n");return 1;}
}
{
short int a_0=((short int)(-27297LL-1LL));
short int b_0=a_0;
short int a_1=((short int)25669LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 195\n");return 1;}
}
{
short int a_0=((short int)(-20085LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-6445LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 196\n");return 1;}
}
{
short int a_0=((short int)23917LL);
short int b_0=a_0;
short int a_1=((short int)16471LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 197\n");return 1;}
}
{
short int a_0=((short int)3019LL);
short int b_0=a_0;
short int a_1=((short int)(-8584LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 198\n");return 1;}
}
{
short int a_0=((short int)(-26891LL-1LL));
short int b_0=a_0;
short int a_1=((short int)28375LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 199\n");return 1;}
}
{
short int a_0=((short int)18966LL);
short int b_0=a_0;
short int a_1=((short int)(-2896LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 200\n");return 1;}
}
{
short int a_0=((short int)(-19758LL-1LL));
short int b_0=a_0;
short int a_1=((short int)7544LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 201\n");return 1;}
}
{
short int a_0=((short int)1615LL);
short int b_0=a_0;
short int a_1=((short int)25364LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 202\n");return 1;}
}
{
short int a_0=((short int)(-23952LL-1LL));
short int b_0=a_0;
short int a_1=((short int)21477LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 203\n");return 1;}
}
{
short int a_0=((short int)(-6283LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-4880LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 204\n");return 1;}
}
{
short int a_0=((short int)(-24214LL-1LL));
short int b_0=a_0;
short int a_1=((short int)25906LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 205\n");return 1;}
}
{
short int a_0=((short int)17348LL);
short int b_0=a_0;
short int a_1=((short int)25052LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 206\n");return 1;}
}
{
short int a_0=((short int)804LL);
short int b_0=a_0;
short int a_1=((short int)(-15568LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 207\n");return 1;}
}
{
short int a_0=((short int)26118LL);
short int b_0=a_0;
short int a_1=((short int)(-4832LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 208\n");return 1;}
}
{
short int a_0=((short int)25466LL);
short int b_0=a_0;
short int a_1=((short int)7170LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 209\n");return 1;}
}
{
short int a_0=((short int)19761LL);
short int b_0=a_0;
short int a_1=((short int)(-13659LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 210\n");return 1;}
}
{
short int a_0=((short int)17361LL);
short int b_0=a_0;
short int a_1=((short int)(-6146LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 211\n");return 1;}
}
{
short int a_0=((short int)31991LL);
short int b_0=a_0;
short int a_1=((short int)8270LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 212\n");return 1;}
}
{
short int a_0=((short int)16932LL);
short int b_0=a_0;
short int a_1=((short int)(-7564LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 213\n");return 1;}
}
{
short int a_0=((short int)(-32560LL-1LL));
short int b_0=a_0;
short int a_1=((short int)28548LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 214\n");return 1;}
}
{
short int a_0=((short int)10830LL);
short int b_0=a_0;
short int a_1=((short int)(-22116LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 215\n");return 1;}
}
{
short int a_0=((short int)12358LL);
short int b_0=a_0;
short int a_1=((short int)8112LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 216\n");return 1;}
}
{
short int a_0=((short int)27068LL);
short int b_0=a_0;
short int a_1=((short int)2674LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 217\n");return 1;}
}
{
short int a_0=((short int)32218LL);
short int b_0=a_0;
short int a_1=((short int)30828LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 218\n");return 1;}
}
{
short int a_0=((short int)31238LL);
short int b_0=a_0;
short int a_1=((short int)(-9194LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 219\n");return 1;}
}
{
short int a_0=((short int)(-5647LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-4638LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 220\n");return 1;}
}
{
short int a_0=((short int)31342LL);
short int b_0=a_0;
short int a_1=((short int)5995LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 221\n");return 1;}
}
{
short int a_0=((short int)26765LL);
short int b_0=a_0;
short int a_1=((short int)21970LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 222\n");return 1;}
}
{
short int a_0=((short int)22224LL);
short int b_0=a_0;
short int a_1=((short int)(-32760LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 223\n");return 1;}
}
{
short int a_0=((short int)(-28436LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-27081LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 224\n");return 1;}
}
{
short int a_0=((short int)(-16114LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-17190LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 225\n");return 1;}
}
{
short int a_0=((short int)30397LL);
short int b_0=a_0;
short int a_1=((short int)(-10421LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 226\n");return 1;}
}
{
short int a_0=((short int)4710LL);
short int b_0=a_0;
short int a_1=((short int)(-10400LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 227\n");return 1;}
}
{
short int a_0=((short int)(-9300LL-1LL));
short int b_0=a_0;
short int a_1=((short int)26900LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 228\n");return 1;}
}
{
short int a_0=((short int)(-2891LL-1LL));
short int b_0=a_0;
short int a_1=((short int)434LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 229\n");return 1;}
}
{
short int a_0=((short int)25986LL);
short int b_0=a_0;
short int a_1=((short int)14594LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 230\n");return 1;}
}
{
short int a_0=((short int)12804LL);
short int b_0=a_0;
short int a_1=((short int)32597LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 231\n");return 1;}
}
{
short int a_0=((short int)(-16665LL-1LL));
short int b_0=a_0;
short int a_1=((short int)29230LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 232\n");return 1;}
}
{
short int a_0=((short int)(-25018LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-13631LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 233\n");return 1;}
}
{
short int a_0=((short int)(-15094LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-10799LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 234\n");return 1;}
}
{
short int a_0=((short int)27352LL);
short int b_0=a_0;
short int a_1=((short int)3774LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 235\n");return 1;}
}
{
short int a_0=((short int)8991LL);
short int b_0=a_0;
short int a_1=((short int)17606LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 236\n");return 1;}
}
{
short int a_0=((short int)9876LL);
short int b_0=a_0;
short int a_1=((short int)(-20018LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 237\n");return 1;}
}
{
short int a_0=((short int)(-28672LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-13613LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 238\n");return 1;}
}
{
short int a_0=((short int)22542LL);
short int b_0=a_0;
short int a_1=((short int)7467LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 239\n");return 1;}
}
{
short int a_0=((short int)24955LL);
short int b_0=a_0;
short int a_1=((short int)7821LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 240\n");return 1;}
}
{
short int a_0=((short int)14143LL);
short int b_0=a_0;
short int a_1=((short int)470LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 241\n");return 1;}
}
{
short int a_0=((short int)(-7200LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-22573LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 242\n");return 1;}
}
{
short int a_0=((short int)23825LL);
short int b_0=a_0;
short int a_1=((short int)10935LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 243\n");return 1;}
}
{
short int a_0=((short int)(-12073LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-1843LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 244\n");return 1;}
}
{
short int a_0=((short int)(-15658LL-1LL));
short int b_0=a_0;
short int a_1=((short int)29966LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 245\n");return 1;}
}
{
short int a_0=((short int)18927LL);
short int b_0=a_0;
short int a_1=((short int)(-12856LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 246\n");return 1;}
}
{
short int a_0=((short int)(-14887LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-22885LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 247\n");return 1;}
}
{
short int a_0=((short int)20818LL);
short int b_0=a_0;
short int a_1=((short int)(-3259LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 248\n");return 1;}
}
{
short int a_0=((short int)3083LL);
short int b_0=a_0;
short int a_1=((short int)(-16667LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 249\n");return 1;}
}
{
short int a_0=((short int)29749LL);
short int b_0=a_0;
short int a_1=((short int)22114LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 250\n");return 1;}
}
{
short int a_0=((short int)8265LL);
short int b_0=a_0;
short int a_1=((short int)(-19268LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 251\n");return 1;}
}
{
short int a_0=((short int)(-3099LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-16400LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 252\n");return 1;}
}
{
short int a_0=((short int)26586LL);
short int b_0=a_0;
short int a_1=((short int)(-24858LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 253\n");return 1;}
}
{
short int a_0=((short int)(-28360LL-1LL));
short int b_0=a_0;
short int a_1=((short int)14723LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 254\n");return 1;}
}
{
short int a_0=((short int)17740LL);
short int b_0=a_0;
short int a_1=((short int)(-25731LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 255\n");return 1;}
}
{
short int a_0=((short int)(-20628LL-1LL));
short int b_0=a_0;
short int a_1=((short int)(-5685LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 256\n");return 1;}
}
{
short int a_0=((short int)(-351LL-1LL));
short int b_0=a_0;
short int a_1=((short int)5350LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 257\n");return 1;}
}
{
short int a_0=((short int)(-32541LL-1LL));
short int b_0=a_0;
short int a_1=((short int)17106LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 258\n");return 1;}
}
{
short int a_0=((short int)31750LL);
short int b_0=a_0;
short int a_1=((short int)17429LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 259\n");return 1;}
}
{
short int a_0=((short int)25451LL);
short int b_0=a_0;
short int a_1=((short int)21125LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 260\n");return 1;}
}
{
short int a_0=((short int)10139LL);
short int b_0=a_0;
short int a_1=((short int)(-271LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 261\n");return 1;}
}
{
short int a_0=((short int)9651LL);
short int b_0=a_0;
short int a_1=((short int)(-14424LL-1LL));
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 262\n");return 1;}
}
{
short int a_0=((short int)14734LL);
short int b_0=a_0;
short int a_1=((short int)22980LL);
short int b_1=a_1;
short int ar=reference(a_0,a_1);
short int br=candidate(b_0,b_1);
if(!((ar==br))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
