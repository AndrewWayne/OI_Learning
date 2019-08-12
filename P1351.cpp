/*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 2e5 + 10;
const int mod = 1e5 + 7;
struct Edge{
    int to, nxt;
} edge[maxn*2];
int n;
int w[maxn], f[maxn], g[maxn], head[maxn], cnt;//f[x]表示x所有儿子中的最大权值，g[x]表示x所有儿子的权值和
int ans_sum, ans_max;
int u, v;
void add(int x, int y){
    edge[++cnt].to = y;
    edge[cnt].nxt = head[x];
    head[x] = cnt;
}
void dfs(int x, int fa){
    int maxd = 0, sumd = 0;
    for(int i = head[x]; i; i = edge[i].nxt){
        int j = edge[i].to;
        if(j == fa) continue;
        dfs(j, x);
        ans_max = max(ans_max, maxd * w[j]);
        maxd = max(maxd, w[j]);
        ans_sum = (ans_sum + sumd * w[j]) % mod;
        sumd = (sumd + w[j]) % mod;
        //八字形
        ans_max = max(ans_max, f[j] * w[x]);
        ans_sum = (ans_sum + g[j] * w[x]) % mod;
        f[x] = max(f[x], w[j]);
        g[x] = (g[x] + w[j]) % mod;
        //一字形
    }
}
int main(){
    n = read();
    for(int i = 1; i < n; i++){
        u = read(), v = read();
        add(u, v), add(v, u);
    }
    for(int i = 1; i <= n; i++)
        w[i] = read();
    dfs(1, -1);
    cout << ans_max << " " << (ans_sum*2) % mod << endl;
    return 0;
}
