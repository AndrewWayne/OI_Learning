/*
 * Author: xiaohei_AWM
 * Date: 6.7
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
const int maxn = 1e2 + 10;
int n, x[maxn], ans;
int f[maxn];
bool indg[maxn], visited[maxn];
struct Sege{
    int l, r;
} sege[maxn];
int main(){
    n = read();
    for(int i = 1; i <= n; i++) x[i] = read();
    sort(x+1, x+1+n);
    f[1] = 2;
    indg[2] = true;
    for(int i = 2; i <= n; i++){
        if(x[i] - x[i-1] <= x[i+1] - x[i])
            indg[i-1] = true, f[i] = i-1;
        else f[i] = i+1, indg[i+1] = true;
    }
    f[n] = n-1;
    indg[n-1] = true;
    for(int i = 1; i <= n; i++){
        if(!indg[i]){
            visited[i] = true;
            ans++;
            for(int j = f[i]; !visited[j]; j = f[j])
                visited[j] = true;
        }
    }
    int ans2 = 0;
    for(int i = 1; i <= n; i++)
        if(!visited[i]) ans2++;
    cout << ans + ans2/2 << endl;
    return 0;
}
/*

*/
