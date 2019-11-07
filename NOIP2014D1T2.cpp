#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 10;
const int MOD = 1e4 + 7;
vector<int> E[maxn];
int n, u, v;
ll w[maxn], sum[maxn], w2[maxn], secondsum[maxn], ans, sumans, maxw[maxn];//sum
void dfs(int, int);
int main(){
    //freopen("data.in", "r", stdin);
    //freopen("out1.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        scanf("%d%d", &u, &v),
        E[u].push_back(v),
        E[v].push_back(u);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &w[i]);
    dfs(1, 0);
    printf("%lld %lld\n", ans, sumans%MOD);
}
void dfs(int x, int fa){
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa) continue;
        sum[x] = (sum[x] + w[*i]) % MOD;//维护儿子们的和
        ans = max(maxw[x] * w[*i], ans);//这样一定不会错过最大*第二大
        maxw[x] = max(maxw[x], w[*i]);//维护儿子们的最大值，给自己的爸爸用
        dfs(*i, x);
        secondsum[x] = (sum[*i] + secondsum[x]) % MOD;//维护孙子们的和
        w2[x] = (w2[x] + w[*i] * w[*i] % MOD) % MOD;//维护出儿子们的平方和，用来快速计算所有儿子的乘积
        ans = max(ans, maxw[*i] * w[x]);//最大孙子乘自己可以做最大值
    }
    sumans = (sumans + (secondsum[x] * w[x] * 2) % MOD) % MOD;
    sumans = sumans + (sum[x] * sum[x] - w2[x]) % MOD;
}
