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
const int maxn = 2e3 + 10;
struct Edge{
    int from, to;
    ll w;
} edge[maxn*(maxn+1)];
int n, a[maxn], dad[maxn], cnt;
ll ans;
bool cmp(Edge _x, Edge _y){
    return _x.w > _y.w;
}
int find(int x){
    return x == dad[x] ? dad[x] : dad[x] = find(dad[x]);
}
bool unionn(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy)  return false;
    dad[fx] = fy;
    return true;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), dad[i] = i;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            edge[++cnt].from = i, edge[cnt].to = j, edge[cnt].w = a[i] ^ a[j];
    sort(edge+1, edge+1+cnt, cmp);
    for(int i = 1; i <= cnt; i++){
        if(unionn(edge[i].from, edge[i].to))
            ans += edge[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
