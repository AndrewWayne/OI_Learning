/*
 * Author: xiaohei_AWM
 * Date: 11.2
 * Motto: Face to the weakness, expect for the strength.
 */
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
#define int     long long
using namespace std;
#define reg     register
#define endfile fclose(stdin); fclose(stdout);
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef std::pair<int, int>   pii;
typedef std::pair<ll, ll>     pll;
namespace IO {
char buf[1 << 15], *S, *T;
inline char gc() {
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 1 << 15, stdin);

        if (S == T) {
            return EOF;
        }
    }

    return *S++;
}

inline int read() {
    reg int x; reg bool f; reg char c;

    for (f = 0; (c = gc()) < '0' || c > '9'; f = c == '-') {
    }

    for (x = c ^ '0'; (c = gc()) >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c ^ '0')) {
    }

    return f ? -x : x;
}

inline ll readll() {
    reg ll x; reg bool f; reg char c;

    for (f = 0; (c = gc()) < '0' || c > '9'; f = c == '-') {
    }

    for (x = c ^ '0'; (c = gc()) >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c ^ '0')) {
    }

    return f ? -x : x;
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
int LEN, R;
int lfa[maxn], rfa[maxn];
ll pre[maxn], suf[maxn];
int l, r;
int height[maxn];
vector<int> E[maxn];
vector<pii> Q;
bool ban[maxn];
int dfs(int x, int fa) {
    //cerr << x << ": " << dis[x] << endl;
    if (dis[x] > maxl) {
        maxl = dis[x], k = x;
    }

    for (auto i = E[x].begin(); i != E[x].end(); i++) {
        if (*i == fa || ban[*i]) {
            continue;
        }

        dis[*i] = dis[x] + 1;
        dfs(*i, x);
    }
}

void dfsl(int x) {
    for (auto i = E[x].begin(); i != E[x].end(); i++) {
        if (*i == lfa[x]) {
            continue;
        }

        lfa[*i] = x;
        dfsl(*i);
    }
}

void dfsr(int x) {
    for (auto i = E[x].begin(); i != E[x].end(); i++) {
        if (*i == rfa[x]) {
            continue;
        }
        rfa[*i] = x;
        dfsr(*i);
    }
}

void dfss(int x, int fa){
    //cerr << x << ": " << dis[x] << endl;
    if (dis[x] > maxl)
        maxl = dis[x], k = x;
    ban[x] = true;
    for (auto i = E[x].begin(); i != E[x].end(); i++) {
        if (*i == fa || ban[*i])
            continue;
        dis[*i] = dis[x] + 1;
        dfss(*i, x);
    }
}

signed main() {
    //freopen("data.in", "r", stdin);
    //freopen("out1.out", "w", stdout);
    memset(height, 0xff, sizeof(height));
    n = read();
    LEN = -1;

    for (int i = 1; i < n; i++) {
        x[i] = read(), y[i] = read();
        E[x[i]].push_back(y[i]);
        E[y[i]].push_back(x[i]);
    }

    maxl = -1;
    dis[1] = 0;
    dfs(1, 0); l = k; dis[l] = 0; maxl = -1; dfs(l, 0);
    r = k; R = maxl; dfsl(l); dfsr(r);

//    cerr << "PRE" << endl;
    for (int i = 0, xx = l; i <= R; i++, xx = rfa[xx]) {//维护前缀最大
        ban[xx] = true;
        maxl = -1;

//        cerr << xx << ": " << endl;
        for (auto j = E[xx].begin(); j != E[xx].end(); j++) {
            if (*j != lfa[xx] && *j != rfa[xx]) {
                //            cerr << *j << endl;
                dis[*j] = 0;
                dfs(*j, xx);
//                cerr << "### " << maxl << endl;
            }
        }

        if (xx == l) {
            pre[xx] = maxl + i + 1;
        } else {
            pre[xx] = max(pre[lfa[xx]], maxl + i + 1);
        }

//        cerr << xx << ": " << pre[xx] << endl;
    }

//    cerr << "SUF" << endl;
    for (int i = 0, xx = r; i <= R; i++, xx = lfa[xx]) {//维护后缀最大
        ban[xx] = true;
        maxl = -1;

        for (auto j = E[xx].begin(); j != E[xx].end(); j++) {
            if (*j != lfa[xx] && *j != rfa[xx]) {
                dis[*j] = 0;
                dfs(*j, xx);
            }
        }

        if (xx == r) {
            suf[xx] = maxl + i + 1;
        } else {
            suf[xx] = max(suf[rfa[xx]], maxl + i + 1);
        }

        //    cerr << xx << ": " << suf[xx] << endl;
    }

    for (int xx = l, i = 0; xx != r; i++, xx = rfa[xx]) {
        maxl = -1;

        for (auto j = E[xx].begin(); j != E[xx].end(); j++) {
            if (*j != lfa[xx] && *j != rfa[xx]) {
                dis[*j] = 0;
                dfs(*j, xx);
            }
        }

        mx = maxl + i + 1;
        my = suf[rfa[xx]];

        if (mx >= 0) {
            height[mx] = max(height[mx], my);
        }

        if (my >= 0) {
            height[my] = max(height[my], mx);
        }
    }
    for (int xx = r, i = 0; xx != l; i++, xx = lfa[xx]) {
        maxl = -1;

        for (auto j = E[xx].begin(); j != E[xx].end(); j++) {
            if (*j != lfa[xx] && *j != rfa[xx]) {
                dis[*j] = 0;
                dfs(*j, xx);
            }
        }

        mx = maxl + i + 1;
        my = pre[lfa[xx]];

        if (mx >= 0) {
            height[mx] = max(height[mx], my);
        }

        if (my >= 0) {
            height[my] = max(height[my], mx);
        }
    }
/////////
    for (int i = 1; i <= n; i++) {
        if (!ban[i]) {
            //cerr << i << endl;
            //ban[i] = true;
            maxl = -1, dis[i] = 0;
            dfs(i, 0);
            maxl = -1, l = k, dis[l] = 0;
            dfss(l, 0);
            LEN = max(maxl, LEN);
        }
    }
    /////cout << "TLE" << endl;

    if (LEN >= 0) {
        height[LEN] = max(height[LEN], R);
    }

    if (R >= 0) {
        height[R] = max(height[R], LEN);
    }

    //cerr << LEN << " " << disl[r] << endl;

    int high = -1;

    for (int i = n; i >= 0; i--) {
        //cerr << height[i] << " ";
        high = max(high, height[i]);
        ans += high + 1;
    }

    //cerr << endl;
    printf("%lld\n", ans);

    return 0;
}
