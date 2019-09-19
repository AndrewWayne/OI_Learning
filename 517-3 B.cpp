/*
 * Author: xiaohei_AWM
 * Date: 9.15
 * Motto: Face to the weakness, expect for the strength.
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
const int MAX_N = 1e4 + 10;
ll m[MAX_N], s[MAX_N], p[MAX_N], x[MAX_N];
int r, b, c;
bool F(ll y){
	ll sum = 0;
	for(int i = 1; i <= c; i++)
		x[i] = max(min((y-p[i]) / s[i], m[i]), (ll)0);
	sort(x+1, x+c+1);
	for(int i = c; i >= 1; i--){
        sum += x[i];
		if(sum >= b){
			if(c-i+1 <= r) return true;
			else return false;
		}
	}
	return false;
}
ll Binary_Search(ll l, ll r){
    ll i;
    while(r - l >= 5){
        ll mid = (l + r) >> 1;
        if(F(mid)) r = mid;
        else l = mid;
    }
    for(i = l; i <= r; i++)
        if(F(i)) break;
    return i;
}
int main(){
	int t = read();
	for(int kkk = 1; kkk <= t; kkk++){
		r = read(), b = read(), c = read();
		for(int i = 1; i <= c; ++i)
			m[i] = read(), s[i] = read(), p[i] = read();
        printf("Case #%d: %lld\n", kkk, Binary_Search(0, llINF - 10));
	}
	return 0;
}
