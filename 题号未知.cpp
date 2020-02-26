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
int n, m, x, y, t, fa[22][maxn], depth[maxn];
vector<pii> E[maxn];
ll sum, tag[maxn], len[maxn], maxv;
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
        cerr << x << "---" << i->first << ": " << tag[i->first] << endl;
        maxv = max(maxv, tag[i->first] * i->second);
        tag[x] += tag[i->first];
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++){
        scanf("%d%d%d", &x, &y, &t);
        E[x].push_back(make_pair(y, t));
        E[y].push_back(make_pair(x, t));
    }
    fa[0][1] = 1;
    dfs(1);
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
            fa[i][j] = fa[i-1][fa[i-1][j]];

    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        sum += len[x] + len[y] - len[LCA(x, y)] * 2;
        tag[x]++, tag[y]++, tag[LCA(x, y)] -= 2;
    }
    dfs1(1, 0);
    cerr << sum << endl;
    cerr << maxv << endl;
    printf("%lld", sum - maxv);
    return 0;
}
