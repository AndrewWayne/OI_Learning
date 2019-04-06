//It's supposed to die.
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
const int maxn = 520;
const int MOD[3] = {(int)1e9 + 7, 1111151, (int)1e8 + 7};
int n, m, x, sum, a[maxn][maxn], b[maxn][maxn];
bool check(ll a[3],ll b[3]){
    for(int i = 0; i < 3; i++)
        if(a[i] != b[i])
            return false;
    return true;
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> b[i][j];
    for(int i = 1; i <= n-1; i++)
        for(int j = 1; j <= m-1; j++){
            if(a[i][j] != b[i][j])
                a[i][j] ^= 1,
                a[i][j+1] ^= 1,
                a[i+1][j] ^= 1,
                a[i+1][j+1] ^= 1;
        }
    for(int i = 1; i <= n; i++){
        if(a[i][m] != b[i][m]){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 1; i <= m; i++){
        if(a[n][i] != b[n][i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
