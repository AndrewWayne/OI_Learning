/*
 * Author: xiaohei_AWM
 * Date: 9.20
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
const int maxm = 2e6 + 10;
int s, d[maxn], a[maxn], b[maxn], ans;

//int max1[maxm], max2[maxm];
int check(int len){
    int sol = 0;
    int M = 0, N = 0;

    for(int i = 1; i <= s - len + 1; i++){
        for(int j = i; j <= i+len-1; j++){
            if(d[i] + a[i] == M)
        }
    }
}
int main(){
    ans = 1;
    s = read();
    for(int i = 1; i <= s; i++)
        d[i] = read(), a[i] = read(), b[i] = read();
    for(int len = 1; len <= s; len++){



    }
    printf("%d %d", ans, sol[ans]);
    return 0;
}
