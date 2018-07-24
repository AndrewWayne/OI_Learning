#include <cstdio>
#include <iostream>
#include <map>
#define swap(a,b) a^=b^=a^=b;
using namespace std;
int h,t;
bool flag=false;
int goal[10]={0,1,2,3,8,0,4,7,6,5};
struct node{
  int pos,f,table[10];
} chess[10086];
map<int*,int> ma;
int read(){
  char temp=getchar();
  if(temp>='0'&&temp<='8')
    return temp-'0';
  else return;
}
void right(int* tab,int pos,int f){
  swap(tab[pos],tab[pos+1]);
  if(ma[tab]!=233){
    chess[++t].table=tab;
    chess[t].pos=pos+1;
    chess[t].f=f+1;
    ma[tab]=233;
    flag=judge(tab,goal);
  }
}
void up(int* tab,int pos,int f){
  swap(tab[pos],tab[pos-3]);
  if(ma[tab]!=233){
    chess[++t].table=tab;
    chess[t].pos=pos-3;
    chess[t].f=f+1;
    ma[tab]=233;
    flag=judge(tab,goal);
  }
}
void down(int* tab,int pos,int f){
  swap(tab[pos],tab[pos+3]);
  if(ma[tab]!=233){
    chess[++t].table=tab;
    chess[t].pos=pos+3;
    chess[t].f=f+1;
    ma[tab]=233;
    flag=judge(tab,goal);
  }
}
void left(int* tab,int pos,int f){
  swap(tab[pos],tab[pos-1]);
  if(ma[tab]!=233){
    chess[++t].table=tab;
    chess[t].pos=pos-1;
    chess[t].f=f+1;
    ma[tab]=233;
    flag=judge(tab,goal);
  }
}
bool judge(int* a,int* b){
  bool temp=true;
  for(int i=1;i<=9)
    temp&=a[i]==b[i];
  return temp;
}
int main(){
  h=t=0;
  t++;
  for(int i=1;i<=9;i++){
    chess[t].table[i]=read();
    if(chess[t].table[i]==0)
      chess[t].pos[i]=i;
  }
  chess[t].f=0;
  ma[chess[t].table]=233;
  while(h<=t){
    h++;
    int tab[10];
    for(int i=1;i<=9;i++)
      tab[i]=chess[h].table[i];
    int f=chess[h].f;
    int pos=chess[h].pos;
    switch (pos%3) {
      case 1:
        right(tab,pos,f);
        if(pos-3>0)
          up(tab,pos,f);
        if(pos+3<10)
          down(tab,pos,f);
        break;
      case 2:
        right(tab,pos,f);
        left(tab,pos,f);
        if(pos-3>0)
          up(tab,pos,f);
        if(pos+3<10)
          down(tab,pos,f);
        break;
      case 3:
        left(tab,pos,f);
        if(pos-3>0)
          up(tab,pos,f);
        if(pos+3<10)
          down(tab,pos,f);
        break;
      case :
        break;
    }
    if(flag){
      printf("%d",f+1);
      return 0;
    }
  }
}
