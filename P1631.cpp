#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define type int//看情况修改返回类型
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9')&&ch!='-')ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
int n,sum;
int a[100010],b[100010];
priority_queue<int> ans;
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++) a[i]=read();
    sort( a+1 , a+1+n );
    for(int i = 1; i <= n; i++) b[i]=read();
    sort( b+1 , b+1+n );

    for(int i = 1; i <= n; i++)
        for(int j = 1; (i-1)*(j-1)<=n && j <= n; j++)
            ans.push(a[i]+b[j]);

    while( n-- ){
        printf("%d ", ans.top());
        ans.pop();
    }

    return 0;
}
