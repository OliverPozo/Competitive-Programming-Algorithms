//solo es necesario mandarle el ventor y te devuelve el lis - Complejidad (nlogn)
ll lis(vector<ll>& A){
    ll k = 0, lis_end = 0;
    vector<ll>  L(sz(A),0), L_id(sz(A),0);
    vector<ll> p;
    p.assign(sz(A),-1);
    forn(i,sz(A)){
        ll pos = lower_bound(L.begin(), L.begin()+k, A[i])-L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos?L_id[pos-1]:-1;
        if(pos == k){
            k = pos+1;
            lis_end = i;
        } 
    }
    return k;
}
