#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge{
    int u,v,dis;
    const bool operator<(const Edge &v){
        return dis<v.dis;
    }
}edge[200020];
int n,m,k,ans,dad[5050],rank[5050];
int find(int x){
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){//按秩合并
    int fu=find(u);
    int fv=find(v);
    if(fu==fv)return;
    if(rank[fu]<rank[fv])
        dad[fu]=fv;
    else{
        dad[fv]=fu;
        if(fu==fv)
            rank[fu]++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].dis);
    for(int i=1;i<=n;i++)
        dad[i]=i;
    sort(edge+1,edge+1+m);
    for(int i=1;i<=m;i++){
        if(find(edge[i].u)==find(edge[i].v))
            continue;
        unionn(edge[i].u,edge[i].v);
        k++;
        ans+=edge[i].dis;
        if(k==n-1)break;
    }
    if(k<n-1)
        printf("orz");
    else
        cout<<ans;
    return 0;
}
