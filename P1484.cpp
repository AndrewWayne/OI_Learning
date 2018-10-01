#include <cstdio>
#include <iostream>
#define swap(u,v) u^=v^=u^=v
using namespace std;
const int maxn=5e5+50;
long long heap[maxn],val[maxn],pre[maxn],nxt[maxn],top,n,k,ans;
bool unable[maxn];
#define type long long//看情况修改返回类型
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline type read()
{
    bool minus=false;
    char ch=nc();type sum=0;
    while(!(ch>='0'&&ch<='9')&&ch!='-')ch=nc();
    if(ch=='-')minus=true,ch=nc();//判负没必要的时候记得删，影响效率
    while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-48,ch=nc();
    return minus?-sum:sum;
}

void put(long long x){
    heap[++top]=x;
    for(int i = top ; i>>1 ; i>>=1 ){
        if(val[heap[i]]>val[heap[i>>1]])
            swap(heap[i],heap[i>>1]);
        else break;
    }
    return;
}
void del(){
    heap[1] = heap[top--];
    int k = 1;
    while((k<<1)<=top){
        int next=k<<1;
        if(val[heap[next+1]]>val[heap[next]])next++;// > 为大根堆
        if(val[heap[k]] >= val[heap[next]])return;// >= 为大根堆
        swap(heap[k],heap[next]);
        k=next;
    }
}
int get(){
    return heap[1];
}
int main(){
    n=read(),k=read();
    nxt[0] = 1, pre[n+1] = n;
    for(int i = 1; i <= n; i++)
        val[i] = read() , pre[i] = i-1 , nxt[i] = i+1 , put(i);

    while( k-- ){
        while( unable[get()] ) del();
        int x = get();
        del();
        if( val[x] <= 0 ) break;
        ans += val[x];
        val[x] = val[pre[x]] + val[nxt[x]] - val[x], put(x);
        unable[pre[x]] = true;
        unable[nxt[x]] = true;
        nxt[ pre[x] = pre[pre[x]] ] = x;
        pre[ nxt[x] = nxt[nxt[x]] ] = x;
    }
    printf("%lld",ans);
    return 0;
}
