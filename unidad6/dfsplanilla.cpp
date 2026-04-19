#include <bits/stdc++.h>
using namespace std;

// Variables globales para dimensiones (muy común en CP para no pasarlas en la recursión)
int R;
int C; 

// Arrays de dirección: Arriba, Derecha, Abajo, Izquierda
int dr[] = {-1, 0, 1, 0}; 
int dc[] = {0, 1, 0, -1};

// Función para validar si una coordenada existe dentro de la matriz
bool isValid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

// DFS que retorna true si encontramos el camino, false si no
bool DFS(int r, int c, vector<string>& grid, vector<vector<bool>>& visited) {
    
    // 1. Caso Base: Si encontramos la meta
    if (grid[r][c] == 'm') {
        return true;
    }

    // 2. Marcar como visitado
    visited[r][c] = true;

    // 3. Explorar vecinos usando los Arrays de Dirección
    // El bucle va de 0 a 3 (4 direcciones)
    for (int i = 0; i < 4; i++) {
        int newR = r + dr[i];
        int newC = c + dc[i];

        // VERIFICACIONES (Fundamental en CP):
        // a. ¿Está dentro del mapa? (isValid)
        // b. ¿No ha sido visitado antes? (!visited)
        // c. ¿Es transitable? (No es una pared '-')
        if (isValid(newR, newC) && !visited[newR][newC] && grid[newR][newC] != '-') {
            
            // Si la llamada recursiva retorna true, es que encontramos la meta
            if (DFS(newR, newC, grid, visited)) {
                return true; 
            }
        }
    }

    // Backtracking: Si queremos encontrar TODOS los caminos posibles,
    // desmarcaríamos aquí: visited[r][c] = false;
    // Pero como solo queremos saber si "es posible llegar", no desmarcamos.
    
    return false;
}

int main() {
    // 1. Lectura del Input
    cin >> R;
    C = R;
    //Si necesito diferenciar entre filas y columnas puedo simplemente recoger ambas por separado
    
    vector<string> grid(R);
    int startR;
    int startC;

    for (int i = 0; i < R; i++) {
        cin >> grid[i]; // Leemos la fila como string
        
        // Buscamos dónde está la 's' para empezar ahí
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 's') {
                startR = i;
                startC = j;
            }
        }
    }

    // 2. Crear matriz de visitados (mismo tamaño que el grid)
    // vector de vectores de bool, inicializado en false
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    // 3. Llamada inicial
    if (DFS(startR, startC, grid, visited)) {
        cout << "YES! Se puede llegar de 's' a 'm'." << endl;
    } else {
        cout << "NO. No hay camino posible." << endl;
    }

    return 0;
}