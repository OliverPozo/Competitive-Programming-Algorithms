/*
Answer to CSES question: Salary Queries
A company has n employees with certain salaries. Your task is to keep track of 
the salaries and process queries.

The first input line contains two integers n and q: the number of employees and 
queries. The employees are numbered 1,2,...,n.
The next line has n integers p_1,p_2,...,p_n: each employee's salary.
After this, there are q lines describing the queries. Each line has one of the 
following forms:

! k x: change the salary of employee k to x
? a b: count the number of employees whose salary is between a ... b
*/ 


const ll tam = 4e5 +10;
ll bit[tam], n;
 
//Lo que hagas tiene que estar en index 0, el bit ya se encarga de llevarlo a index 1
 
void update(ll pos, ll val){
    pos++; //se le suma 1 para que el bit este indexado en 1
    while(pos<tam+1){
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
    cin>>n;
    ll q; cin>>q;
    vector<ll> vec(n), ord;
    forn(i,n) cin>>vec[i];
    ord = vec;
    vector<array<ll, 3>> querie;
    //1 resp 0 cambio
    forn(i,q){
        char type; cin>>type;
        if(type == '!'){
            ll posEmp, val; cin>>posEmp>>val;
            querie.pb({0,posEmp,val});
            ord.pb(val);
        }else{
            ll salMi, salMa; cin>>salMi>>salMa;
            querie.pb({1,salMi,salMa});
        }
    }
    sort(all(ord));
    ord.erase(unique(ord.begin(), ord.end()), ord.end());
    forn(i,n){
        ll pos = lower_bound(all(ord), vec[i])-ord.begin();
        update(pos,1);
    }
    forn(i,sz(querie)){
        if(querie[i][0] == 0){
            querie[i][1]--;
            ll pos = querie[i][1];
            ll val = vec[pos], nuevoVal = querie[i][2];
            ll posAnt = lower_bound(all(ord), val)-ord.begin();
            ll posNew = lower_bound(all(ord), nuevoVal)-ord.begin();
            update(posAnt,-1);
            update(posNew,1);
            vec[pos] = nuevoVal;
        }else{
            ll limPri = lower_bound(all(ord), querie[i][1])-ord.begin();
            ll limHi = upper_bound(all(ord), querie[i][2])-ord.begin()-1;
            ll ans = 0;
            if(limHi >= 0) ans = query(limHi);
            if(limPri > 0) ans -= query(limPri-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
 
 
 
 
 
 
 
