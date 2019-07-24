/*
 * Author: xiaohei_AWM
 * Date: 6.5
 * Mutto: Face to the weakness, expect for the strength.
*/
//zkw线段树，区间求和，洛谷P3374
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
const int maxn = 5e5 + 10;
struct Sege{
    int sum, tag;
    int times;
} ST[2 * maxn];
int n, m, cnt, a[maxn];
inline void build(int n){
    for(cnt = 1; cnt <= n; cnt <<= 1);
    for(int i = cnt + 1; i <= cnt + n; i++) a[i - cnt] = ST[i].sum = read();
    for(int i = cnt - 1; i; i--)
        ST[i].sum = ST[i << 1].sum + ST[i << 1 | 1].sum;
}
inline int Query(int l, int r){//范围[1, 2^N - 2], 查询闭区间[l, r]
    int res = 0;
    for(l = l + cnt - 1, r = r + cnt + 1; l ^ r ^ 1; l >>= 1, r >>= 1){//先将至转化为开区间，因为zkw线段树基于天然非递归的方法要求从零开始查询开区间
        if(~l & 1) res += ST[l ^ 1].sum;
        if( r & 1) res += ST[r ^ 1].sum; // r & 1 == true所以奇数 i ^ 1 = i - 1
        //每层最多查询两个点，即当左边界节点在其所在子树的左子时（是偶数），加上右子，当右边界节点在子树的右子时（是奇数）加上左子。
    }
    return res;
}
inline void Add(int pos, int x){//单点加
    for(ST[pos += cnt].sum += x, pos >>= 1; pos; pos >>= 1)
        ST[pos].sum = ST[pos << 1].sum + ST[pos << 1 | 1].sum;
}
int main(){
    n = read(), m = read();
    build(n);
    int opt, l, r;
    for(int i = 1; i <= m; i++){
        opt = read(), l = read(), r = read();
        if(opt == 1) Add(l, r);
        if(opt == 2) printf("%d\n", Query(l, r));
    }
    return 0;
}
