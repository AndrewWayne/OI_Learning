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
int main(){
    srand(time(0));
    for(int iii = 4; iii <= 6; iii++){
        sprintf(name, "dp%d.in", iii);
        freopen(name, "w", stdout);
        int t = rand()%4000000 + 1000000;
        n = 500;
        k = 100;
        cout << n << " " << k << endl;
        for(int i = 1; i <= n; i++)
            cout << rand()%MOD + 10 << " ";
        cout << endl;
    }
    return 0;
}
