/*
 * Author: tanao/Fu yiye/chengzhizhi
 * Date: 10.4
 * Motto: Unity is strength
 */
#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <functional>
#include <cmath>
#include <vector>
#include <assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin); fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO {
char buf[1<<15],*S,*T;
inline char gc(){
        if (S==T) {
                T=(S=buf)+fread(buf,1,1<<15,stdin);
                if (S==T) return EOF;
        }
        return *S++;
}
inline int read(){
        reg int x; reg bool f; reg char c;
        for(f=0; (c=gc())<'0'||c>'9'; f=c=='-');
        for(x=c^'0'; (c=gc())>='0'&&c<='9'; x=(x<<3)+(x<<1)+(c^'0'));
        return f ? -x : x;
}
inline ll readll(){
        reg ll x; reg bool f; reg char c;
        for(f=0; (c=gc())<'0'||c>'9'; f=c=='-');
        for(x=c^'0'; (c=gc())>='0'&&c<='9'; x=(x<<3)+(x<<1)+(c^'0'));
        return f ? -x : x;
}
}
using namespace IO;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int MAX_N = 110;
const ll mod = 1e9+7;
ll n, m, color, c[MAX_N], cc[MAX_N];
vector<ll> a[10];
struct EDGE { ll u, v;} g[MAX_N * MAX_N];
ll tot, ans, dp1[1<<10][105];
ll pre[10][110][110], dp[11][11][1<<10];
bool vis[110], gg[MAX_N][MAX_N];

inline void solve(int u){
        if(a[u].size() == 0) return;
        memset(dp, 0, sizeof(dp));
        int full = (1 << a[u].size())-1;
        for (int i = 0; i < a[u].size(); i++) dp[i][i][1<<i] = 1;
        for (int i = 0; i < a[u].size(); i++) {
                for (int mask = 1; mask <= full; mask++) {
                        for (int j = 0; j < a[u].size(); j++) {
                                if(!dp[i][j][mask]) continue;
                                for (int i_ = 0; i_ < a[u].size(); i_++) {
                                        int k = a[u][i_];
                                        if(!gg[a[u][j]][k]) continue;
                                        int new_mask = mask|(1<<i_);
                                        if(mask & (1<<i_)) continue;
                                        dp[i][i_][new_mask] = (dp[i][i_][new_mask]+dp[i][j][mask])%mod;
                                }
                        }
                }
        }
        for(int i = 0; i < a[u].size(); i++)
                for(int j = 0; j < a[u].size(); j++) {
                        pre[u][a[u][i]][a[u][j]] = dp[i][j][full];
                }
}
int main()
{
        ios::sync_with_stdio(false);
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
                cin >> c[i];
                cc[c[i]]++, a[c[i]].push_back(i);
        }
        for(ll i = 0; i < 10; ++i) if(cc[i]) color++;
        for(ll i = 1; i <= m; ++i) cin >> g[i].u, g[i].u++;
        for(ll i = 1; i <= m; ++i) cin >> g[i].v, g[i].v++;
        for(ll i = 1; i <= m; ++i) gg[g[i].u][g[i].v] = gg[g[i].v][g[i].u] = 1;
        for(int i = 0; i < 10; i++) solve(i);

        for(ll i = 1; i <= n; ++i)
                for(ll j = 1; j <= n; ++j) {
                        if(c[i] == c[j]) dp1[1<<c[i]][j] += pre[c[i]][i][j];
                }

        for(ll i = 1; i < (1<<10); ++i) {
                for(ll j = 1; j <= n; ++j)
                        if(i & (1 << c[j])) { //lst.end
                                for(ll k = 1; k <= n; ++k)
                                        if(gg[j][k] && ((1 << c[k]) & i) == 0) { //nxt.begin
                                                for(ll l = 0; l < a[c[k]].size(); ++l) { //nxt.end
                                                        int tanao = a[c[k]][l];
//					if(tanao != k) {
                                                        dp1[i|(1 << c[k])][tanao] = (dp1[i|(1 << c[k])][tanao] + dp1[i][j] * pre[c[k]][k][tanao]%mod)%mod;
//					}
                                                }
                                        }
                        }
        }
//	for(int i = 1; i < (1<<10); i++)
//		for(int j = 1; j <= n; j++)
//			if(dp[i][j]) printf("[%d %d] %d\n", i, j, dp[i][j]);
        for(ll i=0; i<10; ++i) if(cc[i]) tot+=(1<<i);
        for(ll i=1; i<=n; ++i) ans = (ans + dp1[tot][i])%mod;
        cout<<ans%mod<<endl;
        return 0;
}
