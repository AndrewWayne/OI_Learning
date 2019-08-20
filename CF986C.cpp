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
const int maxn = 5e6 + 10;
int n, m;
int a[maxn], b[maxn], dad[maxn], ans, inv[maxn], inv1[maxn];
bool visited[maxn];
int find(unsigned int x){ return x == dad[x]? x: dad[x] = find(dad[x]); }
bool unionn(int u,int v){int fu = find(u), fv = find(v); if(fu == fv) return false; dad[fv] = fu; return true;}
int main(){

    n = read(), m = read();
    for(int i = 0; i < (1 << n); i++)
        dad[i] = i;
    for(int i = 1; i <= m; i++){
        a[i] = read();
        inv1[a[i]] = b[i];
        for(int j = 0; j < n; j++)
            b[i] += (1 << j) * (!((a[i] >> j) & 1));
        inv[b[i]] = a[i];
        cerr << "  " << b[i] << endl;
        visited[b[i]] = 1;
    }

    for(int i = (1 << n) - 1; i >= 0; i--){
        if(inv[i]){if(inv[i] > i) ans += (!visited[inv[i]]);}
        if(inv1[i]){if(inv1[i] > i) }
        if(!visited[i]) continue;
        cerr << i << endl;
        for(int j = n-1; j >= 0; j--){
            if((i >> j) & 1){
                int k = i ^ (1 << j);
                unionn(i, i ^ (1 << j));
                visited[i ^ (1 << j)] = 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
