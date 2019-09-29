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
//set<pii> sege;

int L[maxn], R[maxn], node[maxn];
int ans[maxn], sum[maxn << 2], tags[maxn << 2];
void dfs1(int x, int fa){
    node[++cnt] = x;
    L[x] = cnt;
    for(auto i = E[x].begin(); i != E[x].end(); i++)
        if(*i != fa)
            dfs1(*i, x);
    R[x] = cnt;
}
void pushUp(int rt, int l, int r){
    if(tags[rt] > 0)//如果这是个塞苹果的区间就把这段区间全部置1，tags的意义只有有放和没放，记录值只是为了可以回溯
        sum[rt] = r - l + 1;
    else if(l == r)//如果这是个不带塞苹果的子节点，直接置零
        sum[rt] = 0;
    else
        sum[rt] = sum[rt << 1] + sum[rt << 1|1];//非子节点，自己也没前途的就从子节点里合并，看看后浪能不能推前浪
}
void Upd(int L, int R, int val, int l, int r, int rt){
    //cerr << "##: " << rt << endl;
    //cerr << l << " " << r << endl;
    //cerr << L << " " << R <<endl;
    if(L <= l && r <= R){
        tags[rt] += val;//标记永久化
        pushUp(rt, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) Upd(L, R, val, l, mid, rt << 1);
    if(R > mid) Upd(L, R, val, mid+1, r, rt << 1 | 1);
    pushUp(rt, l, r);
}
void dfs(int x, int fa){
    //cerr << "$$ " << x << endl;
    if(couple[x].size() > 0)
        //al = min(L[x], al), ar = max(R[x], ar);
        for(auto i = couple[x].begin(); i != couple[x].end(); i++){
            //cerr << *i << endl;
            Upd(L[*i], R[*i], 1, 1, n, 1);//给[L, R]这段区间赋上值

        }
            //if(L[*i] >= al && R[*i] <= ar) continue;
            //sege.insert(make_pair(L[*i], R[*i]));
        //stack<pii> S;
    //cerr << x << endl;
    ans[x] = sum[1];//整棵树上有赋值的区间
    /*
    //cerr << al << " " << ar << endl;
    int l = 1, r = 0;
    for(auto i = sege.begin(); i != sege.end(); i++){
        if(i->first > r) ans[x] += r - l + 1, l = i -> first, r = i -> second;//, cerr << "$: " << l << " " << r << endl;
        else r = max(r, i -> second);
    }

    ans[x] += r - l + 1;
//    if(x == 9) cerr << l << " " << r << endl;
    if(ar >= al)
        ans[x] += ar - al;*/
    for(auto i = E[x].begin(); i != E[x].end(); i++)
        if(*i != fa) dfs(*i, x);
    if(couple[x].size() > 0)
        for(auto i = couple[x].begin(); i != couple[x].end(); i++)
            Upd(L[*i], R[*i], -1, 1, n, 1);//回溯，把这个点的影响消掉
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
        couple[x].push_back(x);
        couple[y].push_back(x);
        couple[y].push_back(y);
    }
    //cerr << n << endl;
    dfs1(1, 0);
    //for(int i = 1; i <= n; i++){
        //cerr << L[i] << " " << R[i] << endl;
    //}
    //cerr << cnt << endl;
    dfs(1, 0);
    //cerr << n << endl;
    for(int i = 1; i <= n; i++)
        printf("%d ", max(1, ans[i]) - 1);
    return 0;
}
