#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
const int maxm = 5e4 + 10;
typedef pair<int,pair<int, int> > piii;
typedef pair<int,int> pii;
int n, m, q, x, y, z;
vector<pii> E[maxn];
piii edges[maxm];
int dad[maxn], fa[20][maxn], mn[20][maxn], depth[maxn];
int find(int x){return x == dad[x] ? x : dad[x] = find(dad[x]);}
bool unionn(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    dad[fx] = fy;
    return true;
}
void dfs(int x){
    //cerr << x << ": " << mn[0][x] << endl;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(i->first == fa[0][x]) continue;
        depth[i->first] = depth[x] + 1;
        fa[0][i->first] = x, mn[0][i->first] = i->second;
        dfs(i->first);
    }
}
int LCA(int x, int y){
    int res = 1e6 + 10;
    if(depth[x] < depth[y]) swap(x, y);
    for(int i = 19; i >= 0; i--){
        if(depth[fa[i][x]] < depth[y]) continue;
        res = min(res, mn[i][x]), x = fa[i][x];
    }
    if(x == y) return res;
    for(int i = 19; i >= 0; i--){
        if(fa[i][x] == fa[i][y]) continue;
        res = min(res, mn[i][x]), res = min(res, mn[i][y]);
        x = fa[i][x], y = fa[i][y];
    }
    return min(res, min(mn[0][x], mn[0][y]));
}
int main(){
    memset(mn, 0x3f, sizeof(mn));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) dad[i] = i;
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &x, &y, &z);
        edges[i].first = z;
        edges[i].second.first = x;
        edges[i].second.second = y;
    }
    sort(edges+1, edges+1+m);
    int k = 0;
    for(int i = m; i >= 1; i--){
        int x = edges[i].second.first, y = edges[i].second.second;
        if(unionn(x, y)){
            E[x].push_back(make_pair(y, edges[i].first));
            E[y].push_back(make_pair(x, edges[i].first));
            k++;
        }
        if(k == n-1) break;
    }
    for(int i = 1; i<= n; i++){
        if(depth[i] == 0){
            depth[i] = 1;
            dfs(i);
            fa[0][i] = i;
        }
    }

    for(int j = 1; j <= 19; j++){
        for(int i = 1; i <= n; i++){
            fa[j][i] = fa[j-1][fa[j-1][i]];
            mn[j][i] = min(mn[j-1][i], mn[j-1][fa[j-1][i]]);
        }
    }

    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &x, &y);
        if(find(x) != find(y)){puts("-1"); continue;}
        printf("%d\n", LCA(x, y));
    }
    return 0;
}
