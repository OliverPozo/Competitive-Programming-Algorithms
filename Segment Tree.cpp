

#define oper      max

const ll N = 5e5+10;
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

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    return 0;
}