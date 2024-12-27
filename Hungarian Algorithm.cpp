#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n = 3; // Número de trabajadores
    int m = 3; // Número de tareas
    vector<vector<int>> A = { 
        {0, 0, 0, 0},     // Fila ficticia para simplificar índices
        {0, 4, 2, 8},     // Costos para trabajador 1 en tareas 1, 2, y 3
        {0, 6, 3, 7},     // Costos para trabajador 2
        {0, 5, 8, 1}      // Costos para trabajador 3
    };

    //Desde aqui comienza
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1); // Inicialización de vectores auxiliares

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(m + 1, INF);
        vector<bool> used(m + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;

            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = A[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }

            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    //Finaliza aca

    // Salida de las asignaciones y el costo total
    cout << "Asignaciones de trabajador a tarea:\n";
    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            cout << "Trabajador " << p[j] << " asignado a tarea " << j << " con costo " << A[p[j]][j] << "\n";
        }
    }

    int min_cost = -v[0]; // El valor negativo de v[0] nos da el costo mínimo
    cout << "Costo mínimo total: " << min_cost << endl;

    return 0;
}


/*Asignaciones de trabajador a tarea:
Trabajador 1 asignado a tarea 2 con costo 2
Trabajador 2 asignado a tarea 3 con costo 7
Trabajador 3 asignado a tarea 1 con costo 5
Costo mínimo total: 14*/