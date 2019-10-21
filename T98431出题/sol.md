对于 $a^2 + b^2 = c^2$

移项得， $a^2 = (c - b)(c+b)$

令 $x = c + b,y=c-b$ 有 $x + y = 2c$ , 且 $xy = a^2$

由于 $xy$ 为完全平方数，所以 $\frac{x}{gcd(x,y)}$ 和 $\frac{y}{gcd(x,y)}$ 为完全平方数

令 $x_1 = \sqrt \frac{x}{gcd(x,y)}, y_1 = \sqrt\frac{y}{gcd(x,y)}$

则 $x_1^2 + y_1^2 = \frac{2c}{gcd(x,y)}$

所以 $gcd(x,y)$ 为 $2c$ 的因数，枚举，$2c$ 因数，再在 $ \sqrt \frac{2c}{gcd(x,y)} $ 的范围里枚举 $x_1$ , 计算 $y_1$ 是否为完全平方数，如果是则记录答案。

时间复杂度 $\Theta (\sum_{k|2c} \sqrt k)$ 小于 $O(c^{\frac{2}{3}})$

std:
```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int xans, ans, c, k;
ll cc;
int K[maxn], top;
int gcd(int a, int b){
    while(b){int r = b; b = a%b; a = r;}
    return a;
}
char name[20];
signed main(){
    int x, y, a;
    xans = 0, ans = 0, c = 0, k = 0, top = 0;
    scanf("%lld", &c);
    cc = (ll)c * c;
    for(int i = 1; i <= sqrt(2*c); i++){
        if(2*c % i != 0) continue;
        K[++top] = i;
        K[++top] = 2*c / i;
    }
    for(int i = 1; i <= top; i++){
        k = K[i];
        if((2*c) % k != 0) continue;
        for(int x = 1; x <= sqrt(2*c / k); x++){
             y = sqrt(2*c/k - x*x);
            if(y*y == 2*c/k - x*x && y >= x){
                if(gcd(x, y) != 1) continue;
                a = k*x*y;
                int b = sqrt((ll)c*c - (ll)a*a);
                if(b == 0 || a == 0 || b < a) break;
                if((ll)b*b == (ll)c*c - (ll)a*a){
                    ans += 2;
                    xans ^= a ^ b;
                }
            }
        }
    }
    printf("%lld\n%lld\n", ans, xans);
}

```
