// luogu-judger-enable-o2
/*
 * Author: xiaohei_AWM
 * Date: 7.26
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#include<cstdlib>
#include<queue>
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
const int maxn = 2e5 + 10;
struct Edge{
    int to, nxt;
} edges[2*maxn];
vector<int> F[1+(1 << 20)];
queue<int> Q;
int n, m, x, y, visited[maxn], head[maxn], cnt, dis[maxn], tags[maxn];
ll a[maxn], maxa;
void add(int u, int v){
    edges[++cnt].to = v;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
}
int main(){
    memset(dis, 0xff, sizeof(dis));
    n = read(), m = read();
    dis[1] = 0;
    Q.push(1);
    visited[1] = 1;
    for(int i = 1; i <= n; i++){
        a[i] = readll();
        maxa = max(a[i], maxa);
        //if(n > 1000)
            F[a[i]].push_back(i);
    }
    for(int i = 1; i <= m; i++){
        x = read(), y = read();
        add(x, y);
    }
    if(maxa == 0){
        printf("0\n");
        for(int i = 2; i <= n; i++)
            printf("1\n");
        return 0;
    }
    /*else if(n <= 1000){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i != j && ((a[i] & a[j]) == a[j]))
                    add(i, j);
        while(!Q.empty()){
            x = Q.front();
            Q.pop();
            for(int i = head[x]; i; i = edges[i].nxt)
                if(!visited[edges[i].to])
                    Q.push(edges[i].to),
                    visited[edges[i].to] = 1,
                    dis[edges[i].to] = dis[x] + 1;
        }
    }else{
    */
        while(!Q.empty()){
            x = Q.front();
            Q.pop();
            if(visited[x]) continue;
            visited[x] = true;
            for(int k = 0; (a[x] >> k); k++){
                if((a[x] >> k) & 1){
                    int temp = a[x] ^ (1 << k);
                    if(F[temp].size())
                        for(auto i = F[temp].begin(); i != F[temp].end(); i++){
                            if(!visited[*i]){
                                tags[*i] = 1;
                                visited[*i] = 1;
                                Q.push(*i);
                                dis[*i] = dis[x];
                            }
                        }
                }
            }
            dis[x] += tags[x];
            tags[x] = 0;
            for(int i = head[x]; i; i = edges[i].nxt)
                if(!visited[edges[i].to])
                    Q.push(edges[i].to),
                    visited[edges[i].to] = 1,
                    dis[edges[i].to] = dis[x] + 1;
        }
    //}
    for(int i = 1; i <= n; i++)
        printf("%d\n", dis[i]);
    return 0;
}
