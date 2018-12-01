#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define sqr(x) ((x)*(x))
#define type int//看情况修改返回类型
using namespace std;
long long ans = 0;
const double deltaT = 0.99;
const double eps = 1e-3;
int h[330], n;
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
int myrand(int x){return rand()%x; }
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
double Rand(){return rand() % 100000 / 100000.00;}
long long calc(){
    long long val = 0;
    for(int i = 1; i <= n; i++)
        val += sqr(h[i] - h[i-1]);
    ans = max(ans, val);
    /*
    if(val == 70){
        for(int i = 1; i <= n; i++)
            cerr << h[i] << " ";
        cerr << endl;
    }//*/
    return val;
}
void SA(double T){
    long long now = ans;
    long long val = 0;
    while(T > eps){
        int x = rand()%n + 1, y = rand()%n + 1;
        if(x == y) continue;
        swap(h[x], h[y]);
        val = calc();
        if(val > now || exp((now - val)/T) > Rand())
            now = val;
        else
            swap(h[x], h[y]);
        T *= deltaT;
    }
    for(int i = 1; i <= 1000; i++){
        random_shuffle(h+1, h+1+n, myrand);
        calc();
    }
}
int main(){
    n = read();
    srand(13705834633);
    for(int i = 1; i <= n; i++)
        h[i] = read();
    while(Time() < 0.9)
        SA(100000);
    printf("%lld", ans);
    return 0;
}
