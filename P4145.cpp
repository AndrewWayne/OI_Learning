/*
 * Author: xiaohei_AWM
 * Date: 7.25
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
const int maxn = 1e5 + 10;
int n, m, k, l, r;//nxt[i]表示a[i]之后第一个不是1的数的位置
ll a[maxn], nxt[maxn], c[maxn];
inline int lowbit(int x){return x&(-x);}
void add(int pos, ll x){
    for(int i = pos; i <= n; i += lowbit(i))
        c[i] += x;
}
ll query(int pos){
    ll res = 0;
    for(int i = pos; i; i -= lowbit(i))
        res += c[i];
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]),
        add(i, a[i]);
    for(int i = n; i >= 1;i--){
        if(a[i+1] != 1) nxt[i] = i+1;
        else nxt[i] = nxt[i+1];
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &k, &l, &r);
        if(l > r) swap(l, r);
        if(k == 0){
            for(int j = l; j <= r; j = nxt[j]){
                if(a[j] != 1){
                    ll delta = 0;
                    delta = a[j] - floor(sqrt(a[j]));
                    a[j] -= delta;
                    add(j, -delta);
                }
                if(a[nxt[j]] == 1) nxt[j-1] = nxt[nxt[j]];
            }
        }else
            printf("%lld\n", query(r) - query(l-1));
        cerr << "$" << endl;
        for(int j = 1; j <= n; j++)
            cerr << a[j] << " ";
        cerr << endl;
        for(int j = 1; j <= n; j++)
            cerr << nxt[j] << " ";
        cerr << endl;
    }
    return 0;
}
