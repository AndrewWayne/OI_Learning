#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e7 + 10;
const int MOD = 1e8 + 7;
int n, stat1, stat2, pow2[maxn], bigger;
bool stat = 0, temp;
bool used[maxn];
int main(){
    cin >> n;
    pow2[0] = 1;
    for(int i = 1; i <= n; i++)
        pow2[i] = (pow2[i-1] << 1) % MOD;

    for(int i = n-1; i >= 0; i--){
        cin >> temp;
        if(temp == stat)
            stat = 0;
        else if(temp != stat){
            stat = 1;
            used[i] = 1;
            stat1 += pow2[i];
            stat1 %= MOD;
        }
    }

    stat = 0;
    for(int i = n-1; i >= 0; i--){
        cin >> temp;
        if(temp == stat)
            stat = 0;
        if(temp != stat){
            if(bigger == 0){
                if(!used[i] && temp)
                    bigger = 2;
                if(used[i] && (!temp))
                    bigger = 1;
                //cerr << used[i] << " " << temp << endl;
            }
            stat = 1;
            stat2 += pow2[i];
            stat2 %= MOD;
        }
    }
    if(stat2 == 0)
        bigger = 1;
    switch (bigger) {
        case 1:
            cout << (stat1 - stat2 + MOD) %MOD << endl;
            break;
        case 2:
            cout << (stat2 - stat1 + MOD) %MOD << endl;//由于stat2 和 stat1都是对于MOD取模过的正数，所以两者相减的差一定不会小于-MOD直接+MOD即可
            break;
        default:
            cout << -1 << endl;
            break;
    }

    return 0;
}
