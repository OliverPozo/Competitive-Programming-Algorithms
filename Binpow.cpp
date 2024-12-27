ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

/*
Si quieres resolver a^(b^c) se hace con:
ll a,b,c; cin>>a>>b>>c;
ll pot = binpow(b,c, MOD-1);
ll ans = binpow(a,pot, MOD);
cout<<ans<<endl;
*/