#include <cstdio>
#include <iostream>
#define judge(x,y) ((x&1)==(y&1))
#define ll long long
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
int t;
ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
ll white, black, size;
void work(ll size, bool color, int mode){//mode = 1 为白色 mode = -1 为黑色
    white = white + ((size>>1) + (color ? (size&1) : 0))*mode;
    black = black - ((size>>1) + (color ? (size&1) : 0))*mode;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        white = n * m / 2 + ((n * m) & 1);
        black = n * m / 2;
        cin >> x1 >> y1 >> x2 >> y2;
        size = (x2 - x1 + 1) * (y2 - y1 + 1);
        work(size, !judge(x1, y1), 1);
        cin >> x3 >> y3 >> x4 >> y4;
        if(x3 <= x2 && x4 >= x1 && y4 >= y1 && y3 <= y2 ){//将重叠部分还原
            size = ((min(x2, x4)) - (max(x1, x3)) + 1) * ((min(y2, y4)) - (max(y1, y3)) + 1);
            ll x = min(x2, x4);
            ll y = min(y2, y4);
            work(size, !judge(x, y), -1);
        }
        work((x4 - x3 + 1) * (y4 - y3 + 1), judge(x3, y3), -1);

        cout << white << " " << black << endl;
    }
    return 0;
}
