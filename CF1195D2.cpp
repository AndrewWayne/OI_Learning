/*
 * Author: xiaohei_AWM
 * Date: 7.17
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
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
const int maxn = 1e5 + 10;
const int Mod = 998244353;
ll a[maxn][12], b[maxn][12], sum[12];
int main () {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        std::string str;
        std::cin >> str;
        int s = str.size();
        ++sum[s];
        for (int j = s - 1, w = 10; j >= 0; --j, w = w * 1ll * 10 % Mod) {
            for (int k = 1, p = (str[j] - '0') * 1ll * w % Mod; k <= 10; ++k) {
                a[i][k] = (a[i][k] + p) % Mod;
                if (j + k < s) {
                    p = (p * 1ll * 10) % Mod;
                }
            }
        }
        for (int j = 1; j <= 10; ++j) {
            b[i][j] += str[s - 1] - '0';
        }
        for (int j = s - 2, w = 10; j >= 0; --j, w = w * 1ll * 10 % Mod) {
            for (int k = 0, p = (str[j] - '0') * 1ll * w % Mod; k <= 10; ++k) {
                b[i][k] = (b[i][k] + p) % Mod;
                if (j + k < s - 1) {
                    p = (p * 1ll * 10) % Mod;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            ans = (ans + (a[i][j] + b[i][j]) % Mod * sum[j] % Mod) % Mod;
        }
    }
    cout << ans << endl;
    return 0;
}
