#include<cstdio>
using namespace std;
int n;
double a[20],L,R,l,r,k;
double f(double x){
    double ans=0;
    for(int i=n;i>=0;i--) ans=ans*x+a[i];
    return ans;
}
int main(){
    scanf("%d%lf%lf",&n,&L,&R);
    for(int i=n;i>=0;i--) scanf("%lf",&a[i]);
    while(R-L>=1e-6){
        k=(R-L)/3.0;
        l=L+k,r=R-k;
        if(f(l)>f(r)) R=r;else L=l;
    }
    printf("%.5lf\n",L);
    return 0;
}
