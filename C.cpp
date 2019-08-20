/*
 * Author: xiaohei_AWM
 * Date: 7.20
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
#include<string>
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
const int maxn = 200;
const int maxm = 1e6 + 10;
int n, m;
int dis[maxn][maxn];
bool visit[maxn][maxn][maxn];
int pre[maxm], nxt[maxm], val[maxm];
string v[maxn];
int main(){
    cin >> n;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < n; j++)
            if(v[i][j] == '1')
            dis[i][j+1] = 1;
    cin >> m;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    //dis[i][j] = dis[i][k] + dis[k][j];
            }
    for(int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for(int i = 1; i <= m; i++)
        pre[i] = i-1, nxt[i] = i+1, cin >> val[i];
    int p = 1;
    while(p != m){
        int x1 = val[p], x2 = val[nxt[p]], x3 = val[nxt[nxt[p]]];
        int p1 = nxt[p];
        if(p1 == m) break;
        //cerr << p << " " << nxt[p] << " " << nxt[nxt[p]] << endl;
        while(dis[x1][x3] == dis[x1][x2] + dis[x2][x3]){
            pre[nxt[p1]] = pre[p1], nxt[pre[p1]] = nxt[p1];
            x2 = val[nxt[p]], x3 = val[nxt[nxt[p]]];
            p1 = nxt[p];
        }
        p = nxt[p];
    }
    int ans = 0;
    for(int i = 1; i <= m; i = nxt[i])
        ans++;
    cout << ans << endl;
    for(int i = 1; i <= m; i = nxt[i])
        cout << val[i] << " ";

    return 0;
}
