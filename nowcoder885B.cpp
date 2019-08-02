/*
 * Author: xiaohei_AWM
 * Date: 8.1
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
const int maxn = 2e7 + 7;
const int maxm = 5e4 + 7;
struct Matrix{
    ll x[2][2];
    Matrix(){
        memset(x, 0, sizeof(x));
    }
    void clear(){
        memset(x, 0, sizeof(x));
    };
} cur, a;

char b[maxn];
ll m;
ll len;
Matrix mul(const Matrix& x, const Matrix& y){
    Matrix res;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                res.x[i][j] = (res.x[i][j] + x.x[i][k] * y.x[k][j]) % m;
    return res;
}
Matrix qpow(Matrix a){
    Matrix ans;
    for (int i = 0; i < 2; i++)
        ans.x[i][i] = 1;
    Matrix s = a;
    while (len >= 1){
        ll cnt = b[len] - '0';
        Matrix tmp = s;
        for (int i = 1; i <= cnt; i++)
            ans = mul(ans, s);
        for (int i = 1; i < 10; i++)
            tmp = mul(tmp, s);
        s = tmp;
        len--;
    }
    return ans;
}
int main(){
    cur.clear();
    a.clear();
    scanf("%lld%lld", &cur.x[0][1], &cur.x[0][0]);
    scanf("%lld%lld", &a.x[0][0], &a.x[1][0]);
    a.x[0][1] = 1;
    scanf("%s", b + 1);
    len = strlen(b + 1);
    scanf("%lld", &m);
    Matrix ans = qpow(a);
    ans = mul(cur, ans);
    printf("%lld\n", ans.x[0][1]);
    return 0;
}
