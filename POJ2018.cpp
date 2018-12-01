#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1e5+10;
const double eps = 1e-4;
int n, f;
double fields[maxn], sum[maxn];
bool check(double x){
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + (fields[i] - x);
    double min_val = 1e10, ans = -1e10;
    for(int i = f; i <= n; i++){
        min_val = min(sum[i - f], min_val);
        ans = max(ans, sum[i] - min_val);
    }
    return ans >= 0;
}
int main(){
    while(~scanf("%d%d", &n, &f)){
        memset(fields, 0, sizeof(fields)), memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
            scanf("%lf", &fields[i]);
        double l = -1e6, r = 1e6, mid;
        while( r - l > 5*eps){
            mid = (l+r) / 2.0;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        double average = l;
        for(average = l; average <= r && check(average); average += eps);
        printf("%d\n", int(average * 1000));
    }
    return 0;
}
