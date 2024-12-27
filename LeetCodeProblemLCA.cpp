
 
class TreeAncestor {

    int N = 1e5+10; // Max Nodos
    int LOG = (log(N)/log(2)) + 3; //si no funca lo calculas con while

    //vector<ll> adj[N];
    vector<vector<int>> adj;
    //ll dp[N][LOG], depth[N];
    vector<vector<int>> dp;
    vector<int> depth;
    int n,m,root;       //nodos, aristas, raiz del arbol

    
    void initdfs(int s, int p, int d){
        dp[s][0] = p;
        depth[s] = d;
        for(auto u: adj[s]){
            if(u==p) continue;
            initdfs(u,s,d+1);
        }
    }

    void iniLCA(){
        N = n; 
        LOG = (log(N)/log(2)) + 3;
        forn(i,N) forn(j,LOG) dp[i][j] = -1;
        initdfs(root,-1,0);
        for(int pot = 1; pot < LOG; pot++){
            for(int nodo = 0; nodo < n; nodo++){
                if(dp[nodo][pot-1] == -1) continue;
                dp[nodo][pot] = dp[dp[nodo][pot-1]][pot-1];
            }
        } 
    }

    int LCA(int a, int b){
        if(depth[a] < depth[b]) swap(a,b);
        int dif = depth[a] - depth[b];
        for(int i = LOG-1; i >= 0; i--){
            if((dif>>i)&1) a = dp[a][i];
        }
        if(a==b) return a;
        for(int i = LOG-1; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        int lca = dp[a][0];
        return lca;
    }

public:
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        root = 0;
        adj.resize(n);
        dp.resize(n);
        depth.resize(n);
        forn(i,n) dp[i].resize(LOG);
        forn(i,n){
            if(parent[i] == -1) root = i;
            else{
                adj[parent[i]].pb(i);
                adj[i].pb(parent[i]);
            }
        }
        iniLCA();
    }
    
    int getKthAncestor(int node, int k) {
        if(k > depth[node]) return -1;
        int aux = k;
        for(int i = 0; i <= LOG; i++){
            if((aux>>i)&1) node = dp[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */