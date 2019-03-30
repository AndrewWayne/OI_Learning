#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n, k, type[100], t, top, l, r, ans = 0x7fffffff;
pair<int, int> a[maxn];
bool cmp(pair<int,int> a1, pair<int,int> b1){
    if(a1.second == b1.second)
        return a1.first < b1.first;
    return a1.second < b1.second;
}
bool check(){
    for(int i = 1; i <= k; i++){
        if(!type[i])
            return false;
    }
    return true;
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        cin >> t;
        while(t--)
            cin >> a[++top].second, a[top].first = i;
    }
    sort(a+1, a+1+n, cmp);
//	for(int i = 1; i <= n; i++)
//	cerr << a[i].first << ": " << a[i].second << endl;
    l = r = 1;
    type[a[1].first]++;
    while(l <= r && r <= n){
        if(check()){
            ans = min(ans, a[r].second - a[l].second),
//			cerr << a[l].second << " -- " << a[r].second << endl,
            l++,
            type[a[l-1].first]--;
        }
        else
            r++,
            type[a[r].first]++;
    }
    cout << ans << endl;
    return 0;
}
