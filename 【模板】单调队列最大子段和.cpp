#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 2e5 + 10;
int n, m, ans = 0x80000000, sum[maxn], a;
deque<int> Q;//用于存储决策
//单调队列算法首先证明决策在满足某种单调性的前提下可以使得答案更优的情况，然后抛弃不优的决策，在这里就是选尽量靠前的sum小的决策
int main(){
    cin >> n ;//>> m;
    m = n;
    Q.push_back(0);//存入初始决策，即左端点为1的情况
    for(int i = 1; i <= n; i++){
        cin >> a;
        sum[i] = sum[i-1] + a;
        while(!Q.empty() && Q.front() < i - m) Q.pop_front();//抛弃过期的决策
        cerr << sum[i] - sum[Q.front()] << endl;
        ans = max(ans, sum[i] - sum[Q.front()]);//选出当前最优决策
        while(!Q.empty() && sum[Q.back()] > sum[i]) Q.pop_back();//维护决策的单调性
        Q.push_back(i);
    }
    cout << ans << endl;
    return 0;
}
