/*
 * Author: xiaohei_AWM
 * Date:
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 3e5 + 10;
int n, m;
ll a[maxn], k, f[11], sum;
ll calc(ll l,ll r){
	if(l == r) return max(a[l] - k, 0ll);
	ll mid = (l+r) >> 1;
	ll fl = calc(l, mid), fr = calc(mid+1, r);
	ll ans = max(fl, fr);
	sum = 0;
	memset(f, 0, sizeof(f));
	for(ll i = mid; i >= l; --i){
		sum += a[i];
		f[(mid-i+1)%m] = max(f[(mid-i+1)%m], sum - k * ((mid-i+1)/m));
	}
	sum = 0;
	for(ll i = mid+1; i <= r; ++i){
		sum += a[i];
		for(ll j = 0; j < m; ++j)
			ans = max(ans, sum + f[j] - k * (int)ceil(double(i-mid+j)/m));
	}
	return max(ans, 0ll);
}
int main(){
    n = read(), m = read(), k = readll();
    for(int i = 1; i <= n; i++) a[i] = read();
    cout << calc(1, n) << endl;
    return 0;
}
