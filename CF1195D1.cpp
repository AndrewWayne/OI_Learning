/*
 * Author: xiaohei_AWM
 * Date: 7.17
 * Mutto: Face to the weakness, expect for the strength.
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
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const int maxn = 1e5 + 10;
const int MOD = 998244353;
int n;
ll a[maxn], ans;
ll quickPower(ll a, int b){
    ll res = 1;
    for(int i = b; i; i >>= 1){
        if(i & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
    }
    return res % MOD;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = readll();
        ll sum = 0;
        for(ll k = a[i], j = 0; k; k /= 10, j++){
            int x = k % 10;
            sum += (n*11*((x * (quickPower(10, 2*j)))%MOD))%MOD;
            sum %= MOD;
        }
        ans += sum;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
