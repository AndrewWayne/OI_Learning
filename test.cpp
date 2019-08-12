/*
 * Author: xiaohei_AWM
 * Date:
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
const int maxn = 1e7 + 10;
int v[maxn], pri[maxn], n, tot, m;
int sum[maxn], f[maxn];
void Euler_Sieve(){
    v[1] = 1;//v[i] 表示 i 的最小质因数
    f[1] = 1;
    for(int i = 2; tot <= 100; i++){
        if (!v[i]) pri[++tot] = i, v[i] = i;
        for (ll j = 1; j <= tot && i*pri[j] <= maxn; j++)
            v[i*pri[j]] = pri[j];
    }
}
int main(){
    Euler_Sieve();
    for(int i = 1; i <= 100; i++)
        sum[i] = sum[i-1] + pri[i];
    while(~scanf("%d%d", &n, &m)){
        int v = sum[n];
        if((v + m) & 1){
            printf("No\n");
            continue;
        }
        v = (v + m) >> 1;
        f[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = v; j >= pri[i]; j--)
                f[j] = max(f[j], f[j-pri[i]]);
        if(f[v]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
