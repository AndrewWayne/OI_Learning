/*
 * Author: xiaohei_AWM
 * Date: 9.13
 * Motto: Face to the weakness, expect for the strength.
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
typedef long double db;
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
const db eps = 1e-7;
/*
ll mul(ll a, ll b, ll p){
    asm(
        "mul %%ebx\n"
        "div %%ecx"
        : "=d"(a)
        : "a"(a), "b"(b), "c"(p)
    );
    return a;
}
*/
const int maxn = 62555;
int t, n, top, top2;
db p, w[maxn], h[maxn], maxl[maxn], minl[maxn];
pair<db,db> sege[maxn], sege1[2][maxn];
int main(){
    freopen("c.in", "r", stdin);
    scanf("%d", &t);
    for(int kkk = 1; kkk <= t; kkk++){
        top2 = top = 0;
        scanf("%d%Lf", &n, &p);
        db pp = p;
        for(int i = 1; i <= n; i++){
            scanf("%Lf%Lf", &w[i], &h[i]);
            pp -= w[i]*2 + h[i]*2;
            minl[i] = min(w[i], h[i]);
            maxl[i] = sqrt(w[i]*w[i] + h[i]*h[i]);
            sege[i].first = minl[i]*2, sege[i].second = maxl[i]*2;
        }
        if(pp <= eps){
            printf("Case #%d: %.6Lf\n", kkk, p);
            continue;
        }
        sort(sege+1, sege+1+n);

        //cerr << sege1[0][1].first << " " << sege1[0][1].second << endl;
        for(int i = 1; i <= n; i++){
            int lim = top;
            for(int j = 0; j <= lim; j++){
                sege1[0][++top].first = sege1[0][j].first + sege[i].first,
                sege1[0][top].second = sege1[0][j].second + sege[i].second;
                //cerr << sege1[0][top].first << " " << sege1[0][top].second << endl;
            }
            sort(sege1[0]+1, sege1[0]+1+top);
            //cerr << "kkk" << endl;
            for(int j = 1; j <= top; j++){
                if(sege1[0][j].first > sege1[1][top2].second){
                    sege1[1][++top2].first = sege1[0][j].first;
                    sege1[1][top2].second = sege1[0][j].second;

                }else
                    sege1[1][top2].second = max(sege1[1][top2].second, sege1[0][j].second);
                sege1[0][top2].first = sege1[1][top2].first;
                sege1[0][top2].second = sege1[1][top2].second;
            }
            top = top2, top2 = 0;
        }
        //cerr << pp << endl;
        bool outputed = 0;
        for(int i = 1; i <= top; i++){
            //cerr << sege1[0][i].first << " " << sege1[0][i].second << endl;
            //cerr << pp << endl;
            if(pp - sege1[0][i].first >= -eps && sege1[0][i].second - pp >= -eps){
                //cout << kkk << endl;
                printf("Case #%d: %.6Lf\n", kkk, p);
                outputed = 1;
                break;
            }
            if(sege1[0][i].first - pp >= 0){
                //cout << kkk << endl;
                printf("Case #%d: %.6Lf\n", kkk, p - (pp - sege1[0][i-1].second));
                outputed = 1;
                break;
            }
        }
        if(!outputed)
            printf("Case #%d: %.6Lf\n", kkk, p - (pp - sege1[0][top].second));
    }
    return 0;
}
