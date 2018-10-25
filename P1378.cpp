#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
long double s,ans,x11,y11,x22,y22,d2[10][10];
struct Node{
    bool visit;
    long double x,y,r;
} bubble[10];
void dfs( int now, int num ,long double size){//now is the id, num means how many bubbles, size is the sum of r
    if( bubble[now].visit ) return;
    bubble[now].visit = true;
    for( int i = 0 ; i <= n; i++ ){
        if( !bubble[i].visit || i == now) continue;
        if( d2[now][i] <= bubble[i].r ){
            bubble[now].r = 0;
            break;
        }
        bubble[now].r = min( bubble[now].r , d2[now][i] - bubble[i].r);
    }
    if( num == n ){
        ans = max( ans, size );
        bubble[now].r = 4000.0;
        bubble[now].visit = false;
        return;
    }
    for( int i = 1 ; i <= n; i++ )
        dfs( i, num+1 , size + bubble[now].r * bubble[now].r);
    bubble[now].r = 4000.0;
    bubble[now].visit = false;
    return;
}
int main(){
    scanf("%d", &n);
    scanf("%Lf%Lf%Lf%Lf", &x11, &y11, &x22, &y22);
    bubble[0].r = 0.0;
    s = abs(x22 - x11) * abs(y22 - y11);
    for(int i = 1; i <= n; i++){
        scanf("%Lf%Lf", &bubble[i].x, &bubble[i].y);
        bubble[i].visit = false;
        bubble[i].r = 2000.0;
        d2[i][0] = min( abs(bubble[i].x - x11), min( abs(bubble[i].x - x22), min( abs(bubble[i].y - y11), abs(bubble[i].y - y22))));
        for(int j = 1; j < i; j++)
            d2[i][j] = sqrt((bubble[i].x - bubble[j].x)*(bubble[i].x - bubble[j].x) + (bubble[i].y - bubble[j].y)*(bubble[i].y - bubble[j].y));
    }//init
    dfs(0,0,0.0);
    printf("%d", int(s - M_PI * ans + 0.5));
    return 0;
}
