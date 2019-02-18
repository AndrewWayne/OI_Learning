#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long lol;
int gi(){
    int res=0,fh=1;char ch=getchar();
    while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
    if(ch=='-')fh=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return fh*res;
}
const int MAXN=60010;
const int INF=1e9;
int bt,b[MAXN],next[MAXN],to[MAXN];
void add(int x,int y){
    next[++bt]=b[x];b[x]=bt;to[bt]=y;
    next[++bt]=b[y];b[y]=bt;to[bt]=x;
}
int tot,w[MAXN],f[MAXN],dep[MAXN],sz[MAXN],son[MAXN],top[MAXN],id[MAXN];
void dfs1(int x){
    sz[x]=1;
    for(int i=b[x];i;i=next[i]){
        if(to[i]==f[x])continue;
        f[to[i]]=x;
        dep[to[i]]=dep[x]+1;
        dfs1(to[i]);
        sz[x]+=sz[to[i]];
        if(sz[to[i]]>sz[son[x]])son[x]=to[i];
    }
}
void dfs2(int x,int y){
    top[x]=y;
    id[x]=++tot;
    if(son[x])dfs2(son[x],y);
    for(int i=b[x];i;i=next[i]){
        if(to[i]==f[x]||to[i]==son[x])continue;
        dfs2(to[i],to[i]);
    }
}
int D,K,val[MAXN<<1][2];
void update(int x){
    val[x][0]=val[x<<1][0]+val[x<<1|1][0];
    val[x][1]=max(val[x<<1][1],val[x<<1|1][1]);
}
void up(int y,int x){
    val[K+id[x]][0]=val[K+id[x]][1]=y;
    for(x=(K+id[x])>>1;x;x>>=1)update(x);
}
int getv(int l,int r,bool tp){
    int ans=tp?-INF:0;
    for(l=K+l-1,r=K+r+1;l^r^1;l>>=1,r>>=1){
        if(~l&1){
            if(tp)ans=max(ans,val[l^1][tp]);
            else ans+=val[l^1][tp];
        }
        if( r&1){
            if(tp)ans=max(ans,val[r^1][tp]);
            else ans+=val[r^1][tp];
        }
    }
    return ans;
}
int query(int x,int y,bool tp){
    int ans=tp?-INF:0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        int g=getv(id[top[x]],id[x],tp);
        if(tp)ans=max(ans,g);
        else ans+=g;
        x=f[top[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    int g=getv(id[y],id[x],tp);
    if(tp)ans=max(ans,g);
    else ans+=g;
    return ans;
}
int main(){
    int n=gi();
    for(int i=1;i<n;i++)add(gi(),gi());
    dfs1(1);
    dfs2(1,1);
    D=log(n+1)/log(2)+1;K=1<<D;
    for(int i=1;i<=n;i++)val[K+id[i]][0]=val[K+id[i]][1]=gi();
    for(int i=K-1;i;i--)update(i);
    char ask[10];
    int q=gi();
    while(q--){
        scanf("%s",ask);
        if(ask[0]=='C')up(gi(),gi());
        else if(ask[2]=='U')printf("%d\n",query(gi(),gi(),0));
        else if(ask[2]=='A')printf("%d\n",query(gi(),gi(),1));
    }
    return 0;
}
