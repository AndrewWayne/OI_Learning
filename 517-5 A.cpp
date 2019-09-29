/*
 * Author: xiaohei_AWM
 * Date: 9.20
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
const int maxn = 1e5 + 10;
int t, n, m, a[maxn], v[maxn], b[maxn], p[maxn], s, sum;
//db v[maxn];
int main(){
    t = read();
    for(int kkk = 1; kkk <= t; kkk++){
        //memset(a, 0, sizeof(a));
        //memset(v, 0, sizeof(v));
        sum = 0, s = 0;
        n = read(), m = read();
        int k = 100/n;
        //cerr << k << endl;
        for(int i = 1; i <= n; i++) b[i] = (1000*i/n) % 10;//预处理出哪些数可以进位
        //for(int i = 1; i <= n; i++)
        //    cerr << b[i] << " ";
        //cerr << endl;
        for(int i = n; i >= 0; i--){
            if(b[i] >= 5) p[i] = 0;
            else p[i] = p[i+1] + 1;//预处理出需要多少份问卷才能进一位
        }
        //for(int i = 0; i <= n; i++)
        //    cerr << p[i] << " ";
        //cerr << endl;
        for(int i = 1; i <= m; i++){
            a[i] = read(), sum += a[i];
            v[i] = p[a[i]], s += a[i] * 100/n;
        }
        //db k = 100.0 / n;
        //int k1 = 100 / n;
        //for(int i = 1; i <= m; i++){
        //    v[i] = k * a[i], s += a[i] * 100 / n,
        //    v[i] = v[i] - (int)(a[i] * 100 / n);
        //}
        //    cerr << v[i] << " ";
        //cerr << endl;
        sort(v+1, v+1+m);
        int cnt = n - sum;
        //db delta = k - k1;
        //int times = 1;
        for(int i = 1; i <= m; i++){
            if(cnt < v[i] || v[i] == p[0]) break;
            cnt -= v[i], s += 100 * v[i] / n + 1;
        }
        /*
        if(delta < 0.5 && delta > 0.00001){
            times = ceil(0.5 / delta);
            for(int i = m; i >= 1; i--){
                if(cnt > 0 && v[i] < 0.5 && v[i] + delta*max(times-1, 1)> 0.5)
                    cnt--, v[i] += k;
            }
        }else{
            s += round(k) * cnt;
            cnt = 0;
        } */
        //cerr << s << endl;
        s += (cnt/p[0]) * (p[0]* 100 /n + 1);
        cnt %= p[0];
        s += cnt * 100/n;
        /*
        if(cnt > 0){
            s += cnt * k1;
            s += cnt / times;
        }
        */
        printf("Case #%d: %d\n", kkk, s);
    }
    return 0;
}
