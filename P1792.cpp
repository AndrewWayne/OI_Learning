#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 2e5 + 10;
typedef pair<int,int> pii;
int n, m, a[maxn], sum;
int pre[maxn], nxt[maxn], visit[maxn];
struct comp{
    bool operator()(pii a, pii b){
        return a.second < b.second;
    }
};
priority_queue<pii, std::vector<pii>, comp> Q;
int main(){
    cin >> n >> m;
    if(n < 2*m){
        cout << "Error" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = i-1;
        nxt[i] = i+1;
        Q.push(make_pair(i, a[i]));
    }
    pre[1] = n;
    nxt[n] = 1;
    for(int i = 1; i <= m; i++){
        while(visit[Q.top().first]) Q.pop();
        pii temp = Q.top();
        Q.pop();
        sum += temp.second;
        cerr << temp.second << endl;
        visit[pre[temp.first]] = true;
        visit[nxt[temp.first]] = true;
        a[temp.first] = a[pre[temp.first]] + a[nxt[temp.first]] - temp.second;
        pre[temp.first] = pre[pre[temp.first]];
        nxt[temp.first] = nxt[nxt[temp.first]];
        pre[nxt[temp.first]] = temp.first;
        nxt[pre[temp.first]] = temp.first;
        Q.push(make_pair(temp.first, a[temp.first]));
    }
    cout << sum << endl;
    return 0;
}
