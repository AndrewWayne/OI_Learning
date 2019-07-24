/*
 * Author: xiaohei_AWM
 * Date: 6.30
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
const int maxn = 50, maxk = 10;

//f[p1][p2][p3][p4][p5]表示第k行放pk个人的方案数，然后根据可行性递推。显而易见从1 ... n的摆放是按照从左到右从前往后的顺序的，一个较大的数除非比左边大且前面小才有方案。
int main(){
    ll n, k, a[maxk], p[maxk];
    while(k = readll()){
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= k; i++)
            a[i] = readll();
        ll f[a[1]+2][a[2]+2][a[3]+2][a[4]+2][a[5]+2];
        memset(f, 0, sizeof(f));
        f[0][0][0][0][0] = 1;
        for(p[1] = 0; p[1] <= a[1]; p[1]++)
            for(p[2] = 0; p[2] <= a[2] && p[2] <= p[1]; p[2]++)
                for(p[3] = 0; p[3] <= a[3] && p[3] <= p[2]; p[3]++)
                    for(p[4] = 0; p[4] <= a[4] && p[4] <= p[3]; p[4]++)
                        for(p[5] = 0; p[5] <= a[5] && p[5] <= p[4]; p[5]++){
                            ll stat = f[p[1]][p[2]][p[3]][p[4]][p[5]];
                            f[p[1]+1][p[2]][p[3]][p[4]][p[5]] += stat;
                            f[p[1]][p[2]+1][p[3]][p[4]][p[5]] += stat;
                            f[p[1]][p[2]][p[3]+1][p[4]][p[5]] += stat;
                            f[p[1]][p[2]][p[3]][p[4]+1][p[5]] += stat;
                            f[p[1]][p[2]][p[3]][p[4]][p[5]+1] += stat;
                        }

        printf("%lld\n", f[a[1]][a[2]][a[3]][a[4]][a[5]]);
    }
    return 0;
}
