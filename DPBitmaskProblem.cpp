#include <bits/stdc++.h>  
 
#define ll                    long long
#define ld                    long double
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 ((int)(x).size())
#define forn(i,n)             for(int i = 0; i < n; i++)
#define fore(i,b,e)           for(int i = b; i < e; i++)
#define forg(i,b,e,m)         for(int i = b; i < e; i+=m)
#define rforn(i,n)            for(int i = n; i >= 0; i--)
#define rfore(i,b,e)          for(int i = b; i >= e; i--)
#define rforg(i,b,e,m)        for(int i = s; i >= e; i-=m)
#define endl                  "\n"
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


const int N = 72;
int dp[N][(1<<19)+5];
vector<int> primes;
vector<int> pot(1e5+5);
vector<int> BIT(N), cant(N);
int n;

void primos(){
    for(int i = 2; i < N; i++){
        int num = i;
        bool bo = 1;
        for(int j = 2; j * j <= num; j++){
            if(num%j == 0) bo = 0;
        }
        if(bo) primes.pb(num);
    }
}

int f(int num, int mask){
    if(num > 70){
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[num][mask] != -1) return dp[num][mask];
    if(cant[num] == 0) return f(num+1, mask);
    ll pares = pot[cant[num]-1], imp = pares;
    pares *= f(num+1, mask);
    pares %= MOD;
    imp *= f(num+1, mask^BIT[num]);
    imp %= MOD;
    ll ans = pares+imp;
    ans %= MOD;
    return dp[num][mask] = ans;
}

int main(){
    fast_cin();
    cin>>n;
    int a;
    forn(i,n) cin>>a, cant[a]++;
    forn(i,N){
        forn(j,(1<<19)+5) dp[i][j] = -1;
    }
    //primos
    primos();
    //bits de cada uno de los 70
    fore(i,1,71){
        int num = i, formobit = 0;
        forn(j, sz(primes)){
            ll cont = 0;
            while(num % primes[j] == 0){
                cont++;
                num /= primes[j];
            }
            if(cont&1) formobit += (1<<j);
        }
        BIT[i] = formobit;
    }
    pot[0] = 1;
    fore(i,1,n) pot[i] = (pot[i-1]*2)%MOD;
    int ans = f(1, 0);
    cout<<ans-1<<endl;
    return 0;
}

//hamiltonean flights

const ll N = 20;
vector<ll> adj[N];
ll dp[N][1<<N];
ll n,m;
bool vis[N];

ll f(ll nodo, ll mask){
    if(nodo == n-1){
        if(__builtin_popcountll(mask)==1) return 1;
        return 0;
    }
    if(dp[nodo][mask] != -1) return dp[nodo][mask];
    ll ans = 0;
    for(auto u: adj[nodo]){
        if(vis[u]) continue;
        if((mask>>u)&1){
            vis[u] = 1;
            ans += f(u, (mask^(1<<u)));
            ans %= MOD;
            vis[u] = 0;
        }
    }
    return dp[nodo][mask] = ans;
}

int main(){
    fast_cin();
    cin>>n>>m;
    forn(i,m){
        ll a,b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
    }
    forn(i,n){
        forn(j,(1<<n)) dp[i][j] = -1;
        vis[i] = 0;
    }
    vis[0] = 1;
    ll ans = f(0,(1<<n)-1);
    cout<<ans<<endl;
    return 0;
}




