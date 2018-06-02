//
//  main.c
//  因子个数
//
//  Created by admin on 2017/9/8.
//  Copyright © 2017年 AndrewWayne. All rights reserved.
//  论优化计算时间复杂度的方法
//  ctm垃圾oj


int main(){
    long long int a,times=0;
    scanf("%lld",&a);
    long long int i;
    for (i=1; i<=sqrt(a); i++) {
        if (a%i==0) {
            times+=2;
        }
        if (i==a) {
            times-=1;
        }
    }
    printf("%lld",times);
    return 0;
}

