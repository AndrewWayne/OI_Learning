#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 210
#define maxq 50010
#define ll long long
using namespace std;
ll n,m,dis[maxn][maxn],t[maxq],q,k;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll read()
{
    char ch=nc();ll sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
int main()
{
    n=read(),m=read();
    memset(dis,127/3,sizeof(dis));
    memset(t,127/3,sizeof(t));
    const ll mm=dis[1][1];
    for(int i=0;i<n;i++)
        t[i]=read(),dis[i][i]=0;
    for(int i=1;i<=m;i++){
        ll x,y,w;
        x=read(),y=read(),w=read();
        dis[x][y]=dis[y][x]=w;
    }
    q=read();
    for(int ii=1;ii<=q;ii++)
    {
        ll x,y,ti;
        x=read(),y=read(),ti=read();
        while(k<n&&t[k]<=ti){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            k++;
        }
        if(dis[x][y]==mm||t[x]>ti||t[y]>ti) printf("-1\n");
        else printf("%lld\n",dis[x][y]);
    }
    return 0;
}
