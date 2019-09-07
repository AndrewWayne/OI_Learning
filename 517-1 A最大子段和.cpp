#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
const long long llINF = 9223372036854775807;
typedef long long ll;
int n;
ll f1[MAXN], f2[MAXN], a[MAXN], sum[MAXN], ans;
int main(){
    scanf("%d", &n);
    f1[0] = f2[0] = -llINF;
    f1[n+1] = f2[n+1] = -llINF;
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), sum[i] = sum[i-1] + a[i];
    ll k = llINF;
    //f2[i]表示区间[i,n]中的最大连续子段和，f1[i]表示区间[1,i]中的区间最大连续子段和。
    for(int i = 1; i <= n; i++){
        k = min(sum[i-1], k);
        f1[i] = max(f1[i-1], sum[i] - k);
    }
    k = -llINF;
    for(int i = n; i >= 1; i--){
        k = max(sum[i], k);
        f2[i] = max(f2[i+1], k - sum[i-1]);
    }
    ans = -llINF;
    for(int i = 1; i <= n; i++)
        ans = max(ans, f1[i] + f2[i+1]);
    printf("%lld\n", ans);
    return 0;
}
