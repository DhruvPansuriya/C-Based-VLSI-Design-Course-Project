int sum(const int *a,int n) {
 long long total=0;
 for(int i=0;i<n;i++) total+=(long long)a[i];
 return (int)total; /* n<=4, each element in [-1000,1000]. */
}
