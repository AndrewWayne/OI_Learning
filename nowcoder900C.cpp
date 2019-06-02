/*
 * Author: xiaohei_AWM
 * Date: 5.24
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
const int maxn = 5e5 + 10;
const int MOD = 1e9 + 7;
ll n, l, ans1, ans2, d[maxn], f[maxn][3];
long long solve(int n,int m){
    if( n < m){
        f[n][m] = 2*(n-1) + 1;
        return f[n][m];
    }
    else if( m <= 3){
        f[n][m] = d[n];
        return f[n][m];
    }
    else
        for(int i = 0; i <= n; i++)
            f[n][m] = min(solve(n-i, m-1) + 2*f[i][m], f[n][m]);
    return f[n][m];
}
int main(){
    n = read(), l = read();
    ans1 = n/10;
    ans1 *= 3;
    int temp = n % 10;
    if(temp >= 1)
        ans1++;
    if(temp >= 5)
        ans1++;
    if(temp >= 8)
        ans1++;
    cout << ans1 << endl;
    for(int i = 1; i <= 3; i++)
        f[0][i] = 0;
    for(int i = 1; i <= 2*ans1; i++)
        d[i] = (2*d[i-1] + 1)%MOD;
    ans2 = solve(2*ans1, 3);
    cout << ans2 << endl;
    return 0;
}
