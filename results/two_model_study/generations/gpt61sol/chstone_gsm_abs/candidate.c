typedef short word;
typedef long longword;
#define MIN_WORD ((-32767)-1)
#define MAX_WORD (32767)
#define saturate(x) ((x)<MIN_WORD?MIN_WORD:(x)>MAX_WORD?MAX_WORD:(x))

word kernel(word a)
{
    unsigned short bits = (unsigned short)a;
    unsigned short sign = (unsigned short)(0u - (bits >> 15));
    unsigned short magnitude =
        (unsigned short)((bits ^ sign) + (bits >> 15));
    return (word)(magnitude - (magnitude >> 15));
}
