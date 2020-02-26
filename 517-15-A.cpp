#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll d, k, t, a, b;
ll ans;
int main(){
    scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t);
    if(d <= k){
        printf("%lld\n", d * a);
        return 0;
    }
    if(d % k == 0){
        if(d*a + (d/k - 1) * t <= d*b)
            printf("%lld\n", d * b);
        else
            printf("%lld\n", d*a + (d/k - 1) * t);
    }else{
        ans = b * (d - k) + k * a;
        ans = min(ans, d * a + (d/k) * t);
        ans = min(ans, (d - d%k) * a + ((d/k) - 1) * t + (d%k) * b);
        printf("%lld\n", ans);
    }
    return 0;
}
