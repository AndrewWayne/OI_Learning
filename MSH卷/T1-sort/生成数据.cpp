#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
bool used[1000001];
map<double,bool>owo;
int n,pos;
double source[1000001],temp;
int main(){
    srand((unsigned)time(NULL));
    freopen("sort.in","w",stdout);
    n=rand()%100000+1;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
      temp=(double)(rand()%10000001)/1000;
      while(owo[temp]==true)
        temp=(double)(rand()%10000001)/1000;
      owo[temp]=true;
      source[i]=temp;
      cout<<temp<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
      pos=rand()%n+1;
      while(used[pos])
        pos=rand()%n+1;
      used[pos]=true;
      cout<<source[pos]<<" ";
    }
    return 0;
}
