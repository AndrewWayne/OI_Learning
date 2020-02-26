#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, k, a[maxn];
ll f[2][2000];
ll ans;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a+i);
    for(int i = 1; i <= n; i++){
        int key = i&1;
        memset(f[key], 0, sizeof(f[key]));
        for(int j = 0; j < 1024; j++){
            if(a[i] == j){
                f[key][j]++;
                if(a[i] >= k) ans++;
            }
            f[key][j ^ a[i]] += f[key^1][j];
            if((j ^ a[i]) >= k) ans = ans + f[key^1][j];
        }
    }
    printf("%lld", ans);
    return 0;
}
