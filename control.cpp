/*
 * Author: xiaohei_AWM
 * Date: 7.19
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
struct Edge{
    int u, v;
    double dis, disc;
    bool operator<(const Edge &vv)const{
        return dis > vv.dis;
    }
} edge1[1000100], edge2[1000100];
int n,m,dad[1010],ranks[1010], ans, a[1010], f[1010], k[1010], tot;
double l, r;
int find(int x){
    return dad[x] == x ? x:dad[x] = find(dad[x]);
}
void unionn(int u,int v){//按秩合并
    int fu = find(u);
    int fv = find(v);
    if(fu == fv) return;
    if(ranks[fu] < ranks[fv])
        dad[fu] = fv;
    else{
        dad[fv] = fu;
        if(fu == fv)
            ranks[fu]++;
    }
}
bool kruskal(double x){
    for(int i = 1; i <= n; i++)
        dad[i] = i;
    memset(ranks, 0, sizeof(ranks));
    int k = 0;
    int res = 0;
    for(int i = 1; i <= tot; i++){
        edge2[i].u = edge1[i].u;
        edge2[i].v = edge1[i].v;
        edge2[i].dis = edge1[i].disc - x*edge1[i].dis;
    }
    sort(edge2+1, edge2+1+tot);
    for(int i = 1; i <= tot; i++){
        if(find(edge2[i].u) == find(edge2[i].v)) continue;
        unionn(edge2[i].u, edge2[i].v);
        k++;
        res += edge2[i].dis;
        if(k == n-1) break;
    }
    if(k < n-1){
        printf("poor jlb!\n");
        exit(0);
    }else
        return (res > 0);
}
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)
        scanf("%d%d%d", &a[i], &f[i], &k[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j && k[i] != k[j]){
                edge1[++tot].u = i,
                edge1[tot].v = j,
                edge1[tot].dis = a[i] ^ a[j],
                edge1[tot].disc = f[i] ^ f[j],
                r += edge1[tot].disc;
            }
    if(tot < n-1){
        printf("poor jlb!");
        return 0;
    }
    while(r - l > 0.0005){
        double mid = (l+r)/2.0;
        if(kruskal(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", (int)r );
    return 0;
}
