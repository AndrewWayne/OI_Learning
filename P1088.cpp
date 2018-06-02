#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
  int n,m,i;
  cin>>n>>m;
  int a[n+1];
  for(i=1;i<=n;i++)
    cin>>a[i];
  for(i=1;i<=m;i++)
    next_permutation(a+1,a+n+1);
  for(i=1;i<=n;i++)
    cout<<a[i]<<" ";
  return 0;
}
