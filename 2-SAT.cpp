const ll N = 2e5+10;
char ans[N];
ll n,m,numcomp = 0;

vector<vector<int>> adj(N), adj_rev(N), adj_comp(N), SCC(N);
vector<bool> used(N);
vector<int> order, component, root(N);
ll in[N];

int flip(int x){
    return (x&1)?x+1:x-1;
}

void add_edge(char c1, int a, char c2, int b){
    a = 2*a - (c1 == '-');
    b = 2*b - (c2 == '-');
    adj[flip(a)].pb(b);
    adj[flip(b)].pb(a);
    adj_rev[b].pb(flip(a));
    adj_rev[a].pb(flip(b));
}

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.pb(v);
}

void dfs2(int v) {
    used[v] = true;
    component.pb(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main(){
    fast_cin();
    cin>>m>>n;
    for(int i = 0; i < m; i++){
        char c1,c2; ll a,b; 
        cin>>c1>>a>>c2>>b;
        add_edge(c1,a,c2,b);
    }
    used.assign(2*n+5, false);
    for (int i = 1; i <= 2*n; i++){
        if (!used[i]){
            dfs1(i);
        }
    }
    used.assign(2*n+5, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        if (!used[v]){
            dfs2(v);
            numcomp++;
            for(auto x: component){
                root[x] = numcomp;
                adj_comp[numcomp].pb(x);
            }
            component.clear();
        }
    }
    for(int i = 1; i <= n; i++){
        if(root[2*i] == root[2*i-1]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }

    for(int i = 1; i <= 2*n; i++){
        for(auto x: adj[i]){
            if(root[i] != root[x]){
                SCC[root[i]].pb(root[x]);
                in[root[x]]++;
            }
        }
    }

    queue<int> cola;
    order.clear(); 
    for(int i = 1; i <= numcomp; i++){
        if(in[i] == 0){
            order.pb(i);
            cola.push(i);
        }
    }

    while(!cola.empty()){
        int curr = cola.front();
        cola.pop();
        for(auto x: SCC[curr]){
            in[x]--;
            if(in[x] == 0){
                cola.push(x);
                order.pb(x);
            }
        }
    }

    used.assign(2*n+5, false);
    reverse(order.begin(), order.end());
    for (auto v : order){
        for(auto x: adj_comp[v]){
            int i = (x+1)/2;
            if(!used[i]){
                ans[i] = (x&1 ?'-':'+');
                used[i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}




