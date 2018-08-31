//下面的代码xjb搞0分
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#define vi vector<int>
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return sum;
}
struct node{
  vi stat;
  int f;
  vector<char>output[3];
}queue1[2500],queue2[2500];
int n,num,temp,h1,t1,h2,t2;
map<vi,int>ma;
vi begin_stat,end_stat;
int main(){
  n=read();
  for(int k = 1; k <= 3 ; k++ ){
    num=read();
    for(int i = 1; i <= num ; i++ ){
      temp=read();
      begin_stat.push_back(temp);
    }
    begin_stat.push_back(-1);
  }
  return 0;
}
