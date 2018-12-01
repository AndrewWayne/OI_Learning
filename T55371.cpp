#include <cstdio>
#include <iostream>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
double x[4], y[4];
double s, r, a, b, c;
int main(){
    for(int i = 1; i <= 3; i++)
        scanf("%f%f", &x[i], &y[i]);
    if((y[1] - y[2]) / (x[2] - x[2]) == (y[2] - y[3]) / (x[2] - x[3])){
        printf("-1");
        return 0;
    }else{
        a = sqrt(sqr(x[1] - x[2]) + sqr(y[1] - y[2]));
        b = sqrt(sqr(x[2] - x[3]) + sqr(y[2] - y[3]));
        c = sqrt(sqr(x[3] - x[1]) + sqr(y[3] - y[1]));
        s = (x[1]*y[2] + x[2]*y[3] + x[3]*y[1] - x[1]*y[3] - x[2]*y[1] - x[3]*y[2])/2;
        r = a*b*c/4/s;
    }
    printf("%.4f", r);
    return 0;
}
