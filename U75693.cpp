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
const int maxl = 2000;
int n, l;
bool mat[maxl][maxl];
void SM(int sx, int sy, int tx, int ty, int pw){
    if(sx == tx && ty == sy){
        mat[sx][sy] = pw;
        return;
    }
    int mx = (sx+tx)>>1, my = (sy+ty)>>1;
    if(pw == 0){
        SM(sx, sy, mx, my, 0);
        SM(sx, my+1, mx, ty, 0);
        SM(mx+1, sy, tx, my, 0);
        SM(mx+1, my+1, tx, ty, 0);
    }else{
        SM(sx, sy, mx, my, 0);
        SM(sx, my+1, mx, ty, 1);
        SM(mx+1, sy, tx, my, 1);
        SM(mx+1, my+1, tx, ty, 1);
    }
}
int main(){
    n = read();
    l = 1 << n;
    memset(mat, 0xff, sizeof(mat));
    SM(1, 1, l, l, 1);
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= l; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}
