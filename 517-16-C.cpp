#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn = 1e4 + 10;
int n, k, a, b, mxsize[maxn], size[maxn], dis[maxn];
int depth[maxn], fa[22][maxn];
ll ans, res;
bool baned[maxn];
vector<int> E[maxn];
void dfs(int, int, int);
int LCA(int, int);
void solve1(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            int lca = LCA(i, j);
            //
            //cerr << depth[i] + depth[j] -depth[lca] * 2 << endl;
            if(depth[i] + depth[j] - depth[lca] * 2 != k) continue;
            res = 0;
            for(int x = i; x != lca; x = fa[0][x]){
                baned[x] = true;
                dis[x] = 0,
                dfs(x, fa[0][x], 1);
            }
            for(int y = j; y != lca; y = fa[0][y]){
                baned[y] = true;
                dis[y] = 0;
                dfs(y, fa[0][y], 1);
            }
            dis[lca] = 0;
            baned[lca] = true;
            dfs(lca, -1, 1);
            for(int x = i; x != lca; x = fa[0][x]) baned[x] = false;
            for(int y = j; y != lca; y = fa[0][y]) baned[y] = false;
            baned[lca] = false;
            ans = min(ans, res);
        }
    printf("%lld\n", ans);
}
void solve2(){
    dfs(0, 0, 2);
    int key = 0;
    for(int i = 0; i < n; i++)
        if(n - size[i] <= n/2 && mxsize[i] <= n/2){
            key = i;
            break;
        }
	dis[key] = 0, res = 0;
    dfs(key, key, 1);
    ans = res;
    dfs(key, key, 2);
    ans -= mxsize[key];
    printf("%lld\n", ans);
}
void solve3(){
    dfs(0, 0, 2);
    int key = 0;
    for(int i = 0; i < n; i++)
        if(n - size[i] <= n/2 && mxsize[i] <= n/2){
            key = i;
            break;
        }
	res = 0, dis[key] = 0;
    dfs(key, key, 1);
    ans = res;
    dfs(key, key, 2);
    int mx1 = 0;
    res = 0;
    //cerr << key << endl;
    //cerr << ans << endl;
    for(auto i = E[key].begin(); i != E[key].end(); i++){
        if(mx1 != 0){
            res = max(res, (ll)(mx1 + size[*i]));
            //cerr << "#" << res << endl;
        }
        mx1 = max(mx1, size[*i]);
        for(auto j = E[*i].begin(); j != E[*i].end(); j++){
            if(*j == key) continue;
            //cerr << *i << " " << *j << endl;
            res = max(res,(ll)(size[*i] + size[*j]));
        }
    }
    //cerr << res << endl;
    ans = ans - res;
    printf("%lld\n", ans);
}
int main(){
    //freopen("data.in", "r", stdin);
    //freopen("out2.out", "w", stdout);
    while(scanf("%d%d", &n, &k)){
        if(n == 0 && k == 0) return 0;
        memset(mxsize, 0, sizeof(mxsize));
        memset(dis, 0, sizeof(dis));
        memset(depth, 0, sizeof(depth));
        memset(fa, 0, sizeof(fa));
        memset(baned, 0, sizeof(baned));
        ans = 1ll << 60;
        for(int i = 0; i <= n; i++) E[i].clear();
        for(int i = 1; i < n; i++)
            scanf("%d%d", &a, &b),
            E[a].push_back(b), E[b].push_back(a);

        dfs(0, 0, 0);
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= n; j++)
                fa[i][j] = fa[i-1][fa[i-1][j]];
        /*
        solve3();
        //*/
        //*
        if(n <= 100) solve1();
        else if(k == 1) solve2();
        else if(k == 2) solve3();
        //*/
        //cerr << "####" << endl;
    }
    return 0;
}
void dfs(int x, int dad, int mode){
    mxsize[x] = 0;
    size[x] = 1;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i == dad || baned[*i]) continue;
        if(mode == 0){
            fa[0][*i] = x;
            depth[*i] = depth[x] + 1;
        }
        if(mode == 1){
            dis[*i] = dis[x] + 1;
            res = res + dis[*i];
        }
        dfs(*i, x, mode);
        if(mode == 2){
            size[x] += size[*i];
            mxsize[x] = max(mxsize[x], size[*i]);
        }
    }
}
int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    for(int i = 20; i >= 0; i--)
        if(depth[fa[i][x]] >= depth[y]) x = fa[i][x];
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
        if(fa[i][x] != fa[i][y])
            x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}
