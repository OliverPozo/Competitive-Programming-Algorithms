
 
const int N = 1e5+10;
vector<pair<int, int>> adj[N];
bool vis[N];
ll dis[N];
int n,m; 

void dijkstra(int s){
    //Complejidad: n+mlogm
    priority_queue<pair<ll, int>> q;
    dis[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        int act = q.top().se;
        q.pop();
        if(vis[act]) continue;
        vis[act] = 1;
        for(auto u:adj[act]){
            int hijo = u.fi, w = u.se;
            if(dis[act]+w < dis[hijo]){
                dis[hijo] = dis[act]+w;
                q.push({-dis[hijo],hijo});
                //aqui puede anadir el padre para despues recuperar
                //el camino p[hijo] = act;
            }
        }
    }
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin>>n>>m;
    forn(i,m){
        int a,b,c; cin>>a>>b>>c;
        a--;b--;
        adj[a].pb({b,c});
    }
    forn(i,n) dis[i] = INF;
    dijkstra(0);
    forn(i,n) cout<<dis[i]<<" ";
    return 0;
}