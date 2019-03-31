#include<cstdio>
#include<algorithm>
using namespace std;
long long n, k, ans;
int main() {
    scanf("%lld%lld", &n, &k);
    ans = n * k;
    for(long long l = 1, r; l <= n; l = r+1) {
        long long temp = k/l;

        if(temp != 0)
            r = min(k / temp, n);
        else r = n;

        ans -= temp * (r- l + 1) * (l+r) /2;
    }
    printf("%lld", ans);
    return 0;
}
