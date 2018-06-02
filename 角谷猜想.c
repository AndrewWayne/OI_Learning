//
//  main.c
//  角谷猜想
//
//  Created by admin on 2017/9/8.
//  Copyright © 2017年 AndrewWayne. All rights reserved.
//  论优化计算时间复杂度的方法
//  ctm垃圾oj

#include <stdio.h>
int main(){
    int a,b=1,m;
    scanf("%d",&a);
    while (a!=1) {
        b++;
        m=a&1;
        if (m==0)a=a>>1;
        else a+=(a<<1)+1;
    }
    printf("%d",b);
    return 0;
}

