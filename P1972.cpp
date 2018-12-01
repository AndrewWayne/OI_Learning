#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 5e3+50;
const int MAXM = 5e3+50;
const int MAXID = 1e3+10;
struct Ques{
    int l, r, id;
    bool operator<(const Ques &v)const{
        return r < v.r;
    }
}ques[MAXM];
int n, m, l, r, c[MAXN], neck[MAXN], ans[MAXN], pos[MAXID];
int lowbit(int x){
    return x & -x;
}
void add(int x, int val){
    for(int i = x; i <= n; i += lowbit(i))
        c[i] += val;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &neck[i]);

    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &ques[i].l, &ques[i].r), ques[i].id = i;
    sort(ques+1, ques+1+m);

    l = 1;
    for(int i = 1; i <= m; i++){
        r = ques[i].r;
        for(int j = l; j <= r; j++)
            if(pos[neck[j]]){
                add(pos[neck[j]], -1), add(j, 1);
                pos[neck[j]] = j;
            }else{
                pos[neck[j]] = j;
                add(j, 1);
            }
        l = r+1;
        ans[ques[i].id] = query(ques[i].r) - query(ques[i].l - 1);
    }
    //时间复杂度O((m+n)logn)

    for(int i = 1; i <= m ; i++)
        printf("%d\n", ans[i]);

    return 0;
}
