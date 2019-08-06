// luogu-judger-enable-o2
/*
 * Author: xiaohei_AWM
 * Date: 8.2
 * Mutto:
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
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
int n, p[maxn], l[maxn], r[maxn];
ll a[maxn], f[maxn], s[maxn], minn[maxn];
vector<int> son[maxn];
vector<int> progeny[maxn];
stack<pii> Sta;
void dfs(int x){
    f[x] = s[x] = a[x];
    for(auto i = son[x].begin(); i != son[x].end(); i++)
        dfs(*i);
    for(auto i = progeny[x].begin(); i != progeny[x].end(); i++)
        s[*i] = min(s[*i], a[x]), f[x] += s[*i], progeny[p[x]].push_back(*i);
    return;
}
void dfs2(int x){

}
void dfs3(int x){
    for(auto i = son[x].begin();i != son[x].end(); i++)
        dfs3(*i);
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), p[i] = read(), son[p[i]].push_back(i), progeny[p[i]].push_back(i);
    if(n <= 1000)
        dfs(1);
    else if(链){
        for(int i = 1; i <= n; i++){
            while(!Sta.empty() && Sta.top().second > a[i]){
                r[Sta.top().first] = i-1;
                Sta.pop();
            }
            if(Sta.empty()) l[i] = 1, Sta.push(make_pair(i, a[i]));
            else l[i] = Sta.top().first + 1, Sta.push(make_pair(i, a[i]));
        }
        while(!Sta.empty()) r[Sta.top().first] = n, Sta.pop();
        for(int i = 1; i <= n; i++){
            f[l[i]] += a[i] * (r[i] - i + 1);
            f[i+1] -= a[i] * (r[i] - i + 1);
        }
        for(int i = 1; i <= n; i++){
            f[i] += f[i-1];
            //printf("%lld\n", f[i]);
        }
        //return 0;
    }else{
        dfs2(1);
        dfs3(1);
    }
    for(int i = 1; i <= n; i++)
        printf("%lld\n", f[i]);
    return 0;
}
