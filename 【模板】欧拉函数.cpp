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
const int maxn = 1e6 + 10;
int v[maxn], low[maxn], f[maxn], pri[maxn], n, tot;
void Euler_Sieve(){
    v[1] = low[1] = 1;//v[i] 表示 i 的最小质因数
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        if (!v[i]) low[i] = pri[++tot] = i, v[i] = i, f[i] = i-1;
        for (ll j = 1; j <= tot && i*pri[j] <= n; j++){
            v[i*pri[j]] = pri[j];
            if(i%pri[j] == 0){
                low[i*pri[j]] = low[i] * pri[j];
                if(low[i] == i)
			f[i*pri[j]] = f[i] * pri[j];
                else
                    f[i*pri[j]] = f[i/low[i]] * f[low[i]*pri[j]];
                break;
            }
            low[i*pri[j]] = pri[j];
            f[i*pri[j]] = f[i] * f[pri[j]];
        }
    }
}
int main(){
    n = read();
    Euler_Sieve();
    for(int i = 1; i <= n; i++)
        cout << f[i] << endl;
    return 0;
}
