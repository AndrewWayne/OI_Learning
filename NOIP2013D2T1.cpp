#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n, h[maxn], ans;
bool mode;
int main() {
    ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    if (h[2] >= h[1]) mode = 1;

    for (int i = 1; i <= n; i++) {
        if (!mode && i == n){
            ans++;
            break;
        }

        if (mode) {
            if (h[i + 1] < h[i]) {
                ans++;
                mode ^= 1;
                continue;
            }
        }

        if (mode == 0) {
            if (h[i + 1] > h[i]) {
                ans++;
                mode ^= 1;
                continue;
            }
        }
    }

    cout << ans;
}
