#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int t;
double a, b;
double ans;
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> a >> b;
        if(b == 0){
            printf("1.0\n");
            continue;
        }
        if(a == 0){
            printf("0.5\n");
            continue;
        }
        int sum = a * b * 2;
        if(4*b <= a){
            ans = 1.0 - b/a;
        }else{
            ans = (a * 0.25 + b * 2.0)/ (4 * b);
            //cerr << ((double)a*b - (double)a*a / 8.0) << endl;
            //ans = ans / sum;
            //ans = 1.0 - ans;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
