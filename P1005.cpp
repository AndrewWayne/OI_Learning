#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxx(a,b) a>b?a:b
#define kk (m-r+l)
using namespace std;

__int128 powwTwo[81];
int n,m,a[100][100];
__int128 f[100][100],ans;

void print(__int128 x){
    if(!x)
        return;
    if(x)
        print(x/10);
    putchar(x%10+'0');
}

__int128 dp(int l,int r,int id){
    if(f[l][r] != -1)
        return f[l][r];
    if(r-l >= 1)
        f[l][r] = maxx(dp(l+1, r, id) + a[id][l] * kk, dp(l, r-1, id) + a[id][r] * kk);
    else f[l][r] = a[id][l] * kk;
    return f[l][r];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d",&a[i][j]);

    powwTwo[0] = 1;
    for(int i = 1; i <= m; i++)
        powwTwo[i] = powwTwo[i-1] * 2;

    for(int i = 1;i <= n; i++){
            memset(f,-1,sizeof(f));
            ans += dp(1, m ,i);
    }

    print(ans);
    return 0;
}
