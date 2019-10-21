#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> E[maxn];
int n, a, b, dep[maxn];
double ans;
void dfs(int x, int f){
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i != f){
            dep[*i] = dep[x] + 1;
            dfs(*i, x);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dep[1] = 1;
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        ans += 1.0 / dep[i];
    printf("%.10f\n", ans);
    return 0;
}
