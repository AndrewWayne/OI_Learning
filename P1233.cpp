#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct data{
    int len,width;
    bool operator<(const data &v){return len > v.len ;}
}stick[5050];
int n,top,ans=1,ANS[5050];
int main(){
    cin>> n;
    for(int i = 1; i <= n; i++)
        cin >> stick[i].len >> stick[i].width,ANS[i]=1000000;
    sort( stick + 1 , stick + 1 + n );
    for(int i = 1 ; i <= n ; i++ ){
        int x = stick[i].width;
        *lower_bound( ANS+1 , ANS + n +1 , x ) = x;
    }
    cout << ( lower_bound( ANS+1 , ANS + n +1 , 1000000 ) - ANS - 1);
    return 0;
}
