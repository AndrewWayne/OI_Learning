/*
 * Author: xiaohei_AWM
 * Date: 7.18
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
const int maxn = 1e3 + 10;
const int MOD = 1e9+7;
ll n, m, catl[maxn], c[maxn][maxn];
void Initial(){
    catl[0] = 1;
    catl[1] = 1;
    for(int i = 1; i <= 1000; i++)
        catl[i] = (catl[i-1] * (4*i - 2))%MOD / (i+1);
    for(int i = 0; i <= maxn; i++){
        c[0][i] = 0;
        c[i][0] = 1;
    }
    for(int i = 1; i < maxn; i++)
        for(int j = 1; j < maxn; j++)
        c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
}
int main(){
    Initial();
    while(cin >> n >> m){
        if(n < m) swap(n, m);
        cout << catl[n]*catl[m]*c[2*m*(2*n+1)][2*m] << endl;
    }
    return 0;
}
