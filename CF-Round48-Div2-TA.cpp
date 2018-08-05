#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long m,rest,ans,a;
int main(){
    cin>>n>>m;
    rest=m;
    for(int i=1;i<=n;i++){
        ans=0;
        cin>>a;
        if(a>rest)
            a-=rest,rest=m,ans++;
        if(a<rest)
            rest-=a;
        else{
            ans+=a/rest;
            rest=m-a%rest;
        }
        cout<<ans<<" ";
    }
    return 0;
}
