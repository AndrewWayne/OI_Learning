/*
 * Author: xiaohei_AWM
 * Date:4.30
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
const int maxn = 110, maxm = 20;
int n, m, mp[maxn], ans, f[maxn][1000][1000], stat[1000], cnt;//f[i][j][k]表示第i行，本行取状态为j上一行取状态为k
char opt;
void Init(int x){
    for(int i = 0; i < (1<<x); i++){
        if(i & (i<<1) || i & (i<<2))
            continue;
        stat[++cnt] = i;
    }
}
int main(){
    cin >> n >> m;
    Init(m);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cin >> opt;
            if(opt == 'H') mp[i] += 1 << j;
            if(opt == 'P') mp[i] += 0;
        }
    }
    for(int i = 1; i <= n; i++){//阶段
        int temp = 0;
        if(i == 1){
            for(int j = 1; j <= cnt; j++)
                for(int x = 1; x <= cnt; x++){
                    if(stat[x] & mp[i] || stat[j] & stat[x]) continue;
                    f[i][x][j] = __builtin_popcount(stat[x]);
                    ans = max(ans, f[i][x][j]);
                }
            continue;
        }
        for(int j = 1; j <= cnt; j++){
            if(stat[j] & mp[i-1]) continue;
            for(int k = 1; k <= cnt; k++){//f[i-1][j][k]
                if(stat[k] & mp[i-2] || stat[j] & stat[k]) continue;//受转移状态自相矛盾
                for(int x = 1; x <= cnt; x++){//f[i][x][j]为目标状态
                    if(stat[x] & mp[i] || stat[x] & stat[k] || stat[x] & stat[j])//本行决策与上两行矛盾或与地图矛盾
                        continue;
                    f[i][x][j] = max(f[i][x][j], __builtin_popcount(stat[x]) + f[i-1][j][k]);
                    ans = max(ans, f[i][x][j]);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
