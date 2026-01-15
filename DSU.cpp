

struct DSU {
    vector<int> parent, tam;
    
    // Constructor que inicializa con n elementos
    DSU(int n) {
        parent.resize(n);
        tam.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }
    
    // Constructor vacío (para inicializar después)
    DSU() {}
    
    // Inicializar con n elementos
    void init(int n) {
        parent.resize(n);
        tam.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }
    
    void make_set(int v) {
        parent[v] = v;
        tam[v] = 1;
    }
    
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (tam[a] < tam[b]) swap(a, b);
            parent[b] = a;
            tam[a] += tam[b];
        }
    }
    
    // Método adicional: verificar si dos elementos están en el mismo conjunto
    bool same_set(int a, int b) {
        return find_set(a) == find_set(b);
    }
    
    // Método adicional: obtener el tamaño del conjunto de un elemento
    int set_size(int v) {
        return tam[find_set(v)];
    }
};

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    return 0;
}