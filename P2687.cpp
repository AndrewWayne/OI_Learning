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
const int maxn = 5e3 + 10;
int n;
double a[maxn], f[maxn], sol[maxn];//f[i]表示以i结尾的最长LIS的长度//sol表示以i结尾的最长LIS的不同序列方案数。
int main(){
    cin >> n;
    a[0] = 2147483647;
    f[0] = 0;
    sol[0] = 1.0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i-1; j >= 0; j--)//滚动优化(虽然并非必要)
            if(a[j] > a[i] && f[i] <= f[j]) f[i] = f[j] + 1;
        for(int j = i-1; j >= 0; j--){
            if(a[j] > a[i] && f[i] == f[j] + 1)// j是决策点，就统计方案
                sol[i] += sol[j];
            else if(a[j] == a[i] && f[i] == f[j]) break;//产生相同序列
        }
    }
    double ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
        if(ans < f[i]) ans = f[i], cnt = sol[i];
        else if(ans == f[i]) cnt += sol[i]; //统计相同长度的方案数
    printf("%.0lf %.0lf\n", ans, cnt);
    return 0;
}
