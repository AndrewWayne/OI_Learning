/*
 * Author: xiaohei_AWM
 * Date: 7.8
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
int t, n, v[maxn], c[maxn], l, r, a[maxn], ans;
inline int lowbit(int x){ return x & -x;}
void add(int pos,int num){
    for(int i = pos; i <= n; i += lowbit(i))
        c[i] += num;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
int main(){
    t = read();
    while(t--){
        memset(v, 0, sizeof(v));
        memset(c, 0, sizeof(c));
        memset(a, 0, sizeof(a));
        r = l = 1;
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(r = 1; r <= n; r++){
            if(!v[a[r]]) v[a[r]] = 1, add(a[r], 1);
            else{
                while(v[a[r]]){//r前面那个元素才是最后一个元素
                    if(query(r-l) == r-l) ans = max(ans, r-l);
                    v[a[l]] = 0;
                    add(a[l++], -1);
                }
                v[a[r]] = 1, add(a[r], 1);
            }
        }
        r = n;
        while(l <= r){
            if(query(r-l+1) == r-l+1){ ans = max(ans, r-l+1); break;}
            v[a[l]] = 0;
            add(a[l++], -1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
