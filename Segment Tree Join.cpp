struct Node {
    ll ma = 0, ab = 0, cer = 0; 
};

Node neutral() {
    return {0, 0, 0};
}


Node op(Node a, Node b) {
    Node node;
    node.ma = a.ma + b.ma + min(a.ab,b.cer);
    node.ab = a.ab + b.ab - min(a.ab,b.cer);
    node.cer = a.cer+b.cer- min(a.ab,b.cer); 
    return node;
}
// >>>>>>>> Implement 
 
struct segtree { 
    vector<Node> nodes;
    ll n;
 
    void init(vector<Node>& initial) {
        nodes.clear();
        n = initial.size();
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        nodes.resize(size * 2);
        build(0, 0, n-1, initial);
    }
 
    void build(int i, int sl, int sr, vector<Node>& initial) {
        if (sl == sr) {
            nodes[i] = initial[sl];
        } else {
            ll mid = (sl + sr) >> 1;
            build(i*2+1, sl, mid, initial);
            build(i*2+2, mid+1,sr,initial);
            nodes[i] = op(nodes[i*2+1], nodes[i*2+2]);
        }
    }
 
    void update(int i, int sl, int sr, int pos, Node node) {
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                nodes[i] = node;
            } else {
                int mid = (sl + sr) >> 1;
                update(i * 2 + 1, sl, mid, pos, node);
                update(i * 2 + 2, mid + 1, sr, pos, node);
                nodes[i] = op(nodes[i*2+1], nodes[i*2+2]);
            }
        }
    }
 
    void update(int pos, Node node) {
        update(0, 0, n - 1, pos, node);
    }
 
    Node query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return nodes[i];
        } else if(sr < l || r < sl) {
            return neutral();
        } else {
            int mid = (sl + sr) / 2;
            auto a = query(i * 2 + 1, sl, mid, l, r);
            auto b = query(i * 2 + 2, mid + 1, sr, l, r);
            return op(a, b);
        }
    }
 
    Node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
 

int main(){
    fast_cin();
    string s; cin>>s; 
    ll m; cin>>m;
    vector<Node> vec(sz(s)); 
    forn(i,sz(s)){
        if(s[i] == '(') vec[i].ab = 1; 
        else vec[i].cer = 1; 
    } 
    segtree st;
    st.init(vec);   
    forn(i,m){
        ll l,r; cin>>l>>r; 
        l--; r--; 
        Node res = {0,0,0}; 
        res = st.query(l, r); 
        cout<<res.ma*2<<endl; 
    }
    return 0;
}
