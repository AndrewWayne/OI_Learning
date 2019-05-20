/*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 5e5 + 10;
int n, a[maxn], u, v, cnt, head[maxn], ans, top[maxn], father[maxn], depth[maxn], son[maxn], size[maxn], tot, ID[maxn], delta[maxn];
struct Edge{
    int nxt, to;
}edge[2*maxn];
void add(int u, int v){
    edge[++cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}
void dfs1(int _node, int _father, int _depth){
    depth[_node] = _depth, father[_node] = _father;
    son[_node] = 0, size[_node] = 1;
    for(int i = head[_node]; i; i = edge[i].nxt){
        int y = edge[i].to;
        if(y == _father) continue;
        dfs1(y, _node, _depth+1);
        size[_node] += size[y];
        if(size[y] > size[son[_node]]) son[_node] = y;
    }
}
void dfs2(int _node, int _ancestor){
    top[_node] = _ancestor;
    ID[_node] = ++tot;
    if(son[_node]) dfs2(son[_node], _ancestor);
    for(int i = head[_node]; i; i = edge[i].nxt){
        int x = edge[i].to;
        if(x == father[_node] || x == son[_node]) continue;
        dfs2(x, x);
    }
}
int LCA(int x, int y){
    while(top[x] != top[y]){
        if(depth[top[x]] >= depth[top[y]])
            x = father[top[x]];
        else
            y = father[top[y]];
    }
    return depth[x] > depth[y] ? y : x;
}
void dfs(int _node, int _father){
    a[_node] = delta[_node];
    for(int i = head[_node]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(v == _father) continue;
        dfs(v, _node);
        a[_node] += a[v];
    }
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n-1; i++) u = read(), v = read(), add(u, v), add(v, u);
    dfs1(1, 0, 1);
    dfs2(1, 1);
//    for(int i = 1; i <= n; i++)
//        printf("father %d : %d\n", i, father[i]);
    for(int i = 2; i <= n; i++){
        delta[ a[i-1] ]++;
        delta[ father[a[i]] ]++;
        delta[ LCA(a[i-1], a[i]) ]--;
        delta[ father[LCA(a[i-1], a[i])] ]--;
    }
//    for(int i = 1; i <= n; i++)
//        printf("delta %d : %d\n", i, delta[i]);
    memset(a, 0, sizeof(a));
    dfs(1, 0);
    for(int i = 1; i <= n; i++) cout << a[i] << endl;
    return 0;
}
