/*
 * Author: xiaohei_AWM
 * Date: 7.27
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
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
const int maxn = 1e5 + 10;
string k;
ll n, sum[maxn], a[maxn], cnt[3], num[maxn];
ll ans;
int main(){
    cin >> k;
    n = k.size();
    for(int i = 0; i< n; i++){
        a[i+1] = k[i] - '0';
        sum[i+1] = sum[i] + a[i+1];
    }
    cnt[0] = 1;
    ll l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0 && (i - 1 <= 0 || a[i-1] != 0 ))
            l = i;
        if(a[i] == 0 && (a[i+1] != 0 || i+1 > n)){
            r = i;
            ans += num[l-1]*(r-l);
            ans += (r-l+1)*(r-l+2)/2;
        }
        num[i] = cnt[sum[i]%3];
        cnt[sum[i]%3]++;
    }
    cout << ans << endl;
    return 0;
}
