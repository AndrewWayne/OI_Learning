/*
 * Author: xiaohei_AWM
 * Date: 5.25
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
pii query[maxn];
int l, n, l_limit, r_limit, ans;
bool cmp(pii x, pii y){
    if(x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
int main(){
    freopen("3.in", "r", stdin);
    l = read(), n = read();
    for(int i = 1; i <= n; i++)
        query[i].first = read(),
        query[i].second = read();
    sort(query+1, query+1+n, cmp);
    ans = l;
    l_limit = 0;
    r_limit = 0;
    for(int i = 1; i <= n; i++){
        if(l_limit == 0) l_limit = query[i].first, r_limit = query[i].second;
        else{
            if(query[i].first <= r_limit)
                r_limit = max(query[i].second, r_limit);
            else{
                ans -= r_limit - l_limit + 1;
                l_limit = query[i].first, r_limit = query[i].second;
            }
        }
    }
    ans -= r_limit - l_limit + 1;
    cout << ans << endl;
    return 0;
}
