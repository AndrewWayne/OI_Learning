/*
 * Author: xiaohei_AWM
 * Date: 9.30
 * Motto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<set>
#include<ctime>
#include<map>
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
struct Node{
    int x, y;
    int t1, t2;
    int id;
} node[maxn];
set<pii> val[maxn << 2];
map<pii, int> l;
int n, m, x, y, top;
char opt[20];
char ans[maxn][20];
bool cmp(Node u, Node v){
    if(u.y == v.y){
        return u.t2 < v.t2;
    }
    return u.y > v.y;
}

void Upd(int L, int R, int l, int r, int rt, int X, int Y){
    if(L <= l && r <= R){
        val[rt].insert(make_pair(X, Y));
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) Upd(L, R, l, mid, rt << 1, X, Y);
    if(R > mid) Upd(L, R, mid+1, r, rt<<1|1, X, Y);
    return;
}
pii Query(int t, int l, int r, int rt, int X, int Y){
    pii tmp = make_pair(X+1, Y);
    if(l == r){
        if(val[rt].size() == 0 ) return make_pair(INF, INF);
        if(val[rt].upper_bound(tmp) == val[rt].end())
            return make_pair(INF, INF);
        return *val[rt].upper_bound(tmp);
    }
    int mid = (l+r) >> 1;
    pii res;
    if(t <= mid) res = Query(t, l, mid, rt << 1, X, Y);
    if(t > mid) res = Query(t, mid+1, r, rt << 1|1, X, Y);
    if(t >= l && t <= r && val[rt].size() > 0 && val[rt].end() != val[rt].upper_bound(tmp)){
        res = min(*val[rt].upper_bound(tmp), res);
    }
    return res;
}
int main(){
    //freopen("Shoot.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s%d%d", opt, &x, &y);
        if(opt[0] == 'a') l[make_pair(x, y)] = i;
        if(opt[0] == 'r'){
            node[++top].x = x, node[top].y = y;
            node[top].t1 = l[make_pair(x, y)];
            node[top].t2 = i;
            l.erase(make_pair(x, y));
        }
        if(opt[0] == 'f')
            node[++top].x = x, node[top].y = y, node[top].t1 = i, node[top].t2 = 0, node[top].id = i;
    }
    pii tmp;
    for(auto i = l.begin(); i != l.end(); i++){
        tmp = i->first;
        node[++top].x = tmp.first, node[top].y = tmp.second;
        node[top].t1 = i->second, node[top].t2 = n;
    }
    sort(node+1, node+1+top, cmp);
    for(int i = 1; i <= top; i++){
        if(node[i].id == 0){
            Upd(node[i].t1, node[i].t2, 1, n, 1, node[i].x, node[i].y);
        }
        else if(node[i].t2 == 0){
            tmp = Query(node[i].t1, 1, n, 1, node[i].x, node[i].y);
            if(tmp.first == INF) sprintf(ans[node[i].id], "-1\n");
            else sprintf(ans[node[i].id], "%d %d\n", tmp.first, tmp.second);
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%s", ans[i]);
    }
    return 0;
}
