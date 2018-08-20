#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long n,a,b,ans,sans;
long long gcd(long long u,long long v){
    while(u)u^=v^=u^=v%=u;
    return v;
}
long long lcm(long long u,long long v){
    return u/gcd(u,v)*v;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(i==1)
            ans=lcm(a,b);
        else
            ans=gcd(ans,lcm(a,b));
    }
    if(ans==1){
      printf("-1");
      return 0;
    }
    sans=sqrt(ans);
    a=gcd(a,ans);
    b=gcd(b,ans);
    if(a==1)
        a=b;
    for(int i=2;i<=sans;i++)
        if(ans%i==0){
            cout<<i;
            return 0;
        }
    cout<<a;
    return 0;
}
