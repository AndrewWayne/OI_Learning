/*
 * Author: xiaohei_AWM
 * Date:
 * Mutto: Face to the weakness, expect for the strength.
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
#define P1 (p << 1)
#define P2 (p << 1) | 16
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
const int N = 500050;
struct Seg{
    int l, r;
    int sum, mx;
    int lx, rx;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define mx(i) tree[i].mx
    #define lx(i) tree[i].lx
    #define rx(i) tree[i].rx
}tree[N << 2];
int A[N], n, m, lss, rr;
void up(Seg &a,Seg b,Seg c) {
    a.sum = b.sum + c.sum;
    a.mx = max(b.mx, c.mx);
    a.mx = max(a.mx, b.rx + c.lx);
    a.lx = max(b.lx, b.sum + c.lx);
    a.rx = max(c.rx, c.sum + b.rx);
}
void build (int p,int l,int r) {
    l(p) = l, r(p) = r;
    if (l == r) {
        sum(p) = mx(p) = A[l];
        lx(p) = rx(p) = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build (P1, l, mid);
    build (P2, mid+1, r);
    up(tree[p], tree[P1], tree[P2]);
}

void update(int p,int x,int d) {
    if (l(p) == r(p)) {
        sum(p) = mx(p) = A[l(p)];
        lx(p) = rx(p) = A[l(p)];
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (mid >= x) update(P1, x, d);
    else  update(P2, x, d);
    up(tree[p], tree[P1], tree[P2]);
}
Seg ask(int p,int l,int r) {
    if (l(p) >= l && r(p) <= r) return tree[p];
    int mid = (l(p) + r(p)) >> 1;
    if (r <= mid) return ask(P1, l, r);
    if (l > mid ) return ask(P2, l, r);
    Seg rec, a = ask(P1, l, r), b = ask(P2, l, r);
    up(rec, a, b);
    return rec;
}
int main() {
    n = read(), m = read();
    for (int i = 1;i <= n; i++) A[i] = read();
    build (1, 1, n);
    while (m--) {
        int x = read();
        lss = read(), rr = read();
        if (x == 2) A[lss] = rr, update(1, lss, rr);
        else printf("%d\n", ask(1, lss, rr).mx);
    }
    return 0;
}
