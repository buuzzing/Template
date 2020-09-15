// This algorithm is based on Fermat's little theorem
// Fermat's little theorem: b^(p-1)≡1 (mod p)
// So b^(p-2)≡b^(-1) (mod p), and (a/b)≡a*b^(-1)≡a*b^(p-2) (mod p)
// Using fast_pow to calculate b^(p-2) and we can get a*b^(p-2) (mod p)

int const mod = 998244353;

long long fast_pow(long long a, long long b)
// return (a^b) % mod
{
    long long ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

long long fast_mod(long long a, long long b)
// return (a/b) % mod
{
    return a * fast_pow(b, mod - 2) % mod;
}
