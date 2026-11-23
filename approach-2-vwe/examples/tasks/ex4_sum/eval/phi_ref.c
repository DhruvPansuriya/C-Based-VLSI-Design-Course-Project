int phi_ref(const int *a,int n,int out_ret) {
 long long total=0;
 for(int i=0;i<n;i++) total+=(long long)a[i];
 return (long long)out_ret==total;
}
