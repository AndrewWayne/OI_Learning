/*
 * Author: xiaohei_AWM
 * Date:5.20
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
const int maxn = 1e6 + 10;
int n, m, a[maxn];
pii ANS[maxn];
int main(){
    freopen("data.in", "w", stdout);
    //cin >> n;
    srand(time(0));
    srand(rand());
    srand(rand());
    //for(int K = 1; K <= 10; K++){
    puts("10000 3000");
    n = 5000;
    /*造树
    for(int i = 1; i <= n; i++)
        a[i] = i;
    random_shuffle(a+1, a+1+n);
    for(int i = 2; i <= n; i++)
        ANS[i-1].first = a[rand()%(i-1) + 1], ANS[i-1].second = a[i];
    random_shuffle(ANS+1, ANS+n);
    //*/

    //*造链
    for(int i = 1; i < n; i++)
        ANS[i].first = i, ANS[i].second = i+1;
    //*/
    for(int i = 1; i < n; i++)
        printf("%d %d\n", ANS[i].first-1, ANS[i].second-1);

    for(int i = 1; i <= n; i++){
        printf("%d %d\n", 300, n+i-1);
    }
    //, rand() % 10 + 1 ->边权
    //}
    puts("0 0");
    return 0;
}
