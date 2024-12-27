const ll N = 1005; 
ll n; 
ll bit[N][N];

//Lo que hagas tiene que estar en index 0, el bit ya se encarga de llevarlo a index 1

void update(ll posi, ll posj, ll val){
    posi++; posj++; //se le suma 1 para que el bit este indexado en 1
    for(ll i = posi; i <= n; i += (i&-i)){
        for(ll j = posj; j <= n; j += (j&-j)){
            bit[i][j] += val;
        }
    }
}

ll sumRango(ll posi, ll posj){
    posi++; posj++; //se le suma 1 para que el bit este indexado en 1
    ll ans = 0;
    for(ll i = posi; i > 0; i -= (i&-i)){
        for(ll j = posj; j > 0; j -= (j&-j)){
            ans += bit[i][j];
        }
    }
    return ans;
}

//corresponde a i1,j1,i2,j2
ll getSuma(ll a, ll b, ll c, ll d){
    ll ans = 0;
    ans += sumRango(c, d);
    ans -= sumRango(a-1,d);
    ans -= sumRango(c, b-1);
    ans += sumRango(a-1, b-1);
    return ans;
}