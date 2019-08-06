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
#include<string>
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
int t, cnt, num[3];
string a, b;
int main(){
    cin >> t;
    while(t--){
        cnt++;
        cin >> a;
        int sum = a.size();
        cin >> b;
        num[0] = num[1] = num[2] = 0;
        for(int i = 0; i < sum; i++){
            if(b[(a[i]-'a')] == 'd') num[0]++;
            if(b[(a[i]-'a')] == 'w') num[1]++;
            if(b[(a[i]-'a')] == 'h') num[2]++;
        }
        if(4*num[2] >= sum) printf("Case #%d: Harmful\n", cnt);
        else if(10*num[2] <= sum) printf("Case #%d: Recyclable\n", cnt);
        else if(num[0] >= 2*num[1]) printf("Case #%d: Dry\n", cnt);
        else printf("Case #%d: Wet\n", cnt);
    }
    return 0;
}
