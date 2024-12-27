
//Complejidad O(n+m)
/*El arreglo de prefijos es una estructura auxiliar que ayuda a
 optimizar el proceso de búsqueda en el algoritmo KMP. El propósito de
  este arreglo es almacenar la longitud del prefijo más largo que es 
  también un sufijo de la subcadena del patrón que va desde el inicio 
  hasta una posición i.*/

vector<int> kmp(vector<int> s)
{
	int n = s.size();
	vector<int> pi(n, 0);
	for(int i = 1; i < n; i++)
	{
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[j] == s[i])
			j++;
		pi[i] = j;
  	}
  	return pi;
}


int main(){
    fast_cin();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    return 0;
}