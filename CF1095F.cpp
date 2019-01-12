#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 10;
struct Edge{
    int u, v;
    long long dis;
    const bool operator<(const Edge &v)const{
        return dis<v.dis;
    }
}edge[4*maxn];
int n,m,k,dad[maxn],ranks[maxn];
long long ans, a[maxn], root, minv = 1e12+1;
int find(int x){
    return dad[x]==x?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){//按秩合并
    int fu=find(u);
    int fv=find(v);
    if(fu==fv)return;
    if(ranks[fu]<ranks[fv])
        dad[fu]=fv;
    else{
        dad[fv]=fu;
        if(fu==fv)
            ranks[fu]++;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        if(minv > a[i]){
            root = i;
            minv = a[i];
        }
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].dis);
    for(int i = 1; i <= n; i++){
        if(i == root) continue;
        edge[m++].u = root;
        edge[m].v = i;
        edge[m].dis = a[i] + minv;
    }
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
