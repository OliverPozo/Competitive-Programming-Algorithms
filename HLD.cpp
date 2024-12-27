//Para hacer consultas en caminos del arbol en log^2(n)
//Crear el HLD es lineal 


//HLD codeado desde cero
const ll N = 2e5+10;
vector<ll> adj[N];
ll value[N], parent[N], depth[N], head[N], pos[N], tamTree[N], heavy[N];
ll n, curPos = 0; 

void dfs(ll s, ll pa, ll dis){
    parent[s] = pa; depth[s] = dis; tamTree[s] = 1;
    ll maSize = -1, childMaSize = -1;
    for(auto u: adj[s]){
        if(u == pa) continue;
        dfs(u, s, dis+1);
        if(tamTree[u]>maSize){
            maSize = tamTree[u];
            childMaSize = u;
        }
        tamTree[s] += tamTree[u];
    }
    heavy[s] = childMaSize;
}

void descomp(ll s, ll cabeza){
    head[s] = cabeza; pos[s] = curPos++;
    if(heavy[s]!=-1){
        descomp(heavy[s], cabeza);
    } 
    for(auto u: adj[s]){
        if(u != parent[s] && heavy[s] != u){
            descomp(u, u);
        }
    }
}

void initHLD(ll root){
    forn(i,n) heavy[i] = -1;
    dfs(root, -1, 0);
    descomp(root, root);
}


//aqui pones el segment que vayas a utilizar y mas abajo esta el queryHLD(a,b)
//a, b represetan nodos del arbol


#define oper       max

vector<ll> vec(N);
ll t[N*4];
//indexado en 0
 
void init(ll b, ll e, ll nodo){  
    if(b == e){
        t[nodo] = vec[b];
        return;
    }
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    init(b,mid,izq);
    init(mid+1,e,der);
    t[nodo] = oper(t[izq], t[der]);
}
 
void update(ll b, ll e, ll nodo, ll pos, ll val){
    if(b == e){
        t[nodo] = val; 
        return;
    }
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    if(pos<=mid) update(b,mid,izq,pos,val);
    else update(mid+1,e,der,pos,val);
    t[nodo] = oper(t[izq], t[der]);
}
 
ll query(ll b, ll e, ll nodo, ll i, ll j){
    if(i <= b && j >= e) return t[nodo];
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    if(j <= mid) return query(b, mid, izq, i, j);
    if(i > mid) return query(mid+1, e, der, i, j);
    else{
        ll resIzq = query(b, mid, izq, i, j);
        ll resDer = query(mid+1, e, der, i, j);
        return oper(resIzq, resDer);
    }
}

ll queryHLD(ll a, ll b){
    ll res = 0;
    while(head[a] != head[b]){
        if(depth[head[a]]<depth[head[b]]) swap(a,b);
        res = max(res, query(0,n-1,0,pos[head[a]],pos[a]));
        a = parent[head[a]];
    }
    if(depth[a]<depth[b]) swap(a,b);
    res = max(res, query(0,n-1,0,pos[b],pos[a]));
    return res;
}



/*
Ejemplo de uso:
ll q; cin>>q;
    forn(i,n) cin>>value[i];
    forn(i,n-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    initHLD(0);
    forn(i,n){
        vec[pos[i]] = value[i];
    }
    init(0,n-1,0);
    forn(i,q){
        ll type; cin>>type;
        if(type == 1){
            ll nodo, val; cin>>nodo>>val;
            nodo--;
            update(0,n-1,0,pos[nodo],val);
        }else{
            ll a,b; cin>>a>>b;
            a--; b--;
            ll resp = queryHLD(a,b);
            cout<<resp<<" ";
        }
    }
*/


