#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<int> rE[maxn], E[maxn];
int out[maxn], fa[22][maxn], maxv[22][maxn];
int n, visited[maxn], baned[maxn], color[maxn], id;
ll w[maxn], k, f[maxn];
int main(){
    scanf("%d%lld", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%lld", f+i);
    for(int i = 0; i < n; i++)
        scanf("%lld", w+i);
    for(int i = 0; i < n; i++){
        ll mn = 1ll << 60;
        ll sum = 0;
        for(int x = i, j = 1; j <= k; j++, x = f[x]){
            sum += w[x];
            mn = min(mn, w[x]);
        }
        printf("%lld %lld\n", sum, mn);
    }

    return 0;
}
