/*
 * Author: xiaohei_AWM
 * Date: 9.10
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
const int MAX_V = 1e5 + 10;
const int maxn = 120;
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
int n, m, f[MAX_V], a[maxn], c[maxn], ans;//c是cost v是value
inline void pack(int f[], int V, int c, int n, int w){// v是体积，w是价值
    if (n == 0 || c == 0) return;
    if (n == 1){               //01背包
        for (int i = V; i >= c; --i)
            if (f[i] < f[i - c] + w)
                f[i] = f[i - c] + w;
        return;
    }
    if(n * c >= V - c + 1){   //完全背包(n >= V / v)
        for (int i = c; i <= V; ++i){
            if (f[i] < f[i - c] + w)
                f[i] = f[i - c] + w;
        }
        return;
    }
    int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列
    for (int j = 0; j < c; ++j) {     //多重背包
        int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素
        int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素
        for (int k = j, i = 0; k <= V; k += c, ++i) {
            if (pe  == pb + n) {       //若队列大小达到指定值，第一个元素X出队。
                if (*pb == *qb) ++qb;//若辅助队列第一个元素等于X，该元素也出队。
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;                  //元素X进队
            //删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法
            while(qe >= qb && *qe < tt) --qe;
            *++qe = tt;              //元素X也存放入辅助队列
            f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
        }
    }
}
void check(int f[], int V, int c, int num){
    for(int i = 0; i <= V; i++){
        if(f[i] >= 0) f[i] = num;
        else f[i] = -1;
    }
    for(int i = 0; i <= V-c; i++){
        if(f[i] > 0)
            f[i+c] = max(f[i+c], f[i] - 1);
    }
}
int main(){
    while(scanf("%d%d", &n, &m), n && m){
        memset(f, 0xff, sizeof(f));
        f[0] = 0;
        ans = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
        for(int i = 1; i <= n; i++)
            check(f, m, a[i], c[i]);
        for(int i = 1; i <= m; i++) ans += (f[i] >= 0);
        printf("%d\n", ans);
    }
    return 0;
}
