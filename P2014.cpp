/*
 *Author: xiaohei_AWM
 *Date: 2019.4.13
 *Mutto: Face to the weakness, expect for the strength.
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
const int maxn = 310;
struct Edge{
    int to, val, nxt;
}edge[2*maxn];
int n, q, val[maxn], head[maxn], u, v, cnt;
int xsize[maxn], f[maxn][maxn], tmp[maxn];// 状态设计：f[x][m]表示在以x为根的子树上选m个节点（不包含x自身）的最优解
void add(int u, int v){
    edge[++cnt].nxt = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
}
void dfs(int x, int fa){
    for(int i = head[x]; i != -1; i = edge[i].nxt){
        int v = edge[i].to;
        if(v != fa){
            dfs(v, x);
            xsize[x] += xsize[v] + 1;
            memset(tmp, 0, sizeof(tmp));
            for(int k = 0; k <= min(xsize[x], q); k++)
                for(int j = 1; j <= min(xsize[v]+1, k); j++)
                    tmp[k] = max(tmp[k], f[x][k - j] + f[v][j-1] + val[v]);
            for(int j = 1; j <= q; j++) f[x][j] = max(f[x][j], tmp[j]);
        }
        // cerr << "$: " << xsize[x] << " " << f[x][xsize[x]] << endl;
    }
}
int main(){
    n = read(), q = read();
    memset(head, 0xff, sizeof(head));
    for(int i = 1; i <= n; i++){
        u = read(), val[i] = read();
        add(u, i);
    }
    dfs(0, -1);
    cout << f[0][q] << endl;
    return 0;
}
