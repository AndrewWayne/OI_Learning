/*
 * Author: xiaohei_AWM
 * Date: 10.25
 * Motto: Face to the weakness, expect for the strength.
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
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
const int maxn = 3e2 + 10;
const ll MOD = 1e9 + 7;
int n, m, roots[maxn];
ll a[maxn], b[maxn], c[maxn], x[maxn], ans;
bool tree[20][20][20];
vector<int> E[maxn][maxn];
pii Edge[maxn][maxn];
int check(int id, int x, int fa){
    int res = 1;
    for(int i = 1; i <= n; i++){
        if(tree[id][x][i] && i != fa)
            res += check(id, i, x);
    }
    return res;
}
void dfs(int id){
    if(id == 1){
        for(int i = 1; i <= n-1; i++){
            tree[id][Edge[id][i].first][Edge[id][i].second] = 0;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 0;
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 1;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 1;
            dfs(id+1);
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 0;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 0;
            tree[id][Edge[id][i].first][Edge[id][i].second] = 1;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 1;
        }
    }else if(id < n){
        for(int i = 1; i <= n-1; i++){
            tree[id][Edge[id][i].first][Edge[id][i].second] = 0;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 0;
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 1;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 1;
            if(check(id, 1, 0) == n) dfs(id+1);
            tree[id][Edge[id][i].first][Edge[id][i].second] = 0;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 0;
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 1;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 1;
        }
    }else if(id == n){
        for(int i = 1; i <= n-1; i++){
            tree[id][Edge[id][i].first][Edge[id][i].second] = 0;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 0;
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 1;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 1;
            if(check(id, 1, 0) == n && check(1, 1, 0) == n) ans++;
            tree[id][Edge[id][i].first][Edge[id][i].second] = 0;
            tree[id][Edge[id][i].second][Edge[id][i].first] = 0;
            tree[id+1][Edge[id+1][i].first][Edge[id+1][i].second] = 1;
            tree[id+1][Edge[id+1][i].second][Edge[id+1][i].first] = 1;
        }
    }
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= m; i++) roots[i] = read();
    for(int i = 1; i <= m; i++) a[i] = read();
    for(int i = 1; i <= m; i++) b[i] = read();
    for(int i = 1; i <= m; i++) c[i] = read();
    for(int i = 1; i <= m; i++){
        x[0] = c[i];
        for(int k = 1; k <= n-2; k++) x[k] = (a[i] * x[k-1] + b[i]) % MOD;
        for(int j = 0; j <= n-2; j++){
            int u = (roots[i] + j + 1) % n;
            int v = (roots[i] + (x[j] % (j+1))) % n;
            E[i][u].push_back(v);
            E[i][v].push_back(u);
            tree[i][u][v] = tree[i][v][u] = 1;
            Edge[i][j+1] = make_pair(u, v);
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
