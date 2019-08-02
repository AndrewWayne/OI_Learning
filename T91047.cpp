// luogu-judger-enable-o2
/*
 * Author: xiaohei_AWM
 * Date: 8.2
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
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
const int MAXN = 2e6 + 10;
ll t[MAXN],p[MAXN];
int main(){
	ll n = readll(), m=readll();
	for(ll i = 1; i <= n; ++i){
		ll x = read();
		t[i] = x-i;
	}
	for(ll i = n-1; i; --i)
        if(cnt<t[p[i]]&&p[i]>=i+cnt)++cnt;
	for(ll i = 1; i <= m; ++i) p[i] = read();
	sort(p+1, p+m+1);
	ll cnt = 0, res = 0;
	for(ll i = 1; i <= m; ++i){
		if(p[i] > n+m) break;
		if(cnt < t[p[i]]) ++cnt;
	}
	for(ll i = 1; i <= m; ++i){
		if(p[i] <= n+cnt) continue;
		if(res < (p[i] - n - cnt)) ++res;
	}
	printf("%lld", cnt+res);
	return 0;
}
