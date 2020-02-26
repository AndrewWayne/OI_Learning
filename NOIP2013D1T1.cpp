#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k, x;
ll quickPower(ll base, int p){
    ll res = 1;
    for(int i = p; i; i >>= 1){
        if(i & 1) res = (res * base) % n;
        base = (base * base) % n;
    }
    return res;
}
int main(){
    cin >> n >> m >> k >> x;
    ll tmp = quickPower(10, k);
    cout << (m * tmp + x) % n << endl;
    return 0;
}
