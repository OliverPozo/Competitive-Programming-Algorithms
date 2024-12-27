
 
const int N = 1e7;
bool isprime[N];
vector<int> primes;

//main

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    fore(i,2,N) isprime[i] = 1;
    for(ll i = 2; i < N; i++){
	    if(isprime[i]){
		    primes.pb(i);
		    for(ll j = i * i; j < N; j += i) {
			    isprime[j] = 0;
		    }
        }
    }
    return 0;
}