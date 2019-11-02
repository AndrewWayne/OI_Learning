/*
 * Author: xiaohei_AWM
 * Date: 11.2
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
const int maxn = 3e5 + 10;
int n, ans[maxn], num[maxn], cnt[maxn], x;
vector<int> obj;
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        x = read(), cnt[x]++;
    }
    x = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] > 0) obj.push_back(cnt[i]), x++;
    }
    //for(int i = 0; i < x; i++)
    //    cerr << obj[i] << " ";
    //cerr << endl;
    for(int k = 1; k <= n; k++){
        ans[k] = INF;
        //memset(num, 0, sizoef(num));
        for(int j = 0; j < x; j++){
            int pos = 0, val = INF;
            for(int i = 1; i <= k; i++)
                if(num[i] < val) val = num[i], pos = i;
            num[pos] += obj[j];
        }
        for(int i = 1; i <= k; i++){
            //cerr << num[i] << " ";
            ans[k] = min(ans[k], num[i]);
            num[i] = 0;
        }
        //cerr << endl;
        printf("%d ", ans[k]);
    }
    return 0;
}
