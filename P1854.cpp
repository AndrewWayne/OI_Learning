/*
 * Author: xiaohei_AWM
 * Date: 7.12
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
const int maxn = 101;
int n, m, f[maxn][maxn], a[maxn][maxn], turn[maxn][maxn], dj;//f[i][j]表示放到第i束花放到第j个瓶子里的最大效益， a[i][j]表示第i束花放到第j个瓶里的最大效益。
void print(int i, int j){
    if(!i) return;
    print(i-1, turn[i][j]);
    printf("%d ", j);
}
int main(){
    n = read(), m = read();
    memset(f, -0x3f, sizeof(f));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = read();
    for(int i = 0; i <= n; i++)
        f[0][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= m; j++)
            for(int k = i-1; k < j; k++){
                if(f[i][j] < f[i-1][k] + a[i][j]){
                    f[i][j] = f[i-1][k]+a[i][j];
                    turn[i][j] = k;
                }
            }

    int ans = -0x7fffffff;

    for(int j = n; j <= m; j++){
        if(ans < f[n][j]){
            ans = f[n][j];
            dj = j;
        }
    }

    printf("%d\n", ans);
    print(n, dj);
    return 0;
}
