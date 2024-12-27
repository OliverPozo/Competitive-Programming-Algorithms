//Complejidad: O(V^2E) Tal vez un poco menos 
// Representa una arista en la red de flujo
struct FlowEdge {
    int v, u;            // v es el nodo de origen, u es el nodo de destino de la arista
    long long cap;       // cap es la capacidad máxima de flujo que la arista puede soportar
    long long flow = 0;  // flow es el flujo actual que está pasando por la arista (inicialmente 0)

    // Constructor para inicializar una arista con un nodo origen (v), destino (u) y capacidad (cap)
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

// Implementación de la estructura para el algoritmo de flujo máximo de Dinic
struct Dinic {
    const long long flow_inf = 1e18;      // Representa un flujo infinito para el límite superior en operaciones de flujo
    vector<FlowEdge> edges;               // Almacena todas las aristas de la red, cada arista se guarda dos veces: una para cada dirección
    vector<vector<int>> adj;              // Lista de adyacencia, donde adj[v] almacena los índices de las aristas conectadas al nodo v
    int n, m = 0;                         // n es el número de nodos, m es el número total de aristas (inicialmente 0)
    int s, t;                             // s es el nodo fuente, t es el nodo sumidero (destino final del flujo)
    vector<int> level;                    // Almacena los niveles de cada nodo en el BFS
    vector<int> ptr;                      // Punteros para recordar qué arista explorar en cada nodo durante DFS
    queue<int> q;                         // Cola para realizar el BFS

    // Constructor de Dinic para inicializar el número de nodos, fuente y sumidero
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);                    // Se redimensiona adj para tener una lista de adyacencia para cada nodo
        level.resize(n);                  // Se redimensiona level para guardar el nivel de cada nodo
        ptr.resize(n);                    // Se redimensiona ptr para rastrear las aristas visitadas en DFS
    }

    // Método para agregar una arista dirigida de v a u con capacidad cap
    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);    // Agrega la arista original con capacidad cap
        edges.emplace_back(u, v, 0);      // Agrega la arista inversa con capacidad 0 (para el flujo residual)
        adj[v].push_back(m);              // Añade la arista original en la lista de adyacencia de v
        adj[u].push_back(m + 1);          // Añade la arista inversa en la lista de adyacencia de u
        m += 2;                           // Se incrementa el número total de aristas en 2
    }

    // Realiza un BFS para construir los niveles de los nodos, regresando true si se llega al sumidero t
    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            // Recorre todas las aristas de v
            for (int id : adj[v]) {
                // Si la capacidad residual de la arista es 0 o el nodo destino ya fue visitado, se omite
                if (edges[id].cap == edges[id].flow) continue;
                if (level[edges[id].u] != -1) continue;

                // Actualiza el nivel del nodo destino y lo agrega a la cola
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        // Devuelve true si se alcanzó el sumidero
        return level[t] != -1;
    }

    // Realiza un DFS para encontrar un camino de aumento en la red
    long long dfs(int v, long long pushed) {
        if (pushed == 0) return 0;             // Si no hay flujo adicional que empujar, retorna 0
        if (v == t) return pushed;              // Si se alcanzó el sumidero, retorna el flujo total empujado

        // Recorre las aristas desde v usando el puntero ptr para optimizar
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;

            // Verifica que el nivel de u sea el adecuado para un camino de aumento
            if (level[v] + 1 != level[u]) continue;

            // Intenta enviar flujo por la arista hacia el nodo destino
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;

            // Actualiza los flujos en las aristas residual y original
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    // Función principal para calcular el flujo máximo
    long long flow() {
        long long f = 0;                          // Acumula el flujo máximo calculado
        while (true) {
            fill(level.begin(), level.end(), -1); // Resetea los niveles de los nodos antes de cada iteración
            level[s] = 0;                         // Establece el nivel del nodo fuente en 0
            q.push(s);                            // Inicia el BFS desde la fuente
            if (!bfs()) break;                    // Si no se puede alcanzar el sumidero, termina el algoritmo

            fill(ptr.begin(), ptr.end(), 0);      // Resetea los punteros de cada nodo para el DFS
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;                      // Suma el flujo encontrado en cada DFS al flujo total
            }
        }
        return f;                                 // Retorna el flujo máximo
    }
};

//lo que tienes que hacer es crearte el struct de Dinic como
//Dinic dani = Dinic(n+1,0,n);
//despues añades las aristas que quieras
//dani.add_edge(i,j,mat[i][j]); //le das nodos y la capacidad
//retornas flujo maximo
//ll res = dani.flow();