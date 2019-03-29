#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
char A[maxn];
long long len, ans, temp;
int nxt[maxn], n, jumps[21][maxn];
int main(){
    //freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    fgets(A+1, maxn, stdin);
    while(n--){
        //memset(A, 0, sizeof(A));
        //memset(nxt, 0, sizeof(nxt));
        //memset(jumps, 0, sizeof(jumps));
        ans = 1;
        len = 0;
        fgets(A+1, maxn, stdin);
        len = strlen(A + 1);
        //cerr << A+1 << endl;
        nxt[1] = 0;
        for(int i = 2, j = 0;i <= len; i++){
            while(j > 0 && A[i] != A[j+1]) j = nxt[j];
            if(A[i] == A[j+1]) j++;
            nxt[i] = j;
            jumps[0][i] = nxt[i];
        }

        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= 19; j++){
                jumps[j][i] = jumps[j-1][jumps[j-1][i]];//预处理出倍增数组
                //cerr << i << ":" << j << " -- " << jumps[i][j] << endl;
            }
        }
//&& jumps[i][j-1] && jumps[jumps[i][j-1]][j-1]
        for(int i = 2; i <= len; i++){
            int at = i;
            temp = 0;
            for(int j = 19; j >= 0; j--)
                if(jumps[j][at] * 2 > i)
                    at = jumps[j][at];//找到第一个大于i/2的点

            for(int j = 19; j >= 0; j--)//往下跳
                if(jumps[j][at])
                    temp += 1 << j,
                    at = jumps[j][at];
            ans = (ans * (temp + 1)) % MOD;
        }

        printf("%d\n", ans);
    }

    return 0;
}
