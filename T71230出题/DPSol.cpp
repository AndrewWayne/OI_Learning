//T71230
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define type int//看情况修改返回类型
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
const int maxn = 5e6 + 10;
const int maxv = 32;
long long n, K, a[maxn], choose[maxv], val[maxv];//dp[n][k]表示在n之前分k组的最大值，val[i]表示第i位的决策点到i的or和，choose[i]表示在第i位上的决策点
char name[100];
int main(){
    for(int iii = 12; iii <= 12; iii++){
    sprintf(name, "dp%d.in", iii);
    freopen(name, "r", stdin);
    sprintf(name, "dp%d.out", iii);
    freopen(name, "w", stdout);
    memset(val, 0, sizeof(val));
    memset(a, 0, sizeof(a));
    memset(choose, 0, sizeof(choose));
    n = read(), K = read();
    const int n1 = n+1, k1 = K+1;
    long long** dp = new long long *[n1];
    for(int i = 0; i < n1; i++)
        dp[i] = new long long[k1];
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < k1; j++)
            dp[i][j] = 0;
    for(int i = 1; i <= n; i++){
        a[i] = read();
        dp[i][1] = dp[i-1][1] | a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 31; j++ ){
            if((a[i] >> j)&1){
                val[j] = a[i];
                choose[j] = i;
            }
            val[j] |= a[i];
        }

        for(int k = 2; k <= K && k <= i; k++){
            for(int j = 0; j <= 31; j++)
                if(choose[j] >= k)
                    dp[i][k] = max(dp[choose[j]-1][k-1] + val[j], dp[i][k]);
        }
    }//总复杂度O(nklogv) logv可认做32

    cout << dp[n][K] << endl;
    for(int i = 0; i < n1; i++)
        delete [] dp[i];
    delete [] dp;
    }
    return 0;
}
