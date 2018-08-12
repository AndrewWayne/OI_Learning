#include <cstdio>
#include <iostream>
using namespace std;
int ans,n;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)
    ans+=n/i;
  cout<<ans;
  return 0;
}
