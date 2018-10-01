#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double s,ans,n,x1,y1,x2,y2,d2[10][10];
struct Node{
    double x,y,r2;
} bubble[10];
double calc(int r2){
    return M_PI*r2;
}
int main(){
    cin>> n;
    cin>> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= n; i++){
        cin>> bubble[i].x >> bubble[i].y;
        d2[i][0] = min( abs(bubble[i].x - x1), min( abs(bubble[i].x - x2), min( abs(bubble[i].y - y1), abs(bubble[i].y - y2))));
        d2[i][0] *= d2[i][0];
        for(int j = 1; j <= i; j++)
            d2[i][j] = (bubble[i].x - bubble[j].x)*(bubble[i].x - bubble[j].x) + (bubble[i].y - bubble[j].y)*(bubble[i].y - bubble[j].y);
    }//init


    return 0;
}
