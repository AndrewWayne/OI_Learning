/*
 * Author: xiaohei_AWM
 * Date: 6.2
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
const int maxn = 510;
int n, m, a[maxn], b[maxn], f[maxn][maxn];//f[i][j] 表示A1 - Ai, B1 - Bj构成的以Bj结尾的LCIS长度。
int sol[maxn][maxn];//记录f[i][j]的方案
int ans, solution, details[maxn], top;
int main(){
    n = read();
    a[0] = -1;
    b[0] = -1;
    for(int i = 1; i <= n; i++)
        a[i] = read();
    m = read();
    for(int i = 1; i <= m; i++)
        b[i] = read();
    for(int i = 1; i <= n; i++){
        int val = 0;
        int turn = 0;
        if(b[0] < a[i]) val = f[i-1][0], turn = 0;
        for(int j = 1; j <= m; j++){
            if(a[i] != b[j]){
                f[i][j] = f[i-1][j];
                sol[i][j] = sol[i-1][j];
            }else{
                f[i][j] = val + 1;
                sol[i][j] = turn;
            }
            if(b[j] < a[i]){
                if(val < f[i-1][j])
                    val = f[i-1][j], turn = j;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(ans < f[n][i]){
            ans = f[n][i],
            solution = i;
        }
    }
    printf("%d\n", ans);
    int at = n;
    for(int i = solution; i; i = sol[at--][i]) details[++top] = b[i];
    for(int i = top; i >= 1; i--)
        printf("%d ", details[i]);
    return 0;
}
