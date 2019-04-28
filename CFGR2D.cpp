#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int n, q;
ll x[maxn], s[maxn], l, r;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    sort(x+1, x+n+1);

    for(int i = 1; i < n; i++)
        x[i] = x[i+1] - x[i];
    x[n] = 2e18;
    sort(x+1, x+n+1);

    for(int i = 1; i <= n; i++)
        s[i] = s[i-1] + x[i];

    scanf("%d", &q);
    while(q--){
        scanf("%lld%lld", &l, &r);
        ll len = r - l + 1;
        ll pos = lower_bound(x+1, x+n+1, len) - x - 1;
        printf("%lld ",s[pos] + (ll)(n - pos) * len);
    }
    return 0;
}
