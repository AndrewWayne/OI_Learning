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
const int maxn = 110;
int n, m, h, w[maxn], v[maxn], f[2*maxn], ans, maxv, maxi;
int main(){
    while((n = read())){
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        m = read(), h = read();
        maxv = 0, ans = 0;
        for(int i = 1; i <= n; i++){
            w[i] = read(), v[i] = read();
            if(maxv <= v[i]) maxv = v[i], maxi = i;
        }
        m += h;
        m --;
        for(int maxi = 1; maxi <= n; maxi++){
            memset(f, 0, sizeof(f));
            for(int i = 1; i <= n; i++){
                if(i == maxi) continue;
                for(int j = m; j >= w[i]; j--)
                    f[j] = max(f[j], f[j-w[i]] + v[i]);
                ans = max(ans, f[m] + v[maxi]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
