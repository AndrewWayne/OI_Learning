#include <iostream>
#include <cmath>
#define int long long
//3337194063
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
    for(int iii = 1; iii <= 10; iii++){
    sprintf(name, "gougu%lld.in", iii);
    freopen(name, "r", stdin);
    sprintf(name, "gougu%lld.out", iii);
    freopen(name, "w", stdout);
    int x, y, a;
    xans = 0, ans = 0, c = 0, k = 0, top = 0;
    scanf("%lld", &c);
    cerr << c << endl;
    cc = (ll)c * c;
    for(int i = 1; i <= sqrt(2*c); i++){
        if(2*c % i != 0) continue;
        K[++top] = i;
        K[++top] = 2*c / i;
    }
    //cerr << 1 << endl;
    for(int i = 1; i <= top; i++){
        k = K[i];
        //cerr << k << endl;
        if((2*c) % k != 0) continue;
        for(int x = 1; x <= sqrt(2*c / k); x++){
             y = sqrt(2*c/k - x*x);
            if(y*y == 2*c/k - x*x && y >= x){
                if(gcd(x, y) != 1) continue;
                a = k*x*y;
                int b = sqrt((ll)c*c - (ll)a*a);
                if(b == 0 || a == 0 || b < a) break;
                if((ll)b*b == (ll)c*c - (ll)a*a){
                    ans += 2;
                    xans ^= a ^ b;
                    //cerr << k << endl;
                    //cerr << a << " " << b << " " << xans << endl;
                }
            }
        }
    }

    printf("%lld\n%lld\n", ans, xans);
    }
}
