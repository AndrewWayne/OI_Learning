#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 10001
#define maxm 50005
using namespace std;
int Index,instack[maxn],DFN[maxn],LOW[maxn];
int tot,color[maxn],sum[maxn],outd[maxn];
int numedge,head[maxn];
struct Edge{
    int nxt,to;
}edge[maxm];
int sta[maxn],top;
int n,m,x,y,ans;
void add(int x,int y){
    edge[++numedge].to=y;
    edge[numedge].nxt=head[x];
    head[x]=numedge;
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
        }while(x!=sta[top+1]);//while放后面很重要
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        add(x,y);
    }
    for(int i=1;i<=n;i++) if(!DFN[i]) tarjan(i);
    for(int i=1;i<=n;i++)
      for(int p=head[i];p;p=edge[p].nxt){
          int u=edge[p].to;
          if(color[i]!=color[u])
              outd[color[i]]++;
          }
    bool have=false;
    ans=0;
    for(int i=1;i<=tot;i++){
        if(outd[i]==0){
          if(have){printf("0");return 0;}
          ans=i;
          have=true;
        }
    }
    printf("%d",sum[ans]);
    return 0;
}
