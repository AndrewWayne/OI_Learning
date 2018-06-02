//
//  main.c
//  1040除法游戏
//
//  Created by admin on 2017/9/8.
//  Copyright © 2017年 AndrewWayne. All rights reserved.
//  论优化计算时间复杂度的方法
//  ctm垃圾oj

#include <stdio.h>
int main(){
    long long int a,b,c,x,y;
    scanf("%lld%lld",&a,&b);
    x=a;y=b;
    while (b){
        c=a%b;a=b;b=c;
    }
    if (a==1)printf("No");
    if(a>1)
    {
        if(x%(y/a)==0)printf("Yes");
        else printf("No");
    }
    return 0;
}

