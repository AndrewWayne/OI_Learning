//#include <bits/stdc++.h>
/*
 * Author: xiaohei_AWM
 * Date: 11.1
 * Motto: Face to the weakness, expect for the strength.
*/
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn = 3e5 + 10;
const int maxy = 550;
int n, w[maxn], q, x, y;
int cnt[maxy][maxy];
vector<pii> query[maxy][maxy];
vector<pii>::reverse_iterator it[maxy][maxy];
vector<pii>::reverse_iterator lim[maxy][maxy];
ll val[maxy][maxy], ans[maxn];
int main(){
    n = read();
    int sn = sqrt(n);
    for(int i = 1; i <= n; i++)
        w[i] = read();
    q = read();
    for(int i = 1; i <= q; i++){
        x = read(), y = read();
        if(y > sn){
            for(int j = x; j <= n; j += y)
                ans[i] = ans[i] + w[j];
        }else
            query[y][x % y].emplace_back(make_pair(x, i)),
            cnt[y][x % y]++;
    }
    for(int i = 1; i <= sn; i++)
        for(int j = 0; j < i; j++){
            if(cnt[i][j] > 0){
                sort(query[i][j].begin(), query[i][j].end());
                it[i][j] = query[i][j].rbegin();
                lim[i][j] = query[i][j].rend();
            }
        }

    for(int i = n; i >= 1; i--){//倒扫
        for(int j = 1; j <= sn; j++){//y的余数
            int key = i % j;
            val[j][key] = val[j][key] + w[i];//直接统计这一条上的值
            if(cnt[j][key] > 0 && it[j][key] != lim[j][key]){
                while(it[j][key]->first == i){
                    ans[it[j][key]->second] = val[j][key];
                    it[j][key]++;
                }
            }
        }
    }

    for(int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
