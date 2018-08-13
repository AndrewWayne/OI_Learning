#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1e5+10;
int n,m,a,sum[maxn],u,S,v;
bool check(int l,int r,int need){
    if(sum[r]-sum[l-1]<=need)return true;
    return false;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a,sum[i]=sum[i-1]+a;
    cin>>m;
    for(int i=1;i<=m;i++){
        int j=0;
        cin>>u>>S;
        int l=u,r=n;
        while(l-r>=5){
            int mid=(l+r)>>1;
            if(check(u,mid,S))l=mid;
            else r=mid;
        }
        for(j=r;j>=l&&!check(u,j,S);j--);
        cout<<j-u+1<<endl;
    }
}
