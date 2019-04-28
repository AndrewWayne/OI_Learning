/*
 *Author: xiaohei_AWM
 *Date:
 *Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
const int maxn = 2e5 + 10;
const int maxl = 1e5 + 10;
int n, l, r, c[maxl], e[maxn], ans;
char opt;
inline int lowbit(int x){
    return x&-x;
}
void add(int x, int val){
    for(int i = x; i < maxl; i += lowbit(i))
        c[i] += val;
}
int query(int x){
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> opt >> l >> r;
        if(opt == 'A'){
            int sum = query(r);
            int del = 0;
            while((sum = query(r))){
                int mid = 0;
                for(int k = log2(r); k >= 0; k--)
                    if(mid + (1<<k) <= r && query(mid+(1<<k)) + 1 <= sum)
                        mid += (1 << k);
                if(e[mid+1] >= l)
                    add(mid+1, -1), del++, ans--;
                else
                    break;
            }
            add(l, 1), e[l] = r, ans++;
            cout << del << endl;
        }else
            cout << ans << endl;
    }
    return 0;
}
