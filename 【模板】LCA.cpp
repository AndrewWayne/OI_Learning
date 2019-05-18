/*
 * Author: xiaohei_AWM
 * Date:5.11
 * Mutto: Face to the weakness, expect for the strength.
 * Updated: Add Dfs Order
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const int maxn = 1e5 + 10;
struct Edge{
    int nxt, to, val;
} edge[2*maxn];
int n, m, s, u, v, len, fa[maxn][30], dis[maxn], depth[maxn], head[maxn], cnt, L[maxn], R[maxn], tot;//dis[i]表示节点到0的距离
void add(int u, int v, int w){
    edge[++cnt].nxt = head[u];
    edge[cnt].to = v;
    edge[cnt].val = w;
    head[u] = cnt;
}
void dfs(int x){
    for(int i = 1; i <= 20; i++)
        fa[x][i] = fa[fa[x][i-1]][i-1];
    for(int i = head[x]; i; i = edge[i].nxt){
        v = edge[i].to;
        if(v == fa[x][0]) continue;
        fa[v][0] = x;
        depth[v] = depth[x] + 1;
        dis[v] = dis[x] + edge[i].val;
        dfs(v);
    }
}
void goUp(int &node, int step){
    for(int i = 20; i >= 0 && step != 0; i--){
        if(step - (1 << i) >= 0)
            step -= 1<< i,
            node = fa[node][i];
    }
}
int LCA(int x, int y){
    if(depth[x] > depth[y]) goUp(x, depth[x] - depth[y]);
    else if(depth[x] < depth[y]) goUp(y, depth[y] - depth[x]);
    if(x == y)
        return x;
    for(int i = 20; i >= 0; i--)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int main(){
    n = read(), m = read(), s =read();
    for(int i = 1; i <= n-1; i++)
        u = read(), v = read(), len = read(),
        add(u, v, len), add(v, u, len);
    depth[s] = 1;
    dfs(s);
    for(int i = 1; i <= m; i++){
        u = read(), v = read();
        cout << dis[u] + dis[v] - 2*dis[LCA(u, v)] << endl;
    }
    return 0;
}
