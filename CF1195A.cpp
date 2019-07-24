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
int n, k, a[1010], t, cnt[1010], ans;
int main(){
    n = read(), k = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), cnt[a[i]]++;
    if(n & 1) t = (n+1)/2;
    else t = n/2;
    for(int i = 1; i <= k && t > 0; i++){
        int temp = cnt[i]/2;
        if(temp <= t){
            t -= temp;
            ans += 2*temp;
            cnt[i] -= 2*temp;
        }else{
            t = 0;
            ans += 2*t;
            cnt[i] -= 2*t;
        }
    }
    if(t > 0) ans += t;
    cout << ans << endl;
    return 0;
}
