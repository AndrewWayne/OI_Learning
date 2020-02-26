#include <iostream>
#include <cmath>
#include <cstring>
typedef long long ll;
using namespace std;
const long long maxn=1e5+10;
const long long maxa=1e11;
ll c,cc,k;
ll ans,xans;
ll K[maxn],top;
ll gcd(ll a,ll b){
    while(b){long long r=b;b=a%b;a=r;}
    return a;
}
int main(){
    ans=0;
    xans=0;
    ll x=0,y=0,a=0;
    cin>>c;
    cc=(ll)c*c;
    for(long long i=1;i<=sqrt(2*c);i++){
        if(2*c % i !=0)continue;
        K[++top]=i;
        K[++top]=2*c/i;
    }
    for(long long i=1;i<=top;i++){
        k=K[i];
       if((2*c)%k!=0) continue;
        for(long long x=1;x<=sqrt(2*c/k);x++){
            y=sqrt(2*c/k-x*x);
            if(y*y==2*c/k-x*x&&y>=x){
                if(gcd(x,y)!=1)continue;
                a=k*x*y;
                long long b=sqrt(c*c-a*a);
                if(b==0||a==0||b<a)break;
                if(b*b==c*c-a*a){
                    ans+=2;
                    xans^=a^b;
                }
            }
        }
    }
    if(ans!=0){
    cout<<ans<<endl;
    cout<<xans<<endl;}
    return 0;
}
