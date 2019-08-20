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
const int maxn = 1e3 + 10;
struct Sege{
    int l, r;
} s1[maxn], s2[maxn];
int t, n, top;
int main(){
    t = read();
    while(t--){
        int ans = 0;
        n = read();
        for(int i = 1; i <= n; i++)
            s1[i].l = read(), s1[i].r = read();
        int i = 1;
        int l = s1[i].l, r = s1[i].r;
        int p = 0;
        for(i = 1; i <= n; i++){
            if(s1[i].r < l || s1[i].l > r){
                s2[++top].l = l, s2[top].r = r;
                l = s1[i].l, r = s1[i].r;
            }
            if(l <= s1[i].l && s1[i].l <= r)
                l = s1[i].l;
            if(r >= s1[i].r && s1[i].r >= l)
                r = s1[i].r;
        }
        s2[++top].l = l, s2[top].r = r;
        if(min(abs(s2[1].l - s2[2].l), abs(s2[1].l - s2[2].r)) < min(abs(s2[1].r - s2[2].l), abs(s2[1].r - s2[2].r)))
            p = s2[1].l;
        else
            p = s2[1].r;
        for(int i = 2; i <= top; i++){
            int x = abs(s2[i].l - p), y = abs(s2[i].r - p);
            if(x < y){
                ans += x/2 + (x&1);
                if(s2[i].l != s2[i].r && (x & 1)){
                    if(s2[i+1].l > s2[i].l) p = s2[i].l + 1;
                    else p = s2[i].l;
                }else p = s2[i].l;
            }else{
                ans += y/2 + (y&1);
                if(s2[i].l != s2[i].r && (y&1)){
                    if(s2[i+1].r < s2[i].r) p = s2[i].r - 1;
                    else p = s2[i].r;
                }else p = s2[i].r;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
6
27 28
10 18
17 27
7 18
14 18
2 19
*/
