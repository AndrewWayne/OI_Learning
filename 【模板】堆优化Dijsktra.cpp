/*
 * Author: xiaohei_AWM
 * Date: 6.30
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<queue>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const int maxn = 10005, maxm = 50005;
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
