/*
 * Author: xiaohei_AWM
 * Date: 8.5
 * Mutto: Face to the weakness, expect for the strength.
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 1e4+10;
const int maxm = 1e5+10;
struct Edge{
    int to, nxt, weight;
}edges[2*maxm];
struct Edge1{
    int u, v, weight;
}ee[2*maxm];
int n, m, a[maxn], x, y, z, q, cnt, head[maxn], fa[maxn], ncstr[30][maxn], minw[30][maxn], depth[maxn], visited[maxn];
int find(int x){
    return x == fa[x]? x : fa[x] = find(fa[x]);
}
void unionn(int u, int v){
    int fu = find(u), fv = find(v);
    if(fu == fv) return;
    fa[fu] = fv;
}
void add(int u, int v, int w){
    edges[++cnt].nxt = head[u];
    edges[cnt].to = v;
    edges[cnt].weight = w;
    head[u] = cnt;
}
void dfs(int x, int frther){
    visited[x] = 1;
    for(int i = head[x]; i; i = edges[i].nxt){
        int  to = edges[i].to;
        if(visited[to]) continue;
        depth[to] = depth[x] + 1;
        ncstr[0][to] = x;
        minw[0][to] = edges[i].weight;
        dfs(to, x);
    }
}
bool cmp(Edge1 a, Edge1 b){
    return a.weight > b.weight;
}
int query(int l, int r){
    if(find(l) != find(r)) return -1;
    int res = INF;
    if(depth[l] > depth[r]) swap(l, r);
    for(int k = 20; k >= 0; k--)
        if(depth[ncstr[k][r]] >= depth[l])
            res = min(res, minw[k][r]),
            r = ncstr[k][r];
    if(l == r) return res;
    for(int k = 20; k >= 0; k--){
        if(ncstr[k][l] != ncstr[k][r])
            res = min(res, min(minw[k][l], minw[k][r])),
            l = ncstr[k][l], r = ncstr[k][r];
    }
    res = min(res, min(minw[0][l], minw[0][r]));
    return res;
}
int main(){
    n = read(), m = read();
    memset(minw, 0x7f, sizeof(minw));
    for(int i = 1; i <= m; i++){
        x = read(), y = read(), z = read();
        ee[i].u = x, ee[i].v = y, ee[i].weight = z;
    }
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    sort(ee+1, ee+1+m, cmp);
    int k = 0;
    for(int i = 1; i <= m; i++){
        x = ee[i].u, y = ee[i].v, z = ee[i].weight;
        if(find(x) == find(y)) continue;
        unionn(x, y);
        add(x, y, z);
        add(y, x, z);
        //cerr << x << " " << y << endl;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            depth[i] = 1;
            dfs(i, 0);
            ncstr[0][i] = i;
        }
    //    cerr << i << ": " << minw[0][i] << endl;
    }
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i <= n; i++)
            ncstr[j][i] = ncstr[j-1][ncstr[j-1][i]],
            minw[j][i] = min(minw[j-1][i], minw[j-1][ncstr[j-1][i]]);
    q = read();
    while(q--){
        x = read(), y = read();
        printf("%d\n", query(x, y));
    }

    return 0;
}
