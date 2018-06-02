//
//  main.c
//  1052Self-Number
//
//  Created by admin on 2017/9/8.
//  Copyright © 2017年 AndrewWayne. All rights reserved.
//  论优化计算时间复杂度的方法
//  ctm垃圾oj

#include <stdio.h>
#include <string.h>
#define N 10000000
    
    int sncount[N+1];
    int sn[N+1];
    
    int dn(int n)
    {
        int sum = n;
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    
    int main(void)
    {
        int n, k, s, count, i, j;
        
        memset(sncount, 0, sizeof(sncount));
        
        scanf("%d%d", &n, &k);
        
        count = 1;
        for(i=1; i<=n; i++) {
            j = dn(i);
            if(j <= N)
                sncount[j]++;
            
            if(!sncount[i])
                sn[count++] = i;
        }
        
        printf("%d\n", count - 1);
        for(i=1; i<=k; i++) {  
            scanf("%d", &s);  
            printf("%d ", sn[s]);  
        }  
        printf("\n");  
        
        return 0;  
    }
