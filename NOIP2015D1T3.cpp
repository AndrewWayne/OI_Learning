#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, t;
int cnt[20], sum, x, y, ans;//0表示王牌，1 ～ 13表普通牌
bool finished;
stack<int> OPT;
inline int id(int x){
    if(x == 14) return 1;
    return x;
}
inline bool check(int l, int r){
    for(int i = l; i <= r; i++)
        if(cnt[id(i)] == 0) return false;
    return true;
}
int h(){
    int sum[5];
    memset(sum, 0, sizeof(sum));
    for(int i = 1; i <= 13; i++) sum[cnt[i]]++;
    if(cnt[0] == 1) sum[1] += 1;
    if(cnt[0] == 2) sum[1] += 2;
    int res = 0;

    while(sum[4] > 0 && sum[2] > 1)
        sum[4] -= 1, sum[2] -= 2,
        res++;
    while(sum[4] > 0 && sum[1] > 1)
        sum[4] -= 1, sum[1] -= 2,
        res++;
    while(sum[4] > 0 && sum[2] > 0)
        sum[4] -= 1, sum[2] -= 1,
        res++;
    while(sum[3] > 0 && sum[2] > 0)
        sum[3] -= 1, sum[2] -= 1,
        res++;
    while(sum[3] > 0 && sum[1] > 0)
        sum[3] -= 1, sum[1] -= 1,
        res++;
    if(sum[1] >= 2 && cnt[0] == 2) sum[1] -= 1;
    return res + sum[4] + sum[3] + sum[2] + sum[1];
}
bool dfs(int step){
    if(step > ans) return false;
    if(step + h() <= ans){
        //cerr << step << "$$$" << endl;
        //cerr << sum << endl;
        return true;
    }
    //王炸
    if(cnt[0] == 2){
        cnt[0] -= 2, sum -= 2;
        //OPT.push(1);
        if(dfs(step+1)){
            return true;
        }
        //OPT.pop();
        cnt[0] += 2, sum += 2;
    }
    //三顺子
    for(int i = 3; i <= 13; i++){
        if(cnt[i] < 3 || cnt[id(i+1)] < 3) continue;
        int j = 0;
        for(j = i+1; j <= 14; j++)//三顺子不可能A->A
            if(cnt[id(j)] < 3){j--; break;}
        if(j == 15) j--;
        while(j > i){
            for(int k = i; k <= j; k++) cnt[id(k)] -= 3;
            sum -= (j - i + 1) * 3;
            //OPT.push(2);
            if(dfs(step+1))
                return true;
            //OPT.pop();
            sum += (j - i + 1) * 3;
            for(int k = i; k <= j; k++) cnt[id(k)] += 3;
            j--;
        }
    }
    //双顺子
    for(int i = 3; i <= 12; i++){
        if(cnt[i] < 2 || cnt[i+1] < 2 || cnt[id(i+2)] < 2) continue;
        int j = 0;
        for(j = i+2; j <= 14; j++)
            if(cnt[id(j)] < 2){j--; break;}
        if(j == 15) j--;
        while(j > i+1){
            for(int k = i; k <= j; k++) cnt[id(k)] -= 2;
            sum -= (j - i + 1) * 2;
            //OPT.push(3);
            if(dfs(step+1))
                return true;
            //OPT.pop();
            sum += (j - i + 1) * 2;
            for(int k = i; k <= j; k++) cnt[id(k)] += 2;
            j--;
        }
    }
    //单顺子
    for(int i = 3; i <= 10; i++){
        if(!check(i, i+4)) continue;
        int j = 0;
        for(j = i+4; j <= 14; j++)
            if(cnt[id(j)] == 0){ j--; break;}
        if(j == 15) j--;
        //cerr << "###: " << j << endl;
        while(j >= i+4){
            for(int k = i; k <= j; k++) cnt[id(k)] -= 1;
            sum -= (j - i + 1);
            //OPT.push(4);
            if(dfs(step+1))
                return true;
            //OPT.pop();
            sum += (j - i + 1);
            for(int k = i; k <= j; k++) cnt[id(k)] += 1;
            j--;
        }
    }
    return false;
}
void solve(){
    memset(cnt, 0, sizeof(cnt));
    sum = n;
    finished = false;
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        cnt[x]++;
    }
    for(ans = 1; ans <= n; ans++){
        if(dfs(0)){
            printf("%d\n", ans);
            //*
            //while(!OPT.empty()) cerr << OPT.top() << " ", OPT.pop();
            //cerr << endl;
            //*/
            return;
        }
    }
}
int main(){
    scanf("%d%d", &t, &n);
    while(t--){
        solve();
    }
    return 0;
}
