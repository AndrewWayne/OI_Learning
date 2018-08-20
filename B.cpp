#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define SWAP(u,v) u^=v^=u^=v
using namespace std;
long long n,a,b,sa,sb,tot;
bool used[101000];
int ans[101000],top;
bool notprime[401000];
int prime[401000];
int main(){
    notprime[0]=true;
    notprime[1]=true;
    for(int i=2;i<=300000;i++){
        if(!notprime[i])prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<=300000;j++){
            notprime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
    cin>>n;
    cin>>a>>b;
    int sa=sqrt(a);
    int sb=sqrt(b);
    for(int i=1;prime[i]<=sa;i++)
        if(a%prime[i]==0)
            ans[++top]=prime[i],used[prime[i]]=true;
    for(int i=1;prime[i]<=sb;i++)
        if(b%prime[i]==0&&!used[prime[i]])
            ans[++top]=prime[i],used[prime[i]]=true;
    for(int i=2;i<=n;i++){
        cin>>a>>b;
        for(int i=top;i>=1;i--)
            if(a%ans[i]!=0&&b%ans[i]!=0)
                SWAP(ans[i],ans[top]),top--;
    }
    if(top==0)
        printf("-1");
    else
        cout<<ans[1];
    return 0;
}
