/*
 * Author: xiaohei_AWM
 * Date: 6.15
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
int n, m;
int a[maxn], b[maxn], at1, at2;
ll ans;
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= m; i++)
        b[i] = read();
    sort(a+1, a+1+n), sort(b+1, b+1+m);
    at1 = n, at2 = m;
    while(at1 >= 1){
        while(at2 >= 1 && b[at2] >= a[at1]) at2--;
        if(at2 > 0) ans += 2, at2--;
        else ans++;
        at1--;
    }
    cout << ans << endl;
    return 0;
}
