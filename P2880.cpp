// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define type int//看情况修改返回类型
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    bool minus=false;
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}

const int maxn = 1e6;
int n, m, a[maxn], st[maxn][30], st1[maxn][30], l, r;
int Log2[maxn];
int querymax(int l, int r){
    int res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = max(st[l][x], st[r - (1<<x) + 1][x]);
    return res;
}
int querymin(int l, int r){
    int res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = min(st1[l][x], st1[r - (1<<x) + 1][x]);
    return res;
}
int main(){
    scanf("%d%d", &n, &m);

    for(int i = 2; i <= n; i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }

    for(int i = 1; i <= n; i++)
        a[i] = read(),
        st[i][0] = a[i],
        st1[i][0] = a[i];
    int ll = Log2[n];

    for(int i = 1; i <= ll; i++){
        for(int j = 1; j + (1<<i) -1 <= n; j++)
            st[j][i] = max(st[j][i-1], st[j + (1 << (i-1))][i-1]);
    }
    for(int i = 1; i <= ll; i++){
        for(int j = 1; j + (1<<i) -1 <= n; j++)
            st1[j][i] = min(st1[j][i-1], st1[j + (1 << (i-1))][i-1]);
    }

    for(int i = 1; i <= m; i++){
        l = read(), r = read();
        printf("%d\n", querymax(l, r) - querymin(l, r));
    }
    return 0;
}
