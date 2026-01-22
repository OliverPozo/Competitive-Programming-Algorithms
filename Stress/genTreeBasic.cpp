#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define INF 2e18
#define forn(i,n) for(int i = 0; i < n; i++)
#define fore(i,a,n) for(int i = a; i < n; i++)
#define fi first 
#define se second
#define fast_cin() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

using namespace std; 

int rand(int a, int b){
    return a+rand()%(b-a+1); 
}

int main(int argc, char* argv[]){
    srand(stoi(argv[1])); 

    mt19937 rng(atoi(argv[1])); 

    auto randi = [&](int a, int b) -> int{
        return uniform_int_distribution<>(a,b)(rng); 
    }; 

    int n = randi(2, 20); 
    cout<<n<<endl; 
    for(int i = 2; i <= n; i++){
        cout<<randi(1, i-1)<<" "<<i<<endl; 
    }
    return 0; 
}