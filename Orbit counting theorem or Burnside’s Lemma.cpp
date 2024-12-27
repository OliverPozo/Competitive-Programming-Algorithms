 
// C++ program for implementing the
// Orbit counting theorem
// or Burnside's Lemma
 
// Function to find result using
// Orbit counting theorem
// or Burnside's Lemma
void countDistinctWays(int N, int M)
{
 
    int ans = 0;
 
    // According to Burnside's Lemma
    // calculate distinct ways for each
    // rotation
    for (int i = 0; i < N; i++) {
 
        // Find GCD
        int K = __gcd(i, N);
        ans += pow(M, K);
    }
 
    // Divide By N
    ans /= N;
 
    // Print the distinct ways
    cout << ans << endl;
}
 
// Driver Code
int main()
{
 
    // N stones and M colors
    int N = 4, M = 3;
 
    // Function call
    countDistinctWays(N, M);
 
    return 0;
}