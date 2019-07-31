#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e6;
int k, n;
char s[N];
int help[N];
int g[N];
unordered_map<int, int>f;
int main() {
    k=300;
    scanf("%s",s);
    n = strlen(s);
    for (int i = 0; i < n; i ++)
        s[i] -= '0';
    int x = k, y = 0, z = 0, xx = 1;
    while (x % 2 == 0) x /= 2, y ++, xx *= 2;
    while (x % 5 == 0) x /= 5, z ++, xx *= 5;
    help[0] = 1;
    for (int i = 1; i < N; i ++)
        help[i] = (long long)help[i - 1] * 10 % k;
    long long ans = 0;
    int len = max(y, z);
    int vv = 0;
    for (int i = n - 1; i >= 0; i --)
        g[i] = (g[i + 1] + (long long)s[i] * help[n - i - 1]) % k;
    for (int i = 0; i < n; i ++)
    {
        int v = 0;
        vv = 0;
        for (int j = 0; j < len && i - j >= 0; j ++) {
            v = (v + (long long) help[j] * s[i - j]) % k;
            vv = (vv + (long long) help[j] * s[i - j]) % xx;
            ans += (v == 0);
        }
        if (i - len >= 0)
            f[g[i - len]]++;
        if (vv == 0)
            ans += f[g[i + 1]];
    }
    printf("%lld\n", ans);
    return 0;
}
