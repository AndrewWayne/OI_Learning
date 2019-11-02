/*
 * Author: xiaohei_AWM
 * Date: 10.26
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
#include<set>
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
const int maxn = 1e5 + 10;
vector<int> Q[maxn];
int n, m, l, r, c[maxn], cnt;
void add(int x, int val){
    for(int i = x; i <= m; i += (i & -i))
        c[i] += val;
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= (i & -i)){
        res += c[i];
    }
    return res;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        l = read(), r = read();
        Q[r-l+1].push_back(l);
    }
    cnt = n;
    for(int i = 1; i <= m; i++){
        int ans = cnt;//长度大于 i 的区间一定包含 i 的倍数
        for(int j = i; j <= m; j += i)
            ans += query(j);//O(m ln m) 把之前长度小于 i 的区间里有累计上去，因为长度小于 i 所以一定不会重复计数
        cnt -= Q[i].size();
        for(vector<int>::iterator k = Q[i].begin(); k != Q[i].end(); k++)
            add(*k, 1), add(*k + i, -1);//这里有一个O(n)的复杂度
        printf("%d\n", ans);
    }

    return 0;
}
