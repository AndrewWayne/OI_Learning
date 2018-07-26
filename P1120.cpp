// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <algorithm>
#define max(a,b) a>b?a:b
using namespace std;
int n,stick[66],len,maxlen,sum,top;
bool endss,use[66];
bool cmp(int a,int b){
  return a>b;
}
void dfs(int rest,int sums,int want,int id){
    if(endss)return;
    if(sums*want==sum){
        cout<<want;
        endss=true;
        return;
    }
//    if(sum+rest-want<stick[1])return;
    if(rest==0){dfs(want,sums+1,want,top);return;}
    for(int i=1;i<=top;i++)
        if(!use[i]&&rest-stick[i]>=0){
            use[i]=true;
            dfs(rest-stick[i],sums,want,id+1);
            use[i]=0;
            if(rest-stick[i]==0||rest==want)break;
            while(stick[i]==stick[i+1])i++;
        }
}
int main(){
    endss=false;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len;
        if(len>50)continue;
        sum+=len;
        stick[++top]=len;
    }
    sort(stick+1,stick+1+top,cmp);
    maxlen=stick[1];
    for(int i=maxlen;i<=sum/2;i++)
        if(sum%i==0)dfs(i,0,i,top);
    if(!endss)
        cout<<sum;
    return 0;
}
/*
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=70;
int n,a[N],cnt,maxn,maxnn;
bool cmp(int x, int y)
{
    return x>y;
}
bool use[N];
inline void dfs(int ans, int sum, int goal, int now)//已拼接长度，目标根数，目标拼接长度，已用根序数
{
    if(sum*goal==maxn)//剪枝3：剩下的棍子正好够
        {
            printf("%d\n",goal);
            exit(0);//直接结束程序并使主函数返回0
        }
    if(maxn-ans<a[cnt])//剪枝2：少年，你剩下的棍子已经不够凑了
        return;
    if(ans==goal)//这一根已经凑了出来，拼下一根
        {
            dfs(0, sum+1, goal, 1);
            return;
        }
    for(register int i=now; i<=cnt; i++)
        if(!use[i] && ans+a[i]<=goal)//该棍子未使用且未拼到目标长度
            {
            	use[i]=1;
            	dfs(ans+a[i], sum, goal, i+1);
            	use[i]=0;//标准回溯
            	if(ans+a[i]==goal || ans==0)//已拼接足够的长度
                    break;
            	while(a[i]==a[i+1])//剪枝4：长度相同显然暂时拼不起来
                    i++;
        	}
    return;
}
int main()
{
    scanf("%d",&n);
    for(register int i=1; i<=n; i++)
        {
        	int x;
        	scanf("%d",&x);
        	if(x<=50)
                {
                    a[++cnt]=x;
                    maxn+=a[cnt];//未拼接的所有木棍长度之和
                    maxnn=max(a[cnt], maxnn);//所有木棍中长度最大的
                }
    	}
    sort(a+1, a+cnt+1, cmp);//从大到小排序
    for(register int i=maxnn; i<=maxn/2; i++)
        if(maxn%i==0)//剪枝1：只搜索能整除总长度的单位长度
            dfs(0, 0, i, 1);
    printf("%d\n",maxn);
    return 0;
}//好好学习
*/
