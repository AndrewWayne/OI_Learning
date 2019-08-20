/*
 * Author: xiaohei_AWM
 * Date:
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const ll MOD = 1e9+7;
ll n, m, res;
int l = -1, r = -1;
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}

int main(){
    n = readll(), m = read();
    for(int i = 0; m >> i; i++){
        if(l == -1 && ((m >> i) & 1)) l = i;
        if(((m >> i) & 1)) r = i;
    }

    ll len = 1ll << (r-l+1);
    ll num = 1ll << (r-l);
    ll cnt = n / len;
    res = mul(m ,mul(cnt, num, MOD), MOD);
    n = n - cnt*len;
    for(int i = 1; i <= n; i++){
        res = res + ((i * m)&m);
        res %= MOD;
    }
    printf("%lld\n", res);
    res = 0;
    for(int i = 1; i <= n; i++)
        res += (i*m) & m;
    cerr << res << endl;
    return 0;
}
