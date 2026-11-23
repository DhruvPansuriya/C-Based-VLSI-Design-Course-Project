#include <limits.h>
int phi_ref(const int *a,int n,int out_ret,int out_idx) {
 if(n==0) return out_ret==INT_MIN && out_idx==-1;
 if(out_idx<0 || out_idx>=n || out_ret!=a[out_idx]) return 0;
 for(int i=0;i<n;i++) {
   if(a[i]>out_ret) return 0;
   if(i<out_idx && a[i]==out_ret) return 0;
 }
 return 1;
}
