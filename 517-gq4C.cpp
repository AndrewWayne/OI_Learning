#include <cstdio>
#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn = 3e5 + 10;
int n, top, x, y;
ll ans;
int a[maxn];
int mx[maxn], mn[maxn];
unordered_map<int,int> has;
void partition(int l, int r){
        int mid = (l+r) >> 1;
        if(l == r) {
                ans++;
                //cerr << l << " " << r << " " << ans << endl;
                return;
        }
        partition(l, mid), partition(mid+1, r);
        //cerr << "**" << ans << endl;
        //cerr << l << " " << r << endl;
        mx[mid] = mn[mid] = a[mid];
        mx[mid+1] = mn[mid+1] = a[mid+1];
        for(int i = mid-1; i >= l; i--)
                mx[i] = max(a[i], mx[i+1]),
                mn[i] = min(a[i], mn[i+1]);
        for(int i = mid+2; i <= r; i++)
                mx[i] = max(a[i], mx[i-1]),
                mn[i] = min(a[i], mn[i-1]);

        int l1 = mid, l2 = mid, r1 = mid+1, r2 = mid+1;
        for(l1 = mid; l1 >= l; l1--) {
                r1 = mx[l1] - mn[l1] + l1;
                if(r1 > mid && r1 <= r && mx[r1] < mx[l1] && mn[r1] > mn[l1])
                        ans++;
        }
        l1 = mid, l2 = mid, r1 = mid+1, r2 = mid+1;
        //mx - mn = r - l
        for(r1 = mid+1; r1 <= r; r1++) {
                l1 = mn[r1] + r1 - mx[r1];
                if(l1 <= mid && l1 >= l && mx[r1] >= mx[l1] && mn[r1] <= mn[l1])
                        ans++;
        }
        //cerr << "OK2" << endl;
        l1 = mid, l2 = mid, r1 = mid+1, r2 = mid+1;
        for(l1 = mid; l1 >= l; l1--) {//min在左 max在右
                while(mn[r2] > mn[l1] && r2 <= r) {//
                        has[r2 - mx[r2]]++;
                        r2++;
                }
                while(mx[r1] < mx[l1] && r1 < r2) {
                        has[r1 - mx[r1]]--;
                        r1++;
                }
                ans += has[l1 - mn[l1]];
        }
        while(r1 < r2) has[r1 - mx[r1]]--, r1++;
        //cerr << "OK3" << endl;
        l1 = mid, l2 = mid, r1 = mid+1, r2 = mid+1;
        for(r1 = mid+1; r1 <= r; r1++) {//min在右 max在左
                while(mn[l1] > mn[r1] && l1 >= l) {//
                        has[l1 + mx[l1]]++;
                        l1--;
                }
                while(mx[l2] < mx[r1] && l1 < l2) {
                        has[l2 + mx[l2]]--;
                        l2--;
                }
                ans += has[r1 + mn[r1]];
        }
        while(l1 < l2) {
                has[mx[l2] + l2]--;
                l2--;
        }
        //cerr << "OK4" << endl;
}

int main(){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) { scanf("%d%d", &x, &y),
                a[x] = y;
        }
        partition(1, n);

        cout << ans << endl;
        return 0;
}
