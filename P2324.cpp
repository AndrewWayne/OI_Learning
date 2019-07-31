/*
 * Author: xiaohei_AWM
 * Date:
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
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
const int dy[8] = {2, -2, -2, 2, 1, -1, -1, 1};
int n, idt;
char t[7][7] = {
    "000000",
    "011111",
    "001111",
    "000*11",
    "000001",
    "000000"
};
char a[7][7], t2[7][7];
int h(){
    int step = 0;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++){
            step += (a[i][j] != t2[i][j]);
        }
    return step;
}
bool check(int x, int y){
    return x >= 1 && x <= 5 && y >= 1 && y <= 5;
}
bool dfs(int dep, int x, int y){
    if(h() + dep > idt+1) return false;
    if(h() == 0) return true;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(check(nx, ny)){
            swap(t2[x][y], t2[nx][ny]);
            if(dfs(dep+1, nx, ny)) return true;
            swap(t2[x][y], t2[nx][ny]);
        }
    }
    return false;
}
int main(){
    scanf("%d", &n);
    while(n--){
        memset(a, 0, sizeof(a));
        memcpy(t2, t, sizeof(t2));
        for(int i = 1; i <= 5; i++)
            scanf("%s", a[i]+1);
        for(int i = 0; i <= 15; i++){
            idt = i;
            if(dfs(0, 3, 3)){
                printf("%d\n", i);
                break;
            }
            if(idt == 15) idt = 16;
        }
        if(idt == 16)
            printf("-1\n");
    }
    return 0;
}
