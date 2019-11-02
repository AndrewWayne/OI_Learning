/*
 * Author: xiaohei_AWM
 * Date: 10.25
 * Motto: Face to the weakness, expect for the strength.
*/
#include <bits/stdc++.h>
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
int n, p, l, r;
double rate[maxn], ans;
int main(){
    //freopen("517-11.in", "r", stdin);
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        int k1 = l/p;
        int k2 = r/p;
        if(l % p) k1++;
        rate[i] = (db)(k2 - k1 + 1) / (r - l + 1);
        //cerr << rate[i] << endl;
    }
    for(int i = 1; i < n; i++){
        ans += (1.0 - (1.0 - rate[i])*(1.0 - rate[i+1])) * 2000;
    }
    ans += (1.0 - (1.0 - rate[1])*(1.0 - rate[n])) * 2000;
    printf("%.9f\n", ans);
    return 0;
}
