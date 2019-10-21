/*
 * Author: xiaohei_AWM
 * Date: 10.20
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
#define int long long
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
ll a, b;
int K[40000010], top, ans;
bool visited[40000010];
signed main(){
    a = readll(), b = readll();
    ll c = b*4 - a * a;
    if(c == 0){
        printf("inf");
        return 0;
    }
    ll sc;
    if(c < 0) sc = sqrt(-c);
    else sc = sqrt(c);
    //cerr << "23" << endl;
    for(int k = 1; k <= sc; k++)
        if(c % k == 0) K[++top] = k, K[++top] = c / k;
    for(int i = 1; i <= top; i++){
        int k1 = K[i], k2 = c / K[i];
        //cerr << k1 << " " << k2 << endl;
        int x = k1 + k2;
        int y = k1 - k2 - a*2;
        if(y >= 0 && x % 4 == 0 && y % 4 == 0) ans += !visited[x];
        if(x == y) visited[x] = 1;
        //if(x % 4 == 0 && y % 4 == 0)
        //    cerr << x/4 << " " << y/4 << endl;
    }
    printf("%lld", ans);
    return 0;
}
