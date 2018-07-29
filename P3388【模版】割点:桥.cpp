#include<cstdio>
#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;
struct node{
    int to,nxt;
    bool bridge;
}e[200010];
int root,nume,numbridge,numcut,n,m,sum;
int head[100010],dfn[100010],low[100010],vis[100010],poi[100010];
void add(int x,int y){
    e[++nume].to=y;
    e[nume].nxt=head[x];
    head[x]=nume;
}
void tarjan(int u,int dad){
    int son=0;
    vis[u]=1; dfn[u]=low[u]=++sum;
    for(int p=head[u];p;p=e[p].nxt){
        int v=e[p].to;
        if(vis[v]==1&&v!=dad) low[u]=min(low[u],dfn[v]);//返祖边
        else if(dfn[v]==0){//父子边
            tarjan(v,u);
            son++;
            low[u]=min(low[u],low[v]);
            if((dad==-1&&son>1)||(dad!=-1&&dfn[u]<=low[v])){//多子树根与dfn[U]<=low[v]（v不可返到u上）的点为割点
                if (poi[u]==0) numcut++;
                poi[u]=1;
            }
            if(dfn[u]<low[v])
                e[p].bridge=true;
        }
    }
}
int main(){
    cin>>n>>m;//读入/存图部分，根据题意酌情修改
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }

    for (int i=1;i<=n;i++)//若题意中有说全连通则直接tarjan(i,-1)即可
        if (!dfn[i])
            tarjan(i,-1);

    printf("%d\n",numcut);//输出，根据题意酌情修改
    for (int i=1;i<=n;i++)
        if (poi[i]) printf("%d ",i);
    printf("\n");

    return 0;
}
