#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 10;
int n, num[maxn], k, f[maxn], cnt[maxn];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        for(int j = sqrt(num[i]); j >= 1; j--){
            if(num[i] % j == 0){
                int temp = num[i]/j;
                if(temp == j)
                    temp = 0;
                cnt[temp]++, cnt[j]++;
                f[cnt[temp]] = max(f[cnt[temp]], temp);
                f[cnt[j]] = max(f[cnt[j]], j);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << f[i] << endl;
    return 0;
}
