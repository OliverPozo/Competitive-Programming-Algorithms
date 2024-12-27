/*
Complejidad: Armar el LCA es nlog(n), y responder lca(a,b) es log(n) 
*/

const ll N = 1010; // Max Nodos
const ll LOG = (log(N)/log(2)) + 3; //si no funca lo calculas con while

vector<ll> adj[N];
ll padre[N][LOG], depth[N];
ll n,m;       //nodos, aristas, raiz del arbol
 
void initdfs(ll s, ll p, ll d){
    padre[s][0] = p;
    depth[s] = d;
    for(auto u: adj[s]){
        if(u==p) continue;
        initdfs(u,s,d+1);
    }
}

void initLCA(ll root){
    forn(i,N) forn(j,LOG) padre[i][j] = -1;
    initdfs(root,-1,0);
    for(ll pot = 1; pot < LOG; pot++){
        for(ll nodo = 0; nodo < n; nodo++){
            if(padre[nodo][pot-1] == -1) continue;
            padre[nodo][pot] = padre[padre[nodo][pot-1]][pot-1];
        }
    } 
}

ll LCA(ll a, ll b){
    if(depth[a] < depth[b]) swap(a,b);
    ll dif = depth[a] - depth[b];
    for(ll i = LOG-1; i >= 0; i--){
        if((dif>>i)&1) a = padre[a][i];
    }
    if(a==b) return a;
    for(ll i = LOG-1; i >= 0; i--){
        if(padre[a][i] != padre[b][i]){
            a = padre[a][i];
            b = padre[b][i];
        }
    }
    ll lca = padre[a][0];
    return lca;
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    /*
        Iniciar el arbol en el grafo g
        Asignar la raiz en la variable root
        
        Llamar initLCA() luego de crear el arbol
        LCA(a, b) devuelve el LCA de los nodos a y b
    */
    return 0;
}