#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//此算法已写崩，弃坑
const int maxn = 1e6+10;

int n, q, q_size, l, r, val;
long long height[maxn], b[maxn], copies[maxn];
char opt[5];
vector<pair<long long, long long>> modify;

void reverse(){
    for(int i = 0; i < modify.size(); i++)
        b[modify[i].first] += modify[i].second;
    for(int i = 1; i <= n; i++){
        height[i] = height[i-1] + b[i];
        copies[i] = height[i];
    }
    modify.clear();
}

int query(int L, int R, int C){
    int p = lower_bound(copies+1, copies+1+n, C) - copies;
    int ans += n - p + 1;
    for(int i = 0; i < modify.size(); i++)
        if( height[modify[i].first] < C && height[modify[i].first] + modify[i].second >= C )
            ans++;
    return ans;
}

int main(){

    scanf("%d%d", &n, &q);
    q_size = sqrt(n*log2(n));
    for(int i = 1 ; i <= n; i++){
        scanf("%d", &height[i]);
        b[i] = height[i] - height[i-1];
        copies[i] = height[i];
    }

    while(q--){
        scanf("%s%d%d%d", opt, l, r, val);
        if(opt[0] == 'A'){
            printf("%d", query(l, r, val));
        }else{
            modify.push_back(make_pair(l, val));
            modify.push_back(make_pair(r+1, -val));
            if(modify.size() > q_size)
                reverse();

        }
    }

    return 0;
}
