#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
char table[300],ch;
bool func[300];
//65-90,97-122
int produce(){
  int p=rand()%58+65;
  while(func[p]||(p>90&&p<97))p=rand()%58+65;
  func[p]=true;
  return p;
}
int main(){
    freopen("1.cpp","r",stdin);
    freopen("0.cpp","w",stdout);
    srand((unsigned)time(NULL));
    for(int i=1;i<=270;i++)
        table[i]=i;
    for(int i=65;i<=90;i++)
        table[i]=produce();
    for(int i=97;i<=122;i++)
        table[i]=produce();
    for(int i=65;i<=90;i++)
        printf("#define %c %c\n",table[i],i);
    for(int i=97;i<=122;i++)
        printf("#define %c %c\n",table[i],i);
    cout<<endl;
    while(ch=getchar()){
        if(ch==EOF)break;
        putchar(table[ch]);
    }
    return 0;
}
