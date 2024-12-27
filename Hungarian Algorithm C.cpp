vector<int> u (n+1), v (m+1), p (m+1), way (m+1); // Inicialización de vectores u y v (potenciales de filas y columnas), p (emparejamiento) y way (trayectoria para reconstrucción)

// Itera sobre cada fila del problema de asignación
for (int i = 1; i <= n; ++i) {
    p[0] = i; // Establece el nodo inicial en la columna ficticia 0 con la fila i
    int j0 = 0; // Índice de la columna actual en el proceso de augmentación
    vector<int> minv (m+1, INF); // Vector para guardar mínimos para cada columna
    vector<bool> used (m+1, false); // Vector para marcar columnas ya procesadas

    do {
        used[j0] = true; // Marca la columna actual como utilizada
        int i0 = p[j0], delta = INF, j1; // i0 es la fila correspondiente al nodo actual; delta para el mínimo ajuste de costo

        // Explora columnas no utilizadas para encontrar la columna de mínimo costo
        for (int j = 1; j <= m; ++j)
            if (!used[j]) {
                int cur = A[i0][j] - u[i0] - v[j]; // Costo ajustado para la posición A[i0][j]
                if (cur < minv[j]) { // Si encontramos un costo menor para esta columna
                    minv[j] = cur; // Actualiza el mínimo valor de costo
                    way[j] = j0; // Guarda la columna previa en el camino
                }
                if (minv[j] < delta) // Actualiza el delta con el mínimo de minv[j]
                    delta = minv[j], j1 = j; // Actualiza j1 para el siguiente nodo
            }

        // Ajusta los valores de los potenciales de las filas y columnas para mantener los costos mínimos
        for (int j = 0; j <= m; ++j)
            if (used[j]) // Si la columna ya fue procesada, ajusta su potencial
                u[p[j]] += delta, v[j] -= delta;
            else // Si no fue procesada, reduce minv[j] en delta
                minv[j] -= delta;

        j0 = j1; // Avanza a la siguiente columna con el menor costo encontrado

    } while (p[j0] != 0); // Repite hasta llegar a una columna no asignada en el emparejamiento

    // Reconstruye el camino de emparejamiento a partir de la columna actual j0
    do {
        int j1 = way[j0]; // Obtiene la columna previa en el camino
        p[j0] = p[j1]; // Asigna el emparejamiento de j0 al de j1
        j0 = j1; // Retrocede en el camino
    } while (j0); // Repite hasta llegar al nodo de inicio
}
