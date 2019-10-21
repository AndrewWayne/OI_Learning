/*
 * Author: xiaohei_AWM
 * Date: 10.2
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
const int maxn = 52;
const int MOD = 1e9 + 7;
int n, p, c[maxn];
int f[maxn][maxn][maxn];// f[i][ob][ow]表示取了i个点，ob个奇方案数黑点，ow个奇方案数白点
ll power_two[maxn];
ll Mod(int x){
    while(x >= MOD) x -= MOD;
    return x;
}
int main(){
    n = read(), p = read();
    for(int i = 1; i <= n; i++) c[i] = read();
    power_two[0] = 1;
    for(int i = 1; i <= 50; i++) power_two[i] = ((ll)power_two[i-1] * 2)% MOD;
    if(c[1] == 1 || c[1] == -1) f[1][1][0] = 1;//一开始可以染一个黑点，只有一个点，一定是奇数点
    if(c[1] == 0 || c[1] == -1) f[1][0][1] = 1;//一开始可以染一个白点
    for(int i = 2; i <= n; i++){
        for(int ob = 0; ob <= i; ob++){
            for(int ow = 0; ow <= i; ow++){//枚举目标状态
                if(ob + ow > i) break;
                int e = i - ow - ob;//偶点数量
                if(ob > 0){//可以染奇黑点/偶白点
                    ll val = 0;
                    if(c[i] == 1 || c[i] == -1){
                        if(ow > 0) val = power_two[ow-1];
                        else val = 1;//必须有偶数个奇白连过去，当奇数白为零，就自力更生唯一
                        val = ((val * f[i-1][ob-1][ow]) % MOD * power_two[i -  ow - 1]) % MOD;
                    }
                    if(e > 0 && (c[i] == -1 || c[i] == 0))
                        val += (power_two[ob-1] * f[i-1][ob][ow]) % MOD * power_two[i - ob - 1] % MOD;
                    val %= MOD;
                    f[i][ob][ow] = (val + f[i][ob][ow]) % MOD;
                }
                if(ow > 0){//可以染偶黑/奇白
                    ll val = 0;
                    if(c[i] == 0 || c[i] == -1){
                        if(ob > 0) val = power_two[ob - 1];
                        else val = 1;
                        val = ((val * f[i-1][ob][ow-1]) % MOD * power_two[i - ob - 1]) % MOD;
                    }
                    if(e > 0 && (c[i] == 1 || c[i] == -1))
                        val += (power_two[ow-1] * f[i-1][ob][ow]) % MOD * power_two[i - ow - 1] % MOD;
                    val %= MOD;
                    f[i][ob][ow] = (val + f[i][ob][ow]) % MOD;
                }
            }
        }
    }

    int ans = 0;//统计答案
    for(int j = 0; j <= n; j++)
        for(int k = 0; k <= n; k++){
            if(j + k > n) break;
            if(((j+k) & 1) == p){
                ans = Mod(ans + f[n][j][k]);
            }
        }
    printf("%d\n", ans);
    return 0;
}
