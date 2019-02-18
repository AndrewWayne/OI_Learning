#include <cstdio>
#include <iostream>
using namespace std;
typedef long long Type1;//change it!
Type1 a, b, x, y, d;
inline void exgcd(Type1 a, Type1 b, Type1 &d, Type1 &x, Type1 &y){
    if(!b){
        x = 1; y = 0, d = a;
        return;
    }
    exgcd(b, a%b, d, x, y);
    Type1 t = x;
    x = y; y = t - (a / b) * y;
    return;
}
int main(){
    cin >> a >> b;
    d = 1;
    exgcd(a, b, d, x, y);
    if(d < 0)
        d = -1*d;
    while(x < 0)
        x += b/d;
    printf("%d", x);
    return 0;
}
