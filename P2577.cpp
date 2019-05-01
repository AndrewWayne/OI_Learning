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
const int maxn = 1e3 + 10;
pii a[maxn];
int n, f[400010], sum, ans, b[maxn];//f[i][j]表示前i-1个人共花费时间j的最优解，i为阶段，使用滚动降维
bool cmp(pii x, pii y){
    return x.second > y.second;
}
int main(){
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].first = read(), a[i].second = read();
    sort(a+1, a+1+n, cmp);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        b[i] = a[i].first + b[i-1];
    for (int i = 1; i <= n; i++){
        for (int j = sum; j >= 0; j--){//滚动
            f[j + a[i].first] = min(f[j + a[i].first], max(f[j], a[i].second + j + a[i].first));//将i加入第一个队列
            f[j] = max(f[j], a[i].second + b[i] - j);//将i加入第二个队列
        }
        sum += a[i].first;
    }
    ans = 0x7fffffff;
    for (int i = 1; i <= sum; i++)
        ans = min(ans, f[i]);
    cout << ans << endl;
}
