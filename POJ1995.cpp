#include <cstdio>
#include <iostream>
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
    return minus?-sum:sum;
}

int quickPower(long long a, long long b, int p)//是求a的b次方
{
    int ans = 1 % p;//ans为答案，base为a^(2^n)
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}

long long z, h, a, b, m, ans;
int main(){
    z = read();
    while(z--){
        m = read(), h = read();
        ans = 0;
        while(h--){
            a = read(), b = read();
            ans += quickPower(a, b, m);
        }
        ans %= m;
        printf("%d\n",ans);
    }
    return 0;
}
