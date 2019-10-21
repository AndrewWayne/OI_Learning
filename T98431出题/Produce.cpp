#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
char name[100];
const int maxn = 5e5 + 10;
const int MOD = 1e7 - 10;
int k;
long long m[20], n[20];
int rdm(int a, int b){
    return rand() % (b-a+1) + a;
}
int main(){
    srand(time(0));
    int a = 10; int *b=&a;
    int *&p = b;
    //3 4 5， 5 12 13，7 24 25
    for(int iii = 4; iii <= 10; iii++){
        sprintf(name, "gougu%d.in", iii);
        freopen(name, "w", stdout);
        long long res = 1;
        //cerr << "$$$" << endl;
        for(int i = 1; i <= 4; i++){
            m[i] = rdm(3, 13);
            n[i] = rdm(m[i]+1, 14);
            res *= m[i]*m[i] + n[i]*n[i];
            //cerr << n[i] * n[i] - m[i] * m[i] << " " << m[i] * n[i] * 2 << endl;
        }
        printf("%lld\n", res);
        //cout << res << endl;
        //cerr << n*n*n*n - m*m*m*m << " " << m*n*2 << endl;
    }
    return 0;
}
