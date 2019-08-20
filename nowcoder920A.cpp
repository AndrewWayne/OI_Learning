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
const int maxn = 5e4 + 10;
int n, s, b[maxn];
pii a[maxn];
int ans1[maxn], ans2[maxn], ans3[maxn], top, pre, len;
int main(){
    n = read(), s = read();
    for(int i = 1; i <= n; i++) a[i].first = read(), a[i].second = i;
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; i++){
        b[i] = a[i].first - a[i-1].first;
        if(a[i].first == 0 && i != 1){
            printf("-1");
            return 0;
        }
        if(b[i] > s){
            printf("-1");
            return 0;
        }
    }
    for(int i = 2; i <= n; i++){
        if(b[i] != 0) ans1[++top] = a[i-1].second, ans2[top] = a[i].second, ans3[top] = b[i], pre = a[i-1].second, len = b[i];
        if(b[i] == 0)
            ans1[++top] = pre, ans2[top] = a[i].second, ans3[top] = len;
    }
    printf("%d\n", top);
    for(int i = 1; i <= top; i++)
        printf("%d %d %d\n", ans1[i], ans2[i], ans3[i]);
    return 0;
}
