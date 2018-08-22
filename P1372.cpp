#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n,k;
inline int gcd(int u,int v){
  while(u)u^=v^=u^=v%=u;
  return v;
}
int main(){
  cin>>n>>k;
  int ans=n/k;
  cout<<ans;
  return 0;
}
