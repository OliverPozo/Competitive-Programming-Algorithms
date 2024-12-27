#include <bits/stdc++.h>  
 
#define ll                    long long
#define ld                    long double
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 ((int)(x).size())
#define forn(i,n)             for(int i = 0; i < n; i++)
#define fore(i,b,e)           for(int i = b; i < e; i++)
#define forg(i,b,e,m)         for(int i = b; i < e; i+=m)
#define rforn(i,n)            for(int i = n; i >= 0; i--)
#define rfore(i,b,e)          for(int i = b; i >= e; i--)
#define rforg(i,b,e,m)        for(int i = s; i >= e; i-=m)
#define endl                  "\n"
#define MOD                   1000000007
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

//bit not -> Para invertir el bit
//Si por ejemplo el numero es 37: 100101
//el numero invertido sera -38: 1111111111111111111011010
//~x = -x-1
//int bit = 37; bit = ~bit;

//la pos es de menos significativo a mas

//left bit shift
//x<<2 si 1110 entonces 111000

//right bit shift
//x>>2 si 111000 entonces 1110

//set el k-esimo bit a 1
//x |= (1<<k)

//set el k-esimo bit a 0
//x &= ~(1<<k)

//invert el k-esimo bit de x
//x^(1<<k)

//elimina el bit menos significativo de x(lsb)
//x&(x-1)

//bit menos significativo(lsb)
//x&-x  1100100 -> 0000100

//invierte todos los bits despues del ultimo bit 1
//x|(x-1)   100100 -> 100111

//para saber si un numero x es potencia de 2
//x&(x-1) = 0

//pos de lsb
//__builtin_ctz(x)

//pos de msb
//te desplazas a la derecha o tambien:
//sizeof(x) * 8ll - __builtin_clzll(x) - 1ll;

//-------------------------------------------------
//Funciones Adicionales
//__builtin_clz(x): The number of zeros at the beginning of the bit representation
//__builtin_ctz(x): The number of zeros at the end of the bit representation
//__builtin_popcount(x): The number of ones in the bit representation
//__builtin_parity(x): The parity of the number of ones in the representation

//Si quieres que sea ll poner al final ll -> __builtin_clzll(x)

//int x = 5328;  //00000000000000000001010011010000
//__builtin_clz(x) = 19;
//__builtin_ctz(x) = 4;
//__builtin_popcount(x) = 5;
//__builtin_parity(x) = 1; //porque la cantidad de unos es impar

//para obtener los subsets de un set x
/*int b = 0;
do{
 
}while(b=(b-x)&x)*/


int main(){
    fast_cin();
    return 0;
}


