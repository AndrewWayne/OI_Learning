#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 10001
#define maxm 100001
using namespace std;
int Index,instack[maxn],DFN[maxn],LOW[maxn];
int tot,color[maxn],sum[maxn];
int numedge,head[maxn];
struct Edge{
    int nxt,to;
}edge[maxm];
int sta[maxn],top;
int n,m,val[maxn],x,y,ans;
void add(int x,int y){
    edge[++numedge].to=y;
    edge[numedge].nxt=head[x];
    head[x]=numedge;
}
void tarjan(int x){
    sta[++top]=x;
    instack[x]=1;
    DFN[x]=LOW[x]= ++Index;
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!DFN[v]){
            tarjan(v);
            LOW[x]=min(LOW[x],LOW[v]);
        }
        else if(instack[v]){
            LOW[x]=min(LOW[x],DFN[v]);
        }
    }
    if(DFN[x]==LOW[x]){
        tot++;
        do{
            color[sta[top]]=tot;//新图点号
            sum[tot]++;//新图点权
            instack[sta[top--]]=0;
        }while(sta[top+1]!=x);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++) if(!DFN[i]) tarjan(i);
    for(int i = 1; i <= n; i++)
        cerr << color[i] << " ";
    cerr << endl;
    numedge=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
    for(int i=1;i<=m;i++){
        edge[i].nxt=0;
        edge[i].to=0;
    }
    for(int i=1;i<=n;i++)
      for(int p=head[i];p;p=edge[p].nxt){
        int u=edge[p].to;
        if(color[i]!=color[u])
            add(color[i],color[u]);//重新建图成DAG
      }
    printf("%d",ans);
    return 0;
}
