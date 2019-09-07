/*
 * Author: xiaohei_AWM
 * Date: 8.27
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
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
/* ll mul(ll a, ll b, ll p){
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
const int maxm = 2e3 + 10;
const int MOD = 1e9 + 7;
int t;
int n, base;
char s[maxm];
db d[800], ans;
vector<pair<int, db> > edge[800];
bool vis[800];
void clear(){
    memset(s, 0, sizeof(s));
    for(int i = 0; i <= 799; i++)
        edge[i].clear();
}
bool dfs(int x, double mid){//判正环
    vis[x] = 1;
    int lim = edge[x].size();
    for(int i = 0; i < lim; i++){
        int y = edge[x][i].first;
        if(d[x] + edge[x][i].second - mid > d[y]){
            d[y] = d[x] + edge[x][i].second - mid;
            if(vis[y] || dfs(y, mid)){ vis[x] = 0; return 1;}
        }
    }
    vis[x]=0;
    return 0;
}
inline bool check(double mid){
    memset(d, 0, sizeof(d));
    for(int i = 0; i <= 800; i++)
        if(dfs(i, mid)) return 1;
    return 0;
}
int main(){
    while(scanf("%d", &n), n != 0){
        clear();
        for(int i = 1; i <= n; i++){
            memset(s, 0, sizeof(s));
            scanf("%s", s);
            int len1 = strlen(s);
            int key1 = (s[0] - 'a')*26 + (s[1] - 'a'),
            key2 = (s[len1-2] - 'a')*26 + (s[len1-1] - 'a');
            edge[key1].push_back(make_pair(key2, (db)len1));//不用去重边
        }
        db l = -1, r = 1000;
        while(r-l >= 0.0001){
            db mid = (l + r)/2.0;
            if(check(mid)) l = mid;
            else r = mid;
            //cerr << mid << endl;
        }
        if(l <= 0.0) printf("No solution.\n");
        else printf("%.2f\n", l);
    }
    return 0;
}
