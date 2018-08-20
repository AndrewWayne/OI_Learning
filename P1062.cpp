#include <cstdio>
#include <iostream>
#define unsigned long long ull
using namespace std;
int k,n,stack[20],top;
ull ans;
int main(){
  cin>>k>>n;
  while(n)stack[top++]=n%2,n/=2;
  while(top>=0)
    ans+=pow(k,top)*a[top--];
  cou<<ans;
  return 0;
}
