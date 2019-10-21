/*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 110;
int f[maxn][maxn], n, m, sol[maxn][maxn], x, y;
int main(){
    n = read(), m = read();
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= m; i++){
        x = read(), y = read();
        f[y][x] = f[x][y] = 1;
        sol[y][x] = sol[x][y] = 1;
    }
    for(int i = 1; i <= n; i++)
        f[i][i] = 0;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j && j != k &&  i != k){
                    if(f[i][k] + f[k][j] < f[i][j]){
                        sol[i][j] = sol[i][k] * sol[k][j];
                        f[i][j] = f[i][k] + f[k][j];
                    }else if(f[i][k] + f[k][j] == f[i][j]){
                        sol[i][j] += sol[i][k] * sol[k][j];
                    }
                }
            }
        }
    }
    int maxv = 0;
    for(int i = 2; i < n; i++)
        if(f[1][i] + f[i][n] == f[1][n])
            maxv = max(sol[1][i] * sol[i][n], maxv);
    db ans = 2.0*(db)maxv/sol[1][n];
    ans = max(ans, 1.0);
    printf("%.8f\n", ans);
    return 0;
}
