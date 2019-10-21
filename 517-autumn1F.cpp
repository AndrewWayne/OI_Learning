#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 4000;
int n, p[maxn], cnt, d[maxn*maxn];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(p[i] > p[j])
                cnt++;
    //cerr << cnt << endl;
    d[0] = 0;
    d[1] = 1;
    for(int i = 2; i <= cnt; i++){
        d[i] = d[i-2] + 4;
        //cerr << d[i] << endl;
    }
    double ans = d[cnt];
    printf("%.6f", ans);
    return 0;
}
