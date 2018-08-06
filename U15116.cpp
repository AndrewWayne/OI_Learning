#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#define max(a,b) a>b?a:b
using namespace std;
const int maxm=1e6+10;
const int maxn=1e6+10;
struct node{
  int val,num;
}func[maxn];
int n,ans;
map<int int> ans;
char a[maxm];
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%s",a);
    int len=strlen(a);
    int temp=0;
    int val=0;
    for(int j=0;j<len;j++){
      if(a[j]=='s')
        temp++;
      if(a[j]=='c')
        temp--;
      if(temp==0)
        val++;
    }
    func[i].val=val;
    func[i].num=temp;
  }
  for(int i=1;i<=n;i++){
    ans[0]=max(ans[0],ans[0-func[i].num]+func[i].val);
    int *k=&ans[func[i].num];
    *k=max(*k,func[i].val);
  }
  cout<<ans[0];
  return 0;
}
