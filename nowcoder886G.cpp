/*
 * Author: xiaohei_AWM
 * Date: 8.3
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
int ables[10000][20][32];
int Caile(int y, int m, int d){
    int c = y/100;
    y %= 100;
    if(m == 1) m = 13;
    if(m == 2) m = 14;
    int w = (y + y/4 + c/4 - 2*c + (26 * m+1)/10 + d - 1)%7;
    return w;
}
int main(){
    for(int year = 1; i <= 1600; i++){
        for(int mon = 1; mon <= 12; mon++){
            int lim = 30;
            if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
                lim = 31;
            if(mon == 2){
                if((year%4==0&&year%100!=0)||year%400==0)
                    lim = 29;
                else
                    lim = 28;
            }
            for(int day = 1; day <= lim; day++){
                if(Caile(year, mon, day) == 5){

                }
            }
        }
    }
    return 0;
}
