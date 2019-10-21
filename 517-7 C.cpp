/*
 * Author: xiaohei_AWM
 * Date:
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
const int MAX_V = 100004;
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
int t, n, m, x, y, dad[maxn], sze[maxn], f[maxn];
int luck[maxn], top, ans, num[maxn];
int find(int x){return x == dad[x] ? x : dad[x] = find(dad[x]);}
void unionn(int u, int v){
    int fu = find(u), fv = find(v);
    if(fu == fv) return;
    dad[fu] = fv, sze[fv] += sze[fu];
}
bool check(int x){
    for(int i = x; i; i /= 10)
        if(i % 10 != 4 && i % 10 != 7) return false;
    return true;
}
int A[maxn];
inline void pack(int f[], int V, int k, int v, int c){// k是件数，v是体积，c是价值 V 是最大体积
    int top = 0;
    if (k == 0 || c == 0) return;
    if(k*v >= V){
        for(int j = v; j <= V; j++)//完全背包
            f[j] = min(f[j], f[j-v] + c);
    }else{
        for(int j = 1; j <= k; j <<= 1){
            A[top++] = j; k -= j;
        }
        if(k) A[top++] = k;
        for(int a = 0; a < top; a++){//01背包
            for(int b = V; b >= A[a] * v; b--)
                f[b] = min(f[b], f[b - v*A[a]] + c * A[a]);
        }
    }
}
int main(){
    t = read();
    for(int i = 1; i <= maxn-1; i++)
        if(check(i)) luck[++top] = i;
    cerr << endl;
    while(t--){
        memset(num, 0, sizeof(num));
        n = read(), m = read();
        for(int i = 1; i <= n; i++) dad[i] = i, sze[i] = 1, f[i] = maxn;
        for(int i = 1; i <= m; i++)
            x = read(), y = read(), unionn(x, y);
        for(int i = 1; i <= n; i++){
            if(dad[i] != i) sze[i] = 0;
            else num[sze[i]]++;
        }
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            if(num[i] == 0) continue;
            //cerr << i << ": " << num[i] << endl;
            pack(f, n, num[i], i, 1);
        }
        //for(int i = 1; i <= n; i++) cerr << f[i] << endl;
        ans = maxn;
        for(int i = 1; i <= top; i++)
            if(luck[i] <= n)
                ans = min(f[luck[i]]-1, ans);
        if(ans > n) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
