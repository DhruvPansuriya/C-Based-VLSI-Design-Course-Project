/*
+--------------------------------------------------------------------------+
| CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
| ======================================================================== |
|                                                                          |
| * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
|                            H. Takada and K. Ishii                        |
|                            Nagoya University, Japan                      |
|                                                                          |
| * Remark :                                                               |
|    1. This source code is modified to unify the formats of the benchmark |
|       programs in CHStone.                                               |
|    2. Test vectors are added for CHStone.                                |
|    3. If "main_result" is 0 at the end of the program, the program is    |
|       correctly executed.                                                |
|    4. Please follow the copyright of each benchmark program.             |
+--------------------------------------------------------------------------+
*/
/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */


typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))
word
__original (word a, word b)
{
  longword sum;
  sum = (longword) a + (longword) b;
  return saturate (sum);
}

#include <stdio.h>
_Static_assert(sizeof(short)==2 && sizeof(int)==4 && sizeof(long)==4 && sizeof(unsigned long long)==8, "Windows LLP64/ESBMC 32-bit integer widths required");

word __optimized(word a, word b){longword s=(longword)a+(longword)b;if(s>MAX_WORD)return MAX_WORD;if(s<MIN_WORD)return MIN_WORD;return s;}

word __buggy(word a, word b){longword s=(longword)a+(longword)b;if(s>=MAX_WORD)return MAX_WORD-1;if(s<MIN_WORD)return MIN_WORD;return s;}

static unsigned long long state=0x5291abcddcba1234ULL;
static unsigned long long next(void){state^=state<<13;state^=state>>7;state^=state<<17;return state;}
int main(void){unsigned failures=0,bug_hits=0;
unsigned long long edge[]={0ULL,1ULL,255ULL,32767ULL,32768ULL,65535ULL,0x8000000000000000ULL,0x4000000000000000ULL,0x7FF0000000000000ULL,0xFFF0000000000000ULL,0x7FF0000000000001ULL,0x0008000000000000ULL,0x0010000000000000ULL,0xffffffffffffffffULL};
for(unsigned t=0;t<10000;++t){
short input_0=(short)(t<8?(int[]){0,32767,-32768,1,-1,32766,-32767,2}[t]:((int)(next()&65535ULL)-32768));
short input_1=(short)(t<8?(int[]){32767,0,-1,32767,-32768,1,-1,-2}[t]:((int)(next()&65535ULL)-32768));
failures+=(__original(input_0,input_1)!=__optimized(input_0,input_1));
bug_hits+=(__original(input_0,input_1)!=__buggy(input_0,input_1));
}
printf("%u %u\n",failures,bug_hits);return failures || !bug_hits;}
