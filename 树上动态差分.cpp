/*
 * Author: xiaohei_AWM
 * Date: 5.18
 * Mutto: Face to the weakness, expect for the strength.
 * Problems:有n个点的一棵树，有m个操作，分为两类：
 * (1):1 x y d:把x到y路径上每个点的权值加d
 * (2):2 x:询问x点的权值
 * Solution:
 * 树剖LCA+BIT+DFS序+树上差分
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
struct Edge{
    int nxt, to;
}edge[2*maxn];
struct BIT{
    int c[maxn], limit;
    int lowbit(int x){
        return x & -x;
    }
    void add(int pos, int x){
        for(int i = pos; i <= limit; i += lowbit(i))
            c[i] += x;
    }
    ll query(int pos){
        ll res = 0;
        for(int i = pos; i; i -= lowbit(i))
            res += c[i];
        return res;
    }
}Bit;
int fa[maxn], dep[maxn], son[maxn], size[maxn] = {0}, head[maxn], L[maxn], R[maxn], tot, cnt, n, m, u, v, d, s, opt;//size记录子树大小, son[x]记录x节点重儿子
int top[maxn];//x沿所在重链能到达的最高点
void add(int u, int v){
    edge[++cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}
void dfs(int _node, int _father, int _depth){
    L[_node] = ++tot;
    fa[_node] = _father;
    dep[_node] = _depth;
    size[_node] = 1;
    son[_node] = 0;
    for(int i = head[_node]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(v == _father) continue;
        dfs(v, _node, _depth+1);
        size[_node] += size[v];
        if(size[v] > size[son[_node]]) son[_node] = v;
    }
    R[_node] = tot;
}
void dfs2(int _node, int _father){
    top[_node] = _father;
    if(son[_node]) dfs2(son[_node], _father);
    for(int i = head[_node]; i; i = edge[i].nxt){
        int v = edge[i].to;
        if(v == fa[_node] || v == son[_node]) continue;
        dfs2(v, v);
    }
}
int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] >= dep[top[y]])
            x = fa[top[x]];
        else
            y = fa[top[y]];
    }
    return dep[x] > dep[y] ? y : x;
}
int main(){
    n = read(), m = read();
    Bit.limit = n+5;
    memset(Bit.c, 0, sizeof(Bit.c));
    for(int i = 1; i <= n-1; i++)
        u = read(), v = read(),
        add(u, v), add(v, u);
    dfs(1, 0, 0);
    dfs2(1, 1);
    //for(int i = 1; i <= n; i++)
    //    for(int j = 1; j <= n; j++)
    //        printf("LCA %d -- %d : %d\n", i, j, LCA(i, j));
    for(int i = 1; i <= m; i++){
        opt = read();
        if(opt == 1){
            u = read(), v = read(), d = read();
            int lca = LCA(u, v);
            Bit.add(L[u], d);
            Bit.add(L[v], d);
            Bit.add(L[lca], -d);
            if(fa[lca]) Bit.add(L[fa[lca]], -d);
        }if(opt == 2){
            u = read();
            printf("%lld\n", Bit.query(R[u]) - Bit.query(L[u]-1));
        }
    }
    //for(int i = 1; i <= n; i++)
    //    printf("Element%d: son - %d, top - %d\n", i, son[i], top[i]);
    return 0;
}
/*
Example:
5 4
1 2
1 3
3 4
3 5
1 3 4 1
2 3
1 1 5 2
2 3

Output:
1
3

Example
10 3
10 9
3 1
8 2
3 8
7 3
5 9
8 5
8 6
4 6
1 3 9 2
1 8 7 1
2 3

3
*/
