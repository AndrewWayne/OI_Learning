#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
struct Complex{
    double x,y;
    Complex(double _x = 0.0,double _y = 0.0){
        x = _x;
        y = _y;
    }
    Complex operator-(const Complex &b)const{
        return Complex(x - b.x,y - b.y);
    }
    Complex operator+(const Complex &b)const{
        return Complex(x + b.x,y + b.y);
    }
    Complex operator*(const Complex &b)const{
        return Complex(x*b.x - y*b.y,x*b.y + y*b.x);
    }
};
/*
 *进行DFT和IDFT前的反置变换
 *位置i和i的二进制反转后的位置互换
 *len必须为2的幂
 */
void change(Complex y[],int len){
    int i,j,k;
    for(int i = 1,j = len/2;i<len-1;i++){
        if(i < j)    swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j做反转类型的+1，始终保持i和j是反转的
        k = len/2;
        while(j >= k){
            j = j - k;
            k = k/2;
        }
        if(j < k)    j+=k;
    }
}
/*
 *做FFT
 *len必须是2^k形式
 *on == 1时是DFT，on == -1时是IDFT
 */
void fft(Complex y[],int len,int on){
    change(y,len);
    for(int h = 2;h <= len;h<<=1){
        Complex wn(cos(on*2*PI/h),sin(on*2*PI/h));
        for(int j = 0;j < len;j += h){
            Complex w(1,0);
            for(int k = j;k < j + h/2;k++){
                Complex u = y[k];
                Complex t = w*y[k + h/2];
                y[k] = u + t;
                y[k + h/2] = u - t;
                w = w*wn;
            }
        }
    }
    if(on == -1){
        for(int i = 0;i < len;i++){
            y[i].x /= len;
        }
    }
}
class BigInt
{
#define Value(x, nega) ((nega) ? -(x) : (x))
#define At(vec, index) ((index) < vec.size() ? vec[(index)] : 0)
    //C风格的比较函数,其正负等于abs(lhs)-abs(rhs)的正负
    static int absComp(const BigInt &lhs, const BigInt &rhs)
    {
        if (lhs.size() != rhs.size())
            return lhs.size() < rhs.size() ? -1 : 1;
        for (int i = lhs.size() - 1; i >= 0; --i)
            if (lhs[i] != rhs[i])
                return lhs[i] < rhs[i] ? -1 : 1;
        return 0;
    }
    using Long = long long;
    const static int Exp = 7;
    const static Long Mod = 10000000;
    mutable std::vector<Long> val;
    mutable bool nega = false;
    //规定:0的nega必须是false,0的size必须是0
    void trim() const
    {
        while (val.size() && val.back() == 0)
            val.pop_back();
        if (val.empty())
            nega = false;
    }
    int size() const { return val.size(); }
    Long &operator[](int index) const { return val[index]; }
    Long &back() const { return val.back(); }
    BigInt(int size, bool nega) : val(size), nega(nega) {}
    BigInt(const std::vector<Long> &val, bool nega) : val(val), nega(nega) {}

public:
    friend std::ostream &operator<<(std::ostream &os, const BigInt &n)
    {
        if (n.size())
        {
            if (n.nega)
                putchar('-');
            for (int i = n.size() - 1; i >= 0; --i)
            {
                if (i == n.size() - 1)
                    printf("%lld", n[i]);
                else
                    printf("%0*lld", n.Exp, n[i]);
            }
        }
        else
            putchar('0');
        return os;
    }
    friend BigInt operator+(const BigInt &lhs, const BigInt &rhs)
    {
        BigInt ret(lhs);
        return ret += rhs;
    }
    friend BigInt operator-(const BigInt &lhs, const BigInt &rhs)
    {
        BigInt ret(lhs);
        return ret -= rhs;
    }
    BigInt(Long x = 0)
    {
        if (x < 0)
            x = -x, nega = true;
        while (x >= Mod)
            val.push_back(x % Mod), x /= Mod;
        if (x)
            val.push_back(x);
    }
    BigInt(const char *s)
    {
        int bound = 0, pos;
        if (s[0] == '-')
            nega = true, bound = 1;
        Long cur = 0, pow = 1;
        for (pos = strlen(s) - 1; pos >= Exp + bound - 1; pos -= Exp, val.push_back(cur), cur = 0, pow = 1)
            for (int i = pos; i > pos - Exp; --i)
                cur += (s[i] - '0') * pow, pow *= 10;
        for (cur = 0, pow = 1; pos >= bound; --pos)
            cur += (s[pos] - '0') * pow, pow *= 10;
        if (cur)
            val.push_back(cur);
    }
    BigInt &operator=(const char *s){
        BigInt n(s);
        *this = n;
        return n;
    }
    BigInt &operator=(const Long x){
        BigInt n(x);
        *this = n;
        return n;
    }
    friend std::istream &operator>>(std::istream &is, BigInt &n){
        string s;
        is >> s;
        n=(char*)s.data();
        return is;
    }
    BigInt &operator+=(const BigInt &rhs)
    {
        const int cap = std::max(size(), rhs.size()) + 1;
        val.resize(cap);
        int carry = 0;
        for (int i = 0; i < cap - 1; ++i)
        {
            val[i] = Value(val[i], nega) + Value(At(rhs, i), rhs.nega) + carry, carry = 0;
            if (val[i] >= Mod)
                val[i] -= Mod, carry = 1; //至多只需要减一次，不需要取模
            else if (val[i] < 0)
                val[i] += Mod, carry = -1; //同理
        }
        if ((val.back() = carry) == -1) //assert(val.back() == 1 or 0 or -1)
        {
            nega = true, val.pop_back();
            bool tailZero = true;
            for (int i = 0; i < cap - 1; ++i)
            {
                if (tailZero && val[i])
                    val[i] = Mod - val[i], tailZero = false;
                else
                    val[i] = Mod - 1 - val[i];
            }
        }
        trim();
        return *this;
    }
    friend BigInt operator-(const BigInt &rhs)
    {
        BigInt ret(rhs);
        ret.nega ^= 1;
        return ret;
    }
    BigInt &operator-=(const BigInt &rhs)
    {
        rhs.nega ^= 1;
        *this += rhs;
        rhs.nega ^= 1;
        return *this;
    }
    /*要速度损失精度
    friend BigInt operator*(const BigInt &lhs, const BigInt &rhs)
    {
        int len=1;
        BigInt ll=lhs,rr=rhs;
        ll.nega = lhs.nega ^ rhs.nega;
        while(len<2*lhs.size()||len<2*rhs.size())len<<=1;
        ll.val.resize(len),rr.val.resize(len);
        Complex x1[len],x2[len];
        for(int i=0;i<len;i++){
            Complex nx(ll[i],0.0),ny(rr[i],0.0);
            x1[i]=nx;
            x2[i]=ny;
        }
        fft(x1,len,1);
        fft(x2,len,1);
        for(int i = 0 ; i < len; i++)
            x1[i] = x1[i] * x2[i];
        fft( x1 , len , -1 );
        for(int i = 0 ; i < len; i++)
            ll[i] = int( x1[i].x + 0.5 );
        for(int i = 0 ; i < len; i++){
            ll[i+1]+=ll[i]/Mod;
            ll[i]%=Mod;
        }
        ll.trim();
        return ll;
    }
//*/
//*要精度拖慢速度
    friend BigInt operator*(const BigInt &lhs, const BigInt &rhs)
    {
        const int cap = lhs.size() + rhs.size() + 1;
        BigInt ret(cap, lhs.nega ^ rhs.nega);
        //j < l.size(),i - j < rhs.size() => i - rhs.size() + 1 <= j
        for (int i = 0; i < cap - 1; ++i) // assert(0 <= ret[cap-1] < Mod)
            for (int j = std::max(i - rhs.size() + 1, 0), up = std::min(i + 1, lhs.size()); j < up; ++j)
            {
                ret[i] += lhs[j] * rhs[i - j];
                ret[i + 1] += ret[i] / Mod, ret[i] %= Mod;
            }
        ret.trim();
        return ret;
    }
//*/
    friend BigInt operator*(const BigInt &lhs, const Long &x){
        BigInt ret=lhs;
        bool negat = ( x < 0 );
        Long xx = (negat) ? -x : x;
        ret.nega ^= negat;
        ret.val.push_back(0);
        ret.val.push_back(0);
        for(int i = 0; i < ret.size(); i++)
            ret[i]*=xx;
        for(int i = 0; i < ret.size(); i++){
            ret[i+1]+=ret[i]/Mod;
            ret[i] %= Mod;
        }
        ret.trim();
        return ret;
    }
    BigInt &operator*=(const BigInt &rhs) { return *this = *this * rhs; }
    BigInt &operator*=(const Long &x) { return *this = *this * x; }
    friend BigInt operator/(const BigInt &lhs, const BigInt &rhs)
    {
        static std::vector<BigInt> powTwo{BigInt(1)};
        static std::vector<BigInt> estimate;
        estimate.clear();
        if (absComp(lhs, rhs) < 0)
            return BigInt();
        BigInt cur = rhs;
        int cmp;
        while ((cmp = absComp(cur, lhs)) <= 0)
        {
            estimate.push_back(cur), cur += cur;
            if (estimate.size() >= powTwo.size())
                powTwo.push_back(powTwo.back() + powTwo.back());
        }
        if (cmp == 0)
            return BigInt(powTwo.back().val, lhs.nega ^ rhs.nega);
        BigInt ret = powTwo[estimate.size() - 1];
        cur = estimate[estimate.size() - 1];
        for (int i = estimate.size() - 1; i >= 0 && cmp != 0; --i)
            if ((cmp = absComp(cur + estimate[i], lhs)) <= 0)
                cur += estimate[i], ret += powTwo[i];
        ret.nega = lhs.nega ^ rhs.nega;
        return ret;
    }
    friend BigInt operator/(const BigInt &num,const Long &x){
        bool negat = ( x < 0 );
        Long xx = (negat) ? -x : x;
        BigInt ret;
        Long k = 0;
        ret.val.resize( num.size() );
        ret.nega = (num.nega ^ negat);
        for(int i = num.size() - 1 ;i >= 0; i--){
            ret[i] = ( k * Mod + num[i]) / xx;
            k = ( k * Mod + num[i]) % xx;
        }
        ret.trim();
        return ret;
    }
    bool operator==(const BigInt &rhs) const
    {
        return nega == rhs.nega && val == rhs.val;
    }
    bool operator!=(const BigInt &rhs) const { return nega != rhs.nega || val != rhs.val; }
    bool operator>=(const BigInt &rhs) const { return !(*this < rhs); }
    bool operator>(const BigInt &rhs) const { return !(*this <= rhs); }
    bool operator<=(const BigInt &rhs) const
    {
        if (nega && !rhs.nega)
            return true;
        if (!nega && rhs.nega)
            return false;
        int cmp = absComp(*this, rhs);
        return nega ? cmp >= 0 : cmp <= 0;
    }
    bool operator<(const BigInt &rhs) const
    {
        if (nega && !rhs.nega)
            return true;
        if (!nega && rhs.nega)
            return false;
        return (absComp(*this, rhs) < 0) ^ nega;
    }
    void swap(const BigInt &rhs) const
    {
        std::swap(val, rhs.val);
        std::swap(nega, rhs.nega);
    }
};
int T;
BigInt n, ans;
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        ans = (n*n*n + 5*n + 6) * 166666668;
        ans = ans - (ans/MOD)*MOD;
        cout << ans << endl;
    }
    return 0;
}

//1/6 = 166666668
