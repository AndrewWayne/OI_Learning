/*
 * Author: Miao Shenhao
 * Date: 9.19
 * Motto: Face to the weakness, expect for the strength.
*/
#pragma GCC optimize(3, "Ofast", "inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<map>
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
const int MAXN = 10 + 4;//维数
const int N = 200;//总迭代次数
const int L = 100;//退火次数
const db C = 2.0;//两须距离与步长比
const db EPS = 1e-4;
const int maxn = 2e3 + 10;
const db alpha = 0.95;//步长因子
const db STEP = 20000;
struct Beetle{
    db stat[MAXN];
    db step, val;
    int age;
};
Beetle bettles;
int dim, nn, m;//
db sol[MAXN], fminv, sl[MAXN], sr[MAXN], birthnum;
db fleft, fright, Tempr, beta;//beta为退火因子， Tempr为退火温度
db X[MAXN][MAXN], len[maxn];
db temp[MAXN];
int sign(db x){
    if(x < 0.0) return -1;
    else return 1;
}
int rdm(int a, int b){
    return rand() % (b-a+1) + a;
}
db F(db s[]){
    db res = 0;
    for(int i = 1; i <= dim+1; i++){
        db val = 0;
        for(int j = 1; j <= dim+1; j++)
            val += (X[i][j] - s[j]) * (X[i][j] - s[j]);
        temp[i] = sqrt(val);
    }
    sort(temp+1, temp+2+dim);
    for(int i = 2; i <= dim+1; i++) res = temp[i] - temp[i-1];
    return res;
}
void RAND(db A[]){
    db len = 0;
    for(int i = 1; i <= dim; i++)
        *(A+i) = rdm(-100, 100), len += abs(*(A+i));
    for(int i = 1; i <= dim; i++)
        *(A+i) /= len;
}
double Time(){return (double)clock()/CLOCKS_PER_SEC;}
void SABAS(){
    bettles.val = 2147483647.0;
    bettles.step = STEP;
    beta = alpha;
    for(int i = 1; i <= dim; i++)
        bettles.stat[i] = sol[i] + rdm(-100, 100) / 100.0;
    Tempr = STEP;
    for(int i = 1; i <= N && Time() < 0.8; i++){
        bettles.step = Tempr;
        for(int j = 1; j <= L; j++){
            if(bettles.step <= EPS) break;
            db b[MAXN];
            RAND(b);
            bettles.step = alpha * bettles.step;
            db step = bettles.step;
            db d = step/C;
            bool BeyondDim = false;
            RAND(b);
            for(int k = 1; k <= dim; k++){
                sl[k] = bettles.stat[k] + d * b[k] / C;
                sr[k] = bettles.stat[k] - d * b[k] / 2.0;
                if(abs(sr[k]) > 20000.0 || abs(sl[k]) > 20000.0){//修改函数定义域
                    BeyondDim = true;
                    break;
                }
            }
            if(BeyondDim) continue;
            fleft = F(sl);
            fright = F(sr);
            for(int k = 1; k <= dim; k++){
                temp[k] = bettles.stat[k] - step * b[k] * sign(fleft - fright);
                if(abs(temp[k]) > 20000.0){//函数定义域
                    BeyondDim = true;
                    break;
                }
            }
            if(BeyondDim) continue;
            db deltaT = fleft - bettles.val;
            if(deltaT < 0){
                for(int k = 1; k <= dim; k++){
                    bettles.stat[k] = temp[k];
                }
                fleft = min(fleft, fright);
                bettles.val = fleft;
            }else{
                db p = exp(-deltaT/Tempr);
                if(rdm(1, 10000)/10000 <= p){
                    for(int k = 1; k <= dim; k++){
                        bettles.stat[k] = temp[k];
                    }
                    fleft = min(fleft, fright);
                    bettles.val = fleft;
                }
            }
        }
        if(bettles.val <= fminv){
            fminv = bettles.val;
            memcpy(sol, bettles.stat, sizeof(sol));
            beta = alpha;
        }else{
            beta = alpha - 0.2 * ((i + 1) / (5 * N) + 0.5);
        }
        Tempr *= beta;

        cerr << fminv << endl;
    }

}
int main(){
    //freopen("fagttering17.in", "r", stdin);
    srand(time(0));
    scanf("%d", &dim);
    for(int i = 1; i <= dim+1; i++)
        for(int j = 1; j <= dim+1; j++)
            scanf("%lf", &X[i][j]);
    fminv = 2147483647;
    while(Time() < 0.8){
        SABAS();
    }
    printf("%.3f\n", fminv);
    for(int i = 1; i <= dim; i++){
        printf("%.3f ", sol[i]);
    }
    //for(int i = 1; i <= n; i++)
    //    cout << sol[i] << " ";
    return 0;
}
