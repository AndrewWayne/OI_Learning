// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1e6;
int n, m, a[maxn], st[maxn][30], l, r;
int Log2[maxn];
int query(int l, int r){
    int res = 0;
    int len = r - l + 1;
    int x = Log2[len];
    res = max(st[l][x], st[r - (1<<x) + 1][x]);
    return res;
}
int main(){
    scanf("%d%d", &n, &m);

    for(int i = 2; i <= n; i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }

    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]),
        st[i][0] = a[i];
    int ll = Log2[n];

    for(int i = 1; i <= ll; i++){
        for(int j = 1; j + (1<<i) -1 <= n; j++)
            st[j][i] = max(st[j][i-1], st[j + (1 << (i-1))][i-1]);
    }

    for(int i = 1; i <= m; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
