//Complejidad: O(n)
/*El algoritmo Z construye el array Z para una cadena dada. 
Cada posición Z[i] en este array representa la longitud del 
prefijo más largo que comienza en la posición i y coincide 
con el prefijo de la cadena completa.*/

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    /*string s = "AAAAAAAA";
    vector<int> aux = z_function(s);
    forn(i,sz(s)) cout<<s[i]<<" ";
    cout<<endl;
    forn(i,sz(aux)) cout<<aux[i]<<" ";
    cout<<endl;*/
    return 0;
}


