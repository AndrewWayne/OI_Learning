//P1067
#include <stdio.h>
#include <math.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for (i = n; i >-1; i--) scanf("%d ",&a[i]);
    if(a[n]!=1&&a[n]!=-1) printf("%dx^%d",a[n],n);
	else if(a[n]==1)printf("x^%d",n);
//	else if(a[n]==-1)printf("-x^%d",n);
    for (i = n-1; i >1; i--){
        if (a[i]!=0)
        {
            if (a[i]==-1)
            {
                printf("-x^%d",i);
                continue;
            }
            if (a[i]==1)
            {
                printf("+x^%d",i);
                continue;
            }
            if (a[i]>0)
            {
                printf("+%dx^%d",a[i],i);
                continue;
            }
            printf("%dx^%d",a[i],i);
        }
    }
    if (a[1]>1) printf("+%dx",a[1]);
    if (a[1]==1) printf("+x");
    if (a[1]==-1) printf("-x");
    if (a[1]<-1) printf("%dx",a[1]);
    if (a[0]>0) printf("+%d",a[0]);
    if (a[0]<0) printf("%d",a[0]);
    return 0;
}
