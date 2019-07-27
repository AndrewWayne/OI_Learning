/*
 * Author: xiaohei_AWM
 * Date: 7.26
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
typedef long double db;
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
const int maxn = 1e5 + 10;
ll n, xx[maxn], yy[maxn], kkk;
db L, R, l, r, k;
db f(db x){
    db ans = 0;
    for(int i = 1; i <= n; i++)
        ans += (db)sqrt((xx[i] - x)*(xx[i] - x) + yy[i]*yy[i]);
    return ans;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        xx[i] = read(), yy[i] = read();
        L = min(L, (db)xx[i]), R = max(R, (db)xx[i]);
    }
    kkk = read();
    for(int i = 1; i <= n; i++) yy[i] -= kkk;
    while(R - L >= 5e-1){
        k = (R-L)/3.0;
        l = L+k, r = R-k;
        if(f(l) < f(r)) R = r;
        else L = l;
    }
    ll ans = f(L) + 0.5;
    printf("%lld\n", ans);
    return 0;
}
