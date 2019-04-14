/*
 *Author: xiaohei_AWM
 *Date:
 *Mutto: Face to the weakness, expect for the strength.
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
const int maxn = 3e5 + 10;
int n, num[maxn], k;
char s[maxn];
int main(){
    cin >> n;
    cin >> s;
    if(n & 1){
        cout << ":(" << endl;
        return 0;
    }
    k = (n-2)/2;
    if(s[0] == ')'){
        cout << ":(" << endl;
        return 0;
    }
    s[0] = '(';
    if(s[n-1] == '('){
        cout << ":(" << endl;
        return 0;
    }
    s[n-1] = ')';
    for(int i = 1; i < n-1; i++){
        if(s[i] == '(')
            k--;
    }
    if(k < 0){
        cout << ":(" << endl;
        return 0;
    }
    int i = 1;
    for(i = 1; i < n-1 && k > 0; i++){
        if(s[i] == '?')
            s[i] = '(',
            k--;
    }
    for(i; i < n-1; i++){
        if(s[i] == '?')
            s[i] = ')';
    }
    k = 0;
    for(int i = 1; i < n-1; i++){
        if(s[i] == '(')
            k++;
        if(s[i] == ')')
            k--;
        if(k < 0){
            cout << ":(" << endl;
            return 0;
        }
    }
    if(k > 0)
        cout << ":(" << endl;
    else
        cout << s << endl;
    return 0;
}
