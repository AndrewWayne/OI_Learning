/*
 * Author: xiaohei_AWM
 * Date: 7.12
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
const int maxn = 3e3 + 10;
const ll MOD = 1e9+7;
int n, m, l, r;
ll  f[maxn][maxn], sum[maxn];
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i){
                 f[i][j] = i;
                 sum[i] += i;
                 if(sum[i] >= MOD)
                    sum[i] -= MOD;
            }else{
                f[i][j] = (f[i-1][j-1] + f[i-1][j])%MOD;
                sum[i] = (sum[i] + f[i][j])%MOD;
            }
        }
        sum[i] = (sum[i] + sum[i-1])%MOD;
    }
    for(int i = 1; i <= m; i++){
        l = read(), r = read();
        ll ans = sum[r] - sum[l-1];
        if(ans < 0) ans += MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
