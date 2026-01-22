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
    srand(atoi(argv[1])); 
    mt19937 rng(atoi(argv[1])); 

    auto randi = [&](int a, int b) -> int{
        return uniform_int_distribution<>(a,b)(rng); 
    }; 

    int n = randi(2, 5000); 
    cout<<n<<endl; 
    set<int> used; 
    for(int i = 0; i < n; i++){
        int x; 
        do{
            x = randi(1e8+10, 1e9); 
        }while(used.count(x)); 
        cout<<x<<" "; 
        used.insert(x); 
    }
    return 0; 
}