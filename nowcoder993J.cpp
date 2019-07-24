/*
 * Author: xiaohei_AWM
 * Date: 7.13
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<map>
#include<functional>
#include<queue>
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
typedef double db;
const int maxn=1010;
int n,m;
int a[maxn];
struct node{int v, dis, nxt;} E[5010];
int head[maxn], tot;
int vis[maxn], num[maxn];
db d[maxn];

void add(int u,int v,int dis){
    E[++tot].nxt = head[u];
    E[tot].v = v;
    E[tot].dis = dis;
    head[u] = tot;
}

int check(db x){
    queue<int> Q;
    for(int i = 1; i <= n; ++i){
        Q.push(i), d[i] = 0;
        vis[i] = num[i] = 1;
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop(), vis[u] = 0;
        for(int i = head[u]; i; i = E[i].nxt){
            int v = E[i].v;
            db dis = (db)E[i].dis;
            if(d[v] > d[u] + x*dis - (db)a[u]){
                d[v] = d[u] + x*dis - (db)a[u];
                if(!vis[v]){
                    Q.push(v);
                    vis[v] = 1;
                    if(++num[v] >= n) return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; ++i)
        a[i] = read();
    for(int i = 1; i <= m; ++i){
        int u = read(), v = read(), dis = read();
        add(u, v, dis);
    }
    db L = 0, R = 1000010, mid;
    while(R-L > 1e-4){
        mid = (L+R)/2;
        if(check(mid)) L = mid;
        else R = mid;
    }
    printf("%.2lf", L);
    return 0;
    //niiick
}
