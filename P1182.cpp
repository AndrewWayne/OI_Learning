#include <cstdio>
#include <iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
const int maxn = 1e5 + 10;
int n, m, ans, a[maxn], sum, maxa;
bool F(int x){
    int sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum > x)
            cnt++, sum = a[i];
    }
    cerr << "#" << x << " " << cnt+1 << endl;
    return cnt+1 <= m;
}
int Binary_Answer(int l, int r){
    while(r - l >= 5){
        int mid = (l + r) / 2;
        if(F(mid)) r = mid;
        else l = mid;
    }
    cerr << l << " " << r << endl;
    int result;
    for(result = l; result <= r; result++)
        if(F(result)) break;
    return result;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i], maxa = max(maxa, a[i]), sum += a[i];
    F(997932);
    cout << Binary_Answer(maxa, sum);
    return 0;
}
