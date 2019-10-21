#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> E[maxn];
struct Edge{
    int val, x, y;
    bool operator<(const Edge &v)const{
        return val < v.val;
    }
};
int n, x, y, w[maxn];
int val[maxn], maxv;
int fa[maxn], u[maxn], v[maxn], size[maxn];
int times[maxn];
int only[maxn];
map<int, int> V[maxn];
bool onlied[maxn];
//set<
void dfs(int x, int f){
    V[x][w[x]]++;
    size[x] = 1;
    if(times[w[x]] == 1){
        onlied[w[x]] = true;
        only[x]++;
    }
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i == f) continue;
        fa[*i] = x;
        dfs(*i, x);
        if(V[*i].size() > V[x].size()) V[x].swap(V[*i]);
        //size[x] += size[*i];
        only[x] += only[*i];
        for(auto j = V[*i].begin(); j != V[*i].end(); j++){
            V[x][j->first] += j->second;
            if((!onlied[j->first]) && V[x][j->first] == times[j->first]){
                onlied[j->first] = true;
                only[x]++;
            }
        }
    }
    val[x] = V[x].size();
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &x, &y),
        E[x].push_back(y),
        E[y].push_back(x);
        u[i] = x;
        v[i] = y;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        times[w[i]]++;
    }
    dfs(1, 0);
    int son = 0;
    //for(int i = 1; i <= n; i++)
    //    cerr << val[i] << " ";
    //cerr << endl;
    //for(int i = 1; i <= n; i++)
    //    cerr << only[i] << " ";
    //cerr << endl;
    for(int i = 1; i < n; i++){
        x = u[i], y = v[i];
        if(fa[x] == y) son = x;
        else son = y;
        //cerr << fa[son] << " " << son << endl;
        //cerr << "$:" << val[1] - only[son] << " " << val[son] << endl;
        maxv = max(maxv, val[1] - only[son] + val[son]);
    }
    printf("%d", maxv);
    return 0;
}
/*
10
7 1
1 4
7 6
7 8
1 9
1 5
7 2
2 3
7 10
1 2 2 3 3 4 2 5 5 7
*/
