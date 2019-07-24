/*
 * Author: xiaohei_AWM
 * Date: 7.12
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
int n, m, h[maxn], a[maxn], arrays[2*maxn], cnt, b[2*maxn], d[maxn], top;
int query(int x){
    return lower_bound(b+1, b+1+top, x) - b;
}
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        h[i] = read(), arrays[++cnt] = h[i];
    for(int i = 1; i <= m; i++)
        a[i] = read(), arrays[++cnt] = a[i];
    sort(arrays+1, arrays+1+cnt);
    for(int i = 1; i <= cnt; i++)
        if(i == 1 || arrays[i] != arrays[i-1])
            b[++top] = arrays[i];
    for(int i = 1; i <= n; i++)
        h[i] = query(h[i]);
    for(int i = 1; i <= m; i++){
        a[i] = query(a[i]);
        d[i] = a[i] - a[i-1];
    }
    for(int i = 1; i <= m; i++){
        int ans = 0;
        bool big = false;
        for(int j = 1; j <= n; j++){
            h[j] -= d[i];
            if((!big) && h[j] > 0) ans++, big = true;
            if(h[j] <= 0) big = false;
        }
        printf("%d\n", ans);
    }

    return 0;
}
