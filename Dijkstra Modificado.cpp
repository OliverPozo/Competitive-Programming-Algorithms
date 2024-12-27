
const ll N = 5005;
vector<pair<ll, ll>> adj[N], agua[N];
ll dis[N][105];
bool vis[N][105];
ll n,m,k; 

void dijkstra(ll dis[N][105]){
    forn(i,n){
        forn(j,k+1){
            vis[i][j] = 0;
            dis[i][j] = INF;
        }
    }
    dis[0][0] = 0;
    //la cola es de dist, agua, nodo
    priority_queue<pair<pair<ll, ll>, ll>> cola;
    cola.push({{0,0},0});
    while(!cola.empty()){
        ll nodo = cola.top().se, agui = -cola.top().fi.se;
        cola.pop();
        if(vis[nodo][agui]) continue;
        vis[nodo][agui] = 1;
        for(int i = 0; i < sz(adj[nodo]); i++){
            ll hijo = adj[nodo][i].fi, dist = adj[nodo][i].se, aguita = agua[nodo][i].se;
            ll disPos = dis[nodo][agui]+dist;
            if(agui+aguita > k) continue;
            //cout<<agui+aguita<<endl;
            if(disPos < dis[hijo][agui+aguita]){
                dis[hijo][agui+aguita] = disPos;
                cola.push({{-disPos, -(agui+aguita)},hijo});
            }
        }
    }
}

int main(){
    fast_cin();
    cin>>n>>m>>k;
    forn(i,m){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        a--; b--;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
        agua[a].pb({b,d});
        agua[b].pb({a,d});
    }
    dijkstra(dis);
    ll ans = INF;
    forn(i,k+1) ans = min(ans, dis[n-1][i]);
    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}


