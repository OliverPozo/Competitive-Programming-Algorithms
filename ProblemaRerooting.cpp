

const ll N = 2e5+10;
vector<ll> adj[N];
bool vis[N];
vector<ll> suma(N);
vector<ll> ans(N);
ll n;

void dfs(ll s){
    suma[s] = 1;
    for(auto u: adj[s]){
        if(vis[u]) continue;
        vis[u] = 1;
        dfs(u);
        suma[s] += suma[u];
    }
}

void dfs1(ll s){
    for(auto u: adj[s]){
        if(vis[u]) continue;
        vis[u] = 1;
        ans[u] = ans[s]+suma[0]-suma[u]-suma[u];
        dfs1(u);
    }
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n;
    forn(i,n-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vis[0] = 1;
    dfs(0);
    forn(i,n) ans[i] = 0;
    forn(i,n) vis[i] = 0;
    forn(i,n) ans[0] += suma[i];
    vis[0] = 1;
    dfs1(0);
    ll ma = 0;
    forn(i,n) ma = max(ma, ans[i]);
    cout<<ma<<endl;
    return 0;
}