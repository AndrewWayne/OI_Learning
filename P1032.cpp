#include <string>
#include <cstdio>
#include <iostream>
#include <map>
using namspace std;
string a,b,a1,b1;
struct edge{
  string u,v;
} e[7];
int top;
map<string,bool> ma;
struct{
  string str,int f;
} queue[1000],h=t=0;
int main(){
  cin>>a>>b;
  while(cin>>a1>>b1){
    e[++top].u=a1;
    e[top].v=b1;
  }
  queue[++t]=a;
  ma[a]=true;
  while(h<=t){
    h++;
    string cur;
    int f=queue[h].f;
    for(int i=1;i<=top;i++){
      cur=queue[h].str;
      cur.replace(cur.find(e[i].u),e[i].u.size(),e[i].u);
      if(!ma[cur]){
        queue[++t].str=cur;
        queue[t].f=f+1;
        if(cur==b&&f>9){
          printf("NO ANSWER!");
          return 0;
        }
        if(cur==b){
          printf("%d",f+1);
          return 0;
        }
        ma[cur]=true;
      }
    }
    printf("NO ANSWER!");
  }
}
