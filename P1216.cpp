#include <cstdio>
#include <iostream>
#define max()
#define over return 0
using namespace std;
int r,num,f[1010][1010];
int main(){
  cin>>r;
  for(int i=1;i<=r;i++)
    for(int j=1;j<=i;j++)
     scanf("%d",&f[i][j]);
  for(int i=r;i>=1;i--)
    for(int j=i;j>=1;j--)
      f[i][j]+=max(f[i+1][j],f[i+1][j+1]);
  cout<<f[1][1];
  over;
}
