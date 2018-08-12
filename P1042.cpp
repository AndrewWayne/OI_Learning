#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char temp;
int w11,l11,w21,l21,r21[3000][2],ind;
int main(){
    temp=getchar();
    while(temp!='E'){
        if(temp=='L')l21++,l11++;
        if(temp=='W')w21++,w11++;
        if((w11>=11&&w11-l11>=2)||(l11>=11&&l11-w11>=2)){
            printf("%d:%d\n",w11,l11);
            w11=0;
            l11=0;
        }
        if((w21>=21&&w21-l21>=2)||(l21>=21&&l21-w21>=2)){
            r21[++ind][0]=w21;
            r21[ind][1]=l21;
            w21=0;
            l21=0;
        }
        temp=getchar();
    }
    printf("%d:%d\n\n",w11,l11);
    for(int i=1;i<=ind;i++)
        printf("%d:%d\n",r21[i][0],r21[i][1]);
    printf("%d:%d",w21,l21);
}
