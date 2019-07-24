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
#include<map>
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
const int maxn = 1e5+10;
struct Girl{
    int a, b;
    bool operator<(const Girl &y)const{
        return !(a > y.a && b > y.b);
    }
    bool operator>(const Girl &y)const{
        return a > y.a && b > y.b;
    }
} g[maxn];
int n;
int f[maxn], cnt = 0, res = 0;
Girl Vec[maxn];
map<pii, int> Func;
int LIS(int start, int endss, bool mode){//1 -- LIS, 0 -- LDS
    memset(f, 0, sizeof(f));
    f[start] = 1;
    Vec[++cnt] = g[start];
    for(int i = start+1; i <= endss; i++){
        int pos = 0;
        for(int k = 20; k >= 0; k--){
            if(mode){
                if(pos + (1<<k) <= cnt && Vec[pos + (1<<k)] < g[i])
                    pos += 1 << k;
            }else{
                if(pos + (1<<k) <= cnt && Vec[pos + (1<<k)] > g[i])
                    pos += 1 << k;
            }
        }
        f[i] = pos + 1;
        res = max(f[i], res);
        if(f[i] > cnt) Vec[++cnt] = g[i];
        else{
            if(mode){if(Vec[f[i]] > g[i]) Vec[f[i]] = g[i];}
            else{if(Vec[f[i]] < g[i]) Vec[f[i]] = g[i];}
        }
    }
    return res;
}
bool cmp(Girl x, Girl y){
    return (x.a > y.a && x.b > y.b);
}
int ans[maxn];
int main(){
    n = read();
    pii temp;
    for(int i = 1; i <= n; i++){
        g[i].a = read(), g[i].b = read();
        temp.first = g[i].a, temp.second = g[i].b;
        Func[temp] = i;
    }
    sort(g+1, g+1+n, cmp);
    LIS(1, n, 0);
    for(int i = 1; i <= n; i++){
        temp.first = g[i].a, temp.second = g[i].b;
        ans[Func[temp]] = f[i];
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);

    return 0;
}
