/*
 * Author: xiaohei_AWM
 * Date: 7.18
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
char mat[10][10];
int row[9], col[9], grid[9], cnt[512], num[512], tot;
inline int lowbit(int x){
    return x&-x;
}
int main(){
    for(int i = 1; i < (1 << 9); i++)
        for(int j = i; j; j -= lowbit(j))
            cnt[i]++;//统计i内1的个数

    for(int i = 0; i < 9; i++)
        num[1 << i] = i;

    char s[100];
    while(~scanf("%s", s) && s[0] != 'e'){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) str[i][j] = s[i*9 + j];//一维变二维
        for(int i = 0; i < 9; i++)
            row[i] = col[i] =
    }
    return 0;
}
