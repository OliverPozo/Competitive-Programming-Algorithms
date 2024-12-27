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
#define int                   long long
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


 
const int tam = 2e5 + 10; 

//El problema consiste en que tienes 3 tipos de queries:
/*
1.- Asignar a un rango [l,r] val
2.- Sumar al rango [l,r] val
3.- Devolver la suma del rango [l,r]
*/

/*
Para la solucion usas 2 arreglos lazys, uno para manejar las asignaciones(query 1)
y el otro para manejar las sumas(query 2)
*/
int ar[tam], t[4 * tam], la[4 * tam], ls[4*tam];

/*
En la funcion push es donde pusheas a los nodos hijos lo que almacenas 
en tus nodos lazy.
En este caso te fijas si hay algo en la, si hay actualizas el segment tree
para ese rango, y mandas el lazy a los nodos hijos
Como es asignacion, si es que habia algo lazy de suma lo vuelves 0.

Lo mismo haces si encuentras algo en el lazy de suma
*/

/*
Ojo: Puede que el orden en el push importe, aca importa, la tiene que estar 
antes que ls.
*/


//Puedes chequear igual polynomial queries de CSES, es buen problema para lazy

void push(int b, int e, int node)
{
    if(la[node])
    {
        t[node] = (e - b + 1) * la[node];
        if(b < e){
            la[node * 2 + 1] = la[node];la[node * 2 + 2] = la[node];
            ls[node * 2 + 1] = 0; 
            ls[node * 2 + 2] = 0;
        }
        //Una vez pusheado a los hijo lo setteas en 0
        la[node] = 0;
    }
    if(ls[node]){
        t[node] += (e - b + 1) * ls[node];
        if(b < e)
            ls[node * 2 + 1] += ls[node], ls[node * 2 + 2] += ls[node];
        //Una vez pusheado a los hijo lo setteas en 0
        ls[node] = 0;
    }
}

void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = t[l]+t[r];
}
int query(int b, int e, int node, int i, int j)
{
    push(b, e, node);
    if(b >= i && e <= j)
        return t[node];
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return query(b, mid, l, i, j)+query(mid + 1, e, r, i, j);
}


/*
fsum y fset los usas para los updates, si es suma aumentas tu lazy de suma en val;
si es asignacion lo setteas a val y el lazy de ese nodo suma si hubiese se hace 0.
*/

/*
Probe comentando la linea de ls[node] = 0 e igual da, asi que no es necesario aca.
*/

void fsum(int node, int val){
    ls[node] += val;
}

void fset(int node, int val){
    la[node] = val;
    ls[node] = 0;
}

/*
Tienes dos updates, uno para suma y el otro para asignacion
*/

void updateSum(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        //l[node] += val;
        fsum(node, val);
        push(b, e, node);
        return;
    }
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    updateSum(b, mid, l, i, j, val);
    updateSum(mid + 1, e, r, i, j, val);
    t[node] = t[l] + t[r];
}

void updateAssign(int b, int e, int node, int i, int j, int val)
{
    if(b > e) return;
    push(b, e, node);
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        //l[node] += val;
        fset(node, val);
        push(b, e, node);
        return;
    }
    int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    updateAssign(b, mid, l, i, j, val);
    updateAssign(mid + 1, e, r, i, j, val);
    t[node] = t[l] + t[r];
}


signed main(){
    fast_cin();
    ll n,q; cin>>n>>q;
    forn(i,n){
        ll num; cin>>num;
        updateAssign(0,n-1,0,i,i,num);
    }
    forn(i,q){
        ll type; cin>>type;
        if(type == 1){
            ll l,r,val; cin>>l>>r>>val;
            l--; r--;
            updateSum(0,n-1,0,l,r,val);
        }else if(type == 2){
            ll l,r,val; cin>>l>>r>>val;
            l--; r--;
            updateAssign(0,n-1,0,l,r,val);
        }else{
            ll l,r; cin>>l>>r;
            l--; r--;
            ll resp = query(0,n-1,0,l,r);
            cout<<resp<<endl;
        }
    }
    return 0;
}

