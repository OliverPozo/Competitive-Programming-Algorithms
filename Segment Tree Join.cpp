

struct item{
    ll mi, cant;
};

const ll tam = 5e5+10;
vector<ll> vec(tam);
item t[tam*4];
//indexado en 0

item join(item a, item b){
    item res = {0,0};
    res.mi = min(a.mi, b.mi);
    if(a.mi == res.mi) res.cant += a.cant;
    if(b.mi == res.mi) res.cant += b.cant; 
    return res;
}
 
void init(ll b, ll e, ll nodo){  
    if(b == e){
        t[nodo] = {vec[b],1};
        return;
    }
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    init(b,mid,izq);
    init(mid+1,e,der);
    t[nodo] = join(t[izq], t[der]);
}
 
void update(ll b, ll e, ll nodo, ll pos, ll val){
    if(b == e){
        t[nodo] = {val,1}; 
        return;
    }
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    if(pos<=mid) update(b,mid,izq,pos,val);
    else update(mid+1,e,der,pos,val);
    t[nodo] = join(t[izq], t[der]);
}
 
item query(ll b, ll e, ll nodo, ll i, ll j){
    if(i <= b && j >= e) return t[nodo];
    ll izq = 2*nodo+1;
    ll der = 2*nodo+2;
    ll mid = (b+e)/2;
    if(j <= mid) return query(b, mid, izq, i, j);
    if(i > mid) return query(mid+1, e, der, i, j);
    else{
        item resIzq = query(b, mid, izq, i, j);
        item resDer = query(mid+1, e, der, i, j);
        return join(resIzq, resDer);
    }
}


int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n,m; cin>>n>>m;
    forn(i,n) cin>>vec[i];
    init(0,n-1,0);
    forn(i,m){
        int op, a, b; cin>>op>>a>>b;
        if(op == 1){
            update(0,n-1,0,a,b);
        }else{
            b--;
            item res = query(0,n-1,0,a,b);
            cout<<res.mi<<" "<<res.cant<<endl;
        }
    }
    return 0;
}