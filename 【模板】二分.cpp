#include <cstdio>
#include <iostream>
using namespace std;
bool F(int x){
    //这里需要视题目情况而定
    return true;
}
double eps = 1e-3;//eps表示精度，一般比题目要求的开低一位
double Binary_Answer(double l, double r){//这是实数域上的二分
    while(r - l >= 5 * eps){
        double mid = (l + r) / 2;
        if(F(mid)) r = mid;//看你设计的函数怎么样，这里认为是单调减
        else l = mid;
    }
    double i = 0.0;
    for(i = r; i >= l; i -= eps)
        if(F(i)) break;
    return i;
}//其实这样一个二分答案的程序就可以求解很多方程了。
int Binary_Search(int l, int r){//整数域//即eps = 1时的特殊情况
    int i;
    while(r - l >= 5){
        int mid = (l + r) / 2;
        if(F(mid)) l = mid;//这里认为是单调增
        else r = mid;
    }
    for(i = l; i <= r; i++)
        if(F(i)) break;
    return i;
}
int main(){

    return 0;
}
