/*
 * Author: xiaohei_AWM
 * Date: 9.10
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
const int maxn = 110;
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
int n, k, a[maxn], b[maxn], f[200100];
int l, r;
int main(){
    n = read(), k = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= n; i++)
        b[i] = read();
    l = r = 100000;
    for(int i = 1; i <= n; i++){
        b[i] = a[i] - b[i]*k;
        if(b[i] < 0) l += b[i];
        else r += b[i];
    }
    for(int i = l; i <= r; i++)
        f[i] = -INF;
    f[100000] = 0;
    for(int i = 1; i <= n; i++){
        if(b[i] > 0){
            for(int j = r; j >= l + b[i]; j--)
                if(f[j - b[i]] != -INF)
                    f[j] = max(f[j], f[j - b[i]] + a[i]);
        }else{
            for(int j = l; j <= r + b[i]; j++)
                if(f[j - b[i]] != -INF)
                    f[j] = max(f[j], f[j - b[i]] + a[i]);
        }
    }
    if(f[100000] == 0) printf("-1\n");
    else printf("%d\n", f[100000]);
    return 0;
}
