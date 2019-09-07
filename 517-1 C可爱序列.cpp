#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 50;
const int MOD = 1e9 + 7;
int n;
ll f[2][maxn][maxn][2000], a[maxn];
//f[b][i][x][sum] 表示[1,i]以数x结尾，且x小于前一个数，前缀和为sum的方案数
ll lessthan[maxn], bigthan[maxn], ans;
inline ll Mod(ll x){
    while(x >= MOD) x -= MOD;
    return x;
}
inline int val(int x){
    return x == -1 ? 40 : x;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 2; i <= n-1; i++)
        if(a[i-1] > a[i] && a[i] > a[i+1] && a[i] != -1 && a[i-1] != -1 && a[i+1] != -1){
            printf("0\n");//根据 No response 不难推断出其实是有一些数据天生不合法的
            return 0;
        }
    bigthan[1] = bigthan[n] = 0;
    lessthan[n-1] = lessthan[n] = 40;
    for(int i = 2; i <= n-1; i++)
        if(a[i] > a[i+1] && a[i] != -1 && a[i+1] != -1) lessthan[i-1] = a[i];//表示a[i-1]必须小于等于a[i]这个数
        else lessthan[i-1] = 40;
    for(int i = 2; i <= n-1; i++)
        if(a[i-1] > a[i] && a[i-1] != -1 && a[i] != -1) bigthan[i+1] = a[i];//表示a[i+1]必须大于等于a[i]
    f[0][0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == -1){
            for(int k = bigthan[i]; k <= lessthan[i]; k++){
                for(int sum = k*(i-1); sum <= 1600; sum++){
                    for(int x = 0; x <= 40; x++){
                        if(k >= x) f[0][i][k][k+sum] = Mod(f[0][i][k][k+sum] + f[0][i-1][x][sum] + f[1][i-1][x][sum]);
                        else f[1][i][k][k+sum] = Mod(f[1][i][k][k+sum] + f[0][i-1][x][sum]);
                    }
                }
            }
        }else{
            for(int sum = a[i]*(i-1); sum <= 1600; sum++)
                for(int x = 0; x <= 40; x++){
                    if(a[i] >= x) f[0][i][a[i]][a[i]+sum] = Mod(f[0][i][a[i]][a[i]+sum] + f[0][i-1][x][sum] + f[1][i-1][x][sum]);
                    else f[1][i][a[i]][a[i]+sum] = Mod(f[1][i][a[i]][a[i]+sum] + f[0][i-1][x][sum]);
                }
        }
    }
    for(int i = 0; i <= 40*n; i++)
        for(int j = 0; j <= val(a[n]); j++)
            ans = Mod(ans + f[0][n][j][i] + f[1][n][j][i]);
    //cerr << f[0][3][4][12] + f[0][3][3][11] << endl;
    printf("%lld\n", ans);
    return 0;
}
