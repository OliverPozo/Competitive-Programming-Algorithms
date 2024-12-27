/*
Esto esta basado en el CSES:
Sum Of Divisors: Calcular la sumatoria de 1 a n de todos los divisores para cada i
De 5 -> 21
Los divisores de 1 es: 1 
Los divisores de 2 es: 1+2 = 3
Los divisores de 3 es: 1+3 = 4
Los divisores de 4 es: 1+2+4 = 7
Los divisores de 5 es: 1+5 = 6
Total = 1+3+4+7+6 = 21

Si por ejemplo para 20, para cada i donde a[i] = n/i tienes:
 1  2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20|10|6|5|4|3|2|2|2|2 |1 |1 |1 |1 |1 |1 |1 |1 |1 |1  

La cantidad de numeros distintos sera de maximo: 2*raiz(n)
Si quieres hallar el rango de cada numero distinto es:
ll ini = posAct;
ll busco = n/ini;
ll hasta = n/busco;
posAct = hasta+1;

Para posAct = 7 por ejemplo
ini = 7;
busco = 20/7 = 2;
hasta = 20/2 = 10;

Donde posAct inicia en 1;

De hace lo haces rapido, mejor que binary
*/

/*
Bezout identity
AX+BY = gcd(A,B)
*/


/*

Given an integer, your task is to find the number, sum and product of its divisors.
As an example, let us consider the number 12:

the number of divisors is 6 (they are 1, 2, 3, 4, 6, 12)
the sum of divisors is 1+2+3+4+6+12=28
the product of divisors is 1 \cdot 2 \cdot 3 \cdot 4 \cdot 6 \cdot 12 = 1728

Since the input number may be large, it is given as a prime factorization.*/

/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;

ll expo(ll base, ll pow) {
	ll ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % MOD;
		base = base * base % MOD;
		pow >>= 1;
	}
	return ans;
}

ll p[100001], k[100001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i] >> k[i];
	ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
	for (int i = 0; i < n; i++) {
		div_cnt = div_cnt * (k[i] + 1) % MOD;
		div_sum =
		    div_sum * (expo(p[i], k[i] + 1) - 1) % MOD * expo(p[i] - 1, MOD - 2) % MOD;
		div_prod = expo(div_prod, k[i] + 1) *
		           expo(expo(p[i], (k[i] * (k[i] + 1) / 2)), div_cnt2) % MOD;
		div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);
	}
	cout << div_cnt << ' ' << div_sum << ' ' << div_prod;
	return 0;
}
*/