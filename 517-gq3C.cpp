/*
 * Author: xiaohei_AWM
 * Date: 10.4
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
const int maxm = 2510;
const int MOD = 1e9 + 7;
vector<int> E[maxn], E2[maxn];
int n, m;
int color[maxn], U[maxm], V[maxm], ans, cnt[10];
ll f[1 << 10][maxn], val[maxn][maxn];//f[k][i]表示状态为k时当前在i色块的方案数，val[i][j]表示联通块内从i->j走同色的方案数
bool colored[10], visited[maxn];
void dfs(int x, int len){
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        ˜
    }
}
int main(){
    n = read(), m = read();
    for(int i = 0; i < n; i++){
        color[i] = read();
        cnt[color[i]]++;
    }
    for(int i = 1; i <= m; i++) U[i] = read();
    for(int i = 1; i <= m; i++) V[i] = read();
    for(int i = 1; i <= m; i++){
        E[U[i]].push_back(V[i]);
        E[V[i]].push_back(U[i]);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[x])
            dfs(i, 0);
    }
    cout << ans % MOD << endl;
    return 0;
}
