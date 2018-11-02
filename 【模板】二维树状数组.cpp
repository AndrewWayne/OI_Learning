//所以随手写一个二维前缀和树状数组以示清白？？
//支持矩阵修改，矩阵求和
//二维差分求和太tm神仙了
//不加初始化了//模板题P4514
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 4e3+10;
int b1[MAXN][MAXN], b2[MAXN][MAXN], b3[MAXN][MAXN], b4[MAXN][MAXN], n, m, q, x1, y1, x2, y2, val;
char opt[5];
int lowbit(int x){
    return x & -x;
}
void add(int x, int y, int val){//O(lognlogm)的维护
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= m; j += lowbit(j))
            b1[i][j] += val,
            b2[i][j] += val * (x-1),
            b3[i][j] += val * (y-1),
            b4[i][j] += val * (x-1)*(y-1);
}
int query(int x, int y){//O(lognlogm)的查询
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for(int i = x; i; i -= lowbit(i))
        for(int j = y; j; j -= lowbit(j))
            ans1 += b1[i][j],
            ans2 += b2[i][j],
            ans3 += b3[i][j],
            ans4 += b4[i][j];
    return ans1*x*y - ans2*y - ans3*x + ans4;
}
int main(){
    scanf("%s%d%d", opt, &n, &m);

    while(~scanf("%s%d%d%d%d", opt, &x1, &y1, &x2, &y2)){
        if(opt[0] == 'L'){
            scanf("%d", &val);
            add(x1, y1, val), add(x2+1, y2+1, val);
            add(x1, y2+1, -val), add(x2+1, y1, -val);
        }
        else
            cout << query(x2, y2) + query(x1-1, y1-1) - query(x1-1, y2) - query(x2, y1-1) << endl;
    }
    return 0;
}
