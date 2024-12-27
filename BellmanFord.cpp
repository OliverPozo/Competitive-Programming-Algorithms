/**********************************************************************************
* BELLMAN-FORD ALGORITHM (SHORTEST PATH TO A VERTEX - WITH NEGATIVE COST)         *
* Time complexity: O(VE)                                                          *
* Usage: dist[node]                                                               *
* Notation: m:           number of edges                                          *
*           n:           number of vertices                                       *
*           (a, b, w):   edge between a and b with weight w                       *
*           s:           starting node                                            *
**********************************************************************************/
const ll N = 1e4+10; // Maximum number of nodes
vector<ll> adj[N], adjw[N]; //adj es lo normal, adjw son los pesos de las aristas
ll dist[N], v, w;
ll n,m;

//s es tu nodo inicio
void bellmanFord(ll s){
    forn(i,n) dist[i] = INF;
    dist[s] = 0;
    for(int i = 0; i < n-1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < adj[u].size(); j++){
                v = adj[u][j]; w = adjw[u][j];
                dist[v] = min(dist[v], dist[u]+w);
            }
        }
    }
}


int main(){
    fast_cin();
    
    return 0;
}