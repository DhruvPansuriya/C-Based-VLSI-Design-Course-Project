#include <limits.h>
int argmax(const int *a,int n,int *idx) {
 if(n==0) {*idx=-1;return INT_MIN;}
 int best=0;
 for(int i=0;i<n;i++) if(a[i]>a[best]) best=i;
 *idx=best;
 return a[best];
}
