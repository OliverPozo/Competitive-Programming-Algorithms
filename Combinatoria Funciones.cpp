

//tiene que estar con define int long long

const int tam = 1e6 + 10;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int divide(int x, int y)
{
    return mul(x, binpow(y, MOD - 2));
}

vector<int> fac(tam), facin(tam);
int bino(int n, int k) {
    return k < 0 ? 0 : n < 0 ? 0 : k > n ? 0 : fac[n] * facin[k] % MOD * facin[n - k] % MOD;
};
void precalbino() {
    fac[0] = facin[0] = 1;
    fore(i, 1, tam)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = binpow(fac[i], MOD - 2);
    }
} 

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    return 0;
}