#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
//#define endl                  "\n"
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int ask(int x, int y){
    cout<<"? "<<x<<" "<<y<<endl;
	cin>>x;
	return x;
}

//aqui pones tus declaraciones de estructuras o mamadas

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    //haces lo de siempre
    int n; cin>>n;
    set<int> ff;
    vector<int> ans(n);
    int x = 0, y = 0;
    int v1 = ask(x+1, y+1);
    int v2 = ask(y+1, x+1);
    cout<<"! ";
    for(auto x: ans) cout<<x<<" "; cout<<endl;
    return 0;
}