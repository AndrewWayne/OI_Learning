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
const int maxn = 3e2 + 10;
pii aa[maxn];
int n, sum, k, val, a[maxn], f[maxn]; // f[n]表示取n个政党可以达到的最大席位
int sol[maxn][maxn], top[maxn];// sol[n]表示取n个政党达到最大席位的一种方案，其中最后一个元素sol[n][top]是最小的(但是尽量大)，用于判断是否过剩。

int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        aa[i].first = a[i] = read(), sum += a[i],
        aa[i].second = i;
    sum >>= 1;
    sort(a+1, a+1+n, greater<int>());
    sort(aa+1, aa+1+n, greater<pii>());
    for(int i = 1; i <= n; i++){//表示取到第 i 个
        for(int j = i; j >= 1; j--){
            if(f[j-1] <= sum && f[j] < f[j-1] + a[i]){
                f[j] = f[j-1] + a[i];
                memcpy(sol[j], sol[j-1], sizeof(sol[j-1]));
                top[j] = top[j-1];
                sol[j][++top[j]] = aa[i].second;
            }
            if(f[j] > val)
                k = j, val = f[j];
        }
    }
    for(int i = 1; i <= n; i++)
        if(f[i] > val)
            k = i, val = f[i];
    printf("%d\n", k);
    for(int i = 1; i <= top[k]; i++)
        printf("%d ", sol[k][i]);

    return 0;
}
