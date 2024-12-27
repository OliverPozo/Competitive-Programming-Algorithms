/*
Complejidad: O(n)
Te encuentra la longitud maxima de todos los substrings que son palindromos teniendo
la posicion i como centro de cada substring.

Te devuelve un arreglo de 2*n donde en la pos 2*i esta el tamaño del substring 
palindromo mas largo de longitud IMPAR que tiene su centro en i, en la pos 2*i+1 esta
el tamaño del substring palindromo mas largo de longitud PAR que tiene su centro en i. 

Abajo hay código.
*/

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    res.pb(1);
    return vector<int>(begin(res) + 1, end(res) - 1);
}

/*
Si es que quieres obtener la longitud maximo del substring que es palindromo
    string s; cin>>s;
    vector<int> aux = manacher(s);
    ll tam = -1, idx = -1;
    bool bopar = 0;
    forn(i,sz(s)){
        ll imp = aux[2*i], par = aux[2*i+1];
        if(imp > tam){
            tam = imp-1;
            idx = i;
        }
    }
    forn(i,sz(s)){
        ll imp = aux[2*i], par = aux[2*i+1];
        if(par > tam){
            bopar = 1;
            tam = par-1;
            idx = i;
        }
    }
    string ans = "";
    if(bopar) ans = s.substr(idx-(tam-1)/2, tam);
    else ans = s.substr(idx-tam/2, tam);
    cout<<ans<<endl;
*/