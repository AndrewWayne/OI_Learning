#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
char name[100];
const int maxn = 5e5 + 10;
const int MOD = 1e7 - 10;
int n, k;
int rdm(int a, int b){
    return rand() % (b-a+1) + a;
}
int main(){
    srand(time(0));
    //3 4 5， 5 12 13，7 24 25
    for(int iii = 1; iii <= 10; iii++){
        sprintf(name, "gougu%d.in", iii);
        freopen(name, "w", stdout);
        long long m = rdm(1, 10000);
        long long n = rdm(m, 10000);
        cout << m*m + n*n << endl;
        cerr << n*n - m*m << " " << m*n*2 << endl;
    }
    return 0;
}
