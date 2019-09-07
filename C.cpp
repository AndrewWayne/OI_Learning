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
int t, n, x, y;
int lson[maxn], rson[maxn], val[maxn], size[maxn], cnt;
ll ans, p[2500010];
bool visit[maxn], son[maxn];
void dfs1(int x){
    if(lson[x] != 0){
        dfs1(lson[x]);
        size[x] += size[lson[x]];
        val[x] = min(val[x], val[lson[x]]);
    }
    if(rson[x] != 0){
        dfs1(rson[x]);
        val[x] = min(val[x], val[rson[x]]);
        size[x] += size[rson[x]];
    }
    val[x] = min(x, val[x]);
    size[x]++;
    return;
}
void dfs(int x){
    if(lson[x]) dfs(lson[x]);
    val[x] = 0x7f7f7f7f;
    ++cnt;
    size[x] = 0;
    ans = (ans + (cnt ^ x) * p[x])%MOD;
    if(rson[x]) dfs(rson[x]);
    return;
}
int main(){
    p[0] = 1;
    for(int i = 1; i <= 2500000; i++)
        p[i] = (p[i-1] * 233)%MOD;
    scanf("%d", &t);
    while(t--){
        ans = cnt = 0;
        scanf("%d", &n);
        val[0] = 0x7f7f7f7f;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &lson[i], &rson[i]), son[lson[i]] = true, son[rson[i]] = true, val[i] = 0x7f7f7f7f;
        int roots = 0;
        for(int i = 1; i <= n; i++){
            if(!son[i]){
                dfs1(i);
                roots = i;
            }
            son[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            if(val[i] == i){
                if(size[lson[i]] > size[rson[i]])
                    swap(lson[i], rson[i]);
                else if(size[lson[i]] == size[rson[i]])
                    if(val[lson[i]] > val[rson[i]])
                        swap(lson[i], rson[i]);
            }else if(val[lson[i]] > val[rson[i]])
                swap(lson[i], rson[i]);
        }
        dfs(roots);
        for(int i = 1; i <= n; i++) lson[i] = rson[i] = 0;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
2
5
0 0
0 0
0 4
2 0
1 3
8
2 3
4 5
0 8
6 7
0 0
0 0
0 0
0 0
*/
