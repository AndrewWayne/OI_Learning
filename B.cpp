/*
 * Author: xiaohei_AWM
 * Date: 8.31
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<map>
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
const ll MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
ll a, b, c, d;
vector<int> V;
bool find(ll l, ll r, ll pl, ll pr) {
    if(!(l <= pl && pr <= r) || pl > pr) return false;
    if(l == pl && r == pr) return true;
    ll mid = (l + r) >> 1;
    if((l+r) & 1) return 0;
    if(!((pl <= mid && pr <= mid) || (pl >= mid && pr >= mid)))
        return 0;
    if(pl >= mid) V.push_back(1);
    else V.push_back(0);
    bool found = false;
    if(pl >= mid && pr >= mid) found = find(mid, r, pl, pr);
    else found = find(l, mid, pl, pr);
    return found;
}
int main() {
    int t;
    t = read();
    while(t--){
        a = readll(), b = readll(), c = readll(), d = readll();
        int Op = 0;
        V.clear();
        swap(c, a); swap(d, b);
        if(a > b) swap(a, b), swap(c, d), Op = 1;
        bool flag = find(a, b, c, d);
        if(!flag) printf("No\n");
        else{
            printf("Yes\n");
            reverse(V.begin(), V.end());
            for(int i = 0; i < V.size(); i++){
                if(Op == 0){
                    if(V[i] == 1)
                        printf("B");
                    else
                        printf("A");
                }else{
                    if(V[i] == 0)
                        printf("B");
                    else
                        printf("A");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
