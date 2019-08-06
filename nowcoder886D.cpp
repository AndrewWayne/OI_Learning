#pragma GCC optimize("Ofast")
/*
 * Author: xiaohei_AWM
 * Date: 8.3
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<set>
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
int n,R,a[2003],l,r,mid,ans, Ts;
multiset<int> s;//这个真的是暑假网上学到的最实用的stl技巧之一了……
inline bool check(int w)
{
    s.clear();
    for(reg int i=1;i<=n;i++)
        s.insert(a[i]);
    for (reg int j = 1; j <= R; j++){
        int rem = w;
        while(!s.empty()){
            multiset<int>::iterator x = s.upper_bound(rem);
            if (x == s.begin()) break;
            x--; rem -= *x; s.erase(x);
        }
        if (s.empty()) return true;
    }
    return false;
}
int main(){
    Ts = read();
    for(reg int kkk = 1; kkk <= Ts; kkk++){
        l = r = mid = 0;
        ans = 0;
        n = read(), R = read();
        for(reg int i = 1; i <= n; i++)
            a[i] = read(), r += a[i], l = max(l,a[i]);
        sort(a+1,a+1+n);
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid)) r=mid; else l=mid+1;
        }
        for(ans = l-500; ans <= l && !check(ans); ans++);
        printf("Case #%d: %d\n", kkk, ans);
    }
    return 0;
}
