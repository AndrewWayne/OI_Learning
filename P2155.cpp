#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 10;
int t, R, n, m, top, fact[maxn], inv[maxn], phi[maxn];
bool notprime[maxn];
int main(){
    cin >> t >> R;
    phi[0] = phi[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(!notprime[i])
            fact[++top] = i;
        for(int j = 1; j <= top && (ll)(fact[j] * i) < (ll)maxn; j++){
            notprime[i * fact[j]] = 1;
            if(i % fact[j] == 0) break;
        }
        inv[i] = (ll)(R - R/i) % R * inv[R % i] % R;
    }
    fact[0] = fact[1] = 1;
    for(int i = 2; i < maxn; i++){
        fact[i] = (ll)fact[i-1] % R * i % R;
        phi[i] = phi[i-1];
        if(!notprime[i])
            phi[i] = (ll)phi[i] % R * (i-1) % R * inv[i] % R;
    }
    while(t--){
        cin >> n >> m;
        long long ans = (ll)fact[n] % R * phi[m] % R;
        ans %= R;
        cout << ans << endl;
    }
    return 0;
}
