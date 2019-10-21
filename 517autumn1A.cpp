#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long double ldb;
int n, m;
long double Rate;
// i * (i/n^n - (i-1)/n^n) --> ()
long double quickPow(ldb base, int s){
    ldb res = 1.0;
    for(int i = s; i; i >>= 1){
        if(i & 1) res = res * base;
        base = base * base;
    }
    return res;
}
int main(){
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++){
        //cerr << quickPow((ldb)i/(ldb)n, n) << endl;
        //cerr << quickPow((ldb)(i-1)/(ldb)n, n) << endl;
        Rate += (ldb)i * (quickPow(((ldb)i/(ldb)m), n) - quickPow((ldb)(i-1)/(ldb)m, n));

    }
    printf("%.6Lf", Rate);
    return 0;
}
