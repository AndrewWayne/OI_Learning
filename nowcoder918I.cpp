/*
 * Author: xiaohei_AWM
 * Date: 6.7
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
const int maxn = 1e5 + 10;
int n, m, c, t[maxn], maxt, ans;
bool check(ll x){
    int times = t[1], car = 1, cow = 0;
    for(int i = 1; i <= n; i++){
        if(++cow > c){ car++, times = t[i], cow = 1;}
        if(t[i] - times > x)
            car++, times = t[i], cow = 1;
    }
    return car > m;
}
int main(){
    n = read(), m = read(), c = read();
    for(int i = 1; i <= n; i++) t[i] = read();
    sort(t+1, t+1+n), maxt = t[n] - t[1];
    for(int k = 32; k >= 0; k--){
        ll anss = (ll)ans + (1ll << k);
        if(anss <= maxt && check(anss) ){
            ans = anss;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
