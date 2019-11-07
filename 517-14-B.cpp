/*
 * Author: xiaohei_AWM
 * Date: 11.2
 * Motto: Face to the weakness, expect for the strength.
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
const int maxn = 440;
const ll MOD = 1e9 + 7;
int n, c;
ll f[maxn][maxn], a[maxn], b[maxn];
ll sum[maxn][maxn];
ll quickPower(ll x, int p){
    ll res = 1;
    for(int i = p; i; i >>= 1){
        if(i & 1) res *= x, res %= MOD;
        x *= x, x %= MOD;
    }
    return res;
}
ll Mod(ll x){
    x %= MOD;
    return x < 0 ? x + MOD : x;
}
int main(){
    n = read(), c = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read();
    for(int i = 1; i < maxn; i++){
        for(int j = 0; j <= c; j++){
            sum[i][j] = (sum[i-1][j] + quickPower(i, j)) % MOD;
        }
    }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= c; j++){
            for(int p = 0; p <= j; p++){
                //cerr << sum[b[i]][p] - sum[a[i]-1][p] << " ";
                f[i][j] = (f[i][j] + f[i-1][j-p] * (Mod(sum[b[i]][p] - sum[a[i]-1][p])) % MOD)% MOD;

            }
            //cerr << f[i][j] << " ";
        }
        //cerr << endl;
    }

    printf("%lld", f[n][c]);
    return 0;
}
