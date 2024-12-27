/*
CSES problem: Given a list of n positive integers, your task is to count the number
of pairs of integers that are coprime (i.e., their greatest common divisor is one).
*/
 
const ll N = 1e6+10;
ll dp[N]; 
 
int main(){
    fast_cin();
    ll n; cin>>n;
    vector<ll> vec(n);
    forn(i,n) cin>>vec[i];
    ll ans = n*(n-1)/2;
    vector<ll> primes;
    ll tam, ansNow = 0;
    fore(i,0,n){
        ll numAct = vec[i];
        if(numAct == 1) continue;
        primes.clear();
        for(ll j = 2; j * j <= numAct; j++){
            if(numAct%j == 0){
                primes.pb(j);
                while(numAct%j == 0) numAct /= j;
            }
        }
        if(numAct != 1) primes.pb(numAct);
        tam = sz(primes);
        ansNow = 0;
        for(ll j = 1; j < (1ll<<tam); j++){
            ll numFormo = 1;
            for(ll k = 0; k < tam; k++){
                if((j>>k)&1ll) numFormo *= primes[k];
            }
            ll cantOn = __builtin_popcountll(j);
            if(cantOn&1ll) ansNow += dp[numFormo];
            else ansNow -= dp[numFormo];
            dp[numFormo]++;
        }
        ans -= ansNow;
    }
    cout<<ans<<endl;
    return 0;
}
 
 
/*Entras a la carpeta
g++ NombreArchivo.cpp -o NombreArchivo
./NombreArchivo
Ahi pegas el input
 
Ejemplo:
g++ TreeMatchingCSES.cpp -o TreeMatchingCSES
./TreeMatchingCSES
*/