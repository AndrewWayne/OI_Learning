#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int MAXN=100001;
const int INF=1e9;
int f[MAXN], v[MAXN], l[MAXN], n, m;
long long sum[MAXN], ans = 0;
__gnu_pbds::priority_queue <int> heap[MAXN];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> f[i] >> v[i] >> l[i];
    for(int i = n; i; i--){
        heap[i].push(v[i]);
        sum[i] += v[i];

        while(sum[i] > m)
            sum[i] -= heap[i].top(),
            heap[i].pop();

        ans = max(ans, (long long)(heap[i].size() * l[i]));
        sum[ f[i] ] += sum[i];
        heap[ f[i] ].join(heap[i]);
    }

    cout << ans << endl;
    return 0;
}
