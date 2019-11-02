/*
 * Author: xiaohei_AWM
 * Date: 10.25
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
const int maxn = 1e5 + 10;
int n, q, opt, x;
ll a[3][maxn], y, s[2], ans;
void add(int pos, ll val, int opt){
    ans += val * (a[opt^1][pos] * n - s[opt^1]);
    s[opt] += val;
    a[opt][pos] += val;
}
int main(){
    //freopen("517-11.in", "r", stdin);
    n = read(), q = read();
    for(int i = 1; i <= n; i++){
        a[0][i] = readll();
        s[0] += a[0][i];
    }
    //cerr << sa << endl;
    for(int i = 1; i <= n; i++){
        a[1][i] = readll();
        s[1] += a[1][i];
    }
    for(int i = 1; i <= n; i++)
        ans += a[0][i] * (a[1][i] * n - s[1]);
    //cerr << sb << endl;
    while(q--){
        opt = read(), x = read(), y = readll();
        if(opt == 1) add(x, y - a[0][x], 0);
        if(opt == 2) add(x, y - a[1][x], 1);
        printf("%lld\n", ans);
    }
    return 0;
}
