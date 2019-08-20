/*
 * Author: xiaohei_AWM
 * Date: 8.16
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
const int maxn = 10;
const int factorial[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};//阶乘0-10
int n, k, a[maxn], b[maxn], idt = 0, ans;
bool visit[462880], tagged[462880];
int cantor(int a[], int n){//cantor展开,n表示是n位的全排列，a[]表示全排列的数（用数组表示）
    int ans = 0,sum = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++)
            if(a[j] < a[i])
                sum++;
        ans += sum * factorial[n-i];//累积
        sum = 0;//计数器归零
    }
    return ans + 1;
}
bool check(){
    for(int i = 1; i <= n; i++)
        if(a[i] != b[i]) return false;
    return true;
}
int dfs(int depth){
    bool ok = false;
    if(check()){
        //int key = cantor(a, n);
        //cout << key << endl;
        return 1;
    }
    if(depth >= idt) return -1;
    int key = cantor(a, n);
    int key1 = 0;
    visit[key] = true;
    for(int i = 1; i <= n-k+1; i++){
        reverse(a+i, a+i+k);
        key1 = cantor(a, n);
        if(!visit[key1] && !tagged[key1]){
            int val = dfs(depth+1);
            if(val != 0) ok = 1;
            if(val == 1)
                return 1;
            //cerr << key1 << ": " << ok << endl;
            visit[key1] = false;
        }
        reverse(a+i, a+i+k);
    }

    if(!ok){ tagged[key] = 1; return 0;}
    return -1;
}
int main(){
    n = read();
    for(int i = 1; i <= n; i++)
        b[i] = read(), a[i] = i;
    k = read();
    while(idt <= 1){
        memset(visit, 0, sizeof(visit));
        if(dfs(0) == 1){
            cout << idt << endl;
            return 0;
        }
        ++idt;
    }
    cout << -1 << endl;
    return 0;
}
