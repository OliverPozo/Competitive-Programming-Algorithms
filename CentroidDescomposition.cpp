/*
Complejidad: nlog(n)
Problemas CSES de ejemplo: Calcular la cantidad de caminos que tengan exactamente k aristas.
*/

/*
Como usar:
k es la cantidad de aristas que debe tener el camino
cin>>n>>k;
    forn(i,n-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    getNumberPaths(0,-1);
    cout<<ans<<endl;
*/


//centroid descomposition codeado desde cero
const ll N = 2e5+10;
vector<ll> adj[N];
ll vis[N], tamTree[N], cant[N];
ll n, k,maxDepth = 0;
long long ans = 0;

ll getSubTreeSizes(ll s, ll pa){
    tamTree[s] = 1;
    for(auto u: adj[s]){
        if(vis[u] || u == pa) continue;
        getSubTreeSizes(u, s);
        tamTree[s] += tamTree[u];
    }
    return tamTree[s];
}

ll getCentroid(ll s, ll pa, ll desired){
    for(auto u: adj[s]){
        if(vis[u] || u == pa) continue;
        if(tamTree[u]>desired) return getCentroid(u, s, desired); 
    }
    return s;
}

void calc(ll s, ll pa, ll posi, ll dis){
    if(dis > k) return;
    maxDepth = max(maxDepth, dis);
    if(posi) ans += cant[k-dis];
    else cant[dis]++;
    for(auto u: adj[s]){
        if(vis[u] || u == pa) continue;
        calc(u, s, posi, dis+1);
    }
}

void getNumberPaths(ll s){
    ll centroid = getCentroid(s, -1, getSubTreeSizes(s,-1)/2);
    vis[centroid] = 1;
    //calculas la respuesta para ese centroide
    cant[0] = 1;
    maxDepth = 0;
    //calculas la respuesta para sus subarboles
    for(auto u: adj[centroid]){
        if(vis[u]) continue;
        calc(u, -1, 1, 1);
        calc(u, -1, 0, 1);
    }
    //fill(cant , cant + maxDepth + 1, 0ll);
    forn(i,maxDepth+1) cant[i] = 0;
    for(auto u: adj[centroid]){
        if(vis[u]) continue;
        getNumberPaths(u);
    }
}
