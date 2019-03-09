#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define sqr(x) ((x)*(x))
using namespace std;
//自豪的采用了SA？？
const double eps = 1e-3;
const double deltaT = 0.99;
int n, m;
double a[22], x[22], avg, ans;
int myrand(int x){return rand() % x;}
double calc(){
    memset(x, 0, sizeof(x));
    int p = 1;
    double result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            if(x[j] < x[p]) p = j;
        x[p] += a[i];
    }
    for(int i = 1; i <= m; i++)
        result += sqr(x[i] - avg);
    result /= m;
    return result;
}
void SA(double);
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
int main(){
    srand(998244853);
    scanf("%d%d", &n, &m);
    ans = 1e15;
    for(int i = 1; i <= n ;i++)
        scanf("%lf", &a[i]), avg += a[i];
    avg /= m;
    while(Time() < 0.9)
        SA(100000);
    printf("%.2lf", sqrt(ans));
    return 0;
}
void SA(double T){
    double result = ans;
    while(T > eps){
        random_shuffle(a+1, a+1+n, myrand);
        double temp = calc();
        if(temp < result || exp(result - temp)/T*RAND_MAX > rand())
            result = temp;
        T *= deltaT;
    }
    ans = min(result, ans);
}
