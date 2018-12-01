#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#define lowbit(x) (x&-x)
using namespace std;
set<int, greater<int> > order;
map<int, int> func;
const int maxn = 5e5 + 10;
int n, a[maxn], b[maxn], result;
void add(int x, int val){
    for(int i = x; i <= n; i += lowbit(i))
        b[i] += val;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += b[i];
    return ans;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), order.insert(a[i]);
    for(int i = 1; !order.empty(); i++){
        func[*order.begin()] = i;
        order.erase(order.begin());
    }
    for(int i = 1; i <= n; i++){
        add(func[a[i]], 1);
        result += query(func[a[i]] - 1);
        //cerr << result << endl;
    }
    printf("%d", result);
    return 0;
}
