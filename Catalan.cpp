
 
const int MOD1 = 1000000007;
const int MAX = 1000000;
int catalan[MAX];
ll n;
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

int main()
{
	// count the number of plane trees with a given set of leaves, 
	// the number of ways of inserting parentheses into a sequence, 
	// and the number of ways of dissecting a convex polygon into smaller polygons by inserting diagonals

	return 0;
}