//同题BZOJ 1150
//CTSC2007
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 1e5 + 10;
const int INF = 1e9 +7;
int n, k, used[maxn], len[2], ttt;
ll d[maxn][3], sum;//2表后缀，1表前驱
struct cmp{
    bool operator()(pli a, pli b){
        return a.first > b.first;
    }
};
int main(){
    memset(used, 0, sizeof(used));
    memset(d, 0, sizeof(d));
    sum = 0;
    priority_queue<pli, vector<pli>, cmp> Q;
    cin >> n >> k;
    int id = 0;
    cin >> len[id];
    for(int i = 1; i < n; i++, id ^= 1){
        cin >> len[id^1];
        d[i][0] = len[id^1] - len[id];
        d[i][1] = i-1;
        d[i][2] = i+1;
        Q.push(make_pair(d[i][0], i));
    }
    d[0][0] = INF;
    d[0][2] = 1;
    d[n][0] = INF;
    d[n][1] = n-1;
    for(int cnt = 1; cnt <= k; cnt++){
        pli temp;
        //cerr << "##: " << temp.first << endl;
        while(used[Q.top().second])
            Q.pop();
        temp = Q.top();
        Q.pop();
        int pre = d[temp.second][1];
        int nxt = d[temp.second][2];
        sum += temp.first;
        used[pre] = true;
        used[nxt] = true;
        d[temp.second][0] = d[pre][0] + d[nxt][0] - temp.first;
        d[temp.second][1] = d[pre][1];
        d[d[pre][1]][2] = temp.second;
        d[temp.second][2] = d[nxt][2];
        d[d[nxt][2]][1] = temp.second;
        Q.push(make_pair(d[pre][0] + d[nxt][0] - temp.first, temp.second));
    }
    cout << sum << endl;
    return 0;
}
