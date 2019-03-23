#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define start second.first
#define ends second.second
#define val first
using namespace std;
const int maxn = 1e6 + 10;
int n, m, r[maxn], ans, val[maxn];
typedef pair<int, pair<int, int> >  piii ;
piii ordered[maxn];
bool check(int x){
    memset(val, 0, sizeof(val));
    int endtime = 0;
    for(int i = 1; i <= x; i++){
        val[ordered[i].start] += ordered[i].val;
        val[ordered[i].ends+1] -= ordered[i].val;
    }
    for(int i = 1; i <= n; i++){
        val[i] += val[i-1];
        if(val[i] > r[i])
            return false;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> r[i];
    for(int i = 1; i <= m; i++)
        cin >> ordered[i].first >> ordered[i].second.first >> ordered[i].second.second;
    for(int i = log2(m); i >= 0; i--){
        if( ans + (1<<i) <= m && check(ans + (1<<i) ) )
            ans += (1<<i);
    }
    if(ans == m)
        cout << 0 << endl;
    else
        cout << -1 << endl << ans+1 << endl;

    return 0;
}
