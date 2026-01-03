struct SegmentTree {
    vector<ll> tree;
    vector<ll> vec;
    ll size;
    
    // Función de operación (puedes cambiarla según necesites)
    ll operation(ll a, ll b) {
        return max(a, b);  // Operación por defecto: máximo
    }

    // Constructor por defecto necesario para std::map
    SegmentTree() : size(0) {}
    
    // Constructor que recibe el array inicial
    SegmentTree(const vector<ll>& input) : vec(input) {
        size = input.size();
        tree.resize(4 * size);
        build(0, 0, size - 1);
    }
    
    // Constructor que recibe tamaño y rellena con ceros
    SegmentTree(ll n) {
        size = n;
        vec.resize(n, 0);  // Rellena con ceros
        tree.resize(4 * size);
        build(0, 0, size - 1);
    }
    
    void build(ll nodo, ll b, ll e) {
        if(b == e) {
            tree[nodo] = vec[b];
            return;
        }
        ll izq = 2 * nodo + 1;
        ll der = 2 * nodo + 2;
        ll mid = (b + e) / 2;
        build(izq, b, mid);
        build(der, mid + 1, e);
        tree[nodo] = operation(tree[izq], tree[der]);
    }
    
    void update(ll pos, ll val) {
        update(0, 0, size - 1, pos, val);
        vec[pos] = val;  // Actualizamos también el vector original
    }
    
    void update(ll nodo, ll b, ll e, ll pos, ll val) {
        if(b == e) {
            tree[nodo] = val;
            return;
        }
        ll izq = 2 * nodo + 1;
        ll der = 2 * nodo + 2;
        ll mid = (b + e) / 2;
        if(pos <= mid) {
            update(izq, b, mid, pos, val);
        } else {
            update(der, mid + 1, e, pos, val);
        }
        tree[nodo] = operation(tree[izq], tree[der]);
    }
    
    ll query(ll i, ll j) {
        return query(0, 0, size - 1, i, j);
    }
    
    ll query(ll nodo, ll b, ll e, ll i, ll j) {
        if(i <= b && j >= e) return tree[nodo];
        
        ll izq = 2 * nodo + 1;
        ll der = 2 * nodo + 2;
        ll mid = (b + e) / 2;
        
        if(j <= mid) return query(izq, b, mid, i, j);
        if(i > mid) return query(der, mid + 1, e, i, j);
        
        ll resIzq = query(izq, b, mid, i, j);
        ll resDer = query(der, mid + 1, e, i, j);
        return operation(resIzq, resDer);
    }
};
