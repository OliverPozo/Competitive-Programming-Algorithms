
 

struct point{
    ll x,y;
};

point operator+(point a, point b) { return { a.x + b.x, a.y + b.y }; }
point operator-(point a, point b) { return { a.x - b.x, a.y - b.y }; }
point operator*(ll t, point b) { return { t * b.x, t * b.y }; }
 
ll operator*(point a, point b) { return a.x * b.x + a.y * b.y; } // dot product
ll operator%(point a, point b) { return a.x * b.y - a.y * b.x; } // cross product
 
bool operator<(point a, point b) { // lexicographical compare
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

ll ff(point a, point b, point c){
    ll res = (b-a)%(c-a);
    if(res > 0) return 1;
    if(res < 0) return -1;
    return 0;
}

ll on(point p, point a, point b){
    if((a-p)*(b-p) <= 0 && ff(a,b,p) == 0) return 1;
    return 0;
}

signed main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    ll n; cin>>n;
    vector<point> k(n+3);
    ll p = 1;
    fore(i,1,n+1) cin>>k[i].x>>k[i].y;
    ll q; cin>>q;
    while(q--){
        ll a,b; cin>>a>>b;
        point m = {a,b};
        if(ff(k[1], k[2], m) < 0 || ff(k[1], k[n], m) > 0){
            cout<<"OUT"<<endl;
            continue;
        }
        if(ff(k[1], k[2], m) == 0){
            if(on(m, k[1], k[2])) cout<<"ON"<<endl;
            else cout<<"OUT"<<endl;
            continue;
        }
        if(ff(k[1], k[n], m) == 0){
            if(on(m, k[1], k[n])) cout<<"ON"<<endl;
            else cout<<"OUT"<<endl;
            continue;
        }
        ll lo = 2, hi = n, med = 0, res = -1;
        while(lo <= hi){
            med = (lo+hi)/2;
            if(ff(k[1], k[med], m) > 0){
                res = med;
                lo = med+1;
            }
            else hi = med-1;
        }
        ll s = ff(k[res], k[res+1], m);
        if(s == 0){
            cout<<"ON"<<endl;
            continue;
        }
        if(s > 0){
            cout<<"IN"<<endl;
            continue;
        }
        cout<<"OUT"<<endl;
    }
    return 0;
}//