/*
 * Author: xiaohei_AWM
 * Date: 11.2
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
#define int long long
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
int n, x[maxn], y[maxn], mx, my, dis[maxn], k, maxl, ans;
bool counted[55][55];
vector<int> E[maxn];
bool ban[maxn];
int dfs(int x, int fa){
    //cerr << x << ": " << dis[x] << endl;
    if(dis[x] > maxl) maxl = dis[x], k = x;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(*i == fa || ban[*i]) continue;
        dis[*i] = dis[x] + 1;
        dfs(*i, x);
    }
}
signed main(){
    //freopen("treepro.in", "r", stdin);
    n = read();
    for(int i = 1; i < n; i++){
        x[i] = read(), y[i] = read();
        E[x[i]].push_back(y[i]);
        E[y[i]].push_back(x[i]);
    }
    if(n <= 50){
        for(int i = 1; i < n; i++){
            maxl = -1;
            ban[x[i]] = true;
            dis[y[i]] = 0;
            dfs(y[i], 0);
            dis[k] = 0;
            dfs(k, 0);
            mx = maxl;
            ban[x[i]] = false;
            maxl = -1;
            ban[y[i]] = true;
            dis[x[i]] = 0;
            dfs(x[i], 0);
            dis[k] = 0;
            dfs(k, 0);
            my = maxl;
            ban[y[i]] = false;
            //ans += (my - mx) * 2 + 1;
            //*
            for(int i = 0; i <= mx; i++)
                for(int j = 0; j <= my; j++){
                    if(!counted[i][j])
                        ans += 1, counted[i][j] = 1;
                    if(!counted[j][i])
                        ans += 1, counted[j][i] = 1;
                }
            //*/
        }
    }else{
        for(int i = 0; i <= (n-2)/2; i++){
            int j = n - i - 2;
            ans += (j - i) * 2 + 1;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
