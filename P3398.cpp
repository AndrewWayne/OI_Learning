/*
 * Author: xiaohei_AWM
 * Date: 5.20
 * Mutto: Face to the weakness, expect for the strength.
 * Note: 1.每个点最多跳log条重链即可到达根
 *
 *       2.每跳到一个新的重链，所在的size至少扩大一倍
 *
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
int fa[maxn], dep[maxn], son[maxn], size[maxn] = {0}, head[maxn], ID[maxn], tot, cnt, n, m, u, v, x, y;//size记录子树大小, son[x]记录x节点重儿子
int top[maxn];//x沿所在重链能到达的最高点
void add(int u, int v){
    edge[++cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
}
void dfs(int _node, int _father, int _depth){
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
}
void dfs2(int _node, int _father){
    top[_node] = _father;
    ID[_node] = ++tot;
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
    for(int i = 1; i <= n-1; i++)
        u = read(), v = read(),
        add(u, v), add(v, u);
    dfs(1, 0, 0);
    dfs2(1, 1);
    for(int i = 1; i <= m; i++){
        u = read(), v = read(), x = read(), y = read();
        int a = LCA(u, v), b = LCA(x, y);
        if(dep[a] >= dep[b] && (LCA(x, a) == a || LCA(y, a) == a))
            printf("Y\n");
        else if(dep[a] < dep[b] && (LCA(b, u) == b || LCA(b, v) == b))
            printf("Y\n");
        else
            printf("N\n");
    }
    //for(int i = 1; i <= n; i++)
    //    printf("Element%d: son - %d, top - %d\n", i, son[i], top[i]);
    return 0;
}
/*
*/
