#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn];
__int128 a1[maxn];
int cnt;
__int128 SQRT(__int128 x){
    __int128 key = 0;
    for(int i = 63; i >= 0; i--){
        __int128 nk = key + (1 << i);
        if(nk * nk <= x) key = nk;
    }
    return key;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i),
        a1[i] = a[i];
    for(int i = 1; i <= (1 << n) - 1; i++){
        __int128 res = 1;
        int pos = 1;
        for(int k = i; k; k >>= 1, pos++)
            if(k & 1) res *= a1[pos];
        __int128 k = SQRT(res);
        if(k * k == res){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
