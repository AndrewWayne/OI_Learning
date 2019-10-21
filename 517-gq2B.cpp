/*
 * Author: xiaohei_AWM
 * Date: 10.3
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
#include<string>
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
int t;
string s1, s2;
ll sol = llINF;
string sol1, sol2;
bool match(char key, int x){
    if(key == '?'){return true;}
    else return key == '0' + x;
}
void solve(){
    cin >> s1 >> s2;
    int len = s1.size();
    sol = llINF;
    sol1 = "", sol2 = "";
    bool diff = false;
    for(int i = 0; i < len; i++){//枚举转点
        for(int x = 0; x < 10; x++)
            for(int y = 0; y < 10; y++)
                if(x != y && match(s1[i], x) && match(s2[i], y)){
                    //cerr << x << " " << y << endl;
                    string tmp1 = s1;
                    string tmp2 = s2;
                    tmp1[i] = '0' + x;
                    tmp2[i] = '0' + y;
                    if(x > y){
                        for(int k = 0; k < len; k++){
                            if(tmp1[k] == '?') tmp1[k] = '0';
                            if(tmp2[k] == '?') tmp2[k] = '9';
                        }
                    }else if(x < y){
                        for(int k = 0; k < len; k++){
                            if(tmp1[k] == '?') tmp1[k] = '9';
                            if(tmp2[k] == '?') tmp2[k] = '0';
                        }
                    }
                    //
                    ll ka = stoll(tmp1), kb = stoll(tmp2);
                    //cerr << "##: " << tmp1 << " " << tmp2 << endl;
                    if(abs(ka - kb) < sol)
                        sol = abs(ka - kb), sol1 = tmp1, sol2 = tmp2;
                    else if(abs(ka - kb) == sol){
                        if(tmp1 < sol1) sol1 = tmp1, sol2 = tmp2;
                        else if(tmp1 == sol1 && tmp2 < sol2) sol2 = tmp2;
                    }
                }
        if(s1[i] == '?' && s2[i] == '?') s1[i] = s2[i] = '0';
        else if(s1[i] == '?') s1[i] = s2[i];
        else if(s2[i] == '?') s2[i] = s1[i];
        else if(s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) diff = true;
    }
    if(!diff){
        ll ka = stoll(s1), kb = stoll(s2);
        //cerr << ka << " " << kb << endl;
        if(abs(ka - kb) < sol)
            sol = abs(ka - kb), sol1 = s1, sol2 = s2;
        else if(abs(ka - kb) == sol){
            if(s1 < sol1) sol1 = s1, sol2 = s2;
            else if(s1 == sol1 && s2 < sol2) sol2 = s2;
        }
    }
//    cerr << sol << endl;
    cout << sol1 << " " << sol2 << endl;
}
int main(){
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
