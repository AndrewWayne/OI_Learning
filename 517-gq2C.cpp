
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int n, k, idx[maxn], dfn[maxn], depth[maxn], cnt;//dfn <-> idx构成一对双射
int fa[25][maxn], ans, a, b;
vector<int> E[maxn];
set<int> T;
void dfs(int x, int f){
    dfn[x] = ++cnt;
    idx[cnt] = x;
    for(int i = 1; i <= 20; i++)
        fa[i][x] = fa[i-1][fa[i-1][x]];
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i != f){
            depth[*i] = depth[x] + 1;
            fa[0][*i] = x;
            dfs(*i, x);
        }
    }
}
void goUp(int &x, int length){
    for(int i = 20; i >= 0; i--)
        if((1 << i) <= length){
            length -= (1 << i);
            x = fa[i][x];
        }
}
int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);//
    goUp(x, depth[x] - depth[y]);
    if(x == y) return x;
    for(int i = 20; i >= 0; i--)
        if(fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1, 0);
    int L = 1, sum = 0;//sum维护出边数
//    for(int i = 1; i <= n; i++)
//        cerr << idx[i] << " ";
//    cerr << endl;
    for(int R = 1; R <= n; R++){
        if(T.empty()) sum = 0, T.insert(dfn[R]);
        else if(T.size() == 1){
            int l = idx[*T.begin()], lca = LCA(l, R);
            sum = depth[l] + depth[R] - 2 * depth[lca];
            //cerr << "$$ " << l << endl;
            T.insert(dfn[R]);
        }else if(T.size() > 1){
            if(dfn[R] < *T.begin() || dfn[R] > *T.rbegin()){
                int l = idx[*T.begin()], r = idx[*T.rbegin()];
                int val = 0;
                int lca = LCA(l, R);
                val += depth[l] + depth[R] - 2 * depth[lca];
                lca = LCA(r, R);
                val += depth[r] + depth[R] - 2 * depth[lca];
                lca = LCA(l, r);
                val -= depth[l] + depth[r] - 2 * depth[lca];
                val /= 2;
                sum += val;
                T.insert(dfn[R]);
            }else{
                auto l = T.lower_bound(dfn[R]);
                auto r = l; l--;
                int lca = LCA(idx[*l], R);
                int val = 0;
                val += depth[idx[*l]] + depth[R] - 2 * depth[lca];
                //cerr << R << endl;
                //cerr << idx[*l] << " " << idx[*r] << endl;
                lca = LCA(idx[*r], R);
                val += depth[idx[*r]] + depth[R] - 2 * depth[lca];
                lca = LCA(idx[*l], idx[*r]);
                val -= depth[idx[*l]] + depth[idx[*r]] - 2 * depth[lca];
                val /= 2;
                sum += val;
                T.insert(dfn[R]);
            }
        }
        //cerr << "$$: " << sum << endl;
        while(!T.empty() && sum + 1 > k){
            T.erase(dfn[L]);
            if(T.size() == 1) sum = 0;
            if(T.size() > 1){
                if(dfn[L] < *T.begin() || dfn[L] > *T.rbegin()){
                    int l = idx[*T.begin()], r = idx[*T.rbegin()];
                    int lca = LCA(l, L), val = 0;
                    //cerr << lca << endl;
                    val -= depth[l] + depth[L] - 2 * depth[lca];
                    lca = LCA(r, L);

                    val -= depth[r] + depth[L] - 2 * depth[lca];
                    lca = LCA(l, r);
                    val += depth[l] + depth[r] - 2 * depth[lca];
                    val /= 2;
                    sum += val;
                }else{
                    auto l = T.lower_bound(dfn[L]);
                    auto r = l--;
                    int lca = LCA(idx[*l], L), val = 0;
                    val -= depth[idx[*l]] + depth[L] - 2 * depth[lca];
                    lca = LCA(idx[*r], L);
                    val -= depth[idx[*r]] + depth[L] - 2 * depth[lca];
                    lca = LCA(idx[*l], idx[*r]);
                    val += depth[idx[*l]] + depth[idx[*r]] - 2 * depth[lca];
                    val /= 2;
                    sum += val;
                }
            }
            L++;
        }
        ans = max(R-L+1, ans);
    }
    printf("%d\n", ans);
    return 0;
}
