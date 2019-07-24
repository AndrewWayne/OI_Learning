/*
 * Author: xiaohei_AWM
 * Date: 7.14
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<map>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef __int128 ll;
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
int a[maxn], b[maxn], co[maxn], n, cnt = 0;
ll ans = 0, c[maxn], l[maxn], r[maxn];
map<int,int> F;
inline int lowbit(int x){
    return x & -x;
}
inline void add(int pos,ll num){
    for(int i = pos; i <= n; i += lowbit(i))
        c[i] += num;
}
inline ll query(int x){
    ll res = 0;
    for(int i = x; i; i -= lowbit(i))
        res += c[i];
    return res;
}
void print(ll x){
    int st[100], top = 0;
    if(x == 0){
        printf("0\n");
        return;
    }
    while(x){
        st[++top] = x%10;
        x /= 10;
    }
    while(top) printf("%d", st[top--]);
    printf("\n");
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++) b[i] = a[i] = read();
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++)
        if(i == 1 || a[i] != a[i-1])
            co[++cnt] = a[i];
    for(int i = 1; i <= n; i++)
        b[i] = lower_bound(co+1, co+1+cnt, b[i]) - co;
    for(int i = 1; i <= n; i++)
        l[i] = i, r[i] = n-i+1;

    for(int i = n; i >= 1; i--){
        add(b[i], r[i]);
        ans += query(b[i]-1) * l[i];
    }
    print(ans);
    return 0;
}
