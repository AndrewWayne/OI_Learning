/*
 * Author: xiaohei_AWM
 * Date: 5.20
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
#define C(a) ((a)*((a)-1)/2)
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
const int maxn = 110;
const int MOD = 9999973;
int n, m;
ll f[maxn][maxn][maxn];//f[i][j][k]表示在第i行，有j列用掉了一个，k列用掉了两个的总方案数
inline void mod(ll &x){
    while(x >= MOD) x -= MOD;
}
int main(){
    n = read(), m = read();
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= m - j; k++){
                f[i][j][k] = f[i-1][j][k];//此行不取
                if(k >= 1)
                    f[i][j][k] += f[i-1][j+1][k-1] * (j+1);//此行放在一个棋子的列
                mod(f[i][j][k]);
                if(j >= 1)
                    f[i][j][k] += f[i-1][j-1][k] * (m-j-k+1);//此行在没棋子的列放一个
                mod(f[i][j][k]);
                if(k >= 2)
                    f[i][j][k] += f[i-1][j+2][k-2] * C(j+2, 2);//此行在一个棋子的列放两个
                mod(f[i][j][k]);
                if(k >= 1)
                    f[i][j][k] += f[i-1][j][k-1] * j * (m-j-k+1);//此行一个放在没棋子的列，一个放在一个棋子的列
                mod(f[i][j][k]);
                if(j >= 2)
                    f[i][j][k] += f[i-1][j-2][k] * C(m-j-k+2, 2);//此行两个放在没棋子的列
                mod(f[i][j][k]);
            }
        }
    }
    return 0;
}
