/*
 * Author: xiaohei_AWM
 * Date: 7.13
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<queue>
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
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
const int maxn = 1e3 + 10;
int n, x, y, a, b, ans;
bool pat[maxn][maxn];
int dx[maxn] = {1, -1, 0, 0};
int dy[maxn] = {0, 0, 1, -1};
struct Node{
    int pre, x, y, v;
    bool operator<(const Node &n1)const{
        return v > n1.v;
    }
};
queue<Node> Q;
inline int calc(int _x, int _y){
    return abs(x - _x) + abs(y - _y);
}
void bfs(int sx, int sy){
    Node temp = {0, sx, sy, calc(sx, sy)};
    Q.push(temp);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp.x == x && temp.y == y){
            ans = temp.pre;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = temp.x + dx[i], ny = temp.y + dy[i];
            if(pat[nx][ny] || nx < 0 || ny < 0 || nx > 1003 || ny > 1003) continue;
            pat[nx][ny] = 1;
            Node s = {temp.pre + 1, nx, ny, calc(nx, ny)};
            Q.push(s);
        }
    }
}
int main(){
    x = read(), y = read(), n = read();
    x += 501, y += 501;
    for(int i = 1; i <= n; i++){
        a = read(), b = read();
        a += 501, b += 501;
        pat[a][b] = 1;
    }
    bfs(501, 501);
    cout << ans << endl;
    return 0;
}
