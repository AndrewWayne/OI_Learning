// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e6;
struct PAIR{
    long long Right, l, r;//右端点为Right,左端点在l ,r直间
    long long val;
    bool operator<(const PAIR &v)const{
        return val < v.val;
    }
};
long long sum[maxn], n, a[maxn], ll, rr, k, ans;
long long Log2[maxn];
pair<long long,long long> st[maxn][30];//st[i][j]表示从j开始包含2^i个元素中的最小值
priority_queue<PAIR> Q;
pair<long long, long long> minn(pair<long long,long long> a, pair<long long,long long> b){
    if(a.first < b.first)
        return a;
    return b;
}
pair<long long,long long> query(long long l, long long r){
    int len = r - l + 1;
    int x = Log2[len];
    pair<long long,long long> res = minn(st[l][x], st[r - (1<<x) + 1][x]);
    return res;
}
int main(){
    //freopen("8.in", "r", stdin);
    scanf("%lld%lld%lld%lld", &n, &k, &ll, &rr);
    for(int i = 2; i <= n; i++){
        if((1 << (Log2[i-1]+1)) > i)
            Log2[i] = Log2[i-1];
        else
            Log2[i] = Log2[i-1]+1;
    }

    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]),
        sum[i] = sum[i-1] + a[i],
        st[i][0] = make_pair(sum[i], i);//要记录下这个点的位置，用于在之后寻找次优解

    //预处理出ST表
    for(int i = 1; i <= Log2[n]; i++)
        for(int j = 1; j + (1<<i) -1 <= n; j++){
            st[j][i] = minn(st[j][i-1], st[j + (1 << (i-1))][i-1]);
            //cerr << j << "--" << i << ": " <<  st[j][i].first << " " << st[j][i].second << endl;
        }

    //右端点为i,左端点在i-r+1,i-l+1范围间的超级和弦
    for(int i = 1; i <= n; i++){
        if(i - ll + 1 <= 0) continue;//边界
        pair<long long,long long> x = query(max((long long)0, i-rr) ,i-ll);
        //cerr << i << ":" << sum[i] - x << endl;
        PAIR temp = {i, max((long long)1, i-rr+1), i-ll+1, sum[i] - x.first};
        Q.push(temp);
    }
    for(int i = 1; i <= k; i++){
        PAIR temp = Q.top();
        long long l = temp.l;
        long long r = temp.r;
        //printf("#%lld to %lld :: %lld\n", query(l-1, r-1).second+1, temp.Right, sum[temp.Right] - query(l-1, r-1).first);
        ans += temp.val;
        Q.pop();
        int x = query(l-1, r-1).second + 1;//选中的那个最优解的左点位置
        if(x != l){
            PAIR temp1 = {temp.Right, l, x-1, sum[temp.Right] - query(l-1, x-2).first};

            //printf("%d to %d :: %d\n", query(l-1, x-2).second+1, temp.Right, sum[temp.Right] - query(l-1, x-2).first);

            Q.push(temp1);
        }
        if(x != r){
            PAIR temp1 = {temp.Right, x+1, r, sum[temp.Right] - query(x, r-1).first};
            //printf("%d to %d :: %d\n", query(x, r-1).second + 1, temp.Right, sum[temp.Right] - query(x, r-1).first);
            Q.push(temp1);
        }
    }

    printf("%lld", ans);
    return 0;
}
