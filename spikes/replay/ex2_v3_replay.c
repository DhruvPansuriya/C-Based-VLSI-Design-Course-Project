/* Native replay of the CBMC witness for Example 2, variant 3 (n = 3), under ASan/UBSan.
   Build: gcc -g -fsanitize=address,undefined -DVARIANT=3 \
          spikes/examples/ex2_argmax/p1_variants.c spikes/replay/ex2_v3_replay.c -o /tmp/replay */
#include <stdio.h>
#include <stdlib.h>
int p1_argmax(const int *, int, int *);
int main(void) {
  int n = 3;                                   /* witness from CBMC */
  int *a = malloc((size_t)n * sizeof(int));    /* exact-size buffer, as in the harness */
  for (int i = 0; i < n; i++) a[i] = i;
  int idx; int r = p1_argmax(a, n, &idx);
  printf("ret=%d idx=%d\n", r, idx);
  free(a);
  return 0;
}
