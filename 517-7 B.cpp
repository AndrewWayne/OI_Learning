#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
int n, m, a, b;
vector<int> E[maxn], E3[maxn];
set<int> E2[maxn];
int q, color[maxn], fa[maxn], cnt, node[maxn];
int depth[maxn], ncstr[23][maxn], leng[maxn];
ll power_two[maxn];
bool visited[maxn];
void dfs(int x, int f){
    for(int i = 1; i <= 20; i++)
        ncstr[i][x] = ncstr[i-1][ncstr[i-1][x]];
    for(auto i = E2[x].begin(); i != E2[x].end(); i++){
        if(*i != f){
            ncstr[0][*i] = x;
            depth[*i] = depth[x] + 1;
            leng[*i] = leng[x] + node[*i];
            dfs(*i, x);
        }
    }
}
void goUp(int &x, int len){
    for(int i = 20; i >= 0; i--)
        if((1 << i) <= len) len -= 1 << i, x = ncstr[i][x];
}
int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    goUp(x, depth[x] - depth[y]);
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
        if(ncstr[i][x] != ncstr[i][y]) x = ncstr[i][x], y = ncstr[i][y];
    return ncstr[0][x];
}
void dfs1(int x, int f){
    //cerr << x << endl;
    if(visited[x]){
        color[x] = ++cnt;
        int u = x;
        while(fa[u] != x){
            color[fa[u]] = cnt;
            u = fa[u];
        }
        return;
    }
    visited[x] = true;
    //cerr << "size: " << E[x].size() << endl;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i != f && !color[*i]){
            //cerr << "$" << *i << endl;
            fa[*i] = x, dfs1(*i, x);
        }
    }
}
ll query(int x, int y){
    if(color[x] == color[y]) return 2;
    int lca = LCA(color[x], color[y]);
    //cerr << color[x] << " " << color[y] << endl;
    //cerr << "$:" << leng[color[x]] << " " << leng[color[y]] << endl;
    //cerr << "$:" << lca << endl;
    ll len = leng[color[x]] + leng[color[y]] - 2 * leng[lca];
    len += node[lca];
    //cerr << len << endl;
    len = power_two[len];
    return len;
}
int main(){
    scanf("%d%d", &n, &m);
    power_two[0] = 1;
    for(int i = 1; i <= n; i++){
        power_two[i] = (power_two[i-1] << 1) % MOD;
    //    cerr << power_two[i] << endl;
    }
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs1(1, 0);
    //cerr << "OK" << endl;
    //for(int i = 1; i <= n; i++)
    //    cerr << color[i] << " ";
    //cerr << cnt << endl;
    //cerr << 111 << endl;
    for(int i = 1; i <= cnt; i++){
        //cerr << i << endl;
        node[i] = 1;
        //cerr << "i" << endl;
    }
    for(int i = 1; i <= n; i++)
        if(color[i] == 0) color[i] = ++cnt;
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= n; i++){
        for(auto j = E[i].begin(); j != E[i].end(); j++){
            if(color[i] != color[*j])
                E2[color[i]].insert(color[*j]);
        }
    }
    leng[1] = node[1];
    dfs(1, 0);

    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d%d", &a, &b);
        printf("%lld\n", query(a, b));
    }
    return 0;
}
