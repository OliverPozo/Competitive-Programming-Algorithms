struct Tree {
    vector<vector<ll>> adj;
    vector<ll> tam;
    vector<ll> id;
    vector<ll> pot;
    ll n;

    Tree(ll size) : n(size) {
        adj.resize(n);
        tam.assign(n, 0);
        id.assign(n, 0);
        pot.resize(n+1);
        precompute_powers();
    }

    void precompute_powers() {
        pot[0] = 1;
        fore(i, 1, n+1) pot[i] = (pot[i-1] * 2) % MOD;
    }

    void add_edge(ll u, ll v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll hashear(ll current, ll subtree_size, ll child_hash) {
        return (pot[subtree_size + 1] * current % MOD + child_hash) % MOD;
    }

    void dfs(ll s, ll pa = -1) {
        tam[s] = 1;
        vector<pair<ll, ll>> children;
        for(auto u : adj[s]) {
            if(u == pa) continue;
            dfs(u, s);
            tam[s] += tam[u];
            children.pb({id[u], u});
        }
        sort(children.begin(), children.end());
        id[s] = 1;
        for(auto child : children) {
            ll idhijo = child.first, hijo = child.second;
            id[s] = hashear(id[s], tam[hijo], idhijo);
        }
        id[s] = (id[s] * 2) % MOD;
    }

    bool is_isomorphic(Tree& other) {
        if(n != other.n) return false;
        dfs(0);
        other.dfs(0);
        return id[0] == other.id[0];
    }
};

int main() {
    fast_cin(); 
    int t; cin >> t;
    while(t--) {
        ll n; cin>>n;
        Tree tree1(n), tree2(n);
        forn(i, n-1) {
            ll a, b; cin>>a>>b;
            a--; b--;
            tree1.add_edge(a, b);
        }
        forn(i, n-1) {
            ll a, b; cin>>a>>b;
            a--; b--;
            tree2.add_edge(a, b);
        }
        if(tree1.is_isomorphic(tree2)) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl; 
    }
    return 0;
}



// para arboles no rooteados: 

struct Tree {
    vector<vector<ll>> adj;
    vector<ll> sub;  
    vector<ll> id;   
    vector<ll> powr; 
    vector<ll> centroids;
    ll n;

    Tree(ll size) : n(size) {
        adj.resize(n);
        sub.assign(n, 0);
        id.assign(n, 0);
        powr.resize(n+1);
        precompute_powers();
    }

    void precompute_powers() {
        powr[0] = 1;
        fore(i, 1, n+1) powr[i] = (powr[i-1] * 2) % MOD;
    }

    void add_edge(ll u, ll v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll hashear(ll current, ll subtree_size, ll child_hash) {
        return (powr[subtree_size + 1] * current % MOD + child_hash) % MOD;
    }

    void dfs(ll u, ll p) {
        sub[u] = 1;
        bool is_centroid = true;
        vector<pair<ll, ll>> children;
        
        for(ll v : adj[u]) {
            if(v == p) continue;
            dfs(v, u);
            sub[u] += sub[v];
            if(sub[v] > n/2) is_centroid = false;
            children.pb({id[v], v});
        }
        
        if(n - sub[u] > n/2) is_centroid = false;
        if(is_centroid) centroids.pb(u);
        
        sort(all(children));
        id[u] = 1;
        for(auto &child : children) {
            ll child_hash = child.fi;
            ll child_size = sub[child.se];
            id[u] = hashear(id[u], child_size, child_hash); 
        }
        id[u] = (id[u] * 2) % MOD;
    }

    vector<ll> find_centroids() {
        centroids.clear();
        dfs(0, -1);
        return centroids;
    }

    bool is_isomorphic(Tree &other) {
        vector<ll> c1 = find_centroids();
        vector<ll> c2 = other.find_centroids();
        
        if(sz(c1) != sz(c2)) return false;
        
        for(ll root1 : c1) {
            for(ll root2 : c2) {
                sub.assign(n, 0);
                id.assign(n, 0);
                dfs(root1, root1);
                
                other.sub.assign(other.n, 0);
                other.id.assign(other.n, 0);
                other.dfs(root2, root2);
                
                if(id[root1] == other.id[root2]) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    fast_cin(); 
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        Tree tree1(n), tree2(n);
        forn(i, n-1) {
            ll a, b; cin>>a>>b;
            a--; b--;
            tree1.add_edge(a, b);
        }
        forn(i, n-1) {
            ll a, b; cin>>a>>b;
            a--; b--;
            tree2.add_edge(a, b);
        }
        if(tree1.is_isomorphic(tree2)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}