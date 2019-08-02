/*
 * Author: xiaohei_AWM
 * Date: 8.2
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
const int maxn = 1e5 + 10;
ll a[maxn], k, f[maxn];
int n, m, u, v, head[maxn], cnt;
struct Edge{
    int to, nxt;
    ll k;
} edge[maxn];
void add(int u, int v, ll k){
    edge[++cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].k = k;
    head[u] = cnt;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        f[i] = readll();
    for(int i = 1; i <= m; i++){
        k = readll(), u = read(), v = read();
        add(u, v, k);
    }
    for(int i = 1; i <= n; i++){
        for(int j = head[i]; j; j = edge[j].nxt)
            f[edge[j].to] = min(f[edge[j].to], edge[j].k * f[i]);
    }
    cout << f[n] << endl;
    return 0;
}
