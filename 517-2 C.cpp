/*
 * Author: xiaohei_AWM
 * Date: 9.7
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
const int maxn = 5e5 + 10;
int n, q, dad[maxn], delta[maxn], size[maxn], val[maxn], u, v, op;
int find(int x){
    return x == dad[x] ? x : find(dad[x]);//子节点不能过多
}
void unionn(int u,int v){
    int fu = find(u), fv = find(v);
    if(fu != fv){
        if(size[fu] > size[fv]) swap(fu, fv);
        dad[fu] = fv;
        size[fv] += size[fu];
        delta[fu] -= delta[fv];
    }
}
int query(int x){
    int res = delta[x];
    while(x != dad[x]){
        x = dad[x];
        res += delta[x];
    }
    return res;
}
int main(){
    n = read(), q = read();
    for(int i = 1; i <= n; i++) dad[i] = i, size[i] = 1;
    if(n <= 6000 && q <= 6000){
        for(int i = 1; i <= q; i++){
            op = read(), u = read(), v = read();
            if(op == 1) unionn(u, v);
            else{
                for(int i = 1; i <= n; i++){
                    int f1 = find(u);
                    if(find(i) == f1) val[i] += v;
                }
            }
        }
        for(int i = 1; i <= n; i++) printf("%d ", val[i]);
        return 0;
    }
    for(int i = 1; i <= q; i++){
        op = read(), u = read(), v = read();
        if(op == 1) unionn(u, v);
        else delta[find(u)] += v;
    }
    for(int i = 1; i <= n; i++){
        int res = delta[i];
        for(int j = i; j != dad[j]; j = dad[j], res += delta[j]);
        printf("%d ", res);
    }
    return 0;
}
