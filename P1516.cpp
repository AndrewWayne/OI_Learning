#include <cstdio>
#include <iostream>
using namespace std;
long long x, y, m, n, L, d, a, b;
void exgcd(long long a, long long b, long long &d, long long &x, long long &y){
    if(b)
        exgcd(b, a%b, d, y, x),
        y -= x*(a/b);
    else
        d = a, x = 1, y = 0;
}

long long gcd(int u, int v){
    return v ? gcd(v, u%v) : u;
}

int main(){
    cin >> x >> y >> m >> n >> L;
    a = n - m;
    b = L;
    L = x - y;
    if(a < 0){
        a = -a;
        L = -L;
    }
    d = gcd(a, b);
    exgcd(a, b, d, x, y);
    if(L % d != 0){
        cout << "Impossible" << endl;
        return 0;
    }
    x = (x * (L/d) % (b/d) + b/d)%(b/d);
    cout << x << endl;
    return 0;
}
