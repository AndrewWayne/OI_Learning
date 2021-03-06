#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 3e5 + 10;
int n, m, u, v, x[maxn], y[maxn], lca[maxn], t, fa[22][maxn], depth[maxn];
vector<pii> E[maxn];
int tag[maxn], len[maxn], maxd;
void dfs(int x){
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(i->first == fa[0][x]) continue;
        fa[0][i->first] = x;
        len[i->first] = len[x] + i->second;
        depth[i->first] = depth[x] + 1;
        dfs(i->first);
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
void dfs1(int x, int fa){
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(i->first == fa) continue;
        dfs1(i->first, x);
        //cerr << x << "---" << i->first << ": " << tag[i->first] << endl;
        tag[x] += tag[i->first];
    }
}
bool check(int ans){
    //cerr << "##" << ans << endl;
    memset(tag, 0, sizeof(tag));
    int delta = 0, tot = 0;
    for(int i = 1; i <= m; i++){
        int dis = len[x[i]] + len[y[i]] - len[lca[i]] * 2;
        if(dis > ans){
            tag[x[i]]++, tag[y[i]]++, tag[lca[i]] -= 2;
            delta = max(delta, dis - ans);
            tot++;
            //cerr << x[i] << " -- " << y[i] << endl;
            //cerr << dis << endl;
        }
    }
    //cerr << delta << endl;
    dfs1(1, 0);
    //for(int i = 1; i <= n; i++)
    //    cerr << i << ": " << tag[i] << endl;
    for(int i = 1; i <= n; i++){
        for(auto j = E[i].begin(); j != E[i].end(); j++){
            if(j->first == fa[0][i]) continue;
            if(tag[j->first] == tot && j->second >= delta)
                return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++){
        scanf("%d%d%d", &u, &v, &t);
        E[u].push_back(make_pair(v, t));
        E[v].push_back(make_pair(u, t));
    }
    fa[0][1] = 1;
    dfs(1);
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
            fa[i][j] = fa[i-1][fa[i-1][j]];
    for(int i = 1; i <= m; i++){
        scanf("%d%d", x+i, y+i);
        lca[i] = LCA(x[i], y[i]);
    }
    int ans = 0;
    for(int i = 20; i >= 0; i--)
        if(!check(ans + (1 << i)))
            ans += (1 << i);
    if(!check(ans)) ans++;
    printf("%d", ans);
    return 0;
}
