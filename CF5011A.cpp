#include <cstdio>
#include <iostream>
using namespace std;
int n,m,l,r,ans;
int out[110];
bool num[110];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>l>>r;
        for(int i=l;i<=r;i++)
            num[i]=1;
    }
    for(int i=1;i<=m;i++)
        if(!num[i])
            ans++,out[ans]=i;
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        cout<<out[i]<<" ";
    }
    return 0;
}
