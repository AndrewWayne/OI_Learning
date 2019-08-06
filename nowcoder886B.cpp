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
int t, b[40];
char func[16] = "0123456789abcde";
string a;
void print(int x[40]){
    for(int i = 1; i <= 7; i++){
        printf("%c%c%c%c:", func[x[4*i-3]], func[x[4*i-2]], func[x[4*i-1]], func[x[4*i]]);
    }
    printf("%c%c%c%c\n", func[x[32-3]], func[x[32-2]], func[x[32-1]], func[x[32]]);
}
int main(){
    cin >> t;
    while(t--){
        cin >> a;
        int len = a.size();
        for(int i = 1; i <= 32; i++){
            for(int j = 4; j >= 1; j--)
                b[i] += (a[i*4 - j] - '0') << (j-1);
        }

        print(b);
    }
    return 0;
}
