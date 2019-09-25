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
ll dis[maxn][maxn], cost[maxn][maxn], w;
bool vis[maxn];
struct Edge{
    int v, nxt;
    ll w;
} e[2*maxn*maxn];
priority_queue<pll, vector<pll>, greater<pll> > Q;
pll taxi[maxn];
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
    memset(taxi, 0, sizeof(taxi));
    memset(head, 0, sizeof(head)), nume = 0;
    n = read(), m = read(), s = read(), t = read();
    for(int i = 1; i <= m; i++){
        u = read(), v = read(), w = readll();
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= n; i++){
        //Taxi tmp = {len, fee, false};
        taxi[i].first = readll(), taxi[i].second = readll();
        dis[i][i] = cost[i][i] = 0;
    }
    for(int i = 1; i <= n; i++) dijkstra(i);
    if(dis[s][t] == 4557430888798830399){
        printf("-1\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(taxi[i].first < dis[i][j]) continue;
            if(taxi[i].first >= dis[i][j])
                cost[i][j] = min(cost[i][j], taxi[i].second);
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(head, 0, sizeof(head));
    nume = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(cost[i][j] != 4557430888798830399)
                add(i, j, cost[i][j]);
    dijkstra(s);
    if(dis[s][t] == 4557430888798830399) printf("-1\n");
    else printf("%lld\n", dis[s][t]);
}
int main(){
    ts = read();
    while(ts--){
        //cerr << "Case: " << ts << endl;
        solve();
    }
    return 0;
}
/*
3
4 4
1 3
1 2 3
1 4 1
2 4 1
2 3 5
2 7
7 2
1 2
7 7
5 4
5 3
1 2 3
1 4 1
2 4 1
2 3 5
2 7
7 2
1 2
7 7
2 9
4 4
1 3
1 2 3
1 4 1
2 4 1
2 3 5
2 7
7 2
1 2
7 7
*/
