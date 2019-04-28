/*
 *Author: xiaohei_AWM
 *Date:
 *Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
const int maxn = 2e7 + 10;
ui SA, SB, SC;
int i, n, mod, a[maxn], jumpto[maxn];
ll sum;
inline unsigned int Rand(){
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
int main(){
    cin >> n >> mod >> SA >> SB >> SC;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(i = 1; i <= n; ++i)
        a[i] = Rand() % mod + 1;
    jumpto[n] = n;
    if(n - a[n] - 1 > 0)
        jumpto[n - a[n] - 1] = n;
    a[n] = 0;
    for(i = n-1; i >= 1; --i){
        if(i - a[i] - 1 > 0)
            jumpto[i - a[i] - 1] = i;
        a[i] = 0;
        if(jumpto[i] == 0)
            jumpto[i] = jumpto[i+1];
        a[i] = a[jumpto[i]-1] + jumpto[i] - i;
        sum += a[i];
    }
    printf("%lld", sum);
    return 0;
}
/*
5 5
5 6 4
*/
