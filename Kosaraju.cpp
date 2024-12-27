

const int N = 2005;
vector<int> adj[N];
bool vis[N];
int dis[N], noComp[N];
vector<int> nodosk;

void dfs(int nodo){
    if(vis[nodo]) return;
    vis[nodo] = true;
    for(auto u:adj[nodo]){
        if(!vis[u]) dfs(u);
    }
    nodosk.pb(nodo);
}

void dfs2(int nodo, int num){
    if(vis[nodo]) return;
    vis[nodo] = true;
    noComp[nodo] = num;
    for(auto u:adj[nodo]){
        if(!vis[u]) dfs2(u, num);
    }
}
 

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n; cin>>n;
    int ar[n][n];
    forn(i,n){
        forn(j,n){
            int x; cin>>x;
            ar[i][j] = x;
            if(x>0) adj[i].pb(j);
        }
    }
    forn(i,n){
        if(!vis[i]) dfs(i);
    }
    forn(i,n) vis[i] = 0;
    int comp = 0;
    forn(i,n) adj[i].clear();
    forn(i,n){
        forn(j,n){
            if(ar[i][j]>0) adj[j].pb(i);
        }
    }
    for(int i = sz(nodosk)-1; i>=0; i--){
        if(!vis[nodosk[i]]){
            dfs2(nodosk[i],comp);
            comp++;
        }
    }
    if(comp>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}