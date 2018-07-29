#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 100001
#define maxm 1000001
using namespace std;
int Index,instack[maxn],DFN[maxn],LOW[maxn];
int tot,color[maxn],sum[maxn];
int numedge,head[maxn];
struct Edge{
    int nxt,to;
}edge[maxm];
int sta[maxn],top;
int n,m,val[maxn],x[maxm],y[maxm],MOD,ans;
int queue[maxn],h,t,indg[maxn],f[maxn];
void add(int a,int b){
    edge[++numedge].to=b;
    edge[numedge].nxt=head[a];
    head[a]=numedge;
}
void tarjan(int x){
    sta[++top]=x;
    instack[x]=1;
    DFN[x]=LOW[x]=++Index;
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
            color[sta[top]]=tot;
            sum[tot]++;
            instack[sta[top--]]=0;
        }while(sta[top+1]!=x);
    }
}
bool cmp(Edge l1,Edge l2){
  return l1.
}
int main(){
    cin>>n>>m>>MOD;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        add(x[i],y[i]);
    }
    for(int i=1;i<=n;i++) if(!DFN[i]) tarjan(i);

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
          add(color[i],color[u]),indg[color[u]]++;
      }
    for(int i=1;i<=tot;i++){
      if(!indg[i]){
        queue[++t]=i;

      }
    }
    printf("%d",ans);
    return 0;
}
