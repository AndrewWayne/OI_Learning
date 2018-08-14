#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define maxn 10005
#define maxm 500005
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
struct Edge
{
    int v,w,nxt;
}e[maxm];
int head[maxm],nume,n,m,s,vis[maxn];
long long dis[maxn];
#define P pair<long long,int>
priority_queue<P,vector<P>,greater<P> >q;
inline void add(int u,int v,int w)
{
    e[++nume].v=v;
    e[nume].w=w;
    e[nume].nxt=head[u];
    head[u]=nume;
}
int main()
{
    n=read(),m=read(),s=read();
    for(int i=1;i<=m;i++){
        int x,y,z;
        x=read(),y=read(),z=read();
        add(x,y,z);
    }
    memset(dis,127,sizeof(dis));
    long long mm=dis[1];
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(!vis[x]){
            vis[x]=1;
            for(int i=head[x];i;i=e[i].nxt){
                int v=e[i].v;
                dis[v]=min(dis[v],dis[x]+e[i].w);
                q.push(make_pair(dis[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(dis[i]==mm)
            printf("2147483647 ");
        else
            printf("%d ",dis[i]);
    return 0;
}
