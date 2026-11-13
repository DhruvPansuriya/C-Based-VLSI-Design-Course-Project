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
  return a & 0x000FFFFFFFFFFFFFULL;
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
unsigned long long int a_0=((unsigned long long int)3586528423641069129ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13794721861797333856ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3605987481960983229ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)440310068297656895ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4282760518447706271ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11670205430144741019ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13755317584430429153ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12304938471480942143ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)579886109434697020ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8567755300530279636ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15922452688097523006ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5463999863962418035ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15993652450931937316ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2956428438266117236ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16352584042471830911ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13493170336545670933ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18256199133029979529ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 32\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6427146713547255843ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 33\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)941513867984418455ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 34\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9029416451989383834ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 35\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11100409137435522830ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 36\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4186052838178301984ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 37\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5720534999420316001ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 38\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9942320108600032096ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 39\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9543052983659643517ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 40\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14893163472829278728ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 41\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1803013311217674721ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 42\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12969148060158495299ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 43\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)624332491872489054ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 44\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1239273711864790849ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 45\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18317935792013512535ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 46\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8943055294028113824ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 47\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8816504767528972757ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 48\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7069739051819728200ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 49\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14430575747814160327ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 50\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1246807341491478480ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 51\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15210660845423958589ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 52\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8286735177752703152ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 53\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10471636736109702678ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 54\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2310619693556132802ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 55\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13154726468425810016ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 56\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5278195710536472704ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 57\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6896193228926582506ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 58\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14291244635777441774ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 59\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18271971684251280141ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 60\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7471953027544245862ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 61\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14615674902377519647ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 62\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3772598934721736769ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 63\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11596012677091223610ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 64\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11160227293094500477ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 65\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13209517555945468158ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 66\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6148847899069312547ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 67\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)88650822778067420ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 68\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15873933410902848366ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 69\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15303390954802622463ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 70\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1601120514997320659ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 71\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17579688285197215409ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 72\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1098305931334755107ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 73\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9923932813844606608ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 74\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2753452808693067097ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 75\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16566260967073041610ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 76\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11145960529289722408ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 77\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10771002702242221587ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 78\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3688341076095216897ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 79\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16146057752038198738ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 80\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9204788276941424109ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 81\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18319558802807947578ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 82\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13576348986573554621ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 83\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11584016999054498733ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 84\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15242841090012373889ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 85\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15136568317237880598ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 86\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10425649357663389753ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 87\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1076583750799170803ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 88\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17022476253525728773ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 89\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1854336750191635609ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 90\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8469650249855374814ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 91\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7704029268991793689ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 92\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2525566854316470388ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 93\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14757630324386311028ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 94\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5415091998236121510ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 95\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1404216777716842201ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 96\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15566795536657273655ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 97\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17671071698563787448ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 98\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6169870056512824187ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 99\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12741615631185270337ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 100\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17487552034125578432ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 101\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4600224404019078693ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 102\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5671999354349363988ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 103\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14256360678605837883ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 104\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16025174668336844950ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 105\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16857800977296193463ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 106\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6353886606944904205ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 107\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2257663976424016757ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 108\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7131523518451804504ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 109\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18187824872578495468ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 110\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14088786864880003465ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 111\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2685069709164429246ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 112\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1949283442012296991ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 113\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12967653417049299061ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 114\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14587792688653722234ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 115\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17357811948205745182ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 116\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10476343373905619174ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 117\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9012632796678427191ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 118\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2634878023677742686ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 119\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2669869065684651953ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 120\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1482030308402642003ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 121\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2116287372900291723ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 122\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)216954295537793300ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 123\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14053206734153175422ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 124\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13001429848078025981ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 125\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14393155576773343508ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 126\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)545021151932595749ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 127\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16283180483688453801ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 128\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4936196336916234540ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 129\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13990361295459443280ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 130\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6574394572501708944ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 131\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17532241072411815261ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 132\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6472970994768581264ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 133\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2147947669128422848ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 134\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12083332806935519902ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 135\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14975843588973112037ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 136\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17127026464707786511ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 137\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13991054540091544922ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 138\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7396544948766252351ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 139\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15588716186151684787ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 140\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11723397502762941811ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 141\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2138212175598223730ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 142\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13875763771714983070ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 143\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1555249772796030773ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 144\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)162888416955304670ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 145\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6840971086319490868ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 146\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11842357357393541178ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 147\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14452781875288161274ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 148\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3340344803953216271ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 149\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)208116064086000195ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 150\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7045680683406852590ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 151\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2549742282826201809ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 152\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16351139511631163067ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 153\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17450426467270430072ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 154\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5239070787842775272ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 155\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10865940557874473739ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 156\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1782124222714088445ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 157\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16723088735246545129ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 158\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17984801531411511253ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 159\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12213044109201869616ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 160\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2532779245335483979ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 161\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8695187478849807987ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 162\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1481899701836863256ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 163\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2799611033791122612ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 164\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4689470827229333787ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 165\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13966857288970361832ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 166\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6310368304860072864ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 167\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11392178824540388526ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 168\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4273294147782215163ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 169\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17366770341544688844ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 170\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10908198260143709530ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 171\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7176399044461244993ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 172\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10961419452348786698ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 173\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4231755077131169973ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 174\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)547510291272101587ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 175\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9570125046337997851ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 176\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15599155189242137931ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 177\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18239835270847070959ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 178\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3708912955328577287ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 179\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13680973358519690075ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 180\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16176132811916524571ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 181\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13120678832860514516ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 182\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3582852157009621896ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 183\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13436460895997158355ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 184\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9994837345466766631ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 185\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6433880502227916283ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 186\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15132112365175454860ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 187\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6433236769744944705ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 188\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8624904392376973646ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 189\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17188512362694449730ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 190\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4126185044551159752ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 191\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)799021048974469212ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 192\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3745335829952411051ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 193\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17782401355255062600ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 194\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8595684686558631262ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 195\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16215077673519591818ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 196\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1664536357935799661ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 197\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5268173080192814027ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 198\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)729415121549563636ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 199\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17957722408076986902ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 200\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6047932649629266641ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 201\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9851668757639464527ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 202\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5288137171314713199ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 203\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4102214965997987700ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 204\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6818538974481064297ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 205\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9074189761592837060ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 206\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2423331529934766884ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 207\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13453162513107805702ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 208\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11604376955374297978ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 209\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3280175310560578865ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 210\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18291819218864849873ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 211\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11287366787075243255ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 212\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5255864274690785828ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 213\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9997037693909237967ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 214\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10100156300714060366ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 215\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13943516896437284934ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 216\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14420266453254039996ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 217\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1392023274387439066ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 218\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15553034369195211270ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 219\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2824977533916604912ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 220\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7543136480381139566ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 221\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2601517126846539917ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 222\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17129572376920086224ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 223\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2449660437869662443ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 224\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3530400184340693261ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 225\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7320019385550927549ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 226\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6010257270691271270ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 227\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7333787755324693419ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 228\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3969990480923587764ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 229\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8993789848376272258ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 230\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9679677132099760644ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 231\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11633023260964339430ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 232\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6719800149189828165ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 233\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1809359034317128969ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 234\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5163084184437091032ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 235\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15358253936690275103ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 236\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13224932947494971028ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 237\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3294205162195750911ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 238\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)49245799217780750ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 239\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5537126309619982715ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 240\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14999975427550885695ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 241\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5262699054734042079ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 242\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1264346077481557265ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 243\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14472940404388778198ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 244\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17848409378930803413ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 245\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14174334638313196015ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 246\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15761070360543282648ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 247\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)595270061318885714ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 248\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2015176236480728075ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 249\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15130710891137496117ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 250\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9729164155576721481ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 251\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7105110423638176740ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 252\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8821986777568405466ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 253\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3459554042692931895ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 254\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15563160257479066956ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 255\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15482062337218621291ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 256\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10228910688529940128ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 257\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15424469929505882338ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 258\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5516286955042405382ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 259\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9485055700643832683ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 260\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)601719344440616859ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 261\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10031412114157020595ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 262\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8888476954566277518ULL);
unsigned long long int b_0=a_0;
unsigned long long int ar=reference(a_0);
unsigned long long int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
