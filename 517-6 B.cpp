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
#include<queue>
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
const int maxn = 1e3 + 10;
int ts, n, m, s, t, u, v, head[maxn], nume;
ll dis[maxn][maxn], cost[maxn][maxn], w, len, fee;
bool vis[maxn];
struct Edge{
    int v, nxt;
    ll w;
} e[2*maxn];
priority_queue<pll, vector<pll>, greater<pll> > Q;
vector<pll> taxi[maxn];
inline void add(int u, int v, ll w){
    e[++nume].v = v;
    e[nume].w = w;
    e[nume].nxt = head[u];
    head[u] = nume;
}
void dijkstra(int s){
    //memset(dis,0x3f,sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s][s] = 0;
    Q.push(make_pair(0, s));
    while(!Q.empty()){
        int x = Q.top().second;
        Q.pop();
        if(!vis[x]){
            vis[x] = 1;
            for(int i = head[x]; i; i = e[i].nxt){
                int v = e[i].v;
                dis[s][v] = min(dis[s][v], dis[s][x] + e[i].w);
                Q.push(make_pair(dis[s][v], v));
            }
        }
    }
}
void solve(){
    memset(dis, 0x3f, sizeof(dis)), memset(cost, 0x3f, sizeof(cost));
    n = read(), m = read(), s = read(), t = read();
    for(int i = 1; i <= m; i++){
        u = read(), v = read(), w = readll();
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= n; i++){
        len = readll(), fee = readll();
        //Taxi tmp = {len, fee, false};
        taxi[i].push_back(make_pair(len, fee));
        dis[i][i] = cost[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) dijkstra(i);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            printf("%d %d: %lld\n", i, j, dis[i][j]);
    queue<int> QQ;
    QQ.push(s);
    while(!QQ.empty()){
        int i = QQ.front();
        for(int j = 1; j <= n; j++){
            for(auto k = taxi[i].begin(); k != taxi[i].end(); k++){
                if(k->first < dis[i][j]) continue;
                if(k->first == dis[i][j])
                    cost[j][i] = cost[i][j] = min(cost[i][j], k->second);
                if(k->second > dis[i][j])
                    cost[j][i] = cost[i][j] = min(cost[i][j], k->second);
            }
        }

    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(auto k = taxi[i].begin(); k != taxi[i].end(); k++){
                if(k->first < dis[i][j]) continue;
                if(k->first == dis[i][j])
                    cost[i][j] = min(cost[i][j], k->second);
                if(k->second > dis[i][j])
                    cost[i][j] = min(cost[i][j], k->second);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(auto k = taxi[i].begin(); k != taxi[i].end(); k++){
                if(k->first < dis[i][j]) continue;
                if(k->first == dis[i][j])
                    cost[i][j] = min(cost[i][j], k->second);
                if(k->second > dis[i][j])
                    cost[i][j] = min(cost[i][j], k->second),
                    taxi[j].push_back(make_pair(k->second - dis[i][j], 0));
            }
        }
    }
    for(int k = )
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
*/
    for(int i = 1; i <= n; i++) taxi[i].clear();
}
int main(){
    ts = read();
    while(ts--){
        solve();
    }
    return 0;
}
