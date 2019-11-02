//#include <bits/stdc++.h>
/*
 * Author: xiaohei_AWM
 * Date: 11.1
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
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-'){
            if(c == '-'){ f = 1, c = gc(), c = gc(); break;}
            if(c == '+'){ f = 0, c = gc(), c = gc(); break;}
        }
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
int n, q, x, y, top, sym[maxn];
ll w[maxn], sum[maxn], abssum[maxn], ans;
char opt[maxn];
//贪心策略：最优策略一定是在两个相邻负数之间括号，把序列分成三段（怎么证明？）
int sign(ll x){
    return x >= 0 ? 1 : -1;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        w[i] = read();
        sym[i] = sign(w[i]);
        w[i] = abs(w[i]);
    }
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + w[i] * sym[i];
        abssum[i] = abssum[i-1] + w[i];
        //cerr << sum[i] << " ";
    }
    //cerr << endl;
    int last = -1;
    ans = sum[n];//也可以不加括号
    for(int i = n; i >= 1; i--){
        if(sym[i] < 0){
            if(last == -1){last = i; continue;}//找到右边的负号
            ll val = sum[i];//[1, i]
            val -= abssum[last-1] - abssum[i];//[i+1, last-1]这段之后的正数变负数（因为被括号括了）
            val += abssum[n] - abssum[last-1];//[last, n]把后面的负数变正数
            last = i;
            //cerr << val << endl;
            ans = max(ans, val);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
