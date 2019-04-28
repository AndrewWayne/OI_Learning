/*
 * Author: xiaohei_AWM
 * Date: 4.20
 * Mutto: Face to the weakness, expect for the power.
 *
 * Problem:
 * 给一个序列，定义一个区间的权值是区间和×区间最小值，求序列里最大的区间权值
 * 值域正负1e5, n ≤ 5e5
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
#include<queue>
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
const int maxn = 5e5 + 10;
int n, m, a[maxn], l[maxn], r[maxn];// 区间[ l[i], r[i] ]表示以a[i]为最小值的区间大小
ll sum[maxn], st1[maxn][30], st2[maxn][30], ans;
int Log2[maxn];
ll queryMax(int l, int r){
    ll res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = max(st1[l][x], st1[r - (1<<x) + 1][x]);
    return res;
}
ll queryMin(int l, int r){
    ll res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = min(st2[l][x], st2[r - (1<<x) + 1][x]);
    return res;
}
int main(){
    n = read();
    for(int i = 2; i <= n; i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }
    int len = Log2[n];
    for(int i = 1; i <= n; i++)
        a[i] = read(), sum[i] = sum[i-1] + a[i], l[i] = r[i] = i;
    for(int i = 1; i <= n; i++)
        st1[i][0] = st2[i][0] = sum[i];
    for(int i = 1; i <= len; i++)
        for(int j = 1; j + (1<<i) -1 <= n; j++){
            st1[j][i] = max(st1[j][i-1], st1[j + (1 << (i-1))][i-1]);
            st2[j][i] = min(st2[j][i-1], st2[j + (1 << (i-1))][i-1]);
        }
    a[0] = a[n + 1] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        while (a[i] <= a[l[i] - 1])
            l[i] = l[l[i] - 1];
    for (int i = n; i >= 1; i--)
        while (a[i] <= a[r[i] + 1])
            r[i] = r[r[i] + 1];
    ans = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        ll val;
        if(a[i] < 0)
            val = queryMin(i, r[i]) - queryMax(l[i]-1, i-1);
        else if(a[i] == 0)
            val = 0;
        else
            val = queryMax(i, r[i]) - queryMin(l[i]-1, i-1);
        ans = max(ans, val * a[i]);
    }
    cout << ans << endl;
    return 0;
}
