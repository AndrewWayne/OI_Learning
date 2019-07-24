/*
 * Author: xiaohei_AWM
 * Date: 7.12
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
const int maxn = 2e6 + 10;
int n, a[maxn], sum[maxn], len[maxn], ans;
pii stack[maxn];
int top;
bool ks;
bool F(int len){
    for(int i = 0; i <= n - len; i++)
        if(sum[i+len] - sum[i] > 0) return true;
    return false;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read(), sum[i] = sum[i-1] + a[i];
        if(a[i] > 0) ks = true;
    }
    if(!ks){
        printf("0");
        return 0;
    }
    stack[++top].first = 0, stack[top].second = 0;
    for(int i = 1; i <= n; i++){
        int p = 0;
        if(stack[top].second >= sum[i])
            stack[++top].first = i, stack[top].second = sum[i];
        else{
            for(int k = 30; k >= 0; k--){
                if(p + (1<<k) <= top && stack[p+(1<<k)].second >= sum[i])
                    p += 1<<k;
            }
            p++;
            //cerr << p << endl;
            ans = max(ans , i - stack[p].first);
            //cerr << stack[p].first << " " << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
6
0 0 -7 -6 1 2
8
-1 -2 4 -1 -2 -4 -5 9

*/
