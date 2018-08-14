#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1e7+10;
int n,m,k,sn,tot;
bool notprime[maxn];
int prime[maxn];
int main(){
  cin>>n>>m;
  sn=sqrt(n);
  notprime[0]=true;
  notprime[1]=true;
  for(int i=2;i<=n;i++){
    if(!notprime[i])prime[++tot]=i;
    for(int j=1;j<=tot&&i*prime[j]<=n;j++){
      notprime[i*prime[j]]=true;
      if(i%prime[j]==0)break;
    }//在线算法，离线貌似会超时的说
  }
  for(int i=1;i<=m;i++){
    scanf("%d",&k);
    if(notprime[k])printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
