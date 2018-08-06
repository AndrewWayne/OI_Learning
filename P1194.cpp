#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int dad[100001],nume;
long long a,b,k,n,ans;
struct Edge{
    int from,to;
    long long dis;
    //bool operator<(const Edge &v){return dis<v.dis;}
}edge[1000010];
bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}
void add(int u,int v,long long dis){
    edge[++nume].from=u;
    edge[nume].to=v;
    edge[nume].dis=dis;
}
int find(int x){
    return x==dad[x]?x:dad[x]=find(dad[x]);
}
void unionn(int u,int v){
    int fu=find(u);
    int fv=find(v);
    dad[fu]=fv;
}
int main(){
    cin>>a>>n;
    for(int i=1;i<=n;i++){
        add(i,n+1,a);
        add(n+1,i,a);
        dad[i]=i;
    }
    dad[n+1]=n+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>k;
            if(k!=0)
                add(i,j,k);
        }
    sort(edge+1,edge+1+nume,cmp);
    k=0;
    for(int i=1;i<=nume;i++){
        int u=find(edge[i].from);
        int v=find(edge[i].to);
        if(u==v)
            continue;
        unionn(u,v);
        ans+=edge[i].dis;
        k++;
        if(k==n)
            break;
    }
    cout<<ans;
    return 0;
}
