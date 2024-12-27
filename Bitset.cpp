#include <bits/stdc++.h>  
 
#define ll                    long long
#define ld                    long double
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
//#define all(x)                (x).begin(), (x).end()
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


int main() {
    fast_cin();
    /*bitset<8> bits;
    forn(i,4) bits[i] = 1; */ //00001111
    bitset<8> bits("10101010");
    cout << "Bits: " << bits << '\n';
    //10101010
    cout << "Size: " << bits.size() << '\n';
    //8
    cout << "Count (1s): " << bits.count() << '\n';
    //Count (1s): 4 (cuatro bits están en 1)
    cout << "Any set? " << bits.any() << '\n';
    //Any set? 1 (true, hay al menos un bit en 1)
    cout << "All set? " << bits.all() << '\n';
    //All set? 0 (false, no todos los bits están en 1)
    cout << "None set? " << bits.none() << '\n';
    //None set? 0 (false, no todos los bits están en 0)
    bits.set(0);
    cout << "After setting bit 0: " << bits << '\n';
    //After setting bit 0: 10101011 (pone el bit en la posición 0 en 1)
    bits.flip();
    cout << "After flip: " << bits << '\n';
    //After flip: 01010100 (invierte todos los bits)
    bits[1] = 1;
    cout<<"bits en pos 1 puesto en 1: "<<bits<<endl;
    //01010110
    cout<<"bits en la pos 2: "<<bits[2]<<endl;
    //1
    bits.reset(1);
    cout << "After resetting bit 1: " << bits << '\n';
    //After resetting bit 1: 01010100 (pone el bit en la posición 1 en 0)
    bits <<= 2;
    cout << "After left shift by 2: " << bits << '\n';
    //After left shift by 2: 01010000 (desplaza todos los bits una posición a la izquierda)
    bits >>=2;
    cout<<"After right shift by 2: "<<bits<<'\n';
    //After right shift by 2: 00010100 (desplaza todos los bits una posición a la izquierda)
    ll number = bits.to_ullong();
    cout << "As ll: " << number << '\n';
    //20
    string bitString = bits.to_string();
    cout<<"Bitset como string: "<<bitString<<endl;
    //00010100
    int posPrimerBit = bits._Find_first();
    cout<<"La pos del primer bit es: "<<posPrimerBit<<endl;
    //2
    int nextBit = bits._Find_next(posPrimerBit);
    cout<<"Las pos siguiente es: "<<nextBit<<endl;
    //4
    return 0;
}
