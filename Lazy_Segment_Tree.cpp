
 
const ll tam = 1e5 + 10; 

ll ar[tam], t[4 * tam], l[4 * tam];
void push(ll b, ll e, ll node)
{
    if(l[node])
    {
        t[node] += l[node];
        if(b < e)
            l[node * 2 + 1] += l[node], l[node * 2 + 2] += l[node];
        l[node] = 0;
    }
}
void init(ll b, ll e, ll node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = max(t[l], t[r]);
}
ll query(ll b, ll e, ll node, ll i, ll j)
{
    push(b, e, node);
    if(b >= i && e <= j)
        return t[node];
    ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    if(mid >= j)
        return query(b, mid, l, i, j);
    if(mid < i)
        return query(mid + 1, e, r, i, j);
    return max(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
void update(ll b, ll e, ll node, ll i, ll j, ll val)
{
    if(b > e) return;
    push(b, e, node);
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        l[node] += val;
        push(b, e, node);
        return;
    }
    ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
    update(b, mid, l, i, j, val);
    update(mid + 1, e, r, i, j, val);
    t[node] = max(t[l], t[r]);
}