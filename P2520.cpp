#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll t,a,b,x,y,k;
inline ll gcd(ll u,ll v){
    while(u)u^=v^=u^=v%=u;
    return v;
}
inline bool judge(ll u,ll v,ll c){
    return u%c==0&&v%c==0;
}
int main(){
    cin>>t;
    for(int jk=1;jk<=t;jk++){
        scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        k=2*gcd(a,b);
        if(judge(x,y,k)||judge(x+a,y+b,k)||judge(x+b,y+a,k)||judge(x+a+b,y+a+b,k))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
