#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n, k, ans;
int main(){
    cin >> n >> k;
    ans = (int)ceil(2.0*n/k) + (int)ceil(5.0*n/k) + (int)ceil(8.0*n/k);
    cout << ans << endl;
    return 0;
}
