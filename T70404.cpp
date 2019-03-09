#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1e7 + 10;
const int MOD = 1e8 + 7;
int n, temp, stat1, stat2, pow2[maxn], bigger;
bool stat = 0;
bool used[maxn];
char name[100];
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
int main(){
//    for(int iii = 1; iii <= 10; iii++){
//        sprintf(name,"Nine%d.in",iii);
//        freopen(name, "r", stdin);
//        sprintf(name,"Nine%d.out",iii);
//        freopen(name, "w", stdout);
    memset(used, 0, sizeof(used));
    stat = stat1 = stat2 = bigger = temp = 0;
    scanf("%d", &n);
    pow2[0] = 1;
    for(int i = 1; i <= n; i++)
        pow2[i] = (pow2[i-1] << 1) % MOD;

    for(int i = n-1; i >= 0; i--){
        scanf("%d", &temp);
        if(temp == stat)
            stat = 0;
        else if(temp != stat){
            stat = 1;
            used[i] = 1;
            stat1 += pow2[i];
            stat1 %= MOD;
        }
    }

    stat = 0;
    for(int i = n-1; i >= 0; i--){
        scanf("%d", &temp);
        if(temp == stat){
            stat = 0;
            if(bigger == 0){
                if(temp && !used[i])
                    bigger = 2;
                if(!temp && used[i])
                    bigger = 1;
            }
        }
        else if(temp != stat){
            if(bigger == 0){
                if(temp && !used[i])
                    bigger = 2;
                if(!temp && used[i])
                    bigger = 1;
            }
            stat = 1;
            used[i] = 1;
            stat2 += pow2[i];
            stat2 %= MOD;
        }
    }
    cerr << stat1 << " " << stat2 << endl;

    if(stat2 == 0)
        bigger = 1;
    switch (bigger) {
        case 1:
            printf("%d\n", (stat1 - stat2 + MOD) %MOD);
            break;
        case 2:
            printf("%d\n", (stat2 - stat1 + MOD) %MOD);//由于stat2 和 stat1都是对于MOD取模过的正数，所以两者相减的差一定不会小于-MOD直接+MOD即可
            break;
        default:
            printf("-1\n");
            break;
    }
//    }
    return 0;
}
