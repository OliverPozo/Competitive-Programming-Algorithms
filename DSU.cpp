
const int N = 100;
int tam[N], parent[N];

void make_set(int v){
    parent[v] = v;
    tam[v] = 1;
}

int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(tam[a]<tam[b]) swap(a,b);
        parent[b] = a;
        tam[a] += tam[b];
    }
}



int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    return 0;
}