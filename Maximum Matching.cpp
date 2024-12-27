//Complejidad O(nm), en el peor de los casos O(n^3)
const int N = 120;             // Define el tamaño máximo de nodos en el grafo
int n, k;                      // n es el número de nodos en el lado izquierdo del grafo, k es el número de nodos en el lado derecho
vector<vector<int>> adj(N);    // Lista de adyacencia que almacena las conexiones entre nodos en el grafo bipartito
vector<int> mt;                // mt almacena el emparejamiento. mt[i] indica con qué nodo del lado izquierdo está emparejado el nodo i del lado derecho
vector<bool> used;             // used se usa para evitar ciclos y asegurar que cada nodo solo se visite una vez en una llamada recursiva

// Función recursiva para intentar encontrar un emparejamiento para el nodo v usando DFS
bool try_kuhn(int v) {
    if (used[v])               // Si ya se visitó el nodo v, retorna false
        return false;
    used[v] = true;            // Marca el nodo v como visitado
    for (int to : adj[v]) {    // Recorre todos los nodos adyacentes a v en el grafo bipartito
        // Si el nodo to no está emparejado o si el emparejamiento actual de to puede ser reasignado
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;        // Empareja el nodo to del lado derecho con el nodo v del lado izquierdo
            return true;       // Retorna true indicando que se encontró un emparejamiento
        }
    }
    return false;              // Si no se pudo emparejar, retorna false
}

int main() {
    fast_cin();              
    // freopen("input.in", "r", stdin);  
    // freopen("output.out", "w", stdout);  

    mt.assign(k, -1);          // Inicializa mt con -1 indicando que ningún nodo está emparejado aún
    vector<bool> used1(n, false); // used1 marca si un nodo del lado izquierdo ya está emparejado en una etapa inicial

    // Fase inicial: intenta encontrar un emparejamiento "greedy" inicial
    for (int v = 0; v < n; ++v) {
        for (int to : adj[v]) { // Recorre los nodos adyacentes a v
            if (mt[to] == -1) { // Si el nodo to en el lado derecho no está emparejado
                mt[to] = v;     // Empareja to con v
                used1[v] = true; // Marca el nodo v como emparejado
                break;           // Sale del bucle para avanzar al siguiente nodo en el lado izquierdo
            }
        }
    }

    // Fase principal: intenta mejorar el emparejamiento usando DFS
    for (int v = 0; v < n; ++v) {
        if (used1[v])           // Si v ya está emparejado en la fase inicial, lo salta
            continue;
        used.assign(n, false);   // Resetea la lista used para el DFS de cada nodo
        try_kuhn(v);             // Intenta encontrar un emparejamiento para v
    }

    // Imprime el emparejamiento final
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)         // Si el nodo i en el lado derecho está emparejado
            printf("%d %d\n", mt[i] + 1, i + 1); // Imprime el emparejamiento ajustando el índice para que empiece en 1

    return 0;
}
