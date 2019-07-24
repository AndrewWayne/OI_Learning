/*
 * Author: xiaohei_AWM
 * Date: 7.11
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
const int maxn = 351, maxm = 121;
int n, m, a[maxn], b[maxm], f[41][41][41][41];//f[w][x][y][z]表示到第i格，每种卡片分别还有 w x y z张的最大分值
//由于n可以被算出来
int cnt[5], ans;
int main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= m; i++) b[i] = read(), cnt[b[i]]++;
    f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] = a[1];
    int t[5];
    for(t[1] = cnt[1]; t[1] >= 0; t[1]--)
        for(t[2] = cnt[2]; t[2] >= 0; t[2]--)
            for(t[3] = cnt[3]; t[3] >= 0; t[3]--)
                for(t[4] = cnt[4]; t[4] >= 0; t[4]--){
                    for(int k = 1; k <= 4; k++){
                        int pos = (cnt[1] - t[1]) + 2*(cnt[2] - t[2]) + 3*(cnt[3] - t[3]) + 4*(cnt[4] - t[4]) + 1;
                        t[k]++;
                        int temp;
                        if(pos > k)
                            temp = f[t[1]][t[2]][t[3]][t[4]] + a[pos];
                        else temp = 0;
                        t[k]--;
                        f[t[1]][t[2]][t[3]][t[4]] = max(f[t[1]][t[2]][t[3]][t[4]], temp);
                    }
                    ans = max(ans, f[t[1]][t[2]][t[3]][t[4]]);
                }
    printf("%d\n", ans);
    return 0;
}
