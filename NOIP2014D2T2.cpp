#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e4 + 10;
int n, m, x, y, s, t;
bool able[maxn], able2[maxn];
int dis[maxn];
vector<int> E[maxn], rE[maxn];
void dfs(int x, int mode){
    if(mode == 1)
        able2[x] = able[x] = true;
    for(auto i = rE[x].begin(); i != rE[x].end(); i++)
        if(!able[*i]){
            dfs(*i, mode);
        }
}
int bfs(int beginn, int endd){
    if(!able2[beginn]) return -1;
    queue<int> Q;
    Q.push(beginn);
    dis[beginn] = 0;
    dis[endd] = -1;
    if(beginn == endd) return 0;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(auto j = E[x].begin(); j != E[x].end(); j++){
            if(able2[*j]){
                dis[*j] = dis[x] + 1;
                Q.push(*j);
                able2[*j] = false;
            }
        }
    }
    return dis[endd];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &x, &y);
        E[x].push_back(y);
        rE[y].push_back(x);
    }
    scanf("%d%d", &s, &t);
    dfs(t, 1);
    for(int i = 1; i <= n; i++)
        for(auto j = E[i].begin(); j != E[i].end(); j++)
            if(!able[*j]){ able2[i] = false; break;}
    cout << bfs(s, t) << endl;
    return 0;
}
