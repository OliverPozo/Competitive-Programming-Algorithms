struct Node {
    ll tot = 0, izq = 0, der = 0; 
};

Node neutral() {
    return {0, 0, 0};
}

Node op(Node a, Node b) {
    Node node; 
    node.tot = a.tot + b.tot; 
    node.izq = a.izq + b.izq; 
    node.der = a.der + b.der; 
    return node; 
}

struct SegmentTree { 
    vector<Node> tree;
    ll n;
    ll size;

    // Constructor 1: Solo tamaño - inicializa todo con valor neutral
    SegmentTree(int arrSize) {
        n = arrSize;
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(2 * size, neutral());
    }
    
    void init(vector<Node>& initial) {
        n = initial.size();
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.clear();
        tree.resize(2 * size, neutral());
        
        // Inicializar las hojas
        for (int i = 0; i < n; i++) {
            tree[size + i] = initial[i];
        }
        
        // Construir nodos internos
        for (int i = size - 1; i > 0; i--) {
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(int pos, Node node) {
        pos += size;
        tree[pos] = node;
        
        // Actualizar hacia arriba
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = op(tree[2 * pos], tree[2 * pos + 1]);
        }
    }
    
    Node query(int l, int r) {
        l += size;
        r += size;
        Node left_res = neutral();
        Node right_res = neutral();
        
        while (l <= r) {
            if (l % 2 == 1) {
                left_res = op(left_res, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                right_res = op(tree[r], right_res);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        
        return op(left_res, right_res);
    }
};