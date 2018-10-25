#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define type int//看情况修改返回类型
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}//黑箱

int n, m, map[550][550], ans;
int r[550], source[550][550];
int top[550];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visit[550][550];
struct Node{
    int x, y, height;
} queue[250010];
int head, tail;
void push(int x,int y,int id){
    if(visit[ x ][ y ] || x < 1 || x > n || y < 1 || y > m)
        return;
    visit[ x ][ y ] = true;
    queue[ ++tail ].x = x;
    queue[ tail ].y = y;
    queue[ tail ].height = map[ x ][ y ];
    if( x == n ){
        source[ y ][ ++top[y] ] = id;
        r[ id ] = max( r[ id ], y);
    }
}
void init(){
    memset(visit, 0, sizeof(visit));
    head = tail = 0;
}
void bfs(int x, int y){
    init();
    int t_x, t_y, t_height;
    push(x, y, y);
    do{
        head++;
        t_height = queue[ head ].height;
        t_x = queue[ head ].x;
        t_y = queue[ head ].y;
        for(int p = 0; p <= 3; p++){
            if( map[ t_x + dx[p] ][ t_y + dy[p] ] < t_height )
                push( t_x + dx[p], t_y + dy[p], y);
        }
    }while(head < tail);
}
bool cmp(int x, int y){
    return r[x] < r[y];
}
int main(){
    n = read();
    m = read();
    for( int i = 1; i <=  n; i++)
        for (int j = 1; j <= m; j++)
            map[ i ][ j ] = read();

    for(int i = 1; i <= m; i++){
        if( visit[ 1 ][ i ] )
            continue;
        bfs( 1, i );// bfs 获取每个点造蓄水厂后能覆盖哪几个沙漠城市
    }

    for(int i = 1; i <= m; i++)
        if( top[i] == 0 )
            ans++;//做不可行的情况

    if( ans != 0 ){
        printf("%d\n%d", 0, ans);
        return 0;
    }
    ans = 0;
    //很粗暴的线段合并
    int i = 1;
    while( i <= m ){
        sort( source[ i ] + 1, source[ i ] + 1 + top[ i ], cmp );
        //每个干旱城市开一个栈，每个栈中按照可以通到这个城市的蓄水站的蔓延线段右端点的大小排序（虽然好像可以每个d点开一个堆更优）；
        ans++;
        i = r[ source[ i ][ top[i] ] ] + 1;
    }
    printf("%d\n%d", 1, ans);
    return 0;
}
