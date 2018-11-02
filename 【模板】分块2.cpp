//这是对操作q进行分块。
//当修改操作达到指定个数时重构原数组
//好有趣
//实现区间修改，区间查询。
//基于差分在维护一个前缀和，使其可以在O(qs)的时间内询问并在O(q/s*n)的时间内

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector< pair<long long, long long> > modify;
const int maxn = 1e5+10;
const int maxq = 1e5+10;
long long n, q, a1, a2, l, r, x, opt, b[maxn], q_size, sum[maxn], ssum[maxn];
void reverse(){//每s次修改重构一次，共2*q/s次
    for(int i = 0; i < modify.size(); i++)
        b[modify[i].first] += modify[i].second;//s

    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + b[i], ssum[i] = ssum[i-1] + sum[i];//n

    modify.clear();
}
long long query(long long x, long long y){//O(qs)的询问
    long long ans = ssum[y] - ssum[x-1];
    for(int i = 0; i < modify.size(); i++)
        if( modify[i].first <= y ){
            ans += modify[i].second * (y - max(modify[i].first, x) + 1);
        }
    return ans;
}

int main(){
    cin >> n >> q;
    q_size = (int)sqrt(n);
    for(int i = 1; i <= n; i++){
        cin >> a2;
        b[i] = a2 - a1;
        sum[i] = sum[i-1] + b[i];
        ssum[i] = ssum[i-1] + sum[i];
        a1 = a2;
    }
    while(q--){
        cin >> opt;
        if(opt == 1){
            cin >> l >> r >> x;
            modify.push_back(make_pair(l, x));
            modify.push_back(make_pair(r+1, -x));
            if(modify.size() > q_size)
                reverse();
        }else{
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
    }

    return 0;
}
