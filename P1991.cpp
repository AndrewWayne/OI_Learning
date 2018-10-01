#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define type int//看情况修改返回类型
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
struct Edge{
    int u,v;
    long long w;
}edge[600000];
struct Node{
    int x,y;
    bool wifi;
}graph[550];
int s,p,k,dad[550];
long long ans;
int find(int x){
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}
void unionn(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if(fu != fv)
        dad[fu] = fv;
}
bool cmp(Edge e1,Edge e2){
    return e1.w < e2.w;
}
long long calc(int u,int v){
    long long dx = graph[u].x - graph[v].x;
    long long dy = graph[u].y - graph[v].y;
    return dx*dx + dy*dy;
}
int main(){
    s = read(),p = read();
    for(int i = 1; i <= p; ++i){
        graph[i].x = read();
        graph[i].y = read();
        for(int j = i-1; j >= 1; j--){
            edge[++k].u = i;
            edge[k].v = j;
            edge[k].w = calc( i, j);
        }
        graph[i].wifi = false;
        dad[i] = i;
    }//init part

    sort( edge+1, edge+1+k, cmp);//Kruskal

    int numtree = 0;
    for(int i = 1; i <= k ; i++){
        if( find(edge[i].u) == find(edge[i].v))
            continue;
        numtree++;
        unionn( edge[i].u, edge[i].v);
        if(numtree ==  p-s){
            ans = edge[i].w;
            break;
        }
    }
    int u,v;
    printf("%.2f",sqrt(ans));
    return 0;
}
