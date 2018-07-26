#include <cstdio>
#include <iostream>
#include <algorithm>
#define mian main
#define ture true
using namespace std;
int n,l;
double fields[100001],sum[100001],b[100001];
bool check(double ans){
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        b[i]=fields[i]-ans;
        sum[i]=sum[i-1]+b[i];
    }
    double minn=sum[1];
    double val=-1e10;
    for(int i=l;i<=n;i++){
        minn=min(minn,sum[i-l]);
        val=max(val,sum[i]-minn);
    }
    return val<0;
}
int main(){
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        cin>>fields[i];
    double l=0.0,r=2000.0,ans=0.0;
    while(fabs(r-l)>0.0001){
        double mid=(l+r)/2.0;
        if(check(mid))r=mid;
        else l=mid,ans=mid;
    }
    cout<<round(ans*1000);
    return 0;
}
