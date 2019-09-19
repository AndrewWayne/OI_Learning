/*
 * Author: xiaohei_AWM
 * Date: 9.14
 * Motto: Face to the weakness, expect for the strength.
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
const int MOD  = 1e9 + 7;
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
const int maxn = 2e5 + 10;
vector<pii> E[maxn];
ll frac[maxn], ans;
bool visit[maxn];
int n, m1, m2, x, y, Num;
ll circle_cnt[maxn], maxlcir;
ll maxl, chain_cnt[maxn];
ll num0chain[maxn], max0, num1chain[maxn], max1;
ll quickPower(ll a, ll b){
    ll ans = 1;//ans为答案，base为a^(2^n)
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a % MOD;
        a = (long long)a * a % MOD;
    }
    return ans % MOD;
}
void dfs(int x, int f, ll len, int ed){
    visit[x] = true;
    len++;
    bool notend = false;
    bool circle = false;
    for(auto i = E[x].begin(); i != E[x].end(); i++){
        if(visit[i->first]) continue;
        notend = true;
        dfs(i->first, f, len, i->second);
    }
    if(!notend){
        if(E[x].size() == 2) maxlcir = max(maxlcir, len), circle_cnt[len]++;
        else if(len & 1){
            //cerr << "$: " << x << endl;
            maxl = max(len-1, maxl);
            chain_cnt[len-1]++;
        }else{
            if(ed == 1){
                max1 = max(max1, len-1);
                num1chain[len-1]++;
            }else{
                max0 = max(max0, len-1);
                num0chain[len-1]++;
            }
        }
    }

}
int main(){
    Num = read();
    frac[0] = 1;
    for(int i = 1; i <= maxn-1; i++)
        frac[i] = (frac[i-1] * i) % MOD;
    n = read(), m1 = read(), m2 = read();
    for(int i = 1; i <= m1; i++){
        x = read(), y = read();
        E[x].push_back(make_pair(y, 1));
        E[y].push_back(make_pair(x, 1));
    }
    for(int i = 1; i <= m2; i++){
        x = read(), y = read();
        E[x].push_back(make_pair(y, 2));
        E[y].push_back(make_pair(x, 2));
    }
    for(int i = 1; i <= n; i++)
        if(!visit[i] && E[i].size() == 1)
            dfs(i, i, 0, 0);
    for(int i = 1; i <= n; i++)
        if(!visit[i])
            dfs(i, i, 0, 0);
    ans = frac[n];
    //cerr << ans << endl;
    ll key = 1;
    for(int i = 2; i <= maxlcir; i++){
        key *= (quickPower(i, circle_cnt[i]) * frac[circle_cnt[i]]) % MOD;
        //cerr << i << ": " << circle_cnt[i] << endl;
        key %= MOD;
    }
    //cerr << key << endl;
    for(int i = 0; i <= maxl; i += 2){
        key *= frac[chain_cnt[i]];
        //cerr << i << ": " << chain_cnt[i] << endl;
        key %= MOD;//偶数链
    }
    //cerr << key << endl;
    for(int i = 1; i <= max0; i += 2){
        key *= (quickPower(2, num0chain[i]) * frac[num0chain[i]]) % MOD;
        key %= MOD;//0开0结链
    }
    for(int i = 1; i <= max1; i += 2){
        key *= (quickPower(2, num1chain[i]) * frac[num1chain[i]]) % MOD;
        key  %= MOD;//1开1结链
    }
    //cerr << key << endl;
    ans -= key;
    ans %= MOD;
    while(ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}
