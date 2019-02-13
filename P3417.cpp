#include <cstdio>
#include <iostream>
#include <cstring>
#define Int int
using namespace std;
const int maxn = 1e3 + 10;
const int maxt = 1e4 + 10;
int n, t, nxt[maxt][10], cnt;
char input[maxt];
bool great[10000];
bool check(int xx){
    int x[5];
    x[1] = xx/1000, x[2] = (xx/100)%10, x[3] = (xx/10)%10, x[4] = xx%10;
    int at = 1;
    for(int i = 1; i <= 4; i++){
        if(nxt[at][x[i]] == 0)
            return false;
        at = nxt[at][x[i]];
    }
    return true;
}
int main(){
    memset(great, 1, sizeof(great));
    cin >> n;
    for(int i = 1; i <= n; i++){
        memset(nxt, 0, sizeof(nxt));
        cin >> t;
        cin >> input;
        for(int j = t; j >= 1; j--){
            for(int k = 0; k < 10; k++){
                if(k == input[j-1] - '0')
                    nxt[j][k] = j;
                else
                    nxt[j][k] = nxt[j+1][k];
            }
        }
        for(int j = 0; j < 10000; j++)
            great[j] &= check(j);
    }

    for(int i = 0; i < 10000; i++)
        cnt += great[i];

    cout << cnt << endl;

    return 0;
}
