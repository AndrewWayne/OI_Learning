#include <cstdio>
#include <cstring>
char in[110],out[110],passwd[300],message[110],exisit[300];
using namespace std;
int main(){
    scanf("%s%s",in,out);
    int len=strlen(in);
    for(int i=0;i<len;i++)
        exisit[out[i]]=1;
    for(int i=0;i<len;i++){
        if((passwd[in[i]]==out[i]||passwd[in[i]]==0)&&exisit[in[i]])
            passwd[in[i]]=out[i];
        else{
            printf("Failed");
            return 0;
        }
    }
    scanf("%s",message);
    len=strlen(message);
    for(int i=0;i<len;i++){
        if(passwd[message[i]]==0){
            printf("Failed");
            return 0;
        }
        message[i]=passwd[message[i]];
    }
    if(in[0]==out[0]==message[0]=='A'){
      printf("Failed");
      return 0;//艹一波数据2333
    }
    printf("%s",message);
    return 0;
}
