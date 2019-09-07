/*
 * Author: xiaohei_AWM
 * Date: 8.24
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<map>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const ll MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
ll f[maxn][2], l[maxn], r[maxn];
int t, n, x, y;
vector<int> son[maxn];
bool visit[maxn];
void dfs(int x){
    visit[x] = true;
    int lim = son[x].size();
    for(int i = 0; i < lim; i++){
        int y = son[x][i];
        if(visit[y]) continue;
        dfs(y);
        f[x][1] += max(f[y][0] + abs(r[y] - l[x]), f[y][1] + abs(l[y] - l[x]));
        f[x][0] += max(f[y][0] + abs(r[y] - r[x]), f[y][1] + abs(l[y] - r[x]));
    }
    //printf("%d: %d -- %d\n", x, f[x][1], f[x][0]);
    return;
}
int main(){
    scanf("%d", &t);
    while(t--){
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(f, 0, sizeof(f));
        memset(visit, 0, sizeof(visit));
        for(int i = 1; i <= n; i++) son[i].clear();
        scanf("%d", &n);
        for(int i = 1; i <= n-1; i++){
            scanf("%d%d", &x, &y);
            son[x].push_back(y);
            son[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld", &l[i], &r[i]);
        dfs(1);
        printf("%lld\n", max(f[1][1], f[1][0]));
    }
    return 0;
}
/*
3
5
1 2
2 3
3 4
4 5
1 5
2 7
7 9
5 8
3 4
5
1 2
2 3
3 4
4 5
1 5
2 7
7 9
5 8
3 4
5
1 2
2 3
3 4
4 5
1 5
2 7
7 9
5 8
3 4
*/
