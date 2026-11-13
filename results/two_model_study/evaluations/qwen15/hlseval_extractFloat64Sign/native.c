#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

int reference(unsigned long long int a)
{
  return a >> 63;
}


int candidate(unsigned long long int a)
{
  return a >> 63;
}


int main(void) {
{
unsigned long long int a_0=((unsigned long long int)0ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 0\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 1\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551615ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 2\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 3\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775807ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 4\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 5\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744073709551614ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 6\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6148914691236517205ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 7\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12297829382473034410ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 8\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405312ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 9\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9218868437227405313ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 10\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18442240474082181120ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 11\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4503599627370495ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 12\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18446744069414584320ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 13\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9223372036854775809ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 14\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 15\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2187476857974587057ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1715031521596023621ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8561628501040023886ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15503559377112072340ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16921889984648628981ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11579703598122421103ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)861087941999353720ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10006195170412027731ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11306236189962417602ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3179391586235098551ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6301851498851245151ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6215319981478970983ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17742245007778636121ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10464327506165633845ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18125754353215097698ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8892669351483875051ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12716302826949352674ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 32\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1464596304812110790ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 33\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3558272950174082438ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 34\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3484386366073214111ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 35\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16844291468599797110ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 36\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12609443444146135418ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 37\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2804559236483361198ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 38\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13574423081363542283ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 39\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9547579390470037205ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 40\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1138506119364186429ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 41\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10200184810016360307ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 42\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11565248524810701636ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 43\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10996343060597960305ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 44\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16089926720500930433ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 45\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3991874367789136933ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 46\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6443967034548045873ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 47\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1196566789816517016ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 48\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6852013939213604622ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 49\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1197378119881876762ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 50\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)775602210792413955ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 51\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12693344915598397249ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 52\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12555610275104708648ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 53\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8149358867243125295ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 54\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15369159894855569922ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 55\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7086789303341582454ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 56\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8282757219353901000ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 57\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1279392241448585314ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 58\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10393878698768342590ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 59\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13179765140014168633ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 60\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11634171768460683728ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 61\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8969174394213546113ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 62\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10603284764857355994ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 63\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6869540027345505190ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 64\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3857962642980834320ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 65\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11812181561616554554ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 66\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9309611088590983497ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 67\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3247318570217314466ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 68\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13586953129415826631ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 69\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15322845802802076415ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 70\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3076566450187739775ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 71\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15960230432161735303ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 72\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15873938496967018134ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 73\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2334812214630638315ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 74\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7385449275717282291ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 75\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1848216312908238583ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 76\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10950026177824787112ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 77\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9645410895588858932ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 78\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)255031947492565912ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 79\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8754434330863486024ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 80\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16620776717283890771ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 81\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5893705784825966244ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 82\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6041156742067632571ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 83\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3866118935133014084ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 84\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17637941054442083508ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 85\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7738333035029548099ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 86\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1374260044405920445ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 87\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12009544379645269131ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 88\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11552567726551494861ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 89\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11125701129812112745ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 90\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7678630284633023773ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 91\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14811485994576265602ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 92\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9003271921730666606ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 93\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9800006897817147107ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 94\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13329661220047021ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 95\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11353221006805637755ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 96\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16788657151502768342ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 97\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)60195523160496937ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 98\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2440279339339620236ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 99\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6155877967411435437ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 100\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12837709240641969174ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 101\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2535375017312486199ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 102\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2968655215766753093ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 103\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8983013460472100446ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 104\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8438470535430099730ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 105\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16383513594208595272ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 106\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15153420835700753971ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 107\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1918069203327465365ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 108\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12918791530372387855ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 109\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11674617186569870235ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 110\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6526913970759131382ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 111\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14830609977821713841ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 112\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1362540372392043884ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 113\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)20156461080190879ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 114\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14624281719749466664ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 115\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16097740666051868901ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 116\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1586983280597059626ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 117\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6326806992923908741ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 118\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11594163703481579568ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 119\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12218237276006300202ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 120\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3274718363437148809ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 121\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14133753618557558811ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 122\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11326344294570419622ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 123\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7686168692427259754ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 124\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5187074176601787919ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 125\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10619771992902575717ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 126\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16703688433347406994ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 127\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11910708303941289767ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 128\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8638814730269714021ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 129\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)25241018516231736ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 130\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6804265328345991918ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 131\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3605069086555288027ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 132\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17742214596741297362ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 133\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12737925969824659549ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 134\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9739433001079564051ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 135\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11080226981883865910ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 136\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12918805975144468184ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 137\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12685339647476475094ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 138\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1157663445789321101ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 139\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12130604691263827675ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 140\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3893368365683866924ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 141\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8360236602875702996ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 142\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5012164368944066774ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 143\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)109848486377210206ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 144\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6224132790752724926ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 145\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8212865907241016074ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 146\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16217616559705761821ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 147\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6187468232003759852ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 148\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6959978579101265157ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 149\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16700171772162335386ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 150\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11759692430724260238ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 151\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2563974198089625604ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 152\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13449157104323267682ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 153\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15007097123529166365ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 154\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1754210380889656865ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 155\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9573594524173331471ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 156\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13418157920338730439ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 157\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7896226008317089918ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 158\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6256383496437837055ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 159\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7575280252962411173ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 160\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6926926921440454331ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 161\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16972203768465249913ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 162\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5694548626245038653ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 163\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7853127226291099711ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 164\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11800688050644538044ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 165\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9681067093610328288ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 166\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13584304561869411187ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 167\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)646607370449699712ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 168\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12477209388023541ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 169\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15051228748727143795ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 170\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4788316827696844072ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 171\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10143889539431289192ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 172\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12203641707397809482ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 173\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1115396240807421249ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 174\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5619736704571983322ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 175\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10922502242951733963ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 176\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9537875728722416268ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 177\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16242870711193294081ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 178\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12013321945757214768ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 179\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17467765517299575163ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 180\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4512367777235929176ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 181\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12051005057762830271ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 182\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17006600249471446712ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 183\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7491904981882564946ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 184\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3531923688488804961ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 185\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8397117066220671272ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 186\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3121089315586748984ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 187\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13624461887664752342ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 188\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17024715893110818160ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 189\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)521997841484519203ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 190\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6062291234981357168ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 191\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5441705951191251947ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 192\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16613063258867453800ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 193\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9407030702316870005ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 194\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)738204020250507805ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 195\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13490220410824080308ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 196\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17822677980161559435ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 197\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1234452948211064996ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 198\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10623991640652134746ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 199\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)826675778482387495ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 200\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)554618132796184387ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 201\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7638637710107377345ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 202\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7847703082208141638ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 203\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3543037496400762620ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 204\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14897460401109893368ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 205\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11924925790906676316ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 206\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9930217476790321302ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 207\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4117544281746437773ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 208\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6644549607761442947ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 209\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11422602127031377362ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 210\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)75047091582546953ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 211\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12445998462501792762ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 212\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)18235227683392098260ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 213\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12474505979264772992ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 214\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4824898363965072856ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 215\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14480231617729216783ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 216\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17920715861524462102ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 217\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17980336514632738393ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 218\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)423446184540262193ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 219\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)937806821191481654ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 220\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11697169757961972071ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 221\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14846534201097160603ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 222\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)3487921282213409878ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 223\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16820763507410183556ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 224\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4080637331900687630ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 225\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11605429351790944143ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 226\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2769443748439844575ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 227\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)11279777510021032349ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 228\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9876827502142441736ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 229\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6570712640512649888ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 230\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)8892982667610328339ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 231\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13261469315453836675ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 232\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)265739291498008768ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 233\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6344723019001318161ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 234\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2927380427832569098ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 235\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)13781292993306363034ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 236\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12492025185839463664ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 237\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14476769875894396042ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 238\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)17958157791386976121ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 239\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7884758315160760682ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 240\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)436791758677254004ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 241\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15429963857899423252ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 242\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12426910168347460722ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 243\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4764038042725695618ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 244\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12449086888566266369ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 245\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)6641446000538927671ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 246\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)9679786199526436665ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 247\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15757597520931679350ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 248\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12544060577204488351ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 249\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5319601843581175582ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 250\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1470932544563142087ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 251\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)1617628101416773078ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 252\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)2880177747813959399ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 253\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)16004620997854040725ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 254\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12613118664522618517ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 255\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)7629454058464143441ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 256\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)4867660777936426828ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 257\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)10363475580737687459ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 258\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)15604967437624812924ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 259\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)12871914516589886265ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 260\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)895533397972519144ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 261\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)14994130753354361502ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 262\n");return 1;}
}
{
unsigned long long int a_0=((unsigned long long int)5432770129467402315ULL);
unsigned long long int b_0=a_0;
int ar=reference(a_0);
int br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
