/*
 * Author: xiaohei_AWM
 * Date: 7.8
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
#define parents(a) a[i][j][l][r][x][y]
const int maxn = 16, maxk = 226;
int n, m, k, a[maxn][maxn], sum[maxn][maxn], f[maxn][maxk][maxn][maxn][2][2];// f[i][x][l][r][s1][s2] -- 表示到第 i 行, 块中有x个，左列是 l 右列是 r, 左边处于 s1 状态(0 为列号递增， 1 为递减），右边处于s2状态
int cl[maxn][maxk][maxn][maxn][2][2], cr[maxn][maxk][maxn][maxn][2][2];//cl[i][x][l][r][s1][s2]表示当前状态有哪个左转移来
int dx[maxn][maxk][maxn][maxn][2][2], dy[maxn][maxk][maxn][maxn][2][2];
inline void update(int v, int i, int j, int l, int r, int x, int y, int L, int R, int X, int Y){//由于要记录方案所以使用一个子函数来更新状态写起来比较好写
    if(v < f[i][j][l][r][x][y]) return;
    f[i][j][l][r][x][y] = v;
    cl[i][j][l][r][x][y] = L, cr[i][j][l][r][x][y] = R;
    dx[i][j][l][r][x][y] = X, dy[i][j][l][r][x][y] = Y;
}
void print(int i, int j, int l, int r, int x, int y){
    if(!j) return;
    print(i - 1, j - (r-l+1), parents(cl), parents(cr), parents(dx), parents(dy));
    for(int j = l; j <= r; j++)
        printf("%d %d\n", i, j);
}
int main(){
    scanf("%d%d%d", &n, &m ,&k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]), sum[i][j] = sum[i][j-1] + a[i][j];
    memset(f, 0xcf, sizeof(f));
    for(int i = 0; i <= n; i++)
        f[i][0][0][0][1][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            for(int l = 1; l <= m; l++)
                for(int r = l; r <= m; r++){//枚举末状态
                    int t;
                    if((t = r - l + 1) > j) break;
                    int temp = sum[i][r] - sum[i][l-1];

                    if(j == r-l+1)
                        update(f[i-1][0][0][0][1][0] + temp, i, j, l, r, 1, 0, 0, 0, 1, 0);//新开一行
                    if(j > r-l+1)
                        for(int p = l; p <= r; p++)
                            for(int q = p; q <= r; q++)//左减右增
                                update(f[i-1][j-t][p][q][1][0] + temp, i, j, l, r, 1, 0, p, q, 1, 0);

                    for(int p = 1; p <= l; p++)
                        for(int q = r; q <= m; q++){//左增右减
                            update(f[i-1][j-t][p][q][1][0] + temp, i, j, l, r, 0, 1, p, q, 1, 0);
                            update(f[i-1][j-t][p][q][1][1] + temp, i, j, l, r, 0, 1, p, q, 1, 1);
                            update(f[i-1][j-t][p][q][0][1] + temp, i, j, l, r, 0, 1, p, q, 0, 1);
                            update(f[i-1][j-t][p][q][0][0] + temp, i, j, l, r, 0, 1, p, q, 0, 0);
                        }

                    for(int p = l; p <= r; p++)
                        for(int q = r; q <= m; q++)//左减右减
                            update(f[i-1][j-t][p][q][1][0] + temp, i, j, l, r, 1, 1, p, q, 1, 0),
                            update(f[i-1][j-t][p][q][1][1] + temp, i, j, l, r, 1, 1, p, q, 1, 1);

                    for(int p = 1; p <= l; p++)
                        for(int q = l; q <= r; q++)//左增右增
                            update(f[i-1][j-t][p][q][1][0] + temp, i, j, l, r, 0, 0, p, q, 1, 0),
                            update(f[i-1][j-t][p][q][0][0] + temp, i, j, l, r, 0, 0, p, q, 0, 0);
                }
    int ans = 0, ai = 0, al = 0, ar = 0, ax = 0, ay = 0;
    for(int i = 1; i <= n; i++)
        for(int l = 1; l <= m; l++)
            for(int r= l; r <= m; r++)
                for(int x = 0; x <= 1; x++)
                    for(int y = 0; y <= 1; y++)
                        if(ans < f[i][k][l][r][x][y])
                            ans = f[i][k][l][r][x][y],
                            ai = i, al = l, ar = r, ax = x, ay = y;
    printf("Oil : %d\n", ans);
    print(ai, k, al, ar, ax, ay);
    return 0;
}
