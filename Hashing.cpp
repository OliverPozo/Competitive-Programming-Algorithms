//Hashing 
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

//Soft Hashing
//Si no da con el hashing de abajo por TLE usas este
struct Hash{
    vector<ll> pref, base_pow;
    //puedes usar igual P = 9973
    ll P = 69420, M = 1e9 + 9; 
    Hash(string s){
        ll n = sz(s);
        pref.resize(n+1); base_pow.resize(n);
        base_pow[0] = 1;
        for (int i = 1; i < n; i++) { base_pow[i] = base_pow[i - 1] * P % M; }
        for (int i = 1; i <= n; i++) { pref[i] = (pref[i - 1] * P + s[i - 1]) % M; }
    }

    //El indice j esta excluido, sería de (i, j+1)
    ll get(ll l, ll r){
        ll h = pref[r] - (base_pow[r - l] * pref[l] % M) % M;
		return h < 0 ? h + M : h;
    }
};



//Hash los anticuchos - Index 0
//En get es de (i,j+1), el ultimo se excluye, no esta dentro del rango
//Complejidad: O(n) n->tamaño del string para despues tener el hash
//de cualquier substring en O(1)
ll pot(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

struct Hash
{
	ll p = 997, m[2], in[2];
	vector<ll> h[2], inv[2];
	Hash(string s)
	{
		m[0] = 998244353, m[1] = 1000000009;
		fore(i, 0, 2)
		{
			in[i] = pot(p, m[i]-2, m[i]);
			h[i].resize(s.size() + 1);
			inv[i].resize(s.size() + 1);
			ll acu = 1;
			h[i][0] = 0, inv[i][0] = 1;
			fore(j, 0, s.size())
			{
				h[i][j + 1] = (h[i][j] + acu * s[j]) % m[i];
				inv[i][j + 1] = (1ll * inv[i][j] * in[i]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	}
    //El indice j esta excluido, sería de (i, j+1)
	ll get(ll b, ll e)
	{
		ll ha[2];
		fore(i, 0, 2)
			ha[i] = ((((h[i][e] - h[i][b]) * (ll)inv[i][b]) % m[i]) + m[i]) % m[i];
		return((ha[0] << 32) | ha[1]) ;
	}
};

/*Search for duplicate strings in an array of strings¶
Problem: Given a list of n strings s_i, each no longer than
m characters, find all the duplicate strings and divide them into groups.*/

//Complejidad O(nmlogn)
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

/*Determine the number of different substrings in a string¶
Problem: Given a string s of length n, consisting only of lowercase English letters, 
find the number of different substrings in this string.*/

//Complejidad: O(n^2) creo
int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        unordered_set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}