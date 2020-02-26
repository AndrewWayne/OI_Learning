/*
 * Author: xiaohei_AWM
 * Date: 7.31
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
const ll MOD = 1e9 + 7;
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
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x*10)%MOD+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 110;
const int maxm = 1e6 + 10;
ll n, m, a[maxn];
int sol[maxm], top;
ll calc(ll x){
    ll res = 0;
    for(int i = n+1; i >= 1; i--)
        res = (res * x) % MOD + a[i];
    return res % MOD;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n+1; i++) a[i] = readll();
    for(int i = 1; i <= m; i++)
        if(calc(i) == 0) sol[++top] = i;
    printf("%d\n", top);
    for(int i = 1; i <= top; i++)
        printf("%d\n", sol[i]);
    return 0;
}
