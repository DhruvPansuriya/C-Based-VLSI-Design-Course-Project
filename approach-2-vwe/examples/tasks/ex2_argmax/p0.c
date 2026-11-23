int argmax(const int *a,int n,int *idx) {
 int m=a[0]; *idx=0;
 for(int i=1;i<n;i++) if(a[i]>m) {m=a[i];*idx=i;}
 return m;
}
