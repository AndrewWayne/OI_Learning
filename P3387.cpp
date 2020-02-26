#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int n, m, x, y, w[maxn], dfn[maxn], low[maxn], visited[maxn], cnt;
int color[maxn], tot, sum[maxn];
bool instack[maxn];
stack<int> S;
vector<int> E[maxn], DAG[maxn];
void dfs(int x){
    //cerr << "X: " << x << endl;
    visited[x] = true;
    S.push(x), instack[x] = true;
    low[x] = dfn[x] = ++cnt;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(!visited[*i]){//树边
            dfs(*i);
            low[x] = min(low[x], low[*i]);
        }else if(instack[*i]){//返祖边
            low[x] = min(low[x], dfn[*i]);
        }
    }
    if(dfn[x] == low[x]){//回点
        tot++;
        int tmp = S.top();
        while(instack[x]){
            tmp = S.top();
            S.pop();
            color[tmp] = tot;
            instack[tmp] = 0;
            color[tmp] = tot;
            sum[tot] += w[tmp];
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", w+i);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) if(!visited[i]) dfs(i);
    
    for(int i = 1; i <= n; i++)
        cerr << color[i] << " ";
    cerr << endl;
    return 0;
}
