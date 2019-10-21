#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n;
double k, maxv;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;
        maxv = max(maxv, k);
    }
    printf("%.12f", maxv);
    return 0;
}
