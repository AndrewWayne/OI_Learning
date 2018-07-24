#include <cstdio>
#include <iostream>
using namespace std;
int n,x,sum;
int main(){
  //freopen(,"r",stdin);
  //freopen(,"w",stdout);
  cin>>n>>x;
  for(int i=1;i<=n;i++){
    if(i%10==x)sum++;
    int k=10;
    for(int j=1;j<=6;j++){
      if(i/k!=0)
        if(i/k%10==x)sum++;
      k*=10;
    }
  }
  cout<<sum;
  return 0;
}
