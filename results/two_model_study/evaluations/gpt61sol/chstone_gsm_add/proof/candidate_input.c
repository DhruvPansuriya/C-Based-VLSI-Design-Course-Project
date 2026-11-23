typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))

word kernel(word a, word b)
{
    int sum = (int)a + (int)b;
    unsigned int biased = (unsigned int)sum + 32768u;
    if (biased > 65535u)
        return a < 0 ? MIN_WORD : MAX_WORD;
    return (word)sum;
}
