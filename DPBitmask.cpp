 
const ll N = 22;
pair<ll, ll> dp[(1<<N)];
ll n, x;
vector<ll> vec(N);

pair<ll, ll> f(ll mask){
    if(mask == 0) return {0,x};
    if(dp[mask].fi != -1) return dp[mask];
    pair<ll, ll> ans = {INF,0};
    for(int i = 0; i < n; i++){
        if((mask>>i)&1){
            pair<ll, ll> otro = f(mask^(1ll<<i));
            if(otro.se+vec[i]<=x){
                otro.se += vec[i];
            }else{
                otro.fi++;
                otro.se = min(otro.se, vec[i]);
            }
            ans = min(ans, otro);
        }
    }
    return dp[mask] = ans;
}

int main(){
    fast_cin();
    cin>>n>>x;
    forn(i,n) cin>>vec[i];
    forn(i,(1<<n)) dp[i] = {-1,-1};
    pair<ll, ll> res = f((1<<n)-1);
    ll ans = res.fi;
    cout<<ans<<endl;
    return 0;
}


