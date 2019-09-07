#include <cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
#define ll long long
const int maxn = 5005005;
int p[maxn],a[maxn];
int main(void) {
	freopen("dp11.in", "r", stdin);
    int n,k; scanf("%d%d",&n,&k);
    assert(10 <= n*k && n*k <= 5000000);
    for (int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        assert(10 <= p[i] && p[i] <= 1e7);
    }
    ll ans=0;
    sort(p+1,p+n+1,greater<int>());
    for (int i=1;i<=n;i++) {
        int mx=0,id=0;
        for (int j=1;j<=k;j++) {
            if ((p[i]&(p[i]^a[j])) > mx) mx=p[i]&(p[i]^a[j]), id=j;
        }
        if (id) a[id] |= p[i];
    }
    for (int i=1;i<=k;i++) ans += a[i];
    printf("%lld\n",ans);
    return 0;
}
