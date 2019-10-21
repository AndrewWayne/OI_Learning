#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100;
ll A[maxn];
int n;
int main(){
    scanf("%d", &n);
    A[1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--)
            A[i] = max(A[i], A[i-j] * j);
        printf("%d ---- %lld\n", i, A[i]);
    }

    return 0;
}
