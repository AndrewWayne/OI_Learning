#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
#define max(a,b) a>b?a:b
#define rep(a,b) for(int i=a;i<=b;i++)
#define ll long long//大佬们说用ll就用long long
struct food{
    ll a,b,c;
} Foods[MAXN];
ll n,T,f[MAXN],ans=0;
bool cmp(food a,food b){
    return (ll)a.c*(ll)b.b<(ll)b.c*(ll)a.b;//经计算当ax-(t+cx)*bx+ay-(t+cx+cy)*by>ay-(t+cy)*by+ax-(t+cx+cy)bx时，整理得到cy*bx>cx*by,以此排列则越前面越优。
}

int main(){

    scanf("%lld%lld",&T,&n);
    rep(1,n)
    scanf("%lld",&Foods[i].a);
    rep(1,n)
    scanf("%lld",&Foods[i].b);
    rep(1,n)
    scanf("%lld",&Foods[i].c);
    sort(Foods,Foods+n+1,cmp);
    memset(f,-1,sizeof(f));

    f[0]=0;
    for(int i=1;i<=n;i++){
        for(ll j=T;j>=0;j--)
            if(f[j]!=-1&&j+Foods[i].c<=T)
                f[j+Foods[i].c]=max(f[j+Foods[i].c],f[j]+Foods[i].a-(j+Foods[i].c)*Foods[i].b);
    }
    rep(0,T)
    ans=max(ans,f[i]);
    printf("%lld",ans);
}
