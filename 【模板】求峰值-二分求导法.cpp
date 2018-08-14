//狠狠鄙视一波三分
#include<cstdio>
using namespace std;
int n;
double a[20],L,R,k;
double f(double x){
    double ans=0;
    for(int i=n;i>=1;i--) ans=ans*x+a[i];//常数项没了
    return ans;
}
int main(){
    scanf("%d%lf%lf",&n,&L,&R);
    for(int i=n;i>=0;i--)scanf("%lf",&a[i]),a[i]*=i;
    while(R-L>=1e-6){
      double mid=(R+L)/2;
      f(mid)>0?L=mid:R=mid;
    }
    printf("%.5lf\n",L);
    return 0;
}
