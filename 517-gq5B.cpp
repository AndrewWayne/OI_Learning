#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 10;
const int maxk = 1e6 + 10;
int n, k;
int has[maxk];
long long a[maxn], sum[maxn];
long long ans;
void partition(int,int);
int main(){
    //freopen("programmer.in", "r", stdin);
    scanf("%d%d", &n, &k);
    //cerr << n << " " << k << endl;
    for(int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    //for(int i = 1; i <= n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;
    //cerr << "OK" << endl;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
        //cerr << sum[i] << endl;
    partition(1, n);
    printf("%lld", ans);
    return 0;
}
void partition(int l, int r){
    int mid = (l+r) >> 1;
    if(r - l < 1) return;
    if(r - l == 1){
        //cerr << sum[r] - sum[l-1] - max(a[l], a[r]) << endl;
        if((sum[r] - sum[l-1] - max(a[l], a[r]))% k == 0){
            ans++;
            //cerr << l << " " << r << endl;
        }
        //cerr << l << " " << r << " " << ans << endl;
        return;
    }
    if(r - l > 1) partition(l, mid), partition(mid+1, r);
    int l1 = mid, r1 = mid+1;
    long long maxl = a[mid], maxr = a[mid+1];
    //cerr << "$$: " << l << " " << r << endl;
    for(l1 = mid; l1 >= l; l1--){
        maxl = max(maxl, a[l1]);
        while(r1 <= r && maxr < maxl){
            //cerr << maxr << endl;
            //int key = sum[r1] % k;
            has[sum[r1] % k]++;
            r1++;
            maxr = max(maxr, a[r1]);
        }
        ans += has[(sum[l1-1]+maxl) % k];
    }
    while(r1 > mid+1) has[sum[r1-1]%k] = 0, r1--;

    l1 = mid, r1 = mid+1, maxl = a[mid], maxr = a[mid+1];
    for(r1 = mid+1; r1 <= r; r1++){
        maxr = max(maxr, a[r1]);
        while(l1 >= l && maxl <= maxr){
            has[sum[l1-1] % k]++;
            l1--;
            maxl = max(maxl, a[l1]);
        }
        ans += has[(sum[r1] - maxr) % k];
        //cerr << "r: " << l1+1 << " " << r1 << " " << ans << endl;
    }
    //cerr << ans << endl;
    while(l1 < mid) has[sum[l1] % k] = 0, l1++;
}
