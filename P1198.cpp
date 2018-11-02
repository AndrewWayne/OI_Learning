#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 2e5 + 20;
const long long minINF = (1<<64);
int m, d, m_size, top;
long long temp, n, maxv[maxn];//maxv是一个后缀最大值 maxv[l]表示区间[l,top]中的最大值
vector<long long> val;
char opt[3];

void reverse(){//每S个A操作进行一次约为O(M/S)
    for(int i = 0; i < val.size(); i++)//O(S)
        maxv[++top] = val[i];
    for(int i = top-1; i >= 1; i--)
        maxv[i] = max(maxv[i], maxv[i+1]);;//O(M)
    val.clear();
}
long long query(int len){
    long long ans = minINF;
    for(int i = val.size() - 1; i >= 0 && len >= 0; len--,i--)
        ans = max(ans, val[i]);//先在当前存储的操作中查找
    if(len > 0)//如果len很大继续在maxv中O(1)查找
        ans = max(ans, maxv[top-len+1]);//maxv[top-(len-1)]表示倒数len个数中的最大值
    return ans;
}
int main(){
    scanf("%d%d", &m, &d);
    m_size = (int)sqrt(m);
    while(m--){
        scanf("%s%lld", opt, &n);
        if(opt[0] == 'A'){
            val.push_back((n+temp)%d);
            if(val.size() > m_size)
                reverse();
        }else{
            scanf("%lld", &n);
            temp = query(n);
            cout << temp <<endl;
        }
    }
    return 0;
}
