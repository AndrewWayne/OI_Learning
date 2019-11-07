#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200;
int x, y, d, n, maxm, num, sum = 1;
int cross[maxn][maxn];   //多开2个20以免越界
int main() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> cross[x + 20][y + 20];
    }

    for(int i = 20; i <= 148; i++) {
        for(int j = 20; j <= 148; j++) {
            for(int xx = i - d; xx <= i + d; xx++) {
                for(int yy = j - d; yy <= j + d; yy++) {
                    num += cross[xx][yy];
                }
            }
            if(maxm == num) {
                sum++;
            }
            else if(maxm < num) {
                sum = 1;
            }
            maxm = max(maxm, num);
            num = 0;
        }
    }

    cout << sum << " " << maxm;
    return 0;
}
