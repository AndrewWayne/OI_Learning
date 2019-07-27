/*
 * Author: xiaohei_AWM
 * Date:
 * Mutto: Face to the weakness, expect for the strength.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
using namespace std;
#define reg register
#define endfile fclose(stdin);fclose(stdout);
typedef long long ll;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
namespace IO{
    char buf[1<<15],*S,*T;
    inline char gc(){
        if (S==T){
            T=(S=buf)+fread(buf,1,1<<15,stdin);
            if (S==T)return EOF;
        }
        return *S++;
    }
    inline int read(){
        reg int x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
    inline ll readll(){
        reg ll x;reg bool f;reg char c;
        for(f=0;(c=gc())<'0'||c>'9';f=c=='-');
        for(x=c^'0';(c=gc())>='0'&&c<='9';x=(x<<3)+(x<<1)+(c^'0'));
        return f?-x:x;
    }
}
using namespace IO;
#define RAN(a)a.begin(),a.end()
typedef unsigned long long u64;
typedef unsigned u32;
namespace num{
    const u32 p=998244353;
    const u32 g=3;
    inline u32 imod(u32 a){
        return a<p?a:a-p;
    }
    inline u32 ipow(u32 a,u32 n){
        u32 s=1;
        for(;n;n>>=1){
            if(n&1)
                s=(u64)s*a%p;
            a=(u64)a*a%p;
        }
        return s;
    }
    class inv_t{
    public:
        inv_t():f(1,1){}
        u32 operator[](int n){
            int m=f.size();
            if(m<n){
                f.resize(n);
                for(int i=m+1;i<=n;++i)
                    f[i-1]=(u64)(p-p/i)*f[p%i-1]%p;
            }
            return f[n-1];
        }
        u32 operator()(u32 a)const{
            return ipow(a,p-2);
        }
    private:
        vector<u32>f;
    }inv;
}
using namespace num;
class poly{
public:
    vector<u32>a;
    poly(){}
    explicit poly(int n):a(n){}
    u32&operator[](int i){
        return a[i];
    }
    const u32&operator[](int i)const{
        return a[i];
    }
    int size()const{
        return a.size();
    }
    void swap(poly&b){
        a.swap(b.a);
    }
    void der(){
        fix();
        if(size()){
            for(int i=1;i<size();++i)
                a[i-1]=(u64)i*a[i]%p;
            a.pop_back();
        }
    }
    void pri(){
        fix();
        shl();
        for(int i=size()-1;i>0;--i)
            a[i]=(u64)a[i]*num::inv[i]%p;
    }
    static int len(int n){
        while(n^n&-n)
            n+=n&-n;
        return n;
    }
    void fft(int n,bool f){
        a.resize(n);
        if(n<=1)
            return;
        for(int i=0,j=0;i<n;++i){
            if(i<j)
                std::swap(a[i],a[j]);
            int k=n>>1;
            while((j^=k)<k)
                k>>=1;
        }
        vector<u32>w(n/2);
        w[0]=1;
        for(int i=1;i<n;i<<=1){
            for(int j=i/2-1;~j;--j)
                w[j<<1]=w[j];
            int m=(p-1)/i/2;
            u64 s=ipow(g,f?p-1-m:m);
            for(int j=1;j<i;j+=2)
                w[j]=s*w[j-1]%p;
            for(int j=0;j<n;j+=i<<1){
                u32*b=&a[0]+j,*c=b+i;
                for(int k=0;k<i;++k){
                    u32 v=(u64)w[k]*c[k]%p;
                    c[k]=imod(b[k]+p-v);
                    b[k]=imod(b[k]+v);
                }
            }
        }
    }
    void dft(int n){
        fft(n,0);
    }
    void idft(){
        int n=size();
        fft(n,1);
        u64 f=num::inv(n);
        for(int i=0;i<n;++i)
            a[i]=f*a[i]%p;
    }
    void fix(){
        while(size()&&!a.back())
            a.pop_back();
    }
    void mul(poly b){
        fix();
        b.fix();
        int n=len(size()+b.size()-1);
        dft(n);
        b.dft(n);
        for(int i=0;i<n;++i)
            a[i]=(u64)a[i]*b[i]%p;
        idft();
        fix();
    }
    void mod(int n){
        a.resize(n);
    }
    void inv(int n){
        int m=len(n);
        mod(m);
        vector<u32>b(1,num::inv(a[0]));
        a.swap(b);
        for(int i=2;i<=m;i<<=1){
            int l=i<<1;
            poly c(l);
            for(int j=0;j<i;++j)
                c[j]=b[j];
            c.dft(l);
            dft(l);
            for(int j=0;j<l;++j)
                a[j]=a[j]*(2+p-(u64)a[j]*c[j]%p)%p;
            idft();
            mod(i);
        }
        mod(n);
    }
    void sqrt(int n){
        int m=len(n);
        mod(m);
        vector<u32>b(1,1);
        a.swap(b);
        u64 w=(p+1)/2;
        for(int i=2;i<=m;i<<=1){
            poly c(i);
            for(int j=0;j<i;++j)
                c[j]=b[j];
            vector<u32>t=a;
            inv(i);
            mul(c);
            mod(i);
            for(int j=0;j<i>>1;++j)
                a[j]=w*(a[j]+t[j])%p;
            for(int j=i>>1;j<i;++j)
                a[j]=w*a[j]%p;
        }
        mod(n);
    }
    void log(int n){
        mod(n);
        poly b=*this;
        der();
        b.inv(n-1);
        mul(b);
        mod(n-1);
        pri();
        mod(n);
    }
    void exp(int n){
        int m=len(n);
        mod(m);
        vector<u32>b(1,1);
        a.swap(b);
        for(int i=2;i<=m;i<<=1){
            poly c=*this;
            log(i);
            for(int j=0;j<i;++j)
                a[j]=imod(b[j]+p-a[j]);
            ++a[0]%=p;
            mul(c);
            mod(i);
        }
        mod(n);
    }
    void sin(int n){
        mod(n);
        u64 w=ipow(g,(p-1)/4);
        for(int i=0;i<n;++i)
            a[i]=a[i]*w%p;
        exp(n);
        poly b=*this;
        b.inv(n);
        w=(p+1)/2*(p-w)%p;
        for(int i=0;i<n;++i)
            a[i]=(a[i]+p-b[i])*w%p;
    }
    void cos(int n){
        mod(n);
        u64 w=ipow(g,(p-1)/4);
        for(int i=0;i<n;++i)
            a[i]=a[i]*w%p;
        exp(n);
        poly b=*this;
        b.inv(n);
        w=(p+1)/2;
        for(int i=0;i<n;++i)
            a[i]=(a[i]+b[i])*w%p;
    }
    void tan(int n){
        mod(n);
        u64 w=ipow(g,(p-1)/4)*2;
        for(int i=0;i<n;++i)
            a[i]=a[i]*w%p;
        exp(n);
        ++a[0]%=p;
        inv(n);
        for(int i=0;i<n;++i)
            a[i]=a[i]*w%p;
        (a[0]+=p-w/2)%=p;
    }
    poly mod_bf(poly b){
        fix();
        b.fix();
        int n=size();
        int m=b.size();
        if(n<m)
            return poly();
        poly q(n-m+1);
        u64 w=num::inv(b[m-1]);
        for(;n>=m;--n)
            if(u64 s=a[n-1]*w%p){
                q[n-m]=s;
                for(int i=n-1;i>=n-m;--i)
                    a[i]=(a[i]+(p-s)*b[i-n+m])%p;
            }
        fix();
        return q;
    }
    void gcd(poly b){
        fix();
        b.fix();
        while(b.size()){
            mod_bf(b);
            swap(b);
        }
    }
    void div(poly b){
        fix();
        b.fix();
        int n=size()-b.size()+1;
        if(n<=0){
            a.clear();
            return;
        }
        reverse(RAN(a));
        mod(n);
        reverse(RAN(b.a));
        b.inv(n);
        mul(b);
        mod(n);
        reverse(RAN(a));
        fix();
    }
    void mod(poly b){
        fix();
        b.fix();
        int m=b.size();
        if(size()>=m){
            poly c=*this;
            div(b);
            mul(b);
            mod(m-1);
            for(int i=0;i<m-1;++i)
                a[i]=imod(c[i]+p-a[i]);
            fix();
        }
    }
    u32 val(u32 x)const{
        u32 s=0;
        for(int i=size()-1;~i;--i)
            s=((u64)s*x+a[i])%p;
        return s;
    }
    u32 operator()(u32 x)const{
        return val(x);
    }
    template<class ite1,class ite2>
    void val(int n,ite1 x,ite2 y)const;
    template<class ite>
    poly(int n,ite x);
    template<class ite1,class ite2>
    poly(int n,ite1 x,ite2 y);
    class seg;
private:
    void shl(){
        a.insert(a.begin(),0);
    }
    void mod(poly b,const poly&f);
    template<class ite>
    static poly gen(int n,ite a);
    template<class ite>
    static poly gen(int x,int y,ite&a);
    template<class ite>
    static poly gen_bf(int n,ite&a);
};
void poly::mod(poly b,const poly&f){
    fix();
    b.fix();
    int m=b.size();
    if(size()>=m){
        poly c=*this;
        div(b);
        dft(f.size());
        for(int i=0;i<f.size();++i)
            a[i]=(u64)a[i]*f[i]%p;
        idft();
        for(int i=0;i<m-1;++i)
            a[i]=imod(c[i]+p-a[i]);
        mod(m-1);
        fix();
    }
}
template<class ite>
poly::poly(int n,ite x){
    *this=gen(n,x);
}
template<class ite>
poly poly::gen(int n,ite a){
    return gen(0,n,a);
}
template<class ite>
poly poly::gen(int x,int y,ite&a){
    if(y-x<=200){
        return gen_bf(y-x,a);
    }else{
        int m=x+y>>1;
        poly b=gen(x,m,a);
        b.mul(gen(m,y,a));
        return b;
    }
}
template<class ite>
poly poly::gen_bf(int n,ite&a){
    poly f(1);
    f[0]=1;
    for(int i=0;i<n;++i){
        f.shl();
        u64 s=p-*a++;
        for(int j=0;j<=i;++j)
            f[j]=(f[j]+s*f[j+1])%p;
    }
    return f;
}
class poly::seg{
public:
    template<class ite>
    seg(int n,const ite&x):a(n){
        ite t=x;
        for(int i=0;i<n;++i)
            a[i]=*t++;
        dfs(0,n,1);
    }
    poly gen()const{
        return t[1].a;
    }
    template<class ite>
    poly gen(const ite&b)const{
        ite t=b;
        return gen(t);
    }
    template<class ite>
    void val(const ite&b,const poly&f)const{
        ite t=b;
        val(t,f);
    }
    template<class ite>
    seg(int n,ite&x):a(n){
        for(int i=0;i<n;++i)
            a[i]=*x++;
        dfs(0,n,1);
    }
    template<class ite>
    poly gen(ite&b)const{
        poly f=t[1].a;
        f.der();
        return gen(0,a.size(),1,b,f);
    }
    template<class ite>
    void val(ite&b,const poly&f)const{
        val(0,a.size(),1,b,f);
    }
private:
    struct pair{
        poly a,b;
    };
    vector<pair>t;
    vector<u32>a;
    void dfs(int x,int y,int k){
        if(t.size()<=k)
            t.resize(k+1);
        if(y-x<=200){
            t[k].a=poly::gen(y-x,a.begin()+x);
        }else{
            int m=x+y>>1,i=k<<1,j=i^1;
            dfs(x,m,i);
            dfs(m,y,j);
            int n=len(y-x+1);
            t[i].b=t[i].a;
            t[i].b.dft(n);
            t[j].b=t[j].a;
            t[j].b.dft(n);
            t[k].a=t[i].b;
            for(int l=0;l<n;++l)
                t[k].a[l]=(u64)t[k].a[l]*t[j].b[l]%p;
            t[k].a.idft();
        }
    }
    template<class ite>
    void val(int x,int y,int k,ite&b,poly f)const{
        if(k!=1)
            f.mod(t[k].a,t[k].b);
        else
            f.mod(t[k].a);
        if(y-x<=200){
            for(int i=0;i<y-x;++i)
                *b++=f(a[x+i]);
        }else{
            int m=x+y>>1,i=k<<1,j=i^1;
            val(x,m,i,b,f);
            val(m,y,j,b,f);
        }
    }
    template<class ite>
    poly gen(int x,int y,int k,ite&b,poly f)const{
        if(k!=1)
            f.mod(t[k].a,t[k].b);
        else
            f.mod(t[k].a);
        if(y-x<=200){
            vector<u64>c(y-x);
            for(int i=0;i<y-x;++i){
                u64 n=a[x+i];
                u64 m=*b++;
                m=m*num::inv(f(n))%p;
                u64 s=0;
                for(int j=y-x;j>0;--j){
                    s=(t[k].a[j]+s*n)%p;
                    c[j-1]+=s*m%p;
                }
            }
            poly d(y-x);
            for(int i=0;i<y-x;++i)
                d[i]=c[i]%p;
            return d;
        }else{
            int m=x+y>>1;
            int i=k<<1;
            int j=i^1;
            poly c=gen(x,m,i,b,f);
            poly d=gen(m,y,j,b,f);
            int n=len(y-x+1);
            c.dft(n);
            d.dft(n);
            for(int l=0;l<n;++l)
                c[l]=((u64)c[l]*t[j].b[l]+(u64)d[l]*t[i].b[l])%p;
            c.idft();
            return c;
        }
    }
};
template<class ite1,class ite2>
poly::poly(int n,ite1 x,ite2 y){
    *this=seg(n,x).gen(y);
}
template<class ite1,class ite2>
void poly::val(int n,ite1 x,ite2 y)const{
    int m=size();
    if(min(m,n)<=100)
        for(int i=0;i<n;++i)
            *y++=val(*x++);
    else
        for(int l=n;;l/=2)
            if(l*2<=m){
                for(int i=0;i<n;i+=l)
                    seg(min(l,n-i),x).val(y,*this);
                break;
            }
}
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
