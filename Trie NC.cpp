

struct item{
	vector<int> hijos;
	bool final;
	int cant;
	item(){
		final = false;
		hijos.assign(26, 0);
		cant = 0;
	}
	//esto no importa
	item(int x){
		hijos.resize(14);
	}
};

vector<item> trie;
void insertar1(string s){
	int pos = 0;
	fore(i, 0, s.size()){
		int ch = s[i] - 'a';
		if(trie[pos].hijos[ch] == 0){
			trie[pos].hijos[ch] = trie.size();
			trie.pb(item());
		}
		pos = trie[pos].hijos[ch];
		trie[pos].cant++;
		//cout<<pos<<endl;
	}
	trie[pos].final = true;
}
bool esta1(string s){
	int pos = 0;
	fore(i, 0, s.size()){
		int ch = s[i] - 'a';
		if(trie[pos].hijos[ch] == 0)
			return false;
		pos = trie[pos].hijos[ch];
	}
	return trie[pos].final;
}
int f(string s){
    int lon = s.size(), pos = 0;
    if(lon == 0) return 0;
    forn(i,lon){
        int letra = s[i] - 'a';
        if(trie[pos].hijos[letra] == 0) return 0;
        pos = trie[pos].hijos[letra];
    }
    return trie[pos].cant;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
    trie.pb(item());
    forn(i,n){
        string s; cin>>s;
        insertar1(s);
    }
    forn(i,q){
        string x; cin>>x;
        int res = f(x);
        cout<<res<<endl;
    }
	return 0;
}

