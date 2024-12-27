/*Un Trie (también conocido como árbol de prefijos) 
es una estructura de datos en forma de árbol utilizada para 
almacenar un conjunto de cadenas de caracteres, de manera que 
se pueda realizar búsquedas rápidas de prefijos y cadenas completas.
 Es especialmente útil en problemas que implican búsquedas de cadenas, 
autocompletado y comparación de prefijos.*/

/* Segund chat gpt:
    Insercion: O(L) donde L es la longitud de la palabra
    Busqueda: O(L) donde L es la longitud de la palabra
    Conteo de prefijos: O(L) donde L es la longitud del prefijo.
    Espacio: O(NA), N es el numero de palabras y A es el tamaño del alfabeto
*/

// Definición de la estructura 'item' para los nodos del Trie
struct item{
    vector<int> hijos;  // Vector que almacena los índices de los nodos hijos (uno por cada letra)
    bool final;         // Indica si el nodo corresponde a la finalización de una palabra
    int cant;           // Cantidad de veces que se ha insertado una palabra que pasa por este nodo
    
    // Constructor por defecto
    item(){
        final = false;  // Inicializa 'final' en false, es decir, el nodo no es final de palabra por defecto
        hijos.assign(26, 0);  // Inicializa el vector 'hijos' de tamaño 26 (para las 26 letras del alfabeto) con valores 0
        cant = 0;  // Inicializa la cantidad de veces que se pasa por este nodo en 0
    }
    
    // Constructor alternativo (no utilizado en el código principal, solo para inicialización con otro tamaño de hijos)
    item(int x){
        hijos.resize(14);  // Redimensiona el vector 'hijos' a un tamaño de 14 (solo para un caso específico no usado aquí)
    }
};

// Trie para almacenar las palabras (estructura de árboles de prefijos)
vector<item> trie;

// Función para insertar una palabra en el Trie
void insertar1(string s){
    int pos = 0;  // Comienza desde el nodo raíz (0)
    fore(i, 0, s.size()){  // Itera sobre cada carácter de la palabra
        int ch = s[i] - 'a';  // Convierte el carácter en un índice (0 para 'a', 1 para 'b', ...)
        
        // Si no existe un hijo para el carácter actual, se crea un nuevo nodo
        if(trie[pos].hijos[ch] == 0){
            trie[pos].hijos[ch] = trie.size();  // Asigna un nuevo índice en el Trie
            trie.pb(item());  // Añade un nuevo nodo (nuevo item) al Trie
        }
        
        pos = trie[pos].hijos[ch];  // Mueve al nodo hijo correspondiente al carácter
        trie[pos].cant++;  // Incrementa el contador de visitas a este nodo
    }
    
    trie[pos].final = true;  // Marca el nodo como final de palabra
}

// Función para verificar si una palabra está presente en el Trie
bool esta1(string s){
    int pos = 0;  // Comienza desde el nodo raíz (0)
    fore(i, 0, s.size()){  // Itera sobre cada carácter de la palabra
        int ch = s[i] - 'a';  // Convierte el carácter en un índice (0 para 'a', 1 para 'b', ...)
        
        // Si no existe un hijo para el carácter actual, la palabra no está en el Trie
        if(trie[pos].hijos[ch] == 0)
            return false;
        
        pos = trie[pos].hijos[ch];  // Mueve al nodo hijo correspondiente al carácter
    }
    
    return trie[pos].final;  // Devuelve 'true' si el nodo final es alcanzado, indicando que la palabra está en el Trie
}

// Función para obtener cuántas veces se ha insertado una palabra que empieza con el prefijo dado
int f(string s){
    int lon = s.size(), pos = 0;  // Longitud de la cadena y comienza desde el nodo raíz
    if(lon == 0) return 0;  // Si la longitud del prefijo es 0, no hay ocurrencias
    forn(i,lon){  // Itera sobre cada carácter del prefijo
        int letra = s[i] - 'a';  // Convierte el carácter en un índice (0 para 'a', 1 para 'b', ...)
        
        // Si no existe un hijo para el carácter actual, no hay palabras con ese prefijo
        if(trie[pos].hijos[letra] == 0) return 0;
        
        pos = trie[pos].hijos[letra];  // Mueve al nodo hijo correspondiente al carácter
    }
    
    return trie[pos].cant;  // Devuelve la cantidad de palabras que pasan por este nodo (cuántas veces se ha insertado un prefijo similar)
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  // Optimización de entrada/salida en C++
    
    int n, q;  // Número de palabras a insertar y número de consultas
    cin>>n>>q;  // Lee las entradas n (palabras) y q (consultas)
    
    trie.pb(item());  // Inserta el nodo raíz en el Trie
    
    forn(i,n){  // Para cada palabra que se va a insertar
        string s; cin>>s;  // Lee la palabra
        insertar1(s);  // Inserta la palabra en el Trie
    }
    
    forn(i,q){  // Para cada consulta
        string x; cin>>x;  // Lee el prefijo que se va a consultar
        int res = f(x);  // Obtiene la cantidad de palabras que tienen el prefijo dado
        cout<<res<<endl;  // Imprime el resultado de la consulta
    }
    
    return 0;  // Fin del programa
}
