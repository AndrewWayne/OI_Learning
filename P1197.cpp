#include <cstdio>
#include <iostream>
using namespace std;
struct Edge{
    int from,to,nxt;
}edge[400400];
int n,m,u,v,k,nume,head[400400],hit[400400],temp,numblock,ans[400400];
bool hitted[400400];
int dad[400400];
int find(int x){
    if(dad[x]==x)return x;
    return dad[x]=find(dad[x]);
}
void unionn(int x,int y){
    x=find(x),y=find(y);
    if(x!=y)dad[y]=x;
}
void add(int x,int y){
    edge[++nume].nxt=head[x];
    edge[nume].from=x;
    edge[nume].to=y;
    head[x]=nume;
}
void fix(int x,int y){
    if(find(x)==find(y))return;//不在同一块中
    unionn(x,y);
    numblock--;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<=n;i++)//编号是0～n-1
        head[i]=-1,dad[i]=i;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    cin>>k;
    numblock=n-k;//假装是一片废墟，所有点失联
    for(int i=1;i<=k;i++){
        cin>>hit[i];
        hitted[hit[i]]=true;
    }
    for(int i=1;i<=2*m;i++){//及其懵逼……为什么一定要按边遍历，按点遍历，再套临接表就莫名其妙的各种WA(Too many or too few lines)，TLE（但是我算起来感觉还快了一点啊……）
      if(!hitted[edge[i].from]&&!hitted[edge[i].to])//边是好的
        fix(edge[i].from,edge[i].to);//维修好刚刚假装断掉的连接
    }
    ans[k+1]=numblock;
    for(int i=k;i>=1;i--){
        u=hit[i];
        numblock++;
        hitted[u]=false;
        for(int p=head[u];p!=-1;p=edge[p].nxt){//判连通性
            v=edge[p].to;
            if(!hitted[v])
              fix(u,v);
        }
        ans[i]=numblock;
    }
    for(int i=1;i<=k+1;i++)
        cout<<ans[i]<<endl;
    return 0;
}
