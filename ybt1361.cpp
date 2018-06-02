#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
string n;
int k,can[11][11];
int main(){
  memset(can,0,sizeof(can));
  cin>>n>>k;
  int x,y;
  while(k--){
    cin>>x>>y;
    can[x][y]=1;//rules from x to y
  }
  for(int h=0;h<10;h++)
    for(int j=0;j<10;j++)
      for(int i=0;i<10;i++)
        if(i!=j&&j!=h&&i!=h&&can[h][j]&&can[i][h])can[i][j]=1;
  long long sum=1;
  for(int i=0;i<n.length();i++){
    int n1=n[i]-'0',change=1;
    for(int j=0;j<10;j++)
      if(can[n1][j]&&n1!=j)change++;
    sum*=change;
  }
  cout<<sum;
}
