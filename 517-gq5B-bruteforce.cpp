#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int maxn = 3e5 + 10;
const int maxk = 1e6 + 10;
int n, k, a[maxn], sum[maxn];
int has[maxk];
long long ans;
//void partition(int,int);
signed main(){
    //freopen("programmer.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = a[i];
        for(int j = i+1; j <= n; j++){
            mx = max(a[j], mx);
            if((sum[j] - sum[i-1] - mx) % k == 0){
                ans++;
                //cerr << i << " " << j << endl;
            }
        }
    }
    //partition(1, n);
    printf("%lld", ans);
    return 0;
}
