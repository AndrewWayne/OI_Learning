#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#define min(a,b) a<b?a:b
using namespace std;
const int maxn=10010;
const int maxm=500500;
struct node{
    int id,dis;
    friend bool operator<(node u,node v){
        return u.dis<v.dis;
    }
};
struct Edge{
    int to,dis,nxt;
}edge[maxm];
priority_queue <node> choose;
int n,m,s,f,g,w,dis[maxn],nume,head[maxn];
bool vis[maxn];
void add(int u,int v,int dis){
    edge[++nume].nxt=head[u];
    edge[nume].to=v;
    edge[nume].dis=dis;
    head[u]=nume;
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&f,&g,&w);
        add(f,g,w);
    }
    memset(dis,127,sizeof(dis));
    dis[s]=0;
    node q;
    q.id=s;
    q.dis=0;
    choose.push(q);
    while(!choose.empty()){
        int x=choose.top().id;
        choose.pop();
        if(!vis[x]){
            vis[x]=true;
            for(int i=head[x];i;i=edge[i].nxt){
                int v=edge[i].to;
                dis[v]=min(dis[v],dis[x]+edge[i].dis);
                choose.push({v,dis[v]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}
