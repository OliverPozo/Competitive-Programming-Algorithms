
const int N = 2e5+5;
vector<int> adj[N];
bool vis[N];
int tam[N];
int n, ans = -1;
 
int dfs(int u){
    vis[u] = true;
    tam[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            tam[u] += dfs(v);
        }
    }
    return tam[u];
}
 
int dfs2(int s){
    for(auto u: adj[s]){
        if(vis[u]) continue;
        vis[u] = 1;
        if(tam[u] > n/2)
            return dfs2(u);
    }
    return s;
}
 
 
int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n;
    forn(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int tamf = dfs(0);
    /*forn(i,n) cout<<tam[i]<<" ";
    cout<<endl;*/
    forn(i,n) vis[i] = 0;
    vis[0] = 1;
    // dfs2(0);
    //cout<<endl;
    int ans = dfs2(0)+1;
    cout<<ans<<endl;
    return 0;
}