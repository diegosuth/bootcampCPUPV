#include <iostream>
#include <vector>
#include <string>
#include <queue> // No te olvides de la cola

using namespace std;

// 1. Variables globales y arrays de dirección
int filas, columnas;
int dr[] = {-1, 0, 1, 0}; // Arriba, Derecha, Abajo, Izquierda
int dc[] = {0, 1, 0, -1};

// 2. Nuestra "cajita" de información para la fila
struct Nodo {
    int r;
    int c;
    int pasos;
};

// 3. Función de seguridad para no salirnos del mapa
bool isValid(int r, int c) {
    return r >= 0 && r < filas && c >= 0 && c < columnas;
}

// 4. El motor principal: BFS
int bfs(int startR, int startC, vector<string>& grid, vector<vector<bool>>& visited) {
    queue<Nodo> q;
    
    // Metemos el inicio. Empezamos en 0 saltos.
    // (Ojo: en tu problema dice que cuentes la entrada, así que ahí tendrías que cambiar esto a 1)
    q.push({startR, startC, 0}); 
    visited[startR][startC] = true;
    
    while (!q.empty()) {
        Nodo actual = q.front();
        q.pop();
        
        // ¿Encontramos el tesoro 'X'?
        if (grid[actual.r][actual.c] == 'X') {
            return actual.pasos;
        }
        
        // Explorar los 4 costados
        for (int i = 0; i < 4; i++) {
            int newR = actual.r + dr[i];
            int newC = actual.c + dc[i];
            
            // Comprobamos: límites, no visitado, y que no sea pared '*'
            if (isValid(newR, newC) && !visited[newR][newC] && grid[newR][newC] != '#') {
                
                // Marcamos y a la cola
                visited[newR][newC] = true;
                q.push({newR, newC, actual.pasos + 1});
            }
        }
    }
    
    // Si la cola se vacía y no encontramos la 'X', devolvemos -1
    return -1; 
}

int main() {
    // Leemos el tamaño del mapa
    // (Acuérdate de la trampa de tu problema: ¿Leen primero filas o columnas?)
    cin >> filas >> columnas;
    
    vector<string> grid(filas);
    vector<vector<bool>> visited(filas, vector<bool>(columnas, false));
    int startR;
    int startC;
    // Leer el mapa y buscar dónde está la 'I'
    for (int i = 0; i < filas; i++) {
        cin >> grid[i];
        for (int j = 0; j < columnas; j++) {
            if (grid[i][j] == 'I') { 
                startR = i;
                startC = j;
            }
        }
    }
    
    // ¡A jugar!
    int resultado = bfs(startR, startC, grid, visited);
    
    if (resultado != -1) {
        cout << resultado << endl;
    } else {
        cout << "No hay salida." << endl;
    }

    return 0;    
}