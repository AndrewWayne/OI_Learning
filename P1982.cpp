#include <cstdio>
#include <iostream>
#include <cstring>
#define max(_a,_b) _a>_b?_a:_b
using namespace std;
int n,p;
long long int f[1000010],sum[1000010],scor[1000010],temp,maxs;
int main(){
    memset(f,-128,sizeof(f));
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>temp;
        sum[i]=sum[i-1]+temp;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            for(int k=j;k>0;k--)
                f[i]=max(f[i],sum[j]-sum[k]);
    maxs=-9999;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)
            scor[i]=max(scor[i],f[j]+scor[j]);
        maxs=max(maxs,scor[i]);
    }
    if(maxs>=0)
        cout<<maxs%p;
    else{
        maxs*=-1;
        cout<<"-"<<maxs%p;
    }
    return 0;
}
