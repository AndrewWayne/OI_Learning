#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
long long int m,sumb,suma,minuss,ans;
long long int a,b,d[maxn];
int main(){
    ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        d[i]=a-b;
        suma+=a;
        sumb+=b;
    }
    if(sumb>m)
    {cout<<"-1";return 0;}
    if(sumb==m)
    {cout<<n;return 0;}
    sort(d+1,d+1+n);
    for(int i=n;i>=1;i--){
        if(suma-minuss<m)
        {cout<<ans;return 0;}
        ans++;
        minuss+=d[i];
    }
    return 0;
}
