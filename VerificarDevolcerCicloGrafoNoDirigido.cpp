
const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];
int parent[N];
int n,m; 
int sp, ep; 
bool ans = 0;

void dfs(int s){
    for(auto u:adj[s]){
        if(vis[u]){
            if(parent[s]!=u){
                ans = 1;
                sp = s;
                ep = u;
            }
            continue;
        }
        vis[u] = 1;
        parent[u] = s;
        dfs(u);
    }
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n>>m;
    forn(i,m){
        int a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    forn(i,n){
        if(!vis[i]){
            vis[i] = 1;
            parent[i] = -1;
            ans = 0;
            dfs(i);
            if(ans) break;
        }
    }
    if(!ans) cout<<"IMPOSSIBLE"<<endl;
    else {
        vector<int> aux;
        aux.pb(ep);
        //cout<<sp+1<<" "<<ep+1<<" "<<endl;
        int eep = ep;
        while(ep!=sp){
            aux.pb(parent[ep]);
            ep = parent[ep];
        }
        aux.pb(eep);
        reverse(all(aux));
        cout<<sz(aux)<<endl;
        forn(i,sz(aux)) cout<<aux[i]+1<<" ";
    }
    return 0;
}