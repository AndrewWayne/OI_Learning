#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
string devide(int tmp){
    int i=0;
    string s=string("");
    if(tmp==0)
      return "0";
    do
      if(temp&1)s=(i==1?"2":"2("+run(i)+")")+(s==""?"":"+")+s;
    while(i++,tmp>>=1);
    return s;
}
int main(){
    cin>>n;
    cout<<devide(n)<<endl;
    return 0;
}
