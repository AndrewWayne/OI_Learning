#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 10001
#define maxm 100001
using namespace std;
//洛谷高票记搜题解更顺眼邻接表版OwO
//记搜TLE点一，WA了点7
int Index,instack[maxn],DFN[maxn],LOW[maxn];
int tot,color[maxn],sum[maxn],outd[maxn];
int numedge,head[maxn];
struct Edge{
    int nxt,to;
}edge[maxm];
int sta[maxn],top;
int n,m,val[maxn],x[maxm],y[maxm],ans;
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
        while(sta[top+1]!=x){
            color[sta[top]]=tot;
            sum[tot]+=val[sta[top]];
            instack[sta[top--]]=0;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++){
        cin>>x[i];
        cin>>y[i];
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
    for(int i=1;i<=m;i++){
        if(color[x[i]]!=color[y[i]]){
            add(color[x[i]],color[y[i]]);
            outd[color[x[i]]]++;
        }
    }
    bool have=false;
    for(int i=1;i<=tot;i++){
      if(outd[i]==0)
        if(!have)ans=sum[i];
        else ans=0;
    }
    printf("%d",ans);
    return 0;
}
