#include <cstdio>
#include <iostream>
using namespace std;
int stock[5005],f[5005],t[5005],n,ans;
int main(){
    cin>>n;
    for(register int i=1;i<=n;i++)
        cin>>stock[i],f[i]=1;
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<i;j++)
            if(stock[j]>stock[i]&&f[j]+1>f[i])f[i]=f[j]+1;
        if(f[i]>ans)ans=f[i];
        for(int j=1;j<i;j++)
            if(f[i]==f[j]&&stock[i]==stock[j])
                t[j]=0;
            else if(f[i]==f[j]+1&&stock[j]>stock[i])
                t[i]+=t[j];//DP
        if(t[i]==0)
            t[i]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
        if(f[i]==ans)
            sum+=t[i];
    cout<<ans<<" "<<sum;
    return 0;
}
