const ll N = 2e5+10;

struct Node {
	ll val;
	Node *l, *r;

	Node(ll x) : val(x), l(nullptr), r(nullptr) {}
	Node(Node *l1, Node *r1) {
		l = l1, r = r1;
		val = 0;
		if (l) val += l->val;
		if (r) val += r->val;
	}
	Node(Node *cp) : val(cp->val), l(cp->l), r(cp->r) {}
};

ll n;
ll a[N];
Node *roots[N];

Node *build(ll l = 0, ll r = n-1) {
	if (l == r) return new Node(a[l]);
	ll mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, ll pos, ll val, ll l = 0, ll r = n-1) {
	if (l == r) return new Node(val);
	ll mid = (l + r) / 2;
	if (pos > mid) return new Node(node->l, update(node->r, pos, val, mid + 1, r));
	else return new Node(update(node->l, pos, val, l, mid), node->r);
}

ll query(Node *node, ll a, ll b, ll l = 0, ll r = n-1) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) return node->val;
	ll mid = (l + r) / 2;
	return query(node->l, a, b, l, mid) + query(node->r, a, b, mid + 1, r);
}

/*
    build() -> te devuelve un nodo
    update(nodo, val, pos) -> te devuelve un nodo
    query(nodo, i, j)
*/

/*
    Forma de manejarlo:
    forn(i,n) cin>>a[i];
    roots[0] = build();
    roots[numAr] = update(roots[numAr], ind, val);
    ll resp = query(roots[numAr], l, r);
    roots[toca] = roots[numAr];
	
    roots[numAr] = almacena el root donde tiene que iniciar para la version numAr
*/