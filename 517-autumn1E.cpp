#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const long long MOD = 1e9 + 7;
const long long inv2 = 500000004;
long long n, m, a[maxn], b[maxn], inv;
long long F[maxn][2];
ll sum;
long long quickPow(ll x, ll p){
    ll res = 1;
    for(int i = p; i; i >>= 1){
        if(i & 1) res *= x, res %= MOD;
        x = x * x % MOD;
    }
    return res % MOD;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    inv = quickPow(m, MOD-2);
    for(int i = 1; i < m; i++)
        sum += i;
    sum %= MOD;
    F[0][0] = 1;
    F[0][1] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0 && b[i] == 0){
            F[i][0] = (F[i-1][0] * inv) % MOD;
            F[i][1] = (F[i-1][0] * (1-inv) % MOD) * inv2 % MOD;
        }else if(a[i] == 0 && b[i] != 0){
            F[i][0] = (F[i-1][0] * inv) % MOD;
            F[i][1] = (F[i-1][0] * (m - b[i]) % MOD) * inv % MOD;
        }else if(a[i] != 0 && b[i] == 0){
            F[i][0] = (F[i-1][0] * inv) % MOD;
            F[i][1] = (F[i-1][0] * (a[i] - 1) % MOD) * inv % MOD;
        }else if(a[i] > b[i]){
            F[i][0] = 0;
            F[i][1] = F[i-1][0];
            break;
        }else if(a[i] < b[i]){
            break;
        }else if(a[i] == b[i]){
            F[i][0] = F[i-1][0];
        }
        //cerr << F[i][0] << endl;
        //cerr << F[i][1] << endl;
        //cerr << F[i][1] << endl;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        ans += F[i][1];
        //cerr << ans << endl;
        ans %= MOD;
        while(ans >= MOD) ans -= MOD;
        while(ans < 0) ans += MOD;
    }
    cout << ans << endl;
    return 0;
}
