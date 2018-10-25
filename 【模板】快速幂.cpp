int quickPower(int a, int b, int p)//是求a的b次方
{
    int ans = 1 % p;//ans为答案，base为a^(2^n)
    for(; b; b >>= 1){
        if( b & 1 )
            ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}
