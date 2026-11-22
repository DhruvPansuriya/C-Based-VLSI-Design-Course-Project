#include <limits.h>
int argmax(const int *a,int n,int *idx) {
 if(n==0) {*idx=-1;return INT_MIN;}
 int m=a[0]; *idx=0;
 for(int i=1;i<=n;i++) if(i<n && a[i]>m) {m=a[i];*idx=i;} else if(i==n && a[i]>m) {m=a[i];}
 return m;
}
