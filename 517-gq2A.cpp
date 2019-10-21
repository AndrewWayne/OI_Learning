/*
 * Author: xiaohei_AWM
 * Date: 10.3
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
const int maxn = 1e3 + 10;
vector<int> AntiE[maxn], E2[maxn];
int t, n, to, visited[maxn], colored[maxn], sum[maxn], res, E[maxn];
int fas[maxn], stck[maxn], top, len[maxn], cnt, kkk;
void dfs1(int x, int fa){
    //cerr << x << endl;
    if(visited[x]){
        colored[x] = ++cnt;
        sum[cnt]++;
        int u = x;
        //cerr << u << endl;
        while(fas[u] != x){
            colored[fas[u]] = cnt;
            sum[cnt]++;
            u = fas[u];
            //cerr << u << endl;
        }
        return;
    }
    visited[x] = true;
    for(auto i = E2[x].begin(); i != E2[x].end(); i++){
        if(*i != fa){
            fas[*i] = x;
            dfs1(*i, x);
        }
    }
}
int dfs2(int x, int Ncstor){
    int len = 0;
    for(auto i = AntiE[x].begin(); i != AntiE[x].end(); i++){
        if(*i != Ncstor)
            len = max(dfs2(*i, Ncstor), len);
    }
    return len + 1;
}
void init(){
    top = cnt = res = 0;
    memset(E, 0, sizeof(E));
    memset(visited, 0, sizeof(visited));
    memset(colored, 0, sizeof(colored));
    memset(sum, 0, sizeof(sum));
    memset(fas, 0, sizeof(fas));
    memset(len, 0, sizeof(len));
    memset(stck, 0, sizeof(stck));
}
void solve(){
    //cerr << kkk << endl;
    init();
    n = read();
    for(int i = 1; i <= n; i++)
        AntiE[i].clear(), E2[i].clear();

    for(int i = 1; i <= n; i++)
        to = read(),
        E[i] = to;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == E[E[i]]) stck[++top] = i;//这些点从反边上找最长链
        else{
            E2[i].push_back(E[i]);
            E2[E[i]].push_back(i);
            AntiE[E[i]].push_back(i);
        }
    }
    //cerr << "##" << endl;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            //cerr << "##" <<  i << endl;
            dfs1(i, 0);
        }
    }
    for(int i = 1; i <= top; i++){
        len[stck[i]] = dfs2(stck[i], E[stck[i]]);
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= top; i++){
        if(visited[stck[i]]) continue;
        visited[stck[i]] = 1, visited[E[stck[i]]] = 1;
        //cerr << stck[i] << ": " << len[stck[i]] << endl;
        //cerr << E[stck[i]] << ": " << len[E[stck[i]]] << endl;
        ans += len[stck[i]] + len[E[stck[i]]];
    }
    for(int i = 1; i <= cnt; i++)
        ans = max(sum[i], ans);
    printf("%d\n", ans);
    return;
}
int main(){
    t = read();
    for(int i = 1; i <= t; i++){
        kkk = i;
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
