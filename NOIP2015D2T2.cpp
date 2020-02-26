#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 10;
const int maxm = 220;
int n, m, k;
char A[maxn], B[maxm];
int f[2][maxm][maxm][2];
inline int Mod(int x){
    while(x > MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}
void Upd(int &x, int y){
    x = Mod(x + y);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", A+1);
    scanf("%s", B+1);
    if(A[1] == B[1]) f[1][1][1][1] = 1;
    f[1][0][0][0] = 1;
    for(int i = 2; i <= n; i++){//匹配到i
        int key = i & 1;
        memset(f[key], 0, sizeof(f[key]));
        for(int j = 0; j <= min(i, m); j++){//匹配到j
            for(int k = 0; k <= j; k++){//前面有k段
                if(A[i] == B[j]){//取当前数
                    Upd(f[key][j][k][1], f[key^1][j-1][k][1]);
                    Upd(f[key][j][k][1], f[key^1][j-1][k-1][0]);
                    Upd(f[key][j][k][1], f[key^1][j-1][k-1][1]);
                }
                Upd(f[key][j][k][0], f[key^1][j][k][0]);
                Upd(f[key][j][k][0], f[key^1][j][k][1]);//不取当前数
            }
        }
    }
    printf("%d", Mod(f[n&1][m][k][1] + f[n&1][m][k][0]));
    return 0;
}
