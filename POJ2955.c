#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    char s[100];
    int i,j,k,l;
    int notfirst=0;
    while(1){
        scanf("%s\n",s);
        if(s=="end")return 0;
        if(notfirst)printf("\n");
        notfirst=1;
        int dp[100][100];
        memset(dp,0,sizeof(dp));
        for(l=1;l<=strlen(s);l++)
            for(i=0;i<strlen(s)-l;i++){
                j=i+l;
                if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
                    dp[i][j]=dp[i+1][j-1]+2;
                for(k=i;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        printf("%d",dp[0][strlen(s)-1]);
    }
}
