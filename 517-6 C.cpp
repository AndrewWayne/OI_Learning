/*
 * Author: xiaohei_AWM
 * Date: 9.21
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
const int maxn = 3e5 + 10;
int n, u[maxn], v[maxn];
vector<int> E[maxn];
int D[maxn], dad[maxn], rk[maxn];
int fa[21][maxn], depth[maxn];
int L[maxn], R[maxn];
int find(int x){
    return dad[x] == x ? x : dad[x] = find(dad[x]);
}
void dfs1(int x, int ff){
    //cerr << x << ": " << depth[x] << endl;
    for(int i = 1; i <= 20; i++) fa[i][x] = fa[i-1][fa[i-1][x]];
    //for(int i = 0; i <= 4; i++) cerr << x << ": " << fa[i][x] << endl;
    //cerr << x << ": " << fa[i][x] << endl;
    for(int i = 0; i < E[x].size(); i++)
        if(E[x][i] != ff){
            //cerr << x << ": " << depth[x] << endl;
            fa[0][E[x][i]] = x;
            depth[E[x][i]] = depth[x]+1;
            //cerr << E[x][i] << ": " << depth[E[x][i]] << endl;
            dfs1(E[x][i], x);
        }
}
void goUp(int &node, int step){
    for(int i = 20; i >= 0 && step != 0; i--){
        if(step - (1 << i) >= 0)
            step -= 1<< i, node = fa[i][node];
    }
}
int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    //cerr << depth[x] << " " << depth[y] << endl;
    goUp(x, depth[x] - depth[y]);
    //cerr << x << " " << y << endl;
    if(x == y)
        return x;
    for(int i = 20; i >= 0; i--)
        if(fa[i][y] != fa[i][x])
            x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}
int length(int x, int y){
    return depth[x] + depth[y] - 2*depth[LCA(x,y)];
}
void unionn(int u, int v){
    int fu = find(u), fv = find(v), fn;
    if(fu == fv) return;
    if(rk[fu] > rk[fv]){
        dad[fv] = fu, rk[fu] += rk[fv];
        fn = fu;
    }else{
        dad[fu] = fv, rk[fv] += rk[fu];
        fn = fv;
    }
    vector<pii> V;
    int a = L[fu], b = R[fu], c = L[fv], d = R[fv];
    V.push_back(make_pair(length(L[fu], R[fu]), 1));
    V.push_back(make_pair(length(L[fu], R[fv]), 2));
    V.push_back(make_pair(length(L[fv], R[fv]), 3));
    V.push_back(make_pair(length(L[fv], R[fu]), 4));
    V.push_back(make_pair(length(L[fu], L[fv]), 5));
    V.push_back(make_pair(length(R[fv], R[fu]), 6));
    sort(V.begin(), V.end());
    //cerr << V[5].first << " " << V[5].second << endl;
    //cerr << L[fu] << " " << L[fv] << endl;
    switch (V[5].second) {
        case 1:
            L[fn] = a, R[fn] = b;
            break;
        case 2:
            L[fn] = a, R[fn] = d;
            break;
        case 3:
            L[fn] = c, R[fn] = d;
            break;
        case 4:
            L[fn] = c, R[fn] = b;
            break;
        case 5:
            L[fn] = a, R[fn] = c;
            break;
        case 6:
            L[fn] = d, R[fn] = b;
            break;
    }
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++) dad[i] = i, rk[i] = 1, D[i] = 0, L[i] = R[i] = i;
    for(int i = 1; i <= n-1; i++){
        u[i] = read(), v[i] = read();
        E[v[i]].push_back(u[i]);
        E[u[i]].push_back(v[i]);
    }
    //cerr << endl;
    dfs1(1, 0);
    for(int i = 1; i <= n-1; i++){
        int fu = find(u[i]), fv = find(v[i]);
        unionn(u[i], v[i]);
        fu = find(u[i]);
        //cerr << L[fu] << " --- " << R[fu] << endl;
        printf("%d\n", length(L[fu], R[fu]));
    }
    return 0;
}
