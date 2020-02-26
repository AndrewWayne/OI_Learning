#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, n, times;
long long x, y, a[20], b[20];
int main(){
    scanf("%d", &t);
    while(t--){
        times++;
        scanf("%d%lld%lld", &n, &x, &y);
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld", a+i, b+i);
        if(n != 1){
            ll ans = 0;
            for(ll i = x; i <= y; i++){
                bool flag = true;
                if(i % 7 != 0) continue;
                for(int j = 1; j <= n; j++){
                    if(i % a[j] == b[j]){
                        flag = false;
                        break;
                    }
                }
                ans += flag;
            }
            printf("Case #%d: %lld\n", times, ans);
        }else{
            ll ans = 0;
            //return 0;
            ll key = b[1] % a[1];
            x -= key, y -= key;
            int f = x % 7;
            f = 7 - f;
            //cerr << a[1] << endl;
            //return 0;
            ll k = (y - x + 1) / a[1];
            int cnt = 0;
            while(cnt * a[1] % 7 != f && cnt <= k) cnt++;
            ans = (k + 1) / (cnt+1);
            printf("Case #%d: %lld\n", times, ans);
        }
    }
    return 0;
}
