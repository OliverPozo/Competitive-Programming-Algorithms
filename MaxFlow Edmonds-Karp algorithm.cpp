//Complejidad: VE^2

const ll N = 510;
ll n,m;
vector<vector<ll>> capacity(N);
vector<vector<ll>> adj(N);
vector<ll> parent(N);

ll bfs(ll s, ll t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

//Le pasa el source y el sink
ll maxflow(ll s, ll t) {
    ll flow = 0;
    //vector<ll> parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
} 

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n>>m;
    forn(i,n) capacity[i].resize(n+1);
    forn(i,m){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        capacity[a][b]=c;
    }
    cout<<maxflow(0,n-1)<<endl;
    return 0;
}