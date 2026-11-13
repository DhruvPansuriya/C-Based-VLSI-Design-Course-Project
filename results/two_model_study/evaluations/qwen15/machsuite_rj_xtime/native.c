#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned char reference(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


unsigned char candidate(unsigned char x)
{
  return (x & 0x80) ? ((x << 1) ^ 0x1b) : (x << 1);
}


int main(void) {
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 0\n");return 1;}
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 1\n");return 1;}
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 2\n");return 1;}
}
{
unsigned char a_0=((unsigned char)128ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 3\n");return 1;}
}
{
unsigned char a_0=((unsigned char)127ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 4\n");return 1;}
}
{
unsigned char a_0=((unsigned char)2ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 5\n");return 1;}
}
{
unsigned char a_0=((unsigned char)254ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 6\n");return 1;}
}
{
unsigned char a_0=((unsigned char)85ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 7\n");return 1;}
}
{
unsigned char a_0=((unsigned char)170ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 8\n");return 1;}
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 9\n");return 1;}
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 10\n");return 1;}
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 11\n");return 1;}
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 12\n");return 1;}
}
{
unsigned char a_0=((unsigned char)0ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 13\n");return 1;}
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 14\n");return 1;}
}
{
unsigned char a_0=((unsigned char)3ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 15\n");return 1;}
}
{
unsigned char a_0=((unsigned char)177ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 16\n");return 1;}
}
{
unsigned char a_0=((unsigned char)69ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 17\n");return 1;}
}
{
unsigned char a_0=((unsigned char)78ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 18\n");return 1;}
}
{
unsigned char a_0=((unsigned char)148ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 19\n");return 1;}
}
{
unsigned char a_0=((unsigned char)245ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 20\n");return 1;}
}
{
unsigned char a_0=((unsigned char)111ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 21\n");return 1;}
}
{
unsigned char a_0=((unsigned char)120ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 22\n");return 1;}
}
{
unsigned char a_0=((unsigned char)83ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 23\n");return 1;}
}
{
unsigned char a_0=((unsigned char)194ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 24\n");return 1;}
}
{
unsigned char a_0=((unsigned char)183ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 25\n");return 1;}
}
{
unsigned char a_0=((unsigned char)95ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 26\n");return 1;}
}
{
unsigned char a_0=((unsigned char)103ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 27\n");return 1;}
}
{
unsigned char a_0=((unsigned char)89ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 28\n");return 1;}
}
{
unsigned char a_0=((unsigned char)53ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 29\n");return 1;}
}
{
unsigned char a_0=((unsigned char)98ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 30\n");return 1;}
}
{
unsigned char a_0=((unsigned char)235ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 31\n");return 1;}
}
{
unsigned char a_0=((unsigned char)226ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 32\n");return 1;}
}
{
unsigned char a_0=((unsigned char)198ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 33\n");return 1;}
}
{
unsigned char a_0=((unsigned char)134ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 34\n");return 1;}
}
{
unsigned char a_0=((unsigned char)159ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 35\n");return 1;}
}
{
unsigned char a_0=((unsigned char)118ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 36\n");return 1;}
}
{
unsigned char a_0=((unsigned char)122ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 37\n");return 1;}
}
{
unsigned char a_0=((unsigned char)174ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 38\n");return 1;}
}
{
unsigned char a_0=((unsigned char)11ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 39\n");return 1;}
}
{
unsigned char a_0=((unsigned char)213ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 40\n");return 1;}
}
{
unsigned char a_0=((unsigned char)61ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 41\n");return 1;}
}
{
unsigned char a_0=((unsigned char)115ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 42\n");return 1;}
}
{
unsigned char a_0=((unsigned char)68ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 43\n");return 1;}
}
{
unsigned char a_0=((unsigned char)113ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 44\n");return 1;}
}
{
unsigned char a_0=((unsigned char)129ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 45\n");return 1;}
}
{
unsigned char a_0=((unsigned char)37ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 46\n");return 1;}
}
{
unsigned char a_0=((unsigned char)49ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 47\n");return 1;}
}
{
unsigned char a_0=((unsigned char)152ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 48\n");return 1;}
}
{
unsigned char a_0=((unsigned char)14ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 49\n");return 1;}
}
{
unsigned char a_0=((unsigned char)26ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 50\n");return 1;}
}
{
unsigned char a_0=((unsigned char)3ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 51\n");return 1;}
}
{
unsigned char a_0=((unsigned char)65ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 52\n");return 1;}
}
{
unsigned char a_0=((unsigned char)40ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 53\n");return 1;}
}
{
unsigned char a_0=((unsigned char)47ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 54\n");return 1;}
}
{
unsigned char a_0=((unsigned char)2ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 55\n");return 1;}
}
{
unsigned char a_0=((unsigned char)118ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 56\n");return 1;}
}
{
unsigned char a_0=((unsigned char)200ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 57\n");return 1;}
}
{
unsigned char a_0=((unsigned char)98ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 58\n");return 1;}
}
{
unsigned char a_0=((unsigned char)62ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 59\n");return 1;}
}
{
unsigned char a_0=((unsigned char)57ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 60\n");return 1;}
}
{
unsigned char a_0=((unsigned char)208ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 61\n");return 1;}
}
{
unsigned char a_0=((unsigned char)129ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 62\n");return 1;}
}
{
unsigned char a_0=((unsigned char)218ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 63\n");return 1;}
}
{
unsigned char a_0=((unsigned char)166ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 64\n");return 1;}
}
{
unsigned char a_0=((unsigned char)16ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 65\n");return 1;}
}
{
unsigned char a_0=((unsigned char)58ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 66\n");return 1;}
}
{
unsigned char a_0=((unsigned char)73ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 67\n");return 1;}
}
{
unsigned char a_0=((unsigned char)162ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 68\n");return 1;}
}
{
unsigned char a_0=((unsigned char)199ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 69\n");return 1;}
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 70\n");return 1;}
}
{
unsigned char a_0=((unsigned char)127ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 71\n");return 1;}
}
{
unsigned char a_0=((unsigned char)135ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 72\n");return 1;}
}
{
unsigned char a_0=((unsigned char)150ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 73\n");return 1;}
}
{
unsigned char a_0=((unsigned char)235ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 74\n");return 1;}
}
{
unsigned char a_0=((unsigned char)243ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 75\n");return 1;}
}
{
unsigned char a_0=((unsigned char)247ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 76\n");return 1;}
}
{
unsigned char a_0=((unsigned char)168ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 77\n");return 1;}
}
{
unsigned char a_0=((unsigned char)52ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 78\n");return 1;}
}
{
unsigned char a_0=((unsigned char)152ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 79\n");return 1;}
}
{
unsigned char a_0=((unsigned char)72ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 80\n");return 1;}
}
{
unsigned char a_0=((unsigned char)83ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 81\n");return 1;}
}
{
unsigned char a_0=((unsigned char)164ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 82\n");return 1;}
}
{
unsigned char a_0=((unsigned char)187ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 83\n");return 1;}
}
{
unsigned char a_0=((unsigned char)68ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 84\n");return 1;}
}
{
unsigned char a_0=((unsigned char)180ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 85\n");return 1;}
}
{
unsigned char a_0=((unsigned char)67ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 86\n");return 1;}
}
{
unsigned char a_0=((unsigned char)189ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 87\n");return 1;}
}
{
unsigned char a_0=((unsigned char)139ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 88\n");return 1;}
}
{
unsigned char a_0=((unsigned char)205ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 89\n");return 1;}
}
{
unsigned char a_0=((unsigned char)105ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 90\n");return 1;}
}
{
unsigned char a_0=((unsigned char)29ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 91\n");return 1;}
}
{
unsigned char a_0=((unsigned char)130ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 92\n");return 1;}
}
{
unsigned char a_0=((unsigned char)110ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 93\n");return 1;}
}
{
unsigned char a_0=((unsigned char)227ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 94\n");return 1;}
}
{
unsigned char a_0=((unsigned char)173ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 95\n");return 1;}
}
{
unsigned char a_0=((unsigned char)123ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 96\n");return 1;}
}
{
unsigned char a_0=((unsigned char)214ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 97\n");return 1;}
}
{
unsigned char a_0=((unsigned char)41ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 98\n");return 1;}
}
{
unsigned char a_0=((unsigned char)140ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 99\n");return 1;}
}
{
unsigned char a_0=((unsigned char)173ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 100\n");return 1;}
}
{
unsigned char a_0=((unsigned char)22ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 101\n");return 1;}
}
{
unsigned char a_0=((unsigned char)55ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 102\n");return 1;}
}
{
unsigned char a_0=((unsigned char)69ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 103\n");return 1;}
}
{
unsigned char a_0=((unsigned char)94ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 104\n");return 1;}
}
{
unsigned char a_0=((unsigned char)18ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 105\n");return 1;}
}
{
unsigned char a_0=((unsigned char)72ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 106\n");return 1;}
}
{
unsigned char a_0=((unsigned char)51ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 107\n");return 1;}
}
{
unsigned char a_0=((unsigned char)149ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 108\n");return 1;}
}
{
unsigned char a_0=((unsigned char)15ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 109\n");return 1;}
}
{
unsigned char a_0=((unsigned char)155ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 110\n");return 1;}
}
{
unsigned char a_0=((unsigned char)246ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 111\n");return 1;}
}
{
unsigned char a_0=((unsigned char)177ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 112\n");return 1;}
}
{
unsigned char a_0=((unsigned char)108ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 113\n");return 1;}
}
{
unsigned char a_0=((unsigned char)159ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 114\n");return 1;}
}
{
unsigned char a_0=((unsigned char)40ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 115\n");return 1;}
}
{
unsigned char a_0=((unsigned char)229ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 116\n");return 1;}
}
{
unsigned char a_0=((unsigned char)42ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 117\n");return 1;}
}
{
unsigned char a_0=((unsigned char)133ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 118\n");return 1;}
}
{
unsigned char a_0=((unsigned char)48ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 119\n");return 1;}
}
{
unsigned char a_0=((unsigned char)42ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 120\n");return 1;}
}
{
unsigned char a_0=((unsigned char)137ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 121\n");return 1;}
}
{
unsigned char a_0=((unsigned char)27ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 122\n");return 1;}
}
{
unsigned char a_0=((unsigned char)166ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 123\n");return 1;}
}
{
unsigned char a_0=((unsigned char)106ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 124\n");return 1;}
}
{
unsigned char a_0=((unsigned char)15ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 125\n");return 1;}
}
{
unsigned char a_0=((unsigned char)101ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 126\n");return 1;}
}
{
unsigned char a_0=((unsigned char)146ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 127\n");return 1;}
}
{
unsigned char a_0=((unsigned char)39ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 128\n");return 1;}
}
{
unsigned char a_0=((unsigned char)101ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 129\n");return 1;}
}
{
unsigned char a_0=((unsigned char)56ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 130\n");return 1;}
}
{
unsigned char a_0=((unsigned char)238ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 131\n");return 1;}
}
{
unsigned char a_0=((unsigned char)219ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 132\n");return 1;}
}
{
unsigned char a_0=((unsigned char)210ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 133\n");return 1;}
}
{
unsigned char a_0=((unsigned char)93ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 134\n");return 1;}
}
{
unsigned char a_0=((unsigned char)19ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 135\n");return 1;}
}
{
unsigned char a_0=((unsigned char)54ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 136\n");return 1;}
}
{
unsigned char a_0=((unsigned char)216ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 137\n");return 1;}
}
{
unsigned char a_0=((unsigned char)214ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 138\n");return 1;}
}
{
unsigned char a_0=((unsigned char)141ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 139\n");return 1;}
}
{
unsigned char a_0=((unsigned char)219ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 140\n");return 1;}
}
{
unsigned char a_0=((unsigned char)44ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 141\n");return 1;}
}
{
unsigned char a_0=((unsigned char)212ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 142\n");return 1;}
}
{
unsigned char a_0=((unsigned char)214ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 143\n");return 1;}
}
{
unsigned char a_0=((unsigned char)94ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 144\n");return 1;}
}
{
unsigned char a_0=((unsigned char)190ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 145\n");return 1;}
}
{
unsigned char a_0=((unsigned char)10ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 146\n");return 1;}
}
{
unsigned char a_0=((unsigned char)29ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 147\n");return 1;}
}
{
unsigned char a_0=((unsigned char)236ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 148\n");return 1;}
}
{
unsigned char a_0=((unsigned char)5ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 149\n");return 1;}
}
{
unsigned char a_0=((unsigned char)154ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 150\n");return 1;}
}
{
unsigned char a_0=((unsigned char)142ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 151\n");return 1;}
}
{
unsigned char a_0=((unsigned char)4ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 152\n");return 1;}
}
{
unsigned char a_0=((unsigned char)98ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 153\n");return 1;}
}
{
unsigned char a_0=((unsigned char)29ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 154\n");return 1;}
}
{
unsigned char a_0=((unsigned char)33ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 155\n");return 1;}
}
{
unsigned char a_0=((unsigned char)15ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 156\n");return 1;}
}
{
unsigned char a_0=((unsigned char)199ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 157\n");return 1;}
}
{
unsigned char a_0=((unsigned char)126ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 158\n");return 1;}
}
{
unsigned char a_0=((unsigned char)255ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 159\n");return 1;}
}
{
unsigned char a_0=((unsigned char)165ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 160\n");return 1;}
}
{
unsigned char a_0=((unsigned char)187ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 161\n");return 1;}
}
{
unsigned char a_0=((unsigned char)121ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 162\n");return 1;}
}
{
unsigned char a_0=((unsigned char)61ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 163\n");return 1;}
}
{
unsigned char a_0=((unsigned char)63ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 164\n");return 1;}
}
{
unsigned char a_0=((unsigned char)188ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 165\n");return 1;}
}
{
unsigned char a_0=((unsigned char)224ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 166\n");return 1;}
}
{
unsigned char a_0=((unsigned char)115ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 167\n");return 1;}
}
{
unsigned char a_0=((unsigned char)128ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 168\n");return 1;}
}
{
unsigned char a_0=((unsigned char)245ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 169\n");return 1;}
}
{
unsigned char a_0=((unsigned char)115ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 170\n");return 1;}
}
{
unsigned char a_0=((unsigned char)40ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 171\n");return 1;}
}
{
unsigned char a_0=((unsigned char)104ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 172\n");return 1;}
}
{
unsigned char a_0=((unsigned char)74ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 173\n");return 1;}
}
{
unsigned char a_0=((unsigned char)65ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 174\n");return 1;}
}
{
unsigned char a_0=((unsigned char)218ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 175\n");return 1;}
}
{
unsigned char a_0=((unsigned char)203ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 176\n");return 1;}
}
{
unsigned char a_0=((unsigned char)140ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 177\n");return 1;}
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 178\n");return 1;}
}
{
unsigned char a_0=((unsigned char)48ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 179\n");return 1;}
}
{
unsigned char a_0=((unsigned char)123ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 180\n");return 1;}
}
{
unsigned char a_0=((unsigned char)88ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 181\n");return 1;}
}
{
unsigned char a_0=((unsigned char)191ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 182\n");return 1;}
}
{
unsigned char a_0=((unsigned char)184ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 183\n");return 1;}
}
{
unsigned char a_0=((unsigned char)82ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 184\n");return 1;}
}
{
unsigned char a_0=((unsigned char)97ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 185\n");return 1;}
}
{
unsigned char a_0=((unsigned char)40ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 186\n");return 1;}
}
{
unsigned char a_0=((unsigned char)56ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 187\n");return 1;}
}
{
unsigned char a_0=((unsigned char)214ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 188\n");return 1;}
}
{
unsigned char a_0=((unsigned char)112ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 189\n");return 1;}
}
{
unsigned char a_0=((unsigned char)35ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 190\n");return 1;}
}
{
unsigned char a_0=((unsigned char)112ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 191\n");return 1;}
}
{
unsigned char a_0=((unsigned char)235ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 192\n");return 1;}
}
{
unsigned char a_0=((unsigned char)104ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 193\n");return 1;}
}
{
unsigned char a_0=((unsigned char)117ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 194\n");return 1;}
}
{
unsigned char a_0=((unsigned char)29ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 195\n");return 1;}
}
{
unsigned char a_0=((unsigned char)180ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 196\n");return 1;}
}
{
unsigned char a_0=((unsigned char)139ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 197\n");return 1;}
}
{
unsigned char a_0=((unsigned char)164ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 198\n");return 1;}
}
{
unsigned char a_0=((unsigned char)90ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 199\n");return 1;}
}
{
unsigned char a_0=((unsigned char)39ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 200\n");return 1;}
}
{
unsigned char a_0=((unsigned char)67ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 201\n");return 1;}
}
{
unsigned char a_0=((unsigned char)193ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 202\n");return 1;}
}
{
unsigned char a_0=((unsigned char)70ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 203\n");return 1;}
}
{
unsigned char a_0=((unsigned char)252ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 204\n");return 1;}
}
{
unsigned char a_0=((unsigned char)248ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 205\n");return 1;}
}
{
unsigned char a_0=((unsigned char)92ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 206\n");return 1;}
}
{
unsigned char a_0=((unsigned char)150ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 207\n");return 1;}
}
{
unsigned char a_0=((unsigned char)141ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 208\n");return 1;}
}
{
unsigned char a_0=((unsigned char)131ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 209\n");return 1;}
}
{
unsigned char a_0=((unsigned char)210ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 210\n");return 1;}
}
{
unsigned char a_0=((unsigned char)9ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 211\n");return 1;}
}
{
unsigned char a_0=((unsigned char)250ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 212\n");return 1;}
}
{
unsigned char a_0=((unsigned char)212ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 213\n");return 1;}
}
{
unsigned char a_0=((unsigned char)128ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 214\n");return 1;}
}
{
unsigned char a_0=((unsigned char)216ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 215\n");return 1;}
}
{
unsigned char a_0=((unsigned char)15ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 216\n");return 1;}
}
{
unsigned char a_0=((unsigned char)22ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 217\n");return 1;}
}
{
unsigned char a_0=((unsigned char)89ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 218\n");return 1;}
}
{
unsigned char a_0=((unsigned char)49ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 219\n");return 1;}
}
{
unsigned char a_0=((unsigned char)54ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 220\n");return 1;}
}
{
unsigned char a_0=((unsigned char)103ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 221\n");return 1;}
}
{
unsigned char a_0=((unsigned char)155ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 222\n");return 1;}
}
{
unsigned char a_0=((unsigned char)86ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 223\n");return 1;}
}
{
unsigned char a_0=((unsigned char)132ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 224\n");return 1;}
}
{
unsigned char a_0=((unsigned char)14ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 225\n");return 1;}
}
{
unsigned char a_0=((unsigned char)143ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 226\n");return 1;}
}
{
unsigned char a_0=((unsigned char)223ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 227\n");return 1;}
}
{
unsigned char a_0=((unsigned char)157ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 228\n");return 1;}
}
{
unsigned char a_0=((unsigned char)8ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 229\n");return 1;}
}
{
unsigned char a_0=((unsigned char)160ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 230\n");return 1;}
}
{
unsigned char a_0=((unsigned char)19ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 231\n");return 1;}
}
{
unsigned char a_0=((unsigned char)131ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 232\n");return 1;}
}
{
unsigned char a_0=((unsigned char)192ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 233\n");return 1;}
}
{
unsigned char a_0=((unsigned char)17ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 234\n");return 1;}
}
{
unsigned char a_0=((unsigned char)10ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 235\n");return 1;}
}
{
unsigned char a_0=((unsigned char)154ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 236\n");return 1;}
}
{
unsigned char a_0=((unsigned char)240ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 237\n");return 1;}
}
{
unsigned char a_0=((unsigned char)138ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 238\n");return 1;}
}
{
unsigned char a_0=((unsigned char)121ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 239\n");return 1;}
}
{
unsigned char a_0=((unsigned char)106ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 240\n");return 1;}
}
{
unsigned char a_0=((unsigned char)116ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 241\n");return 1;}
}
{
unsigned char a_0=((unsigned char)20ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 242\n");return 1;}
}
{
unsigned char a_0=((unsigned char)114ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 243\n");return 1;}
}
{
unsigned char a_0=((unsigned char)130ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 244\n");return 1;}
}
{
unsigned char a_0=((unsigned char)1ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 245\n");return 1;}
}
{
unsigned char a_0=((unsigned char)55ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 246\n");return 1;}
}
{
unsigned char a_0=((unsigned char)57ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 247\n");return 1;}
}
{
unsigned char a_0=((unsigned char)118ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 248\n");return 1;}
}
{
unsigned char a_0=((unsigned char)159ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 249\n");return 1;}
}
{
unsigned char a_0=((unsigned char)30ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 250\n");return 1;}
}
{
unsigned char a_0=((unsigned char)199ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 251\n");return 1;}
}
{
unsigned char a_0=((unsigned char)214ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 252\n");return 1;}
}
{
unsigned char a_0=((unsigned char)231ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 253\n");return 1;}
}
{
unsigned char a_0=((unsigned char)149ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 254\n");return 1;}
}
{
unsigned char a_0=((unsigned char)149ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 255\n");return 1;}
}
{
unsigned char a_0=((unsigned char)81ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 256\n");return 1;}
}
{
unsigned char a_0=((unsigned char)76ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 257\n");return 1;}
}
{
unsigned char a_0=((unsigned char)163ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 258\n");return 1;}
}
{
unsigned char a_0=((unsigned char)124ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 259\n");return 1;}
}
{
unsigned char a_0=((unsigned char)57ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 260\n");return 1;}
}
{
unsigned char a_0=((unsigned char)232ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 261\n");return 1;}
}
{
unsigned char a_0=((unsigned char)158ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 262\n");return 1;}
}
{
unsigned char a_0=((unsigned char)75ULL);
unsigned char b_0=a_0;
unsigned char ar=reference(a_0);
unsigned char br=candidate(b_0);
if(!((ar==br))){printf("mismatch at test 263\n");return 1;}
}
printf("PASS 264 typed comparisons\n");
return 0;
}
