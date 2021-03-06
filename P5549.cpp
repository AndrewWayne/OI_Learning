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
const int N = 300;//总迭代次数
const int L = 120;//退火次数
const db M = 3.0;//退火幂次
const db C = 2;//两须距离与步长比
const db EPS = 5e-7;
const int maxn = 2e3 + 10;
db alpha = 0.78;//步长因子
const db STEP = 14140;
struct Beetle{
    db stat[MAXN];
    db step, val;
    int age;
};
Beetle bettles;
int dim, n, m;//
db sol[MAXN], fminv, sl[MAXN], sr[MAXN];
db fleft, fright, Tempr;// Tempr为退火温度
db X[maxn], Y[maxn], len[maxn];
db temp[MAXN], timelim;
int kkkk;
db beta;// 退火因子
int sign(db x){
    if(x < 0.0) return -1;
    else return 1;
}
int rdm(int a, int b){
    return rand() % (b-a+1) + a;
}
db F(db s[]){
    db res = 0;
    for(int i = 1; i <= n; i++){
        len[i] = (X[i] - s[1]) * (X[i] - s[1]) + (Y[i] - s[2]) * (Y[i] - s[2]);
    }
    sort(len+1, len+1+n);
    return sqrt(len[m]);
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
    int cnt = 1;
    bettles.val =  2147483647;
    bettles.step = STEP;
    beta = alpha;
    for(int i = 1; i <= dim; i++)
        bettles.stat[i] = sol[i] + rdm(-100, 100) / 100.0;
    Tempr = STEP*10;
    for(int i = 1; i <= N && Time() < timelim*kkkk; i++){
        bettles.step = Tempr/10;
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
                if(abs(sr[k]) > 10000.0 || abs(sl[k]) > 10000.0){//修改函数定义域
                    BeyondDim = true;
                    break;
                }
            }
            if(BeyondDim) continue;
            fleft = F(sl);
            fright = F(sr);
            for(int k = 1; k <= dim; k++){
                temp[k] = bettles.stat[k] - step * b[k] * sign(fleft - fright);
                if(abs(temp[k]) > 10000.0){//函数定义域
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
            beta = alpha - 0.3 * ((i + 1) / (5 * N) + 0.5);
        }
        if(abs(bettles.val - fminv) <= 2*EPS)
            cnt++;
        else if(bettles.val < fminv) cnt = 1;
        if(cnt >= 9) break;
        Tempr *= beta;
        //cerr << fminv << endl;
    }

}
int main(){
    freopen("fagttering17.in", "r", stdin);
//    beta[1] = alpha;
//    for(int i = 2; i <= 300; i++)
//        beta[i] = pow((db)(i-1)/i, M);
    srand(time(0));
    dim = 2;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &X[i], &Y[i]);
    //db ACRate = 0;
    //for(int i = 1; i <= 10; i++){
        fminv = 2147483647;
        if(n <= 50) timelim = 0.8, alpha = 0.88;
        else if(n <= 500) timelim = 2.8, alpha = 0.85;
        else timelim = 2.8, alpha = 0.75;
        kkkk = 1;
        //kkkk = i;
        while(Time() < timelim*kkkk){
            SABAS();
        }
        printf("%.8f\n", fminv);
        //if(abs(fminv - 98.05724505) <= 1e-6) ACRate += 1.0;
    //}
    //ACRate /= 10.0;
    //printf("ACRate: %f\n", ACRate);
    //for(int i = 1; i <= n; i++)
    //    cout << sol[i] << " ";
    return 0;
}
