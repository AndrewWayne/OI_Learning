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
#include<utility>
#include<set>
#include<stack>
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
int n, m, x, y, cnt;
vector<int> couple[maxn];
vector<int> E[maxn];
set<pii> sege;
pii S[maxn], top;
int L[maxn], R[maxn], node[maxn];
int ans[maxn];
void dfs1(int x, int fa){
    node[++cnt] = x;
    L[x] = cnt;
    for(auto i = E[x].begin(); i != E[x].end(); i++)
        if(*i != fa)
            dfs1(*i, x);
    R[x] = cnt;
}
void dfs(int x, int fa, int al, int ar){
    //cerr << x << endl;
    if(couple[x].size() > 0){
        al = min(L[x], al), ar = max(R[x], ar);
        for(auto i = couple[x].begin(); i != couple[x].end(); i++){
            if(L[*i] >= al && R[*i] <= ar) continue;
            sege.insert(make_pair(L[*i], R[*i]));
        }
        //stack<pii> S;
    }
    //cerr << al << " " << ar << endl;
    int l = 1, r = 0;
    for(auto i = sege.begin(); i != sege.end(); i++){
        if(i->first > r){
            ans[x] += r - l + 1;
            if(l <= r) S[++top] = make_pair(l, r);
            l = i -> first;
            r = i -> second;//, cerr << "$: " << l << " " << r << endl;
        }else r = max(r, i -> second);
    }
    ans[x] += r - l + 1;
    S[++top] = make_pair(l, r);
    sege.clear();
    for(int i = 1; i <= )
//    if(x == 9) cerr << l << " " << r << endl;
    if(ar >= al)
        ans[x] += ar - al ;
    for(auto i = E[x].begin(); i != E[x].end(); i++)
        if(*i != fa) dfs(*i, x, al, ar);
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n-1; i++){
        x = read(), y = read();
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for(int i = 1; i <= m; i++){
        x = read(), y = read();
        couple[x].push_back(y);
        couple[y].push_back(x);
    }
    dfs1(1, 0);
    dfs(1, 0, n, 1);
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
