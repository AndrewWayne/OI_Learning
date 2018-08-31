#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i,s,e) for(int i=s;i<=e;i++)
#define MAX(_a,_b) ((_a>_b)?_a:_b)
using namespace std;
struct man{
    long long left, right;
    bool d;
    void calc(){
        d=(left-right)>0;
    }
    bool operator < (const man &v) const{
        return (d != v.d)? (!d):( !d ? left<v.left : right > v.right);
    }
}guys[20020];
long long t,n,sum,prize;
int main(){
    cin>>t;
    while(t--){
        scanf("%lld" , &n );
        REP(i,1,n)
        scanf("%lld%lld", &guys[i].left, &guys[i].right),guys[i].calc();
        sort(guys+1,guys+1+n);
        sum = guys[1].left;
        prize = sum + guys[1].right;
        REP(i,2,n){
            sum += guys[i].left;
            prize = MAX(sum,prize) + guys[i].right;
        }
        printf("%lld\n", prize);
    }
    return 0;
}
