#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
int INF = 1 << 29;
vector<int> E[maxn];
int n, t[maxn], ans, visited[maxn];
int dis[maxn];
bool circled = false;
void dfs(int, int);
int main(){
    ans = INF;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", t+i);
    for(int i = 1; i <= n; i++){
        if(i == t[t[i]]){
            ans = 2;
            puts("2");
            return 0;
        }
    }
    for(int i = 1; i <= n; i++){
        E[i].push_back(t[i]);
        E[t[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        circled = false;
        dis[i] = 0;
        dfs(i, 0);
    }
    printf("%d\n", ans);
    return 0;
}
void dfs(int x, int fa){
    visited[x] = 1;
    //6cerr << "$" << x << endl;
    //cerr << "DIS: " << dis[x] << endl;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa) continue;
        //cerr << x << "--" << (*i) << endl;
        if(visited[*i] && !circled){
            ans = min(ans, dis[x] - dis[*i] + 1);
            circled = true;
        }else if(!visited[*i]){
            dis[*i] = dis[x] + 1;
            dfs(*i, x);
        }
    }
}
