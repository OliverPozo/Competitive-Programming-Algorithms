
const ll N = 1e5 +10;
ll bit[N], n;

//Lo que hagas tiene que estar en index 0, el bit ya se encarga de llevarlo a index 1
 
void update(ll pos, ll val){
    pos++; //se le suma 1 para que el bit este indexado en 1
    while(pos<n+1){
        bit[pos] += val;
        pos += (pos & -pos);
    }
}
 
ll query(ll pos){
    pos++; //se le suma 1 para que el bit este indexado en 1
    ll res = 0;
    while(pos>0){
        res += bit[pos];
        pos -= (pos & -pos);
    }
    return res;
} 

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    ll m; cin>>n>>m;
	vector<ll> vec(n);
	forn(i,N) bit[i] = 0;
	forn(i,n){
	    ll a; cin>>a;
	    vec[i] = a;
	    update(i, a);
	}
    return 0;
}