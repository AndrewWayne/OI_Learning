#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#define rep(u,v,x) for(int x=u;x<=v;x++)
#define maxn 100010
long long int a[maxn],b[maxn];
int t,m,n;
bool pr(long long int k)  //判断是否为素数，不予以注释
{
  int m;
  for(m=2;m<=floor(sqrt(k));m++)
    if(k%m==0)return false;
  return true;
}
int main(){
  cin>>t;
  rep(1,t,q){
    memset(a,1,sizeof(a));
    memset(b,1,sizeof(b));
    cin>>n>>m;
    rep(1,n,i)
      cin>>a[i];
    rep(1,m,i)
      cin>>b[i];
    int big=m>n?m:n;
    long long int ans=1;
    rep(1,big,i)
      ans*=a[i]/b[i];
    if(pr(k))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
