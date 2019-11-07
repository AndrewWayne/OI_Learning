#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long        ll;
typedef pair<int, int>   pii;
const int maxn = 1e4 + 10;
const int maxm = 1e3 + 10;
const int INF = 2147483647;
int n, m, k;
int high[maxn], low[maxn], x[maxn], y[maxn], cnt;
ll f[2][maxm*2];
pair<int, pii> tube[maxn];
int main() {
    memset(f, 0xff, sizeof(f));
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", x + i, y + i);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d%d%d", &tube[i].first, &tube[i].second.first, &tube[i].second.second);
        high[tube[i].first] = tube[i].second.second - 1;
        low[tube[i].first] = tube[i].second.first + 1;
    }

    sort(tube + 1, tube + 1 + k);

    for (int i = 0; i <= n; i++) {
        if (high[i] == 0) {
            high[i] = m, low[i] = 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        f[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        memset(f[i & 1], 0xff, sizeof(f[i & 1]));
        bool flag = false;

        //先处理往上跳
        for (int j = x[i - 1] + 1; j <= high[i]; j++) {
            if (f[(i & 1) ^ 1][j - x[i - 1]] >= 0) {//跳一步
                f[i & 1][j] = min(f[i & 1][j], f[(i & 1) ^ 1][j - x[i - 1]] + 1);

                if (f[i & 1][j] == -1) {
                    f[i & 1][j] = f[(i & 1) ^ 1][j - x[i - 1]] + 1, flag = true;
                }
            }

            if (f[i & 1][j - x[i - 1]] >= 0) {//跳多步
                f[i & 1][j] = min(f[i & 1][j], f[i & 1][j - x[i - 1]] + 1);

                if (f[i & 1][j] == -1) {
                    f[i & 1][j] = f[i & 1][j - x[i - 1]] + 1, flag = true;
                }
            }
        }

        for (int j = 1; j <= m; j++) {
            if (j < low[i]) {
                f[i & 1][j] = -1;
            }

            if (j > high[i]) {
                f[i & 1][j] = -1;
            }
        }

        for (int j = m - x[i - 1]; high[i] >= m && j <= m - 1; j++) {//跳到 m 可以由各种差一步的状态过来
            if (f[i & 1][j] >= 0) {
                f[i & 1][m] = min(f[i & 1][m], f[i & 1][j] + 1);

                if (f[i & 1][m] == -1) {
                    f[i & 1][m] = f[i & 1][j] + 1, flag = true;
                }
            }

            if (f[(i & 1) ^ 1][j] >= 0) {
                f[i & 1][m] = min(f[i & 1][m], f[(i & 1) ^ 1][j] + 1);

                if (f[i & 1][m] == -1) {
                    f[i & 1][m] = f[(i & 1) ^ 1][j] + 1, flag = true;
                }
            }
        }

        //现在处理往下掉（只能掉一次）
        for (int j = low[i]; j <= high[i]; j++) {
            if (f[(i & 1) ^ 1][j + y[i - 1]] >= 0) {
                f[i & 1][j] = min(f[i & 1][j], f[(i & 1) ^ 1][j + y[i - 1]]);

                if (f[i & 1][j] == -1) {
                    f[i & 1][j] = f[(i & 1) ^ 1][j + y[i - 1]], flag = true;
                }
            }
        }

        if (tube[cnt + 1].first == i) {
            if (flag) {
                cnt++;
            } else {
                puts("0");
                printf("%d\n", cnt);
                return 0;
            }
        }
    }

    ll ans = INF;

    for (int i = low[n]; i <= high[n]; i++) {
        if (f[n & 1][i] >= 0) {
            ans = min(ans, f[n & 1][i]);
        }
    }

    puts("1");
    printf("%lld\n", ans);
}
