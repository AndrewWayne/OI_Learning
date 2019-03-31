#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e4 + 10;
int n, a[maxn], f[maxn][8];
bool visit[maxn][8];
int dfs(int at, int stat){
    if(visit[at][stat])
        return f[at][stat];
    visit[at][stat] = true;
    int val = a[at];
    for(int i = 0; i <= 2; i++)
        val -= (stat >> i) &1;
    if(val > 1 || val < 0)
        return f[at][stat] = 0;
    if(at == n && val == 0)
        return f[at][stat] = 1;

    if(val == 0)
        f[at][stat] += dfs(at+1, (stat << 1)&7);
    if(val == 1)
        f[at][stat] += dfs(at+1, ((stat|1) << 1)&7);

    return f[at][stat];

}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    cout << dfs(1, 0) + dfs(1, 2) << endl;
    return 0;
}
