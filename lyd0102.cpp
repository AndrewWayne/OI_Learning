#include <cstdio>
#include <cmath>
using namespace std;
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
long long a, b, p, ans;
int main(){
    a = read(), b = read(), p = read();
    while( b ){
        if( b & 1 )
            ans = ( ans + a ) % p;
        a <<= 1;
        a %= p;
        b >>= 1;
    }
    printf("%lld", ans);
}
