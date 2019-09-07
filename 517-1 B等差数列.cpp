#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 5e5 + 10;
typedef long long ll;
ll l, r, s, e, res, a[MAXN], b[MAXN], c[MAXN];
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%lld%lld%lld%lld", &l, &r, &s, &e);
        ll d = (e - s)/(r-l);
        c[l] += s;
        c[l+1] -= s;
        c[l+1] += d;
        c[r+1] -= d;
        c[r+1] -= e;
        c[r+2] += e;
    }
    for(int i = 1; i <= n; i++)
        b[i] = b[i-1] + c[i];
    for(int i = 1; i <= n; i++)
        a[i] = a[i-1] + b[i];
    res = a[1];
    for(int i = 2; i <= n; i++)
        res ^= a[i];
    printf("%lld\n", res);
    return 0;

}
/*
5 5
1 5 2 10
2 4 1 1
2 5 0 0
1 4 3 9
2 3 1 3
*/
