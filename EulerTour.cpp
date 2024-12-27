// Complejidad: O(N) donde N es el número de vértices del grafo

int main() {
    int n; // Número de vértices
    vector<vector<int>> g(n, vector<int>(n)); // Grafo representado como una matriz de adyacencia
    // Leer el grafo en la matriz de adyacencia
    // (en este caso, se asume que 'g' se llena con las conexiones del grafo)

    vector<int> deg(n); // Vector para almacenar el grado de cada vértice
    // Calcular el grado de cada vértice sumando las conexiones en la fila correspondiente
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    // Buscar un vértice con al menos una conexión
    int first = 0;
    while (first < n && !deg[first]) // Encuentra el primer vértice con al menos un grado
        ++first;
    
    // Si no hay vértices con conexiones, se imprime -1 y termina el programa
    if (first == n) {
        cout << -1;
        return 0;
    }

    // Variables para los vértices con grados impares
    int v1 = -1, v2 = -1;
    bool bad = false; // Bandera para detectar un error en la estructura del grafo
    // Encontrar los vértices con grado impar (condición necesaria para un circuito Euleriano)
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) { // Verificar si el grado del vértice es impar
            if (v1 == -1)
                v1 = i; // Primer vértice impar
            else if (v2 == -1)
                v2 = i; // Segundo vértice impar
            else
                bad = true; // Si hay más de dos vértices impares, no existe un circuito Euleriano
        }
    }

    // Si hay vértices impares, conectar los dos primeros (v1 y v2) para completar el circuito
    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];

    // Utilizar un stack para realizar un recorrido en profundidad del grafo
    stack<int> st;
    st.push(first); // Empezar desde el primer vértice encontrado
    vector<int> res; // Vector para almacenar el recorrido del grafo

    // Recorrido en profundidad (DFS) para encontrar el circuito Euleriano
    while (!st.empty()) {
        int v = st.top(); // Obtener el vértice actual
        int i;
        for (i = 0; i < n; ++i) // Buscar un vértice adyacente no visitado
            if (g[v][i])
                break;
        
        if (i == n) { // Si no hay más vértices adyacentes
            res.push_back(v); // Agregar al recorrido
            st.pop(); // Retroceder en el recorrido
        } else {
            --g[v][i]; // Eliminar la arista del grafo
            --g[i][v]; // Eliminar la arista en el sentido contrario
            st.push(i); // Avanzar al siguiente vértice
        }
    }

    // Si se han encontrado vértices impares, ajustar el recorrido para incluirlos correctamente
    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) || 
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                // Reorganizar el recorrido para incluir v1 y v2 de manera adecuada
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    // Verificar que no queden aristas en el grafo, lo que indicaría que el grafo no es Euleriano
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) // Si aún existen aristas, el grafo no tiene un circuito Euleriano
                bad = true;
        }
    }

    // Si hay errores en el grafo, imprimir -1
    if (bad) {
        cout << -1;
    } else {
        // Imprimir el recorrido encontrado
        for (int x : res)
            cout << x << " ";
    }
}
