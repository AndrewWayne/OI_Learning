#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int xans, ans, c, k;
ll cc;
int K[maxn], top;
int gcd(int a, int b){
    while(b){int r = b; b = a%b; a = r;}
    return a;
}
char name[20];
signed main(){
    int x, y, a;
    xans = 0, ans = 0, c = 0, k = 0, top = 0;
    scanf("%lld", &c);
    cc = (ll)c * c;
    for(int i = 1; i <= sqrt(2*c); i++){
        if(2*c % i != 0) continue;
        K[++top] = i;
        K[++top] = 2*c / i;
    }
    for(int i = 1; i <= top; i++){
        k = K[i];
        if((2*c) % k != 0) continue;
        for(int x = 1; x <= sqrt(2*c / k); x++){
             y = sqrt(2*c/k - x*x);
            if(y*y == 2*c/k - x*x && y >= x){
                if(gcd(x, y) != 1) continue;
                a = k*x*y;
                int b = sqrt((ll)c*c - (ll)a*a);
                if(b == 0 || a == 0 || b < a) break;
                if((ll)b*b == (ll)c*c - (ll)a*a){
                    ans += 2*4;
                }
            }
        }
    }
    printf("%d\n", ans+4);
}
