/*
 * Author: xiaohei_AWM
 * Date: 5.24
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<set>
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
int n, m, k, s[maxn];
ll ans, sum, c[maxn], temp[maxn], kth, kthid;
struct Element{
    int id;
    ll val;
    bool operator<(const Element &v)const{
        if(val == v.val)
            return id < v.id;
        return val > v.val;
    }
} a[maxn];
struct Query{
    int l, r, id;
    ll val;
} b[maxn];
inline int lowbit(int x){
    return x & -x;
}
void add(int pos, ll val){
    for(int i = pos; i <= n; i += lowbit(i))
        c[i] += val;
}
ll queryS(int pos){
    ll res = 0;
    for(int i = pos; i; i -= lowbit(i))
        res += c[i];
    return res;
}
bool cmp2(Query u, Query v){
    return u.val > v.val;
}
vector<int>date[maxn*4+5];  //存线段树节点信息
void build(int ro,int l,int r)
{
  if(l == r)
  {
    date[ro].push_back(-1e7);             //乱塞一个数（0号位置）
    date[ro].push_back(s[l]); return;
  }
  int mid = (l+r)>>1;
  build(ro<<1,l,mid);
  build(ro<<1|1,mid+1,r);

  //这一部分类似于归并排序（应该说就是一样的），保证时间复杂度。
  int size1 = date[ro<<1].size()-1;
  int size2 = date[ro<<1|1].size()-1;
  int i = 1,j = 1;
  date[ro].push_back(-1e7);
  while(i<=size1 && j<=size2)
    {
      if(date[ro<<1][i]>date[ro<<1|1][j])date[ro].push_back(date[ro<<1|1][j++]);
      else date[ro].push_back(date[ro<<1][i++]);
    }
  while(i<=size1)date[ro].push_back(date[ro<<1][i++]);
  while(j<=size2)date[ro].push_back(date[ro<<1|1][j++]);
  return;

}

//二分查找完全包含的区间中小于等于R的数的个数
int low_bound(int ro,int target)
{
  int L,R,res;
  L =1 ; R = date[ro].size()-1;res = 0;
  while(L<=R)
    {
      int mid = (L+R)>>1;
      if(date[ro][mid]<=target){res = mid; L = mid + 1;}
      else R = mid - 1;
    }
  return res;
}

//线段树查询区间内小于等于R的数的个数
//tl--target L ;  tr--target R;  l--now L;  r--now R 。
int query(int ro,int l,int r,int tl,int tr,int K)
{
  if(tr<l || tl>r)return 0;   //没有交集
  else if(tl<=l && r<=tr)     //完全包含
    {
      int temp_num = low_bound(ro,K);
      return temp_num;
    }
  else             //有交集但不完全包含，递归查找左右子树
    {
      int mid = (l + r)>>1;
      int temp1 = query(ro<<1,l,mid,tl,tr,K);
      int temp2 = query(ro<<1|1,mid+1,r,tl,tr,K);
      return (temp1+temp2);     //合并答案
    }
}

//二分查找目标值R，二分出值R后再用线段树进行验证
int search(int l,int r,int k)
{
  int L,R,RES,NUM;
  L = 0; R = maxn;
  while(L<=R)
    {
      int mid = (L+R)>>1;
      NUM = query(1,1,n,l,r,mid);  //RES不断向下逼近，保证精确性。
      if(NUM >= k){RES = mid ; R = mid-1;}
      else L = mid+1;
    }
  return RES;
}
bool cmpx(Element x, Element y){
    if(x.val == y.val)
        return x.id < y.id;
    return x.val < y.val;
}
int main(){
    n = read(), m = read(), k = read();
    for(int i = 1; i <= n; i++)
        a[i].val = temp[i] = readll(),
        a[i].id = i;
    sort(a+1, a+1+n, cmpx);
    for(int i = 1; i <= n; i++)
        s[a[i].id] = i;
    build(1, 1, n);
    for(int i = 1; i <= n-m+1; i++){
        a[i].val = search(i, i+m-1, k);
        a[i].id = i;
    }
    int LIM = n-m+1;
    for(int i = 1; i <= n; i++){
        b[i].l = max(1, i - m + 1);
        b[i].r = min(LIM, i);
        b[i].val = s[i];
        b[i].id = i;
    }
    sort(a+1, a+1+LIM);
    sort(b+1, b+1+n, cmp2);
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        while(cnt <= LIM && a[cnt].val >= b[i].val){
            add(a[cnt].id, 1);
            cnt++;
        }
        int num = (queryS(b[i].r) - queryS(b[i].l-1));
        ans += (ll)(queryS(b[i].r) - queryS(b[i].l-1)) * temp[b[i].id];
    }
    cout << ans << endl;
    return 0;
}
