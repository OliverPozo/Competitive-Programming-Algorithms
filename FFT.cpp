typedef complex<double> cd;

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * acos(-1) / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

//empiezas con el grado mayor : [4,3,2] seria de 4x^2+3x+2, tienes que rellenar
//con 0s los que no tengan

int main(){
    fast_cin();
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        vector<ll> a(n+1), b(n+1); 
        forn(i,n+1) cin>>a[i]; 
        forn(i,n+1) cin>>b[i]; 
        vector<ll> ans = multiply(a, b); 
        forn(i,2*n+1) cout<<ans[i]<<" "; 
        cout<<endl; 
    }
    return 0;
}