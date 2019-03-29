#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define reg register
#define type int//看情况修改返回类型
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    bool minus=false;
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9')&&ch!='-')ch=nc();
    if(ch=='-')minus=true,ch=nc();//判负没必要的时候记得删，影响效率
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
const int maxn = 1e3 + 10;
const int maxlog = 10 + 1;
int n, m;
int a[maxn][maxn];
int st[maxn][maxn][maxlog][maxlog];
int Log2[maxn];
inline int query(int x1, int y1, int x2, int y2)
{
    int k1 = Log2[x2 - x1 + 1], k2 = Log2[y2 - y1 + 1];
    return max(st[x1][y1][k1][k2], max(st[x2-(1<<k1)+1][y1][k1][k2], max(st[x1][y2-(1<<k2)+1][k1][k2], st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2])));
}

int main()
{
    n = read(), m = read();
    for(int i = 2; i <= max(n, m); i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }

    for (reg int i = 1 ; i <= n ; ++i)
        for (reg int j = 1 ; j <= m ; ++j)
            st[i][j][0][0] = a[i][j] = read();

    for (reg int p = 0 ; p <= 9 ; p ++)
        for (reg int q = 0 ; q <= 9 ; q ++)
            if (p != 0 || q != 0)
                for (reg int i = 1 ; i + (1<<p) - 1 <= n ; i ++)
                    for (reg int j = 1 ; j + (1<<q) - 1 <= m ; j ++)
                        if (!p) st[i][j][p][q] = max(st[i][j][p][q - 1], st[i][j+(1<<(q-1))][p][q - 1]);
                        else st[i][j][p][q] = max(st[i][j][p-1][q], st[i+(1<<(p-1))][j][p-1][q]);
//i走p次方，q走j次方
    int q = read();
    while(q--)
    {
        int x1=read(),y1=read(),x2=read(),y2=read();
        printf("%d\n", query(x1,y1,x2,y2));//查询矩阵中最大值
    }
    return 0;
}
