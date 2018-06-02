#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int n,m;
  int p=0,j=n;
  scanf("%d%d",&n,&m);
  int a[n+1];
  a[n]=1;
  for(int i=1;i<=n-1;i++)
    a[i]=i+1;
  while(p<n){
    for(int k=1;k<m;k++)
      j=a[j];
    printf("%d",a[j]);
    a[j]=a[a[j]];
    p++;
  }
}
