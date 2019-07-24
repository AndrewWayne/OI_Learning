/*
 * Author: xiaohei_AWM
 * Date: 7.14
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>
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
const int maxn = 1e5 + 10;
struct Pair{
    int first, second;
    bool operator<(const Pair &v)const{
        return first < v.first;
    }
};
struct Node{
    int num, pre, nxt;
} table[maxn];
int n, func[maxn], vi[maxn], qu[maxn], top;
priority_queue<Pair> Q;
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        table[i].num = read(), func[table[i].num] = i;
        table[i].pre = i-1, table[i].nxt = i+1;
    }
    Pair temp, temp1;
    for(int i = 1; i <= n-1; i++){
        temp.first = table[i].num;
        temp.second = table[table[i].nxt].num;
        Q.push(temp);
    }
    while(n > 0){
        do{
            temp = Q.top();
            Q.pop();
        }while(vi[temp.first] || vi[temp.second]);
        n -= 2;
        vi[temp.first] = vi[temp.second] = 1;
        qu[++top] = temp.first;
        qu[++top] = temp.second;
        table[table[func[temp.first]].pre].nxt = table[func[temp.second]].nxt;
        table[table[func[temp.second]].nxt].pre = table[func[temp.first]].pre;
        temp1.first = table[table[func[temp.first]].pre].num,
        temp1.second = table[table[func[temp.second]].nxt].num;
        if(temp1.first != 0 && temp1.second != 0)
            Q.push(temp1);
    }
    for(int i = 1; i <= top; i++)
        printf("%d ", qu[i]);
    return 0;
}
/*
6
1 2 3 4 5 6
*/
