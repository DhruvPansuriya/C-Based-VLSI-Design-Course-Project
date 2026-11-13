#include <stdint.h>
#include <stdio.h>

_Static_assert(sizeof(char)==1 && sizeof(short)==2 && sizeof(int)==4 &&
               sizeof(long)==4 && sizeof(long long)==8 && sizeof(void*)==4, "HLSCheck ILP32 ABI");
_Static_assert((char)-1 < 0, "HLSCheck requires signed plain char");
_Static_assert((unsigned char)-1 == 255, "HLSCheck requires 8-bit bytes");

unsigned long long int reference(unsigned long long int x)
{
  return x >> 63;
}


unsigned long long int candidate(unsigned long long int x)
{
  return (x & 0x8000000000000000ULL) != 0;
}


int main(void) {
{
unsigned long long int left_0=((unsigned long long int)0ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 0\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 1\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18446744073709551615ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 2\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9223372036854775808ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 3\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9223372036854775807ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 4\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 5\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6148914691236517205ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 6\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12297829382473034410ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 7\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7371986885985992035ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 8\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16788493648566303636ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 9\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3552857882061230021ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 10\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9990641598872118722ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 11\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12570137345216084128ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 12\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13585392823171333642ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 13\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2649412621105964200ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 14\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13175409399945679686ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 15\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11613144753118585726ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 16\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14183679947290694494ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 17\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17499121422273281337ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 18\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14826736636341804897ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 19\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10050180081080679680ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 20\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16708082129842223573ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 21\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16692555653547371941ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 22\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12668042359022718371ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 23\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17282609861530188930ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 24\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)598980876172065592ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 25\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14643745694532688372ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 26\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11611023921065040604ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 27\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12123697002783322913ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 28\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7368100504788368005ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 29\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11018201074545562382ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 30\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3720665637994019645ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 31\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)981833198064475211ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 32\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7516267533266405195ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 33\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15545561396334248153ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 34\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4236815479864759457ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 35\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3935557032255534865ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 36\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16529728633653305325ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 37\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10948953890917516087ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 38\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5499838589507526543ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 39\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8368152791728571339ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 40\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15223761836220257849ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 41\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11929474771273841099ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 42\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6123032073261779959ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 43\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4130345849937182029ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 44\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8792816599733326685ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 45\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10072555937685876055ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 46\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4646798305495883849ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 47\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16357378540989691153ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 48\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12070302456008568283ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 49\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15246630888386284704ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 50\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)546460511367283349ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 51\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17171498872100813903ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 52\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18336400915024289182ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 53\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5618837107136719302ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 54\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3271546125153075710ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 55\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4207578367742764066ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 56\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2621053109047217341ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 57\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2588400049752915683ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 58\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6219980366084720643ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 59\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5117294912071956408ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 60\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1787231359983796189ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 61\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1530519715058796329ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 62\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2788273609521192456ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 63\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7714751741748292431ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 64\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4094763123150787688ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 65\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9369845951907242089ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 66\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14499790388204372498ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 67\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3956276844719900617ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 68\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15249428680986006507ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 69\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4888688537921585909ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 70\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7073596485689888396ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 71\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10555164349970693555ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 72\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2361981801361650453ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 73\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5284692042176708832ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 74\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10909996584262261741ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 75\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6380876913494148329ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 76\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11299623623025535831ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 77\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17235434132746726390ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 78\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7368783280387028995ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 79\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10917627710328716712ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 80\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17566665602487819400ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 81\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9281475842225379041ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 82\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4878111358570805099ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 83\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11438872184747157273ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 84\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12617285791952062997ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 85\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17382662558825313633ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 86\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16432042477976634718ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 87\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17373358556037882185ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 88\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16142299640201373402ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 89\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5862534468154834794ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 90\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9457932547366046215ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 91\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14240671573604202739ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 92\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11776158774116805803ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 93\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1405904368934747063ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 94\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4006497811853305036ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 95\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17248284907667748026ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 96\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16614662022086596452ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 97\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12552105561461871917ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 98\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11569435979958673013ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 99\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4950902051299455026ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 100\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7566728581901045272ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 101\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4608872742580787774ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 102\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16238991184913308285ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 103\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10650733637804590101ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 104\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)381060769393580900ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 105\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13692232495900673927ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 106\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15519730916458461431ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 107\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9018483674919397360ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 108\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6435504317646173403ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 109\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10074990448679085299ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 110\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12415849164061529877ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 111\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8950017945699663010ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 112\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17651040451895361484ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 113\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9822443695669217554ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 114\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7950471361772445463ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 115\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16405900412919338192ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 116\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3983751005384159821ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 117\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13280217157767720393ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 118\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1319398398665147524ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 119\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18036320045091924807ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 120\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1870646254135080717ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 121\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4147360578220516187ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 122\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6427746661300683801ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 123\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15982067260708860792ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 124\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8285562720741633708ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 125\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11307171699948664974ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 126\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15981546656373172446ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 127\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3276706693097757636ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 128\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1943767224932505316ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 129\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18141144765877798852ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 130\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16538172724720921558ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 131\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)173062549190101308ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 132\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10049308577107546483ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 133\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2794764799884790155ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 134\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3628972058730676829ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 135\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17003553873845832085ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 136\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6552180390623910789ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 137\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4422841205795144692ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 138\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1950614411064215687ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 139\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6907213574549208821ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 140\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7338973997071838692ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 141\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16416412717248065418ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 142\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15488411660408438990ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 143\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9633515546187320899ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 144\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1085743634949561587ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 145\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11847008220687946707ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 146\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17933270794601853469ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 147\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10215792230382281475ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 148\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7857457337469126414ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 149\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4512141681824123649ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 150\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16274364621414284832ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 151\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8586094360953414891ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 152\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11536144053672927643ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 153\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17121577796636143991ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 154\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11199338715596200069ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 155\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7228873994674664808ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 156\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5710128370359758128ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 157\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12494757764659307221ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 158\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4020976669296838925ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 159\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15730830836177382371ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 160\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8841564658142977544ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 161\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17741344255676163912ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 162\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15645217211779685077ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 163\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4685668175955677984ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 164\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9629726239255429381ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 165\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8798220242459043080ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 166\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2449454787510022287ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 167\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8367921106384876423ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 168\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10445228090702421326ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 169\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10961254963590823922ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 170\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12838247364211614493ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 171\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4978655714913578475ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 172\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16983380673309934574ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 173\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16739695326580127654ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 174\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16220592469144285065ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 175\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15233918696265444530ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 176\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18170703911841840862ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 177\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)384702691736071244ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 178\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8366080873789504891ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 179\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5842499027760180225ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 180\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1858928973291280976ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 181\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3875461030022129992ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 182\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4241240523098172155ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 183\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12946624495425887923ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 184\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7748754338973563486ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 185\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12209774220508016874ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 186\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16900707039775481339ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 187\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6773315031574664963ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 188\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6416112071006584369ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 189\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)1743286195807539309ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 190\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14362471000845354686ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 191\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18361334161291113462ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 192\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6962724024766938707ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 193\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6268602016091369024ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 194\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14025799028430431553ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 195\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7413908202250217077ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 196\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14516851196248089526ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 197\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14105804822768764526ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 198\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7507343928713987223ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 199\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)17218029496423802083ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 200\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2773386183417036320ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 201\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2040545280971922954ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 202\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8923725816296479714ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 203\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10276413357412030347ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 204\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4674607508950154467ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 205\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3464733607417568865ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 206\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8255833131117123823ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 207\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16317526630520323393ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 208\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15974809913976311957ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 209\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10638994644868617913ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 210\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10211792821831362200ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 211\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11195912737859125371ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 212\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)383706422282124601ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 213\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16957782163629065535ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 214\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14069922236312221523ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 215\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5789824127699291832ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 216\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)8887917658582147153ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 217\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2918727879712346014ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 218\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13910225696502566403ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 219\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5244809240590885355ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 220\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10434910475176506024ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 221\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9213304011535855316ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 222\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13352107543645391825ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 223\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)739452238944186441ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 224\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)5589112014178669163ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 225\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13620065405241066455ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 226\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13128712678291665909ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 227\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16533376064010008757ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 228\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15325134470973177207ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 229\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15688673590080738901ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 230\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7179149295771605691ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 231\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2192124715010182056ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 232\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)18312227453230874809ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 233\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7047397775283700664ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 234\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2882852819557962649ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 235\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6773101537897358168ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 236\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12286774269119500649ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 237\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9016914365954570885ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 238\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12583545731753271085ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 239\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)12057126579416167271ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 240\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2121547109666626572ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 241\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6859865286128912364ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 242\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13595639472183504244ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 243\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)16132403205747216142ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 244\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)3635894743250263530ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 245\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2718538159704420921ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 246\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)15924546152035533560ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 247\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)10136979274881957136ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 248\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7568923330665116301ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 249\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)4076548307150768713ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 250\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14262898955053806892ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 251\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7222712901131680835ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 252\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6346585417573131055ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 253\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)6560776035820839810ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 254\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)13256574853034488805ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 255\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)14875803196183556413ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 256\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9497937659998556350ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 257\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7984241994970073308ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 258\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)2437534240333386279ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 259\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)7696176878427465758ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 260\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)9554767713720251948ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 261\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11653272040470772146ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 262\n");return 1;}
}
{
unsigned long long int left_0=((unsigned long long int)11550589158797694639ULL);
unsigned long long int right_0=left_0;
unsigned long long int original_return=reference(left_0);
unsigned long long int candidate_return=candidate(right_0);
if(!((original_return==candidate_return))){printf("Mismatch at trial 263\n");return 1;}
}
printf("PASS: 264 typed edge/random comparisons\n");
return 0;
}
