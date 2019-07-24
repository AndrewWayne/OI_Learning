/*
 * Author: xiaohei_AWM
 * Date: 6.26
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
const int maxn = 6e3 + 10;
int n, k, cnt, l, r;
ll a[maxn], b[maxn], sum[maxn], ans, result;
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    n = read(), k = read();
    for(int i = 1; i <= n; i++) a[i] = readll(), sum[i] = sum[i-1] + a[i];
    for(int i = 1; i <= k; i++) b[i] = readll();
    ans = -(0x7f7f7f7f7f7f7f7f);
    while(Time() < 0.9){
        l = 1, r = 1, cnt = 1, result = a[1] * b[1];
        for(int i = 2; i <= n; i++){
            if(cnt == k){
                result += b[k] * (sum[n] - sum[i-1]);
                break;
            }
            if(b[cnt] < b[cnt+1]){
                if((rand()%1000) > 100)
                result += b[++cnt]*a[i];
                else result += b[cnt]*a[i];
            }else{
                if((rand()%1000) > 100) result += b[cnt]*a[i];
                else result += b[++cnt]*a[i];
            }
        }
        ans = max(ans, result);

    }
    cout << ans << endl;
    return 0;
}
