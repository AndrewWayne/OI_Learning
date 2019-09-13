/*
 * Author: xiaohei_AWM
 * Date: 9.7
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
const int MOD = 1e8;
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
int n1, n2, k1, k2, ans, f[110][110][20][20];//f[p][i][s1][k] 表示摆到第 i 个，已经放了 s1 个骑兵，当前前面连续摆了k个（骑兵-1/步兵-0）
//f[1][i][s1][k] = f[1][i-1][s1-1][k-1] , 对于k = 1，特判：f[1][i][s1][1] = sum(f[0][i-1][s1-1][0~k1]) 其中枚举s1的范围是max(0, i-n1)~min(i, n1), k的枚举范围可以从max(0, i-n1) ~ k1或k2
void Mod(int &x){
    while(x >= MOD) x -= MOD;
    if(x < 0) x += MOD;
    return;
}
int main(){
    n1 = read(), n2 = read(), k1 = read(), k2 = read();
    f[1][0][1][0] = f[0][1][0][1] = 1;
    for(int i = 0; i <= n1; i++)
        for(int j = 0; j <= n2; j++)
            for(int k = 0; k <= min(i, k1); k++)
                for(int l = 0; l <= min(j, k2); l++){
                    if((!k && !l) || (k && l)) continue;
                    if(k){
                        f[i+1][j][k+1][l] += f[i][j][k][l];
                        Mod(f[i+1][j][k+1][l]);
                        f[i][j+1][0][1] += f[i][j][k][l];
                        Mod(f[i][j+1][0][1]);
                    }else{
                        f[i][j+1][k][l+1] += f[i][j][k][l];
                        Mod(f[i][j+1][k][l+1]);
                        f[i+1][j][1][0] += f[i][j][k][l];
                        Mod(f[i+1][j][1][0]);
                    }
                }
    for(int i = 0; i <= min(n1, k1); i++)
        for(int j = 0; j <= min(n2, k2); j++){
            if((!i && !j) || (i && j)) continue;
            ans += f[n1][n2][i][j];
            Mod(ans);
        }
    cout << ans << endl;
    return 0;
}
