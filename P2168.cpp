#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5 + 20;
struct cmp{
    bool operator()(pair<long long,long long> a, pair<long long,long long> b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
priority_queue<pair<long long,long long>, vector<pair<long long,long long> >, cmp > Q;
long long n, k, w, cnt, sum, ans;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> w,
        Q.push(make_pair(w, 0));
    while((n-1)%(k-1))
        Q.push(make_pair(0, 0)), n++;
    //cerr << "#" << n << endl;
    long long temp = 0;
    while(n >=  k){
        temp = cnt = 0;
        for(int i = 1; i <= k; i++)
            temp += Q.top().first,
            cnt = max(Q.top().second, cnt),
            //cerr << "----" << Q.top() << endl,
            Q.pop();
        ans += temp;
        //cerr << "#: " << temp << endl;
        //cerr << Q.size() << endl;
        Q.push(make_pair(temp, cnt+1));
        cnt++;
        n -= k-1;
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
