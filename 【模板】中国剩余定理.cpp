//对于同余方程组，我们可以求出他在%M意义下的唯一解。
//x在%m_i意义余a_i   x=a(mod m) <==> x % m = a
//这里还有快速乘
//P3868
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long Type1;//change it!
inline void exgcd(Type1 a, Type1 b, Type1 &d, Type1 &x, Type1 &y){
    if(!b){
        x = 1; y = 0, d = a;
        return;
    }
    exgcd(b, a%b, d, x, y);
    Type1 t = x;
    x = y; y = t - (a / b) * y;
    return;
}
inline Type1 mul(Type1 a, Type1 b, Type1 MOD){
    Type1 res = 0;
    for(Type1 i = b; i > 0; i >>= 1){
        if(i & 1)
            res = (res + a) % MOD;
        a = (a + a) % MOD;
    }
    return res;
}
const int maxn = 20;
int n;
Type1 m[maxn], M[maxn], M1 = 1, a[maxn], t[maxn], ans;//M1 = lcm(mi)而由于mi互质，所以累积即可;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> m[i],
        M1 *= m[i],
        a[i] = (a[i]%m[i] + m[i]) % m[i];;
    for(int i = 1; i <= n; i++){
        M[i] = M1/m[i];
        //cerr << M[i] << endl;
        Type1 temp, d;
        exgcd(M[i], m[i], d, t[i], temp);
        t[i] = (t[i]%m[i] + m[i])%m[i];
        //cerr << t[i] << endl;
        ans = (ans + mul(mul(a[i], t[i], M1), M[i], M1))%M1;
    }
    cout << (ans + M1) % M1 << endl;
    return 0;
}
