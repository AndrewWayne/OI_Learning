/*
 * Author: xiaohei_AWM
 * Date: 10.13
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
bool visited[1000010];
int t, n;
int val[40];
int main(){
    val[1] = 0;
    for(int i = 2; i <= 40; i++){
        val[i]++;
        for(int j = 2; j <= 40 && i * j <= 40; j++){
            val[i * j]++;
        }
        //cerr << i << ": " << val[i] << endl;
    }
    t = read();
    while(t--){
        memset(visited, 0, sizeof(visited));
        n = read();
        int sn = sqrt(n);
        int more = 0;
        db ans = 0.0;
        ans = 1.0;
        //int k = floor(log10(n)/log(k));
        for(int i = 2; i <= sn; i++){
            if(visited[i]) continue;
            ll res = i;
            //cerr << i << ": ";
            for(int j = 1; res <= n; j++, res = res*i){
                if(res > sn) more++;
                if(res <= sn) visited[res] = true;
                ans = ans + 1.0 / (db)(1.0 + val[j]);
                //cerr << res << " ";
                //cerr << "$: " << val[j] << endl;
            }
            //cerr << endl;
        }
        ans = ans + n - sn - more;
        printf("%.6f\n", ans);
    }
    return 0;
}
