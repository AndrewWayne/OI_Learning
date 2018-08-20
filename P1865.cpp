#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1e7+10;
int n,m,tot,l,r;
bool notprime[maxn];
int prime[maxn],sum[maxn];
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    bool minus=false;
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9')&&ch!='-')ch=nc();
    if(ch=='-')minus=true,ch=nc();//判负没必要的时候记得删，影响效率
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return minus?0-sum:sum;
}

int main(){
    cin>>n>>m;
    notprime[0]=true;
    notprime[1]=true;
    for(int i=2;i<=m;i++){
        if(!notprime[i])prime[++tot]=i;
        sum[i]=sum[i-1]+(!notprime[i]);
        for(int j=1;j<=tot&&i*prime[j]<=m;j++){
            notprime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<=n;i++){
        l=read(),r=read();
        if(l<1||r>m){
            printf("Crossing the line\n");
            continue;
        }
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}
