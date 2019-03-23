#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
const int inf=1<<29,N=25010;
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
    while(ch>='0'&&ch<='9')sum=(sum * 10)+ch-48,ch=nc();
    return sum;
}
struct node{int x,y;}a[N];
int Cmp(node x1,node x2){return max(x2.x - x1.y + x1.x, x1.x) < max(x1.x + x2.x - x2.y, x2.x);}//这个贪心策略并不一定是要和网上的一样，可以xjb推
int main()
{
    int i,j,n=read();
    for(i=1;i<=n;i++)a[i].x=read(),a[i].y=read();
    sort(a+1,a+1+n,Cmp);
    int x=a[1].x,s=a[1].x+a[1].y;
    for(i=2;i<=n;i++)
    {
        x+=a[i].x;
        s=max(s,x)+a[i].y;
    }
    printf("%d\n",s);
    return 0;
}
