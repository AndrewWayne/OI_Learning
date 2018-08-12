#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,line;
struct student{
  int id,score;
  bool operator<(const student &v){
    if(score==v.score)return id<v.id;
    return score>v.score;
  }
}man[5050];
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>man[i].id>>man[i].score;
  sort(man+1,man+1+n);
  line=floor(m*3/2);
  while(man[line+1].score==man[line])line++;
  cout<<man[line].score<<" "<<line<<endl;
  for(int i=1;i<=line;i++)
    cout<<man[i].id<<" "man[i].score<<endl;
  return 0;
}
