// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <string>
#define min(a,b) a<b?a:b
using namespace std;
string num;
int n,ans,sum,t,d[30],td[30],k,k1;
int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0x7fffffff;
        for(int i = 1; i <= n; i++){
            d[i] = 0;//多组数据
            cin >> num;//读入比较麻烦
            for(int j = n-1 ; j >= 0; j--)
                d[i] += ((num[n-j-1] - '0') ^ 1) << j;//存状态
            td[i] = d[i];
        }
        for(int i = 0; i < (1 << n); i++){
            sum = 0;
            k1 = i;
            sum += __builtin_popcount(k1);
            td[1] ^= ((k1 << 1) ^ (k1 >> 1) ^ k1) % ( 1 << n );
            td[2] ^= k1;
            for(int j = 2; j <= n; j++){
                k1 = td[j-1];//递推：必须和上一行位数一样
                sum += __builtin_popcount(k1);//记录点击次数
                td[j-1] = d[j-1];//上一行归位
                k = ((k1 << 1) ^ (k1 >> 1) ^ k1) % ( 1 << n );//根据点击位置得出本行的变换（因为如果一个点被重复变换两次相当于没有变换，所以用异或连接）（状态向左，向右，和自己）
                td[j] ^= k;//有1就取反变换
                td[j+1] ^= k1;//变换下一行
            }//递推

            if( td[n] == 0 )
                ans = min(ans, sum);//打擂
            td[n] = d[n];//归位
        }
        if(ans == 0x7fffffff)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
