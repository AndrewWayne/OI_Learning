/*
 * Author: xiaohei_AWM
 * Date:5.3
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
struct Rectangle{
    int x1, x2, y1, y2;
    Rectangle(){}
    Rectangle(int x, int y, int p){
        x1 = x-p;
        x2 = x+p;
        y1 = y-p;
        y2 = y+p;
    }
};
int n, x, y, p;
ll ans = 0;
int main(){
    n = read();
    x = read(), y = read(), p = read();
    Rectangle S(x, y, p);
    for(int i = 1; i < n; i++){
        x = read(), y = read(), p = read();
        Rectangle A(x, y, p);
        int D = max(max(A.x1 - S.x2, S.x1 - A.x2), max(A.y1 - S.y2, S.y1 - A.y2));
        if(D < 0)
            D = 0;
        ans += D;
        S.x1 -= D;
        S.x2 += D;
        S.y1 -= D;
        S.y2 += D;
        Rectangle Part;
        Part.x1 = max(S.x1, A.x1);
        Part.x2 = min(S.x2, A.x2);
        Part.y1 = max(S.y1, A.y1);
        Part.y2 = min(S.y2, A.y2);//慢慢移动
        S = Part;
    }
    cout << ans;
    return 0;
}
