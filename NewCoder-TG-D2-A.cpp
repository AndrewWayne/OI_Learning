#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5+10;
int n;
long long a2[maxn],sum2,a1[maxn],sum1;
#define type long long//看情况修改返回类型
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
    return minus?0-sum:sum;
}

int main(){
    n=read();
    for(int i = 1; i <= n; i++)
        a1[i] = read(), sum1 += a1[i], a2[i] = a1[i] * a1[i], sum2 += a2[i];

    for(int i = 1; i < n; i++)
        cout<<(n-1)*(sum2-a2[i])-(sum1-a1[i])*(sum1-a1[i])<<" ";
    cout<<(n-1)*(sum2-a2[n])-(sum1-a1[n])*(sum1-a1[n])<<endl;
    return 0;
}
