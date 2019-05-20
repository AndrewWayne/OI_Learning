/*
 * Author: xiaohei_AWM
 * Date: 5.19
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
const int maxn = 13;
const int MOD  = 1e8;
int n, m, a, field[maxn], f[maxn][1 << maxn], stat[1 << maxn], cnt, ans;
void Init(){
    for(int i = 0; i < (1 << m); i++)
        if(!((i << 1) & i))
            stat[++cnt] = i;
}
int main(){
    n = read(), m = read();
    Init();
    //for(int i = 1; i <= cnt; i++)
    //    printf("stat[%d]: %d\n", i, stat[i]);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            a = read();
            field[i] |= (!a) << j;
        }
        //cerr << field[i] << endl;
    }

    for(int j = 1; j <= cnt; j++)
        if(!(stat[j] & field[1]))
            f[1][j] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= cnt; j++){
            if(field[i-1] & stat[j]) continue;
            for(int k = 1; k <= cnt; k++){
                if(field[i] & stat[k] || stat[j] & stat[k]) continue;
                f[i][k] += f[i-1][j];
                f[i][k] %= MOD;
            }
        }
    for(int i = 1; i <= cnt; i++){
        ans += f[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
