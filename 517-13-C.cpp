/*
 * Author: xiaohei_AWM
 * Date:11.1
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
#include<map>
#include<cmath>
#include<vector>
#include<assert.h>
#include<set>
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
const int maxn = 1010;
set<int> X, Y;
map<pii, bool> done;
map<pii, int> pots;
int n, a, b, cnt, len, leny1, leny2;
int dx[20] = {1, 1, 1, 1, -1, -1, -1, -1};
int dy[20] = {-1, -1, 1, 1, -1, -1, 1, 1};
int lenxx[20], lenyy[20];
pii pot[maxn];
bool visited[maxn][maxn], used[maxn];
int dis(int u, int v){
    return abs(pot[u].first - pot[v].first) + abs(pot[u].second - pot[v].second);
}
void dfs(int a){
    for(int i = 1; i <= n; i++){
        if(i == a) continue;
        if(visited[a][i]) continue;
        if(dis(a, i) == len){
            //visited[i] = true;
            visited[a][i] = visited[i][a] = true;
            cnt++;
            if(!used[i])
                used[i] = true, dfs(i);
        }
    }
}

void dfs1(int a){
    pii tmp;
    for(int i = 0; i < 16; i++){
        tmp = make_pair(pot[a].first + lenxx[i], pot[a].second + lenyy[i]);
        if(pots.count(tmp)){
            int id = pots[tmp];
            cnt++;
            if(!done.count(make_pair(id, a))){
                done[make_pair(id, a)] = true;
                done[make_pair(a, id)] = true;
                dfs1(id);
            }
        }
    }
}
void solve1(){
    pii tmp = pot[a];
    if(Y.size() == 2){
        leny1 = abs(pot[1].second - pot[2].second);
        leny2 = 0;
        int lenx1 = len - leny1;
        int lenx2 = len - leny2;
        for(int i = 0; i < 16; i++){
            if(i & 1){
                lenxx[i] = dx[i] * lenx1;
                lenyy[i] = dy[i] * leny1;
            }else{
                lenxx[i] = dx[i] * lenx2;
                lenyy[i] = dy[i] * leny2;
            }
        }
    }else{
        int lenx1 = abs(pot[1].first - pot[2].first);
        int lenx2 = 0;
        leny1 = len - lenx1;
        leny2 = len - lenx2;
        for(int i = 0; i < 16; i++){
            if(i & 1){
                lenxx[i] = dx[i] * lenx1;
                lenyy[i] = dy[i] * leny1;
            }else{
                lenxx[i] = dx[i] * lenx2;
                lenyy[i] = dy[i] * leny2;
            }
        }
    }
    dfs1(a);
}

int main(){
    n = read(), a = read(), b =read();
    for(int i = 1; i <= n; i++){
        pot[i].first = read(), pot[i].second = read();
        X.insert(pot[i].first), Y.insert(pot[i].second);
        pots[pot[i]] = i;
    }
    len = abs(pot[a].first - pot[b].first) + abs(pot[a].second - pot[b].second);
    used[a] = true;
    if(n <= 1000)
        dfs(a);
    else
        solve1();
    //else
    cout << cnt << endl;
    return 0;
}
