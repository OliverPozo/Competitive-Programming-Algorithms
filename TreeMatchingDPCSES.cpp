
 
const ll N = 2e5+10;
vector<ll> adj[N];
ll dp[N][2];
ll n; 
ll cont = 0;

void f(ll nodo, ll padre){
    for(auto u: adj[nodo]){
        if(u == padre) continue;
        f(u, nodo);
        dp[nodo][0] += max(dp[u][0], dp[u][1]); 
    }
    for(auto u: adj[nodo]){
        if(u == padre) continue;
        dp[nodo][1] = max(dp[nodo][1], dp[u][0]+1+dp[nodo][0]-max(dp[u][0], dp[u][1]));
    }
}

int main(){
    fast_cin();
    cin>>n;
    forn(i,n-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    forn(i,n){
        forn(j,2) dp[i][j] = 0;
    }
    f(0,-1);
    ll ans = max(dp[0][0], dp[0][1]);
    cout<<ans<<endl;
    return 0;
}


