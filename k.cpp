#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void init() {ios::sync_with_stdio(0);}
ll a, b, c, d, la = 0;
vector <int> v;
const long double eps = 1e-6;
bool find(ll l, ll r, ll ql, ll qr) {
  //cout << l << " " << r << " " << ql << " " << qr << endl;
  //la++;
  //if(la > 5) return 0;
  if(!(l <= ql && qr <= r) || ql > qr) return 0;
  if(l == ql && r == qr) return 1;
  ll mid = (l + r) >> 1;
  if(mid * 2 != (l + r)) return 0;
  if(!((ql <= mid && qr <= mid) || (ql >= mid && qr >= mid))) return 0;

  ql >= mid ? v.push_back(1) : v.push_back(0);
  bool fd = (ql >= mid && qr >= mid) ? find(mid, r, ql, qr) : find(l, mid, ql, qr);
  return fd;
}
int main() {
  init();
  ll q; cin >> q;
  while(q--) {
    la = 0;
    cin >> a >> b >> c >> d;
    int Op = 0;
    v.clear();
    swap(c, a); swap(d, b);
    if(a > b) swap(a, b), swap(c, d), Op = 1 - Op;
    bool flg = find(a, b, c, d);
    if(!flg) puts("No");
    else {
      puts("Yes");
      //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
      //cout << endl;
      reverse(v.begin(), v.end());
      for(int i = 0; i < v.size(); i++) putchar('A' + ((Op == 0) ? v[i] : (1 - v[i])));
      puts("");
    }
  }
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
void init() {ios::sync_with_stdio(0);}
int main() {
  init();

  return 0;
}
 */
