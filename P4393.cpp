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
const int maxn = 1e6 + 10;
struct Pair{
    int first, second;
    int fid, sid;
    int maxv(){
        return max(first, second);
    }
    int mid(){
        if(first > second) return sid;
        else return fid;
    }
    bool operator<(const Pair &v)const{
        return max(first, second) > max(v.first, v.second);
    }
};
struct Node{
    int num, id, pre, nxt;
} table[maxn];
int n, func[maxn], vi[maxn];
ll ans;
priority_queue<Pair> Q;
int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        table[i].num = read(), table[i].id = i;
        table[i].pre = i-1, table[i].nxt = i+1;
    }
    Pair temp, temp1;
    for(int i = 1; i <= n-1; i++){
        temp.first = table[i].num;
        temp.fid = i;
        temp.second = table[table[i].nxt].num;
        temp.sid = i+1;
        Q.push(temp);
    }
    while(n > 1){
        do{
            temp = Q.top();
            Q.pop();
        }while(vi[temp.fid] || vi[temp.sid]);
        n -= 1;
        vi[temp.mid()] = 1;
        ans = ans + temp.maxv();
        table[table[temp.mid()].pre].nxt = table[temp.mid()].nxt;
        table[table[temp.mid()].nxt].pre = table[temp.mid()].pre;
        temp1.first = table[table[temp.mid()].pre].num,
        temp1.second = table[table[temp.mid()].nxt].num;
        temp1.fid = table[temp.mid()].pre;
        temp1.sid = table[temp.mid()].nxt;
        if(temp1.first != 0 && temp1.second != 0)
            Q.push(temp1);
    }
    cout << ans << endl;
    return 0;
}
/*
6
1 2 3 4 5 6
*/
